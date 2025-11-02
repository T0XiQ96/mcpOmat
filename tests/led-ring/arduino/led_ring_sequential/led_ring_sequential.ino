#include <Adafruit_NeoPixel.h>

/**
 * LED-Ring: Game normal vorwärts (0->431)
 * Border: logisches Vorwärts durch Mapping auf physische Reihenfolge
 */

// ---- Pins & Parameter ------------------------------------------------------
constexpr uint8_t  GAME_PIN          = 7;
constexpr uint8_t  BORDER_PIN        = 13;
constexpr uint16_t GAME_LED_COUNT    = 432; // 36 x 12
constexpr uint16_t BORDER_LED_COUNT  = 432; // 36 x 12
constexpr uint8_t  BRIGHTNESS        = 25;  // ~10%
constexpr uint16_t STEP_DELAY_MS     = 25;

// ---- Funktionszeiger-Typ (MUSS ganz oben stehen) --------------------------
using IndexMapFn = uint16_t (*)(uint16_t);

// ---- Strips ----------------------------------------------------------------
Adafruit_NeoPixel gameStrip(GAME_LED_COUNT,    GAME_PIN,    NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel borderStrip(BORDER_LED_COUNT, BORDER_PIN, NEO_GRB + NEO_KHZ800);

bool runOnce = false;

// ---- Mapping-Funktionen ----------------------------------------------------
// 1: Identität (Game-Strip ist bereits 0..431 vorwärts)
static inline uint16_t identityMap(uint16_t i) {
  return i;
}

// 2: Border-Logik -> physischer Index
//    Blöcke à 12 LEDs, Blockreihenfolge „von außen nach innen“ (letzter Block zuerst),
//    innerhalb eines Blocks 0..11. So wird logisch 0..431 zu deiner gewünschten
//    Vorwärtsrichtung wie beim Game-Strip.
static inline uint16_t borderLogicalToPhysical(uint16_t i) {
  const uint16_t blockSize = 12;
  const uint16_t blocks    = BORDER_LED_COUNT / blockSize;  // 36
  const uint16_t blockIdx  = i / blockSize;                 // 0..35 (logisch)
  const uint16_t inBlock   = i % blockSize;                 // 0..11
  const uint16_t physBlockStart = (blocks - 1 - blockIdx) * blockSize;
  return physBlockStart + inBlock;                          // physischer Index
}

// ---- Utilities -------------------------------------------------------------
void clearBoth() {
  gameStrip.clear();
  borderStrip.clear();
  gameStrip.show();
  borderStrip.show();
}

// Vorwärtslauf über LOGISCHE Indizes (0..count-1) mit Mapping -> physischer Index
void sweepForwardLogical(Adafruit_NeoPixel &strip, uint16_t count, const char *label, IndexMapFn mapFn) {
  Serial.print("[LED] sweep forward logical: ");
  Serial.println(label);

  strip.clear();
  strip.show();

  for (uint16_t i = 0; i < count; ++i) {
    uint16_t phys = mapFn ? mapFn(i) : i;
    strip.clear(); // pro Schritt genau 1 LED
    strip.setPixelColor(phys, strip.Color(255, 255, 255));
    strip.show();
    delay(STEP_DELAY_MS);
  }

  strip.clear();
  strip.show();
}

// ---- Arduino ---------------------------------------------------------------
void setup() {
  Serial.begin(115200);
  unsigned long start = millis();
  while (!Serial && (millis() - start) < 2000) delay(10);
  Serial.println("\n== LED Ring: game forward, border forward (mapped) ==");

  gameStrip.begin();
  borderStrip.begin();
  gameStrip.setBrightness(BRIGHTNESS);
  borderStrip.setBrightness(BRIGHTNESS);

  clearBoth();
  delay(250);
}

void loop() {
  if (!runOnce) {
    clearBoth();
    // Game: echtes 0->431
    sweepForwardLogical(gameStrip,  GAME_LED_COUNT,    "game strip",   identityMap);
    clearBoth();
    // Border: logisches 0->431, physisch via Mapping
    sweepForwardLogical(borderStrip, BORDER_LED_COUNT, "border strip", borderLogicalToPhysical);
    clearBoth();

    Serial.println("[LED] sweeps finished");
    runOnce = true;
  }
  delay(500);
}
