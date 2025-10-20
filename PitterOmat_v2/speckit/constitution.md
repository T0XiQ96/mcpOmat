# /speckit.constitution — PitterOmat v2

## Vision
Ein robuster, bar‑tauglicher Multiplayer-Light-Game-Automat mit **12 Displays (ESP32)**, einem **Arduino Mega** für LEDs & Buttons, klaren Zuständen (Idle → Menü → Spiel) und einer ersten spielbaren Version **„LichtLoser“**. LED‑Helligkeit ist hardware-schonend limitiert.

## In-Scope (v2)
- 12 Displays: nur aktive zeigen Spiel/Score; inaktive zeigen Logo.
- **Spieler 1** steuert per Touch das Menü bis Spielstart; andere Displays zeigen Sitzplätze/Logo.
- **WiFi** zwischen ESPs (kein ESP‑NOW). **RS‑485** (MAX485) zwischen Master‑ESP und Arduino Mega.
- **LED Hardcap:** max. 55 % für Spiel‑/Grenz‑LEDs. Displayhelligkeit separat (10–100 %).
- **Idle-Modus** mit anpassbarem Timeout, optional Energiesparer (Display dimmen), Idle‑LED‑Effekte.
- **Admin‑PIN** schaltet Admin‑Optionen kurzzeitig frei (10 s).
- **Joker** im 5‑Spieler‑Sonderfall (Spiel‑LED‑Gruppe 2). Joker-Farbwahl: Gold oder Regenbogen.
- **EEZ UI** wird **manuell** gebaut (dynamische UI entfällt).
- **Display‑/Segment‑Mapping für 12 Displays** (Anpassung gegenüber 8).

## Out-of-Scope (Non‑Goals, v2)
- ESP‑NOW und RS‑485 **zwischen ESPs** (nur WiFi benutzen).
- OTA, Cluster‑Hash/Auto‑Sync/Cloud/Online‑Update/Web‑UI‑Updates.
- „Ready‑Screen“, Highscore, Audio‑Tests, SPI‑Test, I²C‑Scan, EEPROM‑Check, Systemdiagnose.
- WiFi‑AP/QR‑App UX (nur minimale Konfig-Platzhalter ohne Funktion).
- Spielwahl aus SD/JSON (optional statisch in Flash nur für „LichtLoser“).

## Qualitätsbalken
- **Deterministische Zustände**, definierte Zeitouts, keine UI‑Dead‑Ends.
- **Thermische Sicherheit:** globales LED‑Brightness‑Limit erzwingen (Clamp).
- **Resilienz:** serielle/RS‑485‑Time‑outs, WiFi‑Reconnect, watchdog‑sicher.
- **Synchronität:** Menü bis Spielstart synchron, danach definierte Rollen/Views.
- **Testbarkeit:** eigenständige Test‑Sketches (Arduino IDE), klare DoD pro Feature.

## Architekturprinzipien
- **Single Source of Truth:** Master‑ESP führt Spielzustand; Slaves subscriben.
- **Datenformate:** schlank (binär auf RS‑485; kompakt JSON/CBOR über WiFi).
- **Trennung:** Transport (WiFi/RS‑485) ≠ Logik (Game/LED) ≠ UI (EEZ).

## Naming/Structure
- `project/firmware/arduino/{ESP32,MEGA}`; Tests in `ESP32/tests/`.
- Assets (LED‑Ring‑Fotos/Skizzen) in `project/assets/LED_RING/`.
- EEZ‑Projekt in `project/ui/EEZ/`. Manifeste/Versionen unter `project/manifests/`.

## Compliance & Safety
- LED‑Cap 55 % fest enforced.
- Admin‑PIN schützt System/Bonus/Debug.
- Logging optional (SD), standardmäßig aus.
