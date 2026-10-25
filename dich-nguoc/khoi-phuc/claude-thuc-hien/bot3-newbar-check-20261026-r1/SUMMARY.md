# Bot3ManagementBarGateCheck: đề xuất bộ kiểm cổng nến mới

## Trạng thái

- **Chưa biên dịch, chưa chạy** `Bot3ManagementBarGateCheck.mq5`; **chưa chạy**
  `bar_gate_cases.py`; chưa so với bản gốc. Không tính kết quả mong đợi nào.
- Chỉ ghi 3 tệp trong thư mục này. Không sửa nguồn chính, Git hay MT5; không chạy
  lệnh; không tạo tác tử; không đọc EX5, mã máy hay thư mục phân tích.
- Hàm được kiểm `Bot3ManageOnBarChange` nằm trong `Bot3ManagementBarGate.mqh`. Tìm tên
  tệp thấy header này đã có ở `bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/` và ở
  `claude-thuc-hien/bot3-newbar-manager-20261026-r1/`, nhưng tôi **không mở** để bộ kiểm
  không dựa vào mã được kiểm. Lời gọi viết theo chữ ký trong TASK của helper; chỉ
  biên dịch mới xác nhận là khớp.
- Cấu hình lượt: thông tin hệ thống ghi mô hình Opus 5.5 (`claude-opus-5-5`) và
  Ultracode bật; tôi không tự kiểm được mức `max` từ trong lượt. Lượt này không có
  công cụ workflow và yêu cầu cấm tạo tác tử, nên làm một mình.

## Nguồn đã đọc (từ `dich-nguoc/khoi-phuc/`)

- `claude-thuc-hien/bot3-newbar-check-20261026-r1/TASK.md` (việc này) và
  `claude-thuc-hien/bot3-newbar-manager-20261026-r1/TASK.md` (chữ ký, thứ tự gọi helper).
- `bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/Bot3PositionManagement.mqh`: struct,
  chữ ký `Bot3ManagePositions`, guard `BOT3_POSITION_MANAGEMENT_MQH`.
- Mẫu đọc/ghi/FNV: `bot-cua-toi-3/source/MQL5/Scripts/bot-cua-toi-3/Bot3PositionManagementFlowCheck.mq5`;
  `Bot3PositionManagementApiCompile.mq5` cùng thư mục (include riêng header là đủ kiểu, `ZeroMemory` dùng được).
- Quy ước factory: `bot-cua-toi-3/tests/manager_flow_cases.py` (dòng 1–200),
  `claude-thuc-hien/bot1-real-six-check-20261026-r1/` và `claude-thuc-hien/bot1-manager-flow-check-20261026-r1/`
  (`.py`, `SUMMARY.md`); `tai-lieu-cu/QUY-TRINH.md`.
- Tìm dòng (chỉ xem dòng khớp): `itertools`/`group` trong `bot-cua-toi-3/tests/`; tên tệp
  `FileOpen(folder+"….bin"` trong `Scripts/bot-cua-toi-3/` (giữ `cases.bin`, `mql5-results.bin`,
  `script-status.bin`); `struct Bot3VirtualFinishSettings` kèm 3 dòng sau (không có `mode`);
  định danh `Gate[A-Z]…`, `FakeiTime`, `FakeBot3ManagePositions` trong `Include/bot-cua-toi-3/`
  (không tệp nào khớp, nên không trùng tên).

## Script `Bot3ManagementBarGateCheck.mq5` (đích `Scripts/bot-cua-toi-3/`)

Thứ tự nạp:

1. `Bot3PositionManagement.mqh` trước mọi macro, để có kiểu. Hàm quản lý thật biên dịch
   với API thật nhưng không được gọi.
2. Biến kiểm và hai hàm giả `FakeiTime`, `FakeBot3ManagePositions`.
3. `#define iTime FakeiTime`, `#define Bot3ManagePositions FakeBot3ManagePositions`.
4. `Bot3ManagementBarGate.mqh`. Guard đã có nên lần nạp `Bot3PositionManagement.mqh` bên
   trong header này (theo TASK helper) bị bỏ qua; macro không chạm hàm thật.
5. `#undef` hai macro. `OnStart` chỉ gọi
   `Bot3ManageOnBarChange(GateCfg.symbol,GateFrame,(uint)GateCase.index,GateBars,GateCfg,GateShared,GateLevelsBuy,GateLevelsSell,GateRequests,GateOptions,GateDeviation)`.

Khởi tạo mỗi ca, sau khi đã đọc và kiểm đủ 64 byte:

- `ZeroMemory` GateCfg, GateShared, GateRequests, GateOptions trước mọi lệnh gán.
- `GateCfg.symbol="CHECK"`, `GateCfg.finish.mode=1`, `GateShared.counter=7`,
  `GateShared.strategy_index=(index+1)%9`.
- `GateBars[i]=100+i` rồi `GateBars[index]=previous`; `GateLevelsBuy[i]=10+i`,
  `GateLevelsSell[i]=20+i` (double); `GateFrame=timeframe`; `GateDeviation=0x0123456789abcdef`.
- Băm về `0xcbf29ce484222325`; số sự kiện và số lần gọi về 0. Lỗi đầu tiên giữ suốt lượt.

Dịch vụ giả (`index` là index đọc từ ca):

| Hàm | Kiểm (mã lỗi) | Sự kiện 5 word | Sau sự kiện | Trả |
|---|---|---|---|---|
| `FakeiTime(symbol,frame,shift)` | symbol khác `CHECK` (20); shift khác 1 (21); lần gọi thứ 3 trở đi (22) | `1`, `(ulong)(long)(int)frame`, `1`, `(ulong)GateBars[index]`, `(ulong)giá trị trả` | lần 0: `GateFrame=after_first_frame`; `change_first_bar` 1 thì `GateBars[index]=after_first_bar`. Lần sau không đổi | lần 0 `observed`, lần sau `second`, ép `datetime` |
| `FakeBot3ManagePositions` (chữ ký thật) | `deviation` khác `GateDeviation` (30); `settings.symbol` khác `CHECK` (31); lần gọi thứ 3 trở đi (32); lần 0 không phải mua hoặc lần 1 không phải bán (33) | `2` mua / `3` bán, `(ulong)(long)shared.counter`, `(ulong)(long)settings.finish.mode`, `(ulong)shared.strategy_index`, bit `levels[0]`; lấy từ đối số, không đọc biến toàn cục | mua và `change_buy` 1: `GateShared.counter++`, `GateCfg.finish.mode++`, `GateShared.strategy_index=(…+1)%9`, `GateBars[index]+=10`. Bán không đổi gì | `buy_reply` / `sell_reply` khác 0, dù state có đổi hay không |

Hàm giả không gọi chiều còn lại, không so thời gian nến, không tính kết quả helper.
Băm: FNV-1a 64 trên từng byte little-endian của 5 word, như `FHashWord` của FlowCheck;
`event_count` đếm mọi sự kiện của cả hai hàm.

Tệp trong `Files/bot3-management-bar-gate/<CheckRun>/`:

| Tệp | Bố cục |
|---|---|
| `cases.bin` (vào) | `<3i`: magic `0x4d424733`, version 1, count 1..10000; cỡ đúng `12+64*count`. Mỗi ca `<8i4q`: id, index, timeframe, after_first_frame, buy_reply, sell_reply, change_first_bar, change_buy; previous, observed, second, after_first_bar |
| `mql5-results.bin` (ra) | `<3i` như đầu vào. Mỗi ca 108 byte `<7iQ9q`: id, returned (giá trị thật của helper), final_timeframe (`GateFrame`), final_counter, final_mode, final_shared_index, event_count; ordered_hash; 9 ô `GateBars` sau helper |
| `script-status.bin` (ra) | `<2i`: first_fault, count ở đầu tệp vào |

- Kiểm ca: id bằng số thứ tự, index 0..8, buy_reply/sell_reply/change_first_bar/change_buy
  0..1; timeframe, after_first_frame và 4 int64 giữ nguyên. Ca sai: lỗi 9, dừng vòng, không
  gọi helper cho ca đó. Còn byte chưa đọc: lỗi 10.
- Mã trả `OnStart`, không ghi status: 4 tên run sai (1..50 ký tự `a-z0-9-`); 5 đã có
  `mql5-results.bin` hoặc `script-status.bin` (không ghi đè); 6 không mở được `cases.bin`;
  7 đầu tệp hoặc cỡ sai; 8 không mở được tệp kết quả; 11 không mở được tệp status. Chạy hết
  thì trả `first_fault` (0 là không lỗi) và in `Bot3ManagementBarGateCheck:<lỗi>,<count>`
  bằng `Print` thật.

## Python `bar_gate_cases.py`

- Chỉ dùng `itertools`, `struct`. Có `MAGIC`, `VERSION`, `HEADER` (`<3i`), `CASE` (`<8i4q`),
  `INTS`, `LONGS`, `cases()`, `encode(rows)`.
- `cases()`: `itertools.product` theo đúng thứ tự TASK, trục đầu đổi chậm nhất: index
  [0,4,8]; (timeframe, after_first_frame) [(15,16385),(0,15)]; (previous, observed, second)
  [(0,0,5),(1000,1000,1100),(1000,1100,1200),(1000,0,1300)]; rồi change_first_bar,
  change_buy, buy_reply, sell_reply, mỗi trục [0,1]. after_first_bar = 5000, id liên tục.
  Do đó id = 128·(vị trí index) + 64·(vị trí frame) + 16·(vị trí times) + 8·change_first_bar
  + 4·change_buy + 2·buy_reply + sell_reply.
- `group` = `index<i>/frame<timeframe>/times<previous>-<observed>-<second>`, chỉ ghép giá
  trị đầu vào.
- `encode(rows)`: count 1..10000, id liên tục, kiểu `int` (không nhận bool), index 0..8,
  4 cờ 0..1, int32/int64 có dấu cho trường còn lại, mỗi bản ghi đúng 64 byte, tổng
  `12+64*count`. Sai thì báo lỗi, không sửa ca.
- Import không ghi đĩa, không dùng số ngẫu nhiên; chạy trực tiếp chỉ in số ca và số byte.
- Số tính từ mã, **chưa chạy**: 3×2×4×2×2×2×2 = 384 ca, 24 nhóm × 16 ca; `cases.bin`
  12+64×384 = 24588 byte; `mql5-results.bin` sẽ dài 12+108×384 = 41484 byte;
  `script-status.bin` 8 byte.

## Ghi chú (đọc mã, chưa biên dịch)

- Word thứ 3 của sự kiện iTime là hằng `1` theo TASK; shift sai chỉ hiện qua lỗi 21,
  không đổi băm.
- Ngoài hợp đồng (chỉ xảy ra khi đã có lỗi 22/32/33): iTime lần 3 trở đi vẫn ghi sự kiện
  và trả `second`; manager lần 3 trở đi vẫn ghi sự kiện và trả lời đáp theo chiều; mỗi sự
  kiện mua có `change_buy` 1 đều đổi state, kể cả lần mua sai thứ tự.
- Index ca là 0/4/8, còn `GateShared.strategy_index` bắt đầu ở 1/5/0 và sau khi đổi là
  2/6/1, nên ô thời gian của ca không bao giờ trùng ô theo `shared.strategy_index`.
- Chỉ đổi biến toàn cục mà đối số tham chiếu tới; sự kiện bán đọc đối số nên thấy được
  việc helper chép settings/shared thay vì dùng tham chiếu. `levels` không bị đổi.
- Script chỉ macro 2 tên theo TASK. Nếu `Bot3ManagementBarGate.mqh` gọi API khác (TASK
  helper cấm), lời gọi đó vào MT5 thật và không có sự kiện; Codex cần xác nhận khi đọc header.
- `GateCfg.finish.mode` ghi bằng `FileWriteInteger` như FlowCheck; tôi không đọc kiểu của
  trường này. Các phép `=1`, `++`, `(ulong)(long)` đều dùng được với kiểu số nguyên.
- Sau `ZeroMemory` không gán thêm trường nào cho Requests/Options (TASK không yêu cầu).

## Codex cần kiểm

1. Ghép `.mq5` vào `bot-cua-toi-3/source/MQL5/Scripts/bot-cua-toi-3/`, `.py` vào
   `bot-cua-toi-3/tests/` (tệp Python không phụ thuộc đường dẫn).
2. Biên dịch với `Bot3ManagementBarGate.mqh` hiện hành, mục tiêu 0 lỗi/0 cảnh báo.
3. Tạo `cases.bin` bằng `encode(cases())`, chạy script trong MT5 thử, so
   `mql5-results.bin` và `script-status.bin` theo thứ tự ca với kết quả gốc lấy độc lập.
