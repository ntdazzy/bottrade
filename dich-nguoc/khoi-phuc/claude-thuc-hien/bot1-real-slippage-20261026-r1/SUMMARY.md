# Bot1ManagementRealSlippage — tóm tắt

Ngày 26/10/2026. Bản đề xuất: **chưa biên dịch, chưa chạy, chưa so với EX5 gốc**.
Không có số % hoàn thành. Tôi chỉ đọc lại mã, so với `TASK.md` và dò bằng regex;
chưa kiểm bằng máy.

## Đã đọc, không đọc

- `AGENTS.md` (có sẵn trong phiên), `tai-lieu-cu/QUY-TRINH.md`, `TASK.md` này.
- Header nguồn bot 1 để dùng đúng kiểu và cách viết: `Bot1ManagementPrelude.mqh`,
  `Bot1ManagementMessages.mqh`, `Bot1ManagementRealDistance.mqh`,
  `Bot1ManagementRealTimed.mqh`, `Bot1ManagementRealStore.mqh`, `Bot1PositionModify.mqh`,
  `Bot1PriceLevels.mqh`, `Bot1TradeErrors.mqh`. Chỉ tìm dòng `struct`/`#include` trong
  `Bot1PendingRequest.mqh`, `Bot1TradeSend.mqh`, `Bot1PositionClose.mqh`,
  `Bot1VirtualStops.mqh` để kiểm chuỗi include.
- `bot1-real-distance-20261025-r1/SUMMARY.md` để theo cách trình bày.
- Trong `bot-cua-toi-1/bang-chung/kiem-quan-ly-vi-the/b1-real-timed-*`: chỉ xem tên tệp,
  tìm chuỗi `Bot1PrintManagementError("` trong `tested-sources` và tìm chữ
  compile/error/warning trong `r10/mql5-run.json` (không thấy). Không mở kết quả so.
- Không đọc EX5, mã máy, bản phân tích; không mở tệp bot 3 (chỉ thấy tên khi tìm tệp).
  Không chạy lệnh/MT5/Git, không tạo tác tử. Chỉ ghi 2 tệp trong thư mục này.

## Tệp và giao diện

- `Bot1ManagementRealSlippage.mqh`, guard `BOT1_MANAGEMENT_REAL_SLIPPAGE_MQH`, 82 dòng.
- Include tương đối `Bot1ManagementPrelude.mqh` và `Bot1ManagementMessages.mqh`.
  Thư mục này không có hai tệp đó, nên cần chép vào
  `bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/` rồi mới biên dịch.
  `Bot1ManagedPosition`, `Bot1PendingRequestState`, `Bot1TradeSendOptions` đến qua chuỗi
  Prelude → PositionModify → TradeSend → PendingRequest.
- `Bot1AdvanceSlippageRealBuyStop` (dòng 9–43), `Bot1AdvanceSlippageRealSellStop`
  (dòng 45–81): cả hai `void`, 17 tham số đúng tên, kiểu và thứ tự trong TASK.
  Chỉ `passed_flag`, `reference`, `ticket` truyền theo giá trị.
- Dùng hàm có sẵn, không viết lại: `Bot1RoundPrice`, `Bot1ModifyPosition`,
  `Bot1PrintManagementError`.
- Trước khi ghi, đã tìm `Bot1AdvanceSlippageReal|BOT1_MANAGEMENT_REAL_SLIPPAGE` trong
  `dich-nguoc/khoi-phuc/**/*.{mqh,mq5}`: không có tên trùng.
- Dòng 1 ghi "Candidate only…". Khi ghép, sửa dòng này theo bằng chứng kiểm thật.

## Thứ tự trong mã

Cổng đầu giống nhau (mua dòng 16, bán dòng 52):
`enabled!=1 || (passed_flag&1)!=1 || !(0.0<trail)` thì `return`. Lúc này chưa đọc giá,
chưa gọi dịch vụ, không đổi `changed` và SL.

Mua:

| Dòng | Mã | Nếu sai |
|---|---|---|
| 18–20 | `quote=tick.bid` → `digits1` (DIGITS) → `point` (POINT) | |
| 21–22 | `gate=Bot1RoundPrice(trail*unit+(point+position.sl),digits1)`; cần `gate<quote` | thoát |
| 23–26 | `quote2=tick.bid` → `digits2` → `boundary=Bot1RoundPrice(start*unit+reference,digits2)`; cần `boundary<quote2` | thoát |
| 27 | cần `tick.bid<position.tp-freeze` (đọc lại `tick.bid`); không gọi DIGITS | thoát |
| 28–30 | `digits3` → `limit_price=Bot1RoundPrice(limit*unit+position.open_price,digits3)`; cần `position.sl<limit_price` | thoát |
| 31–33 | `digits4` → `quote3=tick.bid` → `new_sl=Bot1RoundPrice(quote3-trail*unit,digits4)` | |
| 35–36 | ghi `position.sl=new_sl`, sau đó cần `new_sl<quote3-gap` | thoát, giữ SL mới |
| 38–42 | Modify; đạt: `Print("Slippage control active")`; lỗi: `Bot1PrintManagementError(...)`; sau đó `changed=true` | |

Bán:

| Dòng | Mã | Nếu sai |
|---|---|---|
| 54–56 | `quote=tick.ask` → `point` (POINT) → `captured_unit=unit`; không gọi DIGITS ở đầu | |
| 57–58 | `gate=(position.sl-point)-trail*captured_unit` (không làm tròn); cần `quote<gate` | thoát |
| 59–61 | `quote2=tick.ask`; `boundary=reference-start*captured_unit`; cần `quote2<boundary` | thoát |
| 62 | cần `(freeze+position.tp)<quote2` | thoát |
| 63–64 | `limit_price=position.open_price-captured_unit*limit`; cần `limit_price<position.sl` | thoát |
| 66–68 | `digits1` → `candidate=Bot1RoundPrice(trail*unit+tick.ask,digits1)` (đọc lại `unit`, `tick.ask`); cần `candidate<position.sl` | thoát |
| 69–71 | `digits2` → `quote3=tick.ask` → `new_sl=Bot1RoundPrice(trail*unit+quote3,digits2)` | |
| 73–74 | ghi `position.sl=new_sl`, sau đó cần `(quote3+gap)<new_sl` | thoát, giữ SL mới |
| 76–80 | Modify; đạt: `Print("Slippage controle active")`; lỗi: cùng helper và hậu tố; sau đó `changed=true` | |

Hậu tố lỗi ở dòng 41 và 79: `' when setting Slip TL.  Trying again!` (hai dấu cách sau
`TL.`). Regex thấy đúng 2 chỗ; `Slippage control active` 1 chỗ (dòng 39),
`Slippage controle active` 1 chỗ (dòng 77).

## Kết quả theo lối ra

| Lối ra | `changed` | `position.sl` | Lời gọi giao dịch | In ra |
|---|---|---|---|---|
| Cổng đầu sai | giữ cũ | giữ cũ | không | không |
| Cổng giá sai, trước khi ghi SL | giữ cũ | giữ cũ | không | không |
| Cổng khoảng trống sai | giữ cũ | SL mới | không | không |
| Modify đạt | `true` | SL mới | Modify | thông báo đạt |
| Modify lỗi | `true` | SL mới | Modify | `TrailStop error: '…' when setting Slip TL.  Trying again!`, `error_count` +1 |

Lời gọi dịch vụ khi đi hết đường (đọc từ mã, chưa chạy): mua DIGITS, POINT, DIGITS,
DIGITS, DIGITS, Modify; bán POINT, DIGITS, DIGITS, Modify. Sau đó là `Print`, hoặc helper
lỗi (helper đọc `GetLastError()` một lần).

Số lần làm tròn: mua 4 (dòng 21, 25, 29, 33), bán 2 (dòng 67, 71). Gate, boundary và
limit của bán không làm tròn.

Regex trong tệp không thấy: `NormalizeDouble`, `SymbolInfoTick`, `VOLUME`, `TryClose`,
`position.tp=`, `TODO`, `DBL_EPSILON`, `MathAbs`, `<=`, `>=`, `>`. Tức là không đóng
lệnh, không hỏi khối lượng, không làm mới tick, không ghi TP, không dùng epsilon; mọi phép
so giá là `<`. Không thêm xử lý lỗi cấp phát.

## Khác cách viết, không đổi logic

- Hậu tố lỗi được truyền thẳng chuỗi hằng vào `const string &suffix`, giống bản bán của
  `Bot1ManagementRealTimed.mqh` (dòng 66–67). `Bot1ManagementRealDistance.mqh` dùng biến
  `string suffix` cục bộ; đây vẫn là cùng một lời gọi. Giữa `Bot1ModifyPosition` và
  `GetLastError()` trong helper không có lời gọi API.
  Suy ra, chưa tự kiểm: `tested-sources` của `b1-real-timed-20261025-r1…r10` có dạng này
  và r10 có `mql5-results.bin`, nên trình biên dịch đã nhận dạng này. Nếu bị từ chối thì
  đổi sang biến cục bộ, logic không đổi.
- Dùng `if/else` trên kết quả `Bot1ModifyPosition` thay cho biến `ok`.
- Bán dùng tên riêng `quote2`, `quote3`, `new_sl` như TASK, không dùng lại
  `quote`/`candidate`.

## Cần Codex kiểm

1. Chép vào thư mục include rồi biên dịch; ghi lại lỗi và cảnh báo.
2. Kiểm trình biên dịch có đọc lại tham chiếu `const double &` (`unit`, `trail`, `start`,
   `limit`, `gap`, `freeze`), `position` và `tick` sau mỗi lời gọi `SymbolInfo*` không,
   hay giữ giá trị cũ. Chỉ thấy được khi hàm giả đổi biến. Bán: dòng 57, 60, 63 phải dùng
   `captured_unit`; dòng 67, 71 phải đọc `unit` mới.
3. `Bot1RoundPrice(NaN/Inf,…)` phụ thuộc phép ép `(long)` của MQL5 trong hàm có sẵn; cần đo.
4. So từng nhánh, thứ tự lời gọi, giá trị ghi, chuỗi in và `error_count` với EX5 gốc
   trong MT5 thử riêng.

## Ca nên có (đề xuất, chưa chạy)

- Cổng đầu: `enabled` 0/1/2/−1; `passed_flag` 0, 1, 2, 3, 0xFE, 0xFF (chỉ bit 0 có tác
  dụng); `trail` NaN, −0.0, +0.0, số âm, số dương nhỏ nhất.
- Hai vế bằng nhau ở mỗi cổng `<` thì phải thoát; NaN ở từng toán hạng cũng phải thoát.
- `changed` đầu vào là `true` và `false`, kiểm ở mọi lối ra.
- Hàm giả đổi biến trong từng lời gọi. Mua: `quote` chụp trước DIGITS1, `quote2` trước
  DIGITS2, `tick.bid` dòng 27 đọc sau DIGITS2, `quote3` sau DIGITS4. Bán: `quote` trước
  POINT, `captured_unit` sau POINT, `unit` và `tick.ask` dòng 67 sau DIGITS1, `quote3` sau
  DIGITS2. `reference` là bản sao.
- Cổng khoảng trống sai: SL mới đã ghi, `changed` giữ cũ, không Modify, không in.
- Modify đạt và lỗi: đúng chuỗi in; `error_count` chỉ tăng khi lỗi; `changed=true` ở cả
  hai; `position.tp` không đổi.

## Cấu hình phiên

- Theo thông tin phiên, mô hình là Opus 5.5 (`claude-opus-5-5`). Tôi không tự kiểm được
  mức `max` từ trong phiên.
- Phiên báo Ultracode đang bật, nhưng không có công cụ Workflow và TASK cấm tạo tác tử,
  nên tôi làm trực tiếp trong một phiên.
