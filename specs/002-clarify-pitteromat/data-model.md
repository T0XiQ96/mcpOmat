# Datenmodell – PitterOmat Kernerlebnis

## GameDefinition

| Feld | Typ | Beschreibung | Restriktionen |
|------|-----|--------------|---------------|
| `id` | string | Eindeutige Spielkennung (z.B. `lightloser`) | Muss dem Muster aus `game.schema.json` entsprechen |
| `version` | semver | Versionsanzeige für Menüs und Hash-Änderungen | Erforderlich |
| `title` | string | Lokalisierter Anzeigename | Erforderlich |
| `players.min` | integer | Minimale Spielerzahl | 2 ≤ min ≤ 6 |
| `players.max` | integer | Maximale Spielerzahl | min ≤ max ≤ 6 |
| `supportsHighscore` | bool | Steuert, ob Highscore-Ansicht erscheint | Erforderlich |
| `requiresHardware` | array | Benötigte Hardware (z.B. `encoder`, `display`) | Filtert inkompatible Modi |
| `ledProfile` | object | Nutzung von Spiel-/Grenzsegmenten | Referenzen müssen in `segment_map.json` existieren |
| `optionRefs` | array | Zugeordnete Options-Bundles | Optional |
| `phases` | array | Abfolge von Spielphasen mit Zeiten | Pflicht für Countdown/Gameplay-Steuerung |

**Beziehungen**: Referenziert mehrere `OptionBundle`-Einträge. Wird vom ESP32 ausgewertet; Metadaten informieren die Arduino-Planung.

## OptionBundle

| Feld | Typ | Beschreibung | Restriktionen |
|------|-----|--------------|---------------|
| `id` | string | Eindeutige Bundle-ID | Erforderlich |
| `title` | string | Anzeigename | Erforderlich |
| `scope` | enum | `user`, `admin` oder `system` | Bestimmt Menübereich |
| `fields[]` | object | Einzeloptionen mit key/type/default | Schlüssel einzigartig innerhalb des Bundles |
| `effects` | array | Betroffene Subsysteme (`led`, `session`, …) | Optional |
| `appliesTo` | array | Spiel-IDs oder `["*"]` | Standardmäßig global |

**Beziehungen**: Wird in `GameDefinition.optionRefs` referenziert. ESP32-Anwendung verarbeitet und verteilt Einstellungen an den Arduino.

## PlayerSlot

| Feld | Typ | Beschreibung | Restriktionen |
|------|-----|--------------|---------------|
| `slotId` | integer | Logischer Sitzplatz (1–6) | Eindeutig pro aktiver Session |
| `displayId` | integer | Zugeteiltes Display (1–8) | Laut Sitzplan |
| `spiel.start` | integer | Start-Segment auf SpielLED | Aus `segment_map.json` |
| `spiel.end` | integer | End-Segment (inklusive, Wrap erlaubt) | Aus `segment_map.json` |
| `border.left` | integer | GrenzLED zum linken Nachbarn | Dauerhaft aktiv |
| `border.right` | integer | GrenzLED zum rechten Nachbarn | Dauerhaft aktiv |
| `jokerGroup` | integer/null | Joker-Segment bei aktiviertem Joker | Null, wenn Joker aus |

**Beziehungen**: Wird vom ESP32 beim Setup erzeugt und an den Arduino zur LED-Steuerung übertragen.

## HardwareNode

| Feld | Typ | Beschreibung | Restriktionen |
|------|-----|--------------|---------------|
| `nodeId` | string | Eindeutiger Knoten (z.B. `esp-master`) | Erforderlich |
| `role` | enum | `master_esp`, `client_esp`, `arduino` | Legt Verantwortungen fest |
| `firmwareVersion` | string | Installierte Firmware-Version | Wird bei Updates verglichen |
| `bundleHash` | string | Bestätigter Manifest-Hash | Muss Master-Hash entsprechen |
| `lastSeen` | timestamp | Letzter Heartbeat | >10 s löst Warnung aus |
| `status` | enum | `ready`, `syncing`, `fault`, `offline` | Speist Admin-Anzeige |

**Beziehungen**: Der Master-ESP verwaltet den Status aller Knoten; Admin-Diagnosen zeigen diese Übersicht.

## ManifestEntry

| Feld | Typ | Beschreibung | Restriktionen |
|------|-----|--------------|---------------|
| `type` | enum | `game`, `options`, `theme`, `profile`, `music`, `logo` | Erforderlich |
| `id` | string | Asset-ID | Innerhalb eines Typs eindeutig |
| `version` | semver | Inhaltsversion | Erforderlich |
| `file` | string | POSIX-Pfad auf SD | Muss existieren |
| `hash` | string | `sha256:<digest>` | Muss zum Dateihash passen |
| `metadata` | object | Zusatzinfos (z.B. Kompatibilität) | Optional |

**Beziehungen**: Wird vom `manifest_tool` generiert; ESP32 prüft damit SD-Inhalte und sendet den Bundle-Hash.

## Zustandsübergänge

### Sitzungslebenszyklus

`Idle` → `Configuring` → `ReadyCheck` → `Gameplay` → `Results` → `Idle`

- Übergang `Configuring → ReadyCheck`: Auslösung nach Spielerauswahl und Spielwahl, PlayerSlots werden verteilt.
- Übergang `ReadyCheck → Gameplay`: Alle Spieler müssen bestätigen; bei Abbruch Rückkehr zu `Configuring`.
- Übergang `Gameplay → Results`: Trigger durch Spielende; LED-Animationen und Ergebnisse werden angezeigt.
- Manueller Abbruch (Admin) bringt das System nach `Idle` zurück und protokolliert den Grund.

### Admin-Freigabefenster

`Locked` → `Unlocked` (Button gehalten) → automatische Rückkehr zu `Locked` nach 10 s oder bei manuellem Beenden.

- Während `Unlocked` sind alle Admin-Diagnosen und Update-Steuerungen sichtbar.

## Validierungsregeln (Zusammenfassung)

- Sitzplatz-zu-Display-Tabelle muss pro Spielerzahl exakt dem Sitzplan entsprechen.
- Bei aktiviertem Joker sind Joker-Farbe und entsprechendes SpielLED-Segment verpflichtend; deaktivierte Joker müssen explizit gesetzt sein.
- Manifestprüfung (`bundleHash`) muss erfolgreich sein, bevor `ReadyCheck` in `Gameplay` übergeht.
- Hardware-Diagnosen müssen protokolliert werden, sobald `HardwareNode.status` auf `fault` oder `offline` wechselt.
