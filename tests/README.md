# Testpakete (TREIBER-basierte Hardware-Validierung)

In diesem Verzeichnis liegen alle Hardware-Testpakete, die vor dem Flashen der Gesamtfirmware ausgeführt werden sollen. Die Pakete basieren auf den offiziellen Waveshare-Demos und wurden um projektspezifische Prüfungen erweitert.

## Quellen & Referenzen
- Hersteller-Wiki: https://www.waveshare.com/wiki/ESP32-S3-Touch-LCD-4  
  Enthält die Originalsketche (z.B. RS485, LED, Display) und Pinbelegungen.
- Repository-Ordner `TREIBER/`: Kopie der offiziellen Waveshare-Demos. Bitte unverändert lassen und lediglich in die jeweiligen Testpakete referenzieren bzw. mit Attribution einbinden.

## Paketstruktur
```
/tests/
  /<bundle-name>/
    README.md              <-- Verdrahtung & Ablauf für das Subsystem
    esp32/                 <-- modifizierter ESP32-Sketch (auf Basis der TREIBER-Demo)
    arduino/               <-- modifizierter Arduino-Sketch (falls erforderlich)
    assets/manifest.json   <-- Manifest-Subset für diesen Test
    expected.log           <-- Erwartete serielle Ausgabe
```

## Arbeitsablauf
1. Benötigte Sketche aus `TREIBER/` kopieren und projektspezifische Anpassungen vornehmen (z.B. Manifest-Hash-Echo).
2. README im jeweiligen Bundle pflegen (Verdrahtung, Schritte, erwartete Ergebnisse).
3. Serial-Log aufzeichnen und als `expected.log` ablegen.
4. Nach erfolgreichem Test Bundle nach `/tests/succeeded/` verschieben und Ergebnis dokumentieren.

Weitere Details siehe `docs/operations/test-package-workflow.md`.

## Generatorskript
- python tests/scripts/generate_bundles.py erstellt/aktualisiert die Bundles s485-link, led-ring und display-sync auf Basis der Waveshare-Treiber.
