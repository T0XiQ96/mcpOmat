# /speckit.specify — Produktanforderungen (v2)

## Akteure & Geräte
- **Displays (12× ESP32):** zeigen UI/Spiel; Player 1 hat Touch‑Steuerung.
- **Arduino Mega:** steuert LED‑Ring(e) & Buttons (später Encoder‑Support).
- **MAX485‑Transceiver:** RS‑485 zwischen Master‑ESP und Mega.

## Kernabläufe
### 1) Idle → Menü
- Idle zeigt Logo + LED‑Effekte (konfigurierbar). Start‑Button ist **versteckt**, erscheint erst nach Aktivierung (Touch/Button).
- Energiesparer dimmt Displays im Idle (optional).

### 2) Hauptmenü
- Ticker/News (Marquee) frei konfigurierbar (z. B. Freibier‑Code).
- Buttons: **Start**, **Optionen**.

### 3) Start → Spieleranzahl → Spielwahl
- Spieleranzahl (2–6). Bis zur Auswahl: alle Displays synchron Menü/Platz‑Overlay.
- Spielwahl: zunächst **„LichtLoser“** (ein Modus „Standard“).

### 4) Spiel „LichtLoser“ (v1 des Spiels)
- Start: Einer drückt Button. **Zufälliger Start** in einer Spiel‑LED‑Gruppe (12 LEDs pro Gruppe).
- **Spin‑Kurve:** Beschleunigung → (0.5–2) schnelle Runden → Abbremsen → Zufalls‑Stopp.
- **Ergebnis:** genau **einer verliert**. Lose‑Effekt auf Verlierer, Win‑Neutral auf die übrigen.
- **Joker (nur 5‑Spieler):** Spiel‑LED‑Gruppe 2 gilt als Joker (Farbe: Gold oder Regenbogen).
- **Scores:** nur für aktive Spieler anzeigen; inaktive Displays zeigen Logo.

### 5) Optionen (Nutzer)
- **Quickstart:** „Spiel wiederholen“ (gleicher Modus/Optionen, Spieleranzahl darf geändert werden).
- **Spiele:** Auswahl Spiel/Modus (hier „Standard“). **Spielgeschwindigkeit** (LED‑Rotationsrate),
  **Runden (1–10)** via Slider (Anzeige der Zahl live). **Joker** Schalter + **Joker‑Farbe** (Gold/Regenbogen).

### 6) Optionen (Admin; PIN‑gate 10 s)
- **Farben & Effekte**
  - **Win/Lose/Win‑Neutral/Lose‑Neutral:** Dropdown, Standard = simples Blinken (Win: grün, Lose: rot).
  - **Spielerfarben:** eine Farbe / je Spieler eigene / zufällig; Zusatz: Inaktive Darstellung (Aus/Grau/Dimmen).
  - **Grenzfarben:** einfarbig (braun/grau) oder Regenbogen.
- **System (Seite 1):** LEDs (Helligkeit Spiel/Grenze 10–55 %), Anzeige (Display‑Helligkeit 10–100 %, Idle‑Timeout 5/10/15/30/60, Energiesparer).
- **System (Seite 2):** Neustart (mit Options‑Backup), Werkeinstellung (Profil später).

### 7) Netzwerk (Info & Platzhalter)
- WiFi (AP/QR als **Non‑Goal**), Kommunikation: **ESP↔ESP = WiFi**, **ESP↔Mega = RS‑485**.
- **Sync‑Time:** Auswahl 0/10/20/40/70/100 ms (für Tests). Weitere Vorschläge im Plan.
- Update/Manifest/Online‑Update: **Non‑Goal** (nur UI‑Platzhalter & Vars).

### 8) Debug
- Performance‑Overlay (FPS/CPU/Heap), serielle Ausgabe Switch.
- Tests‑Seite: Display‑Kommunikation (Latenz), RS‑485‑Roundtrip, LED‑Ring‑Test,
  Log‑SD‑Export (als Switch oder Button; v2: nur Platzhalter/Vars).

## Akzeptanzkriterien (Auszug)
- LED‑Cap 55 % wird **immer** erzwungen (auch bei Tests).
- Inaktive Displays zeigen Logo, aktive zeigen korrekte Scores/Reihenfolgen.
- Joker‑Logik nur im 5‑Spieler‑Modus aktiv.
- Admin‑PIN öffnet Admin‑Optionen exakt 10 s.
- Idle‑Timeout/Dimmen arbeiten wie konfiguriert.
