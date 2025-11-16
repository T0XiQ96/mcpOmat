// MEGA_RS485_PitterOmat.ino
// Arduino Mega RS485 SLAVE + Adafruit NeoPixel control fuer Spiel + Grenzen

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <stdint.h>

struct PlayerStateSettings {
  uint8_t playerCount;
  uint8_t mode;
  uint8_t singleColor;
  uint8_t ownRandom;
  uint8_t inactiveMode;
};

struct BorderStateSettings {
  uint8_t mode;
  uint8_t singleColor;
};

struct BrightnessSettings {
  uint8_t game;
  uint8_t border;
};

static PlayerStateSettings runtimePlayerState = {6, 1, 3, 0, 0};
static BorderStateSettings runtimeBorderState = {0, 0};
static BrightnessSettings runtimeBrightness = {25, 25};
static bool runtimeShowBorders = false;
static bool runtimeJokerEnabled = false;
static uint32_t runtimePlayerPalette[6];
static uint32_t runtimeSingleColor = 0;
static uint32_t runtimeLastHitColor = 0;
static bool hitBlinkActive = false;
static bool hitBlinkState = false;
static uint8_t hitBlinkGroup = 0;
static uint32_t hitBlinkColor = 0;
static unsigned long hitBlinkToggleMs = 0;
static unsigned long hitBlinkStartMs = 0;
static bool hitBlinkReadySent = false;

// ===================== RS485 =====================
constexpr uint32_t BAUD = 115200;
#define RS Serial1
constexpr int RS485_DE_PIN = 7;

static inline void rs485SendRaw(const uint8_t *data, size_t len) {
  digitalWrite(RS485_DE_PIN, HIGH);
  delayMicroseconds(10);
  RS.write(data, len);
  RS.flush();
  delayMicroseconds(20);
  digitalWrite(RS485_DE_PIN, LOW);
}
static inline void rs485SendLine(const char *line) {
  rs485SendRaw((const uint8_t *)line, strlen(line));
}

// ===================== NeoPixel ==================
constexpr uint8_t  GAME_PIN         = 6;
constexpr uint8_t  BORDER_PIN       = 8;
constexpr uint16_t GAME_LED_COUNT   = 432;  // 36 Gruppen * 12
constexpr uint16_t BORDER_LED_COUNT = 432;

uint8_t BRIGHT_GAME = 25;
uint8_t BRIGHT_BORD = 25;

Adafruit_NeoPixel gameStrip(GAME_LED_COUNT,   GAME_PIN,   NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel borderStrip(BORDER_LED_COUNT, BORDER_PIN, NEO_GRB + NEO_KHZ800);

// ===================== Forward Decls ============
static void clearGame();
static void clearBorder();
static void clearAll();
static uint16_t borderMap(uint16_t logical);
static void sweepForwardLogical(Adafruit_NeoPixel &strip, uint16_t count, bool isBorder);
static void ledRingTest();

static void setBordersForPlayers(uint8_t pc, bool on);
static void brightnessPreview(Adafruit_NeoPixel &strip, bool isBorder);

static void initPlayerColors();
static void runPlayerPreview();
static void runBorderPreview();

static void clearJoker();
static void updateJokerAnimation();

static void handleSpinParams(int,int,int,int,int,int,int);
static uint8_t spinOneRound();

static uint8_t playerIndexFromGroup(uint8_t group, uint8_t pc);
static void blinkGroupColor(uint8_t group, uint32_t color, uint8_t cycles, uint16_t onMs, uint16_t offMs);

static void stopHitBlink();
static void startHitBlink(uint8_t group, uint32_t color);
static void updateHitBlink();

static void handleLine(const char *line);
static void rs485Poll();

// ===================== Helpers ==================
static inline uint16_t groupBase(uint8_t group) {
  if (group < 1) group = 1;
  if (group > 36) group = 36;
  return (uint16_t)(group - 1) * 12;
}

static void clearGame() {
  for (uint16_t i = 0; i < GAME_LED_COUNT; ++i) gameStrip.setPixelColor(i, 0);
  gameStrip.show();
}
static void clearBorder() {
  for (uint16_t i = 0; i < BORDER_LED_COUNT; ++i) borderStrip.setPixelColor(i, 0);
  borderStrip.show();
}
static void clearAll() {
  hitBlinkActive = false;
  clearGame();
  clearBorder();
}

static uint32_t runtimeBorderColor() {
  if (runtimeBorderState.mode == 0) {
    return runtimeBorderState.singleColor == 0 ? borderStrip.Color(120, 30, 0)
                                               : borderStrip.Color(80, 80, 80);
  }
  return borderStrip.Color(128, 128, 128);
}

// Mapping Border: kehrt die physische Reihenfolge der 36er Segmente um
static inline uint16_t borderMap(uint16_t logical) {
  const uint16_t blockSize = 12;
  const uint16_t blocks    = BORDER_LED_COUNT / blockSize;  // 36
  const uint16_t blockIdx  = logical / blockSize;           // 0..35
  const uint16_t inBlock   = logical % blockSize;           // 0..11
  const uint16_t physBlockStart = (blocks - 1 - blockIdx) * blockSize;
  return physBlockStart + inBlock;
}

static void sweepForwardLogical(Adafruit_NeoPixel &strip, uint16_t count, bool isBorder) {
  int32_t prev = -1;
  const uint32_t bg   = isBorder ? strip.Color(8,8,8) : strip.Color(0,0,0);
  const uint32_t lead = strip.Color(255,255,255);
  for (uint16_t i = 0; i < count; ++i) {
    uint16_t phys = isBorder ? borderMap(i) : i;
    if (prev >= 0) strip.setPixelColor(prev, bg);
    strip.setPixelColor(phys, lead);
    strip.show();
    prev = phys;
    delay(5);
  }
  if (prev >= 0) strip.setPixelColor(prev, bg);
  strip.show();
}

// ===================== LED Test =================
static void ledRingTest() {
  Serial.println(F("LED-Ring-Test start"));
  clearAll();
  gameStrip.setBrightness(BRIGHT_GAME);
  borderStrip.setBrightness(BRIGHT_BORD);
  sweepForwardLogical(gameStrip, GAME_LED_COUNT, false);
  sweepForwardLogical(borderStrip, BORDER_LED_COUNT, true);
  Serial.println(F("LED-Ring-Test done"));
}

// ===================== Borders ==================
static uint8_t currentPlayerCount = 0;

// Border-Preview-State (wird auch genutzt, um die Farbe der Marker festzulegen)
static uint8_t previewBorderMode = 0;        // 0=einfarbig, 1=Regenbogen
static uint8_t previewBorderSingleColor = 1; // 0=braun, 1=grau

static uint32_t borderPreviewToColor() {
  if (previewBorderMode == 0) {
    if (previewBorderSingleColor == 0) return borderStrip.Color(120,30,0);
    else return borderStrip.Color(80,80,80);
  }
  // Default-Farbe wenn Regenbogen gewählt war und ein einzelner Marker gesetzt wird
  return borderStrip.Color(128,128,128);
}

static void setBordersForPlayers(uint8_t pc, bool on) {
  currentPlayerCount = pc;
  const uint32_t colorOn  = runtimeBorderColor();
  const uint32_t colorDim = borderStrip.Color(0,0,0);

  // Hintergrund: alle leicht grau oder aus
  for (uint16_t i = 0; i < BORDER_LED_COUNT; ++i)
    borderStrip.setPixelColor(i, on ? colorDim : 0);

  auto setGroup = [&](uint8_t group, uint32_t col) {
    if (group < 1 || group > 36) return;
    uint16_t start = groupBase(group);
    for (uint8_t i = 0; i < 12; ++i)
      borderStrip.setPixelColor(borderMap(start + i), col);
  };

  if (on) {
    // If border mode is not single-color, paint groups in static rainbow
    if (runtimeBorderState.mode != 0) {
      // choose groups per player count
      const uint8_t *groups = nullptr;
      uint8_t groupCount = 0;
      static const uint8_t g2[] = {18, 36};
      static const uint8_t g3[] = {12, 24, 36};
      static const uint8_t g4[] = {4, 13, 22, 31};
      static const uint8_t g5[] = {2, 9, 16, 23, 30, 1};
      static const uint8_t g6[] = {3, 9, 15, 21, 27, 33};
      switch (pc) {
        case 2: groups = g2; groupCount = 2; break;
        case 3: groups = g3; groupCount = 3; break;
        case 4: groups = g4; groupCount = 4; break;
        case 5: groups = g5; groupCount = 5; break;
        case 6: groups = g6; groupCount = 6; break;
        default: break;
      }
      if (groups && groupCount > 0) {
        for (uint8_t i = 0; i < groupCount; ++i) {
          uint16_t hue = (uint32_t)i * 65536 / groupCount;
          uint32_t col = borderStrip.gamma32(borderStrip.ColorHSV(hue));
          setGroup(groups[i], col);
        }
        borderStrip.show();
        return;
      }
    }

    switch (pc) {
      case 2: { const uint8_t g[] = {18, 36};              for (uint8_t i : g) setGroup(i, colorOn); } break;
      case 3: { const uint8_t g[] = {12, 24, 36};          for (uint8_t i : g) setGroup(i, colorOn); } break;
      case 4: { const uint8_t g[] = {4, 13, 22, 31};       for (uint8_t i : g) setGroup(i, colorOn); } break;
      case 5: { const uint8_t g[] = {3, 10, 17, 24, 31};   for (uint8_t i : g) setGroup(i, colorOn); } break;
      case 6: { const uint8_t g[] = {3, 9, 15, 21, 27, 33};for (uint8_t i : g) setGroup(i, colorOn);} break;
      default: break;
    }
  }
  borderStrip.show();
}

// 2s Brightness-Vorschau: markiert exemplarisch Gruppen 1,9,18,24
static void brightnessPreview(Adafruit_NeoPixel &strip, bool isBorder) {
  stopHitBlink();
  const uint32_t col = strip.Color(255,255,255);
  auto setGroup = [&](uint8_t group, uint32_t c) {
    if (group < 1 || group > 36) return;
    uint16_t start = groupBase(group);
    for (uint8_t i = 0; i < 12; ++i) {
      uint16_t idx = start + i;
      if (isBorder) idx = borderMap(idx);
      strip.setPixelColor(idx, c);
    }
  };
  setGroup(1, col); setGroup(9, col); setGroup(18, col); setGroup(24, col);
  strip.show();
}

// ===================== Spielerfarben Preview ====
static uint32_t playerColors[6];

static void initPlayerColors() {
  playerColors[0] = gameStrip.Color(255,0,0);   // S1 Rot
  playerColors[1] = gameStrip.Color(0,255,0);   // S2 Grün
  playerColors[2] = gameStrip.Color(0,0,255);   // S3 Blau
  playerColors[3] = gameStrip.Color(255,255,0); // S4 Gelb
  playerColors[4] = gameStrip.Color(255,0,255); // S5 Magenta
  playerColors[5] = gameStrip.Color(0,255,255); // S6 Cyan
}

static uint8_t previewPlayerMode = 0;
static uint8_t previewPlayerSingleColor = 0;
static uint8_t previewPlayerOwnRandom = 0;
static uint8_t previewInactiveMode = 0;

static uint32_t randomWheelColor() {
  uint16_t hue = random(0, 65536);
  return gameStrip.gamma32(gameStrip.ColorHSV(hue));
}

static void refreshRuntimePalette(bool randomize) {
  const uint32_t defaults[6] = {
    gameStrip.Color(255, 0, 0),
    gameStrip.Color(0, 255, 0),
    gameStrip.Color(0, 0, 255),
    gameStrip.Color(255, 255, 0),
    gameStrip.Color(255, 0, 255),
    gameStrip.Color(0, 255, 255)
  };

  if (!randomize) {
    for (int i = 0; i < 6; ++i) {
      runtimePlayerPalette[i] = defaults[i];
    }
    return;
  }

  // Generate six well-separated hues with slight jitter
  const uint16_t step = 65536 / 6;
  uint16_t base = (uint16_t)random(0, 65536);
  for (int i = 0; i < 6; ++i) {
    int16_t jitter = (int16_t)random(0, step/3 + 1) - (int16_t)(step/6);
    uint16_t hue = (uint16_t)(base + i * step + jitter);
    runtimePlayerPalette[i] = gameStrip.gamma32(gameStrip.ColorHSV(hue));
  }
}

static uint8_t seatIndexFromGroup(uint8_t group) {
  uint8_t seat = playerIndexFromGroup(group, runtimePlayerState.playerCount);
  return seat;
}

static bool seatInactive(uint8_t seat) {
  if (seat == 0) {
    return false;
  }
  return seat > runtimePlayerState.playerCount;
}

static uint32_t dimColor(uint32_t color, float factor) {
  uint8_t r = (color >> 16) & 0xFF;
  uint8_t g = (color >> 8) & 0xFF;
  uint8_t b = color & 0xFF;
  r = (uint8_t)(r * factor);
  g = (uint8_t)(g * factor);
  b = (uint8_t)(b * factor);
  return gameStrip.Color(r, g, b);
}

static uint32_t colorFromSingleIndex(uint8_t idx, uint8_t group) {
  switch (idx) {
    case 1: return gameStrip.Color(0, 0, 255);
    case 2: return gameStrip.Color(0, 255, 0);
    case 3: return gameStrip.Color(255, 0, 0);
    case 4: {
      uint16_t hue = (uint32_t)(group - 1) * 65536 / 36;
      return gameStrip.gamma32(gameStrip.ColorHSV(hue));
    }
    case 0:
    default:
      return runtimeSingleColor ? runtimeSingleColor : gameStrip.Color(255, 255, 255);
  }
}

static void prepareSpinColorsForSpin() {
  if (runtimePlayerState.mode == 0 && runtimePlayerState.singleColor == 0) {
    runtimeSingleColor = randomWheelColor();
  }
  refreshRuntimePalette(runtimePlayerState.mode == 1 && runtimePlayerState.ownRandom != 0);
}

static uint32_t resolveSpinColor(uint8_t group) {
  // Joker-Farbe während des Spins: bei 5 Spielern ist Gruppe 2 Joker
  if (runtimePlayerState.playerCount == 5 && group == 2 && runtimeJokerEnabled) {
    return gameStrip.Color(255, 180, 0);
  }

  uint32_t color = 0;
  switch (runtimePlayerState.mode) {
    case 0:
      color = colorFromSingleIndex(runtimePlayerState.singleColor, group);
      break;
    case 1: {
      uint8_t seat = seatIndexFromGroup(group);
      if (seat >= 1 && seat <= 6) {
        color = runtimePlayerPalette[seat - 1];
        if (seatInactive(seat)) {
          switch (runtimePlayerState.inactiveMode) {
            case 0: color = 0; break;
            case 1: color = gameStrip.Color(32, 32, 32); break;
            case 2: color = dimColor(color, 0.1f); break;
            default: break;
          }
        }
      } else {
        color = gameStrip.Color(255, 180, 0);
      }
      break;
    }
    case 2:
    default:
      color = randomWheelColor();
      break;
  }
  return color;
}

static void showGroupColor(uint8_t group, uint32_t color) {
  clearGame();
  uint16_t base = groupBase(group);
  for (uint8_t i = 0; i < 12; ++i) {
    gameStrip.setPixelColor(base + i, color);
  }
  gameStrip.show();
}

static void stopHitBlink() {
  hitBlinkActive = false;
  hitBlinkReadySent = false;
}

static void startHitBlink(uint8_t group, uint32_t color) {
  hitBlinkGroup = group;
  hitBlinkColor = color;
  hitBlinkToggleMs = 0;
  hitBlinkState = false;
  hitBlinkStartMs = millis();
  hitBlinkReadySent = false;
  hitBlinkActive = true;
}

static void updateHitBlink() {
  if (!hitBlinkActive) {
    return;
  }
  unsigned long now = millis();
  if (hitBlinkToggleMs == 0 || now - hitBlinkToggleMs >= 200) {
    hitBlinkToggleMs = now;
    hitBlinkState = !hitBlinkState;
    clearGame();
    if (hitBlinkState) {
      uint16_t base = groupBase(hitBlinkGroup);
      for (uint8_t i = 0; i < 12; ++i) {
        gameStrip.setPixelColor(base + i, hitBlinkColor);
      }
    }
    gameStrip.show();
  }

  if (!hitBlinkReadySent && millis() - hitBlinkStartMs >= 3000) {
    rs485SendLine("SPIN_READY\n");
    hitBlinkReadySent = true;
  }
}

static void applyBrightness(const BrightnessSettings &state) {
  runtimeBrightness = state;
  BRIGHT_GAME = runtimeBrightness.game;
  BRIGHT_BORD = runtimeBrightness.border;
  gameStrip.setBrightness(BRIGHT_GAME);
  borderStrip.setBrightness(BRIGHT_BORD);
  gameStrip.show();
  borderStrip.show();
}

static void applyBorderState(const BorderStateSettings &state) {
  runtimeBorderState = state;
  previewBorderMode = runtimeBorderState.mode;
  previewBorderSingleColor = runtimeBorderState.singleColor;
  if (runtimeShowBorders) {
    setBordersForPlayers(currentPlayerCount, true);
  } else {
    clearBorder();
  }
}

static void applyPlayerState(const PlayerStateSettings &state) {
  runtimePlayerState = state;
  if (runtimePlayerState.playerCount < 2 || runtimePlayerState.playerCount > 6) {
    runtimePlayerState.playerCount = 6;
  }
  currentPlayerCount = runtimePlayerState.playerCount;
  refreshRuntimePalette(false);
  if (runtimeShowBorders) {
    setBordersForPlayers(currentPlayerCount, true);
  } else {
    clearBorder();
  }
  clearGame();
  gameStrip.show();
}

static void runPlayerPreview() {
  stopHitBlink();
  clearGame();
  uint8_t pc = currentPlayerCount;
  if (pc < 2 || pc > 6) pc = 6;

  if (previewPlayerMode == 0) {
    // eine Farbe für alle
    if (previewPlayerSingleColor == 0) {
      uint16_t hue = random(0, 65536);
      uint32_t col = gameStrip.gamma32(gameStrip.ColorHSV(hue));
      for (uint16_t i = 0; i < GAME_LED_COUNT; ++i) gameStrip.setPixelColor(i, col);
    } else if (previewPlayerSingleColor == 4) {
      for (uint16_t i = 0; i < GAME_LED_COUNT; ++i) {
        uint16_t hue = (uint32_t)i * 65536 / GAME_LED_COUNT;
        gameStrip.setPixelColor(i, gameStrip.gamma32(gameStrip.ColorHSV(hue)));
      }
    } else {
      uint32_t col = 0;
      switch (previewPlayerSingleColor) {
        case 1: col = gameStrip.Color(0,0,255); break;
        case 2: col = gameStrip.Color(0,255,0); break;
        case 3: col = gameStrip.Color(255,0,0); break;
      }
      for (uint16_t i = 0; i < GAME_LED_COUNT; ++i) gameStrip.setPixelColor(i, col);
    }
  } else {
    // farbige Segmente je Spieler
    auto fillRange = [&](uint8_t start, uint8_t end, uint32_t col) {
      if (start <= end) {
        for (uint8_t g = start; g <= end; ++g) {
          uint16_t base = groupBase(g);
          for (uint8_t i = 0; i < 12; ++i) gameStrip.setPixelColor(base + i, col);
        }
      } else {
        for (uint8_t g = start; g <= 36; ++g) {
          uint16_t base = groupBase(g);
          for (uint8_t i = 0; i < 12; ++i) gameStrip.setPixelColor(base + i, col);
        }
        for (uint8_t g = 1; g <= end; ++g) {
          uint16_t base = groupBase(g);
          for (uint8_t i = 0; i < 12; ++i) gameStrip.setPixelColor(base + i, col);
        }
      }
    };
    switch (pc) {
      case 2: {
        uint8_t groupsPer = 18;
        for (uint8_t p = 0; p < 2; ++p) {
          uint32_t col = previewPlayerOwnRandom ? gameStrip.gamma32(gameStrip.ColorHSV((uint16_t)(p * 40) * 256))
                                                : playerColors[p % 6];
          fillRange(p * groupsPer + 1, p * groupsPer + groupsPer, col);
        }
      } break;
      case 3: {
        uint8_t groupsPer = 12;
        for (uint8_t p = 0; p < 3; ++p) {
          uint32_t col = previewPlayerOwnRandom ? gameStrip.gamma32(gameStrip.ColorHSV((uint16_t)(p * 40) * 256))
                                                : playerColors[p % 6];
          fillRange(p * groupsPer + 1, p * groupsPer + groupsPer, col);
        }
      } break;
      case 4: {
        uint8_t segs[4][2] = { {5,13}, {14,22}, {23,31}, {32,4} };
        for (uint8_t p = 0; p < 4; ++p) {
          uint32_t col = previewPlayerOwnRandom ? gameStrip.gamma32(gameStrip.ColorHSV((uint16_t)(p * 40) * 256))
                                                : playerColors[p % 6];
          fillRange(segs[p][0], segs[p][1], col);
        }
      } break;
      case 5: {
        uint8_t segs[5][2] = { {3,9}, {10,16}, {17,23}, {24,30}, {31,1} };
        for (uint8_t p = 0; p < 5; ++p) {
          uint32_t col = previewPlayerOwnRandom ? gameStrip.gamma32(gameStrip.ColorHSV((uint16_t)(p * 40) * 256))
                                                : playerColors[p % 6];
          fillRange(segs[p][0], segs[p][1], col);
        }
      } break;
      case 6: {
        uint8_t segs[6][2] = { {4,9}, {10,15}, {16,21}, {22,27}, {28,33}, {34,3} };
        for (uint8_t p = 0; p < 6; ++p) {
          uint32_t col = previewPlayerOwnRandom ? gameStrip.gamma32(gameStrip.ColorHSV((uint16_t)(p * 40) * 256))
                                                : playerColors[p % 6];
          fillRange(segs[p][0], segs[p][1], col);
        }
      } break;
    }
  }

  // Joker-Segment (nur 5 Spieler)
  if (pc == 5) {
    uint16_t baseJoker = groupBase(2);
    if (previewInactiveMode == 0) {
      for (uint8_t i = 0; i < 12; ++i) gameStrip.setPixelColor(baseJoker + i, 0);
    } else if (previewInactiveMode == 1) {
      uint32_t grayCol = gameStrip.Color(80, 80, 80);
      for (uint8_t i = 0; i < 12; ++i) gameStrip.setPixelColor(baseJoker + i, grayCol);
    } else if (previewInactiveMode == 2) {
      uint32_t dimGold = gameStrip.Color(128, 90, 0);
      for (uint8_t i = 0; i < 12; ++i) gameStrip.setPixelColor(baseJoker + i, dimGold);
    }
  }

  gameStrip.show();
}

// ===================== Border Preview ===========
static void runBorderPreview() {
  stopHitBlink();
  for (uint16_t i = 0; i < BORDER_LED_COUNT; ++i) borderStrip.setPixelColor(i, 0);

  auto setGroup = [&](uint8_t group, uint32_t col) {
    if (group < 1 || group > 36) return;
    uint16_t start = groupBase(group);
    for (uint8_t i = 0; i < 12; ++i)
      borderStrip.setPixelColor(borderMap(start + i), col);
  };

  if (previewBorderMode == 0) {
    uint32_t col = borderPreviewToColor();
    const uint8_t g6[] = {3, 9, 15, 21, 27, 33};
    for (uint8_t g : g6) setGroup(g, col);
  } else {
    const uint8_t g6[] = {3, 9, 15, 21, 27, 33};
    for (uint8_t i = 0; i < 6; ++i) {
      uint16_t hue = (uint16_t)i * (65536 / 6);
      uint32_t c = borderStrip.gamma32(borderStrip.ColorHSV(hue));
      setGroup(g6[i], c);
    }
  }
  borderStrip.show();
}

// ===================== Joker ====================
static uint8_t jokerMode = 0;   // 0 = Gold, 1 = Regenbogen
static uint8_t jokerPos  = 0;
static int8_t  jokerDir  = 1;
static unsigned long jokerLastStepMs = 0;
static unsigned long jokerPhaseStartMs = 0;
static bool jokerActive = false;

static void clearJoker() {
  uint16_t base2  = groupBase(2);
  for (uint8_t i = 0; i < 12; ++i) {
    gameStrip.setPixelColor(base2 + i, 0);
  }
  gameStrip.show();
}

static void updateJokerAnimation() {
  if (!jokerActive) return;
  unsigned long now = millis();
  if (now - jokerLastStepMs < 30) return; // ~33fps
  jokerLastStepMs = now;

  uint16_t base2 = groupBase(2);

  if (jokerMode == 1) {
    // Continuous rainbow across 12 LEDs, hue shifts over time
    static uint16_t hueBase = 0;
    hueBase += 64; // speed of hue shift
    for (uint8_t i = 0; i < 12; ++i) {
      uint32_t c = gameStrip.gamma32(gameStrip.ColorHSV(hueBase + i * (65536 / 12)));
      gameStrip.setPixelColor(base2 + i, c);
    }
    gameStrip.show();
    return;
  }

  // Gold sweep back and forth
  const uint32_t gold = gameStrip.Color(255, 180, 0);
  // clear group 2
  for (uint8_t i = 0; i < 12; ++i) gameStrip.setPixelColor(base2 + i, 0);
  // draw head and small tail
  uint8_t head = jokerPos % 12;
  gameStrip.setPixelColor(base2 + head, gold);
  if (head > 0) gameStrip.setPixelColor(base2 + head - 1, gameStrip.Color(120, 85, 0));
  if (head < 11) gameStrip.setPixelColor(base2 + head + 1, gameStrip.Color(120, 85, 0));

  // advance
  if (jokerDir > 0) {
    if (jokerPos >= 11) { jokerDir = -1; } else { jokerPos++; }
  } else {
    if (jokerPos == 0) { jokerDir = 1; } else { jokerPos--; }
  }

  gameStrip.show();
}

// ===================== Spin =====================
static int16_t spinAccelMin10 = 5,  spinAccelMax10  = 15;
static int16_t spinMaxSpdMin10 = 5, spinMaxSpdMax10 = 20;
static int16_t spinDecelMin10 = 5,  spinDecelMax10  = 15;
static uint16_t spinStepBaseMs = 20;
static bool spinInProgress = false;

static void handleSpinParams(int aMin,int aMax,int mMin,int mMax,int dMin,int dMax,int stepMs) {
  spinAccelMin10   = aMin;
  spinAccelMax10   = aMax;
  spinMaxSpdMin10  = mMin;
  spinMaxSpdMax10  = mMax;
  spinDecelMin10   = dMin;
  spinDecelMax10   = dMax;
  spinStepBaseMs   = stepMs > 0 ? stepMs : 20;
}

static void showGroupWhite(uint8_t g) {
  showGroupColor(g, gameStrip.Color(255,255,255));
}

static float randomTurns(int16_t min10, int16_t max10) {
  if (max10 < min10) {
    max10 = min10;
  }
  int16_t value = random(min10, max10 + 1);
  return value / 10.0f;
}

static uint16_t turnsToSteps(float turns) {
  if (turns <= 0.01f) {
    return 0;
  }
  return (uint16_t)roundf(turns * 36.0f);
}

static uint8_t spinOneRound() {
  if (spinInProgress) return 1;
  spinInProgress = true;
  prepareSpinColorsForSpin();

  randomSeed(micros());

  float accelTurns = randomTurns(spinAccelMin10, spinAccelMax10);
  float cruiseTurns = randomTurns(spinMaxSpdMin10, spinMaxSpdMax10);
  float decelTurns = randomTurns(spinDecelMin10, spinDecelMax10);

  if (accelTurns < 0.1f) accelTurns = 0.1f;
  if (cruiseTurns < 0.1f) cruiseTurns = 0.1f;
  if (decelTurns < 0.1f) decelTurns = 0.1f;

  uint16_t accelSteps = turnsToSteps(accelTurns);
  uint16_t cruiseSteps = turnsToSteps(cruiseTurns);
  uint16_t decelSteps = turnsToSteps(decelTurns);

  uint32_t totalSteps = (uint32_t)accelSteps + cruiseSteps + decelSteps;
  if (totalSteps == 0) {
    totalSteps = 36;
    cruiseSteps = totalSteps;
    accelSteps = decelSteps = 0;
  }

  uint8_t currentGroup = random(0, 36);
  int dir = random(0, 2) ? 1 : -1;
  uint32_t lastColor = 0;

  auto advanceStep = [&](void) {
    currentGroup = (uint8_t)((currentGroup + dir + 36) % 36);
    uint8_t groupNumber = (uint8_t)(currentGroup + 1);
    
    // Skip Joker group 2 in 5-player mode when Joker is disabled
    if (runtimePlayerState.playerCount == 5 && !runtimeJokerEnabled && groupNumber == 2) {
      currentGroup = (uint8_t)((currentGroup + dir + 36) % 36);
      groupNumber = (uint8_t)(currentGroup + 1);
      if (groupNumber == 2) { // double-skip safety
        currentGroup = (uint8_t)((currentGroup + dir + 36) % 36);
        groupNumber = (uint8_t)(currentGroup + 1);
      }
    }

    uint32_t color = resolveSpinColor(groupNumber);
    showGroupColor(groupNumber, color);
    lastColor = color;
  };

  auto runPhase = [&](uint16_t steps, float startDelay, float endDelay, bool easeIn) {
    if (steps == 0) {
      return;
    }
    for (uint16_t i = 0; i < steps; ++i) {
      float progress = (steps == 1) ? 1.0f : (float)i / (float)(steps - 1);
      float eased = easeIn ? 1.0f - (1.0f - progress) * (1.0f - progress)
                           : progress * progress;
      float delayMs = startDelay + (endDelay - startDelay) * eased;
      advanceStep();
      delay((uint16_t)delayMs);
    }
  };

  uint16_t minStepMs = spinStepBaseMs < 5 ? 5 : spinStepBaseMs;
  float cruiseDelay = (float)minStepMs;
  float slowDelay = cruiseDelay * 4.0f;

  runPhase(accelSteps, slowDelay, cruiseDelay, true);
  runPhase(cruiseSteps, cruiseDelay, cruiseDelay, false);
  runPhase(decelSteps, cruiseDelay, slowDelay, false);

  spinInProgress = false;
  uint8_t winner = (uint8_t)(currentGroup + 1);
  if (runtimePlayerState.playerCount == 5 && !runtimeJokerEnabled && winner == 2) {
    winner = (uint8_t)(((currentGroup + dir + 36) % 36) + 1);
    if (winner == 2) winner = (uint8_t)(((currentGroup + 2*dir + 36) % 36) + 1);
  }
  runtimeLastHitColor = lastColor ? lastColor : resolveSpinColor(winner);
  startHitBlink(winner, runtimeLastHitColor);
  return winner;
}

// Spielerindex aus Gruppe je nach Playercount
static uint8_t playerIndexFromGroup(uint8_t g, uint8_t pc) {
  if (pc < 2 || pc > 6) return 0;
  switch (pc) {
    case 2: return (g >= 1  && g <= 18) ? 1 : 2;
    case 3: return (g <= 12) ? 1 : (g <= 24 ? 2 : 3);
    case 4:
      if (g >= 5  && g <= 13) return 1;
      if (g >= 14 && g <= 22) return 2;
      if (g >= 23 && g <= 31) return 3;
      // 32..36 oder 1..4 -> P4
      return 4;
    case 5:
      if (g == 2) return 0; // Joker slot always reserved in 5-player mode
      if (g >= 3  && g <= 9 ) return 1;
      if (g >= 10 && g <= 16) return 2;
      if (g >= 17 && g <= 23) return 3;
      if (g >= 24 && g <= 30) return 4;
      return 5;
    case 6:
      if (g >= 4  && g <= 9 ) return 1;
      if (g >= 10 && g <= 15) return 2;
      if (g >= 16 && g <= 21) return 3;
      if (g >= 22 && g <= 27) return 4;
      if (g >= 28 && g <= 33) return 5;
      // 34..36,1..3 -> P6
      return 6;
  }
  return 0;
}

static void blinkGroupColor(uint8_t group, uint32_t color, uint8_t cycles, uint16_t onMs, uint16_t offMs) {
  uint16_t base = groupBase(group);
  for (uint8_t c = 0; c < cycles; ++c) {
    for (uint8_t i = 0; i < 12; ++i) gameStrip.setPixelColor(base + i, color);
    gameStrip.show();
    delay(onMs);
    for (uint8_t i = 0; i < 12; ++i) gameStrip.setPixelColor(base + i, 0);
    gameStrip.show();
    delay(offMs);
  }
}

// ===================== RS485 Parser ============
static char rxbuf[128];
static uint8_t rxpos = 0;

static void handleLine(const char *line) {
  if (strcmp(line, "LED_TEST") == 0) { ledRingTest(); return; }

  if (strncmp(line, "SET_BRIGHTNESS ", 15) == 0) {
    char which; int val;
    if (sscanf(line + 15, "%c %d", &which, &val) == 2) {
      val = constrain(val, 1, 255);
      if (which == 'G') {
        runtimeBrightness.game = val;
        applyBrightness(runtimeBrightness);
        brightnessPreview(gameStrip, false);
      } else if (which == 'B') {
        runtimeBrightness.border = val;
        applyBrightness(runtimeBrightness);
        brightnessPreview(borderStrip, true);
      }
    }
    return;
  }

  if (strncmp(line, "PLAYER_STATE ", 13) == 0) {
    PlayerStateSettings st = runtimePlayerState;
    int pc, mode, singleCol, ownRnd, inactive;
    if (sscanf(line + 13, "%d %d %d %d %d", &pc, &mode, &singleCol, &ownRnd, &inactive) == 5) {
      st.playerCount = constrain(pc, 2, 6);
      st.mode = constrain(mode, 0, 3);
      st.singleColor = constrain(singleCol, 0, 5);
      st.ownRandom = ownRnd ? 1 : 0;
      st.inactiveMode = constrain(inactive, 0, 2);
      applyPlayerState(st);
    }
    return;
  }

  if (strncmp(line, "BORDER_STATE ", 13) == 0) {
    BorderStateSettings st = runtimeBorderState;
    int mode, singleCol;
    if (sscanf(line + 13, "%d %d", &mode, &singleCol) == 2) {
      st.mode = constrain(mode, 0, 2);
      st.singleColor = constrain(singleCol, 0, 5);
      applyBorderState(st);
    }
    return;
  }

  if (strncmp(line, "BRIGHT_STATE ", 13) == 0) {
    BrightnessSettings st = runtimeBrightness;
    int g, b;
    if (sscanf(line + 13, "%d %d", &g, &b) == 2) {
      st.game = constrain(g, 1, 255);
      st.border = constrain(b, 1, 255);
      applyBrightness(st);
    }
    return;
  }

  if (strncmp(line, "CFG_PLAYERS ", 12) == 0) {
    int pc = 0; if (sscanf(line + 12, "%d", &pc) == 1) {
      PlayerStateSettings st = runtimePlayerState;
      st.playerCount = constrain(pc, 2, 6);
      applyPlayerState(st);
    }
    return;
  }

  if (strncmp(line, "CFG_JOKER ", 10) == 0) {
    int en = 0;
    if (sscanf(line + 10, "%d", &en) == 1) {
      runtimeJokerEnabled = (en != 0);
    }
    return;
  }

  if (strncmp(line, "BORDERS_STATE ", 14) == 0) {
    int on, pc;
    if (sscanf(line + 14, "%d %d", &on, &pc) == 2) {
      runtimeShowBorders = on != 0;
      PlayerStateSettings st = runtimePlayerState;
      st.playerCount = constrain(pc, 2, 6);
      applyPlayerState(st);
      applyBorderState(runtimeBorderState);
    }
    return;
  }

  if (strncmp(line, "JOKER_PREVIEW ", 14) == 0) {
    int mode, colorIdx;
    if (sscanf(line + 14, "%d %d", &mode, &colorIdx) >= 1) { jokerMode = (mode == 1) ? 1 : 0; (void)colorIdx; }
    return;
  }

  if (strcmp(line, "JOKER:PREVIEW:START") == 0) {
    jokerActive = true; jokerPos = 0; jokerDir = 1; jokerLastStepMs = 0; jokerPhaseStartMs = millis(); return;
  }
  if (strcmp(line, "JOKER:PREVIEW:STOP") == 0) {
    jokerActive = false; clearJoker(); return;
  }

  if (strncmp(line, "PLAYER_PREVIEW ", 15) == 0) {
    int mode, singleColor, ownRand, inactive;
    if (sscanf(line + 15, "%d %d %d %d", &mode, &singleColor, &ownRand, &inactive) >= 1) {
      previewPlayerMode = mode;
      previewPlayerSingleColor = singleColor;
      previewPlayerOwnRandom = ownRand;
      previewInactiveMode = inactive;
      runPlayerPreview();
    }
    return;
  }

  if (strncmp(line, "BORDER_PREVIEW ", 15) == 0) {
    int mode, singleColor;
    if (sscanf(line + 15, "%d %d", &mode, &singleColor) >= 1) {
      previewBorderMode = mode;
      previewBorderSingleColor = singleColor;
      runBorderPreview();
    }
    return;
  }

  if (strcmp(line, "PREVIEW_CLEAR") == 0) { clearAll(); return; }
  if (strcmp(line, "GAME_END") == 0)     { jokerActive = false; clearAll(); return; }

  if (strncmp(line, "SPIN_PARAMS ", 12) == 0) {
    int aMin, aMax, mMin, mMax, dMin, dMax, ms;
    if (sscanf(line + 12, "%d %d %d %d %d %d %d", &aMin, &aMax, &mMin, &mMax, &dMin, &dMax, &ms) == 7)
      handleSpinParams(aMin, aMax, mMin, mMax, dMin, dMax, ms);
    return;
  }

  if (strcmp(line, "SPIN_START") == 0) {
    if (!spinInProgress) {
      stopHitBlink();
      clearGame();
      gameStrip.show();
      uint8_t hitGroup = spinOneRound();
      char buf[16];
      snprintf(buf, sizeof(buf), "HIT %u\n", hitGroup);
      rs485SendLine(buf);   // über RS485 senden
    }
    return;
  }

  Serial.print(F("[UNKNOWN] ")); Serial.println(line);
}

static void rs485Poll() {
  while (RS.available()) {
    char c = (char)RS.read();
    if (c == '\n') {
      rxbuf[rxpos] = 0;
      if (rxpos > 0) handleLine(rxbuf);
      rxpos = 0;
    } else if (c != '\r') {
      if (rxpos < sizeof(rxbuf) - 1) {
        rxbuf[rxpos++] = c;
      } else {
        // overflow -> reset
        rxpos = 0;
      }
    }
  }
}

// ===================== Setup / Loop ============
void setup() {
  Serial.begin(115200);
  pinMode(RS485_DE_PIN, OUTPUT);
  digitalWrite(RS485_DE_PIN, LOW);
  RS.begin(BAUD);

  gameStrip.begin();
  borderStrip.begin();
  applyBrightness(runtimeBrightness);
  clearAll();
  initPlayerColors();
  refreshRuntimePalette(false);
  applyPlayerState(runtimePlayerState);
  applyBorderState(runtimeBorderState);

  Serial.println(F("MEGA RS485 PitterOmat ready."));
}

void loop() {
  rs485Poll();
  updateJokerAnimation();
  updateHitBlink();
  delay(2);
}
