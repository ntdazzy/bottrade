# Bot3ManagementRealStart.mqh — tóm tắt

Trạng thái: đã viết theo mô tả trong `TASK.md`. **Chưa biên dịch, chưa chạy, chưa kiểm.**
Codex kiểm, ghép và chạy.

## Đã đọc
- `TASK.md` trong thư mục này (trùng với yêu cầu của người dùng).
- Hai header để lấy đúng giao diện, trong
  `dich-nguoc/khoi-phuc/bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/`:
  `Bot3ManagementPrelude.mqh` và `Bot3VirtualStops.mqh`.
- Không đọc EX5, mã máy, bằng chứng, lịch sử Git hay tệp đề xuất khác.
  Không sửa nguồn chính, Git, lệnh giao dịch hay việc của tác tử khác.

## Tệp
- `Bot3ManagementRealStart.mqh`: guard `BOT3_MANAGEMENT_REAL_START_MQH`;
  `#include "Bot3ManagementPrelude.mqh"` rồi `#include "Bot3VirtualStops.mqh"`
  (đường dẫn tương đối như các header hiện có, nên khi ghép cần đặt cùng thư mục
  `Include/bot-cua-toi-3`). Chỉ có hai hàm dưới đây; chữ ký và thứ tự tham số giữ
  nguyên như mô tả.

## 1. `Bot3CloseRealStopHit` — thứ tự và hiệu ứng
1. `Print("Closing with virtual SL")`.
2. Lúc này mới đọc `current_stop` (tham chiếu): `Print("Virtual_SL: "+(string)current_stop)`.
3. Lúc này mới đọc giá: BUY `tick.bid`, SELL `tick.ask`;
   `Print("Last Bid: "+(string)(buy ? tick.bid : tick.ask))`. SELL vẫn giữ nhãn `Last Bid`.
4. `SymbolInfoTick(symbol,tick)`, bỏ qua kết quả; hàm này có thể ghi mới `tick`.
5. `Bot3TryClosePosition(state,options,deviation,tick.bid,tick.ask,gap,freeze,(ulong)ticket)`:
   bid/ask đọc sau bước 4; bỏ qua kết quả.
6. Trả `true`.
- Số chuyển sang chuỗi bằng `(string)double`; không dùng `DoubleToString`/`NormalizeDouble`,
  không thêm digits, không đổi nhãn.
- Hàm chỉ tự ghi `tick` (qua `SymbolInfoTick`). Mọi thay đổi khác của `state`/`options`/
  vị thế là do helper con. Không đọc lại vị thế/khối lượng, không ghi P/SL/cờ/bảng.

## 2. `Bot3StartRealManagement` — thứ tự và hiệu ứng
1. `level=Bot3VirtualStopLevel(table,open_tickets,symbol,unit,buy ? 1 : 2,position.open_price,stop_distance,ticket)`.
   Việc ghi `table`/`open_tickets` hoặc in "table full" (nếu có) là do helper này.
2. `current_stop=level` ngay.
3. SELL: `initial_stop=level` trước khi kiểm hit.
4. Kiểm hit bằng `<` nghiêm ngặt, đọc `tick` sau bước 1: BUY `tick.bid<level`;
   SELL `level<tick.ask`. Bằng nhau thì không hit. NaN ở level hoặc giá thì không hit,
   vì phép `<` có thứ tự trả false.
5. Hit: `return Bot3CloseRealStopHit(buy,symbol,current_stop,tick,state,options,deviation,gap,freeze,ticket)`,
   tức trả `true`. BUY không gán `initial_stop` (giữ giá trị cũ); SELL đã gán ở bước 3.
6. Không hit: BUY gán `initial_stop=level`; trả `false`.
- Hàm này không gọi Digits, TakeLevel, Delay, Stamp, Modify, `PositionsTotal`,
  `PositionGetDouble`.

| Nhánh | `current_stop` | `initial_stop` | Print | Gọi đóng lệnh | Trả |
|---|---|---|---|---|---|
| BUY hit | level | giữ nguyên | 3 dòng, giá bid | có | true |
| BUY không hit | level | level | không | không | false |
| SELL hit | level | level (trước khi kiểm) | 3 dòng, giá ask, nhãn `Last Bid` | có | true |
| SELL không hit | level | level | không | không | false |

## Phụ thuộc chưa tự kiểm
- Chữ ký `Bot3TryClosePosition` và kiểu `Bot3PendingRequestState`/`Bot3TradeSendOptions`
  nằm trong các header được prelude include (`Bot3PositionClose.mqh`...). Tôi không mở các
  tệp đó. Lời gọi dùng cùng loại đối số như `Bot3ManagementPrelude.mqh` dòng 98–99:
  `state,options,deviation,tick.bid,tick.ask,<const double&>,<const double&>,(ulong)...`.
- `SymbolInfoTick` cố ý bỏ qua kết quả theo mô tả; nếu trình biên dịch cảnh báo thì không
  cần sửa.
- Hành vi NaN dựa vào phép `<` có thứ tự của MQL5; chưa chạy để xác nhận.

## Ca nên kiểm (Codex)
- BUY/SELL × hit / không hit / bằng nhau / level NaN / giá NaN.
- Đúng thứ tự và nội dung 3 dòng Print; SELL in ask với nhãn `Last Bid`.
- `initial_stop`: BUY giữ nguyên khi hit; SELL được gán trước khi kiểm.
- `Bot3TryClosePosition` nhận bid/ask sau `SymbolInfoTick` và ticket ép `(ulong)`.

## Cấu hình phiên
- Môi trường báo mô hình `claude-opus-5-5` (Opus 5.5) và Ultracode đang bật. Tôi không tự
  xác minh được mức `max` từ trong phiên. Phiên không có công cụ Workflow, nên tôi làm một
  mình, không chia việc cho tác tử phụ.
