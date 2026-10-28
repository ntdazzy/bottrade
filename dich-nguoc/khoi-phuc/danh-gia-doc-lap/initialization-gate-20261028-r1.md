# Cổng khởi tạo hoạt động

Đã dựng `Bot1InitializationGate.mqh` và `Bot3InitializationGate.mqh`.
Phần đầu tách thành hai bước, để nơi gọi kiểm quyền thật ở giữa:

- `BotNStartInitializationGate` đặt cờ hoạt động về 0 rồi đọc thông tin
  tài khoản như bản gốc;
- từ chối thì trả về ngay, không bật cờ;
- cho phép thì đặt cờ hoạt động=1;
- trong chế độ kiểm thử, tốc độ 2 đặt chế độ cổng=1, tốc độ 3 đặt=0;
- chỉ tốc độ 2 hoặc 3 trong chế độ kiểm thử bật cờ M1; tốc độ khác giữ
  nguyên cờ M1.

`BotNFinishInitializationGate` nhận kết quả quyền, bật cờ hoạt động nếu
được phép và tự đọc chế độ kiểm thử. Đã so thứ tự đọc tài khoản, cờ và
dịch vụ kiểm thử với lệnh máy gốc **1.600/1.600 ca mỗi bot**, có cả ca
thay đổi dữ liệu trong lúc dịch vụ trả lời. Kết quả kiểm quyền được cấp
cho phép thử; thân kiểm quyền thật và thông báo từ chối chưa được chạy.

Giới hạn: hàm kiểm quyền thật (HTTP/tài khoản) chưa được đưa vào nguồn;
cổng này không tự cho phép chạy. OnInit đầy đủ và các sự kiện EA còn lại
chưa hoàn tất.
