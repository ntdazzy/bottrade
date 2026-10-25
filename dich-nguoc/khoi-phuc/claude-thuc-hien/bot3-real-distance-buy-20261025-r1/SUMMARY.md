# Bot3DistanceRealBuy — tóm tắt

Ngày 25/10/2026. Đây là bản đề xuất: **chưa biên dịch, chưa chạy, chưa so với EX5 gốc**.
Mã viết theo đặc tả trong `TASK.md`. Không đọc EX5, mã máy hay bản phân tích cũ.

## Tệp và giao diện

- `Bot3DistanceRealBuy.mqh`, guard `BOT3_DISTANCE_REAL_BUY_MQH`, một hàm `Bot3AdvanceDistanceBuyStop`.
- Include đường dẫn tương đối: `Bot3ManagementPrelude.mqh`, `Bot3ManagementMessages.mqh`.
  Thư mục đề xuất này không có hai tệp đó, nên phải chép vào
  `source/MQL5/Include/bot-cua-toi-3/` rồi mới biên dịch.
- Dùng hàm có sẵn, không sửa: `Bot3RoundPrice`, `Bot3ModifyPosition`,
  `Bot3PrintManagementError`, `Bot3TryClosePosition`.
- Chữ ký giữ đúng đặc tả (19 tham số, cùng thứ tự; chỉ `anchor` và `ticket` truyền theo giá trị).

## Thứ tự đọc/ghi trong mã

| Bước | Thứ tự trong mã | Đọc tại đây | Ghi | Sai thì |
|---|---|---|---|---|
| 1 | `!(0.0<trail)` → chụp `quote=tick.bid` → `digits1=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS)` → `point=SymbolInfoDouble(symbol,SYMBOL_POINT)` | `trail`; `tick.bid` trước DIGITS | biến cục bộ | `false` |
| 2 | `gate=Bot3RoundPrice((trail+step)*unit+(point+position.sl),digits1)`; cần `gate<quote` | `trail`, `step`, `unit`, `position.sl` sau POINT | — | `false` |
| 3 | chụp `quote2=tick.bid` → `digits2` → `boundary=Bot3RoundPrice(start*unit+anchor,digits2)`; cần `boundary<quote2` | `tick.bid` trước DIGITS; `start`, `unit` sau DIGITS; `anchor` là giá trị lúc gọi | — | `false` |
| 4 | cần `tick.bid<position.tp-freeze` | `tick.bid`, `freeze`, `position.tp` | — | `false` |
| 5 | `digits3` → `cap=Bot3RoundPrice(limit*unit+position.open_price,digits3)`; cần `position.sl<cap` | `limit`, `unit` sau DIGITS; `position.sl` cũ | — | `false` |
| 6 | `digits4` → chụp `quote3=tick.bid` → `new_sl=Bot3RoundPrice(quote3-trail*unit,digits4)` | `tick.bid`, `trail`, `unit` sau DIGITS | `position.sl=new_sl` ngay | — |
| 7 | cần `new_sl<quote3-gap` | `gap` sau khi ghi SL | — | `false`, giữ `position.sl=new_sl` |
| Sửa | `ok=Bot3ModifyPosition(state,options,ticket,position.sl,position.tp)` | `position.sl`, `position.tp` | `state` (trong hàm có sẵn) | — |
| Sửa lỗi | `Bot3PrintManagementError(suffix,error_count)` → `changed=true` | `GetLastError()` (trong hàm có sẵn) | `error_count`, `changed` | `false` |
| Sửa đạt | `zero_volume=Bot3RoundPrice(volumes[strategy_index]*0.0,2)` → `changed=true` | `strategy_index`, `volumes[...]` sau Modify | `changed` | — |
| | cần `zero_volume<position.volume` | `position.volume` | — | `false` |
| | `minimum=SymbolInfoDouble(symbol,SYMBOL_VOLUME_MIN)`; cần `minimum<=zero_volume` | — | — | `false` |
| Đóng | `Bot3TryClosePosition(state,options,deviation,tick.bid,tick.ask,gap,freeze,ticket)` → trả `true` | truyền tham chiếu; không gọi `SymbolInfoTick` | `state` (trong hàm có sẵn) | — |

Chuỗi báo lỗi giữ đúng: `' when setting trailing Exit_stop_ loss.  Trying again!` (hai dấu cách sau `loss.`).

## Kết quả theo nhánh

| Nhánh thoát | Trả về | `changed` | `position.sl` | Lời gọi giao dịch |
|---|---|---|---|---|
| Bước 1–5 sai | `false` | giữ cũ | giữ cũ | không |
| Bước 7 sai | `false` | giữ cũ | `new_sl` | không |
| `Bot3ModifyPosition` trả `false` | `false` | `true` (sau khi in lỗi) | `new_sl` | `Bot3ModifyPosition` |
| Sửa đạt, cổng khối lượng sai | `false` | `true` | `new_sl` | `Bot3ModifyPosition` |
| Tới `Bot3TryClosePosition` | `true` | `true` | `new_sl` | `Bot3ModifyPosition` + `Bot3TryClosePosition` |

Không sửa `position.tp`, `position.open_price`, `position.volume`; không ghi bảng, Stamp;
không dùng `NormalizeDouble`; không thêm luật.

## Ghi chú kỹ thuật

- Mọi cổng viết dạng `if(!(a<b)) return false;` hoặc `if(!(a<=b)) return false;`,
  nên NaN làm cổng sai và hàm trả `false`.
- Giữ phép `volumes[strategy_index]*0.0`, không thay bằng `0.0`, để Inf/NaN cho tích NaN.
- Giữ nguyên ngoặc và thứ tự toán hạng của từng công thức.
- Chuỗi báo lỗi đặt trong biến `string` cục bộ rồi truyền vào `const string &`.
  Giữa `Bot3ModifyPosition` và `GetLastError()` chỉ có phép tạo chuỗi, không có lời gọi API.
- Tiền đề: `strategy_index` trong 0..8 hợp lệ; hàm không tự kiểm chỉ số.

## Cần Codex kiểm

1. Biên dịch sau khi chép vào thư mục include; ghi lỗi và cảnh báo.
2. Trình biên dịch MQL5 có rút gọn `x*0.0` thành hằng không (ảnh hưởng ca Inf/NaN).
3. `Bot3RoundPrice` với đầu vào NaN cho kết quả theo phép ép `(long)` của MQL5 trong hàm có sẵn; cần đo thật.
4. Theo công thức đặc tả (chưa kiểm): với `volumes` hữu hạn thì `zero_volume=0.0`;
   khi `SYMBOL_VOLUME_MIN>0` thì không tới `Bot3TryClosePosition`. Muốn phủ nhánh trả `true`
   cần ca có `SYMBOL_VOLUME_MIN<=0.0` và `position.volume>0`; chưa rõ MT5 có cho đặt như vậy không.
5. So thứ tự lời gọi (DIGITS 4 lần, POINT, VOLUME_MIN, sửa SLTP, đóng) và từng nhánh với EX5 gốc.

## Cấu hình phiên

- Mô hình theo thông tin phiên: Opus 5.5 (`claude-opus-5-5`); phiên báo Ultracode bật.
  Mức `max` không tự kiểm được từ trong phiên.
- Không chạy lệnh, không dùng tác tử lồng; chỉ ghi hai tệp trong thư mục này.
- Đã tự rà mã với 7 bước đặc tả bằng cách đọc lại; đây không phải phép kiểm bằng máy.
