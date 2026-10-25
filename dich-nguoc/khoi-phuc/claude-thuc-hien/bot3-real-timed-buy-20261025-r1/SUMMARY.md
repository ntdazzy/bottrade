# Tóm tắt — `Bot3AdvanceTimedBuyStop` (dời SL thật theo thời gian, phía mua), r1

Trạng thái thật: **chỉ là bản đề xuất. Chưa biên dịch, chưa chạy kiểm,
chưa so với EX5 gốc; không có ca kiểm nào đạt.** Chỉ ghi hai tệp trong
thư mục này (`Bot3TimedRealBuy.mqh`, `SUMMARY.md`); `TASK.md`, nguồn
chính và thư mục phiên khác không bị sửa. Không chạy lệnh, Git, MT5;
không đọc EX5/mã máy; không dùng tác tử lồng.

Logic chỉ lấy từ [TASK.md](TASK.md). Đọc thêm để viết đúng kiểu và cùng
cách viết, không lấy logic: trong
[nguồn chính](../../bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/)
các tệp `Bot3ManagementPrelude`, `Bot3PositionModify`, `Bot3PriceLevels`,
`Bot3TradeSend`, `Bot3PendingRequest`, `Bot3TradeErrors`,
`Bot3ManagementVirtual`, `Bot3ManagementVirtualStart`,
`Bot3ManagementVirtualTake`;
[TASK phiên Messages](../bot3-management-messages-20261025-r1/TASK.md)
để biết chữ ký `Bot3PrintManagementError`; TASK phía bán chỉ để tránh
trùng tên; `QUY-TRINH.md` theo `AGENTS.md`; SUMMARY phiên timed chỉ để
theo mẫu trình bày.

## Đặc tả → mã

Số dòng là dòng trong [Bot3TimedRealBuy.mqh](Bot3TimedRealBuy.mqh).

| Bước | Đặc tả | Mã |
|---|---|---|
| — | Chặn include; include Prelude và Messages; 13 tham số đúng thứ tự, kiểu, tham chiếu/const | :3–6, :11–15 |
| 1 | `!(0.0<activation)` → false (NaN cũng thoát) | :17 |
| 1 | `TimeCurrent()` đúng 1 lần, ép `long` | :18 |
| 1 | Sau lời gọi: mốc = `opened+(long)delay_seconds`, cộng cuộn 64 bit qua `ulong`, ép lại `long`; `now<mốc` (có dấu) → false | :19–20 |
| 2 | `quote=tick.bid` trước DIGITS lần 1; `digits` lúc này là digits1 (`uint`); rồi POINT | :21–23 |
| 3 | Sau POINT mới đọc `distance`, `unit`: `gate=distance*unit+(point+position.sl)`, rồi `Bot3RoundPrice(gate,digits1)`; `!(gate<quote)` → false | :24–26 |
| 4 | Đọc `tick.bid`, `freeze` lúc so: `!(tick.bid<position.tp-freeze)` → false | :27 |
| 5 | DIGITS lần 2 (digits2); SAU đó `quote=tick.bid` (quote2); đọc lại `distance`, `unit`; `candidate=Bot3RoundPrice(quote2-distance*unit,digits2)`; gán `position.sl=candidate` ngay | :28–31 |
| 6 | Đọc `gap` lúc so: `!(candidate<quote2-gap)` → false, `position.sl` giữ giá trị vừa gán | :32 |
| 7 | `Bot3ModifyPosition(state,options,ticket,position.sl,position.tp)`; sau lời gọi luôn trả `true` | :33, :38 |
| 8 | Chỉ khi Modify `false`: gọi `Bot3PrintManagementError(<đuôi>,error_count)` một lần | :33–37 |

## Thứ tự đọc/ghi đã giữ

- Đường đầy đủ gọi API theo thứ tự: `TimeCurrent` → DIGITS → POINT →
  DIGITS → `Bot3ModifyPosition` → (nếu sửa lỗi) `Bot3PrintManagementError`.
  Mỗi lối thoát sớm nằm trước lời gọi kế tiếp, nên không có lời gọi thừa.
- `quote` chụp trước DIGITS lần 1, chỉ dùng cho cổng `gate<quote`; phép so
  bước 4 đọc `tick.bid` mới. `quote` được gán lại ở :29, sau DIGITS lần 2.
- `distance`/`unit` đọc ở :24 (sau POINT) và đọc lại ở :30 (sau DIGITS
  lần 2); không giữ `offset` cũ. `freeze` đọc ở :27, `gap` ở :32, đều lúc dùng.
- `position.opened`, `position.sl`, `position.tp` lấy từ bản cục bộ; chỉ
  ghi `position.sl` (:31). Không ghi `tp`, không đóng vị thế, không ghi
  bảng, không Stamp/Delay, không kiểm hợp lệ số.
- `Bot3ModifyPosition` nhận `position.sl`/`position.tp` đọc lúc gọi (sau :31).
- `error_count` chỉ đi qua `Bot3PrintManagementError`; hàm này không tự đổi.

## Kiểu số

- `now`, `due`: `long`. `due=(long)((ulong)opened+(ulong)(long)delay_seconds)`:
  `delay_seconds` int32 mở rộng có dấu sang 64 bit, cộng trong `ulong`
  (cuộn theo 2^64), ép lại `long`, so có dấu. Không dùng `double`, không
  trừ `now-opened`.
- `digits`: `uint` từ `(uint)SymbolInfoInteger(...)`, đúng kiểu tham số
  của `Bot3RoundPrice`. Không dùng `NormalizeDouble`.
- Giá: `double`. Mọi phép so viết `if(!(a<b)) return false;`, nên NaN làm
  điều kiện sai và hàm thoát.
- Ngoặc giữ đúng đặc tả: `distance*unit+(point+position.sl)`,
  `quote-distance*unit`, `position.tp-freeze`, `quote-gap`.

## Điểm còn thiếu / cần Codex chốt

1. `Bot3ManagementMessages.mqh` chưa có trong nguồn chính; lúc đọc, thư
   mục `bot3-management-messages-20261025-r1` chỉ có `TASK.md`. Mã dựa vào
   chữ ký trong TASK đó: `void Bot3PrintManagementError(const string &suffix,uint &error_count)`.
   Nếu chữ ký đổi thì lời gọi :36 phải đổi theo.
2. Chuỗi đuôi truyền qua biến cục bộ `suffix` (:35) thay vì chuỗi hằng,
   vì tham số là `const string &` và tôi chưa kiểm được MetaEditor có nhận
   chuỗi hằng cho tham chiếu không. Nội dung giữ đúng từng ký tự (kể cả
   `size_ loss` và hai dấu cách sau `loss.`); số lần gọi và tác dụng phụ
   không đổi. Nếu trình biên dịch nhận chuỗi hằng, Codex có thể đưa thẳng
   vào lời gọi.
3. Phép ép `(long)` từ `ulong` lớn hơn `LONG_MAX` dựa vào việc MQL5 giữ
   nguyên dãy bit (bù hai). Chưa kiểm bằng biên dịch/chạy.
4. Đặc tả nêu đọc `delay_seconds` rồi `opened`. Mã đọc cả hai trong một
   biểu thức sau `TimeCurrent`, viết `opened+delay` theo công thức. Giữa
   hai lần đọc không có lời gọi nào, phép cộng `ulong` giao hoán, nên kết
   quả như nhau.
5. Bước 4 "đọc mới" `tick.bid`/`freeze`: giữa bước 3 và 4 chỉ có
   `Bot3RoundPrice` (chỉ tính trên tham số, không đọc/ghi `tick` hay cài
   đặt), nên lần đọc ở :27 là lần đọc sau POINT như yêu cầu.
6. Bước 6 so bằng biến `candidate`, cùng giá trị vừa gán vào `position.sl`.
7. Đặc tả không có địa chỉ gốc và không nói người gọi làm gì sau
   `true`/`false`. Đầu tệp chưa ghi địa chỉ gốc; khi ghép, Codex cần bổ
   sung và nối đúng luồng.
8. NaN ở `gate`/`candidate` còn đi qua `Bot3RoundPrice` có sẵn; kết quả
   phụ thuộc hàm đó (cách MQL5 ép `(long)NaN`), không do mã này quyết
   định. Cần có trong ca kiểm.

## Chưa kiểm

- Biên dịch MetaEditor (mục tiêu 0 lỗi, 0 cảnh báo) khi đặt tệp cạnh
  Prelude và Messages trong `Include/bot-cua-toi-3/`.
- So với bản gốc trên dữ liệu cố định, gồm:
  - activation `0`, `-0.0`, âm, NaN, +vô cực;
  - `now` bằng mốc và kém mốc 1 giây; delay âm, 0, lớn; tổng tràn qua `LONG_MAX`;
  - hai vế bằng nhau ở ba phép so giá (`gate<quote`, `bid<tp-freeze`, `candidate<quote2-gap`);
  - NaN/vô cực ở point, distance, unit, bid, sl, tp, freeze, gap;
  - `tick`/`distance`/`unit` đổi sau từng lời gọi DIGITS/POINT, để tách
    `quote` đã chụp với giá trị đọc lại; digits lần 1 khác lần 2;
  - số lần gọi mỗi API; giá trị `position.sl` khi bước 6 sai;
  - Modify `false`/`true`: hàm trả `true`, thông báo một lần hoặc không;
    `error_count` chỉ đổi qua hàm báo lỗi.
- Ghép vào hàm quản lý thật, vòng ngoài, EA chính; chạy hai bot song song.
  Chưa có cơ sở để nói phần này hay bot 3 đã đạt.

## Phụ thuộc

- `Bot3ManagementPrelude.mqh`: `Bot3ManagedPosition` (dùng `sl`, `tp`,
  `opened`); qua đó `Bot3PriceLevels.mqh` (`Bot3RoundPrice`),
  `Bot3PositionModify.mqh` (`Bot3ModifyPosition`) → `Bot3TradeSend.mqh`
  (`Bot3TradeSendOptions`) → `Bot3PendingRequest.mqh` (`Bot3PendingRequestState`).
- `Bot3ManagementMessages.mqh` (chưa có, xem điểm 1) → `Bot3TradeErrors.mqh`.
- API MT5: `TimeCurrent`, `SymbolInfoInteger(…,SYMBOL_DIGITS)`,
  `SymbolInfoDouble(…,SYMBOL_POINT)`, `MqlTick`.
- Include dùng đường dẫn tương đối; thư mục đề xuất này không có Prelude
  và Messages nên không biên dịch tại chỗ được.

## Cấu hình phiên

Mô hình theo thông tin hệ thống: `claude-opus-5-5`. Mức `max`/`ultracode`
không tự kiểm được từ trong phiên. Phiên báo bật ultracode nhưng không có
công cụ Workflow và đề bài cấm tác tử lồng, nên làm một mình. Chỉ dùng
Read/Glob/Grep/Write.
