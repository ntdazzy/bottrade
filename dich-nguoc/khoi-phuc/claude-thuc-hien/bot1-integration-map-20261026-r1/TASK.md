# Nối toàn bộ các khối nguồn MQL5 bot 1

Đây là dự án MQL5 có nhiều khối nguồn đã viết riêng và đang cần ghép thành chương trình đầy đủ. Bạn phụ trách lập bảng nối TOÀN BỘ nguồn hiện hành của bot 1, để bên quản lý giao phần viết mã ghép có đủ đầu vào/đầu ra. Yêu cầu Opus5.5 max, ultracode; cấu hình thực tế sẽ được kiểm riêng.

Chỉ đọc cây `dich-nguoc/khoi-phuc/bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1` và các Script cùng bot để hiểu cách dùng.  Không đọc các thư mục phân tích hoặc tìm thuật toán ngoài nguồn được giao. Không sửa mã nguồn chính, Git, MT5; không dùng shell/tạo tác tử. Chỉ ghi `integration-map.json`, `INTEGRATION.md`, `SUMMARY.md` ngay trong thư mục đề xuất này.

Đầu ra cần chính xác và đủ:

1. Liệt kê TỪNG header có nguồn, không bỏ vì là hàm nhỏ. Mỗi tệp ghi đường dẫn tương đối, số dòng nguồn các giao diện hàm, nguyên chữ ký từng hàm được định nghĩa, struct/enum mà nó khai báo và các include trực tiếp. Lấy từ nội dung thực tế; không tự đoán chữ ký. Phân biệt Script kiểm với mã sử dụng trong bot.
2. Với mỗi khối, ghi các dữ liệu nhận vào/ghi ra và hàm nào nó gọi. Chỉ nêu thứ tự gọi khi đọc được rõ trong thân hàm. Tách dữ liệu đầu vào đã chụp với dữ liệu tham chiếu đọc lại. Liệt kê chỗ nhiều struct đang đại diện cùng loại dữ liệu nhưng CHƯA có bằng chứng dùng chung cùng ô trạng thái.
3. Lập bảng các liên kết ĐÃ có mã trực tiếp, kèm file/dòng nơi gọi và tên hàm đích. Tiếp đó lập danh sách các liên kết CHƯA có chương trình gọi/giá trị đầu vào/chủ thể giữ trạng thái. Đừng biến tên giống nhau thành bằng chứng các trường bằng nhau, đừng tự đổi kiểu hoặc ghép cấu hình bằng cách sao chép sớm.
4. Nhóm công việc còn thiếu để tạo chương trình chính: khởi động, mỗi lần nhận giá, đổi nến, chuẩn bị chiến lược, điều kiện vào, đặt/sửa/hủy/đóng, hiển thị, lưu/khởi động lại/thoát/lỗi. Nhóm nào thiếu bằng chứng luồng thì ghi chưa đủ để viết, chỉ rõ đầu vào/thứ tự còn thiếu. Không phát minh quy tắc hoặc viết EA rỗng để gọi là đã ghép.
5. Đề xuất các phần viết mã độc lập tiếp theo CHỈ khi nguồn hiện tại đã xác định trọn giao diện và hành vi. Mỗi phần ghi đầu vào/đầu ra, phụ thuộc và cách kiểm. Nếu thiếu thuật toán thì ghi lại để bên quản lý phân tích tiếp trước khi giao.

JSON gồm `bot`, `modules` (path, functions[{name,signature,line}], types, includes, direct_calls[{caller,callee,line}], reads, writes, unresolved), `confirmed_links`, `missing_links`, `next_implementation_parts`, `whole_bot_complete:false`. Các khối sản phẩm có nguồn chính phải xuất hiện mỗi tệp đúng1lần; đề xuất đang kiểm có trạng thái riêng và không gọi là đã ghép. Không tự tạo số phần trăm hoàn thành hoặc khẳng định mã đã chạy đúng. INTEGRATION.md viết tiếng Việt ngắn, bảng dễ đọc; JSON giữ đủ chi tiết.

Mục tiêu là bảng nối có thể kiểm bằng tên tệp/chữ ký/dòng, giúp giao phần lớn việc viết mã tiếp theo, không thay công việc viết mã bằng báo cáo chung chung. SUMMARY nêu số tệp đã đọc và giới hạn chưa kiểm; không tuyên bố đã biên dịch/chạy nếu chưa làm.

