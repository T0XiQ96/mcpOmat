# ESP32 Display-Kommunikationstest

- **wifi_comm_test.ino**: Ein Gerät `ROLE_MASTER=true`, alle anderen `false`.  
  - Alle ESP32 in dasselbe WiFi („Pittermesh“/„Pitteromat2025“ anpassbar).  
  - Master sendet pro Sekunde PING; Slaves antworten PONG.  
  - Serial Monitor zeigt RTT grob (ms). Ziel: < 20 ms lokal.
