You are the primary Claude implementer for the owner's lost-source recovery of Gold Trade Pro MT5. Codex manages, independently reviews, executes builds/tests and integrates. Read AGENTS.md and dich-nguoc/khoi-phuc/tai-lieu-cu/QUY-TRINH.md first. Be truthful about this reverse-engineering context and the limits of evidence. Do not bypass safeguards, alter licensing, or remove protections.

Assigned scope: the complete two bot1 position-management functions at RVA0x271f0 and RVA0x2abc0, including their branch/dependency inventory and a concrete path to exact MQL5 restoration. These are P20/P21 management of existing positions. Do not work on the refused coordinator0x10f60, strategy-entry body0x18aa0, or licensing. They are outside this task; do not rephrase/retry their earlier refusals.

Fresh immutable extraction, made before this task:
dich-nguoc/khoi-phuc/bot-cua-toi-1/phan-tich/dong-vi-the/management-20261025-r1/
- analysis.json: both full native instruction lists, original hash and boundaries.5621instructions total.
- functions.c: both complete C bodies with original source-line annotations.
- native-guards.txt: complete instruction text, not just selected branches.
- receipt.json: hashes of this extraction.
Original EX5 SHA256 a3b0de423a06e10ebedc279307b93d7cb9188ba2bb5de77131a913c865b0e922. Bot1 code base0x23e5aa10000; calculate RVA by subtraction, never by copying trailing hex digits.

Useful existing evidence and source (read only what this scope needs):
- ban-do-bot-1-3/luot-20261025-r3/bot-1.json: captured functions, direct calls, globals, typed settings origins.
- bot-cua-toi-1/phan-tich/dong-vi-the/modify-callers-20261025-r1/caller-sites.json:19calls of the modify helper in three functions. This scope contains9in each management function. Straight-line origins only, not full paths.
- bot-cua-toi-1/phan-tich/dong-vi-the/refs-20261025-r1/reference-origins.json: shared tick fields+8bid,+16ask. Do not assume all refresh/write paths already proved.
- PHAN-TICH-BANG-DUNG-AO-BOT-1-3.md and doi-chung-mt5/bang-dung-ao-20261024/: earlier Claude analysis, calibrated rounding constants, full-table warning7argument schema and Print opcode proof. These helpers are not yet restored/verified production code. Do not use old incomplete proposals as proven helpers.
- Current source/MQL5/Include/bot-cua-toi-1/Bot1PositionModify.mqh, Bot1PositionClose.mqh, Bot1TradeSend.mqh, Bot1TradeMessages.mqh, Bot1PendingRequest.mqh, Bot1Filling.mqh; scripts/checkers and saved tested-sources identify their exact public contracts.
- kiem-sua-vi-the-bot-1-3.py and KIEM-CHUNG-SUA-VI-THE-BOT-1-3.json: modify helper1596cases original/script/tester matched. Current aggregate passed; this is helper-only proof. No filling step in modify. Keep action/position -> symbol query -> storedmagic -> sl/tp -> actual send ordering.
- PHAN-TICH-CAI-DAT-BOT-1-3.md and existing settings/input maps for the actual global addresses. Unknown global names/types must remain explicitly unresolved.

Write all new deliverables only under this assigned directory. No canonical files, original EX5/captures, prior evidence, automatic memory, shell, MT5, git, other agents or background tasks. File tools only. No stubs, guessed branches, invented behavior or generic bot framework. Keep exact native integer widths, floating-point comparisons/NaN behavior, rounding, loop order, repeated SDK reads, shared writes, method results and side effects.

Required deliverables, in order:
1. analysis.md and machine-readable semantics.json: inventory BOTH COMPLETE functions before new production code. For every native conditional/loop region, list addresses, C lines, inputs/globals/types, precise comparisons/order/units, called helpers, state changes and exit behavior. Account for buy/sell differences and every existing-position strategy branch. Explain any C/native disagreement; native instructions decide. Distinguish observed direct call sites from complete runtime coverage. Record all unresolved items and exact evidence needed. Do not mark full analysis complete while a region remains unresolved.
2. dependency-map.json: all actual helpers and SDK operations required by the two functions, with exact existing implementation/proof if available. For missing virtual-level/time/cleanup/formatting/rounding helpers, identify original RVA, needed contract and smallest known-source calibration/native probe to resolve uncertainty. Do not assume earlier6native cases prove the full table.
3. If all required semantics for a complete executable part are established, provide complete proposed MQL5 files and a proportionate original-versus-MQL5 checker under files/, preserving the actual graph and existing helper behavior. First deliver the complete inventory; do not silently omit unresolved branches to make code compile. If a missing dependency prevents a correct full implementation, finish the full analysis plus that dependency's exact implementation/probe work only when proved; state the precise remaining blockers instead of writing placeholders. Production paths should mirror bot-cua-toi-1/source/MQL5; tool paths cong-cu/.
4. integration.json with exact proposed-to-canonical file mapping and ordered literal commands for Codex to execute, and SUMMARY.md with concrete completed outputs and remaining evidence. Proposals are not passed builds. No overall percentage or100% claim.

Priority: make useful progress toward a complete bot1, not more unrelated test infrastructure. Analyze entire two-function scope, then implement the largest fully evidenced coherent part. Keep all task output concise where possible but never truncate required code or inventory. Codex will independently verify each claim against the original before integration.
