/* Arduino Mega RS-485 Button-Bridge + Echo
   - Liest Buttons und sendet Events über RS-485.
   - Verwendet Serial2; MAX485: DE/RE Pin steuern.
*/
#define DE_PIN 21   // anpassen je nach Shield/Board
#define BTN1 22
#define BTN2 23
#define BTN3 24
#define BTN4 25

void rs485_tx_begin() { digitalWrite(DE_PIN, HIGH); delayMicroseconds(10); }
void rs485_tx_end()   { delayMicroseconds(10); digitalWrite(DE_PIN, LOW); }

void setup() {
  pinMode(DE_PIN, OUTPUT);
  digitalWrite(DE_PIN, LOW);
  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLUP);
  pinMode(BTN3, INPUT_PULLUP);
  pinMode(BTN4, INPUT_PULLUP);
  Serial.begin(115200);
  Serial2.begin(115200); // RS-485 link
  Serial.println("RS-485 Button Bridge ready");
}

void sendPacket(uint8_t type, uint8_t value) {
  rs485_tx_begin();
  uint8_t sum = 0;
  Serial2.write(0xAA); sum += 0xAA;
  Serial2.write(type); sum += type;
  Serial2.write(1);    sum += 1;
  Serial2.write(value); sum += value;
  Serial2.write(sum);
  Serial2.flush();
  rs485_tx_end();
}

bool last1=HIGH,last2=HIGH,last3=HIGH,last4=HIGH;

void loop() {
  // read buttons
  bool b1 = digitalRead(BTN1);
  bool b2 = digitalRead(BTN2);
  bool b3 = digitalRead(BTN3);
  bool b4 = digitalRead(BTN4);

  if (b1!=last1){ last1=b1; if(b1==LOW){ sendPacket(0x10,1); Serial.println("BTN1"); } }
  if (b2!=last2){ last2=b2; if(b2==LOW){ sendPacket(0x10,2); Serial.println("BTN2"); } }
  if (b3!=last3){ last3=b3; if(b3==LOW){ sendPacket(0x10,3); Serial.println("BTN3"); } }
  if (b4!=last4){ last4=b4; if(b4==LOW){ sendPacket(0x10,4); Serial.println("BTN4"); } }

  // echo any received packets
  if (Serial2.available()) {
    int b = Serial2.read();
    Serial.write(b);
  }
}
