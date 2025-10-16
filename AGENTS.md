# Repository Guidelines
This guide helps contributors extend mcpOmat and its Spec Kit tooling consistently.

## Project Structure & Module Organization
- `pitteromat/` hosts agent-facing projects; mirror its `.specify/` scaffolding when starting new agents and keep runtime code beside it (e.g., `pitteromat/src`, `pitteromat/tests`).
- Root `.specify/` stores shared scripts/templates used by CI; prefer updating these copies so every agent inherits improvements.
- `.github/` contains the `spec-check.yml` workflow and PR template; keep workflow-only changes isolated.
- `.vscode/mcp.json` enumerates MCP servers; extend it when adding new backends.
- Specs live under `specs/NNN-feature-slug/` (created on demand); commit the entire folder whenever you touch a feature.

## Build, Test, and Development Commands
- `uv tool install specify-cli --from git+https://github.com/github/spec-kit.git` installs the Spec Kit CLI locally.
- `specify check` runs the same validation as CI; execute it before every PR.
- `pwsh .specify\scripts\powershell\check-prerequisites.ps1` (or the Bash twin) verifies required tooling on Windows/macOS/Linux.
- `pwsh .specify\scripts\powershell\create-new-feature.ps1 "Describe capability"` seeds a numbered spec directory and optional branch.

## Coding Style & Naming Conventions
- Use 4-space indentation in PowerShell, Bash, and future runtime code; keep line endings LF.
- Adopt uppercase snake case for env vars and camelCase for script-local variables, matching existing scripts.
- Keep Markdown headings sentence case and reuse `.specify/templates/*.md` structures; avoid bespoke formatting without justification.
- Feature directories must retain the `NNN-slug` pattern produced by the helper script.

## Testing Guidelines
- Write or update automated tests next to the code they cover (`tests/`, `*.spec.*`, etc.) and document run commands inside the spec.
- `specify check` is mandatory; add language-specific test invocations via Spec Tasks so CI captures them.
- After larger refactors, run `.specify/scripts/powershell/update-agent-context.ps1` to refresh agent memory assets.

## Commit & Pull Request Guidelines
- Follow Conventional Commits (`feat:`, `fix:`, `chore:`, …) as seen in `git log`; include the spec ID when applicable (e.g., `feat: 042 add plan sync`).
- Limit each PR to one feature or fix, update the spec/plan/checklist, and complete the checklist in `.github/pull_request_template.md`.
- Link related issues, attach relevant logs or screenshots, and confirm `specify check` passes before requesting review.
