# Tóm tắt — ứng viên phần A (dời dừng ảo theo thời gian) bot 3, r1

Trạng thái thật: **chỉ là ứng viên. Chưa biên dịch, chưa chạy kiểm,
chưa so với EX5 gốc; không có số ca đạt.** Chỉ ghi hai tệp trong thư
mục này (`Bot3ManagementTimedStop.mqh`, `SUMMARY.md`); `TASK.md`, nguồn
chính và thư mục của phiên khác không bị sửa. Không dùng Bash/PowerShell,
Git, MT5; không đọc EX5/C/mã máy.

Logic chỉ lấy từ phần đầu, "Dữ liệu chung và quy ước" và phần A của
[contract](../../bot-cua-toi-3/phan-tich/dong-vi-the/management-virtual-20261025-r1/contract.md).
Công cụ Read trả về cả tệp; không dùng nội dung B/C. Có đọc
[Prelude r2](../bot3-management-prelude-20261025-r2/Bot3ManagementPrelude.mqh),
bản cùng tên trong
[nguồn chính](../../bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/Bot3ManagementPrelude.mqh)
(nội dung giống hệt r2), cùng `Bot3VirtualStops`, `Bot3ManagementAnchor`,
`Bot3PriceLevels`, `Bot3PositionModify`, `Bot3PositionClose`, chỉ để
viết cùng cách.

## Mô tả A → mã

Số dòng là dòng trong [Bot3ManagementTimedStop.mqh](Bot3ManagementTimedStop.mqh).

| Mục trong A | Mã |
|---|---|
| Hàm void, 11 tham số đúng thứ tự, đúng kiểu tham chiếu/const | :9–13 |
| Chỉ tiếp khi `0.0<activation`; viết `!(0.0<activation)` nên NaN cũng thoát | :15 |
| `TimeCurrent` gọi đúng một lần, chỉ sau khi activation đạt | :16 |
| `now >= opened+(long)delay_seconds`; delay đọc sau `TimeCurrent` | :17 (viết dạng thoát `now<…`, cùng nghĩa với số nguyên) |
| Chụp `level=current_level`, `quote=buy?bid:ask` trước `SymbolInfoDouble(symbol,SYMBOL_POINT)` | :18–20 |
| API POINT chỉ gọi khi hai điều kiện trên đạt | :15, :17 chặn trước :20 |
| Sau API: `offset=distance*unit` | :21 |
| Mua: `((level+point)+offset)<quote`, rồi `tick.bid<(tp-freeze_distance)` | :22, :24 |
| Bán: `quote<((level-point)-offset)`, rồi `(freeze_distance+tp)<tick.ask` | :23, :25 |
| Đạt: `changed=true`, rồi mua `tick.bid-offset`, bán `offset+tick.ask` | :26–27 |
| Dùng `offset` đã tính, không tính lại sau phép kiểm cuối | :27 |
| Không làm tròn, không gửi lệnh, không in | không có lời gọi nào ngoài `TimeCurrent`, POINT |
| Không đạt: giữ nguyên `changed` và `current_level` | mọi `return` ở :15, :17, :23, :25 đều trước :26 |

## Quy tắc đã giữ

- Phép so số thực viết dạng `if(!(a<b)) return;`: có NaN thì điều kiện
  sai, hàm thoát, không đổi gì. Không đổi thành `a>=b`.
- Thứ tự cộng/trừ đúng ngoặc của mô tả; không gộp, không đổi vế.
- Phép kiểm thứ nhất dùng `quote` đã chụp trước API; phép kiểm thứ hai
  và phép gán đọc `tick.bid`/`tick.ask` lúc dùng, sau API.
- `changed` chỉ được gán `true`; không xóa khi không đạt.
- Không kiểm hợp lệ, không nắn giá, không làm tròn; không Modify/Close/Print.
- `freeze_distance` dùng thẳng, không nhân `unit`; `activation` chỉ dùng
  ở phép so với `0.0`. Cả hai đúng như mô tả, không sửa hành vi lạ.

## Điểm mô tả còn thiếu (Codex cần chốt)

1. Mô tả chỉ nói chụp `level`/`quote` trước API POINT, không nói trước
   hay sau `TimeCurrent`. Mã chụp sau phép so thời gian, ngay trước
   POINT. Chỉ khác gốc nếu bộ kiểm thay `TimeCurrent` bằng hàm làm đổi
   `current_level` hoặc `tick`.
2. Mô tả không ghi phép so thời gian có dấu hay không dấu, cũng không
   ghi khi `opened+delay` bị tràn. Mã dùng `long` có dấu
   (`(long)TimeCurrent()`), như `Bot3VirtualStops`.
3. Mô tả không ghi luồng đi đâu sau thân mua `0x36727` (phía bán
   `0x3a21a..0x3a2f7` liền với đoạn sau). Hàm là void như mô tả, nên khi
   ghép, người gọi phải đi tiếp như nhau sau mọi lối ra. Codex cần xác
   nhận; mã không tự thêm giá trị trả về.
4. Mô tả ghi `bool buy`; mã viết `const bool buy` như Prelude. Tham số
   truyền trị nên cách gọi không đổi.

## Chưa kiểm

- Biên dịch MetaEditor (mục tiêu 0 lỗi, 0 cảnh báo), gồm cách MetaEditor
  dịch phép so khi có NaN.
- So với đoạn máy gốc tại ranh giới, dữ liệu cố định, cả mua và bán:
  - activation `0`, âm, `-0.0`, NaN, +vô cực;
  - `now` bằng đúng `opened+delay` và kém 1 giây; delay âm, 0, lớn; tổng tràn; giờ ≥ 2^63;
  - hai vế bằng nhau ở cả hai phép so (phép `<` chặt);
  - NaN/vô cực ở `current_level`, point, distance, unit, bid/ask, tp, freeze;
  - dữ liệu đổi sau `TimeCurrent` và sau POINT (tách `quote` đã chụp với `tick` đọc lại);
  - số lần gọi `TimeCurrent` (0 hoặc 1) và POINT (0 hoặc 1);
  - `changed` vào là `true`/`false` được giữ nguyên khi không đạt.
- Ghép vào hàm quản lý thật (`0x32f60`/`0x37590`), vòng ngoài, EA chính;
  chạy hai bot song song. Chưa có cơ sở để nói phần này hay bot 3 đã đạt.

## Phụ thuộc

- `Bot3ManagementPrelude.mqh`: kiểu `Bot3ManagedPosition`; hàm chỉ dùng
  `tp` (double) và `opened` (long). Prelude cũng là ứng viên chưa biên dịch.
- Qua Prelude (hàm này không dùng nhưng cần để biên dịch):
  `Bot3PriceLevels`, `Bot3PositionModify`, `Bot3PositionClose` →
  `Bot3TradeSend` → `Bot3TradeMessages`, `Bot3PendingRequest` → `Bot3Filling`.
- API MT5 chuẩn: `TimeCurrent()`, `SymbolInfoDouble(string,SYMBOL_POINT)`, `MqlTick`.
- Include dùng đường dẫn tương đối: phải đặt tệp cạnh
  `Bot3ManagementPrelude.mqh` trong `Include/bot-cua-toi-3/`. Thư mục đề
  xuất này không có Prelude nên không biên dịch tại chỗ được.
- Đối số khi ghép (theo phần chung và A): unit `0x73dd8`; tick bid
  `0x74798`, ask `0x747a0`; `current_level` là mốc H (stack mua+0x78 /
  bán+0x88); `changed` là r12b; cài đặt `0x6d5e8`, `0x6d5f0`, `0x7449c`,
  `0x744a8`. Địa chỉ `0x744a8` trùng threshold_b mà SUMMARY Prelude r2
  ghi; khi ghép nên truyền cùng một biến.

## Cấu hình phiên

Mô hình theo thông tin hệ thống: `claude-opus-5-5`. Mức `max`/`ultracode`
không tự kiểm được từ trong phiên. Phiên báo bật ultracode nhưng không có
công cụ Workflow, nên làm một mình. Chỉ dùng Read/Glob/Grep/Write.
