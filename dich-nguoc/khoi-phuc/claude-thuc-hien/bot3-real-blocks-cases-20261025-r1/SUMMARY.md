# SUMMARY — bot3-real-blocks-cases-20261025-r1

## Phạm vi và trạng thái

- Chỉ viết 2 tệp trong thư mục này: `real_blocks_cases.py`, `SUMMARY.md`.
- Chỉ đọc `TASK.md` ở đây và `TASK.md`, `CONTRACT.md` của
  `../bot3-real-blocks-check-20261025-r1`. Không đọc source bot hay phân tích
  lịch sử; không chạy lệnh, không dùng tác tử, không đụng Git hay tệp khác.
- **Chưa chạy**: chưa import, chưa ghi tệp nhị phân, chưa đưa vào bộ kiểm
  MQL5. Mọi số đếm dưới đây là tính tay từ mã. Kiểm nhanh:
  `python real_blocks_cases.py` in số ca theo (stage, nhóm) và tổng byte,
  không ghi tệp.
- Phiên: model `claude-opus-5-5` (theo thông tin phiên), Ultracode bật (theo
  thông báo hệ thống). Không có công cụ Workflow và đề cấm tác tử nên làm một
  mình. Mức effort thực tế không tự xác minh được trong phiên.

## Giao diện module

- `MAGIC = 0x4d524233`, `VERSION = 1`, `HEADER = struct.Struct('<3i')`,
  `CASE = struct.Struct('<22iqQII43d')` (`CASE.size` = 456; chuỗi định dạng ở
  `CASE.format`). Chỉ import `math`, `itertools`, `struct`.
- `INTS` 22 tên, `DOUBLES` 25 tên, đúng thứ tự CONTRACT.
- `cases()` → list dict. Mỗi dict có 22 khoá `INTS`, 25 khoá `DOUBLES`,
  `ticket` (int64), `deviation` (uint64), `index`, `error_count` (uint32),
  `volumes`, `levels` (list 9 float, tạo mới mỗi ca), `group` (str), `id` =
  vị trí (liên tục từ 0). Tổng ≥ 4000 → `ValueError` kèm số ca, không cắt bớt.
- `encode(rows)` → `bytes`: 3 int32 (magic, 1, count) + 456 byte/ca theo thứ
  tự 22 int32, ticket, deviation, index, error_count, 25 double, 9 volumes,
  9 levels. Trước khi đóng gói kiểm: id = vị trí, count 1..100000,
  buy/modify_ok/prior_changed 0..1, stage 0..5, scenario 0..11, index 0..8,
  table_pattern 0..5, 6 cờ byte 0..255. Tràn int32/int64/uint64/uint32 do
  `struct` báo lỗi.
- `group` = `nhóm/trường=giá trị,...`; tên nhóm là phần trước `/`. Nhãn số
  dùng `repr`, `+0`/`-0`, NaN ghi `nan` + 16 hex bit.

## Số ca (tính tay, chưa chạy)

Tổng **2290** ca (< 4000); tệp 12 + 456 × 2290 = **1 044 252 byte**.

| id | Nhóm | Stage | Mỗi phía | Tổng |
|---|---|---|---|---|
| 0–11 | baseline | 0..5 | 1/stage | 12 |
| 12–1133 | special | 0..5 | 143/110/88/88/99/33 | 1122 |
| 1134–1645 | scenario | 0..4: 48/stage; 5: 16 | 256 | 512 |
| 1646–1735 | volume | 0 | 45 | 90 |
| 1736–1759 | deviation, ticket | 0 | 4 + 8 | 24 |
| 1760–1799 | flags | 1 | 20 | 40 |
| 1800–1839 | field | 2 | 20 | 40 |
| 1840–1877 | field, counter-wrap | 4 | 18 + 1 | 38 |
| 1878–2069 | table | 5 | 96 | 192 |
| 2070–2087 | ticket-number, ticket | 5 | 5 + 4 | 18 |
| 2088–2157 | index, digits | 0..4 | (2 + 5)/stage | 70 |
| 2158–2237 | error | 0..3 | 10/stage | 80 |
| 2238–2265 | nan-pair | 0..4 | 2/4/2/4/2 | 28 |
| 2266–2289 | lock-sweep, gap-sweep | 3; 4 | 9; 3 | 24 |

Theo stage: 0 = 536, 1 = 400, 2 = 352, 3 = 334, 4 = 358, 5 = 310.
Trong mỗi khối: stage tăng dần → buy 0 rồi 1 → giá trị theo thứ tự đề.

## Điểm tự chọn / cách hiểu đề

1. Baseline: `scenario = 0` (không API nào có target 0 nên không Mutate).
   "digits3" hiểu là digits0..3 đều bằng 3. `initial_stop` 90,
   `ticket_number` 7, `current_stop` 95 dùng chung cho hai phía như đề.
2. `volumes[i] = 0.1 + i*0.01`, `levels[i] = 95.0/105.0 + i*0.01` tính bằng
   phép double của Python, không làm tròn thập phân (vd. `volumes[2]` =
   0.12000000000000001).
3. Giá trị đặc biệt: NaN A = bit `7ff8000000000123`, NaN B =
   `fff8000000000456`; ±Inf, ±0 cũng dựng từ bit; -1e19, -100.125, 0.01,
   100.125, 1e19 là literal. Ca `special` giữ mọi trường khác như baseline,
   scenario 0. Stage2 `levels[index]` = `levels[2]` (index gốc 2).
4. Chỗ đề chỉ ghi một "NaN": `volumes[index]`, `step_reference`,
   `ticket_number` dùng NaN A; `minimum` trong nhóm `volume` dùng NaN B để
   phân biệt NaN nào lan ra. "Inf" = +Inf, "0" = +0.
5. Nhóm `scenario`: `minimum = +0` cho mọi stage 0..5. Stage5 vẫn đổi
   `modify_ok`, `prior_changed` như đề (16 ca/phía) dù hàm stage5 trong
   CONTRACT không nhận hai giá trị này.
6. Stage0 `deviation`/`ticket`: mỗi giá trị chạy với `minimum` 0.01 (gốc) và
   +0 (để nhánh Close/TryClose chạy, deviation mới vào sự kiện), nên 12
   ca/phía thay vì 6. Nhóm `volume` + `deviation` + `ticket` = 57 ca/phía
   (≤ 60). Muốn bỏ phần thêm thì lọc `minimum=+0` trong `group`.
7. Stage4 "counter intmax × scenario DIGITS2=3": hiểu là lần gọi DIGITS thứ
   hai (lần1, target 3) → 1 ca/phía `counter=INT_MAX, scenario=3`.
8. Stage5 "ticket64 độc lập": ngoài 5 ca `ticket_number` (-0, +0, 2^53+2,
   NaN A, +Inf; ticket giữ 7), thêm 4 ca/phía đổi `ticket` int64 ∈ {0,
   2^53+1, -1, -2^63} (tập của stage0), `ticket_number` giữ 7. Nếu đề chỉ có
   ý "ticket giữ nguyên" thì lọc `stage == 5` và nhóm `ticket`.
9. `index` và `digits` là hai nhóm riêng. Ca `index` giữ SL gốc; ca `digits`
   cộng 0.123456789 vào SL cả hai phía (buy 90.123456789, sell
   110.123456789, phép cộng double). Không làm cho stage5 (đề ghi 0..4).
10. `error` (stage 0..3; stage4 không có error_count): gộp hai cách đọc,
    error_count ∈ {0, 2^32-1} × [modify_ok 1 (error_code gốc 4756) +
    modify_ok 0 × error_code {-1, 0, 4001, 4756}] = 10 ca/phía/stage.
11. `nan-pair`: mỗi cặp chạy cả hai thứ tự (A, B) và (B, A) để thấy payload
    nào lan; scenario 0.
12. Quét ±1 ulp = double liền kề (bit ±1), có cả giá trị tâm. 0 ± ulp =
    ±5e-324 quanh +0. `lock-sweep`: lock_start × lock_extra = 3 × 3 ca/phía
    (buy tâm 5, sell tâm 4). `gap-sweep`: 3 ca/phía (buy 14, sell 13). Lưu ý
    4 − ulp = 4 − 2^-51 còn 4 + ulp = 4 + 2^-50.
13. Giữ mọi giá trị đề liệt kê kể cả khi trùng baseline. Tính tay có 40 ca
    trùng hẳn baseline (trừ id/group): `special` point 0.01 (stage0–3),
    minimum 0.01 (stage0), step_reference +0 (stage4); `field` giá trị gốc
    (stage2: 4, stage4: 4 mỗi phía); `flags` enabled 1 × passed 1; `table`
    pattern 0 × guard 1 × scenario 0; `error` error_count 0 + modify_ok 1.
14. Bit NaN/-0 được giữ vì `struct` `<d` chép nguyên byte IEEE (CPython);
    Codex cần so bit trên tệp đã ghi.

## Chưa phủ (đề không yêu cầu, để Codex chốt)

- Giá trị đặc biệt chỉ đi với scenario 0, không có ca giá trị đặc biệt × Mutate.
- `index` 8 và `deviation` 2^64-1 chưa đi với Mutate (chưa thử quay vòng về 0).
- Nhóm `scenario` stage0 chỉ có minimum +0.
- `ticket`/`deviation` không đổi ở stage1–4; `bid`/`ask` không đổi ở stage
  nào; stage5 không đổi digits.
