Review our newly authored position-close comparison harness and MQL5 test drivers in this owner-authorized lost-source recovery project. Complete the actual read-only review in this turn; do not launch background reviewers or return a promise to send a report later. No commands, edits or trading operations.

Read AGENTS.md and these current files:
- dich-nguoc/khoi-phuc/cong-cu/kiem-dong-vi-the-bot-1-3.py
- dich-nguoc/khoi-phuc/bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/Bot1PositionCloseCheck.mq5
- dich-nguoc/khoi-phuc/bot-cua-toi-3/source/MQL5/Scripts/bot-cua-toi-3/Bot3PositionCloseCheck.mq5
- dich-nguoc/khoi-phuc/bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/Bot1PositionClose.mqh
- dich-nguoc/khoi-phuc/bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/Bot3PositionClose.mqh
- dich-nguoc/khoi-phuc/doi-chung-mt5/dong-vi-the-20261024/close-api-r1/api-contract.json
- Existing unchanged helper Bot1PipelineApi.mqh in the bot1 Scripts directory, plus kiem-huy-lenh-cho-bot-1-3.py as the test-framework dependency.

Focus on concrete defects in binary input/output layout, nullable state and typed service replies, SDK/property binding, service-boundary state snapshots, reset of formatting counters across two close calls, return/completion/memory checks and build/source/tool provenance. Previously found null build-count and missing MQL tool-hash guards should remain fixed here. The native algorithm, supplied service responses and measured formatting must remain clearly distinguished. Report exact file/line and an independently checkable failing example for any defect; distinguish limitations from demonstrated failures. Return a concise report in Vietnamese. Read only the files needed for this review.
