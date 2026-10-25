# Tình trạng các bản mô tả

Các tệp distance.md, slippage.md, high-low.md, lock.md, counter-store.md
là bản nháp do các phiên Codex viết, chưa được phép dùng thẳng để viết mã.
Root đã phát hiện lỗi có bằng chứng:

- distance.md nói đọc DIGITS trước kiểm đóng băng ở bước4, nhưng lệnh
  283d8..283ef chỉ tính TP-freeze và so giá. Không có lần gọi đó.
- distance.md nói tiếp tục kiểm khối lượng sau khi sửa thất bại. Đường
  lỗi2a615..2a630/2dd93..2ddb3 đặt changed rồi sang nhánh kế, bỏ kiểm này.
- lock.md ghi lời gọi2c654 trong khối bắt đầu2c7b4; địa chỉ đó nằm ngoài
  khối đang mô tả. Chưa chấp nhận công thức khóa của bản nháp.
- counter-store.md nói chỉ ghi current_stop theo điều kiện giá. Lệnh
  2966a/2cdaa ghi current_stop TRƯỚC nhánh kiểm giá. Hàm lưu ba DIGITS
  xử lý initial_stop/current_stop, không chuẩn hóa số vé trong ba lần đó.
- counter-store.md ghi bảng64470; địa chỉ thực65470 với số bù-2ee0
  cho hàng đầu62590. Không dùng địa chỉ bản nháp để gán mảng nguồn.

Root đã chốt riêng chức năng ghi bảng trong TASK bot1-real-store-20261025-r1.
Nhánh khoảng giá đã được Root đọc thêm cả đường báo lỗi/đóng. Các phần
chưa kiểm đủ giữ nguyên chưa xác minh; không giao Claude thuật toán mơ hồ.
