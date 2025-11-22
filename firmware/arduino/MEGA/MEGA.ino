// MEGA_RS485_PitterOmat.ino
// Arduino Mega RS485 SLAVE + Adafruit NeoPixel control für Spiel + Grenzen

// Forward-Decl fuer Arduino-Prototyperzeugung (LlSpinPlan wird weiter unten definiert)
struct LlSpinPlan;

#include <Arduino.h>
#include <math.h>
#include <Adafruit_NeoPixel.h>

// ===================== RS485 =====================
constexpr uint32_t BAUD = 115200;
#define RS Serial1
constexpr int RS485_DE_PIN = 7;

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

// Neue, vom ESP vorgegebene Spin-Planung für LichtLoser
struct LlSpinPlan {
  bool active;
  uint8_t startGroup;   // 1..36
  uint8_t currentGroup; // 1..36
  uint16_t accelSteps;
  uint16_t maxSteps;
  uint16_t decelSteps;
  int8_t dir;           // -1 oder +1
  uint16_t stepMs;
  uint16_t blinkMs;
  uint32_t stepIndex;
  unsigned long lastStepMs;
  bool blinkOn;
  unsigned long lastBlinkMs;
  uint32_t totalSteps;
  uint32_t hitColor;
};

static LlSpinPlan g_llSpinPlan{false, 1, 1, 0, 0, 0, 1, 20, 200, 0, 0, false, 0, 0, 0};
static unsigned long g_lastLlSpinCmdMs = 0;

static uint8_t playerIndexFromGroup(uint8_t group, uint8_t pc);
static void blinkGroupColor(uint8_t group, uint32_t color, uint8_t cycles, uint16_t onMs, uint16_t offMs);

static void handleLine(const char *line);
static void rs485Poll();
static void updateLlSpin();
static void stopLlSpinPlan(bool clearGameLeds);

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
  clearGame();
  clearBorder();
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
  clearAll();
  gameStrip.setBrightness(BRIGHT_GAME);
  borderStrip.setBrightness(BRIGHT_BORD);
  sweepForwardLogical(gameStrip, GAME_LED_COUNT, false);
  sweepForwardLogical(borderStrip, BORDER_LED_COUNT, true);
}

// ===================== Borders ==================
static uint8_t currentPlayerCount = 0;
static bool g_jokerEnabled = false;

// Border-Preview-State (wird auch genutzt, um die Farbe der Marker festzulegen)
static uint8_t previewBorderMode = 0;        // 0=einfarbig, 1=Regenbogen
static uint8_t previewBorderSingleColor = 0; // 0=braun, 1=grau

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
  const uint32_t colorOn  = borderPreviewToColor();
  const uint32_t colorDim = borderStrip.Color(8,8,8);

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
    switch (pc) {
      case 2: { const uint8_t g[] = {27, 9};              for (uint8_t i : g) setGroup(i, colorOn); } break;
      case 3: { const uint8_t g[] = {30, 6, 18};          for (uint8_t i : g) setGroup(i, colorOn); } break;
      case 4: { const uint8_t g[] = {31, 4, 13, 22};      for (uint8_t i : g) setGroup(i, colorOn); } break;
      case 5: { const uint8_t g[] = {33, 4, 5, 12, 19, 26};for (uint8_t i : g) setGroup(i, colorOn); } break;
      case 6: { const uint8_t g[] = {33, 3, 9, 15, 21, 27};for (uint8_t i : g) setGroup(i, colorOn);} break;
      default: break;
    }
  }
  borderStrip.show();
}

// 2s Brightness-Vorschau: markiert exemplarisch Gruppen 1,9,18,24
static void brightnessPreview(Adafruit_NeoPixel &strip, bool isBorder) {
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
static uint8_t colorMode = 0;
static uint8_t colorSingleIndex = 0;
static uint8_t colorOwnRandom = 0;
static bool colorRandomPerHit = false;
static uint32_t lastSpinColor = 0;

static uint32_t makeSingleColor(uint8_t idx) {
  switch (idx) {
    case 1: return gameStrip.Color(0,0,255);   // Blau
    case 2: return gameStrip.Color(0,255,0);   // Grün
    case 3: return gameStrip.Color(255,0,0);   // Rot
    default: {
      uint16_t hue = (uint16_t)random(0, 65536);
      return gameStrip.gamma32(gameStrip.ColorHSV(hue));
    }
  }
}

static void llShowGroupColor(uint8_t group, uint32_t color) {
  clearGame();
  uint16_t base = groupBase(group);
  for (uint8_t i = 0; i < 12; ++i) {
    gameStrip.setPixelColor(base + i, color);
  }
  gameStrip.show();
}

static uint32_t computeSpinColor(uint8_t group) {
  if (g_jokerEnabled && currentPlayerCount == 5 && group == 5) {
    return gameStrip.Color(255,180,0);
  }
  uint8_t pc = currentPlayerCount;
  if (pc < 2 || pc > 6) pc = 6;
  uint8_t pidx = playerIndexFromGroup(group, pc);
  uint32_t col = gameStrip.Color(255,180,0);
  if (pidx < 6) {
    if (colorMode == 2) {
      // random per hit/group
      uint32_t newCol;
      do {
        uint16_t hue = (uint16_t)random(0, 65536);
        newCol = gameStrip.gamma32(gameStrip.ColorHSV(hue));
      } while (newCol == lastSpinColor);
      lastSpinColor = newCol;
      col = newCol;
    } else {
      col = playerColors[pidx];
    }
  }
  return col;
}

static void applyPlayerColorConfig() {
  if (colorMode == 0) {
    // Single color for all
    if (colorSingleIndex == 4) {
      // Rainbow Gradient
      for (uint8_t i = 0; i < 6; ++i) {
        uint16_t hue = (uint16_t)i * (65535 / 6);
        playerColors[i] = gameStrip.gamma32(gameStrip.ColorHSV(hue));
      }
    } else {
      uint32_t col = makeSingleColor(colorSingleIndex);
      for (uint8_t i = 0; i < 6; ++i) playerColors[i] = col;
    }
  } else if (colorMode == 1) {
    if (colorOwnRandom) {
      for (uint8_t i = 0; i < 6; ++i) {
        uint16_t hue = (uint16_t)random(0, 65536);
        playerColors[i] = gameStrip.gamma32(gameStrip.ColorHSV(hue));
      }
    } else {
      initPlayerColors(); // feste Standardfarben
    }
  } else if (colorMode == 2) {
    // random baseline; echte Random-Per-Hit später
    for (uint8_t i = 0; i < 6; ++i) {
      uint16_t hue = (uint16_t)random(0, 65536);
      playerColors[i] = gameStrip.gamma32(gameStrip.ColorHSV(hue));
    }
  }
}

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

static void runPlayerPreview() {
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
        const uint8_t ranges[2][2] = { {28, 9}, {10, 27} };
        for (uint8_t p = 0; p < 2; ++p) {
          uint32_t col = previewPlayerOwnRandom ? gameStrip.gamma32(gameStrip.ColorHSV((uint16_t)(p * 40) * 256))
                                                : playerColors[p % 6];
          fillRange(ranges[p][0], ranges[p][1], col);
        }
      } break;
      case 3: {
        const uint8_t ranges[3][2] = { {31, 6}, {7, 18}, {19, 30} };
        for (uint8_t p = 0; p < 3; ++p) {
          uint32_t col = previewPlayerOwnRandom ? gameStrip.gamma32(gameStrip.ColorHSV((uint16_t)(p * 40) * 256))
                                                : playerColors[p % 6];
          fillRange(ranges[p][0], ranges[p][1], col);
        }
      } break;
      case 4: {
        uint8_t segs[4][2] = { {32,4}, {5,13}, {14,22}, {23,31} };
        for (uint8_t p = 0; p < 4; ++p) {
          uint32_t col = previewPlayerOwnRandom ? gameStrip.gamma32(gameStrip.ColorHSV((uint16_t)(p * 40) * 256))
                                                : playerColors[p % 6];
          fillRange(segs[p][0], segs[p][1], col);
        }
      } break;
      case 5: {
        uint8_t segs[5][2] = { {34,4}, {6,12}, {13,19}, {20,26}, {27,33} };
        for (uint8_t p = 0; p < 5; ++p) {
          uint32_t col = previewPlayerOwnRandom ? gameStrip.gamma32(gameStrip.ColorHSV((uint16_t)(p * 40) * 256))
                                                : playerColors[p % 6];
          fillRange(segs[p][0], segs[p][1], col);
        }
      } break;
      case 6: {
        uint8_t segs[6][2] = { {34,3}, {4,9}, {10,15}, {16,21}, {22,27}, {28,33} };
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
    uint16_t baseJoker = groupBase(5);
    if (g_jokerEnabled) {
      // Joker an: zeige gewählte Farbe (Gold oder Rainbow-Standbild)
      if (previewInactiveMode == 2 || previewInactiveMode == 1) {
        uint32_t col = (previewInactiveMode == 2) ? gameStrip.Color(128, 90, 0) : gameStrip.Color(80,80,80);
        for (uint8_t i = 0; i < 12; ++i) gameStrip.setPixelColor(baseJoker + i, col);
      } else {
        // Rainbow Standbild als Fallback
        for (uint8_t i = 0; i < 12; ++i) {
          uint16_t hue = (uint16_t)i * (65535 / 12);
          gameStrip.setPixelColor(baseJoker + i, gameStrip.gamma32(gameStrip.ColorHSV(hue)));
        }
      }
    } else {
      // Joker aus: Segment dunkel
      for (uint8_t i = 0; i < 12; ++i) gameStrip.setPixelColor(baseJoker + i, 0);
    }
  }

  gameStrip.show();
}

// ===================== Border Preview ===========
static void runBorderPreview() {
  for (uint16_t i = 0; i < BORDER_LED_COUNT; ++i) borderStrip.setPixelColor(i, 0);

  auto setGroup = [&](uint8_t group, uint32_t col) {
    if (group < 1 || group > 36) return;
    uint16_t start = groupBase(group);
    for (uint8_t i = 0; i < 12; ++i)
      borderStrip.setPixelColor(borderMap(start + i), col);
  };

  if (previewBorderMode == 0) {
    uint32_t col = borderPreviewToColor();
    const uint8_t g6[] = {33, 4, 5, 12, 19, 26};
    for (uint8_t g : g6) setGroup(g, col);
  } else {
    const uint8_t g6[] = {33, 4, 5, 12, 19, 26};
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
static bool jokerHitActive = false;
static uint8_t jokerHitMode = 0; // 0=gold, 1=rainbow
static int8_t jokerHitPos = 0;
static int8_t jokerHitDir = 1;
static unsigned long jokerHitLastStepMs = 0;

static void clearJoker() {
  uint16_t base5 = groupBase(5);
  for (uint8_t i = 0; i < 12; ++i) gameStrip.setPixelColor(base5 + i, 0);
  gameStrip.show();
}

static void updateJokerAnimation() {
  if (!jokerActive) return;
  unsigned long now = millis();
  if (now - jokerLastStepMs < 30) return;
  jokerLastStepMs = now;
  unsigned long phaseMs = now - jokerPhaseStartMs;

  const uint32_t gold = gameStrip.Color(255, 180, 0);
  uint16_t base5  = groupBase(5);

  if (jokerMode == 1 && phaseMs >= 6000) {
    for (uint8_t i = 0; i < 12; ++i) gameStrip.setPixelColor(base5 + i, gold);
    for (uint8_t g = 1; g <= 36; ++g) {
      if (g == 5) continue;
      uint16_t base = groupBase(g);
      uint16_t hue = (uint16_t)((phaseMs / 10) + g * (65536/36));
      for (uint8_t i = 0; i < 12; ++i) gameStrip.setPixelColor(base + i, gameStrip.ColorHSV(hue));
    }
  } else if (phaseMs < 3000) {
    for (uint8_t i = 0; i < 12; ++i) gameStrip.setPixelColor(base5 + i, 0);
    gameStrip.setPixelColor(base5 + jokerPos, gold);
    if (jokerPos == 0 || jokerPos == 11) jokerDir = -jokerDir;
  } else if (phaseMs < 6000) {
    bool on = ((phaseMs / 250) % 2) == 0;
    uint32_t c = on ? gold : 0;
    for (uint8_t i = 0; i < 12; ++i) gameStrip.setPixelColor(base5 + i, c);
  } else {
    for (uint8_t i = 0; i < 12; ++i) gameStrip.setPixelColor(base5 + i, gold);
  }
  jokerPos += jokerDir;
  gameStrip.show();
}

static void clearJokerHit() {
  jokerHitActive = false;
  uint16_t base5 = groupBase(5);
  for (uint8_t i = 0; i < 12; ++i) gameStrip.setPixelColor(base5 + i, 0);
  gameStrip.show();
}

static void updateJokerHitAnimation() {
  if (!jokerHitActive) return;
  unsigned long now = millis();
  if (now - jokerHitLastStepMs < 40) return;
  jokerHitLastStepMs = now;

  uint16_t base5 = groupBase(5);
  // clear previous
  for (uint8_t i = 0; i < 12; ++i) gameStrip.setPixelColor(base5 + i, 0);

  if (jokerHitMode == 0) {
    // Gold: wandernde einzelne LED
    uint32_t col = gameStrip.Color(255, 180, 0);
    gameStrip.setPixelColor(base5 + jokerHitPos, col);
    jokerHitPos += jokerHitDir;
    if (jokerHitPos <= 0 || jokerHitPos >= 11) {
      jokerHitDir = -jokerHitDir;
    }
  } else {
    // Rainbow: kompletter Block als laufender Regenbogen
    uint16_t hueBase = (uint16_t)((now / 5) & 0xFFFF);
    for (uint8_t i = 0; i < 12; ++i) {
      uint16_t hue = hueBase + (uint16_t)i * (65535 / 12);
      gameStrip.setPixelColor(base5 + i, gameStrip.gamma32(gameStrip.ColorHSV(hue)));
    }
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
  clearGame();
  uint16_t base = groupBase(g);
  for (uint8_t i = 0; i < 12; ++i) gameStrip.setPixelColor(base + i, gameStrip.Color(255,255,255));
  gameStrip.show();
}

static uint8_t spinOneRound() {
  if (spinInProgress) return 1;
  spinInProgress = true;

  randomSeed(micros());
  auto randIn10 = [](int16_t mi, int16_t ma) -> float {
    if (ma < mi) ma = mi;
    int16_t r = random(mi, ma + 1);
    return r / 10.0f;
  };

  float accelTurns = randIn10(spinAccelMin10, spinAccelMax10);
  float maxTurns   = randIn10(spinMaxSpdMin10, spinMaxSpdMax10);
  float decelTurns = randIn10(spinDecelMin10, spinDecelMax10);

  if (accelTurns < 0.1f) accelTurns = 0.1f;
  if (maxTurns   < 0.1f) maxTurns   = 0.1f;
  if (decelTurns < 0.1f) decelTurns = 0.1f;

  uint16_t accelSteps = (uint16_t)(accelTurns * 36.0f);
  uint16_t maxSteps   = (uint16_t)(maxTurns   * 36.0f);
  uint16_t decelSteps = (uint16_t)(decelTurns * 36.0f);

  uint32_t totalSteps = (uint32_t)accelSteps + maxSteps + decelSteps;
  if (totalSteps == 0) totalSteps = 36;

  uint8_t currentGroup = random(0, 36); // 0..35 intern
  int dir = random(0, 2) ? 1 : -1;

  for (uint32_t step = 0; step < totalSteps; ++step) {
    float fDelay;
    if (step < accelSteps) {
      float k = (float)step / (float)accelSteps;
      fDelay = 1.5f - k;
    } else if (step < accelSteps + maxSteps) {
      fDelay = 0.5f;
    } else {
      float k = (float)(step - accelSteps - maxSteps) / (float)decelSteps;
      fDelay = 0.5f + k * 1.5f;
    }
    currentGroup = (uint8_t)((currentGroup + dir + 36) % 36);
    showGroupWhite((uint8_t)(currentGroup + 1));
    delay((uint16_t)(spinStepBaseMs * fDelay));
  }

  spinInProgress = false;
  return (uint8_t)(currentGroup + 1); // 1..36
}

// Spielerindex aus Gruppe je nach Playercount (0-basiert, Joker = 255)
static uint8_t playerIndexFromGroup(uint8_t g, uint8_t pc) {
  if (pc < 2 || pc > 6) {
    return 255;
  }
  switch (pc) {
    case 2:
      if ((g >= 28 && g <= 36) || (g >= 1 && g <= 9)) return 0;
      return 1; // 10..27
    case 3:
      if ((g >= 31 && g <= 36) || (g >= 1 && g <= 6)) return 0;
      if (g >= 7  && g <= 18) return 1;
      // 19..30 -> Spieler 2
      return 2;
    case 4:
      if ((g >= 32 && g <= 36) || (g >= 1 && g <= 4)) return 0;
      if (g >= 5  && g <= 13) return 1;
      if (g >= 14 && g <= 22) return 2;
      // 23..31 -> Spieler 3
      return 3;
    case 5:
      if (g == 5) return 255; // Joker-Segment
      if ((g >= 34 && g <= 36) || (g >= 1 && g <= 4)) return 0;
      if (g >= 6  && g <= 12) return 1;
      if (g >= 13 && g <= 19) return 2;
      if (g >= 20 && g <= 26) return 3;
      // 27..33 -> Spieler 4 (index 4)
      return 4;
    case 6:
      if ((g >= 34 && g <= 36) || (g >= 1 && g <= 3)) return 0;
      if (g >= 4  && g <= 9 ) return 1;
      if (g >= 10 && g <= 15) return 2;
      if (g >= 16 && g <= 21) return 3;
      if (g >= 22 && g <= 27) return 4;
      // 28..33 -> Spieler 5
      return 5;
  }
  return 255;
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

// ===================== LichtLoser Spin Plan (vom ESP) =======================

static float llStepDelayFactor(const LlSpinPlan &plan, uint32_t step) {
  uint32_t accel = plan.accelSteps;
  uint32_t max   = plan.maxSteps;
  uint32_t decel = plan.decelSteps;

  if (step < accel && accel > 0) {
    float k = (float)step / (float)accel;
    // exponentiell abfallend: startet bei 1.5 und nähert sich 0.5
    float decay = expf(-3.0f * k);
    return 0.5f + decay;
  }
  if (step < accel + max) {
    return 0.5f;
  }
  if (decel > 0) {
    uint32_t decelIndex = step - accel - max;
    float k = (float)decelIndex / (float)decel;
    // exponentiell ansteigend: wächst von 0.5 zu 2.0
    const float denom = 1.0f - expf(-3.0f);
    float rise = (1.0f - expf(-3.0f * k)) / (denom > 0.0f ? denom : 1.0f);
    return 0.5f + rise * 1.5f;
  }
  return 1.0f;
}

static void llShowGroupWhite(uint8_t group) {
  clearGame();
  uint16_t base = groupBase(group);
  for (uint8_t i = 0; i < 12; ++i) {
    gameStrip.setPixelColor(base + i, gameStrip.Color(255,255,255));
  }
  gameStrip.show();
}

static void llSetGroupColor(uint8_t group, uint32_t color) {
  uint16_t base = groupBase(group);
  for (uint8_t i = 0; i < 12; ++i) {
    gameStrip.setPixelColor(base + i, color);
  }
  gameStrip.show();
}

static void startLlSpinPlan(uint8_t startGroup,
                            uint16_t accelSteps,
                            uint16_t maxSteps,
                            uint16_t decelSteps,
                            int8_t dir,
                            uint16_t stepMs,
                            uint16_t blinkMs) {
  stopLlSpinPlan(false);
  applyPlayerColorConfig(); // refresh colors per spin (handles random modes)
  g_llSpinPlan.active = true;
  g_llSpinPlan.startGroup = startGroup;
  g_llSpinPlan.currentGroup = startGroup;
  g_llSpinPlan.accelSteps = accelSteps;
  g_llSpinPlan.maxSteps = maxSteps;
  g_llSpinPlan.decelSteps = decelSteps;
  g_llSpinPlan.dir = (dir >= 0) ? 1 : -1;
  g_llSpinPlan.stepMs = stepMs ? stepMs : 20;
  g_llSpinPlan.blinkMs = blinkMs ? blinkMs : 200;
  g_llSpinPlan.stepIndex = 0;
  g_llSpinPlan.lastStepMs = millis();
  g_llSpinPlan.blinkOn = false;
  g_llSpinPlan.lastBlinkMs = millis();
  g_llSpinPlan.totalSteps = (uint32_t)accelSteps + maxSteps + decelSteps;
  if (g_llSpinPlan.totalSteps == 0) {
    g_llSpinPlan.totalSteps = 36;
  }
  g_llSpinPlan.hitColor = 0;
  // neuer Spin beendet Joker-Hit-Anzeige
  clearJokerHit();
}

static void stopLlSpinPlan(bool clearGameLeds) {
  if (!g_llSpinPlan.active) {
    if (clearGameLeds) {
      clearGame();
    }
    return;
  }
  g_llSpinPlan.active = false;
  g_llSpinPlan.blinkOn = false;
  g_llSpinPlan.stepIndex = g_llSpinPlan.totalSteps;
  if (clearGameLeds) {
    llSetGroupColor(g_llSpinPlan.currentGroup, 0);
  }
}

static void updateLlSpin() {
  if (!g_llSpinPlan.active) {
    return;
  }

  unsigned long now = millis();

  if (g_llSpinPlan.stepIndex < g_llSpinPlan.totalSteps) {
    float fDelay = llStepDelayFactor(g_llSpinPlan, g_llSpinPlan.stepIndex);
    uint32_t delayMs = (uint32_t)(g_llSpinPlan.stepMs * fDelay);
    if (delayMs < 1) {
      delayMs = 1;
    }
    if (now - g_llSpinPlan.lastStepMs >= delayMs) {
      g_llSpinPlan.lastStepMs = now;
      int16_t idx = (int16_t)(g_llSpinPlan.currentGroup - 1) + g_llSpinPlan.dir;
      if (idx < 0) {
        idx += 36;
      } else if (idx >= 36) {
        idx -= 36;
      }
      // Joker aus und 5 Spieler: Gruppe 5 überspringen
      if (!g_jokerEnabled && currentPlayerCount == 5 && idx == 4) { // idx 4 => Gruppe 5
        idx += g_llSpinPlan.dir;
    if (idx < 0) idx += 36;
    if (idx >= 36) idx -= 36;
  }
  g_llSpinPlan.currentGroup = (uint8_t)(idx + 1);
  // Kurz aufblitzen in konfigurierter Farbe (vorherige Gruppe wird gelöscht)
  uint32_t c = computeSpinColor(g_llSpinPlan.currentGroup);
  llShowGroupColor(g_llSpinPlan.currentGroup, c);
  g_llSpinPlan.stepIndex++;
    }
    return;
  }

  if (g_llSpinPlan.hitColor == 0) {
    uint8_t pc = currentPlayerCount;
    if (pc < 2 || pc > 6) {
      pc = 6;
    }
    uint8_t pidx = playerIndexFromGroup(g_llSpinPlan.currentGroup, pc);
    if (pidx < 6) {
      if (colorMode == 2) {
        // random per hit
        uint16_t hue = (uint16_t)random(0,65536);
        g_llSpinPlan.hitColor = gameStrip.gamma32(gameStrip.ColorHSV(hue));
      } else {
        g_llSpinPlan.hitColor = playerColors[pidx];
      }
    } else {
      g_llSpinPlan.hitColor = gameStrip.Color(255,180,0);
    }
  }

  if (g_llSpinPlan.blinkMs == 0) {
    llSetGroupColor(g_llSpinPlan.currentGroup, g_llSpinPlan.hitColor);
    Serial.print(F("[LL] Final group: "));
    Serial.println(g_llSpinPlan.currentGroup);
    return;
  }

  if (now - g_llSpinPlan.lastBlinkMs >= g_llSpinPlan.blinkMs) {
    g_llSpinPlan.lastBlinkMs = now;
    g_llSpinPlan.blinkOn = !g_llSpinPlan.blinkOn;
    if (g_llSpinPlan.blinkOn) {
      llSetGroupColor(g_llSpinPlan.currentGroup, g_llSpinPlan.hitColor);
      Serial.print(F("[LL] Final group: "));
      Serial.println(g_llSpinPlan.currentGroup);
    } else {
      llSetGroupColor(g_llSpinPlan.currentGroup, 0);
    }
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
        BRIGHT_GAME = val; gameStrip.setBrightness(BRIGHT_GAME); brightnessPreview(gameStrip, false);
      } else if (which == 'B') {
        BRIGHT_BORD = val; borderStrip.setBrightness(BRIGHT_BORD); brightnessPreview(borderStrip, true);
      }
    }
    return;
  }

  if (strncmp(line, "CFG_PLAYERS ", 12) == 0) {
    int pc = 0; if (sscanf(line + 12, "%d", &pc) == 1) currentPlayerCount = (uint8_t)pc;
    return;
  }

  if (strncmp(line, "CFG_PLAYER_COLORS ", 18) == 0) {
    int m=0,s=0,o=0,r=0;
    if (sscanf(line + 18, "%d %d %d %d", &m, &s, &o, &r) >= 2) {
      colorMode = (uint8_t)m;
      colorSingleIndex = (uint8_t)s;
      colorOwnRandom = (uint8_t)o;
      colorRandomPerHit = (r != 0);
      applyPlayerColorConfig();
    }
    return;
  }

  if (strncmp(line, "CFG_JOKER ", 10) == 0) {
    int en = 0;
    if (sscanf(line + 10, "%d", &en) == 1) {
      g_jokerEnabled = (en != 0);
    }
    return;
  }

  if (strncmp(line, "BORDERS_STATE ", 14) == 0) {
    int on, pc;
    if (sscanf(line + 14, "%d %d", &on, &pc) == 2) setBordersForPlayers((uint8_t)pc, on != 0);
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
    jokerActive = false; clearJoker(); clearJokerHit(); return;
  }
  if (strncmp(line, "JOKER_HIT ", 10) == 0) {
    int mode = 0;
    sscanf(line + 10, "%d", &mode);
    jokerHitMode = (mode == 1) ? 1 : 0;
    jokerHitActive = true;
    jokerHitPos = 0;
    jokerHitDir = 1;
    jokerHitLastStepMs = 0;
    clearJoker(); // ensure only hit animation is running on group 5
    return;
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

  if (strcmp(line, "PREVIEW_CLEAR") == 0) {
    stopLlSpinPlan(true);
    clearAll();
    jokerHitActive = false;
    return;
  }
  if (strcmp(line, "GAME_END") == 0) {
    jokerActive = false;
    jokerHitActive = false;
    stopLlSpinPlan(true);
    clearAll();
    return;
  }

  if (strncmp(line, "SPIN_PARAMS ", 12) == 0) {
    int aMin, aMax, mMin, mMax, dMin, dMax, ms;
    if (sscanf(line + 12, "%d %d %d %d %d %d %d", &aMin, &aMax, &mMin, &mMax, &dMin, &dMax, &ms) == 7)
      handleSpinParams(aMin, aMax, mMin, mMax, dMin, dMax, ms);
    return;
  }

  if (strcmp(line, "SPIN_START") == 0) {
    if (!spinInProgress) {
      uint8_t hitGroup = spinOneRound();
      // kurzes Blink in Spielerfarbe
      uint8_t pidx = playerIndexFromGroup(hitGroup, currentPlayerCount);
      uint32_t col = (pidx >= 1 && pidx <= 6) ? playerColors[pidx - 1] : gameStrip.Color(255,180,0); // Joker→Gold
      blinkGroupColor(hitGroup, col, 5, 80, 80);

    }
    return;
  }

  if (strncmp(line, "LL_SPIN ", 8) == 0) {
    unsigned long now = millis();
    if (now - g_lastLlSpinCmdMs < 50) {
      return;
    }
    g_lastLlSpinCmdMs = now;
    int startGroup, accelSteps, maxSteps, decelSteps;
    int dir, stepMs, blinkMs;
    int jokerEn = 0, cMode = 0, cSingle = 0, cOwn = 0, cRandHit = 0;
    int count = sscanf(line + 8, "%d %d %d %d %d %d %d %d %d %d %d",
                       &startGroup, &accelSteps, &maxSteps, &decelSteps,
                       &dir, &stepMs, &blinkMs,
                       &jokerEn, &cMode, &cSingle, &cOwn, &cRandHit);
    if (count >= 6) {
      if (startGroup < 1) startGroup = 1;
      if (startGroup > 36) startGroup = 36;
      if (accelSteps < 0) accelSteps = 0;
      if (maxSteps < 0) maxSteps = 0;
      if (decelSteps < 0) decelSteps = 0;
      if (stepMs <= 0) stepMs = 20;
      if (count < 7 || blinkMs < 0) {
        blinkMs = stepMs * 2;
      }
      if (count >= 11) {
        g_jokerEnabled = (jokerEn != 0);
        colorMode = (uint8_t)cMode;
        colorSingleIndex = (uint8_t)cSingle;
        colorOwnRandom = (uint8_t)cOwn;
        colorRandomPerHit = (cRandHit != 0);
        applyPlayerColorConfig();
      }
      startLlSpinPlan((uint8_t)startGroup,
                      (uint16_t)accelSteps,
                      (uint16_t)maxSteps,
                      (uint16_t)decelSteps,
                      (int8_t)dir,
                      (uint16_t)stepMs,
                      (uint16_t)blinkMs);
    }
    return;
  }

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
  pinMode(RS485_DE_PIN, OUTPUT);
  digitalWrite(RS485_DE_PIN, LOW);
  RS.begin(BAUD);

  gameStrip.begin();
  borderStrip.begin();
  gameStrip.setBrightness(BRIGHT_GAME);
  borderStrip.setBrightness(BRIGHT_BORD);
  clearAll();
  initPlayerColors();

}

void loop() {
  rs485Poll();
  updateJokerAnimation();
  updateJokerHitAnimation();
  updateLlSpin();
  delay(1);
}

