# Hardware-Testpaket-Workflow

## Ziele
- Offizielle Waveshare-Treiber-Demos (`TREIBER/`) zusammen mit projektspezifischer Firmware nutzen, um jedes Subsystem isoliert zu pruefen.
- Jedes Testpaket vollstaendig eigenstaendig halten (Firmware-Binaries, Verdrahtungshinweise, erwartete serielle Ausgabe, Manifest-Ausschnitt).
- Testergebnisse wieder in die Manifest-Pipeline einspeisen, damit klar ist, welche Asset-Kombination erfolgreich validiert wurde.

## Verzeichnisstruktur
```
/tests/
  /rs485-link/
    README.md              <-- Verdrahtung & Ablauf
    esp32/
    arduino/
    assets/manifest.json
    expected.log
  /led-ring/
  /display-sync/
  /can-bus/
```
- Bestehende Waveshare-Demos aus `TREIBER/` sollen referenziert oder mit Attribution uebernommen werden, um Abweichungen zu minimieren.
- Nach bestandenem Test das Paket nach `/tests/succeeded/` verschieben (siehe `pitteromat.txt`), damit kuenftige Arbeiten auf den verifizierten Artefakten aufbauen.

## Manifest- & Schema-Integration
- Jedes Paket enthaelt ein reduziertes `manifest.json`, validiert gegen `firmware/shared/proto/manifest.schema.json`.
- Spiel-Mocks oder Options-Overrides verwenden dieselben Schemata (`game.schema.json`, `options.schema.json`), um Kompatibilitaet zum Gesamtsystem sicherzustellen.
- Bei Aenderungen Hashes neu erzeugen:
  ```bash
  python -m firmware.shared.scripts.manifest_tool generate --root tests/<name>/assets --manifest-version 1.0.0 --notes "rs485 smoke test"
  ```
  Der verzeichnete Bundle-Hash muss zu den ausgelieferten Dateien im Testordner passen.

## Ablauf-Checkliste
1. Bereitgestellte Binaries (oder lokal gebaute) flashen.
2. Setup gemaess README:
   - `rs485-link`: RS485-Bus Touch-LCD (Master) <-> Arduino (MAX485-Modul) nach `pitteromat.txt`.
   - `display-sync`: Wi-Fi (SoftAP oder vorhandener Router) fuer alle Touch-Displays bereitstellen, keine RS485-Verbindung zwischen den Displays.
3. Serielle Ausgaben (USB) aufzeichnen und mit `expected.log` vergleichen.
4. Ergebnis in `tests/<name>/RESULT.md` dokumentieren (pass/fail, Notizen). Bei Erfolg Ordner nach `/tests/succeeded/` verschieben.
5. Sobald alle benoetigten Bundles bestehen, das globale `manifest.json` fuer das Gesamtsystem aktualisieren.

## Naechste Schritte
- Hilfstarget (z.B. Make/Spec-Kit) ergaenzen, das in CI `python -m firmware.shared.scripts.manifest_tool validate tests/<name>/assets/manifest.json --root tests/<name>/assets` ausfuehrt.
- Tests in CI einbinden (`specify check`-Erweiterungen), damit Inhaltsaenderungen automatisch die zugehoerigen Einzelvalidierungen triggern, bevor die Gesamtfirmware gemergt wird.

