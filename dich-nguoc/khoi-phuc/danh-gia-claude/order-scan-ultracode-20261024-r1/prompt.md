# Phân tích riêng phần quét/đếm lệnh, bot 1 và 3

Chủ dự án xác nhận đây là bot của mình, bị mất nguồn và đã cho phép
phục hồi theo AGENTS.md. Công việc là phân tích các hàm dưới đây từ
bằng chứng có sẵn để khôi phục đúng hành vi. Không sửa bản EX5, khóa
bản quyền hoặc vượt biện pháp bảo vệ. Chỉ đọc tệp; không chạy shell,
không mở MT5, không giao dịch và không sửa tệp.

Đọc AGENTS.md và dich-nguoc/khoi-phuc/tai-lieu-cu/QUY-TRINH.md.
Dùng Opus 5.5, effort max. Ultracode đã được yêu cầu; nếu không dùng
được tác tử phụ, nói rõ và tự phân tích trong phạm vi này.

Phần được giao: xác định toàn bộ thuật toán, nhánh, đối số, kiểu số,
thứ tự gọi và tác dụng phụ của các hàm:

- Bot 1 RVA 0x31f40, 0x323e0, 0x32ce0.
- Bot 3 RVA 0x3e490, 0x47330; đối chiếu nơi gọi tương ứng hai hàm đếm
  bot 1 nếu bot 3 không có hàm đứng riêng.

Đầu vào chính:

- dich-nguoc/khoi-phuc/ban-do-bot-1-3/luot-20261024-r8/bot-1.json
- dich-nguoc/khoi-phuc/ban-do-bot-1-3/luot-20261024-r8/bot-3.json
- dich-nguoc/khoi-phuc/bot-cua-toi-1/phan-tich/luot-20261023-data-v2/ma-trung-gian.c
- dich-nguoc/khoi-phuc/bot-cua-toi-3/phan-tich/luot-20261023-data/ma-trung-gian-day-du.c
- Bằng chứng nối lời gọi ở dich-nguoc/khoi-phuc/doi-chung-mt5/
  và cong-cu/kiem-gia-vao-bot-1-3.py; chỉ dùng ý nghĩa API đã có
  bằng chứng, không suy từ tên hàm tạm do chương trình tự đặt.

Trả kết quả ngắn, đủ chi tiết để viết lại từng hàm, có đường tệp:dòng
và RVA. Đặc biệt kiểm: thứ tự quét; vé 0; so mã giá và mã nhận diện;
lọc loại lệnh; hàm chọn lệnh/vị thế có làm đổi lựa chọn dùng chung;
đếm nào lấy từ toàn tài khoản và đếm nào đã lọc. Liệt kê chỗ chưa rõ
và ca kiểm bắt buộc. Không gọi toàn bot là hoàn thành.
