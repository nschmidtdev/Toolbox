# Agent Guide

## Project Overview

Toolbox is a Windows desktop application written in C++23. It provides a
WebView2/Saucer GUI, a system tray interface, Lua-based tools, and a
machine-readable CLI.

## Repository Layout

- `src/`: implementation, grouped by `core`, `lua`, `platform`, and `ui`.
- `inc/`: public project headers, mirroring the source layout.
- `cli/`: CLI entry point and command handling.
- `res/`: web UI assets embedded into the executable by Saucer.
- `tests/`: C++, Python, and Node.js contract tests.
- `lib/`: vendored and submodule dependencies; avoid editing unless required.

## Development

Use CMake 3.30 or later and a compiler with C++23 support. On Windows, use an
MSVC developer shell when configuring and building.

```powershell
cmake -S . -B cmake-build-debug
cmake --build cmake-build-debug --config Debug
ctest --test-dir cmake-build-debug --output-on-failure -C Debug
```

For a release build, configure `cmake-build-release` and build with
`--config Release`.

## Change Guidelines

- Keep headers in `inc/` and implementations in the corresponding `src/`
  area.
- Preserve the CLI contract: operational commands emit one JSON object to
  stdout and use a non-zero exit code on failure.
- Treat Lua tools as trusted local code; do not unintentionally restrict the
  `os`, `io`, or `package` libraries exposed by the runner.
- When changing files under `res/`, verify that the embedded-resource build
  still succeeds.
- Add or update focused tests under `tests/` for changed behavior.
- Do not commit generated build directories such as `cmake-build-*` or
  `out_embed`.

## Validation

Run the relevant CTest target(s) for narrow changes. Run the full CTest suite
for changes that affect shared behavior, the CLI, Lua execution, settings, or
the runtime UI contract.
