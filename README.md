# Toolbox

Eine modulare Werkzeug-Sammlung für Windows mit Lua-Scripting,
WebView2-basiertem GUI und CLI.

## Lizenz

Dieses Projekt steht unter der **GNU Affero General Public License v3.0
oder später** (AGPL-3.0-or-later).

- [LICENSE](LICENSE) – AGPL-3.0 Lizenztext
- [CONTRIBUTING.md](CONTRIBUTING.md) – Contributor License Agreement (CLA)

Contributor erteilen mit der Einreichung von Code eine Genehmigung, dass
ihr Beitrag vom Projektinhaber unter beliebigen Lizenzen weiterverwendet
werden darf (CLA, siehe CONTRIBUTING.md).

## Abhängigkeiten und Lizenzen

| Bibliothek | Lizenz | Quelle |
|---|---|---|
| saucer | MIT | https://github.com/saucer/saucer |
| sol2 | MIT | https://github.com/ThePhD/sol2 |
| lua-cmake | MIT | https://github.com/lubgr/lua-cmake |
| c_tray | MIT | https://github.com/binRick/c_tray |
| nlohmann/json | MIT | https://github.com/nlohmann/json |
| cppcodec | MIT | https://github.com/tplgy/cppcodec |
| CLI11 | BSD-3-Clause | https://github.com/CLIUtils/CLI11 |
| rang | Unlicense | https://github.com/agauniyal/rang |
| Prism.js | MIT | https://prismjs.com (Lea Verou) |
| coco | MIT | https://github.com/Curve/coco |
| saucer-fill | MIT | (CPM, saucer-Abhängigkeit) |
| saucer-embed | MIT | (CPM, saucer-Abhängigkeit) |
| glaze | MIT | (CPM, saucer-Abhängigkeit) |
| lockpp | MIT | (CPM, saucer-Abhängigkeit) |
| packageproject | MIT | (CPM, saucer-Abhängigkeit) |
| ereignis | MIT | (CPM, saucer-Abhängigkeit) |
| flagpp | MIT | (CPM, saucer-Abhängigkeit) |
| polo | MIT | (CPM, saucer-Abhängigkeit) |
| rebind | MIT | (CPM, saucer-Abhängigkeit) |
| saucer4lua | proprietär/inhouse | https://git.schmidti.digital/Yadciel/saucer4lua |
| toolbox_win | proprietär/inhouse | (projekt-intern) |

Alle MIT-, BSD-3- und Unlicense-Bibliotheken sind mit der AGPL-3.0
kompatibel.

## install

first install node.js

then run 

    npm install -g @saucer-dev/cli

build embeded files with line

    saucer embed <source> <destination>

like

    saucer embed D:/Repos/Toolbox/res/html D:/Repos/Toolbox/out_embed

## Agent CLI

`Toolbox.exe` provides a machine-readable JSON interface without starting the GUI:

```text
Toolbox.exe list
Toolbox.exe create --name "My Tool" --description "Example" --script-file start.lua --timeout 30
Toolbox.exe run "My Tool"
Toolbox.exe -h
```

Use `--home <path>` before the command to target a different user directory. `-h` and `--help` show the human-readable, colored help. Colors are selected automatically and can be overridden with `--color always` or `--color never`. Operational commands continue to write exactly one JSON object to stdout and use a non-zero exit code on failure.

Tools are trusted local Lua programs. `run` exposes the same `os`, `io`, and `package` libraries as the Toolbox GUI, so agents should only execute reviewed tools.
