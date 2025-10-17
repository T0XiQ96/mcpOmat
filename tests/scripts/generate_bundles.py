#!/usr/bin/env python3
"""Erzeugt Hardware-Testpakete aus den Waveshare-TREIBER-Demos."""

import shutil
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parents[2]
TREIBER_ROOT = REPO_ROOT / "TREIBER"
TEST_ROOT = REPO_ROOT / "tests"
SUCCEEDED_ROOT = TEST_ROOT / "succeeded"

# Bundle-Definitionen: name, moegliche Quellordner innerhalb von TREIBER/
BUNDLES = [
    {
        "name": "rs485-link",
        "candidates": [
            "04_RS485_Test",
            "04_RS485_Test-master",
        ],
        "description": "RS485-Kommunikation & Manifest-Hash-Echo",
    },
    {
        "name": "led-ring",
        "candidates": [
            "01_PanelTest",
            "06_LVGL_Proting",
        ],
        "description": "LED-Lauflicht & Joker/Boundary-Validierung",
    },
    {
        "name": "display-sync",
        "candidates": [
            "02_LVGL_Porting",
            "03_Rotation",
        ],
        "description": "Display-Zuordnung & Sitzplatzanzeige",
    },
]

README_TEMPLATE = """# {title}

Dieses Paket basiert auf der Waveshare-Demo "{source}" und wurde fuer PitterOmat erweitert.

## Zweck
- {description}
- Manifest-Hash per `assets/manifest.json` pruefen, bevor auf den Master-ESP32 geflasht wird.

## Schritte
1. ESP32-Sketch aus `esp32/` flashen.
2. Arduino-Sketch (falls vorhanden) aus `arduino/` flashen.
3. Verdrahtung gemaess Haupt-README (`tests/README.md`) sicherstellen.
4. Serielle Ausgabe mit `expected.log` vergleichen.

## Hinweise
- Originalquelle: https://www.waveshare.com/wiki/ESP32-S3-Touch-LCD-4
- Bei Anpassungen README und expected.log aktualisieren.
"""

MANIFEST_STUB = """{
  "manifestVersion": "1.0.0",
  "generatedAt": "TODO",
  "masterFirmware": {
    "version": "TODO",
    "hash": "sha256:TODO"
  },
  "content": [],
  "bundleHash": "sha256:TODO"
}
"""

EXPECTED_STUB = "# Erwarte hier die serielle Ausgabe deines Testlaufs.\n"


def find_source(bundle):
    if not TREIBER_ROOT.exists():
        return None
    for candidate in bundle["candidates"]:
        path = TREIBER_ROOT / candidate
        if path.exists():
            return path
    return None


def copy_sources(source, destination):
    for item in source.iterdir():
        if item.name.startswith("."):
            continue
        target = destination / item.name
        if item.is_dir():
            shutil.copytree(item, target, dirs_exist_ok=True)
        else:
            shutil.copy2(item, target)


def ensure_bundle(bundle):
    bundle_dir = TEST_ROOT / bundle["name"]
    esp32_dir = bundle_dir / "esp32"
    arduino_dir = bundle_dir / "arduino"
    assets_dir = bundle_dir / "assets"

    bundle_dir.mkdir(parents=True, exist_ok=True)
    esp32_dir.mkdir(exist_ok=True)
    arduino_dir.mkdir(exist_ok=True)
    assets_dir.mkdir(exist_ok=True)

    source = find_source(bundle)
    if source:
        copy_sources(source, esp32_dir)
        readme = README_TEMPLATE.format(
            title=f"{bundle['name'].replace('-', ' ').title()} Test",
            source=source.name,
            description=bundle["description"],
        )
    else:
        readme = (
            f"# {bundle['name'].replace('-', ' ').title()} Test\n\n"
            "Keine passende Quelle im TREIBER/-Ordner gefunden. Bitte Dateien manuell hinzufuegen.\n"
        )

    (bundle_dir / "README.md").write_text(readme, encoding="utf-8")
    (assets_dir / "manifest.json").write_text(MANIFEST_STUB, encoding="utf-8")
    expected_log = bundle_dir / "expected.log"
    if not expected_log.exists():
        expected_log.write_text(EXPECTED_STUB, encoding="utf-8")


def main():
    TEST_ROOT.mkdir(exist_ok=True)
    SUCCEEDED_ROOT.mkdir(exist_ok=True)

    for bundle in BUNDLES:
        ensure_bundle(bundle)
        print(f"Bundle '{bundle['name']}' vorbereitet.")


if __name__ == "__main__":
    main()
