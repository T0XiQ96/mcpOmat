/* Arduino Mega LED-Ring Test (36x12) mit Cap 55%
   - Nutzt Adafruit_NeoPixel (alternativ FastLED).
   - Läuft Gruppen nacheinander durch.
*/
#include <Adafruit_NeoPixel.h>

#define LED_PIN    6      // Data Pin zum Ring
#define LEDS_PER_GROUP 12
#define GROUPS 36
#define NUM_LEDS (LEDS_PER_GROUP*GROUPS)
#define CAP_PCT 55        // globales Brightness-Cap
#define BRIGHT_MAX 255

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

uint8_t cap(uint8_t v) {
  uint16_t capped = (uint16_t)v * CAP_PCT / 100;
  if (capped > 255) capped = 255;
  return (uint8_t)capped;
}

void setup() {
  strip.begin();
  strip.show();
  strip.setBrightness(cap(200)); // ca. 55% von 200 ~= 110
}

void lightGroup(uint16_t g, uint32_t color) {
  uint16_t start = g * LEDS_PER_GROUP;
  for (uint16_t i = 0; i < LEDS_PER_GROUP; ++i) {
    strip.setPixelColor(start + i, color);
  }
}

void loop() {
  for (uint16_t g=0; g<GROUPS; ++g) {
    strip.clear();
    lightGroup(g, strip.Color(255, 255, 255)); // weiß (gecappt durch setBrightness)
    strip.show();
    delay(80);
  }
}
