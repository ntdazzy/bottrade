Analyze four small position-scan helpers in this owner-authorized lost-source recovery project. Read AGENTS.md. Complete the read-only analysis in this turn, without agents, background workflows, shell commands, edits, or trading operations. Scope excludes licensing/protection logic.

Read the frozen excerpts and exact instructions:
- dich-nguoc/khoi-phuc/bot-cua-toi-1/phan-tich/dong-vi-the/scan-20261025-r1/functions.c
- dich-nguoc/khoi-phuc/bot-cua-toi-1/phan-tich/dong-vi-the/scan-20261025-r1/native-guards.txt
- dich-nguoc/khoi-phuc/bot-cua-toi-3/phan-tich/dong-vi-the/scan-20261025-r1/functions.c
- dich-nguoc/khoi-phuc/bot-cua-toi-3/phan-tich/dong-vi-the/scan-20261025-r1/native-guards.txt
- corresponding analysis.json files and the existing close-20261024-r1/semantics.json files in the same dong-vi-the directories.

Produce a precise implementation checklist: loop endpoints, one-time versus repeated reads, signed32 overflow/sign extension, full64 comparisons, short-circuit identity reads, nullable UTF-16 string comparison, ticket writes/read timing, ignored volume read and subsequent complete close-guard call. Distinguish bot1's eight identities from bot3's fifteen. Identify service callbacks that could change globals between reads and boundary cases that would catch incorrect caching. State unresolved origins separately; do not name shared prices without source evidence. Compute relative addresses by subtracting code_base (bot1 0x23e5aa10000, bot3 0x17156250000); never infer them from trailing digits. Return a concise Vietnamese report with instruction/line evidence. Finite tests or a captured function list do not prove the complete EA.
