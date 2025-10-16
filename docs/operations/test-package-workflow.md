# Hardware-Testpaket-Workflow

## Ziele
- Offizielle Waveshare-Treiber-Demos (`TREIBER/`) zusammen mit projektspezifischer Firmware nutzen, um jedes Subsystem isoliert zu validieren.
- Jedes Testpaket vollständig eigenständig halten (Firmware-Binaries, Verdrahtungshinweise, erwartete serielle Ausgabe, Manifest-Ausschnitt).
- Testergebnisse zurück in die Manifest-Pipeline speisen, damit ersichtlich bleibt, welche Asset-Kombination erfolgreich war.

## Verzeichnisstruktur
```
/tests/
  /rs485-link/
    README.md              <-- Verkabelung + Ablauf
    esp32/                 <-- Firmware (TREIBER + projektspezifische Ergänzungen)
    arduino/
    assets/manifest.json   <-- Manifest-Subset für diesen Test
    expected.log
  /led-ring/
  /display-sync/
  /can-bus/
```
- Bestehende Waveshare-Demos aus `TREIBER\` sollen referenziert oder mit Attribution übernommen werden, um Abweichungen zu minimieren.
- Nach bestandenem Test das Paket nach `/tests/succeeded/` verschieben (siehe `pitteromat.txt`), damit künftige Arbeiten auf den verifizierten Artefakten aufbauen.

## Manifest- & Schema-Integration
- Jedes Paket enthält ein reduziertes `manifest.json`, validiert gegen `firmware/shared/proto/manifest.schema.json`.
- Spiel-Mocks oder Options-Overrides verwenden dieselben Schemata (`game.schema.json`, `options.schema.json`), um Kompatibilität zum Gesamtsystem sicherzustellen.
- Bei Änderungen Hashes neu erzeugen:
  ```bash
  python -m firmware.shared.scripts.manifest_tool generate --root tests/<name>/assets --manifest-version 1.0.0 --notes "rs485 smoke test"
  ```
  Der verzeichnete Bundle-Hash muss zu den im Testordner ausgelieferten Dateien passen.

## Ablauf-Checkliste
1. Bereitgestellte Binaries (oder lokal gebaute) auf ESP32/Arduino flashen.
2. Verdrahtung gemäß README herstellen – RS485-Tests nutzen die Pinbelegung aus `pitteromat.txt`.
3. Serielle Ausgaben (USB) beider Geräte aufzeichnen und mit `expected.log` vergleichen.
4. Ergebnis in `tests/<name>/RESULT.md` festhalten (pass/fail, Notizen). Bei Erfolg Ordner nach `/tests/succeeded/` verschieben.
5. Sobald alle erforderlichen Bundles bestehen, das globale `manifest.json` aktualisieren.

## Nächste Schritte
- Hilfstarget (z.B. Make/Spec-Kit) ergänzen, das in CI `python -m firmware.shared.scripts.manifest_tool validate tests/<name>/assets/manifest.json --root tests/<name>/assets` aufruft.
- Tests in CI einbinden (`specify check`-Erweiterungen), damit Inhaltsänderungen automatisch die zugehörigen Einzelvalidierungen triggern, bevor die Gesamtfirmware gemergt wird.
