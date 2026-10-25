Read AGENTS.md first. Đây là công việc khôi phục nguồn MQL5 của bot giao dịch 3 thuộc chủ dự án. Codex đã phân tích bằng chứng gốc và chốt mô tả; không yêu cầu bạn gỡ khóa hay vượt biện pháp bảo vệ.

Đọc duy nhất phần chung và phần C tại:
dich-nguoc/khoi-phuc/bot-cua-toi-3/phan-tich/dong-vi-the/management-virtual-20261025-r1/contract.md
Có thể đọc nguồn Include/bot-cua-toi-3 hiện hành và bản Prelude đã giao:
dich-nguoc/khoi-phuc/claude-thuc-hien/bot3-management-prelude-20261025-r2/Bot3ManagementPrelude.mqh

Viết hàm của phần C hoàn chỉnh vào Bot3ManagementSlippageStop.mqh; include Bot3ManagementPrelude.mqh, include guard riêng. 
Chỉ viết trong dich-nguoc/khoi-phuc/claude-thuc-hien/bot3-management-slippage-20261025-r1/.
Thêm SUMMARY.md: quy tắc đã giữ, điều còn chưa kiểm, phụ thuộc. Không viết ngoài thư mục, không Bash/PowerShell, không đọc EX5/C/mã máy. Không thay đổi mô tả, không đoán hoặc thêm luật. Nếu mô tả còn thiếu, ghi điểm thiếu. Không tự nói đã biên dịch hay so bản gốc. Giao tệp thật, không chỉ dán mã trong trả lời. Các phiên khác viết hai phần còn lại cùng lúc, không đụng tệp của họ.
