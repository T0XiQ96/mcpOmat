# /speckit.plan — Technischer Plan (v2)

## Komponenten
- **ESP32 Master (Display 1):** State‑Machine (Idle→Menü→Spiel), WiFi‑Koordination, UI‑Signale an Slaves, RS‑485‑Bridge zum Mega.
- **ESP32 Slaves (Display 2–12):** Rendern Views; folgen Master‑Events.
- **Arduino Mega:** LED‑Treiber & Buttons; RS‑485‑Protokoll (über MAX485).

## Kommunikation
### ESP↔ESP (WiFi)
- Transport: UDP‑Broadcast für Discovery/Keep‑Alive; TCP oder UDP‑unicast für Events.
- Message‑Schema (kompakt JSON oder CBOR):
  ```
  { "t":"STATE", "v": "IDLE|MENU|GAME", "ts":123456 }
  { "t":"SEATS", "players": [1..6], "map":[12], "ts":... }
  { "t":"GAME_EVT","kind":"START|STOP|SCORE|LOSE","data":{...},"ts":... }
  ```
- Latenz‑Messung: Ping/Pong mit Monotonic‑Timestamp; Ziel < 20 ms lokal.

### ESP↔Mega (RS‑485)
- Physik: MAX485; **DE/RE** gesteuert über GPIO.
- Framing: kleines Binär‑Protokoll (Start‑Byte, Typ, Len, Payload, Checksum).
- Kommandos (Beispiele): `LED_SPIN`, `LED_SET_CAP`, `LED_IDLE`, `BTN_SNAP`.
- Baudrate: 115200 (anpassbar), TX‑Window + Flush vor DE low.

## Daten & LED
- **LED‑Gruppen:** 36 Gruppen × 12 LEDs = 432 LEDs (konfigurierbar).
- **Cap‑Enforcement:** Clamp auf 0.55 global *und* pro Kategorie (Spiel/Grenze).
- **„LichtLoser“ Spin:** Ease‑in/out Kurven (z. B. quintic), 0.5–2 Runden Full‑Speed.

## UI (EEZ)
- Manuelles Layout, kein dynamisches Autogen. Screens pro Flow.
- Admin‑Gate per PIN; Timer 10 s (UI‑Timer + Reset on activity).
- Platzhalter‑Controls für Non‑Goals anlegen (nur Vars).

## Tests & Tools
- **ESP32 Tests (Arduino IDE):** WiFi‑Kommunikation (Ping/Pong), SD‑Karte, LED‑Ring‑Sequenz, (optional) Encoder/Button‑Debounce.
- **Mega Tests:** RS‑485 Button‑Bridge/Echo.
- **DoD:** Alle Tests laufen; Logs in Serial Monitor erklärbar; LED‑Cap sichtbar.

## Sync‑Zeit Optionen (Vorschlag)
- **Display Render Sync:** weiche Taktung via Master „beat“ (20/40/70/100 ms).
- **Game Tick:** 10–20 ms. **UI Poll:** 50–100 ms. **Keep‑Alive:** 1 s.

## Risiken
- WiFi‑Interferenz → Fallback auf unicast + Retry. RS‑485 Noise → Terminierung/Fail‑safes.
