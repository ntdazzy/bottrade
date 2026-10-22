# Chuyển dự án ngày 21/10/2026

Đích: `C:\Users\NTD\Desktop\Bot Market Demo`.

- Đã chuyển 485 tệp được chọn từ 483 tệp nguồn; hai công cụ kiểm có thêm
  bản giữ nguyên để kiểm lại biên nhận cũ.
- Đã gỡ 483 tệp nguồn sau khi đối chiếu mã kiểm tra với bản mới.
- Giữ nguyên 402 tệp người dùng đã có ở thư mục đích, gồm 17 tệp EA gốc.
- Tạo 15 hồ sơ bot. Mỗi hồ sơ có README và dữ liệu phân tích đã có.
  Twister có thêm mã hiện hành, phép kiểm và bằng chứng giao dịch.
- Không chuyển MT5, Ghidra, JDK, thư viện đã cài, bộ cài tải về, tài khoản,
  bản C cũ trùng nhau, bản xuất dở và các lượt kiểm thất bại.
- Phần bị loại và môi trường cũ vẫn ở thư mục nghiên cứu của BotTradeEA.
  Thư mục mới chỉ giữ những tệp đã chọn; không xóa toàn bộ môi trường cũ.

## Kiểm tra sau khi gỡ tệp nguồn

- 17 EA gốc khớp mã tệp.
- 7 biên nhận biên dịch và toàn bộ tệp nguồn đã biên dịch còn kiểm được
  từ đường dẫn mới, qua bảng ánh xạ đường dẫn lịch sử.
- 400/400 giá trị khởi tạo và 800/800 ca bộ lọc tính lại vẫn khớp.
- Năm lượt máy thử đã lưu còn trùng 31, 533, 169, 183 và 123 dòng hoạt động
  có thời gian tương ứng. Đây là kiểm lại dữ liệu đã lưu, không chạy MT5 mới.
- Công cụ tạo ca tham số đã chạy thử từ đường dẫn mới; tệp thử đã dọn.
- 7 tệp Python và 2 tệp PowerShell qua kiểm cú pháp. Các liên kết mở
  hồ sơ bot/EA/mã/bằng chứng đều trỏ tới vị trí có thật.

`manifest.json` lưu đường dẫn nguồn cũ, vị trí mới và mã kiểm tra. Nội dung
bằng chứng lịch sử giữ nguyên. Chín tệp công cụ/cấu hình được sửa đường
dẫn có cả mã trước và sau khi sửa trong biên nhận này.

Mở [README gốc của dự án](../../../README.md) để bắt đầu. Công cụ không
phụ thuộc đường dẫn cũ; muốn biên dịch hoặc chạy MT5 mới cần chuẩn bị môi
trường riêng như [hướng dẫn](../../tools/README.md).
