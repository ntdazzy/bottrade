# Bot3RealTakeBuy — tóm tắt

Ngày 25/10/2026. Đây là bản đề xuất: **chưa biên dịch, chưa chạy, chưa so với EX5 gốc**.
Mã viết theo đặc tả trong `TASK.md` (trùng nội dung yêu cầu của người dùng).
Không đọc EX5, mã máy hay bản phân tích cũ.

## Tệp và giao diện

- `Bot3RealTakeBuy.mqh`, guard `BOT3_REAL_TAKE_BUY_MQH`, một hàm `Bot3AdvanceRealTakeBuy`.
- Include đường dẫn tương đối: `Bot3ManagementPrelude.mqh`, `Bot3ManagementMessages.mqh`.
  Thư mục đề xuất này không có hai tệp đó, nên phải chép vào
  `source/MQL5/Include/bot-cua-toi-3/` rồi mới biên dịch.
- Dùng hàm/kiểu có sẵn, không sửa: `Bot3RoundPrice`, `Bot3ModifyPosition`,
  `Bot3PrintManagementError`, `Bot3TryClosePosition`, `Bot3ManagedPosition`,
  `Bot3PendingRequestState`, `Bot3TradeSendOptions` (lấy qua Prelude).
- Chữ ký giữ đúng đặc tả: 17 tham số, cùng thứ tự; chỉ `anchor` và `ticket` truyền theo giá trị.
- Biến `z` trong đặc tả đặt tên là `zero_volume`, giống `Bot3ManagementRealDistance.mqh`.

## Thứ tự lời gọi API trong hàm

1. `SymbolInfoInteger(symbol,SYMBOL_DIGITS)` → `digits1`
2. `SymbolInfoDouble(symbol,SYMBOL_POINT)` → `point`
3. `SymbolInfoInteger(symbol,SYMBOL_DIGITS)` → `digits2` (chỉ khi cổng 2 đạt)
4. `SymbolInfoInteger(symbol,SYMBOL_DIGITS)` → `digits3` (chỉ khi cổng 3 và 4 đạt)
5. `Bot3ModifyPosition(state,options,ticket,position.sl,position.tp)` (chỉ khi cổng 6 đạt)
6. Modify sai: `Bot3PrintManagementError(suffix,error_count)` (bên trong gọi `GetLastError()`).
   Modify đạt: `SymbolInfoDouble(symbol,SYMBOL_VOLUME_MIN)` nếu `zero_volume<position.volume`,
   rồi `Bot3TryClosePosition(...)` nếu `minimum<=zero_volume`.

`Bot3RoundPrice` được gọi 4 lần (gate, boundary, new_tp, zero_volume). Hàm này không gọi
`SymbolInfoTick`, `NormalizeDouble`, không chọn vị thế (ngoài phần có sẵn trong Modify/TryClose).

## Thứ tự đọc/ghi trong mã

| Bước | Thứ tự trong mã (dòng) | Đọc tại đây | Ghi | Sai thì |
|---|---|---|---|---|
| 1 | `!(0.0<distance)` (15) → chụp `quote=tick.ask` (17) → `digits1` (18) → `point` (19) | `distance`; `tick.ask` trước DIGITS1 | biến cục bộ | `false` |
| 2 | `gate=Bot3RoundPrice((position.tp-point)-distance*unit,digits1)` (20); cần `quote<gate` (21) | `position.tp` cũ; `distance`, `unit` sau POINT | — | `false` |
| 3 | chụp `quote2=tick.ask` (22) → `digits2` (23) → `boundary=Bot3RoundPrice(anchor-start*unit,digits2)` (24); cần `quote2<boundary` (25) | `tick.ask` trước DIGITS2; `start`, `unit` sau DIGITS2; `anchor` là giá trị lúc gọi | — | `false` |
| 4 | cần `tick.bid<position.tp-freeze` (27) | `tick.bid`, `freeze` mới; `position.tp` cũ | — | `false` |
| 5 | `digits3` (28) → `new_tp=Bot3RoundPrice(distance*unit+tick.bid,digits3)` (29) | `distance`, `unit`, `tick.bid` sau DIGITS3 | `position.tp=new_tp` ngay (31) | — |
| 6 | cần `tick.ask+gap<new_tp` (32) | `tick.ask`, `gap` sau khi ghi TP; không dùng `quote`/`quote2` | — | `false`, giữ `position.tp=new_tp` |
| Sửa | `Bot3ModifyPosition(state,options,ticket,position.sl,position.tp)` (34) | `ticket`, `position.sl`, `position.tp` (= `new_tp`) | `state` (trong hàm có sẵn) | — |
| Sửa lỗi | `Bot3PrintManagementError(suffix,error_count)` (37) → `changed=true` (38) | `GetLastError()` (trong hàm có sẵn) | `error_count` (trong hàm có sẵn), `changed` | `false` |
| Sửa đạt | `zero_volume=Bot3RoundPrice(volumes[strategy_index]*0.0,2)` (42) → `changed=true` (43) | `strategy_index`, `volumes[...]` sau Modify | `changed` | — |
| | cần `zero_volume<position.volume` (44) | `position.volume` | — | `false` |
| | `minimum=SymbolInfoDouble(symbol,SYMBOL_VOLUME_MIN)` (45); cần `minimum<=zero_volume` (46) | — | — | `false` |
| Đóng | `Bot3TryClosePosition(state,options,deviation,tick.bid,tick.ask,gap,freeze,ticket)` (48) → trả `true` (49) | truyền tham chiếu; không gọi `SymbolInfoTick` | `state` (trong hàm có sẵn) | — |

Chuỗi báo lỗi giữ đúng: `' when setting trailing Exit_TP.  Trying again!` (hai dấu cách sau `Exit_TP.`;
đã dò bằng Grep với mẫu hai dấu cách, khớp dòng 36).

## Kết quả theo nhánh

| Nhánh thoát | Trả về | `changed` | `position.tp` | Lời gọi giao dịch |
|---|---|---|---|---|
| Bước 1–4 sai | `false` | giữ cũ | giữ cũ | không |
| Bước 6 sai | `false` | giữ cũ | `new_tp` | không |
| `Bot3ModifyPosition` trả `false` | `false` | `true` (sau khi in lỗi) | `new_tp` | `Bot3ModifyPosition` |
| Sửa đạt, cổng khối lượng sai | `false` | `true` | `new_tp` | `Bot3ModifyPosition` |
| Tới `Bot3TryClosePosition` | `true` | `true` | `new_tp` | `Bot3ModifyPosition` + `Bot3TryClosePosition` |

`true` chỉ khi tới `Bot3TryClosePosition`; Modify đạt chưa đủ để trả `true`.
Không sửa `position.sl`, `position.open_price`, `position.volume`; không ghi bảng, Stamp;
không dùng `NormalizeDouble`; không thêm kiểm `0<TP` hay luật khác.

## Ghi chú kỹ thuật

- Mọi cổng viết dạng `if(!(a<b)) return false;` hoặc `if(!(a<=b)) return false;`,
  nên NaN làm cổng sai và hàm trả `false` (nếu MQL5 so `<`, `<=` theo IEEE; xem mục kiểm 3).
- Giữ phép `volumes[strategy_index]*0.0`, không thay bằng `0.0`, để Inf/NaN cho tích NaN.
- Giữ ngoặc và thứ tự toán hạng: `(position.tp-point)-distance*unit`, `anchor-start*unit`,
  `distance*unit+tick.bid` (nhân trước, cộng bid sau), `tick.ask+gap`.
- Tham chiếu được đọc ngay tại chỗ dùng, không lưu sẵn trước lời gọi API; chỉ `quote`, `quote2`
  được chụp có chủ ý trước DIGITS1/DIGITS2.
- Chuỗi báo lỗi đặt trong biến `string` cục bộ rồi truyền vào `const string &`, như
  `Bot3ManagementRealDistance.mqh`. Giữa Modify và `GetLastError()` chỉ có phép tạo chuỗi.
- Tiền đề: `strategy_index` trong 0..8 hợp lệ; hàm không tự kiểm chỉ số.
- Đã dò bằng Grep: tệp không có `NormalizeDouble`, `SymbolInfoTick`, `TODO`, `position.sl=`,
  `position.open_price`. Đây là dò chữ, không phải biên dịch.

## Cần Codex kiểm

1. Biên dịch sau khi chép vào thư mục include; ghi lỗi và cảnh báo.
2. Trình biên dịch MQL5 có rút gọn `x*0.0` thành hằng không (ảnh hưởng ca Inf/NaN).
3. Phép so `<`, `<=` của MQL5 với NaN có cho `false` không; `Bot3RoundPrice` với NaN phụ thuộc
   phép ép `(long)` trong hàm có sẵn. Cần đo thật.
4. Theo đọc công thức (chưa chạy): `volumes` hữu hạn cho `zero_volume=0.0`; khi
   `SYMBOL_VOLUME_MIN>0` thì không tới `Bot3TryClosePosition`. Muốn phủ nhánh trả `true`
   cần ca có `SYMBOL_VOLUME_MIN<=0.0` và `position.volume>0`; chưa rõ MT5 có cho đặt như vậy không.
5. Theo đọc công thức (chưa chạy): khi `position.tp==0.0`, `gate` âm nên với `ask` dương cổng 2 sai;
   hàm không thêm kiểm TP, đúng đặc tả.
6. So thứ tự lời gọi (DIGITS 3 lần, POINT, sửa SLTP, VOLUME_MIN, đóng) và từng nhánh với EX5 gốc.

## Cấu hình phiên

- Mô hình theo thông tin phiên: Opus 5.5 (`claude-opus-5-5`); phiên báo Ultracode bật.
  Mức `max` không tự kiểm được từ trong phiên.
- Phiên không có công cụ Workflow, và đề bài cấm chạy lệnh/tác tử lồng, nên làm một mình;
  chỉ ghi hai tệp trong thư mục này.
- Đã đọc: `TASK.md`; giao diện trong nguồn chính (`Bot3ManagementPrelude.mqh`,
  `Bot3ManagementMessages.mqh`, `Bot3PositionModify.mqh`, `Bot3PositionClose.mqh`,
  `Bot3PriceLevels.mqh`); mẫu cách viết (`Bot3ManagementRealDistance.mqh`,
  `Bot3ManagementRealTimed.mqh`, `bot3-real-distance-buy-20261025-r1/`); 120 dòng đầu
  `QUY-TRINH.md` theo yêu cầu của `AGENTS.md`.
- Đã tự rà mã với 6 bước đặc tả bằng cách đọc lại; đây không phải phép kiểm bằng máy.
