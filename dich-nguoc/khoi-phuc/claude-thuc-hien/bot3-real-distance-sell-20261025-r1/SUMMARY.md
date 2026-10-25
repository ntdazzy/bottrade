# SUMMARY: bot3-real-distance-sell-20261025-r1

## Tệp đã ghi

- `Bot3DistanceRealSell.mqh`: hàm `Bot3AdvanceDistanceSellStop`, viết đúng chữ ký trong `TASK.md`.
  Include `Bot3ManagementPrelude.mqh` và `Bot3ManagementMessages.mqh`.
- `SUMMARY.md`: tệp này.

Không sửa nguồn chính, Git hay tệp khác. Không chạy lệnh, không dùng tác tử lồng.

## Trạng thái

- **Chưa biên dịch, chưa chạy, chưa so với EX5 gốc.** Codex cần kiểm.
- Hai lệnh include chỉ phân giải khi tệp nằm cạnh các tệp đó, tức trong
  `bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/`.
- Không đọc EX5, mã máy, bằng chứng hay bản phân tích. Các tệp đã đọc, đều trong thư mục include trên:
  - Đặc tả: `TASK.md`.
  - Giao diện: `Bot3ManagementPrelude.mqh` (`Bot3ManagedPosition`), `Bot3ManagementMessages.mqh`,
    `Bot3PriceLevels.mqh` (`Bot3RoundPrice`), `Bot3PositionModify.mqh`, `Bot3PositionClose.mqh`.
    Phần định nghĩa struct và dòng include trong `Bot3PendingRequest.mqh`, `Bot3TradeSend.mqh`.
  - Cách viết: `Bot3ManagementRealTimed.mqh`.
  - Kiểm trùng tên: không tệp `.mqh` nào trong `dich-nguoc/khoi-phuc` có `Bot3AdvanceDistanceSellStop`
    hoặc `BOT3_DISTANCE_REAL_SELL_MQH`.

## Thứ tự đọc/ghi

Tên trong đặc tả → tên trong mã: `u` → `captured_unit`; `quote2`, `quote3` → `quote` (đọc lại);
`digits1`, `digits2` → `digits` (hỏi lại); `newSL` → `candidate` (tính lại).

| # | Mã | Đọc | Ghi | Không đạt |
|---|---|---|---|---|
| 1 | `if(!(0.0<trail))` | `trail` | – | `return false` |
| 2 | `quote=tick.ask` | `tick.ask` lần 1 | `quote` | – |
| 3 | API `SymbolInfoDouble(symbol,SYMBOL_POINT)` | `symbol` | `point` | – |
| 4 | `captured_unit=unit` | `unit` lần 1 | `captured_unit` | – |
| 5 | `gate=(position.sl-point)-(trail+step)*captured_unit`; cần `quote<gate` | `position.sl` cũ, `trail`, `step` | `gate` | `return false` |
| 6 | `quote=tick.ask` (`quote2`) | `tick.ask` lần 2 | `quote` | – |
| 7 | `boundary=anchor-start*captured_unit`; cần `quote<boundary` | `anchor` (tham trị), `start` | `boundary` | `return false` |
| 8 | cần `(freeze+position.tp)<quote` | `freeze`, `position.tp` | – | `return false` |
| 9 | `cap=position.open_price-captured_unit*limit`; cần `cap<position.sl` | `position.open_price`, `limit`, `position.sl` cũ | `cap` | `return false` |
| 10 | API `SymbolInfoInteger(symbol,SYMBOL_DIGITS)` (DIGITS1) | `symbol` | `digits` | – |
| 11 | `candidate=Bot3RoundPrice(trail*unit+tick.ask,digits)`; cần `candidate<position.sl` | `trail`, `unit` lần 2, `tick.ask` lần 3, `position.sl` cũ | `candidate` | `return false` |
| 12 | API `SymbolInfoInteger(symbol,SYMBOL_DIGITS)` (DIGITS2) | `symbol` | `digits` | – |
| 13 | `quote=tick.ask` (`quote3`) | `tick.ask` lần 4 | `quote` | – |
| 14 | `candidate=Bot3RoundPrice(trail*unit+quote,digits)` (`newSL`) | `trail`, `unit` lần 3 | `candidate` | – |
| 15 | `position.sl=candidate` | – | `position.sl` | – |
| 16 | cần `(quote+gap)<candidate` | `gap` | – | `return false`, giữ SL mới |
| 17 | `Bot3ModifyPosition(state,options,ticket,position.sl,position.tp)` | `ticket`, `position.sl`, `position.tp` | `state` (hàm được gọi ghi) | lỗi → 18; đạt → 19 |
| 18 | `Bot3PrintManagementError(suffix,error_count)` rồi `changed=true` | `suffix` | `error_count` (hàm được gọi ghi), `changed` | `return false` |
| 19 | `zero_volume=Bot3RoundPrice(volumes[strategy_index]*0.0,2)` rồi `changed=true` | `strategy_index`, `volumes[strategy_index]` | `zero_volume`, `changed` | – |
| 20 | cần `zero_volume<position.volume` | `position.volume` | – | `return false` |
| 21 | API `SymbolInfoDouble(symbol,SYMBOL_VOLUME_MIN)` | `symbol` | `minimum` | – |
| 22 | cần `minimum<=zero_volume` | – | – | `return false` |
| 23 | `Bot3TryClosePosition(state,options,deviation,tick.bid,tick.ask,gap,freeze,ticket)` | truyền tham chiếu `deviation`, `tick.bid`, `tick.ask`, `gap`, `freeze`; không làm mới tick | `state` (hàm được gọi ghi) | – |
| 24 | `return true` | – | – | – |

## Kết quả theo nhánh

| Thoát tại | Trả | `changed` | `position.sl` | API đã gọi |
|---|---|---|---|---|
| 1 | `false` | giữ cũ | cũ | không |
| 5, 7, 8, 9 | `false` | giữ cũ | cũ | POINT |
| 11 | `false` | giữ cũ | cũ | POINT, DIGITS1 |
| 16 | `false` | giữ cũ | `newSL` | POINT, DIGITS1, DIGITS2 |
| 18 | `false` | `true` | `newSL` | như 16, thêm Modify (lỗi) và báo lỗi |
| 20 | `false` | `true` | `newSL` | như 16, thêm Modify (đạt) |
| 22 | `false` | `true` | `newSL` | như 20, thêm VOLUME_MIN |
| 24 | `true` | `true` | `newSL` | như 22, thêm TryClose |

- Chỉ trả `true` khi đã tới `Bot3TryClosePosition`. Modify đạt mà chưa tới bước này vẫn trả `false`.
- Mọi cổng viết dạng `if(!(a<b))` hoặc `if(!(a<=b))`, nên NaN làm cổng sai và hàm trả `false`.
- `captured_unit` chỉ dùng ở bước 5, 7, 9. Sau DIGITS (bước 11, 14) mã đọc lại `trail` và `unit`.
- Giữ phép `*0.0`: nếu volume là Inf hoặc NaN thì tích ra NaN, khiến cổng ở bước 20 sai.
- Không dùng `NormalizeDouble`. Không sửa `position.tp`, không ghi bảng hay Stamp, không kiểm chỉ số
  `volumes` (đặc tả coi chỉ số 0..8 hợp lệ là tiền đề) và không thêm luật nào.

## Chỗ viết khác đặc tả (logic giữ nguyên)

- Dùng lại biến `quote`, `digits`, `candidate` như `Bot3AdvanceTimedSellStop` trong `Bot3ManagementRealTimed.mqh`.
- `bool ok=...; if(!ok)` viết gọn thành `if(!Bot3ModifyPosition(...))`.
- Hậu tố lỗi được gán vào biến `string suffix` rồi mới truyền, giống `Bot3AdvanceTimedBuyStop`, để không phụ thuộc
  việc MQL5 có nhận hằng chuỗi cho tham số `const string &` hay không (chưa kiểm). Nội dung chuỗi giữ nguyên
  `' when setting trailing Exit_stop_ loss.  Trying again!`, kể cả hai dấu cách trước `Trying`.

## Codex cần kiểm

- Biên dịch khi ghép vào thư mục include.
- So với EX5 gốc theo bảng đọc/ghi: các lần đọc lại sau API, SL vẫn giữ khi cổng ở bước 16 sai, giá trị
  `changed` và giá trị trả của từng nhánh.
- Mã máy sau biên dịch: phép `*0.0` còn được giữ, và các biểu thức nhân rồi cộng không bị gộp thành FMA.
  Tôi chưa kiểm điểm này.

## Cấu hình phiên

- Mô hình theo môi trường phiên: `claude-opus-5-5`. Thông báo hệ thống ghi Ultracode đang bật.
  Mức `max`: tôi không xem được từ trong phiên, nên chưa xác minh.
- Phiên không có công cụ Workflow, và đề bài cấm tác tử lồng. Tôi làm một mình và không chạy lệnh.
