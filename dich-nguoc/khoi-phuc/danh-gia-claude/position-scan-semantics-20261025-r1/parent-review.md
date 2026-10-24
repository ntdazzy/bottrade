# Đối chiếu danh sách của Claude

Đã kiểm nhật ký: 16 yêu cầu đều dùng `claude-opus-5-5`, mức `max`.
Đã bật cài đặt Ultracode, nhưng lượt này không có quy trình hoặc
agent Ultracode riêng. Claude chỉ đọc C/lệnh máy và phần mô tả đóng;
không coi báo cáo này là đánh giá nguồn MQL5 mới hoặc kết quả chạy.

Các điểm đã tự đối chiếu: tổng..0; tám/15 mã; cộng 32 bit rồi mở rộng
có dấu; đọc lại mã vị thế và chuỗi mục tiêu; so loại đủ 64 bit; giữ
lời đọc khối lượng; đọc lại vé sau đó rồi gọi nguyên phần kiểm đóng.
Nguồn MQL5 và các phép so r1 giữ các điểm này. R2 chạy lại riêng sau
khi sửa bộ đọc tệp của chương trình kiểm.

Địa chỉ được tính bằng chương trình, lấy địa chỉ đầy đủ trừ đúng
`code_base`; không dùng nhãn do agent tự đoán từ đuôi số. Hai nhãn
vai trò của hằng vùng nhớ nội bộ chưa dùng để thay thuật toán.

Nguồn hai ô giá được bổ sung sau báo cáo này: bốn nơi mỗi bot có đủ
lệnh nạp vùng giá và gọi đúng MT5, nối với lệch trường +8/+16 đã đối
chứng. Đây là bằng chứng hai ô thuộc vùng lưu giá gần nhất; chưa
chứng minh thứ tự cập nhật hoặc mọi lần ghi gián tiếp.

Claude nêu đúng giới hạn: chưa có nơi gọi toàn EA, trạng thái chọn và
mã lỗi MT5 thật, mọi tham số và lỗi cấp bộ nhớ. Không thay chúng bằng
suy đoán hoặc dùng số ca đạt để công bố 100% bot.
