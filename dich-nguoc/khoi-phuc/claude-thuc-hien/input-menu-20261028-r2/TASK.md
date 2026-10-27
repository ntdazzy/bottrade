# Khai báo cài đặt MQL5 và bộ ghi giá trị

Viết mã theo mô tả đã chốt dưới đây. Đây là giao diện cài đặt của hai chương trình MQL5. Chỉ đọc tệp JSON cài đặt và các header liên quan được chỉ ra; không cần tự tìm thuật toán giao dịch. Không sửa tệp, chạy shell hoặc gọi tác tử khác. Trả mã đầy đủ trong phản hồi.

Nguồn dữ liệu: `dich-nguoc/khoi-phuc/menu-bot-1-3/luot-20261023-r1/verified-menu.json`.
Mỗi phần tử `bots` có `bot`, danh sách `settings` theo `order`, và `menus`. Cần tạo đủ 72 cài đặt bot 1 và 80 cài đặt bot 3, kể cả `lijntje` và mọi chuỗi tiêu đề. Mỗi hàng có tên, mặc định, nhãn nhìn thấy, dạng dữ liệu; `menus` có thứ tự lựa chọn, số lưu và nhãn.

Hãy trả MỘT tệp Python 3 chỉ dùng thư viện chuẩn, tên `tao-khai-bao-cai-dat-bot-1-3.py`. Khi chạy từ bất kỳ thư mục nào, nó xác định gốc `khoi-phuc` qua vị trí chính nó trong `cong-cu`.

Đầu ra cho mỗi bot N:

1. `bot-cua-toi-N/source/MQL5/Include/bot-cua-toi-N/BotNInputs.mqh`: include guard. Trước các input, khai báo enum riêng cho mỗi mục có `menus`, tên kiểu và hằng phải có tiền tố BotN để tránh trùng. Giữ thứ tự lựa chọn và số của JSON; dùng chú thích thành viên enum cho đúng nhãn. Tên kiểu gốc không cần giữ vì chưa biết, tên input bắt buộc giữ nguyên. Các mục còn lại: bool -> bool, double -> double, string -> string, integer_or_enum không có menu -> int. Mặc định chuỗi phải giữ chính xác cả dấu cách cuối; escape dấu nháy/ký tự điều khiển để hợp lệ MQL5. Các input giữ đúng thứ tự order, tên và giá trị mặc định. Dùng chú thích cuối dòng bằng visible_label khi có; nếu nhãn chỉ đọc được một phần thì giữ đúng phần quan sát được, không tự bổ sung chữ. Không thêm input hoặc luật giao dịch khác.
2. `Scripts/bot-cua-toi-N/BotNInputsCheck.mq5`: input string `CheckRun` bổ sung chỉ dùng trong script kiểm (không sửa header sản phẩm). Include header. OnStart kiểm CheckRun khớp `[a-z0-9-]{1,48}` bằng vòng ký tự, mở `botN-inputs\\RUN\\values.bin` dùng FILE_WRITE|FILE_BIN. Ghi magic int32 0x494e5031, version int32 1, count int32 72/80. Với từng input theo thứ tự: ghi tên chuỗi UTF-16 (int32 độ dài ký tự rồi FileWriteString có độ dài), ghi loại int32: bool=1, int/enum=2, double=3, string=4. bool: ghi int32 0/1; int/enum: ghi int32 đúng số; double: FileWriteDouble; string: độ dài UTF-16+FileWriteString. Giá trị đọc từ biến input thực, không ghi literal mặc định. Đóng file và return 0; return mã khác khi tên lượt sai hoặc mở tệp thất bại. Không mạng, giao dịch, biểu đồ hay DLL.

Yêu cầu cho Python: kiểm schema/counter/order/tên trùng, boolean/integer/double/string hợp lệ; chỗ nào chưa có bằng chứng thì lỗi rõ thay vì đoán. Xác minh SHA-256 của hai default .set khớp `defaults_set_sha256` trước tạo mã. Dùng UTF-8 không BOM và LF cho MQL5. Có chế độ `--check` chỉ so nội dung sinh ra với tệp trên đĩa, exit khác 0 khi lệch; mặc định ghi các tệp trên. Không chỉnh JSON hoặc bằng chứng nguồn.

Chỉ xuất mã Python trong một khối ```python đầy đủ, sau đó tối đa 5 dòng lưu ý. Người quản lý sẽ tự biên dịch, chạy các bộ .set và so kết quả; không tự khẳng định đã kiểm.
