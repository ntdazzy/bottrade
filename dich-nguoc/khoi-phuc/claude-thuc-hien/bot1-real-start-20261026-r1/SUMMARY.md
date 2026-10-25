# SUMMARY: bot1-real-start-20261026-r1

## Trạng thái

- Đã viết `Bot1ManagementRealStart.mqh` theo `TASK.md` (logic Codex đã chốt).
- **Chưa biên dịch, chưa chạy, chưa so với EX5 gốc.** Không viết bộ kiểm vì không được giao.
- Không đọc EX5, mã máy hoặc bằng chứng phân tích. Không tự tìm thuật toán.
- Không sửa nguồn chính, Git hoặc MT5. Không chạy lệnh. Không tạo tác tử con.
- Chỉ ghi 2 tệp trong thư mục này: `Bot1ManagementRealStart.mqh` và `SUMMARY.md`.

## Header đã đọc (chỉ để đúng kiểu và giao diện)

Thư mục `dich-nguoc/khoi-phuc/bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/`:

- `Bot1ManagementPrelude.mqh`: `Bot1ManagedPosition` (`open_price` kiểu `double`).
- `Bot1VirtualStops.mqh`: `Bot1VirtualStopState` và
  `double Bot1VirtualStopLevel(Bot1VirtualStopState &state,long &open_tickets[],const string &symbol,const double &unit,const int side,const double price,const double distance,const long ticket)`.
- `Bot1PositionClose.mqh`:
  `void Bot1TryClosePosition(Bot1PendingRequestState &state,Bot1TradeSendOptions &options,const ulong &deviation,const double &reference_a,const double &reference_b,const double &threshold_a,const double &threshold_b,const ulong ticket)`.
- `Bot1TradeSend.mqh`, `Bot1PendingRequest.mqh`: `Bot1TradeSendOptions`, `Bot1PendingRequestState`.
- `Bot1ManagementRealDistance.mqh`, `Bot1ManagementRealLock.mqh`, `Bot1ManagementVirtualFinish.mqh`:
  chỉ xem cách đặt guard, include và chú thích.

Đã Grep các tên `Bot1CloseRealStopHit`, `Bot1StartRealManagement`,
`BOT1_MANAGEMENT_REAL_START_MQH` và `Bot1ManagementRealStart` trong `dich-nguoc/khoi-phuc`:
chưa có định nghĩa nào. Kết quả chỉ có `TASK.md` này và các dòng gọi trong
`claude-thuc-hien/bot1-manager-complete-20261026-r1/TASK.md` (dòng 21 và 28).
Thứ tự đối số ở các dòng gọi đó khớp với hai chữ ký bên dưới.

## Giao diện

- Guard `BOT1_MANAGEMENT_REAL_START_MQH`. Include `Bot1ManagementPrelude.mqh` và
  `Bot1VirtualStops.mqh`. Prelude đã include VirtualStops; guard chặn định nghĩa trùng.
- `bool Bot1CloseRealStopHit(const bool buy,const string &symbol,const double &current_stop,MqlTick &tick,Bot1PendingRequestState &state,Bot1TradeSendOptions &options,const ulong &deviation,const double &gap,const double &freeze,const long ticket)`
- `bool Bot1StartRealManagement(const bool buy,const string &symbol,const double &unit,const double &stop_distance,const long ticket,Bot1ManagedPosition &position,MqlTick &tick,Bot1VirtualStopState &table,long &open_tickets[],double &initial_stop,double &current_stop,Bot1PendingRequestState &state,Bot1TradeSendOptions &options,const ulong &deviation,const double &gap,const double &freeze)`

## Đối chiếu đặc tả với mã (`Bot1ManagementRealStart.mqh`)

| Yêu cầu trong TASK.md | Dòng |
|---|---|
| Guard và 2 include | 4-7, 44 |
| Chữ ký hàm 1 | 10-13 |
| `Print("Closing with virtual SL");` | 15 |
| `Print("Virtual_SL: "+(string)current_stop);`: đọc qua tham chiếu ngay tại dòng in | 16 |
| `Print((buy ? "Last Bid: " : "Last Ask: ")+(string)(buy ? tick.bid : tick.ask));`: in tick cũ, đọc ngay tại dòng in | 17 |
| `SymbolInfoTick(symbol,tick);` bỏ qua kết quả | 19 |
| `Bot1TryClosePosition(state,options,deviation,tick.bid,tick.ask,gap,freeze,(ulong)ticket);` | 20 |
| `return true;` | 21 |
| Chữ ký hàm 2 | 24-30 |
| `level=Bot1VirtualStopLevel(table,open_tickets,symbol,unit,buy ? 1 : 2,position.open_price,stop_distance,ticket)` | 32-33 |
| `current_stop=level` sau helper, trước nhánh giá | 34 |
| Bán: `initial_stop=level` ngay trước kiểm giá | 36 |
| Kiểm chạm `buy ? tick.bid<level : level<tick.ask`, so strict, không làm mới giá trước đó | 38 |
| `return Bot1CloseRealStopHit(buy,symbol,current_stop,tick,state,options,deviation,gap,freeze,ticket)` | 39-40 |
| Mua không chạm: `initial_stop=level` rồi `return false` | 41-42 |

Các điểm "không làm" đều không có trong mã: không `DoubleToString`/`StringFormat`, không
chụp trước giá trị để in, không đọc lại vé/khối lượng/TP, không thêm điều kiện hoặc thông báo
lỗi, không gọi kiểm chờ/ghi giờ/sửa vị thế, không có cờ `changed`, không ghi lại `current_stop`
sau khi in/đóng, không kiểm TP/trạng thái lệnh/mode/cấp quyền.

## Kết quả theo nhánh (đọc từ mã, chưa chạy)

| Trường hợp | `current_stop` | `initial_stop` | In 3 dòng, lấy tick, gọi đóng | Trả về |
|---|---|---|---|---|
| Mua, `tick.bid<level` | `level` | không ghi | có | `true` |
| Mua, không chạm (`bid>=level` hoặc NaN) | `level` | `level` | không | `false` |
| Bán, `level<tick.ask` | `level` | `level` (ghi trước kiểm) | có | `true` |
| Bán, không chạm (`level>=ask` hoặc NaN) | `level` | `level` (ghi trước kiểm) | không | `false` |

## Codex cần kiểm

1. Mã gọi thẳng `SymbolInfoTick(symbol,tick)` và bỏ kết quả, không dùng biến tạm và không
   khôi phục tick. Việc "giữ tick cũ khi lấy giá thất bại" phụ thuộc terminal không ghi vào
   `tick` khi gọi lỗi. Tôi chưa kiểm hành vi này.
2. Chuỗi in từ `(string)double` do MT5 định dạng. Cần so log với bản gốc trên cùng dữ liệu.
3. Chưa biên dịch nên chưa biết có cảnh báo hay không, ví dụ cảnh báo bỏ giá trị trả về của
   `SymbolInfoTick`. Prelude hiện hành cũng gọi theo cách này.
4. Nếu bên gọi truyền cùng một biến cho `initial_stop` và `current_stop`, thứ tự ghi vẫn đúng
   đặc tả, và cả hai lần ghi đều là cùng giá trị `level`.
5. Include dùng đường dẫn tương đối. Tệp phải đặt cạnh các header Bot1 trong
   `source/MQL5/Include/bot-cua-toi-1/` mới biên dịch được. Trong thư mục đề xuất này
   không có các header đó.

## Cấu hình phiên

- Môi trường phiên ghi model Opus 5.5 (`claude-opus-5-5`); hệ thống báo "Ultracode is on".
  Trong phiên không có bằng chứng đọc được về mức `max`. Codex cần kiểm cấu hình thực tế.
- Không dùng Workflow hoặc tác tử con, vì TASK cấm tạo tác tử.
