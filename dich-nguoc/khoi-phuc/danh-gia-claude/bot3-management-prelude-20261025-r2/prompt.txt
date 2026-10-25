# Tiếp tục viết phần đầu bot 3 sau khi sửa mô tả

Vẫn cùng bối cảnh khôi phục nguồn bot của người dùng; không đổi mục
tiêu hoặc yêu cầu vượt chặn. Lượt trước PID20928 đã mất tiến trình,
response.json trống và chưa tạo mã. Đọc AGENTS.md và mô tả mới:
`dich-nguoc/khoi-phuc/bot-cua-toi-3/phan-tich/dong-vi-the/management-prelude-20261025-r2/contract.md`.
Mô tả cũ có ba lỗi đã chỉ rõ; hãy chỉ dùng bản r2. Không đọc lại toàn
bộ dự án. Bạn không phân tích EX5/C/capture; Codex đã làm bước đó.

Viết ngay `Bot3ManagementPrelude.mqh` và `SUMMARY.md` trong thư mục
TASK này. Chỉ Read/Grep/Glob/Edit/Write; không lệnh, Git, MT5 hoặc kỹ
năng lồng nhau, không ghi ngoài thư mục này. Nguồn chính chưa được sửa.

Ba hàm và struct đúng mô tả: Bot3ReadManagementPosition,
Bot3FillManagementInitialLevels, Bot3CloseManagementCandle. Dùng
Bot3PriceLevels/Bot3PositionModify/Bot3PositionClose có sẵn. Đặc biệt
đóng theo nến phải dùng Bot3TryClosePosition với đủ refs/thresholds,
không thay bằng Bot3ClosePosition. Giữ lần đọc iTime đầu bằng byte
shift được truyền, đọc khung lại ở từng API và ba nhóm chạy riêng.
Không thêm vòng quản lý đầy đủ, chức năng chưa rõ hay lớp trừu tượng.

Đầu ra mới chỉ là ứng viên, ghi rõ chưa biên dịch/chưa chạy kiểm.
Codex sẽ chép và tự biên dịch/so với mã gốc. Không tự nêu đạt 100%.
