#include <Adafruit_NeoPixel.h>

/**
 * LED-Ring-Sequenztest
 * --------------------
 * - Leuchtet nacheinander jede LED des Spiel- und Grenzsegments auf.
 * - Helligkeit auf ca. 10 % begrenzt, damit der Ring nicht voll belastet wird.
 * - Pinbelegung wie im Hardware-Setup:
 *     * SpielLED-Datenleitung: Arduino Mega Pin 12
 *     * GrenzLED-Datenleitung: Arduino Mega Pin 13
 */

// ----- Konfiguration --------------------------------------------------------
constexpr uint8_t GAME_PIN = 12;
constexpr uint8_t BORDER_PIN = 13;

constexpr uint16_t GAME_LED_COUNT = 432;   // 36 Gruppen à 12 LEDs
constexpr uint16_t BORDER_LED_COUNT = 432; // 36 Gruppen à 12 LEDs

constexpr uint8_t BRIGHTNESS = 25;         // ~10 % von 255
constexpr uint16_t STEP_DELAY_MS = 25;

// ----- Globale Objekte ------------------------------------------------------
Adafruit_NeoPixel gameStrip(GAME_LED_COUNT, GAME_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel borderStrip(BORDER_LED_COUNT, BORDER_PIN, NEO_GRB + NEO_KHZ800);

bool runOnce = false;

// ----- Hilfsfunktionen ------------------------------------------------------
void clearBoth()
{
    gameStrip.clear();
    borderStrip.clear();
    gameStrip.show();
    borderStrip.show();
}

void sweepStrip(Adafruit_NeoPixel &strip, uint16_t count, const char *label, bool reverse = false)
{
    Serial.print("[LED] sweep ");
    Serial.print(label);
    Serial.print(" (");
    Serial.print(count);
    Serial.print(" LEDs");
    if (reverse) {
        Serial.print(", reverse");
    }
    Serial.println(")");

    strip.clear();
    strip.show();

    for (uint16_t step = 0; step < count; ++step) {
        uint16_t index = reverse ? step : (count - 1 - step);
        strip.clear();
        strip.setPixelColor(index, strip.Color(255, 255, 255)); // Helligkeit via setBrightness begrenzt
        strip.show();
        delay(STEP_DELAY_MS);
    }

    strip.clear();
    strip.show();
}

// ----- Arduino-Callbacks ----------------------------------------------------
void setup()
{
    Serial.begin(115200);
    unsigned long start = millis();
    while (!Serial && (millis() - start) < 2000) {
        delay(10);
    }
    Serial.println();
    Serial.println("== LED Ring Sequential Test ==");

    gameStrip.begin();
    borderStrip.begin();
    gameStrip.setBrightness(BRIGHTNESS);
    borderStrip.setBrightness(BRIGHTNESS);

    clearBoth();
    delay(250);
}

void loop()
{
    if (!runOnce) {
        clearBoth();
        sweepStrip(gameStrip, GAME_LED_COUNT, "game strip", false);
        clearBoth();
        sweepStrip(borderStrip, BORDER_LED_COUNT, "border strip", false);
        clearBoth();
        Serial.println("[LED] sweep finished");
        runOnce = true;
    }
    delay(500);
}

