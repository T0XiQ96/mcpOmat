/* Button/Encoder Debounce (Millis) — ohne externe Lib
   - Wenn ENCODER_NONGOAL = true, wird nur Button getestet.
*/
const bool ENCODER_NONGOAL = true;

const int PIN_BTN = 2;           // Taster an D2 (mit Pullup)
const unsigned long DEBOUNCE_MS = 30;

volatile bool btnStable = HIGH;
volatile bool btnLast = HIGH;
unsigned long btnLastChange = 0;

void setup() {
  pinMode(PIN_BTN, INPUT_PULLUP);
  Serial.begin(115200);
  Serial.println("Debounce test");
}

void loop() {
  bool raw = digitalRead(PIN_BTN);
  if (raw != btnLast) {
    btnLast = raw;
    btnLastChange = millis();
  } else {
    if (millis() - btnLastChange >= DEBOUNCE_MS && raw != btnStable) {
      btnStable = raw;
      if (btnStable == LOW) Serial.println("BTN DOWN");
      else Serial.println("BTN UP");
    }
  }
  // Encoder-Stub für später
  if (!ENCODER_NONGOAL) {
    // TODO: quadratur auslesen mit ähnlicher Entprellung/Rate-Limit
  }
}
