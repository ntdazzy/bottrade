# Tóm tắt — ứng viên phần C (dời dừng ảo theo trượt giá), bot 3, r1

Trạng thái thật: **chỉ là ứng viên. Chưa biên dịch, chưa chạy kiểm, chưa
so với EX5 gốc; chưa có ca kiểm nào.** Chỉ ghi hai tệp trong thư mục này:
[Bot3ManagementSlippageStop.mqh](Bot3ManagementSlippageStop.mqh) và tệp
này. Không sửa `bot-cua-toi-3/source/`, không đụng tệp phần A/B. Không
chạy lệnh, Git hay MT5.

## Nguồn đã đọc

- `AGENTS.md`, `tai-lieu-cu/QUY-TRINH.md`.
- [contract.md](../../bot-cua-toi-3/phan-tich/dong-vi-the/management-virtual-20261025-r1/contract.md):
  dòng 1–23 (chung), 88–122 (phần C), 123–127 (mục kiểm chung).
  Không đọc phần A/B (dòng 24–87).
- [Prelude r2](../bot3-management-prelude-20261025-r2/Bot3ManagementPrelude.mqh)
  và SUMMARY của nó. Bản cùng tên trong `source/MQL5/Include/bot-cua-toi-3/`
  có nội dung giống r2.
- Để viết cùng kiểu: `Bot3VirtualStops`, `Bot3ManagementAnchor`,
  `Bot3PriceLevels`, `Bot3PositionModify`, `Bot3PositionClose`,
  `Bot3OrderCancel` trong Include bot 3. Lệnh tìm `SYMBOL_POINT` trong
  `source/` có hiện 2 dòng của Scripts kiểm; không mở các tệp đó.
- Không đọc EX5, C, mã máy, bản chụp hay nguồn bot 1.

## Quy tắc đã giữ

Số dòng là dòng trong `Bot3ManagementSlippageStop.mqh`.

| Mục phần C | Mã |
|---|---|
| `void Bot3AdvanceSlippageVirtualStop`, 14 tham số đúng thứ tự và kiểu; giữ `bool buy` như mô tả | :13–18 |
| Chỉ tiếp khi `enabled==1`, `distance_passed`, `0.0<trail_distance`, theo thứ tự đó | :20 |
| Chụp `level=current_level`, `quote=buy?tick.bid:tick.ask` trước API POINT | :21–22 |
| API `SymbolInfoDouble(symbol,SYMBOL_POINT)` | :23 |
| Sau API đọc `unit` một lần vào `unit_value`; `offset=trail_distance*unit_value` | :24–25 |
| Mua: `offset+(level+point)<quote`; `reference+start_distance*U<tick.bid`; `tick.bid<(tp-freeze)`; `current_level<(U*limit+open)` | :28–31 |
| Bán: `quote<((level-point)-offset)`; `tick.ask<(reference-start*U)`; `(freeze+tp)<tick.ask`; `(open-U*limit)<current_level` | :36–39 |
| Print một lần: mua `Slippage control active`, bán `Slippage controle active` (giữ lỗi chữ) | :32, :40 |
| Sau Print: `changed=true` | :42 |
| Đọc lại `trail_distance`, `unit`, `tick`: mua `tick.bid-trail_distance*unit`, bán `trail_distance*unit+tick.ask` | :43 |
| Không Modify/Close/làm tròn; không xóa `changed` khi không đạt | Không có lời gọi nào; mọi nhánh không đạt đều `return` trước :42 |

Thứ tự đọc dữ liệu:

- Điều kiện 1 dùng `level`/`quote` đã chụp; điều kiện 2–3 đọc lại
  `tick.bid`/`tick.ask`; điều kiện 4 đọc lại `current_level`, không dùng `level`.
- Mọi chỗ U trong `offset` và các điều kiện dùng `unit_value`; sau Print
  đọc lại tham chiếu `unit`.
- `trail_distance` được đọc 3 lần: ở cổng, ở `offset` (sau API), sau Print.
- Mọi phép so viết `if(!(a<b)) return;`: có NaN thì thoát; không đổi thành `>=`.
- Giữ dấu ngoặc và thứ tự phép tính như mô tả; không kiểm hợp lệ giá,
  không làm tròn.

## Chưa kiểm

1. Biên dịch (mục tiêu 0 lỗi, 0 cảnh báo). Include dùng tên tệp tương đối:
   phải đặt cạnh `Bot3ManagementPrelude.mqh` trong `Include/bot-cua-toi-3/`.
2. So với lệnh gốc 0x364e2..0x36667 và 0x3a803..0x3a97d. Ca đề xuất:
   - cổng: `enabled` 0/1/2/-1; `distance_passed` false/true;
     `trail_distance` 0, -0, âm, NaN, +vô cực;
   - từng điều kiện mua/bán: hai vế bằng nhau (phải thoát vì `<` chặt),
     lệch nhỏ nhất ở hai phía, NaN/±vô cực ở từng toán hạng;
   - đổi `current_level`, `tick`, `unit`, `trail_distance` trong lúc gọi
     POINT: điều kiện 1 dùng `level`/`quote` cũ, phần còn lại dùng giá trị mới;
   - đổi `trail_distance`, `unit`, `tick` trong lúc Print: `current_level`
     phải theo giá trị mới;
   - Print đúng một lần, đúng chữ; `changed` vào là true hay false đều giữ
     nguyên khi thoát sớm; không có lệnh Modify/Close.
3. `position.tp`/`position.open_price` được đọc qua tham chiếu lúc so
   (sau POINT); gốc giữ O/T trong xmm6/xmm7. Chỉ khác nếu bộ kiểm đổi
   `position` trong lúc gọi API.
4. Cần xem mã máy sinh ra có tính nhân rồi mới cộng/trừ như gốc, không gộp
   thành một lệnh nhân-cộng (FMA).

## Phụ thuộc

- `Bot3ManagementPrelude.mqh`: struct `Bot3ManagedPosition` (chỉ dùng
  `tp`, `open_price`). Prelude kéo theo `Bot3PriceLevels`,
  `Bot3PositionModify`, `Bot3PositionClose` và các tệp chúng include,
  dù phần C không gọi các hàm đó.
- API MT5: `SymbolInfoDouble`, `Print`.
- Bên gọi cấp theo mô tả: `unit` U 0x73dd8; `enabled` int 0x6d4e8;
  `distance_passed` byte local 0x5c mua/0x54 bán; `reference` R (xmm15,
  đã chụp trước, không lấy lại từ bảng); start/trail/limit
  0x6d4f0/0x6d4f8/0x6d500; `freeze_distance` 0x744a8 (theo SUMMARY
  Prelude r2, đây cũng là địa chỉ threshold_b); `tick` bid/ask
  0x74798/0x747a0; `position` do Prelude đọc; `changed` r12b.

## Mô tả còn thiếu (mã không tự điền)

1. Nhánh mua có ba đích ra 0x3672c/0x36736/0x36813, nhưng mô tả không nói
   bước nào đi tới đích nào; nhánh bán không ghi đích ra. Hàm `void` nên
   bên gọi không biết đã thoát ở đâu. Nếu đoạn sau khác nhau theo đích thì
   cần mô tả thêm hoặc thêm đầu ra.
2. Phần C không ghi `current_level` là P (0x6d670) hay H (stack
   mua+0x78/bán+0x88); Codex cần chốt khi ghép.
3. "API POINT" chưa ghi dạng gọi. Mã dùng dạng trả `double`, như
   `Bot3OrderCancel.mqh:10`. Nếu gốc dùng `bool SymbolInfoDouble(...,double &)`
   thì giá trị `point` khi API lỗi có thể khác.
4. `distance_passed` được ghi là byte, còn tham số là `bool`; chưa ghi gốc
   thử `!=0` hay `==1`. Chỉ khác khi byte mang giá trị khác 0/1.

## Cấu hình phiên

Mô hình theo thông tin hệ thống: `claude-opus-5-5`. Hệ thống báo bật
`ultracode`, nhưng phiên này không có công cụ Workflow nên làm một mình.
Không tự kiểm được mức `max` từ bên trong phiên. Chỉ dùng
Read/Grep/Glob/Write.
