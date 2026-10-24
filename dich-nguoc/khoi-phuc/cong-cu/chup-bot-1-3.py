"""Capture only a tester from this project's private MT5, for bot 1 or 3.

Uses the existing read-only capture implementation and preserves its PID/path,
output-scope, memory-size and overwrite checks. Only the current project paths differ.
Usage: python -I -B -X utf8 chup-bot-1-3.py --bot 1 --pid PID --out NEW_CAPTURE_DIR
       --min-code-bytes 8192 --wait-seconds 15 --include-readonly --include-program-data
"""
import argparse
import importlib.util
from pathlib import Path
import sys

ap = argparse.ArgumentParser(add_help=False)
ap.add_argument('--bot', type=int, choices=(1, 3), required=True)
args, remaining = ap.parse_known_args()
root = Path(__file__).resolve().parents[1]
old = root / 'cong-cu-cu/inspect-ex5-running-code.py'
spec = importlib.util.spec_from_file_location('existing_capture', old)
module = importlib.util.module_from_spec(spec)
spec.loader.exec_module(module)
module.ROOT = root / f'bot-cua-toi-{args.bot}/bang-chung'
module.EXPECTED = root.parent / '.local/claude-recovery-20261023/mt5/metatester64.exe'
sys.argv = [str(Path(__file__).resolve()), *remaining]
module.main()
