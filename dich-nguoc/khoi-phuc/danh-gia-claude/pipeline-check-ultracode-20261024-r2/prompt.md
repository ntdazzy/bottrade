Phiên trước chỉ trả lời đã giao năm tác tử phụ, chưa đưa đánh giá.
Các nhật ký tác tử kết thúc bằng `[Request interrupted by user]`;
chúng tôi chưa nhận được kết quả rà soát và không coi đó là xác nhận.

Tiếp tục đúng bối cảnh được phép trước đó: chủ dự án phục hồi bot
của mình, giữ EX5 và khóa dùng nguyên trạng. Chỉ đọc; không chạy shell,
MT5, không giao dịch, không sửa tệp, không vượt biện pháp bảo vệ.

Hoàn tất trực tiếp phần nhỏ sau bằng Opus 5.5, effort max. Ultracode
đã bật; nếu giao phụ thì phải thu kết quả trước khi kết thúc. Nếu
không thu được, tự kiểm phần được giao và trả nhận xét thực tế.

Phạm vi lần này chỉ là bộ kiểm mới do chúng tôi viết:

1. Đọc cong-cu/kiem-chuoi-dat-lenh-bot-1-3.py trong
   dich-nguoc/khoi-phuc/, nhất là Original.call/visit/run và
   validate_fixture_inputs.
2. Kiểm xem điểm api51 thật sự chỉ quan sát, không gán sẵn kết quả
   toàn hàm tạo lệnh; kiểm return-address cùng RSP; kết quả sau hàm
   và trạng thái 35 trường/bốn chuỗi có bị chép vào native không.
3. Đọc phần cần thiết của cong-cu/kiem-hang-doi-bot-1-3.py và
   cong-cu/kiem-gui-lenh-bot-1-3.py để xác nhận cách kế thừa. Không
   đọc cases.json lớn. Bằng chứng hiện hành là pipeline-20261024-r2,
   đã khớp 818 ca mỗi bot; không dùng lượt r1 làm nguồn hiện hành.

Trả một trong hai: lỗi thật kèm file:dòng và cách kiểm, hoặc chưa
thấy lỗi trong phần đã đọc kèm giới hạn. Không chỉ trả lời đã giao
việc, đang làm hoặc sẽ báo sau. Đây chưa phải EA hoàn chỉnh; kết quả
gửi/thuộc tính/lỗi được cấp sẵn và vẫn chưa kiểm nơi giao dịch.
