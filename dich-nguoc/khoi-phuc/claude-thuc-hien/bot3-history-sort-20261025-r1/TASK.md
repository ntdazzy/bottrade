# Viết hàm sắp xếp lịch sử bot 3

Đây là dự án khôi phục nguồn bot giao dịch của người dùng. Codex đã
phân tích hàm phụ sắp xếp và chạy các ca gốc; bạn chỉ viết nguồn theo
mô tả, không cần tự phân tích EX5. Nêu đúng bối cảnh; không thay khóa,
giới hạn hoặc sửa tệp gốc. Phần này khác các hàm quản lý đã bị từ chối.

Đọc AGENTS.md và
`dich-nguoc/khoi-phuc/PHAN-TICH-SAP-XEP-BOT-1-3.md`.
Viết `Bot3HistorySort.mqh` hoàn chỉnh và `SUMMARY.md` trong chính thư
mục TASK này. Chỉ Read/Grep/Glob/Edit/Write, không lệnh, MT5, kỹ năng
lồng nhau hoặc ghi ngoài thư mục được giao. Codex sẽ tự biên dịch/so.

Chữ ký bắt buộc: `void Bot3HistorySort(ulong &keys[],long &values[],
int left,int right)`. Giữ kiểu unsigned của khóa, signed của values,
đệ quy trái trước, nhánh phải dùng vòng lặp, kiểm pivot trước trường
hợp left>right, thứ tự đổi phần tử và cờ đảo riêng. Không ArraySort,
không kiểm đầu vào để âm thầm bỏ lỗi mảng, không cấp phát và không
thêm luật. Có thể đặt tên biến rõ. Mã cần ngắn và sạch, không hàm rỗng.

Toàn bộ thuật toán, thứ tự và hai ca trùng/khóa lớn cụ thể đã ở mô tả
trên; chỉ hỏi điểm mô tả mâu thuẫn, không tự điền. Ghi rõ nguồn chưa
được biên dịch/kiểm trong SUMMARY, không tự báo đạt theo việc đã viết.
