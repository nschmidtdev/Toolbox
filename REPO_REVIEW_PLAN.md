# Repository Review Plan

## Kurzbewertung

Das Projekt ist ein brauchbarer Prototyp fuer eine Windows-Tray-Toolbox mit Saucer/WebView-UI, lokalen `.Toolbox`-Tools, Lua-Ausfuehrung und Tool-Konfiguration. Die Produktidee ist klar, aber die technische Struktur ist noch stark gewachsen: viel Verantwortung sitzt in `ToolboxWindow`, Threading ist riskant, der Build ist fragil und die HTML-Bruecke braucht Haertung.

## Priorisierter Plan

### 1. Build stabilisieren

Status: teilweise erledigt. Der lokale Debug-Build, CLion-CMake-Reload und ein Runtime-Smoke-Test von `Toolbox.exe` sind auf diesem Arbeitsplatz stabil. Vollstaendig abgeschlossen ist der Punkt erst, wenn auch Release/MinSizeRel, Doku und optional CI geprueft sind.

Erledigt:

- `CMakeLists.txt` target-basiert aufgeraeumt.
- Globale `include_directories()` durch `target_include_directories()` ersetzt.
- Doppelte Source-Einbindung entfernt.
- Source-Erfassung auf Wildcards mit `CONFIGURE_DEPENDS` umgestellt.
- `tray_windows.c` nicht mehr direkt im App-Target mitkompiliert.
- `c_tray` Windows-Backend stabilisiert: fehlende C-Header ergaenzt, Win32-Wide-API explizit genutzt und den 64-bit `malloc`-Pointer-Crash beim Tray-Menue behoben.
- Harte `/MTd`-CRT-Option aus `c_tray` entfernt, damit die Library zum restlichen MSVC-Debug-Build passt.
- Ungenutztes `saucer-desktop` aus dem App-Link entfernt.
- MSVC/Saucer-Fill-Konflikt fuer MSVC 19.44 behoben, indem Polyfill-Ersetzungen deaktiviert wurden.
- `WIN32_LEAN_AND_MEAN` vom App-Target entfernt, weil es GDI+ Header unvollstaendig machte.
- Reproduzierbaren lokalen Debug-Smoke-Build und App-Start geprueft.

Noch offen:

- Release-Build pruefen.
- MinSizeRel-Build pruefen.
- README um Build-Voraussetzungen und Build-Befehl ergaenzen.
- Pruefen, ob generierte Build-/Embed-Artefakte sauber ignoriert werden.
- Optional CI-Workflow fuer Debug/Release-Smoke-Build anlegen.

Reproduzierbarer lokaler Smoke-Build:

```powershell
cmd /c "call ""C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"" >nul && cmake -S . -B cmake-build-debug && cmake --build cmake-build-debug --target Toolbox --config Debug"
```

### 2. `ToolboxWindow` zerlegen

- Status: erledigt fuer die geplanten ersten Schnitte. `ToolRegistry`, `LuaRunner`, `ToolboxJsBridge`, `WindowPlacement` und `ResourceLoader` sind aus `ToolboxWindow` herausgezogen.
- `ToolRegistry`: erledigt. Scannt `.Toolbox`, liest `description.txt`, `icon.png`, `start.lua`.
- `LuaRunner`: erledigt. Startet/cancelt Lua-Tasks, verwaltet Timeout-Hook und haelt Task-State ausserhalb von `ToolboxWindow`.
- `ToolboxJsBridge`: erledigt. Registriert `m_webview.expose(...)` ueber explizite Callback-Bindings.
- `WindowPlacement`: erledigt. Buendelt DPI, Position, Groesse, Centering und Resize-Helfer.
- `ResourceLoader`: erledigt. Buendelt embedded resources, Start-URL, `serve`, Icon, Titel und Scheme.

### 3. Threading und UI-Zugriff bereinigen

- Detached Threads vermeiden oder zentral verwalten.
- Lua-Worker kontrolliert beenden.
- UI-Updates nicht direkt aus Worker-Threads ausfuehren.
- Sichtbarkeits- und Focus-State entweder UI-thread-lokal halten oder atomar absichern.

### 4. Frontend haerten

- `innerHTML`-Templates durch DOM-Erzeugung mit `textContent` ersetzen.
- Daten aus `.Toolbox` nicht ungeescaped rendern.
- Doppelte Render-Logik in `index.html` zusammenfuehren.
- UI-Zustand fuer laufende Tools klarer modellieren.

### 5. Lua-Policy klaeren

- Entscheiden, ob Tools trusted code sind.
- Falls nicht trusted: `os`, `io`, `package` standardmaessig deaktivieren oder Berechtigungen pro Tool einfuehren.
- Fehler und Status gezielt an die UI melden, statt pauschal zu reloaden.

### 6. Win32-Helfer vereinheitlichen

- F12-Subclassing aus Toolbox- und Optionsfenster in einen gemeinsamen Helper ziehen.
- `ShellExecuteW` statt `std::system` fuer Explorer/Terminal nutzen.
- Encoding-Probleme in Quelltext und UI bereinigen.

### 7. Tests und Smoke Checks einfuehren

- Unit-Tests fuer `ToolConfigStore`.
- Tests fuer Tool-Scanning ohne echte User-Home-Abhaengigkeit.
- Debug/Release-Smoke-Build lokal und spaeter in CI.
- Optional HTML-Lint oder DOM-Test fuer Renderfunktionen.
