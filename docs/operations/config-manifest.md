# SD Manifest & Hash Strategy

## Purpose
- Provide a single source of truth for all SD-card deployable assets (games, option bundles, themes, profiles, media).
- Allow master ESP32 to generate a deterministic bundle hash that satellites (other ESP32 nodes + Arduino) can compare at boot.
- Document JSON schemas so future tooling (CLI, CI, test packages) can validate content automatically.

## SD Card Layout (baseline)
```
/SDCARD/
  manifest.json              <-- generated file that conforms to manifest.schema.json
  /games/                    <-- individual game definition files (game.schema.json)
  /options/                  <-- user/admin bundles (options.schema.json)
  /themes/
  /profiles/
  /music/
  /logos/
  /updates/
```

## Manifest Overview (`manifest.json`)
- `manifestVersion` (`semver`) — schema revision for compatibility checks.
- `generatedAt` (`RFC3339`) — timestamp when the manifest was produced.
- `masterFirmware` — firmware metadata for the authoritative ESP32:
  - `version` — string, e.g. `0.4.1`.
  - `hash` — `sha256:<64 hex>` of the firmware image.
- `content` — array grouped by type (`game`, `options`, `theme`, `profile`, `music`, `logo`):
  - Each entry provides `id`, `version`, `title`, `file`, `hash`, optional `players`, `scopes`, `dependencies`, free-form `metadata`.
  - `hash` is the SHA-256 digest of the referenced file contents, prefixed with `sha256:`.
  - `players` describes supported min/max player counts (only meaningful for `game` entries).
  - `scopes` is used by `options` entries (`user`, `admin`, `system`).
- `bundleHash` — deterministic SHA-256 checksum derived from the manifest contents (see below).
- `notes` (optional) — free-form human-readable annotation.

Corresponding JSON schema: `firmware/shared/proto/manifest.schema.json`.

## Game Definition Files (`/games/*.json`)
- Describe a playable mode, its timing, LED usage, score handling, and menu hooks.
- Key fields:
  - `id`, `version`, `title`, `description`.
  - `players` object with `min`, `max`, optional `recommended`.
  - `supportsHighscore`, `joker`, `requiresHardware` (`["encoder","rs485","display"]`).
  - `phases` — ordered array of high-level steps (countdown, gameplay, results) with durations and event hooks.
  - `ledProfile` — references logical segment groups plus animations allowed.
  - `displayLayout` — describes LVGL view ids or assets used per player display.
  - `optionRefs` — IDs of option bundles that apply to this game.
  - `telemetry` — list of events this game emits to the session log.

Schema: `firmware/shared/proto/game.schema.json`.

## Option Bundles (`/options/*.json`)
- Encapsulate configurable parameters shown under “Nutzeroptionen” or “Adminoptionen”.
- Fields:
  - `id`, `version`, `title`, `scope` (`user`, `admin`, `system`).
  - `appliesTo` — array of game IDs or `["*"]` for global.
  - `fields` — array of option definitions with `key`, `type`, `label`, `default`, optional `choices`, validation constraints.
  - `effects` — declarative mapping describing which subsystem to update (`led`, `audio`, `session`, `telemetry`).
  - `requiresRestart` — boolean to flag if a change needs a game restart.
  - `sync` — guidance for propagation (`immediate`, `onStart`, `manual`).

Schema: `firmware/shared/proto/options.schema.json`.

## Hashing Workflow
1. Compute per-file hashes:
   - `sha256sum <file>` → store as `sha256:<digest>` in the manifest entry.
2. Construct a canonical string:
   - Sort `content` by `type`, then by `id`.
   - For each entry append: `<type>|<id>|<version>|<file>|<hash>|<players.min>-<players.max>|<scopes...>|<dependencies...>\n`.
   - Prepend manifestVersion and master firmware hash.
3. Calculate `bundleHash = sha256(canonical_string)`.
4. Master ESP32 writes `manifest.json` and `bundleHash`.
5. Satellite nodes recompute using their local files; mismatch triggers sync/update workflow.

This procedure guarantees that any missing, outdated, or altered game/option file changes the final bundle hash.

## Validation Pipeline
- JSON schema validation runs in tooling (`specify check`, custom scripts) before flashing SD content.
- Runtime boot validation:
  - Master verifies each file exists and matches the recorded hash.
  - Clients request `manifest.json`, compute `bundleHash`, compare, and request updates if mismatched.
- Hash/debug telemetry should log current bundle hash, manifest version, and first mismatch for diagnostics.

## CLI Support
- `python -m firmware.shared.scripts.manifest_tool generate --root SDCARD --manifest-version 1.0.0 --firmware-version 0.4.1 --firmware-bin firmware.bin`
  - Scans `SDCARD/`, validates games/options against schemas, computes hashes, and writes/overwrites `SDCARD/manifest.json`.
  - Optional `--output` writes to a custom file path; `--notes` attaches free-form text to the manifest.
- `python -m firmware.shared.scripts.manifest_tool validate manifest.json --root SDCARD`
  - Checks the manifest against the schema, recomputes `bundleHash`, and verifies every referenced file/hash relative to `SDCARD/`.

## Next Steps
- Document game/option authoring workflows (planned `spielEngine` / `optionenEngine` guides) built on top of diesen Schemas.
- Integrate manifest verification into hardware test packs so jede hochgeladene Firmware die passende Asset-Kombination nachweist.
