Owner-authorized recovery of lost trading-bot source is ongoing in this repository. Review our newly authored offline comparison harness and its MQL5 test driver, not the bot binaries. This is a new task focused on correctness of test infrastructure; no trading commands should run. The primary agent is responsible for the original-behavior analysis and final verification.

Read AGENTS.md, then these newly authored files:
- dich-nguoc/khoi-phuc/cong-cu/kiem-chon-lenh-huy-bot-1-3.py
- dich-nguoc/khoi-phuc/bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/Bot1PendingSelectionCheck.mq5
- dich-nguoc/khoi-phuc/bot-cua-toi-3/source/MQL5/Scripts/bot-cua-toi-3/Bot3PendingSelectionCheck.mq5
- dich-nguoc/khoi-phuc/bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/Bot1PipelineApi.mqh
- dich-nguoc/khoi-phuc/cong-cu/kiem-huy-lenh-cho-bot-1-3.py (dependency supplying the existing service/test framework)

Use independent parallel reviewers if available: (1) binary input/output encoding, nullable UTF-16 strings and raw floating-point payloads; (2) integrity of fixture validation and comparison, especially whether both sides could agree using the wrong supplied data; (3) build/source/dependency provenance and incomplete-run detection. Report only concrete defects with exact file/line and a failing example, or clearly state there is no demonstrated defect. Distinguish supplied service outcomes from algorithm outputs, and scoped finite tests from whole-bot completion. Do not change files or run shell commands. Return a concise report in Vietnamese.
