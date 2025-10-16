# SD-Manifest & Hash-Strategie

## Zweck
- Eine zentrale, verlässliche Quelle für alle SD-Inhalte (Spiele, Options-Bundles, Themes, Profile, Medien) bereitstellen.
- Dem Master-ESP32 einen deterministischen Bundle-Hash erzeugen lassen, den alle Satelliten (weitere ESP32 + Arduino) beim Start vergleichen können.
- JSON-Schemata dokumentieren, damit CLI, CI und Testpakete Inhalte automatisch prüfen können.

## SD-Karten-Struktur (Baseline)
```
/SDCARD/
  manifest.json              <-- vom manifest_tool generiert, entspricht manifest.schema.json
  /games/                    <-- einzelne Spieldefinitionen (game.schema.json)
  /options/                  <-- Nutzer-/Admin-Bundles (options.schema.json)
  /themes/
  /profiles/
  /music/
  /logos/
  /updates/
```

## Manifest-Überblick (`manifest.json`)
- `manifestVersion` (Semver) – Schema-Version zwecks Kompatibilitätsprüfung.
- `generatedAt` (RFC3339) – Zeitpunkt der Manifest-Erstellung.
- `masterFirmware` – Metadaten zur maßgeblichen Firmware des Master-ESP32:
  - `version` – z.B. `0.4.1`.
  - `hash` – `sha256:<64 hex>` der Firmwaredatei.
- `content` – Array je Inhaltstyp (`game`, `options`, `theme`, `profile`, `music`, `logo`):
  - Einträge enthalten `id`, `version`, `title`, `file`, `hash` sowie optional `players`, `scopes`, `dependencies`, `metadata`.
  - `hash` ist der SHA-256-Digest der Datei, stets mit Präfix `sha256:`.
  - `players` beschreibt min/max Spieleranzahl (nur für Spiele relevant).
  - `scopes` wird bei Options-Bundles genutzt (`user`, `admin`, `system`).
- `bundleHash` – deterministischer SHA-256-Hash über den Manifest-Inhalt (siehe Workflow).
- `notes` – optionale Freitext-Anmerkungen.

Zugehöriges JSON-Schema: `firmware/shared/proto/manifest.schema.json`.

## Spieldefinitionen (`/games/*.json`)
- Beschreiben Spielmodus, Timing, LED-Nutzung, Scoring, Menü-Hooks.
- Wesentliche Felder:
  - `id`, `version`, `title`, `description`.
  - `players` mit `min`, `max`, optional `recommended`.
  - `supportsHighscore`, `joker`, `requiresHardware` (z.B. `["encoder","rs485","display"]`).
  - `phases` – Abfolge (Countdown, Gameplay, Ergebnis) inkl. Dauer und Hooks.
  - `ledProfile` – referenziert logische Segmentgruppen + erlaubte Animationen.
  - `displayLayout` – LVGL-View-IDs bzw. Assets pro Display.
  - `optionRefs` – IDs verknüpfter Options-Bundles.
  - `telemetry` – Events, die ins Session-Log geschrieben werden.

Schema: `firmware/shared/proto/game.schema.json`.

## Options-Bundles (`/options/*.json`)
- Bündeln konfigurierbare Parameter für Nutzer- oder Adminoptionen.
- Felder:
  - `id`, `version`, `title`, `scope` (`user`, `admin`, `system`).
  - `appliesTo` – Spiel-IDs oder `["*"]` (global).
  - `fields` – Optionseinträge mit `key`, `type`, `label`, `default`, optional `choices`, Validierungsregeln.
  - `effects` – beschreibt, welches Subsystem angepasst wird (`led`, `audio`, `session`, `telemetry`).
  - `requiresRestart` – markiert Optionen, die einen Neustart erfordern.
  - `sync` – gibt an, wann Änderungen greifen (`immediate`, `onStart`, `manual`).

Schema: `firmware/shared/proto/options.schema.json`.

## Hashing-Workflow
1. Dateibasierter Hash:
   - `sha256sum <datei>` ausführen und das Ergebnis als `sha256:<digest>` im Manifest ablegen.
2. Kanonische Zeichenkette erstellen:
   - `content` nach Typ und dann nach ID sortieren.
   - Pro Eintrag: `<type>|<id>|<version>|<file>|<hash>|<players.min>-<players.max>|<scopes>|<dependencies>` anhängen.
   - Manifest-Version und Firmware-Hash voranstellen.
3. `bundleHash = sha256(<kanonische_zeichenkette>)` berechnen.
4. Master-ESP32 schreibt `manifest.json` inkl. `bundleHash`.
5. Clients vergleichen ihre Dateien; Abweichungen erzwingen Sync/Update.

So lässt sich jede fehlende oder geänderte Datei erkennen.

## Validierungspipeline
- Vor dem Flashen: JSON-Schema-Prüfungen (z.B. `specify check`, eigene Skripte).
- Zur Laufzeit:
  - Master prüft Dateiexistenz und Hash.
  - Clients holen `manifest.json`, berechnen `bundleHash`, fordern bei Abweichung Updates an.
- Telemetrielog erfasst aktuellen Bundle-Hash, Manifest-Version und erste Abweichung zur Diagnose.

## CLI-Unterstützung
- Manifest erzeugen:
  ```bash
  python -m firmware.shared.scripts.manifest_tool generate --root SDCARD --manifest-version 1.0.0 --firmware-version 0.4.1 --firmware-bin firmware.bin
  ```
  - Prüft Spiele/Optionen gegen die Schemas, berechnet Hashes und schreibt `SDCARD/manifest.json`.
  - Mit `--output` kann ein anderer Pfad gewählt werden; `--notes` fügt Freitext hinzu.
- Manifest validieren:
  ```bash
  python -m firmware.shared.scripts.manifest_tool validate manifest.json --root SDCARD
  ```
  - Prüft Schema, berechnet `bundleHash` neu und vergleicht alle referenzierten Dateien/Hashes.

## Nächste Schritte
- Autorenguides für Spiele-/Options-Dateien (z.B. `spielEngine`, `optionenEngine`) auf Basis dieser Schemas ausarbeiten.
- Manifest-Validierung in Hardware-Testpakete integrieren, damit jede Firmware mit passendem Asset-Bundle ausgeliefert wird.
