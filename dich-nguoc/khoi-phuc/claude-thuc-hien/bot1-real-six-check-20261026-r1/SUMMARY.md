# Bot1ManagementRealBlocksCheck bản 6 khối: đề xuất

## Trạng thái

- **Chưa biên dịch, chưa chạy** script MQL5, **chưa chạy** `real_blocks_cases.py`,
  chưa so với bản gốc. Không tính kết quả mong đợi nào.
- Chỉ ghi 3 tệp trong thư mục này: `Bot1ManagementRealBlocksCheck.mq5`,
  `real_blocks_cases.py`, `SUMMARY.md`. Không sửa nguồn chính, Git hay MT5;
  không chạy lệnh; không tạo tác tử; không đọc EX5, mã máy hay thư mục phân tích.
- Cấu hình lượt: thông tin hệ thống của phiên ghi mô hình Opus 5.5
  (`claude-opus-5-5`) và báo Ultracode đang bật. Tôi không tự kiểm được mức
  `max` từ bên trong lượt. Không dùng workflow hay tác tử vì yêu cầu cấm tạo
  tác tử (lượt này cũng không có công cụ workflow).

## Nguồn đã đọc (từ `dich-nguoc/khoi-phuc/`)

- `bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/Bot1ManagementRealBlocksCheck.mq5`
  và `bot-cua-toi-1/tests/real_blocks_cases.py` (bản 3 khối, dùng làm gốc).
- `claude-thuc-hien/bot1-real-three-check-20261026-r1/TASK.md` (giao diện).
- `bot-cua-toi-3/source/MQL5/Scripts/bot-cua-toi-3/Bot3ManagementRealBlocksCheck.mq5` (mẫu cấu trúc 6 khối).
- Header Bot1: `Bot1ManagementRealHighLow.mqh`, `Bot1ManagementRealLock.mqh`,
  `Bot1ManagementRealCounter.mqh`, `Bot1ManagementPrelude.mqh`, `Bot1VirtualStops.mqh`,
  `Bot1ManagementMessages.mqh`, `Bot1TradeErrors.mqh`, `Bot1ManagementRealDistance.mqh`,
  `Bot1ManagementRealSlippage.mqh`, `Bot1ManagementRealStore.mqh`; tìm thêm dòng
  khai báo trong `Bot1PositionModify.mqh` và `Bot1PositionClose.mqh`.

## Phần đã sửa so với bản 3 khối (`.mq5`)

| Phần | Bản 3 khối | Bản này |
|---|---|---|
| Biến toàn cục | `int BlocksEnabled,BlocksCounter` | thêm `int BlocksGapCount,BlocksMinimumSteps`; `uchar BlocksBeforeOpen,BlocksShiftSetting,BlocksStepEnabled` |
| Đọc ca | gap_count, minimum_steps đọc vào biến cục bộ, không dùng | trong 22 int (đếm từ 0): ô 11 → `BlocksGapCount`, ô 12 → `BlocksMinimumSteps`. Ô 16/17/18 (before_open, shift_setting, step_enabled) đọc vào `int`, kiểm 0..255, rồi gán `(uchar)` vào biến toàn cục sau khi ca hợp lệ, trước khi gọi khối. Không thêm trường. |
| Kiểm stage | `stage` phải là 0, 1 hoặc 5 | `stage<0 \|\| stage>5` → ca sai, lỗi 9 |
| Include sau macro | Messages, Distance, Slippage, Store | Messages, Distance, Slippage, **HighLow, Lock, Counter**, Store (theo thứ tự stage như mẫu Bot3; thứ tự các include cũ giữ nguyên) |
| `BlocksRunStage` | `(stage,buy,passed_flag,ticket,position,changed)` | thêm `const uchar eligible_flag` sau `passed_flag`; thêm stage 2, 3, 4 |
| Stage 2 | không có | `Bot1AdvanceHighLowRealBuyStop/SellStop`, 18 đối số: `"CHECK",BlocksEnabled,eligible_flag,BlocksGapCount,BlocksUnit,BlocksBeforeOpen,BlocksShiftSetting,BlocksGap,BlocksFreeze,BlocksLevels,BlocksIndex,position,BlocksTick,changed,BlocksState,BlocksOptions,BlocksErrorCount,ticket` |
| Stage 3 | không có | `Bot1AdvanceRealLockBuyStop/SellStop`, 13 đối số: `"CHECK",BlocksLockStart,BlocksLockExtra,BlocksUnit,BlocksGap,BlocksFreeze,position,BlocksTick,changed,BlocksState,BlocksOptions,BlocksErrorCount,ticket` |
| Stage 4 | không có | `Bot1AdvanceRealCounterBuyStop/SellStop`, 17 đối số: `"CHECK",BlocksStepEnabled,BlocksStepReference,BlocksMinimumSteps,BlocksStepDistance,BlocksUnit,BlocksCopiedStep,BlocksAnchor,BlocksGap,BlocksFreeze,BlocksCounter,position,BlocksTick,changed,BlocksState,BlocksOptions,ticket` |
| returned | stage 1, 5 trả `false` | stage 1–5 trả `false`; chỉ stage 0 trả bool thật. Không suy từ `changed`, không bỏ qua khối khi `changed` đã true. |
| Chú thích | — | dòng 1 đổi "three" → "six"; chú thích Mutate thêm gap count, minimum steps; chú thích Messages thêm bộ báo lỗi high-low và lock; bỏ chú thích cũ "none of the three blocks takes them" vì không còn đúng; thêm một dòng ở chỗ gán uchar. |

`BlocksCounter` truyền cho `int &counter` của khối đếm chính là biến mà
`BlocksMutate` ghi. `BlocksIndex` và `BlocksLevels` truyền cho high-low cũng là
biến Mutate ghi. Mutate không đổi gap_count, minimum_steps và 3 cờ uchar.

## Phần giữ nguyên

- magic `0x4d524231`, version 1, count 1..100000, kiểm cỡ tệp `12+440*count`, đọc hết
  440 byte trước khi kiểm, đọc đủ tệp (lỗi 10).
- Đầu vào `<22iqQII41d`, đầu ra 384 byte `<5iIIQ41diQQ`: không thêm hay bớt trường.
  gap_count, minimum_steps và 3 cờ không có trong đầu ra, giống bản 3 khối.
- Mảng 8, index 0..7, Mutate `%8`; danh sách và thứ tự các biến Mutate đổi giữ nguyên.
- Bảng `rows[500][3]`, `guard`, `reported_ticket`; mẫu 0..5; băm 1500 ô; không `take_rows`.
- Hàm dịch vụ giả (DIGITS tối đa 4 lần, POINT tối đa 2 lần, VOLUME_MIN, GetLastError,
  Print, Modify, TryClose), sự kiện 5 word, FNV-1a 64 LE, chữ UTF-16LE.
- Không ghi đè, tên run 1..50 ký tự `a-z0-9-`, mã trả 4/5/6/11, lỗi 1/2/7/8/9/10,
  `script-status.bin`, `Print` cuối là Print thật vì macro đã `#undef`.
- Prelude và VirtualStops nạp trước macro; Messages nạp đầu tiên sau macro.

## Python (`real_blocks_cases.py`)

- Chỉ đổi `STAGES = (0, 1, 2, 3, 4, 5)` và hai chú thích: docstring đầu tệp
  (thay "chỉ stage 0, 1, 5" bằng "mọi stage 0..5" kèm tên TASK này, rồi xuống dòng
  lại câu kế tiếp) và docstring `cases()`.
- Giữ nguyên: nạp ca Bot3, thứ tự cũ, `deepcopy`, `source_case_id`, id liên tục,
  cắt volumes/levels còn 8, `index %= 8`, kiểm `LIMITS`/`STAGES`/độ dài mảng, encode.
- Chưa chạy nên chưa biết số ca và số byte.

## Đối chiếu tĩnh (chỉ đọc mã, chưa biên dịch)

- Kiểu đối số khớp khai báo header: `const int &` ← `int`, `const uchar &` ← `uchar`,
  `const uint &` ← `uint`, `int &counter` ← `int`, `uint &error_count` ← `uint`,
  `const double &levels[]` ← `double[8]`.
- Đếm theo mã header, số lần gọi DIGITS/POINT lớn nhất trên một đường:
  high-low mua 3/2, bán 2/2; lock mua 4/1, bán 2/1; counter 2/0. Các số này nằm
  trong giới hạn của dịch vụ giả (4/2).
- Câu báo lỗi high-low (`error: '…' when modifying stoploss`) và lock
  (`error when setting breakeven: …`) bắt đầu bằng `error`, nên `BlocksPrint` hiện có
  xếp chúng vào đích 8. Khối counter không gọi Print hay GetLastError.

## Codex cần kiểm

1. Ghép `.mq5` vào `Scripts/bot-cua-toi-1/` và `.py` vào `bot-cua-toi-1/tests/`.
   `SOURCE_PATH` dùng `parents[2]`, đúng cho cả hai vị trí.
2. Biên dịch (mục tiêu 0 lỗi/0 cảnh báo), chạy factory, chạy script, rồi so độc lập
   với kết quả gốc.
3. Mỗi ca nhận `id` mới vì giờ có cả stage 2/3/4. Nếu dùng kết quả lượt 3 khối để
   kiểm hồi quy stage 0/1/5 thì phải ghép theo `source_case_id`, không theo `id`.
4. Ca Bot3 có index 8 sẽ thành 0 sau `%8` (có từ bản 3 khối). Ở stage 2, khối
   high-low đọc `levels[index]` nên các ca này đọc `levels[0]`. Cần xem ca nào bị ảnh hưởng.
