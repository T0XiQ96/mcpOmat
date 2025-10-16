# Quickstart – PitterOmat Kernerlebnis

## Voraussetzungen

- Waveshare ESP32-S3 Touch LCD 4 (Master) plus bis zu sieben Spiegel-Displays über RS485.
- Arduino Mega 2560, verdrahtet mit dem LED-Ring (SpielLED Pin 12, GrenzLED Pin 13) sowie Spieler-Tastern/Encoder.
- Gemeinsamer RS485-Bus (A/B-Leitungen, DE/RE-Steuerung) mit 120 Ω Abschluss und gemeinsamer Masse.
- microSD-Karte (FAT32) mit `/games`, `/options`, `/themes`, `/profiles`, `/music`, `/logos`, `/updates`.
- Python 3.11+ samt Projekt-Tools: `pip install -r firmware/shared/scripts/requirements.txt`.
- Waveshare-TREIBER-Ordner (`TREIBER/`) im Repository.

## 1. SD-Inhalte vorbereiten

1. `/games/*.json` und `/options/*.json` gemäß Schemata in `firmware/shared/proto/` anlegen.
2. Manifest generieren:
   ```bash
   python -m firmware.shared.scripts.manifest_tool generate --root SDCARD --manifest-version 1.0.0 --firmware-version <aktueller-tag> --notes "core experience bundle"
   ```
3. Hashes prüfen:
   ```bash
   python -m firmware.shared.scripts.manifest_tool validate SDCARD/manifest.json --root SDCARD
   ```
4. Kompletten `SDCARD/`-Ordner auf die microSD kopieren und in den Master-ESP32-S3 einsetzen.

## 2. Hardware-Test-Bundles flashen

1. Relevantes Subsystem wählen (z.B. RS485, LED-Ring, Display-Sync).
2. Unter `tests/<bundle>/` die ESP32- und Arduino-Sketche aus dem passenden TREIBER-Demo flashen.
3. Verkabelung gemäß README prüfen, serielle Ausgaben beobachten und mit `expected.log` vergleichen.
4. Bei Erfolg Bundle nach `tests/succeeded/` verschieben und Logs archivieren.

## 3. Laufzeit-Firmware aufspielen

1. Arduino-Gesamtfirmware aus `firmware/arduino/` flashen.
2. ESP32-S3-Firmware aus `firmware/esp32/` flashen (LVGL-UI + Manifest-Sync).
3. Sicherstellen, dass beide Knoten starten und im RS485-Diagnosefenster den Status „ready“ melden.

## 4. Funktionalen Smoke-Test ausführen

1. Konsole bis zum Idle-Screen hochfahren.
2. Admin-Button halten, Admin-Modus aufrufen und prüfen:
   - Manifest-Hashes sind auf allen Knoten identisch.
   - RS485-, LED-, Display- und WLAN-Diagnosen zeigen „OK“.
3. Admin-Modus verlassen. Vier-Spieler-Session starten:
   - Vier Spieler wählen und kontrollieren, dass nur passende Spiele sichtbar sind.
   - Gameplay starten, LED-Zuordnung und Displays prüfen.
4. Spiel beenden, Gewinner-/Verlierer-Animationen ansehen und Highscore-Einträge kontrollieren (falls vorhanden).

## 5. Operative Checkliste

- Vor jedem Deployment `manifest_tool validate` ausführen, um Hash-Abweichungen auszuschließen.
- Hardware-Test-Bundles in `tests/succeeded/` aktuell halten und bei Verkabelungs-/Firmwareänderungen erneut laufen lassen.
- Während Events Admin-Zugriff begrenzen: Button halten öffnet für 10 Sekunden, Loslassen sperrt sofort.
- Bei Störungen Diagnoselog nach `docs/operations/test-package-workflow.md` aufnehmen.
