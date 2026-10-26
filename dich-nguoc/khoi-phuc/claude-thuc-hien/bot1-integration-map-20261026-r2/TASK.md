# Cập nhật bảng nối theo nguồn mới nhất bot1

Tiếp tục từ bảng nối r1 vừa làm. Chỉ ghi integration-map.json, INTEGRATION.md, SUMMARY.md trong thư mục đề xuất r2 này; giữ nguyên r1 làm mốc. Opus5.5max, ultracode. Không shell, không sửa nguồn chính/Git/MT5, không tạo tác tử. Không cần đọc lại các header chưa thay đổi.

Đọc lại CHÍNH tệp `dich-nguoc/khoi-phuc/bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/Bot1PendingSubmission.mqh` và hai Script PendingSubmissionCheck/PendingSubmissionApiCompile hiện hành. Bên quản lý vừa ghép nguồn khối này và kiểm riêng; có cả hàm `Bot1SubmissionDifference`. Bảng r1 đang thiếu hoặc dùng phiên bản cũ của khối này. Không lấy bản đề xuất cũ thay cho nguồn chính.

Yêu cầu:
- Dùng r1 làm nền, cập nhật chữ ký/dòng/calls/reads/writes của khối mới; thêm nó vào modules nguồn chính với trạng thái rõ. Cập nhật đủ liên kết và mọi chỗ dẫn dòng tới các hàm của khối.
- Đổi đề xuất cũ thành lịch sử, không gọi tệp nguồn chính hiện tại là chưa ghép. Phân biệt đã có header với đã nối chương trình chính: hiện chưa có EA đầy đủ.
- Cập nhật đếm tổng headers/functions/struct/Script và các đầu chuỗi chưa có nơi gọi. Hiện cây Include có44header. Không tự thêm/bớt chức năng để làm số khớp; liệt kê từ tệp thực tế.
- Sửa các missing_links về MarginGuard/ValidateVolume/đặt lệnh để phản ánh nơi gọi mới. Vẫn giữ thiếu nơi gọi SubmitPendingAfterPrice, nguồn giá cơ sở, cài đặt và chủ thể giữ trạng thái ở chương trình chính.
- JSON phải có `whole_bot_complete:false` ở cấp ngoài cùng và đủ `modules,confirmed_links,missing_links,next_implementation_parts`. Giữ các trường chi tiết hữu ích của r1. Không placeholder hoặc dấu đánh chỗ còn thiếu trong bản cuối.
- Chỉ đề xuất phần ghép tiếp khi giao diện và hành vi đã có căn cứ; không lấy biểu đồ gọi hàm thay cho thuật toán còn thiếu.

Không tự chạy kiểm hoặc công bố logic đã khớp; Codex kiểm bảng bằng nguồn rồi đối chiếu chức năng riêng. SUMMARY ghi rõ thay đổi r1→r2 và phạm vi đã đọc lại.
