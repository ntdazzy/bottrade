# Cổng khởi tạo hoạt động

Đã dựng `Bot1InitializationGate.mqh` và `Bot3InitializationGate.mqh`.
Hàm nhận kết quả kiểm quyền từ bên ngoài, sau đó giữ đúng phần đã đọc
được trong OnInit:

- cờ hoạt động đặt 0 trước kiểm quyền;
- từ chối thì trả về ngay, không bật cờ;
- cho phép thì đặt cờ hoạt động=1;
- trong chế độ kiểm thử, tốc độ 2 đặt chế độ cổng=1, tốc độ 3 đặt=0;
- chế độ kiểm thử luôn bật cờ M1.

API của cả hai bot và toàn bộ header biên dịch 0 lỗi, 0 cảnh báo.

Giới hạn: hàm kiểm quyền thật (HTTP/tài khoản) chưa được đưa vào nguồn;
cổng này không tự cho phép chạy. OnInit đầy đủ và các sự kiện EA còn lại
chưa hoàn tất.
