# Bot3TimedRealSell — bản đề xuất r1

**Trạng thái:** mới viết mã theo `TASK.md`. Chưa biên dịch, chưa chạy, chưa so
với EX5 gốc (phiên này không được chạy lệnh).

## Tệp

| Tệp | Nội dung |
|---|---|
| `Bot3TimedRealSell.mqh` | `bool Bot3AdvanceTimedSellStop(...)` đúng chữ ký trong `TASK.md`; include `Bot3ManagementPrelude.mqh` và `Bot3ManagementMessages.mqh`; chặn include `BOT3_TIMED_REAL_SELL_MQH`. |

Chỉ đọc giao diện có sẵn: `Bot3ManagementPrelude.mqh`, `Bot3PositionModify.mqh`,
`Bot3TradeSend.mqh`, `Bot3PendingRequest.mqh`, `Bot3PriceLevels.mqh`,
`Bot3TradeErrors.mqh` (nguồn chính) và
`../bot3-management-messages-20261025-r1/Bot3ManagementMessages.mqh`.
Không đọc EX5, mã máy hay bản phân tích lịch sử.

## Thứ tự đọc/ghi

| Bước | Dòng | Cách giữ |
|---|---|---|
| 1 | 16–21 | Đọc `activation` trước `TimeCurrent()`; gọi `TimeCurrent()` 1 lần → `long now`. Sau đó đọc `delay_seconds` (int32 → long có dấu) rồi `position.opened`. Mốc = `(long)((ulong)opened+(ulong)delay)` (cộng cuộn 64 bit); `now<mốc` (so có dấu) → false. |
| 2 | 22–27 | `quote=tick.ask` trước `SymbolInfoDouble(symbol,SYMBOL_POINT)`; không hỏi digits. Sau POINT mới đọc `distance*unit`; `gate=(position.sl-point)-offset`, không làm tròn; cần `quote<gate`. |
| 3 | 28 | Sau POINT đọc mới `freeze`, `tick.ask`; cần `(freeze+position.tp)<tick.ask`. |
| 4 | 29–31 | DIGITS lần 1; sau đó đọc mới `distance`, `unit`, `tick.ask`: `candidate=Bot3RoundPrice(distance*unit+tick.ask,digits)`; cần `candidate<position.sl` (SL cũ). Chưa gán SL. |
| 5 | 32–36 | DIGITS lần 2; sau đó `quote=tick.ask` (quote2), đọc mới `distance`, `unit`; `candidate=Bot3RoundPrice(distance*unit+quote,digits)` (nhân trước, cộng quote2 sau); gán `position.sl` ngay. |
| 6 | 37 | Đọc `gap` mới; cần `(quote+gap)<candidate` (quote2, candidate2). Sai → false, SL đã gán vẫn giữ. |
| 7–8 | 38–41 | `Bot3ModifyPosition(state,options,ticket,position.sl,position.tp)`; chỉ khi trả false mới gọi `Bot3PrintManagementError(...,error_count)`. Cả hai trường hợp đều trả true. |

- Số lời gọi API: `TimeCurrent` 1, `SymbolInfoDouble(POINT)` 1,
  `SymbolInfoInteger(DIGITS)` 2, `Bot3ModifyPosition` tối đa 1,
  `Bot3PrintManagementError` tối đa 1 (đếm bằng Grep trên tệp).
- Không có `NormalizeDouble`, `SymbolInfoTick`, sửa tp, đóng vị thế, ghi bảng
  hay Stamp/Delay. Mọi lần trả trước Modify đều là false.
- Chuỗi báo lỗi được Grep cùng một mẫu với `TASK.md:17` (có hai dấu cách sau
  `loss.`): khớp cả hai nơi.

## Kiểu số

- `now`, `delay`, `deadline`: `long`; phép cộng đi qua `ulong` rồi ép lại
  `long`; không dùng double, không dùng phép trừ `now-opened`.
- `digits`: `uint` từ `(uint)SymbolInfoInteger(...)`, truyền thẳng vào
  `Bot3RoundPrice(value,digits)`.
- Giá: `double`; chỉ làm tròn ở bước 4 và 5 bằng `Bot3RoundPrice`.
- So sánh số thực viết dạng `!(a<b)`: NaN làm điều kiện sai → trả false.

## Còn thiếu / Codex cần kiểm

| Điểm | Ghi chú |
|---|---|
| `Bot3ManagementMessages.mqh` | Chưa có trong nguồn chính. Bản đề xuất ở `bot3-management-messages-20261025-r1/` có chữ ký khớp `(const string &suffix,uint &error_count)`. Tệp này chỉ biên dịch được sau khi ghép tệp đó vào cùng thư mục include. |
| Chuỗi hằng vào `const string &` | Dự án đã có tiền lệ: `Bot3ManagementVirtualStoreCheck.mq5:75` truyền `"CHECK"` vào `const string &symbol`. Với tệp này chưa xác nhận vì chưa biên dịch. |
| Địa chỉ native | Đặc tả không ghi, nên đầu tệp không ghi địa chỉ; Codex bổ sung khi ghép. |
| Thứ tự `delay_seconds`/`opened` | Mã đọc `delay_seconds` trước. Giữa hai lần đọc không có API nên không đổi kết quả. |
| Vùng nhớ | Theo đặc tả, các tham chiếu không trùng vùng nhớ (vd. `gap` không trùng `position.sl`); mã dựa vào giả định này. |
| Bộ kiểm | Chưa có (không được giao). Nên có ca: sát mốc thời gian; cuộn 64 bit (`opened` gần `LONG_MAX`, delay âm); NaN ở activation/gate/freeze/gap; đổi `tick.ask`/`distance`/`unit`/`freeze`/`gap` trong từng lời gọi API để kiểm vị trí đọc; Modify true/false và nội dung Print. |
| Cấu hình phiên | Mô hình theo thông tin môi trường: `claude-opus-5-5`. Hệ thống báo Ultracode bật, nhưng phiên không có công cụ Workflow và đặc tả cấm tác tử lồng, nên làm trong một phiên. Mức `max` không tự kiểm được từ trong phiên; cần đối chiếu nhật ký riêng. |
