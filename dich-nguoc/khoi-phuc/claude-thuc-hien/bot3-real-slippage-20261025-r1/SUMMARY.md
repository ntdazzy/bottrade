# SUMMARY: bot3-real-slippage-20261025-r1

## Tệp đã ghi

- `Bot3ManagementRealSlippage.mqh`: guard `BOT3_MANAGEMENT_REAL_SLIPPAGE_MQH`, hai hàm
  `void Bot3AdvanceSlippageRealBuyStop` và `void Bot3AdvanceSlippageRealSellStop`, cùng 17 tham số
  đúng thứ tự và kiểu như `TASK.md`. Include `Bot3ManagementPrelude.mqh`, `Bot3ManagementMessages.mqh`.
- `SUMMARY.md`: tệp này.

Không sửa nguồn chính, Git hay tệp nào khác. Không chạy lệnh, không dùng tác tử khác.

## Trạng thái

- **Chưa biên dịch, chưa chạy, chưa so với EX5 gốc.** Codex cần kiểm.
- Include dùng đường dẫn tương đối, nên chỉ chạy được khi chép tệp vào
  `bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/`.
- Tệp đã đọc:
  - Quy tắc: `AGENTS.md`, `tai-lieu-cu/QUY-TRINH.md` (đủ 133 dòng). Đặc tả: `TASK.md`.
  - Giao diện, trong thư mục include nguồn chính: `Bot3ManagementPrelude.mqh` (`Bot3ManagedPosition`),
    `Bot3ManagementMessages.mqh`, `Bot3PriceLevels.mqh` (`Bot3RoundPrice`),
    `Bot3PositionModify.mqh` (`Bot3ModifyPosition`). Phần định nghĩa struct trong
    `Bot3PendingRequest.mqh` và `Bot3TradeSend.mqh` (tìm bằng Grep).
  - Cách viết: `Bot3ManagementRealTake.mqh`, `Bot3ManagementRealDistance.mqh`, `Bot3ManagementRealTimed.mqh`.
    Mẫu tóm tắt: `SUMMARY.md` của `bot3-real-distance-sell-20261025-r1` và `bot3-real-take-buy-20261025-r1`.
- Không đọc EX5, mã máy, bằng chứng chạy hay bản phân tích. Grep/Glob có trả về tên tệp hoặc dòng
  khớp trong `phan-tich/`, `danh-gia-claude/`, `bang-chung/`, nhưng tôi không mở các tệp đó.

## Tên trong đặc tả → tên trong mã

`u` → `captured_unit`; `ask2` → `quote2`; `limitprice` → `limit_price`; `newSL` → `new_sl`.
Các tên khác giữ như đặc tả.

## Thứ tự gọi API (khi mọi cổng trước đó đạt)

- BUY: DIGITS1 → POINT → DIGITS2 → DIGITS3 → DIGITS4 → `Bot3ModifyPosition` → `Print` hoặc
  `Bot3PrintManagementError`. `Bot3RoundPrice` 4 lần: `gate`, `boundary`, `limit_price`, `new_sl`.
- SELL: POINT → DIGITS1 → DIGITS2 → `Bot3ModifyPosition` → `Print` hoặc `Bot3PrintManagementError`.
  `Bot3RoundPrice` 2 lần: `gate2`, `new_sl`. Không gọi DIGITS trước POINT, không làm tròn cổng đầu.
- DIGITS là `(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS)`, POINT là `SymbolInfoDouble(symbol,SYMBOL_POINT)`.

## BUY: thứ tự đọc/ghi (`Bot3AdvanceSlippageRealBuyStop`)

| # | Dòng | Mã | Đọc | Ghi | Sai thì |
|---|---|---|---|---|---|
| 1 | 16 | `enabled!=1 \|\| (passed_flag&1)!=1 \|\| !(0.0<trail)` | `enabled`, `passed_flag`, `trail` | – | `return` |
| 2 | 18 | `quote=tick.bid` | `tick.bid` lần 1, trước DIGITS1 | `quote` | – |
| 3 | 19 | DIGITS1 | `symbol` | `digits1` | – |
| 4 | 20 | POINT | `symbol` | `point` | – |
| 5 | 21–22 | `gate=Bot3RoundPrice(trail*unit+(point+position.sl),digits1)`; cần `gate<quote` | `trail`, `unit` sau POINT; `position.sl` cũ | `gate` | `return` |
| 6 | 23 | `quote2=tick.bid` | `tick.bid` lần 2, trước DIGITS2 | `quote2` | – |
| 7 | 24 | DIGITS2 | `symbol` | `digits2` | – |
| 8 | 25–26 | `boundary=Bot3RoundPrice(start*unit+reference,digits2)`; cần `boundary<quote2` | `start`, `unit` sau DIGITS2; `reference` (tham trị) | `boundary` | `return` |
| 9 | 27 | cần `tick.bid<position.tp-freeze` | `tick.bid` lần 3, `position.tp`, `freeze` | – | `return` |
| 10 | 28 | DIGITS3 | `symbol` | `digits3` | – |
| 11 | 29–30 | `limit_price=Bot3RoundPrice(limit*unit+position.open_price,digits3)`; cần `position.sl<limit_price` | `limit`, `unit` sau DIGITS3; `position.open_price`; `position.sl` cũ | `limit_price` | `return` |
| 12 | 31 | DIGITS4 | `symbol` | `digits4` | – |
| 13 | 32 | `quote3=tick.bid` | `tick.bid` lần 4, sau DIGITS4 | `quote3` | – |
| 14 | 33 | `new_sl=Bot3RoundPrice(quote3-trail*unit,digits4)` | `trail`, `unit` sau DIGITS4 | `new_sl` | – |
| 15 | 35 | `position.sl=new_sl` | – | `position.sl` | – |
| 16 | 36 | cần `new_sl<quote3-gap` | `gap`, đọc sau khi ghi SL | – | `return`, giữ SL mới |
| 17 | 38 | `Bot3ModifyPosition(state,options,ticket,position.sl,position.tp)` | `ticket`, `position.sl` (= `new_sl`), `position.tp` | `state` (hàm có sẵn ghi) | lỗi → 19 |
| 18 | 39 | đạt: `Print("Slippage control active")` | – | – | – |
| 19 | 42–43 | lỗi: `Bot3PrintManagementError(suffix,error_count)` | `GetLastError()` bên trong | `error_count` bên trong | – |
| 20 | 45 | `changed=true`, sau bước 18 hoặc 19 | – | `changed` | – |

## SELL: thứ tự đọc/ghi (`Bot3AdvanceSlippageRealSellStop`)

| # | Dòng | Mã | Đọc | Ghi | Sai thì |
|---|---|---|---|---|---|
| 1 | 56 | như BUY bước 1 | `enabled`, `passed_flag`, `trail` | – | `return` |
| 2 | 58 | `quote=tick.ask` | `tick.ask` lần 1, trước POINT | `quote` | – |
| 3 | 59 | POINT | `symbol` | `point` | – |
| 4 | 61 | `captured_unit=unit` | `unit` lần 1, sau POINT | `captured_unit` | – |
| 5 | 62–63 | `gate=(position.sl-point)-trail*captured_unit`, không làm tròn; cần `quote<gate` | `position.sl` cũ, `trail` | `gate` | `return` |
| 6 | 64 | `quote2=tick.ask` (`ask2`) | `tick.ask` lần 2 | `quote2` | – |
| 7 | 65–66 | `boundary=reference-start*captured_unit`; cần `quote2<boundary` | `reference` (tham trị), `start` | `boundary` | `return` |
| 8 | 67 | cần `(freeze+position.tp)<quote2` | `freeze`, `position.tp`; dùng lại `quote2` | – | `return` |
| 9 | 68–69 | `limit_price=position.open_price-captured_unit*limit`; cần `limit_price<position.sl` | `position.open_price`, `limit`, `position.sl` cũ | `limit_price` | `return` |
| 10 | 70 | DIGITS1 | `symbol` | `digits1` | – |
| 11 | 72–73 | `gate2=Bot3RoundPrice(trail*unit+tick.ask,digits1)`; cần `gate2<position.sl` | `trail`, `unit` lần 2, `tick.ask` lần 3, đều sau DIGITS1; `position.sl` cũ | `gate2` | `return` |
| 12 | 74 | DIGITS2 | `symbol` | `digits2` | – |
| 13 | 75 | `quote3=tick.ask` | `tick.ask` lần 4, sau DIGITS2 | `quote3` | – |
| 14 | 76 | `new_sl=Bot3RoundPrice(trail*unit+quote3,digits2)` | `trail`, `unit` lần 3 | `new_sl` | – |
| 15 | 78 | `position.sl=new_sl` | – | `position.sl` | – |
| 16 | 79 | cần `(quote3+gap)<new_sl` | `gap`, đọc sau khi ghi SL | – | `return`, giữ SL mới |
| 17 | 81 | Modify như BUY | như BUY | `state` (hàm có sẵn ghi) | lỗi → 19 |
| 18 | 82 | đạt: `Print("Slippage controle active")` (giữ chữ `controle`) | – | – | – |
| 19 | 85–86 | lỗi: `Bot3PrintManagementError(suffix,error_count)`, cùng hậu tố với BUY | `GetLastError()` bên trong | `error_count` bên trong | – |
| 20 | 88 | `changed=true`, sau bước 18 hoặc 19 | – | `changed` | – |

`captured_unit` chỉ dùng ở bước 5, 7, 9. Bước 11 và 14 đọc lại `trail` và `unit` sau DIGITS.

## Kết quả theo nhánh

| Hàm | Thoát tại bước | `changed` | `position.sl` | API đã gọi |
|---|---|---|---|---|
| BUY | 1 | giữ cũ | cũ | không |
| BUY | 5 | giữ cũ | cũ | DIGITS1, POINT |
| BUY | 8, 9 | giữ cũ | cũ | DIGITS1, POINT, DIGITS2 |
| BUY | 11 | giữ cũ | cũ | như trên, thêm DIGITS3 |
| BUY | 16 | giữ cũ | `new_sl` | như trên, thêm DIGITS4 |
| BUY | Modify đạt / lỗi | `true` | `new_sl` | như trên, thêm Modify rồi `Print` / `Bot3PrintManagementError` |
| SELL | 1 | giữ cũ | cũ | không |
| SELL | 5, 7, 8, 9 | giữ cũ | cũ | POINT |
| SELL | 11 | giữ cũ | cũ | POINT, DIGITS1 |
| SELL | 16 | giữ cũ | `new_sl` | POINT, DIGITS1, DIGITS2 |
| SELL | Modify đạt / lỗi | `true` | `new_sl` | như trên, thêm Modify rồi `Print` / `Bot3PrintManagementError` |

- Hai hàm là `void`. Chỉ ghi `position.sl` (bước 15), `changed` (bước 20); `state` và `error_count` do hàm có
  sẵn ghi. Không ghi `position.tp`, `position.open_price`, `tick` hay tham số cài đặt.
- Mọi cổng viết dạng `if(!(a<b)) return;`, nên NaN làm cổng sai và hàm thoát.
- Không gọi `SymbolInfoTick`, `NormalizeDouble`, `Bot3TryClosePosition`. Không tính volume, không ghi bảng
  hay Stamp, không thêm cổng nào.
- `Bot3ModifyPosition` (có sẵn) tự trả `false` khi `IsStopped()` hoặc khi `PositionSelectByTicket` lỗi. Khi đó
  hàm vẫn báo lỗi rồi đặt `changed=true`, đúng nhánh "false" của đặc tả. Tôi không thêm xử lý riêng.

## Chỗ viết khác đặc tả (logic giữ nguyên)

- Ba điều kiện thoát gộp trong một `if` với `||`, đúng thứ tự đặc tả. Ba vế không có tác dụng phụ, nên kết
  quả không phụ thuộc cách tính tắt.
- Hậu tố lỗi gán vào `string suffix` cục bộ rồi mới truyền cho `const string &suffix`, giống
  `Bot3ManagementRealTake.mqh` và `Bot3ManagementRealDistance.mqh`. Còn `Bot3ManagementRealTimed.mqh:66` truyền
  thẳng hằng chuỗi; nguồn chính có cả hai cách. Giữa Modify và `GetLastError()` chỉ có một phép tạo chuỗi.
- SELL: `reference-start*captured_unit` và `position.open_price-captured_unit*limit` được gán vào `boundary`,
  `limit_price` rồi mới so. Công thức, thứ tự nhân và phép so không đổi.
- Ngoặc trong `(freeze+position.tp)<quote2` và `(quote3+gap)<new_sl` chỉ để dễ đọc; thứ tự tính trùng với thứ tự
  ưu tiên mặc định.

## Đã dò bằng Grep (dò chữ, không phải biên dịch)

- Tệp mã không có `NormalizeDouble`, `SymbolInfoTick`, `position.tp=`, `position.open_price=`, `TryClose`,
  `Stamp`, hay phép ghi vào `tick.bid`/`tick.ask`. Chữ `volume` chỉ có ở chú thích dòng 2.
- Hậu tố `' when setting Slip TL.  Trying again!` (hai dấu cách trước `Trying`) ở dòng 42, 85 khớp `TASK.md`
  dòng 13. `Slippage control active` (dòng 39) khớp `TASK.md` dòng 13; `Slippage controle active` (dòng 82)
  khớp dòng 20.
- Trước khi ghi tệp, trong `dich-nguoc/khoi-phuc` chưa có `Bot3AdvanceSlippageReal*`,
  `BOT3_MANAGEMENT_REAL_SLIPPAGE_MQH` hay `Bot3ManagementRealSlippage` (ngoài `TASK.md`). Chỉ có
  `Bot3AdvanceSlippageVirtualStop`, là tên khác.

## Codex cần kiểm

1. Chép tệp vào thư mục include, biên dịch; ghi lại lỗi và cảnh báo.
2. So với EX5 gốc theo hai bảng trên: thứ tự API, các lần đọc lại sau API, `captured_unit` của SELL, SL vẫn
   giữ khi bước 16 sai, giá trị `changed` từng nhánh, các chuỗi in.
3. Kiểm phép `<` của MQL5 với NaN có cho `false` không, và `Bot3RoundPrice` (hàm có sẵn) xử lý NaN/Inf thế nào.
   Tôi chưa đo.
4. Kiểm mã máy sau biên dịch: các dạng `a*b+c` không bị gộp thành FMA, thứ tự cộng/nhân giữ nguyên.
   Tôi chưa kiểm.

## Cấu hình phiên

- Mô hình theo môi trường phiên là `claude-opus-5-5`; thông báo hệ thống ghi Ultracode đang bật. Tôi không xem
  được mức `max` từ trong phiên, nên không khẳng định đã dùng.
- Phiên không có công cụ Workflow, và đề bài cấm chạy lệnh hay tác tử khác. Tôi làm một mình, chỉ dùng công cụ
  đọc/tìm tệp và chỉ ghi hai tệp trong thư mục này.
- Tôi đã tự rà mã theo từng bước đặc tả bằng cách đọc lại và dò Grep; đây không phải kiểm bằng máy.
