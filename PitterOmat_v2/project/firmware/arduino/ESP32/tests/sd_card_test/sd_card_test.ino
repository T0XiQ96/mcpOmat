/* ESP32 SD-Karten Test (Arduino IDE)
   - Listet Root-Verzeichnis.
   Verdrahtung je nach Board (SD-MMC vs SPI-SD) anpassen.
*/
#include <SPI.h>
#include <SD.h>

const int SD_CS = 5; // evtl. anpassen

void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println("SD init...");
  if (!SD.begin(SD_CS)) {
    Serial.println("SD init failed!");
    return;
  }
  Serial.println("SD ok. Root:");
  File root = SD.open("/");
  while (true) {
    File entry = root.openNextFile();
    if (!entry) break;
    Serial.printf("%s %s %u bytes\n",
      entry.isDirectory() ? "DIR " : "FILE",
      entry.name(), (unsigned)entry.size());
    entry.close();
  }
  root.close();
}

void loop() {}
