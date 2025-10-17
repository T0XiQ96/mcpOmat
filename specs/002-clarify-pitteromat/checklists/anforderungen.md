# Anforderungen-Checkliste: PitterOmat Kernerlebnis

**Zweck**: Formale Abnahme der schriftlichen Anforderungen (Gameplay, Hardware, Admin-Sync) vor Umsetzung.  
**Erstellt**: 2025-10-17  
**Tiefe**: Formaler Gate (alle Punkte müssen beantwortet werden, bevor Implementierung startet)  
**Nutzerkreis**: Reviewer & Autor:innen

## Requirement Completeness
- [ ] CHK001 Sind RS485-Verkabelungsanforderungen für Master, Clients und Arduino (inkl. Abschluss- und Bias-Widerstände) vollständig dokumentiert? [Completeness, Hardware-Setup §Steuergeräte & Kommunikation]
- [ ] CHK002 Sind Anforderungen zur Stromversorgung und Strominjektion für den kompletten LED-Ring erfasst? [Completeness, Hardware-Setup §Leistungsversorgung]
- [ ] CHK003 Beschreiben die Spezifikation und Randfälle Joker-Konfiguration (Farbe, Aktivierung, Ausschluss bei fünf Spielern) vollständig? [Completeness, Spec §FR-003; Spec §Randfälle]
- [ ] CHK004 Decken die Admin-Diagnoseanforderungen sämtliche Subsysteme (RS485, WLAN, LED, Displays, Log) ab? [Completeness, Spec §FR-007]
- [ ] CHK005 Ist der Umgang mit Test-Bundles (Erstellung, expected.log, Manifest-Stub) vollständig festgehalten? [Completeness, Test-Workflow §Ablauf-Checkliste]

## Requirement Clarity
- [ ] CHK006 Ist der „Ready-Screen“ in Ablauf, Interaktion und Trigger-Ereignissen eindeutig beschrieben? [Clarity, Spec §US1]
- [ ] CHK007 Sind die Manifest-Validierungsschritte mit konkreten Befehlen und Zuständigkeiten formuliert? [Clarity, Quickstart §1; Plan §Technischer Kontext]
- [ ] CHK008 Sind Display-Sitzplatzzuordnungen widerspruchsfrei und eindeutig für jede Spieleranzahl festgelegt? [Clarity, Hardware-Setup §Display-Zuordnung]
- [ ] CHK009 Sind zeitliche Anforderungen wie 10 s Admin-Fenster und 2 min Diagnose klar quantifiziert und kontextualisiert? [Clarity, Hardware-Setup §Besonderheiten & Betriebsannahmen; Spec §FR-007]

## Requirement Consistency
- [ ] CHK010 Stimmen Joker-Vorgaben in Spezifikation, Hardware-Setup und LED-Testanforderungen überein? [Consistency, Spec §FR-003; Hardware-Setup §LED-Ring; Test-Workflow §Manifest & Schema]
- [ ] CHK011 Sind Manifest-Blockierregeln konsistent zwischen Spezifikation und Quickstart-Smoke-Test beschrieben? [Consistency, Spec §FR-006; Quickstart §4]
- [ ] CHK012 Ist die RS485-Pinbelegung in Plan und Hardware-Dokument konsistent ausgewiesen? [Consistency, Plan §Technischer Kontext; Hardware-Setup §Steuergeräte & Kommunikation]

## Acceptance Criteria Quality
- [ ] CHK013 Sind die Erfolgskriterien für Admin-Diagnosen (≤ 2 min) messbar und decken alle geforderten Subsysteme ab? [Acceptance Criteria, Spec §FR-007; Spec §SC-004]
- [ ] CHK014 Ist das Ziel „Idle → Gameplay in 90 s“ prüfbar für alle unterstützten Spielerzahlen? [Acceptance Criteria, Spec §SC-001]

## Scenario Coverage
- [ ] CHK015 Decken die Anforderungen Rückzugs- und Joker-Umschalt-Szenarien vollständig ab? [Coverage, Spec §Randfälle]
- [ ] CHK016 Sind Hash-Mismatch- und SD-Fehlerszenarien inklusive Admin-Reaktion beschrieben? [Coverage, Spec §FR-006; Spec §FR-008]

## Edge Case Coverage
- [ ] CHK017 Sind Sicherheitsmaßnahmen (Isolationsmessung, Not-Aus, reduzierte Erstinbetriebnahme) als Anforderungen festgehalten? [Edge Case, Hardware-Setup §Sicherheit & Tests]
- [ ] CHK018 Beschreiben die Anforderungen den Umgang mit RS485-Störungen während des Spiels inklusive Wiederanlauf? [Edge Case, Spec §Randfälle]

## Non-Functional Requirements
- [ ] CHK019 Sind Performance- und Offline-Anforderungen (LED-Latenz, 90 s Setup, kein Cloud-Zwang) vollständig dokumentiert? [Non-Functional, Plan §Technischer Kontext; Spec §SC-001]
- [ ] CHK020 Sind Spannungs-/Stromanforderungen als Betriebsvorgaben formuliert? [Non-Functional, Hardware-Setup §Leistungsversorgung]

## Dependencies & Assumptions
- [ ] CHK021 Sind Annahmen zur SD-Content-Erstellung und Schema-Validierung klar nachweisbar dokumentiert? [Dependency, Spec §Annahmen; Quickstart §1]
- [ ] CHK022 Ist die Abhängigkeit zu Waveshare-TREIBER-Demos sowie deren Pflege klar beschrieben? [Dependency, tests/README.md; Test-Workflow §Ziele]

## Ambiguities & Conflicts
- [ ] CHK023 Ist eindeutig geregelt, ob zusätzliche ESP32-Client-Displays optional sind und wie das System bei fehlenden Displays reagieren soll? [Ambiguity, Hardware-Setup §Steuergeräte & Kommunikation; Spec §Annahmen]
