> BẢN NHÁP CHƯA ĐƯỢC CHẤP NHẬN. Xem REVIEW.md trước khi dùng.

# Bot 1 — khối khóa thật

## Bằng chứng

- Mua: RVA `0x28f72..0x293da`.
- Bán: RVA `0x2c7b4..0x2cb18`.
- Cả hai thân được gọi sau giá cao/thấp và trước bộ đếm thật.

## Điều kiện chung

Khối chỉ chạy khi khoảng khóa `lockedDistance` (RVA `0x624d0`) dương. Giá hiện tại được đọc lại từ terminal trước các cổng chính. Các cổng dùng điểm `point`, đơn vị `u`, mức dừng tối thiểu và mức đóng băng. Mọi phép so là chặt; bằng ngưỡng thì không khóa.

## Mua

1. Đọc `bid`, rồi kiểm tra mức khóa hiện tại có vượt mức dừng tối thiểu sau khi trừ `lockedDistance*u` hay không.
2. Kiểm tra `bid < TP - freezeMin`; nếu không đạt thì không khóa.
3. Đọc `DIGITS`, tính `newStop = round(bid - lockedDistance*u)`. Sau đó đọc `bid` lần nữa và kiểm tra `newStop < bid - gap` theo đúng thứ tự gốc.
4. Gọi sửa vị thế tại RVA `0x26d20`; cờ thay đổi được bật trước khi gọi. Nếu lời gọi trả lỗi, vẫn giữ cờ thay đổi và chuyển sang nhánh thông báo lỗi của quản lý.

## Bán

1. Dùng `ask` và hướng ngược lại: mức mới là `round(ask + lockedDistance*u)`.
2. Điều kiện bảo vệ là `freezeMin + TP < ask` và `ask + gap < newStop`; bằng ngưỡng không đạt.
3. Giá neo bán trong `xmm15` phải được khôi phục từ `xmm12` trước khi so. Việc đọc/ghi đó xảy ra tại RVA `0x2c796` và không được bỏ.
4. Gọi sửa tại `0x2c654` trong thân bán; lỗi đi qua cùng bộ chuyển lỗi của quản lý.

## NaN và trạng thái

- Các so sánh giá dùng `ucomisd`; NaN đi vào nhánh không đạt.
- Không tăng bộ đếm trong khối khóa. Không ghi bảng 500 dòng ở đây; chỉ cập nhật mức dừng cục bộ và cờ “đã thay đổi”.
- Nếu sửa thất bại, mức dừng cục bộ vẫn là giá vừa tính; không tự khôi phục giá cũ trước khi đi tiếp.

## Còn thiếu bằng chứng

Tên tham số giao diện người dùng của `0x624d0` và `0x624c8` chưa có chuỗi chắc chắn trong snapshot. Đặc tả chỉ dùng tên chức năng và RVA; Claude không được tự đổi thành tên khác khi viết mã.
