"""Manifest generation and validation utilities for Pitter-o-mat SD content."""

from __future__ import annotations

import json
import hashlib
import textwrap
from datetime import datetime, timezone
from pathlib import Path, PurePosixPath
from typing import Any, Dict, Iterable, List, Optional
import re

import click
from jsonschema import Draft7Validator, ValidationError


SCRIPT_DIR = Path(__file__).resolve().parent
SHARED_DIR = SCRIPT_DIR.parent
SCHEMA_DIR = SHARED_DIR / "proto"

SCHEMA_FILES = {
    "manifest": "manifest.schema.json",
    "game": "game.schema.json",
    "options": "options.schema.json",
}

CATEGORY_CONFIG = {
    "game": {"dir": "games", "extensions": [".json"], "schema": "game"},
    "options": {"dir": "options", "extensions": [".json"], "schema": "options"},
    "theme": {
        "dir": "themes",
        "extensions": [".json"],
        "schema": None,
    },
    "profile": {
        "dir": "profiles",
        "extensions": [".json"],
        "schema": None,
    },
    "music": {
        "dir": "music",
        "extensions": [".wav", ".mp3", ".ogg", ".flac"],
        "schema": None,
    },
    "logo": {"dir": "logos", "extensions": [".png", ".jpg", ".jpeg", ".bmp"], "schema": None},
}


_SCHEMA_CACHE: Dict[str, Draft7Validator] = {}


def load_schema(name: str) -> Draft7Validator:
    if name not in SCHEMA_FILES:
        raise click.ClickException(f"Unknown schema '{name}'")
    if name not in _SCHEMA_CACHE:
        schema_path = SCHEMA_DIR / SCHEMA_FILES[name]
        if not schema_path.exists():
            raise click.ClickException(f"Schema file not found: {schema_path}")
        schema_data = json.loads(schema_path.read_text(encoding="utf-8"))
        _SCHEMA_CACHE[name] = Draft7Validator(schema_data)
    return _SCHEMA_CACHE[name]


def validate_json(data: Dict[str, Any], schema_name: str, source: Path) -> None:
    validator = load_schema(schema_name)
    errors = sorted(validator.iter_errors(data), key=lambda e: e.path)
    if errors:
        formatted = "\n".join(f"- {list(err.path)}: {err.message}" for err in errors)
        raise click.ClickException(
            f"Validation failed for {source} against {schema_name} schema:\n{formatted}"
        )


def compute_hash(path: Path) -> str:
    hasher = hashlib.sha256()
    with path.open("rb") as fh:
        for chunk in iter(lambda: fh.read(1024 * 1024), b""):
            hasher.update(chunk)
    return f"sha256:{hasher.hexdigest()}"


def canonical_entry_id(stem: str) -> str:
    slug = re.sub(r"[^a-z0-9\-]+", "-", stem.lower()).strip("-")
    return slug or "file"


def posix_relpath(path: Path, root: Path) -> str:
    return str(PurePosixPath(path.relative_to(root).as_posix()))


def gather_entries(root: Path, category: str) -> List[Dict[str, Any]]:
    cfg = CATEGORY_CONFIG[category]
    base_dir = root / cfg["dir"]
    if not base_dir.exists():
        return []
    entries: List[Dict[str, Any]] = []
    for file_path in sorted(p for p in base_dir.rglob("*") if p.is_file()):
        if cfg["extensions"] and file_path.suffix.lower() not in cfg["extensions"]:
            continue
        relative_path = posix_relpath(file_path, root)
        file_hash = compute_hash(file_path)
        if cfg["schema"] == "game":
            data = json.loads(file_path.read_text(encoding="utf-8"))
            validate_json(data, "game", file_path)
            entry: Dict[str, Any] = {
                "id": data["id"],
                "version": data["version"],
                "title": data.get("title"),
                "description": data.get("description"),
                "file": relative_path,
                "hash": file_hash,
            }
            players = data.get("players")
            if isinstance(players, dict):
                entry["players"] = {
                    key: value
                    for key, value in players.items()
                    if key in {"min", "max", "recommended"}
                }
            entry["metadata"] = {
                key: data.get(key)
                for key in ["supportsHighscore", "requiresHardware", "joker"]
                if key in data
            }
            entries.append(entry)
        elif cfg["schema"] == "options":
            data = json.loads(file_path.read_text(encoding="utf-8"))
            validate_json(data, "options", file_path)
            entry = {
                "id": data["id"],
                "version": data["version"],
                "title": data.get("title"),
                "description": data.get("description"),
                "file": relative_path,
                "hash": file_hash,
                "scopes": [data["scope"]],
            }
            applies = data.get("appliesTo")
            if applies:
                entry["dependencies"] = applies
            entries.append(entry)
        else:
            stem_id = canonical_entry_id(file_path.stem)
            entry = {
                "id": stem_id,
                "version": "1.0.0",
                "title": file_path.stem,
                "file": relative_path,
                "hash": file_hash,
            }
            entries.append(entry)
    return entries


def build_content(root: Path) -> List[Dict[str, Any]]:
    content = []
    for category in sorted(CATEGORY_CONFIG):
        entries = gather_entries(root, category)
        if entries:
            content.append({"type": category, "entries": entries})
    return content


def canonical_bundle_string(manifest: Dict[str, Any]) -> str:
    lines: List[str] = []
    lines.append(f"manifestVersion|{manifest['manifestVersion']}")
    master = manifest.get("masterFirmware", {})
    lines.append(f"masterFirmware|{master.get('version','')}|{master.get('hash','')}")
    for category in sorted(manifest.get("content", []), key=lambda c: c["type"]):
        cat_type = category["type"]
        for entry in sorted(category["entries"], key=lambda e: e["id"]):
            players = entry.get("players")
            players_repr = ""
            if isinstance(players, dict):
                players_repr = f"{players.get('min','')}-{players.get('max','')}"
            scopes = ",".join(sorted(entry.get("scopes", [])))
            dependencies = ",".join(sorted(entry.get("dependencies", [])))
            line = "|".join(
                [
                    cat_type,
                    entry.get("id", ""),
                    entry.get("version", ""),
                    entry.get("file", ""),
                    entry.get("hash", ""),
                    players_repr,
                    scopes,
                    dependencies,
                ]
            )
            lines.append(line)
    return "\n".join(lines)


def ensure_manifest_valid(manifest: Dict[str, Any]) -> None:
    validate_json(manifest, "manifest", Path("manifest.json"))


def emit_manifest(
    root: Path,
    manifest_version: str,
    firmware_version: str,
    firmware_hash: str,
    notes: Optional[str],
) -> Dict[str, Any]:
    if not root.exists():
        raise click.ClickException(f"Root directory not found: {root}")
    content = build_content(root)
    manifest: Dict[str, Any] = {
        "manifestVersion": manifest_version,
        "generatedAt": datetime.now(timezone.utc).isoformat(),
        "masterFirmware": {"version": firmware_version, "hash": firmware_hash},
        "content": content,
    }
    if notes:
        manifest["notes"] = notes
    bundle_string = canonical_bundle_string(manifest)
    manifest["bundleHash"] = f"sha256:{hashlib.sha256(bundle_string.encode('utf-8')).hexdigest()}"
    ensure_manifest_valid(manifest)
    return manifest


def load_manifest(path: Path) -> Dict[str, Any]:
    data = json.loads(path.read_text(encoding="utf-8"))
    ensure_manifest_valid(data)
    return data


def check_bundle_hash(manifest: Dict[str, Any]) -> None:
    expected = manifest["bundleHash"]
    bundle_string = canonical_bundle_string(manifest)
    actual = f"sha256:{hashlib.sha256(bundle_string.encode('utf-8')).hexdigest()}"
    if expected != actual:
        raise click.ClickException(
            f"bundleHash mismatch:\n expected {expected}\n actual   {actual}"
        )


def verify_files(manifest: Dict[str, Any], root: Path) -> List[str]:
    failures: List[str] = []
    for category in manifest.get("content", []):
        for entry in category.get("entries", []):
            file_rel = entry.get("file")
            if not file_rel:
                continue
            path = root / Path(PurePosixPath(file_rel))
            if not path.exists():
                failures.append(f"Missing file: {file_rel}")
                continue
            actual_hash = compute_hash(path)
            if entry.get("hash") != actual_hash:
                failures.append(
                    f"Hash mismatch for {file_rel}: manifest={entry.get('hash')} local={actual_hash}"
                )
    return failures


def auto_firmware_hash(firmware_bin: Optional[Path]) -> str:
    if firmware_bin is None:
        return "sha256:" + "0" * 64
    if not firmware_bin.exists():
        raise click.ClickException(f"Firmware binary not found: {firmware_bin}")
    return compute_hash(firmware_bin)


@click.group()
def cli() -> None:
    """Utilities for generating and validating manifest.json."""


@cli.command("generate")
@click.option(
    "--root",
    type=click.Path(file_okay=False, path_type=Path),
    default=Path("SDCARD"),
    show_default=True,
    help="Root directory containing SD content.",
)
@click.option(
    "--output",
    type=click.Path(dir_okay=False, path_type=Path),
    help="Optional output path for manifest.json (defaults to <root>/manifest.json).",
)
@click.option(
    "--manifest-version",
    default="1.0.0",
    show_default=True,
    help="Semantic version recorded in manifestVersion.",
)
@click.option(
    "--firmware-version",
    default="0.0.0",
    show_default=True,
    help="Version string for master firmware metadata.",
)
@click.option(
    "--firmware-bin",
    type=click.Path(dir_okay=False, path_type=Path),
    help="Optional binary to hash for master firmware entry.",
)
@click.option(
    "--notes",
    type=str,
    help="Optional human-readable notes stored in manifest.",
)
def generate_cmd(
    root: Path,
    output: Optional[Path],
    manifest_version: str,
    firmware_version: str,
    firmware_bin: Optional[Path],
    notes: Optional[str],
) -> None:
    """Scan SD content and emit a manifest.json with hashes and bundle hash."""
    firmware_hash = auto_firmware_hash(firmware_bin)
    manifest = emit_manifest(
        root=root,
        manifest_version=manifest_version,
        firmware_version=firmware_version,
        firmware_hash=firmware_hash,
        notes=notes,
    )
    manifest_path = output or (root / "manifest.json")
    manifest_path.parent.mkdir(parents=True, exist_ok=True)
    manifest_path.write_text(json.dumps(manifest, indent=2, ensure_ascii=False) + "\n", encoding="utf-8")
    click.echo(f"Wrote manifest to {manifest_path}")


@cli.command("validate")
@click.argument(
    "manifest_path",
    type=click.Path(exists=True, dir_okay=False, path_type=Path),
)
@click.option(
    "--root",
    type=click.Path(file_okay=False, path_type=Path),
    help="Optional root directory to verify file hashes.",
)
def validate_cmd(manifest_path: Path, root: Optional[Path]) -> None:
    """Validate a manifest.json against schema and optional on-disk hashes."""
    manifest = load_manifest(manifest_path)
    check_bundle_hash(manifest)
    click.echo("Manifest schema and bundle hash OK.")
    if root:
        failures = verify_files(manifest, root.resolve())
        if failures:
            click.echo("File verification failed:")
            click.echo("\n".join(f"- {msg}" for msg in failures))
            raise SystemExit(1)
        click.echo("All referenced files present with matching hashes.")


def main() -> None:
    try:
        cli()
    except ValidationError as exc:
        pointer = "/".join(str(x) for x in exc.absolute_path)
        message = textwrap.dedent(
            f"""\
            Validation error at '{pointer}':
            {exc.message}
            """
        )
        raise click.ClickException(message) from exc


if __name__ == "__main__":
    main()
