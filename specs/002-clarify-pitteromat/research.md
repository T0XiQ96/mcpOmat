# Rechercheprotokoll – PitterOmat Kernerlebnis

## Entscheidung: Hardware-Smoke-Test-Workflow
- **Begründung**: Durch die Wiederverwendung der Waveshare-TREIBER-Demos bleiben Low-Level-Treiber nahe an der Herstellerversion und die Inbetriebnahme wird kürzer. Jedes Test-Bundle (RS485, LED-Ring, Display-Sync, Diagnosen) erweitert das Original-Sketch um projektspezifische Prüfungen (z.B. Manifest-Hash-Echo, Segment-Map-Checks) und protokolliert erwartete serielle Ausgaben.
- **Betrachtete Alternativen**:
  - Eigene Mocks für jedes Subsystem – verworfen wegen höherem Wartungsaufwand und Abweichung vom Referenzcode.
  - Ausschließlich Integrationstests mit Gesamtfirmware – verworfen, weil Fehlersuche ohne isolierte Tests mühsam und fehleranfällig ist.

## Entscheidung: Manifest-Validierungs-Pipeline
- **Begründung**: Nach Content-Änderungen führen Entwickler `python -m firmware.shared.scripts.manifest_tool generate --root SDCARD` aus, committen das erzeugte `manifest.json` und notieren den Bundle-Hash. Beim Boot und vor jeder Session berechnet der Master-ESP32 Hashes neu und sendet sie an die Clients; nur bei Übereinstimmung wird gespielt, sonst bleibt der Spielstart gesperrt, bis `validate` erfolgreich ist.
- **Betrachtete Alternativen**:
  - Manuelle Hash-Listen/Spreadsheets – verworfen, fehleranfällig und verstößt gegen Verfassungsprinzip I.
  - Echtzeit-Hash-Streaming pro Asset – verworfen, unnötige RS485-Bandbreite und doppelte Verantwortung neben dem Manifest.

## Entscheidung: Admin-Freigabeverhalten
- **Begründung**: Längeres Drücken des physischen Admin-Buttons schaltet das Menü für 10 Sekunden frei. Das entspricht der Nutzungserwartung, vermeidet PIN-Verwaltung in frühen Ausbaustufen und schützt trotzdem vor versehentlicher Freigabe.
- **Betrachtete Alternativen**:
  - Dauerhafte Umschaltung per Button – verworfen, weil das Gerät leicht im Admin-Modus verbleibt.
  - PIN-Eingabe auf dem Touchdisplay – verschoben; erhöht die UI-Komplexität ohne aktuellen Bedarf.
