# PitterOmat v2 — Projektstruktur

- `speckit/` — Speckit Prompts (Constitution, Specify, Plan, Tasks, Implement, Clarify, Analyze, Checklist, CHANGES)
- `project/assets/LED_RING/` — Lege hier deine Ring‑Fotos/Skizzen ab.
- `project/firmware/arduino/ESP32/tests/` — ESP32 Testsketche (Arduino IDE).
- `project/firmware/arduino/MEGA/` — Arduino Mega RS‑485/Buttons/LED.
- `project/ui/EEZ/` — Manuelles EEZ‑Projekt.
- `project/manifests/` — Platzhalter für spätere Manifeste/Versionen.

**Workflow (Kurz):**  
1) LED‑Ring‑Foto ablegen → Mapping erstellen.  
2) EEZ‑UI bauen (manuell) → Admin‑PIN, Optionen, Debug.  
3) ESP32 Master/Slaves & Mega RS‑485 testen.  
4) „LichtLoser“ implementieren, LED‑Cap prüfen.  
5) Tests laufen lassen und erfolgreiche unter `_archive_successful/` ablegen.
