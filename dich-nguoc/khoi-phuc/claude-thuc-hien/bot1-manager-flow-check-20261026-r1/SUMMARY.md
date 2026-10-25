# Bot1PositionManagementFlowCheck: đề xuất bộ kiểm toàn vòng quản lý

## Trạng thái

- **Chưa biên dịch, chưa chạy** `Bot1PositionManagementFlowCheck.mq5`; **chưa chạy**
  `manager_flow_cases.py`; chưa so với bản gốc. Không tính kết quả mong đợi nào.
- Script nạp `Bot1PositionManagement.mqh`, và manager nạp `Bot1ManagementRealStart.mqh`.
  Lúc viết, cả hai chưa có trong `bot-cua-toi-1/source/` (đang giao ở phiên khác), nên chỉ
  biên dịch được sau khi Codex ghép. Không tạo hàm giả thay manager/RealStart, không sửa header.
- Chỉ ghi 3 tệp trong thư mục này. Không sửa nguồn chính, Git hay MT5; không chạy lệnh;
  không tạo tác tử; không đọc EX5, mã máy hay thư mục phân tích.
- Cấu hình lượt: thông tin hệ thống ghi mô hình Opus 5.5 (`claude-opus-5-5`) và Ultracode
  bật; tôi không tự kiểm được mức `max` từ trong lượt. Lượt này không có công cụ workflow
  và yêu cầu cấm tạo tác tử, nên làm một mình.

## Nguồn đã đọc (từ `dich-nguoc/khoi-phuc/`)

- Mẫu: `bot-cua-toi-3/bang-chung/kiem-quan-ly-vi-the/manager-flow-claude-20261025-r1/tested-sources/Bot3PositionManagementFlowCheck.mq5`;
  cùng thư mục, chỉ để so chữ ký: `Bot3PositionManagement.mqh`, `Bot3VirtualStops.mqh`, `Bot3PositionClose.mqh`.
- `bot-cua-toi-3/tests/manager_flow_cases.py`; `claude-thuc-hien/bot3-manager-flow-check-20261025-r1/CONTRACT.md`
  (nghĩa các trường của mẫu).
- `claude-thuc-hien/bot1-manager-complete-20261026-r1/TASK.md` và `CORRECTION.md` cùng thư mục;
  `claude-thuc-hien/bot1-real-start-20261026-r1/TASK.md` (giao diện RealStart).
- Header Bot1 hiện hành: Prelude, VirtualFinish, VirtualStops, RealTimed, RealDistance,
  RealSlippage, RealHighLow, RealLock, RealCounter, RealStore, Messages, TradeErrors,
  PositionModify, PositionClose, TradeSend, PendingRequest, PriceLevels.
- Quy ước bộ kiểm Bot1 trước: `claude-thuc-hien/bot1-real-six-check-20261026-r1/` (`.mq5`, `.py`, `SUMMARY.md`).

## Khác biệt so với mẫu Bot3 (`.mq5`)

| Phần | Mẫu Bot3 | Bản này |
|---|---|---|
| Tên, include | `Bot3…`, `Include/bot-cua-toi-3/` | `Bot1…`, `Include/bot-cua-toi-1/`; trước macro: `Bot1PositionModify`, `Bot1PositionClose`, `Bot1VirtualStops`; sau macro: `Bot1PositionManagement.mqh` |
| Thư mục Files | `bot3-position-management-flow\CheckRun\` | `bot1-position-management-flow\CheckRun\` |
| Magic | `0x4d504d33` | `0x4d504d31` ở `cases.bin`; `mql5-results.bin` và `cast-values.bin` chép magic đã kiểm như mẫu |
| Kiểm ca | index 0..8 | index 0..7; profile 16 là ca sai (lỗi 9, dừng vòng như mẫu) |
| Dịch vụ take | `FTakeLevel`, trace 21, macro `Bot3VirtualTakeLevel`, biến `FTakeReply` | bỏ hẳn |
| Kiểu trong hàm giả | `Bot3PendingRequestState`, `Bot3TradeSendOptions`, `Bot3VirtualStopState` | kiểu `Bot1…` tương ứng; thân hàm, trace id 8/9/20/22/23 và kiểu trả giữ như mẫu |
| Macro dịch vụ | `Bot3ModifyPosition`… | `Bot1ModifyPosition`, `Bot1TryClosePosition`, `Bot1VirtualStopLevel`, `Bot1VirtualStopDelayPassed`, `Bot1VirtualStopStamp` |
| Settings | nến 3 nhóm, `candle_shift`, take trail ở 16/21 | profile 7/8 chỉ `candle_enabled[0]=1`, `candle_timeframe[0]=15`; không `candle_shift`; profile 21 chỉ bật phần của 14/15/17/18/19/20 |
| Shared | `anchor.rows`, `anchor.step_reference=7.5`, `current_take=444`, `take_rows` | `cache[100][2]` (0 từ ZeroMemory), `copied_step=7.5`; không current_take; bảng chỉ seed `rows[500][3]` |
| Mảng | `volumes`/`levels` 9 | 8 (`.1+i*.01`; 95 mua, 105 bán) |
| Profile 13 | `FTakeReply=bid/ask` | không còn nhánh riêng, khởi tạo như profile 0 |
| Đầu ra | 120 byte `<7iIIQ5di4Q` | 112 byte `<7iIIQ4di4Q`: bỏ current_take; double thứ 4 là `copied_step`; cache_hash trên 200 ô `shared.cache`; table_hash chỉ 1500 ô stop |

## Phần giữ nguyên

- Đầu vào 84 byte `<20iI`, 20 tên int đúng thứ tự, count 1..10000, kiểm cỡ `12+84*count`,
  đọc hết tệp (lỗi 10); tên run 1..50 ký tự `a-z0-9-`; không ghi đè; mã trả 4/5/6/7/8/11;
  lỗi 9/10/20..30, chỉ giữ lỗi đầu.
- Các API giả khác giống hệt mẫu: PositionsTotal (17, đổi eligible sau lần gọi đầu),
  PositionGetTicket (2), PositionGetDouble (3), PositionGetInteger (4), PositionGetString (5),
  SymbolInfoInteger (1, đổi mode ở lần DIGITS thứ `flip_digit`), SymbolInfoDouble (18),
  SymbolInfoTick (6), TimeCurrent (19), iTime/iClose/iOpen (10/11/12), Print (7),
  GetLastError (không ghi sự kiện).
- FModify (8) trả `modify_ok`. FTryClose (9) kiểm `deviation`, bit `tick.bid`/`tick.ask`
  so với `FShared.tick`, bit gap/freeze so với `FCfg` (sai thì lỗi 29), rồi xóa vị thế khi
  `close_ok` và profile khác 7. FStopLevel (20) chỉ trả lời đáp, không chạy bảng thật;
  FDelay (22) trả `delay_pass`; FStamp (23) chỉ ghi sự kiện, không ghi bảng. Không gửi lệnh.
- Khởi tạo khác như mẫu: symbol CHECK, unit 1, stop 10, take 20, emergency .5, gap .2,
  freeze 2.5, mode, eligible ban đầu/sau Total, delay 60 và 7, anchor_limit 1, shift 10,
  min_steps 2, index/error_count/counter từ ca, last_ticket 123456, tick -100/-101,
  current_stop 333, guard 1, khóa `(double)(long)(double)(long)ticket` và giá lời đáp stop
  cho mỗi vé khác 0. Mảng vé động không được đụng tới.
- `cast-values.bin` 32 hằng như mẫu (cả 444, chỉ cấp định dạng chuỗi); `script-status.bin`
  2 int32; Print cuối là Print thật vì macro đã `#undef`.
- `Bot1TradeErrorText`, câu báo lỗi và Print trong header Bot1 chạy thật trên GetLastError/Print giả.

## Python (`manager_flow_cases.py`)

- Nạp `parents[2]/bot-cua-toi-3/tests/manager_flow_cases.py` bằng importlib: không quét đĩa,
  không ghi `sys.modules`, không ghi tệp. `parents[2]` là `dich-nguoc/khoi-phuc/` ở cả thư mục
  đề xuất lẫn `bot-cua-toi-1/tests/`.
- `cases()`: ca Bot3 theo thứ tự cũ, bỏ profile 16, deepcopy, `source_case_id` là id Bot3,
  id mới 0..n-1, `index %= 8`; giá trị khác và group giữ nguyên.
- `encode()`: header `<3i` (magic `0x4d504d31`, version 1, count 1..10000) rồi `<20iI` mỗi ca;
  kiểm kiểu/miền bằng `_field` của Bot3, thêm index 0..7 và profile khác 16; không sửa đầu vào.
- `settings(c)`: bản sao settings Bot3 dạng phẳng, bỏ `take_trail_distance`,
  `take_trail_start`, `candle_shift`; nến chỉ 2 phần tử.
- `positions` (deepcopy), `tick_reply`, `minimum_reply` ủy quyền Bot3; `levels_reply` trả
  float mức dừng (phần tử đầu của Bot3). Các hàm fixture từ chối profile 16 hoặc index ngoài 0..7.
- Xuất `MAGIC`, `VERSION`, `HEADER`, `CASE`, `INTS` (bản sao), `DEFAULTS` (bản sao).
- Số ca theo đọc mã Bot3, **chưa chạy**: Bot3 có 364 ca; bỏ 12 ca profile 16 (baseline 4,
  modifyfalse 4, ticket64 4) còn 352 ca. Mọi ca Bot3 có index 2 nên `%8` không đổi giá trị.
  Cỡ dự kiến: `cases.bin` 12+352×84 = 29580 byte, `mql5-results.bin` 12+352×112 = 39436 byte.

## Đối chiếu tĩnh (chỉ đọc mã)

- Mọi API mà các header nạp sau macro gọi đều có hàm giả (Prelude, VirtualFinish,
  RealTimed/Distance/Slippage/HighLow/Lock/Counter/Store, Messages; RealStart và manager theo
  TASK). Print ở các header này chỉ có 1 đối số chuỗi. Header có Print nhiều đối số
  (`Bot1VirtualStops.mqh`, `Bot1PendingRequest.mqh`) đã nạp trước macro.
  `Bot1TradeErrors.mqh` nạp lần đầu sau macro (qua Messages) và không gọi Print/GetLastError.
- Đóng sớm: bước 5 của TASK manager ghi `SymbolInfoDouble(symbol,SYMBOL_VOLUME)`, nhưng
  `CORRECTION.md` sửa thành `PositionGetDouble(POSITION_VOLUME)`. Với bản sửa, FPositionDouble
  nhận POSITION_VOLUME nên không lỗi 20. Nếu manager ghép lỡ theo bản chưa sửa, FSymbolDouble
  (giữ như mẫu) sẽ báo lỗi 24.
- `FTryClose` giữ kiểu trả bool như mẫu dù `Bot1TryClosePosition` là void; mọi chỗ gọi trong
  header Bot1 đều bỏ kết quả. `FDelay` giữ chữ ký mẫu `(Bot1VirtualStopState&,const int,const long)`;
  header thật là `(const Bot1VirtualStopState&,const int&,const long)`; lời gọi trong
  `Bot1StartVirtualManagement` hợp với cả hai.
- Tên trường script dùng, phải trùng struct trong `Bot1PositionManagement.mqh` cuối:
  settings `symbol, magic, enabled, unit, stop_distance, take_distance, emergency_offset,
  candle_enabled[], candle_timeframe[], anchor_limit, high_low_eligible, timed_activation,
  timed_distance, timed_delay_seconds, virtual_delay_seconds, trail, trail_step, trail_start,
  trail_limit, slippage_enabled, slippage_trail, slippage_start, slippage_limit,
  high_low_gap_count, gap, freeze, finish.*`; shared `cache, copied_step, table, current_stop,
  volumes, strategy_index, error_count, counter, last_ticket, tick`.

## Codex cần kiểm

1. Ghép `.mq5` vào `Scripts/bot-cua-toi-1/`, `.py` vào `bot-cua-toi-1/tests/`; ghép manager
   (áp dụng `CORRECTION.md`) và RealStart; biên dịch, mục tiêu 0 lỗi/0 cảnh báo.
2. Chạy factory, chạy script trong MT5 thử, so độc lập với kết quả gốc theo thứ tự.
3. Nếu so hồi quy với lượt Bot3 thì ghép theo `source_case_id`, không theo `id`.
