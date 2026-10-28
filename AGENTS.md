# Quy tắc làm việc

- Trả lời bằng tiếng Việt đơn giản, ngắn gọn, có bằng chứng. Không đoán
  hoặc gọi phần chưa kiểm là đã đạt. Tên tệp và mã giữ nguyên.
- Luôn đọc quy tắc này và quy trình của dự án trước khi sửa mã.
- Chỉ sửa phần cần cho yêu cầu. Mã phải rõ ràng, sạch, đúng kiểu dữ liệu,
  không hàm rỗng, không luật tự nghĩ thêm và không sửa hành vi lạ của bot gốc.

## Luồng bắt buộc khi khôi phục bot

1. Trước khi viết thêm chức năng, mở và phân tích kỹ đúng bản EX5 gốc.
   Kiểm mã SHA-256; giữ nguyên tệp gốc và bằng chứng cũ.
2. Lập danh sách đầy đủ các phần nhìn thấy trong bot: hàm, thuật toán,
   nhánh điều kiện, tính năng, đầu vào/cài đặt, chế độ, bảng hiển thị,
   tài nguyên, trạng thái lưu, khởi động/thoát và xử lý lỗi. Mỗi phần
   phải chỉ tới vị trí gốc hoặc bằng chứng chạy. Ghi rõ phần chưa hiểu;
   số hàm trong một bản chụp không chứng minh đã thấy toàn bộ EX5.
3. Dùng một bảng theo dõi chung: phần cần phục hồi → bằng chứng gốc →
   nguồn dựng lại → cách kiểm → kết quả → phần còn thiếu. Không bỏ mục
   chỉ vì khó kiểm. Chưa xác định được một nhánh thì chưa viết nhánh đó
   theo suy đoán; tiếp tục phân tích để làm rõ.
4. Sau bước phân tích, làm từng phần theo danh sách. Giữ công thức,
   thứ tự gọi, điều kiện so, làm tròn, đơn vị và tác dụng phụ như EX5.
   Không thay mục tiêu bằng một bot chỉ chạy gần giống.
5. Theo yêu cầu ngày 28/10/2026, không dùng Claude. Codex trực tiếp
   phân tích, viết mã, kiểm độc lập và ghép các phần đã rõ. Có thể làm
   song song các phần độc lập, nhưng phải đối chiếu bằng chứng gốc và
   kiểm kết quả trước khi ghép. Giữ bằng chứng cũ để tra cứu.
6. So từng phần rồi so toàn bộ nguồn MQL5 đã biên dịch với EX5 gốc trên
   cùng dữ liệu và điều kiện. Kiểm cả giao dịch, toàn bộ cài đặt, bảng
   hiển thị, khởi động lại, trạng thái lưu và lỗi; cùng lợi nhuận chưa đủ.
   Theo yêu cầu ngày 25/10/2026, khi đủ EA chính thì chạy bản gốc và
   bản dựng lại song song trong hai môi trường MT5 kiểm thử riêng,
   cùng dữ liệu và cài đặt; so đầy đủ kết quả theo thứ tự. Chưa có EA
   đầy đủ thì ghi đúng là kiểm từng phần, không gọi là đã chạy hai bot.
7. Chỉ xác nhận hoàn thành 100% khi mọi mục bắt buộc đã có bằng chứng
   trực tiếp, không còn nhánh/chức năng bị sót hoặc sai khác chưa xử lý.
   Nêu đúng giới hạn bằng chứng; số ca kiểm đạt không phải tỷ lệ hoàn
   thành toàn bộ bot.

Ưu tiên hiện tại: bot 1 và bot 3; bắt đầu phân tích bot 2 song song theo yêu cầu ngày 26/10/2026. Dùng MT5 riêng cho kiểm thử, không gửi
lệnh lên tài khoản thật, không sửa EX5 gốc, khóa bản quyền hoặc MT5 chính.
Quy trình chi tiết: `dich-nguoc/khoi-phuc/tai-lieu-cu/QUY-TRINH.md`.
