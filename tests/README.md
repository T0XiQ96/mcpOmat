# Testpakete (TREIBER-basierte Hardware-Validierung)

In diesem Verzeichnis liegen alle Hardware-Testpakete, die vor dem Flashen der Gesamtfirmware ausgefuehrt werden sollen. Die Pakete basieren auf den offiziellen Waveshare-Demos und wurden um projektspezifische Pruefungen erweitert.

## Quellen & Referenzen
- Hersteller-Wiki: https://www.waveshare.com/wiki/ESP32-S3-Touch-LCD-4  
  Enthält die Originalsketche (z.B. RS485, LED, Display) und Pinbelegungen.
- Repository-Ordner `TREIBER/`: Kopie der offiziellen Waveshare-Demos. Bitte unverändert lassen und lediglich in die jeweiligen Testpakete referenzieren bzw. mit Attribution einbinden.

## Paketstruktur
```
/tests/
  /<bundle-name>/
    README.md              <-- Ablaufbeschreibung
    esp32/                 <-- ESP32-Sketch (falls erforderlich)
    arduino/               <-- Arduino-Sketch (falls erforderlich)
    assets/manifest.json   <-- Manifest-Subset fuer diesen Test
    expected.log           <-- Erwartete serielle Ausgabe
```

## Arbeitsablauf
1. Benötigte Sketche aus `TREIBER/` kopieren und projektspezifisch anpassen.
2. README/expected.log im jeweiligen Bundle pflegen (Verkabelung, Prüfungen, Soll-Logs).
3. Nach erfolgreichem Test Bundle nach `/tests/succeeded/` verschieben und Ergebnis dokumentieren.

Weitere Details siehe `docs/operations/test-package-workflow.md`.

## Generatorskript
- `python tests/scripts/generate_bundles.py` erstellt/aktualisiert die Bundles `rs485-link`, `led-ring` und `display-sync`.
  - `rs485-link`: RS485-Master (Touch-LCD) ↔ Arduino (MAX485-Modul).
  - `display-sync`: Wi-Fi-Mesh zwischen Touch-Displays (SoftAP oder vorhandener Router).
