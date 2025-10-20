# /speckit.tasks — Aufgabenliste (v2)

> Format: `[DoD]` Definition-of-Done, `(Files)` wichtige Pfade

## EPIC: Projektgrundlage & Assets
- **Ordnerstruktur anlegen** — `project/assets/LED_RING/` für Fotos/Skizzen.  
  [DoD] Ordner existiert, .gitkeep liegt. (Files) assets/LED_RING/
- **LED-Ring analysieren** (nach Foto) — Mapping (36×12) dokumentieren.  
  [DoD] `display_map.h/.md` mit Index‑Zuordnung. (Files) firmware/…

## EPIC: EEZ UI (manuell)
- **Idle/Hauptmenü/Start/Optionen/Spiel** Screens anlegen.  
  [DoD] Navigation laut Specify, Start‑Button erscheint nach Aktivierung.
- **Ticker/News** mit String‑Var und Marquee.  
  [DoD] Text änderbar, läuft L→R.
- **Admin‑PIN Gate (10 s)**  
  [DoD] PIN‑Dialog + Timer; Admin‑Sektion sichtbar solange Timer aktiv.
- **Optionen (User)**: Quickstart, Spiele/Modus, Spielgeschwindigkeit, Runden(1–10), Joker + Joker‑Farbe.  
  [DoD] Controls vorhanden, Vars gebunden.
- **Optionen (Admin)**: Farben/Effekte, System (LED/Anzeige), Netzwerk‑Platzhalter, Debug.  
  [DoD] Controls + Vars vorhanden (auch Non‑Goals als disabled).

## EPIC: Firmware — Common
- **Globales LED‑Cap 55 %**  
  [DoD] Clamp in Render‑Pfad + Tests zeigen Cap.
- **State‑Machine (IDLE→MENU→GAME)**  
  [DoD] Zustandswechsel per Events, klare Timeouts.
- **Idle‑Effekte + Timeout**  
  [DoD] Effekt läuft; Timeout bringt zurück in Idle; Energiesparer dimmt Display.

## EPIC: ESP32 (WiFi)
- **Discovery/Keep‑Alive**  
  [DoD] Slaves finden Master; Status im Serial.
- **Ping/Pong Latenz‑Test**  
  [DoD] Mittelwert/Lag im Serial; Ziel <20 ms lokal.
- **Event‑Broadcasts** (STATE/SEATS/GAME_EVT)  
  [DoD] Slaves reagieren korrekt auf Master.

## EPIC: Mega (RS‑485 + LEDs + Buttons)
- **RS‑485 Echo**  
  [DoD] Mega empfängt/antwortet; DE/RE korrekt.
- **Button‑Debounce (Millis)**  
  [DoD] Entprellung ohne Lib; Events nur bei Flanken.
- **LED‑Ring‑Treiber (36×12)**  
  [DoD] Gruppen‑Sequenz; Test „alle LEDs durch“; Cap greift.
- **„LichtLoser“ Kurve**  
  [DoD] Accel→Full→Decel via Parametrisierung.

## EPIC: Tests & Doku
- **Arduino‑IDE Testsketche** (ESP & Mega)  
  [DoD] Kompilieren; README erklärt Setup.
- **Successive Tests Archiv**  
  [DoD] `_archive_successful/` existiert + Anleitung.

