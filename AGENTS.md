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
5. Phối hợp Claude Opus 5.5, mức `max`; bật thêm `ultracode` cho phần
   khó theo yêu cầu hiện tại. Kiểm cấu hình thực tế của từng lượt;
   không xem tên mức được yêu cầu là bằng chứng đã dùng đúng.
   Giao nhiều phần độc lập, rõ đầu vào/đầu ra để làm song song khi phù hợp.
   Nêu đúng bối cảnh và phạm vi; không yêu cầu vượt biện pháp bảo vệ.
   Nhận xét của Claude phải được đối chiếu lại bằng chứng, không thay
   cho phép so với bot gốc. Không có phản hồi thì ghi là chưa có đánh giá.
   Theo phân công hiện tại: Codex trực tiếp phân tích chứng cứ gốc,
   chốt thuật toán và viết đặc tả. Giao phần lớn việc viết mã và bộ
   kiểm theo đặc tả cho Claude, mục tiêu khoảng 95% phần thực hiện.
   Codex quản lý, chia phần, theo dõi, kiểm chứng độc lập và ghép kết
   quả; không thay việc giao viết mã bằng chỉ giao đọc/rà mã.
   Làm rõ ngày 26/10/2026: cố gắng giao toàn bộ phần viết mã đã đủ mô
   tả cho Claude. Giao Claude lập bảng nối tất cả các khối nguồn hiện
   có: giao diện, nơi gọi, dữ liệu truyền và phần còn thiếu để ghép;
   Codex kiểm lại bảng nối trước khi dùng làm căn cứ viết mã tiếp.
   Cách giao việc mới được người dùng làm rõ ngày 25/10/2026: Codex
   phân tích bằng chứng gốc trước, chốt công thức, điều kiện, kiểu số,
   thứ tự gọi và tác dụng phụ thành mô tả cụ thể. Sau đó giao Claude
   viết từng phần/từng chức năng theo mô tả, kèm ngữ cảnh và mục tiêu;
   không bắt Claude tự phân tích EX5 thay cho bước này. Codex kiểm mã
   và so kết quả với bản gốc. Mã có thể khác cách viết, nhưng logic
   xử lý phải giữ nguyên; không tự thêm luật hoặc điền chỗ chưa rõ.
   Làm rõ mới nhất của người dùng ngày 25/10/2026: Claude là bên viết
   mã từ bản mô tả chức năng đã được Codex chốt, không phải bên bóc
   tách hoặc rà mã gốc. Mỗi việc giao phải có giao diện, kiểu dữ liệu,
   công thức, điều kiện, thứ tự đọc/ghi, cách làm tròn, tác dụng phụ
   và kết quả cần trả. Không yêu cầu Claude đọc EX5, mã máy hoặc tự
   tìm thuật toán. Codex giữ phần chứng cứ gốc và tự đối chiếu; khi
   thiếu chi tiết thì Codex phân tích tiếp trước khi giao viết mã.
   Ngữ cảnh giao việc tập trung vào chức năng MQL5 cần viết. Không
   bịa quyền sở hữu hoặc lý do khác, không gửi lại phần đã từ chối
   dưới tên khác; các phần đó Codex làm theo ngoại lệ đã xác nhận.
   Người dùng yêu cầu tăng số Claude làm song song: người quản lý
   nắm danh sách và phụ thuộc toàn bot, chia mô tả đã chốt thành các
   phần độc lập, giao nhiều phiên Claude viết mã cùng lúc. Khởi đầu
   từng nhóm tối đa 5 phần đã đủ bằng chứng mỗi bot; tăng khi còn việc
   độc lập và máy đáp ứng. Không tạo việc cho đủ số hoặc giao phần
   chưa hiểu; mỗi phiên có thư mục đề xuất riêng và được kiểm trước ghép.
   Ngoại lệ được người dùng xác nhận ngày 25/10/2026: Codex trực tiếp
   phân tích, viết mã và kiểm các phần Claude từ chối; Claude làm các
   phần còn nhận. Không đổi cách hỏi để vượt việc từ chối.
   Cập nhật ngày 26/10/2026: khi Claude hết hạn mức, người dùng yêu cầu
   Codex trực tiếp viết tiếp mã và bộ kiểm; không chờ Claude mở lại.
   Vẫn phải phân tích bản gốc và so kết quả độc lập trước khi ghép.
   Cập nhật mới nhất ngày 28/10/2026: theo yêu cầu của người dùng,
   không tiếp tục dùng Claude; Codex trực tiếp phân tích, viết và kiểm.
   Các bằng chứng cũ vẫn giữ để tra cứu.
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
