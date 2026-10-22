"""Thử một bài phục hồi mã trong phiên Claude mới và lưu bằng chứng."""
import argparse
import hashlib
import json
import os
import re
import subprocess
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from project_paths import PROJECT, WORK, recorded_path


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--claude", type=Path, required=True)
    parser.add_argument("--prompt", type=Path, required=True)
    parser.add_argument("--run", required=True)
    parser.add_argument("--profile", choices=("control", "project", "system"), required=True)
    parser.add_argument("--effort", choices=("low", "medium", "high", "max"), default="low")
    args = parser.parse_args()
    if not re.fullmatch(r"[a-z0-9_-]{1,60}", args.run):
        parser.error("Tên lượt chỉ gồm chữ thường, số, dấu - hoặc _.")
    prompt_file = args.prompt.resolve()
    if not prompt_file.is_relative_to(PROJECT) or not prompt_file.is_file():
        parser.error("Bài thử phải là tệp trong dự án.")
    if not args.claude.is_file() or args.claude.name.lower() != "claude.exe":
        parser.error("Cần đường dẫn tới claude.exe đã cài.")
    output = WORK / ".local/claude-recovery-check" / (args.run + ".json")
    if output.exists():
        parser.error("Lượt này đã có kết quả; dùng tên mới.")

    rules = PROJECT / "CLAUDE.md"
    prompt = prompt_file.read_text(encoding="utf-8-sig")
    prompt += "\nGiới hạn câu trả lời 200 từ, ưu tiên mã và các điểm cần kiểm.\n"
    command = [
        str(args.claude.resolve()), "-p", "--output-format", "json",
        "--no-session-persistence", "--disable-slash-commands",
        "--strict-mcp-config", "--tools", "", "--max-turns", "1",
        "--no-chrome", "--effort", args.effort,
    ]
    if args.profile == "control":
        command.append("--safe-mode")
    elif args.profile == "system":
        command.extend(["--system-prompt-file", str(rules)])
    env = os.environ.copy()
    env.update({
        "CLAUDE_CODE_DISABLE_AUTO_MEMORY": "1",
        "CLAUDE_CODE_SKIP_PROMPT_HISTORY": "1",
        "CLAUDE_CODE_DISABLE_NONESSENTIAL_TRAFFIC": "1",
    })
    report = {
        "profile": args.profile, "effort_requested": args.effort,
        "prompt_file": recorded_path(prompt_file),
        "prompt_sha256": hashlib.sha256(prompt.encode("utf-8")).hexdigest(),
        "rules_sha256": hashlib.sha256(rules.read_bytes()).hexdigest(),
        "agents_sha256": hashlib.sha256((PROJECT / "AGENTS.md").read_bytes()).hexdigest(),
        "command": command, "session_persistence": False,
    }
    start = time.monotonic()
    try:
        result = subprocess.run(command, input=prompt, text=True, encoding="utf-8",
                                capture_output=True, cwd=PROJECT, env=env, timeout=180)
        report["exit_code"] = result.returncode
        data = json.loads(result.stdout)
        report.update({
            "is_error": data.get("is_error", False),
            "subtype": data.get("subtype"), "response": data.get("result", ""),
            "models": list(data.get("modelUsage", {})), "usage": data.get("usage", {}),
        })
    except (OSError, subprocess.TimeoutExpired, json.JSONDecodeError) as error:
        report.update({"is_error": True, "error": str(error)})
    report["elapsed_seconds"] = round(time.monotonic() - start, 2)
    report["has_requested_function"] = bool(re.search(
        r"\bbool\s+RecoveredVolume\s*\(", report.get("response", "")))
    # Có hàm trong câu trả lời chưa chứng minh biên dịch đúng.
    output.parent.mkdir(parents=True, exist_ok=True)
    with output.open("x", encoding="utf-8") as stream:
        json.dump(report, stream, ensure_ascii=False, indent=2)
    print(json.dumps({key: report.get(key) for key in (
        "profile", "effort_requested", "exit_code", "is_error", "models",
        "has_requested_function", "elapsed_seconds")}, ensure_ascii=False), flush=True)
    print(recorded_path(output), flush=True)
    return 1 if report.get("is_error") or report.get("exit_code") != 0 else 0


if __name__ == "__main__":
    raise SystemExit(main())
