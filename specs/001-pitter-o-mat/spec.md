# Feature Specification: Pitter-o-mat Multiplayer Console

**Feature Branch**: `001-pitter-o-mat`  
**Created**: 2025-10-13  
**Status**: Draft  
**Input**: User description: "Arcade console with Arduino-driven LED ring, encoder controls, per-player displays, menu system, and configurable games for 2-6 players."

## User Scenarios & Testing *(mandatory)*

### User Story 1 - Spieler 1 richtet ein Spiel ein (Priority: P1)

Spieler 1 nutzt den Encoder, um Spieleranzahl, Spielmodus (zunaechst "LichtLoser") und Joker-Optionen auszuwaehlen. Alle Anzeigen folgen dem Menuefortschritt, bis das Spiel startet.

**Why this priority**: Ohne Menuefuehrung kann kein Match gestartet werden; sie ist Voraussetzung fuer alle anderen Funktionen.

**Independent Test**: ueber ein manuelles Testskript wird nach Power-on der Menuefluss von Start bis Spielstart durchlaufen und verifiziert, dass Displays und LEDs korrekt mitlaufen.

**Acceptance Scenarios**:

1. **Given** das System startet frisch, **When** Spieler 1 waehlt 4 Spieler und bestaetigt "LichtLoser", **Then** alle in Frage kommenden Displays zeigen ihre Spieler-ID und SpielLED-Gruppen werden vorbereitet, waehrend andere Eingaben gesperrt bleiben.
2. **Given** der Joker ist deaktiviert, **When** Spieler 1 aktiviert ihn im Optionen-Menue und legt Farbe/Animation fest, **Then** die Joker-LED-Gruppe wird mit gewaehlter Farbe markiert und die Einstellung bleibt bis zum Ausschalten erhalten.

---

### User Story 2 - Spieler erkennen Sitzplaetze und Grenzen (Priority: P2)

Teilnehmende Spieler sehen auf ihren Displays Sitzzuordnung und Status, waehrend der LED-Ring ihre Spielbereiche und Grenzen visuell markiert.

**Why this priority**: Klare Platz- und Bereichszuordnung verhindert Streitigkeiten und ermoeglicht sofortiges Spielverstaendnis.

**Independent Test**: Fuer jede Spieleranzahl wird die Display- und LED-Zuweisung geprueft und mit einer Prueftabelle abgeglichen.

**Acceptance Scenarios**:

1. **Given** 6 Spieler sind ausgewaehlt, **When** das Spiel auf Start wartet, **Then** Displays 8/2/3/4/6/7 zeigen Spieler 1-6 und GrenzLED-Gruppen 3/9/15/21/27/33 leuchten dauerhaft.
2. **Given** 5 Spieler sind ausgewaehlt und der Joker ist aus, **When** das Spiel initialisiert, **Then** SpielLED-Gruppe 2 bleibt aus und GrenzLED-Zuordnung 1/2/9/16/23/30 wird dargestellt.

---

### User Story 3 - Spielablauf mit Echtzeit-Feedback (Priority: P2)

Waehrend eines Spiels aktualisieren sich Spiel-LEDs, Displays und Encoder-Ereignisse in Echtzeit, um Fortschritt, Punkte und Effekte darzustellen.

**Why this priority**: Echtzeit-Feedback stellt den Kernnutzen des Pitter-o-mat dar und sorgt fuer Spielspass.

**Independent Test**: In einem Testspiel werden Encoder-Eingaben simuliert und gemessen, ob visuelle Rueckmeldungen innerhalb definierter Latenz erscheinen.

**Acceptance Scenarios**:

1. **Given** ein Spieler erzielt Punkte, **When** das Spiel die Aktualisierung sendet, **Then** der zugehoerige Bildschirm und die SpielLED-Zone zeigen innerhalb von 100 ms den neuen Score oder Effekt.
2. **Given** ein Spieler verliert, **When** die Verlustanimation ausgeloest wird, **Then** die konfigurierten GrenzLED-Animationen laufen ab und Displays zeigen den Status "Ausgeschieden".

---

### User Story 4 - Betreiber verwaltet System-Updates (Priority: P3)

Der Betreiber verbindet einen Master-ESP32S3 per WLAN, stoesst ueber das Optionen-Menue ein Software-Update an und alle weiteren ESP32S3 synchronisieren sich automatisch.

**Why this priority**: Wartbarkeit und konsistenter Softwarestand sind essenziell, um mehrere Geraete im Verbund zu betreiben.

**Independent Test**: Ein Testnetzwerk mit zwei ESPs zeigt, dass nach Upload einer neuen Firmware nur der Master geflasht wird und die anderen per Options-Trigger aktualisieren.

**Acceptance Scenarios**:

1. **Given** eine neue Firmware liegt auf dem Master-ESP, **When** der Betreiber im Optionen-Menue "Update verfuegbar" auswaehlt, **Then** alle anderen ESPs aktualisieren sich und melden Erfolg innerhalb des UI.
2. **Given** ein Update schlaegt fehl, **When** der Master keine Bestaetigung von einem Client erhaelt, **Then** das System markiert diesen Client als "Update erforderlich" und bietet einen erneuten Versuch an.

### Edge Cases

- Power-Cycle waehrend eines laufenden Spiels -> System muss konsistente Default-Einstellungen laden und klar signalisieren, dass das Spiel neu gestartet werden muss.
- 5-Spieler-Modus bei aktivem Joker -> Joker-LED-Gruppe darf nicht als Spielfeld einer Person gelten und muss klar gekennzeichnet werden, um Verwechslung zu vermeiden.
- Encoder-Bounce oder Dauerdruecken -> Eingaben werden entprellt und gegen versehentliche Mehrfachausloesungen geschuetzt.
- WLAN nicht verfuegbar -> Update-Option darf nicht haengen bleiben und muss "kein Netzwerk" melden, ohne dass Spielbetrieb blockiert wird.

## Requirements *(mandatory)*

### Functional Requirements

- **FR-001**: Das System MUSS beim Start den Touch-Mainmenu-Screen laden und Eingaben ueber den ESP32S3-Touchscreen entgegennehmen; Encoder-steuerung bleibt Spielmodi vorbehalten.
- **FR-002**: Zwischen 2 und 6 Spielern MUSS jede gueltige Auswahl den LED-Ring so konfigurieren, dass SpielLED-Gruppen gleichmaessig (oder laut Joker-Regel) aufgeteilt und GrenzLEDs dauerhaft markiert werden.
- **FR-003**: Displays MUESSEN abhaengig von der Spieleranzahl automatisch den zustaendigen Sitz (laut Zuordnungstabelle) anzeigen und ungenutzte Displays ausschalten.
- **FR-004**: Die Optionen MUSS Joker-Einstellungen (aktiviert/deaktiviert, Farbe, Animation) persistent speichern und sofort auf den LED-Ring anwenden.
- **FR-005**: Das System MUSS Gewinn- und Verlustanimationen bereitstellen, die pro Spielmodus auswaehlbar sind und den LED-Ring unabhaengig von Spielfeldgrenzen bespielen koennen.
- **FR-006**: Eine Highscore-Ansicht MUSS fuer Spielmodi mit aktivierter Highscore-Unterstuetzung Spielername, Punktestand und eine Zuruecksetzen-Funktion bereitstellen; Daten werden auf der SD-Karte des Master-ESP gespeichert.
- **FR-007**: Die Update-Funktion MUSS nach Upload einer neuen Firmware auf dem Master-ESP alle weiteren ESP32S3-Geraete per RS485/WLAN informieren und deren Update-Status ueberwachen.
- **FR-008**: Der Arduino Mega 2560 MUSS LED-Ring und Encoder-Ereignisse mit einer Steuerungsfrequenz von mindestens 100 Hz verarbeiten und relevante Zustaende an den Master-ESP weitergeben.
- **FR-009**: Das System MUSS Fehlermeldungen \(z\. B\. Touch/Treiberfehler, LED-Strang nicht erreichbar, WLAN nicht verfuegbar\) als Klartext im Optionen-Menue anzeigen.
- **FR-010**: Menueanimationen MUESSEN lediglich betroffene Pixel aktualisieren ("kein Vollbild-Clear"), um Flackern zu vermeiden.
- **FR-011**: Highscore-spezifische Optionen (Anzeige, Reset, Namensquellen) MUESSEN nur erscheinen, wenn der gewaehlte Spielmodus Highscores unterstuetzt.

### Non-Functional Requirements

- **NFR-001**: Encoder-Eingaben MUESSEN innerhalb von 150 ms visuell bestaetigt werden (Display oder LEDs).
- **NFR-002**: LED-Helligkeit MUSS regelbar zwischen 5 % und 100 % sein, Standard 60 %, ohne die Stromversorgung von 60 A/5 V zu ueberlasten.
- **NFR-003**: Das System MUSS bei Raumtemperatur 0-35  degrees C stabil laufen und nach einem Brown-out automatisch in den Startbildschirm booten.
- **NFR-004**: Firmware-Update-Prozess MUSS fehlertolerant sein und darf bei Abbruch keine inkonsistenten Versionen hinterlassen (Rollback des betroffenen ESP notwendig).

### Key Entities

- **PlayerSlot**: Repraesentiert einen Sitzplatz (2-6). Attribute: `slot_id`, zugehoerige Displays, SpielLED-Start/Endgruppe, GrenzLED-Links/Rechts, aktiver Status.
- **GameMode**: Definiert spielbare Modi (zunaechst "LichtLoser"). Attribute: `name`, zulaessige Spielerzahlen, benoetigte LED-Gruppen, Joker-Unterstuetzung, Gewinn-/Verlustanimationen, `supports_highscore`.
- **HardwareNode**: Beschreibt Geraete im Verbund (Arduino Mega, ESP32S3-Displays). Attribute: `node_id`, `role` (Master/Client), Firmware-Version, Update-Status, Verbindungstyp (RS485/WLAN).
- **HighscoreEntry**: Speichert Spielername, Score, Zeitstempel und Spielmodus; wird auf SD-Karte persistiert.

## Allocation Reference

### Display IDs by Player Count

| Players | Display IDs (clockwise starting at reference zero) |
|---------|----------------------------------------------------|
| 2       | 1 (Player 1), 5 (Player 2)                         |
| 3       | 8 (Player 1), 3 (Player 2), 6 (Player 3)           |
| 4       | 1, 3, 5, 7                                         |
| 5       | 8, 2, 3, 5, 7                                      |
| 6       | 8, 2, 3, 4, 6, 7                                   |

### LED Segments by Player Count

- 2 Players: SpielLED 1-18 fuer Spieler 1, SpielLED 19-36 fuer Spieler 2; GrenzLED 18/36 bilden Grenzen.
- 3 Players: SpielLED 1-12, 13-24, 25-36; GrenzLED 12, 24, 36.
- 4 Players: SpielLED 5-13, 14-22, 23-31, 32-4; GrenzLED 4, 13, 22, 31.
- 5 Players: SpielLED 3-9, 10-16, 17-23, 24-30, 31-1; GrenzLED 1, 2, 9, 16, 23, 30 (Joker optional fuer SpielLED 2).
- 6 Players: SpielLED 4-9, 10-15, 16-21, 22-27, 28-33, 34-3; GrenzLED 3, 9, 15, 21, 27, 33.

## Assumptions & Dependencies

- SD-Karte auf dem Master-ESP verfuegt ueber ausreichend Speicher (>=2 GB) fuer Highscores, Konfigurationsdateien und Update-Pakete.
- RS485-Verbindung zwischen Arduino und Master-ESP liefert mindestens 115200 Baud fuer Echtzeit-Kommunikation; bei Stoerungen faellt das System in einen sicheren Stopp.
- Bedienpersonal nutzt EEZ-Studio-generierte UI-Screens, daher werden Layout-aenderungen dort durchgefuehrt und hier nur logisch spezifiziert.
- WLAN wird ueber WPA2-gesichertes lokales Netz bereitgestellt; externe Cloud-Services sind vorerst nicht Teil des Scopes.

## Out of Scope

- Unterstuetzung weiterer Spiele ausser "LichtLoser" (Platzhalter fuer spaetere Erweiterungen).
- Mobile Companion-App oder Websteuerung (nur vorbereiteter WLAN-Zugriff vorgesehen).
- Audioausgabe, zusaetzliche Sensorik oder physische Sicherheitseinrichtungen.

## Success Criteria *(mandatory)*

### Measurable Outcomes

- **SC-001**: Betreiber koennen ein komplettes Spiel (2-6 Spieler) in unter 90 Sekunden nach Systemstart konfigurieren und starten.
- **SC-002**: LED-Updates (Grenzen, Joker, Animationen) erscheinen innerhalb von 100 ms nach Trigger-Ereignis, gemessen an 95 %-Perzentil ueber 10 Minuten Spielzeit.
- **SC-003**: Mindestens 95 % der Testspiele werden ohne manuelles Eingreifen abgeschlossen; Fehler werden durch UI-Meldungen loesbar.
- **SC-004**: Firmware-Updates erreichen 100 % der verbundenen ESP32S3-Geraete innerhalb von 5 Minuten; fehlerhafte Clients werden identifiziert und erneut anstossbar.

## Clarifications

### Session 2025-10-13

- Q: Wie sollen Spielernamen fuer die Highscore-Erfassung verwaltet werden? -> A: Companion-App verwaltet Namen fuer Highscore-faehige Modi
- Q: Welches Eingabegeraet steuert die Menuefuehrung? -> A: Touchscreen der ESP32S3-Hauptanzeige uebernimmt Menue, Encoder nur fuer Spiel-Inputs




