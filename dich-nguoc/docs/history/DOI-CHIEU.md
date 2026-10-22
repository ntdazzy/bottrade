# Đối chiếu cách đọc mã

Mục tiêu: kiểm tra cách lấy mã đang chạy trước khi áp dụng cho các bot không có mã nguồn.

## Bài đối chứng đã kiểm

- Nguồn: `terminal/MQL5/Experts/Market/Ex5ReadProbe.mq5`.
- Chương trình chỉ chạy trong máy thử, không có lệnh mua hoặc bán.
- Phép tính gốc: `value * 1357911 + 2468022`.
- Đầu vào 17 cho kết quả **25.552.509**, khớp dòng `EX5_PROBE_BEGIN` trong nhật ký máy thử.
- Mã đọc từ bộ nhớ có lệnh nhân với `0x14b857` và cộng `0x25a8b6`; hai số này lần lượt là 1.357.911 và 2.468.022.
- Ghidra xuất lại đúng biểu thức đó trong `decompiled/control.c`.
- Kiểm lại mã kiểm tra của nguồn và bản EX5: đều còn khớp bản ghi biên dịch. Xem `control-fresh-check.json`.

## Điều bài này chưa chứng minh

- Chưa chứng minh toàn bộ mã của 15 bot đã được khôi phục đúng.
- Chưa chứng minh mã dạng C có thể chạy độc lập hoặc biên dịch thành MQ5.
- Chưa xác định đầy đủ tên hàm, kiểu dữ liệu, giá trị nằm ngoài vùng mã và cách gọi các chức năng MT5.
- Chưa đối chiếu từng lệnh giao dịch giữa bot gốc và một bản viết lại.

Số hàm xuất được chỉ là kết quả của công cụ. Không dùng số này làm tỷ lệ chính xác hoặc tỷ lệ khôi phục toàn bộ bot.

## Phạm vi đọc và vận hành

- Chỉ đọc vùng mã riêng của `metatester64.exe` trong bản MT5 dành cho lượt này.
- Hai ca từ chối chương trình khác và nơi ghi ngoài thư mục cho phép đều đạt; xem `capture-guard-checks.json`.
- Thử lấy thêm vùng chỉ đọc của Twister không thu được dữ liệu bổ sung: phần tiếp giáp có quyền ghi. Bản này chưa đọc vùng đó.
- Các lượt chạy phục vụ lấy mã bị dừng sau khi đã chụp. Không dùng chúng để đánh giá lợi nhuận.
- Sau khi chụp, bản máy thử riêng đã dừng; bản sao bộ nhớ đệm đăng nhập đã xóa. Các tệp EX5 gốc vẫn khớp mã kiểm tra.
