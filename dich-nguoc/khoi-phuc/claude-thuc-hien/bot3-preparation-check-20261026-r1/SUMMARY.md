# Bot3PreparationCheck — đề xuất bộ kiểm khối chuẩn bị bot3

## Trạng thái

- Đã viết `Bot3PreparationCheck.mq5` trong thư mục này theo `TASK.md`.
- **Chưa biên dịch, chưa chạy, chưa đối chiếu** với EX5 gốc. Script không tính kết quả
  mong đợi: chỉ gọi `Bot3PrepareStrategy` và ghi lại state. Đúng/sai phải lấy từ lượt chạy
  bản gốc do Codex làm độc lập.
- Không sửa nguồn chính, Git, MT5; không chạy lệnh; không tạo tác tử; không đọc EX5, mã máy
  hay thư mục phân tích.
- Cấu hình lượt: môi trường ghi mô hình `claude-opus-5-5`, Ultracode bật. Tôi không tự kiểm
  được mức `max` từ trong lượt. Lượt này không có công cụ workflow và TASK cấm tạo tác tử,
  nên làm một mình.

## Nguồn đã đọc (từ `dich-nguoc/khoi-phuc/`)

- `claude-thuc-hien/bot3-preparation-check-20261026-r1/TASK.md` (việc này);
  `claude-thuc-hien/bot3-preparation-complete-20261026-r1/` gồm `TASK.md`, `Bot3Preparation.mqh`, `SUMMARY.md`.
- `bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/`: `Bot3Preparation.mqh`, `Bot3DistanceSettings.mqh`,
  `Bot3EntryProfiles.mqh`.
- `bot-cua-toi-3/source/MQL5/Scripts/bot-cua-toi-3/`: `Bot3DistanceSettingsCheck.mq5` (định dạng đọc/ghi
  cũ), `Bot3PreparationApiCompile.mq5`; mẫu dịch vụ giả và tệp trạng thái:
  `Bot3ManagementBarGateCheck.mq5`, `Bot3ManagementRealBlocksCheck.mq5`, `Bot3ManagementVirtualCheck.mq5`
  (dòng 70–129), `Bot3PositionManagementFlowCheck.mq5` (dòng 150–249).
- Biên nhận biên dịch `bot-cua-toi-3/bang-chung/bien-dich/b3-distance-settings-02/metaeditor.log` và
  `b3-preparation-api-20261026-r1/` (cả hai 0 lỗi, 0 cảnh báo); `tai-lieu-cu/QUY-TRINH.md`.
- `Bot3Preparation.mqh` **đã có trong nguồn chính**, trong khi TASK ghi chỉ có ở đề xuất. Đọc hai
  bản thấy giống nhau; tôi chưa tính mã băm. Biên nhận `b3-preparation-api-20261026-r1` ghi header
  SHA-256 `85362328543c1abaccb66a531d50f19812c8528c74919a69b827e84d0dbae786`.

## Thứ tự nạp

1. `#include "../../Include/bot-cua-toi-3/Bot3DistanceSettings.mqh"` đầu tiên (`:7`) để lấy
   `Bot3DistanceInputs`, `Bot3DistanceContext`; header này không gọi dịch vụ terminal. Guard của
   `Bot3EntryProfiles.mqh` làm header chuẩn bị không nạp lại tệp đó.
2. Biến toàn cục `PrepContext` (`Bot3DistanceContext`), 7 bộ đếm, `PrepCaseFault`, `PrepFault` (`:11-20`).
3. 7 dịch vụ giả (`:21-88`), định nghĩa trước macro.
4. 7 `#define` → `#include "../../Include/bot-cua-toi-3/Bot3Preparation.mqh"` → 7 `#undef` (`:90-104`).
   `ArraySetAsSeries`, `ArraySize`, `ArrayResize`, `Print`, `GetLastError` vẫn là hàm thật.
5. Hàm đọc/ghi và `OnStart` nằm sau `#undef`, nên `Print` cuối lượt là `Print` thật. Script chỉ
   gọi hàm tệp, chuỗi, mảng, `ZeroMemory` và `Print` cuối lượt; không gửi lệnh, không đọc giá thật.

## Đầu vào `Files/bot3-preparation/<CheckRun>/cases.bin`

- `CheckRun`: 1..50 ký tự `a-z`, `0-9`, `-`.
- Đầu 16 byte `<4i>`: magic `0x44535431`, version 1, bot 3, count 1..10000; cỡ tệp đúng `16+268·count`.
- Mỗi ca 268 byte, đọc bằng đúng các lệnh và thứ tự của `Bot3DistanceSettingsCheck.mq5` dòng 62–104
  (`PrepReadCase`, `:123-168`); không đọc struct có đệm. Bố cục tính tay, chưa chạy:
  `<id2id2i5i4d2i10d4i4di2q2dq` = id, reference, use_variable, adjust_lots, max_spread, feature_flag,
  freeze_buffer_flag, entry (confirmation_frame, entry_frame, older_width, recent_width, last_shift,
  gap_points), buy_offset, sell_offset, nearby_radius, expiration_hours, virtual_expiration,
  stop_distance, target_distance, trail_distance, trail_start, trail_limit, trail_step, native_6d368,
  native_6d370, trigger_distance, locked_distance, aux_hour1, aux_scan50, aux_older, aux_recent,
  aux_offset, min_change, rồi context sample, point, digits, stops_level, freeze_level, bid, ask, now.
- Cờ đọc như Script cũ (`FileReadInteger(h)!=0` → `bool`), rồi ép `(uchar)` khi gán vào Inputs mới.
- Đọc đủ 268 byte rồi mới so id với vị trí ca (0, 1, 2…).

## Inputs mới (`PrepFillInputs`, `:170-226`)

54 lệnh gán, đúng thứ tự khai báo của `Bot3PreparationInputs`; đã đối chiếu bằng tìm kiếm với 54
trường của header.

| Nguồn | Trường |
|---|---|
| Hằng | `symbol="XAUUSD"`, `comment="case"+IntegerToString(id)`, `indicator_timeframe=15`, `indicator_period=30` |
| Ca cũ, cờ ép `(uchar)` | `variable_distances` ← `use_variable`; `adjust_lots`, `feature_flag`, `freeze_buffer_flag`, `virtual_expiration`, `aux_hour1`, `aux_scan50` |
| Ca cũ, giữ kiểu | `reference`, `entry` (cả 6 trường), `max_spread`, `buy_offset`, `sell_offset`, `nearby_radius`, `expiration_hours`, `stop_distance`, `target_distance`, `trail_distance`, `trail_start`, `native_6d368`, `native_6d370`, `trail_limit`, `trail_step`, `trigger_distance`, `locked_distance`, `aux_older`, `aux_recent`, `aux_offset`, `min_change` |
| Bảng j, 22 trường | double `0.5+(double)id*0.125+(double)j*0.25`; int `(id%2==0 ? 1 : -1)*(id+j+1)`; uchar `(uchar)((id+j)%256)` (`:107-109`). Mỗi hàng j=0..21 dùng đúng một lần, đúng trường và kiểu của TASK (`:183-225`) |

Không tự tính tỷ lệ, đơn vị hay khoảng cách để điền state.

## Mỗi ca (`PrepRunCase`, `:315-329`)

1. `inputs`, `state` là biến cục bộ mới của ca: `ZeroMemory(inputs)` rồi điền; `ZeroMemory(state)`;
   `ArrayResize(state.indicator_values,0)`.
2. Đặt 7 bộ đếm và `PrepCaseFault` về 0.
3. Gọi đúng một lần `Bot3PrepareStrategy((uint)(id%9),inputs,state)` (`:326`). Không bắt lỗi:
   lỗi runtime làm dừng script tại đây, ca đó không có bản ghi/success và không có `script-status.bin`.
4. Lỗi đầu tiên của ca, nếu có, đưa vào `PrepFault` (giữ lỗi đầu tiên của lượt).
5. Ghi bản ghi từ state; không sửa state sau gọi.

## Dịch vụ giả (`:21-88`)

Mỗi hàm tăng bộ đếm của nó, kiểm tham số theo thứ tự đối số, giữ lỗi đầu tiên của ca và vẫn
trả giá trị đã định để ca được ghi. Không hàm nào đọc state.

| Macro → hàm giả | Kiểm (mã lỗi) | Trả / ghi |
|---|---|---|
| `iATR` → `FakeiATR` | symbol khác `XAUUSD` 21; `(int)frame`≠15 22; period≠30 23 | 17 |
| `CopyBuffer` → `FakeCopyBuffer` | handle≠17 31; buffer≠0 32; start≠0 33; count≠100 34 | `ArrayResize(target,2)`, hai ô = `sample`, trả 2; không đặt series |
| `iOpen` → `FakeiOpen` | symbol 41; frame≠`PERIOD_D1` 42; shift≠1 43 | `sample` |
| `SymbolInfoTick` → `FakeSymbolInfoTick` | symbol 51 | `time=(datetime)now`, `bid`, `ask`; trường khác giữ 0; trả `true` |
| `TimeCurrent` → `FakeTimeCurrent` (2 dạng) | không có | chung một bộ đếm; dạng `MqlDateTime&` gọi `ZeroMemory(calendar)`; trả `(datetime)now` |
| `SymbolInfoDouble` → `FakeSymbolInfoDouble` | symbol 71; khác `SYMBOL_POINT` 72 | `point` |
| `SymbolInfoInteger` → `FakeSymbolInfoInteger` | symbol 81; thuộc tính khác 82 | `SYMBOL_DIGITS` `(long)digits`; `STOPS_LEVEL`, `FREEZE_LEVEL` giữ nguyên long; thuộc tính khác trả 0 |

Giá trị 0 cho thuộc tính khác là lựa chọn của tôi vì TASK không nêu; header hiện hành chỉ hỏi
ba thuộc tính trên.

## Đầu ra

| Tệp | Bố cục |
|---|---|
| `mql5-results.bin` | đầu `<4i>`: `0x50525033`, 1, count, 76. Mỗi ca 616 byte `<2i76q>`: id, success=1, 76 từ 64 bit. Cỡ `16+616·count` (tính tay) |
| `script-status.bin` | `<2i>`: lỗi đầu tiên của lượt, count ở đầu `cases.bin`; 8 byte |

Cách ghi: double là bit thô qua `ValueBits`; int kéo dấu qua `(long)`; uint và uchar giữ giá trị;
long giữ nguyên. Không làm tròn, không đổi sang chuỗi. Đã đếm bằng tìm kiếm: 76 lệnh
`FileWriteLong(output,`.

| Từ | Trường `Bot3PreparationState` |
|---|---|
| 0–34 | đúng thứ tự Script cũ: scale, lot_scale, unit, spread, max_spread, feature_flag, freeze_buffer, entry_frame, older_width, recent_width, last_shift, gap_points, buy_offset, sell_offset, nearby_radius, stop_distance, target_distance, trail_distance, trail_start, trail_limit, trail_step, trigger_distance, locked_distance, native_6d378, native_6d380, aux_frame, aux_scan, aux_older, aux_recent, aux_offset, min_change, stop_min_price, freeze_min_price, expiration_seconds, expiration |
| 35–56 | hàng j=0..21: native_6d4e0, native_6d4e8, native_6d4f0, native_6d4f8, native_6d500, native_6d508, native_6d50c, native_6d510, mode, native_6d518, native_6d51c, native_6d520, native_6d550, management_timeframe, native_6d608, native_6d600, native_6d618, native_6d620, native_6d628, native_6d630, native_6d638, native_6d640 |
| 57–68 | native_6d5c8, native_6d5f0, native_6d5dc, native_6d5e8, native_6d5f8, expiration_hours, point, strategy_index, indicator_handle, `ArraySize(indicator_values)`, `(int)ArrayGetAsSeries(indicator_values)`, FNV-1a 64 của comment (UTF-16LE, byte thấp trước, không NUL; khởi đầu `0xcbf29ce484222325`, nhân `0x100000001b3`) |
| 69–75 | số lần gọi iATR, CopyBuffer, iOpen, SymbolInfoTick, TimeCurrent, SymbolInfoDouble, SymbolInfoInteger |

## Mã trả và lỗi

| Mã | Khi | `script-status.bin` |
|---|---|---|
| 4 | CheckRun sai | không ghi |
| 5 | đã có `mql5-results.bin` hoặc `script-status.bin` (không ghi đè) | không ghi |
| 6 | không mở được `cases.bin` | không ghi |
| 7 | magic, version, bot, count hoặc cỡ tệp sai; chưa tạo đầu ra | không ghi |
| 8 | không mở được `mql5-results.bin` | không ghi |
| 11 | không mở được `script-status.bin` | không ghi |
| 9 | id khác vị trí ca: dừng vòng, không gọi hàm cho ca đó; `mql5-results.bin` thiếu các ca sau | có |
| 10 | chưa đọc hết `cases.bin` | có |
| 21–82 | tham số dịch vụ sai (bảng trên); lượt vẫn chạy hết | có |

Chạy hết thì `OnStart` trả lỗi đầu tiên (0 là không lỗi) và in `Bot3PreparationCheck:<lỗi>,<count>`.

## Giới hạn và phần ngoài lượt này

- Chỉ đường chạy thành công với bộ ca Codex chọn. Lỗi runtime (mảng ngắn, chia 0), chỉ báo thất
  bại (handle<0, copied==0, Tick false), thiếu dữ liệu và toàn EA nằm ngoài lượt này; chưa có phép
  chạy hai bot song song.
- Không có từ riêng cho `state.virtual_expiration` (chỉ thấy qua `expiration`), `tick`, `calendar`
  và giá trị trong `indicator_values` (chỉ ghi số ô và cờ series). TASK không yêu cầu các từ này.
- Bộ đếm chỉ đếm số lần gọi; không ghi thứ tự gọi hay giá trị đối số ngoài phép kiểm lỗi.
- Lỗi theo ca không nằm trong bản ghi; `script-status.bin` chỉ giữ lỗi đầu tiên của lượt, không cho
  biết ca nào.
- Cờ đọc qua `!=0` như Script cũ: giá trị khác 0/1 trong tệp sẽ thành 1. TASK nói bộ ca chỉ có 0/1;
  script không kiểm thêm.
- `entry.confirmation_frame` được đọc và chép nhưng header không dùng.
- Đường dẫn include chỉ đúng khi tệp nằm ở `MQL5/Scripts/bot-cua-toi-3/`.

## Codex cần kiểm

1. Đặt `.mq5` vào `bot-cua-toi-3/source/MQL5/Scripts/bot-cua-toi-3/`, biên dịch với
   `Bot3Preparation.mqh` và `Bot3DistanceSettings.mqh` hiện hành; mục tiêu 0 lỗi, 0 cảnh báo.
   Biên nhận đã đọc cho thấy cách đọc từng trường, union bit (Script cũ) và `ZeroMemory` hai struct
   mới (`Bot3PreparationApiCompile.mq5`) biên dịch sạch; cách thay dịch vụ bằng macro giống các script
   kiểm khác trong nguồn chính, tôi chưa xem biên nhận của chúng. Script này chưa biên dịch.
2. Tạo `Files/bot3-preparation/<run>/cases.bin` theo định dạng cũ từ các ca gốc chạy thành công;
   chạy trên MT5 thử riêng; kiểm `script-status.bin` là (0, count).
3. So từng từ, theo thứ tự ca, với kết quả bản gốc lấy độc lập; không dùng nguồn MQL5 mới làm đáp án.
