import json
import os
import pathlib
import subprocess
import sys
import tempfile


def run(cli: pathlib.Path, *args: str, expected_code: int = 0,
        env: dict[str, str] | None = None) -> dict:
    completed = subprocess.run(
        [str(cli), *args],
        check=False,
        capture_output=True,
        text=True,
        encoding="utf-8",
        env=env,
    )
    assert completed.returncode == expected_code, completed.stderr or completed.stdout
    if expected_code == 0:
        assert completed.stderr == "", completed.stderr
    return json.loads(completed.stdout)


def run_text(cli: pathlib.Path, *args: str) -> str:
    completed = subprocess.run(
        [str(cli), *args],
        check=False,
        capture_output=True,
        text=True,
        encoding="utf-8",
    )
    assert completed.returncode == 0, completed.stderr or completed.stdout
    assert completed.stderr == "", completed.stderr
    return completed.stdout


def main() -> None:
    cli = pathlib.Path(sys.argv[1])
    assert cli.is_file(), f"CLI binary missing: {cli}"

    short_help = run_text(cli, "-h")
    long_help = run_text(cli, "--help")
    for help_text in (short_help, long_help):
        assert "TOOLBOX CLI" in help_text
        assert "BEFEHLE" in help_text
        assert "list" in help_text
        assert "create" in help_text
        assert "run" in help_text
        assert not help_text.lstrip().startswith("{")
    colored_help = run_text(cli, "--color", "always", "-h")
    assert "\x1b[" in colored_help

    with tempfile.TemporaryDirectory(prefix="toolbox-cli-test-工具-") as home:
        created = run(
            cli,
            "--home", home,
            "create",
            "--name", "Agent 工具",
            "--description", "Created through the CLI",
            "--script", 'assert(type(toolbox.open_url) == "function")\nprint("agent-ready-✓")',
            "--timeout", "5",
        )
        assert created == {
            "message": "Tool wurde erstellt.",
            "ok": True,
            "tool": "Agent 工具",
        }

        listed = run(cli, "--home", home, "list")
        assert listed["ok"] is True
        assert listed["tools"] == [{
            "description": "Created through the CLI",
            "name": "Agent 工具",
        }]
        listed_with_trailing_home = run(cli, "list", "--home", home)
        assert listed_with_trailing_home == listed
        forced_color_listed = run(cli, "--color", "always", "--home", home, "list")
        assert forced_color_listed == listed

        executed = run(cli, "--home", home, "run", "Agent 工具")
        assert executed == {
            "ok": True,
            "output": "agent-ready-✓\n",
            "tool": "Agent 工具",
        }

        script_file = pathlib.Path(home) / "skript-工具.lua"
        script_file.write_text('print("datei-✓")\n', encoding="utf-8")
        file_created = run(
            cli,
            "--home", home,
            "create",
            "--name", "Datei 工具",
            "--script-file", str(script_file),
        )
        assert file_created["ok"] is True
        file_executed = run(cli, "--home", home, "run", "Datei 工具")
        assert file_executed == {
            "ok": True,
            "output": "datei-✓\n",
            "tool": "Datei 工具",
        }

        syntax_sensitive_name = "x'); error('injected"
        injected = run(
            cli,
            "--home", home,
            "create",
            "--name", syntax_sensitive_name,
        )
        assert injected["ok"] is True
        injected_run = run(cli, "--home", home, "run", syntax_sensitive_name)
        assert injected_run == {
            "ok": True,
            "output": f"Hallo aus {syntax_sensitive_name}\n",
            "tool": syntax_sensitive_name,
        }

        default_home_env = os.environ.copy()
        default_home_env["USERPROFILE"] = home
        default_listed = run(cli, "list", env=default_home_env)
        assert {tool["name"] for tool in default_listed["tools"]} == {
            "Agent 工具", "Datei 工具", syntax_sensitive_name
        }

        rejected = run(
            cli,
            "--home", home,
            "create",
            "--name", "../escape",
            expected_code=2,
        )
        assert rejected["ok"] is False
        assert not (pathlib.Path(home) / "escape").exists()

    with tempfile.TemporaryDirectory(prefix="toolbox-cli-root-") as home, \
            tempfile.TemporaryDirectory(prefix="toolbox-cli-external-") as external:
        toolbox_root = pathlib.Path(home) / ".Toolbox"
        if sys.platform == "win32":
            linked = subprocess.run(
                ["cmd.exe", "/c", "mklink", "/J", str(toolbox_root), external],
                check=False,
                stdout=subprocess.DEVNULL,
                stderr=subprocess.DEVNULL,
            )
            assert linked.returncode == 0
        else:
            toolbox_root.symlink_to(external, target_is_directory=True)
        rejected_root = run(
            cli,
            "--home", home,
            "create",
            "--name", "Must Not Escape",
            expected_code=2,
        )
        assert rejected_root["ok"] is False
        assert not (pathlib.Path(external) / "Must Not Escape").exists()


if __name__ == "__main__":
    main()
