# SD-Karten-Arbeitsbereich (manifest_tool)

Dieser Ordner dient als Arbeitsverzeichnis für alle SD-Inhalte, bevor sie auf die echte microSD kopiert werden. Die Dateien werden vom `manifest_tool` geprüft bzw. erzeugt.

## Verzeichnisstruktur
```
/SDCARD/
  manifest.json          # wird vom manifest_tool erzeugt
  /games/                # Spieldefinitionen (game.schema.json)
  /options/              # Options-Bundles (options.schema.json)
  /themes/
  /profiles/
  /music/
  /logos/
  /updates/
```

## Workflow
1. Änderungen an Spielen/Optionen hier ablegen.
2. Manifest neu erzeugen:
   ```bash
   python -m firmware.shared.scripts.manifest_tool generate --root SDCARD --manifest-version 1.0.0 --firmware-version <aktueller-tag>
   ```
3. Manifest prüfen:
   ```bash
   python -m firmware.shared.scripts.manifest_tool validate SDCARD/manifest.json --root SDCARD
   ```
4. Danach den gesamten Ordnerinhalt auf die microSD kopieren.

Für fortgeschrittene Optionen siehe `python -m firmware.shared.scripts.manifest_tool --help`.
