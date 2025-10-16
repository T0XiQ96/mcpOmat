# Funktionsspezifikation: PitterOmat Kernerlebnis

**Feature Branch**: `002-clarify-pitteromat`  
**Erstellt**: 17.10.2025  
**Status**: Entwurf  
**Eingabe**: Nutzerbeschreibung: „gucke dir pitteromat.txt an“

## Nutzungsszenarien & Tests *(verpflichtend)*

### User Story 1 – Geführtes Spiel-Setup (Priorität: P1)

Spieler 1 startet den Automaten vom Idle-Screen, wählt die Anzahl der Teilnehmenden (2–6), entscheidet sich für ein kompatibles Spiel und führt alle Spieler per Touch-Eingabe und Hardware-Taster in den „Bereit“-Zustand.

**Warum diese Priorität**: Ohne einen verlässlichen Setup-Ablauf kann kein Spiel beginnen; alle weiteren Fähigkeiten hängen davon ab.

**Unabhängiger Test**: Vom Idle-Screen aus vier Spieler wählen, ein verfügbares Spiel starten, jede Spielerbestätigung per Taster einholen und sicherstellen, dass das Spiel ohne Admin-Eingriff startet.

**Akzeptanzszenarien**:

1. **Gegeben** der Automat zeigt den Idle-Screen, **wenn** Spieler 1 Start tippt, eine Spielerzahl auswählt und ein Spiel anklickt, **dann** bleiben nur Spiele sichtbar, die zur gewählten Spielerzahl passen, und der Bereit-Screen erscheint.
2. **Gegeben** der Bereit-Screen ist sichtbar, **wenn** jede teilnehmende Person ihren Hardware-Taster drückt, **dann** wechselt das jeweilige Display auf Grün und das Spiel startet automatisch, sobald alle bestätigt haben.

---

### User Story 2 – LED- & Display-Orchestrierung (Priorität: P2)

Das System ordnet LED-Segmente, Joker-Verhalten und Sitzanzeigen passend zur Spielerzahl zu, zeigt fortlaufend Grenzeffekte, liefert visuelles Feedback während des Spiels und präsentiert zum Schluss Ergebnisse.

**Warum diese Priorität**: Die visuelle Darstellung definiert Spielfeld und Punktestand; falsche Zuordnungen untergraben das Spielerlebnis selbst bei funktionierendem Setup.

**Unabhängiger Test**: Eine Fünf-Spieler-Runde mit deaktiviertem Joker durchführen, LED-Zuordnungen und Score-Updates beobachten und sicherstellen, dass die Displays die richtigen Sitzplätze zeigen – ohne Admin-Menü zu nutzen.

**Akzeptanzszenarien**:

1. **Gegeben** fünf Spieler wurden ohne Joker gewählt, **wenn** das Spiel startet, **dann** bleibt SpielLED-Gruppe 2 dunkel, Grenze-LEDs leuchten dauerhaft und jedes Display zeigt das passende Sitzlabel.
2. **Gegeben** das Spiel endet, **wenn** finale Punkte vorliegen, **dann** signalisiert der LED-Ring Sieger- und Verlierer-Animationen und alle aktiven Displays zeigen Rangliste und Wiederholungsoptionen.

---

### User Story 3 – Admin-Überwachung & Synchronisation (Priorität: P3)

Eine Administratorin öffnet das Optionsmenü, prüft Diagnosen, stößt RS485- bzw. WLAN-Tests an, verwaltet Firmware- und Inhalts-Updates und bestätigt, dass alle Knoten denselben Manifest-Hash besitzen, bevor eine neue Spielrunde freigegeben wird.

**Warum diese Priorität**: Für den stabilen Betrieb braucht es Überwachung und Updates; ohne diesen Blick hinter die Kulissen lassen sich Fehler nicht beheben oder neue Inhalte sicher verteilen.

**Unabhängiger Test**: Im Admin-Menü Manifest-Prüfung ausführen, RS485- und LED-Diagnosen starten und sicherstellen, dass alle Statusanzeigen vor der nächsten Spielsitzung wieder auf „OK“ stehen.

**Akzeptanzszenarien**:

1. **Gegeben** ein neues Content-Bundle liegt auf der SD-Karte, **wenn** die Administratorin eine Manifest-Prüfung startet, **dann** werden Hash-Abweichungen gemeldet und ein Sync-Hinweis erscheint, bevor weitere Spiele erlaubt sind.
2. **Gegeben** die RS485-Verbindung ist gestört, **wenn** der Kommunikationstest läuft, **dann** markiert die UI den betroffenen Knoten und zeigt konkrete Handlungsempfehlungen.

---

### Randfälle

- Joker während einer laufenden Runde umschalten: Änderungen dürfen erst mit der nächsten Partie wirksam werden, damit es keine LED-Konflikte gibt.
- Spieler zieht nach Bereitschaft zurück: Das System muss ins Setup zurückspringen, Spielerzahl anpassen und LEDs/Displays neu zuordnen, bevor es weitergeht.
- Client-ESP meldet abweichenden Manifest-Hash: Gameplay bleibt gesperrt, bis synchronisiert oder ein Admin-Override bestätigt wurde.
- RS485-Störung während des Spiels: Arduino stoppt Animationen sicher, friert Zustand ein und meldet sich beim Master-ESP zur Wiederherstellung.

## Anforderungen *(verpflichtend)*

### Funktionale Anforderungen

- **FR-001**: Der Automat MUSS Spieler 1 erlauben, ausschließlich per Touch-Steuerung und Spielertaster vom Idle-Screen bis zum Spielstart zu wechseln.
- **FR-002**: Das System MUSS Spieldefinitionen von der SD-Karte laden und nur Spiele anzeigen, deren `min`/`max`-Spielerzahl zur Auswahl passt.
- **FR-003**: LED-Segment- und Sitzanzeigen MÜSSEN den dokumentierten Zuordnungen folgen, inklusive Joker-Ausnahme bei fünf Spielern.
- **FR-004**: Jeder Bereit-Screen MUSS eine Bestätigung jedes Spielers über den eigenen Hardware-Taster verlangen, bevor das Spiel beginnt.
- **FR-005**: Während des Spiels MUSS das System Punkte erfassen, LED-Animationen steuern und am Ende Ranglisten samt Replay-Option anzeigen.
- **FR-006**: Beim Start und vor jeder Partie MUSS der Manifest-Hash über alle ESP/Arduino-Knoten geprüft werden; Abweichungen blockieren das Spiel.
- **FR-007**: Das Admin-Menü MUSS Diagnosen für RS485, WLAN, LED, Displays und Fehlerprotokolle mit konkreten Hinweisen innerhalb von zwei Minuten bereitstellen.
- **FR-008**: Ungültige/missende SD-Dateien, Hardwarefehler und Sync-Probleme MÜSSEN in einem abrufbaren Diagnoseprotokoll gespeichert werden.

### Zentrale Entitäten *(sofern Daten involviert sind)*

- **GameDefinition**: Beschreibt einen Spielmodus mit ID, Spielerbereich, LED-Regeln, Hardware-Anforderungen, Phasen und verknüpften Options-Bundles.
- **OptionBundle**: Bündelt Nutzer-/Admin-Optionen (z.B. Joker-Farbe, Countdown-Stil), definiert Gültigkeitsbereich und betroffene Subsysteme.
- **PlayerSlot**: Repräsentiert einen Sitz inklusive Display-ID, SpielLED-Start/-Ende, GrenzLEDs und Joker-Overrides.
- **HardwareNode**: Hält Rolle (Master/Client/Arduino), Firmware-Version, Bundle-Hash, Heartbeat und Status jedes Geräts fest.
- **ManifestEntry**: Speichert Typ, ID, Version, Pfad, SHA-256-Hash und Metadaten jeder SD-Ressource.

## Annahmen

- Maximal sechs gleichzeitige Spieler; zusätzliche Sitzplätze liegen außerhalb des Scopes.
- Spiel- und Options-Dateien werden nach den bereitgestellten JSON-Schemata erstellt und vor Deployments validiert.
- Für jedes Subsystem existieren vorab vorbereitete Hardware-Test-Bundles auf Basis der Waveshare-TREIBER-Demos.
- Die Netzwerkumgebung ist ein vertrauenswürdiges lokales WLAN; Cloud-/Remote-Funktionen sind zukünftige Erweiterungen.

## Erfolgskriterien *(verpflichtend)*

### Messbare Ergebnisse

- **SC-001**: Spieler können in unter 90 Sekunden vom Idle-Screen ins laufende Spiel wechseln – unabhängig von der Spielerzahl.
- **SC-002**: LED-Grenzen und Sitzanzeigen entsprechen in 100 % der Sessions (2–6 Spieler) der dokumentierten Zuordnung.
- **SC-003**: Vor jedem Spiel melden 100 % der Knoten den identischen Manifest-Hash; Abweichungen werden innerhalb eines Versuchs behoben oder blockiert.
- **SC-004**: Administratoren lösen Kommunikations- oder LED-Probleme innerhalb von maximal 2 Minuten über die integrierten Optionen.
