# Bot1ManagementRealDistance — tóm tắt

Ngày 26/10/2026. Bản đề xuất: **chưa biên dịch, chưa chạy, chưa so với EX5 gốc**.
Không có số % hoàn thành. Tôi chỉ đọc lại mã và so với `TASK.md`, chưa kiểm bằng máy.

## Đã đọc, không đọc

- `AGENTS.md`, `tai-lieu-cu/QUY-TRINH.md`, `TASK.md` này.
- Header nguồn bot 1 để dùng đúng giao diện: `Bot1ManagementPrelude.mqh`,
  `Bot1ManagementMessages.mqh`, `Bot1PriceLevels.mqh`, `Bot1PositionModify.mqh`,
  `Bot1PositionClose.mqh`, phần đầu `Bot1TradeSend.mqh` và `Bot1PendingRequest.mqh`
  (để kiểm chuỗi include), `Bot1ManagementRealTimed.mqh` (để theo cách viết).
- Để theo cách viết và cách trình bày đã ghép: header nguồn bot 3
  `Bot3ManagementRealDistance.mqh` và hai `SUMMARY.md` cũ
  (`bot1-management-timed-…`, `bot3-real-distance-buy-…`). Không thấy khác logic
  với `TASK.md`. Mã bot 1 được viết theo `TASK.md`.
- Không đọc EX5, mã máy hoặc bản phân tích. Không chạy lệnh/MT5/Git, không tạo tác tử.
  Chỉ ghi 2 tệp trong thư mục này.

## Tệp và giao diện

- `Bot1ManagementRealDistance.mqh`, guard `BOT1_MANAGEMENT_REAL_DISTANCE_MQH`.
- Include tương đối `Bot1ManagementPrelude.mqh` và `Bot1ManagementMessages.mqh`.
  Thư mục này không có hai tệp đó, nên cần chép vào
  `bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/` rồi mới biên dịch.
- `Bot1AdvanceDistanceBuyStop` (dòng 9–56), `Bot1AdvanceDistanceSellStop`
  (dòng 58–107): cả hai trả `bool`, có 19 tham số đúng tên, kiểu và thứ tự trong TASK.
  Chỉ `anchor` và `ticket` được truyền theo giá trị.
- Dùng hàm có sẵn, không viết lại: `Bot1RoundPrice`, `Bot1ModifyPosition`,
  `Bot1PrintManagementError`, `Bot1TryClosePosition`.
- Đã tìm trong `dich-nguoc/khoi-phuc/**/*.mqh,*.mq5`: chưa có hàm hoặc guard trùng tên.
- Dòng 1 ghi "Candidate only…". Khi ghép, sửa dòng này theo bằng chứng kiểm thật.

## Thứ tự trong mã

Mua:

| Dòng | Mã | Nếu sai |
|---|---|---|
| 17 | `!(0.0<trail)` | `false` |
| 19–21 | `quote=tick.bid` → `digits1` (DIGITS) → `point` (POINT) | |
| 22–23 | `gate=Bot1RoundPrice((trail+step)*unit+(point+position.sl),digits1)`; cần `gate<quote` | `false` |
| 24–27 | `quote2=tick.bid` → `digits2` → `boundary=Bot1RoundPrice(start*unit+anchor,digits2)`; cần `boundary<quote2` | `false` |
| 28 | cần `tick.bid<position.tp-freeze`; không gọi DIGITS | `false` |
| 29–31 | `digits3` → `cap=Bot1RoundPrice(limit*unit+position.open_price,digits3)`; cần `position.sl<cap` | `false` |
| 32–34 | `digits4` → `quote3=tick.bid` → `new_sl=Bot1RoundPrice(quote3-trail*unit,digits4)` | |
| 36–37 | ghi `position.sl=new_sl`, sau đó cần `new_sl<quote3-gap` | `false`, giữ SL mới |
| 39–55 | phần chung | |

Bán:

| Dòng | Mã | Nếu sai |
|---|---|---|
| 66 | `!(0.0<trail)` | `false` |
| 68–70 | `quote=tick.ask` → `point` (POINT) → `captured_unit=unit`; không gọi DIGITS ở đầu | |
| 71–72 | `gate=(position.sl-point)-(trail+step)*captured_unit`; cần `quote<gate` | `false` |
| 73–75 | `quote=tick.ask`; `boundary=anchor-start*captured_unit`; cần `quote<boundary` | `false` |
| 76 | cần `(freeze+position.tp)<quote` | `false` |
| 77–78 | `cap=position.open_price-captured_unit*limit`; cần `cap<position.sl` | `false` |
| 80–82 | `digits1` → `candidate=Bot1RoundPrice(trail*unit+tick.ask,digits1)` (đọc lại `unit`); cần `candidate<position.sl` | `false` |
| 83–85 | `digits2` → `quote=tick.ask` → `candidate=Bot1RoundPrice(trail*unit+quote,digits2)` | |
| 87–88 | ghi `position.sl=candidate`, sau đó cần `(quote+gap)<candidate` | `false`, giữ SL mới |
| 90–106 | phần chung | |

Phần chung (mua dòng 39–55, bán dòng 90–106):

| Bước | Mã | Ghi chú |
|---|---|---|
| 1 | `ok=Bot1ModifyPosition(state,options,ticket,position.sl,position.tp)` | |
| 2 | `!ok`: `Bot1PrintManagementError(suffix,error_count)` → `changed=true` → `false` | không đọc `volumes`, không hỏi VOLUME_MIN, không đóng |
| 3 | `zero_volume=Bot1RoundPrice(volumes[strategy_index]*0.0,2)` → `changed=true` | giữ phép nhân thật |
| 4 | cần `zero_volume<position.volume` | sai thì `false` |
| 5 | `minimum=SymbolInfoDouble(symbol,SYMBOL_VOLUME_MIN)`; cần `minimum<=zero_volume` | sai thì `false` |
| 6 | `Bot1TryClosePosition(state,options,deviation,tick.bid,tick.ask,gap,freeze,ticket)` → `true` | không gọi `SymbolInfoTick`, không dùng kết quả đóng |

Chuỗi lỗi giữ đúng: `' when setting trailing Exit_stop_ loss.  Trying again!`
(có hai dấu cách sau `loss.`). Đã tìm bằng regex và thấy đúng 2 chỗ.

## Kết quả theo lối ra

| Lối ra | Trả về | `changed` | `position.sl` | Lời gọi giao dịch |
|---|---|---|---|---|
| Thoát trước khi ghi SL | `false` | giữ cũ | giữ cũ | không |
| Kiểm khoảng trống sai | `false` | giữ cũ | SL mới | không |
| Sửa lỗi | `false` | `true` | SL mới | Modify |
| Sửa đạt, cổng khối lượng sai | `false` | `true` | SL mới | Modify |
| Tới lời gọi đóng | `true` | `true` | SL mới | Modify, TryClose |

Không ghi `position.tp`, `open_price`, `volume`. Không dùng `NormalizeDouble` hoặc
epsilon, không kiểm thêm, không khôi phục SL. Mọi cổng viết dạng `!(a<b)` hoặc
`!(a<=b)`, nên NaN làm cổng sai và hàm thoát.

Lời gọi dịch vụ khi đi hết đường (đọc từ mã, chưa chạy): mua DIGITS, POINT, DIGITS,
DIGITS, DIGITS, Modify, VOLUME_MIN, TryClose; bán POINT, DIGITS, DIGITS, Modify,
VOLUME_MIN, TryClose.

## Khác cách viết, không đổi logic

- Chuỗi lỗi được gán vào biến `string suffix` cục bộ, rồi truyền vào `const string &`,
  giống `Bot3ManagementRealDistance.mqh` và bản mua của `Bot1ManagementRealTimed.mqh`.
  Đây vẫn là cùng một lời gọi. Giữa `Bot1ModifyPosition` và `GetLastError()` trong
  hàm in lỗi không có lời gọi API.
- Bán dùng lại biến `candidate` cho lần làm tròn thứ hai, đúng như TASK ghi.

## Cần Codex kiểm

1. Biên dịch sau khi chép vào thư mục include; ghi lại lỗi và cảnh báo.
2. Kiểm xem trình biên dịch MQL5 có gộp `x*0.0` thành hằng không, và có giữ giá trị
   cũ của tham chiếu `const` (`unit`, `trail`, `gap`…) sau lời gọi `SymbolInfo*` không.
   Hai điểm này chỉ thấy được ở ca Inf/NaN hoặc khi bộ kiểm đổi biến trong hàm giả.
3. `Bot1RoundPrice(NaN,…)` phụ thuộc phép ép `(long)` của MQL5 trong hàm có sẵn; cần đo.
4. Suy từ công thức và `Bot1RoundPrice`, chưa chạy: nếu `volumes` hữu hạn thì
   `zero_volume=0.0`; khi `SYMBOL_VOLUME_MIN>0`, hàm không tới lời gọi đóng.
   Muốn phủ nhánh trả `true`, cần ca có `SYMBOL_VOLUME_MIN<=0.0` và `position.volume>0`.
5. So từng nhánh, thứ tự lời gọi và giá trị ghi với EX5 gốc trong MT5 thử riêng.

## Ca nên có (đề xuất, chưa chạy)

- `trail`: NaN, −0.0, +0.0, số âm, số dương nhỏ nhất.
- Hai vế bằng nhau ở từng cổng `<`/`<=` thì phải thoát; thử NaN ở từng toán hạng.
- `changed` đầu vào là `true` và `false`, kiểm ở mọi lối ra.
- Hàm giả đổi biến trong từng lời gọi. Mua: `quote` chụp trước DIGITS1, `quote2` trước
  DIGITS2, `quote3` sau DIGITS4. Bán: `quote` đầu chụp trước POINT, `captured_unit` sau
  POINT, `quote` cuối sau DIGITS2. `anchor` là bản sao. `volumes`/`strategy_index`
  được đọc sau Modify.
- Modify lỗi: `error_count` tăng, `volumes` không bị đọc. Thử thêm `volumes` Inf/NaN.

## Cấu hình phiên

- Theo thông tin phiên, mô hình là Opus 5.5 (`claude-opus-5-5`). Tôi không tự kiểm
  được mức `max` từ trong phiên.
- Phiên báo Ultracode đang bật, nhưng không có công cụ Workflow và TASK cấm tạo
  tác tử, nên tôi làm trực tiếp trong một phiên.
