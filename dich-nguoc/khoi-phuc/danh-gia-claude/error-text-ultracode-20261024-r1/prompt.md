Đây là dự án phục hồi mã nguồn bot MT5 của chủ dự án, đã xác nhận quyền
sở hữu và mất nguồn. Chúng tôi giữ nguyên EX5 gốc, không thay khóa/giới
hạn dùng, và chỉ kiểm trong MT5 riêng, tắt giao dịch. Yêu cầu này chỉ
là đánh giá độc lập một phần mã đã viết, không yêu cầu vượt biện pháp
bảo vệ. Nếu không thể đánh giá, hãy nêu rõ giới hạn; không cần đổi phạm vi.

Hãy chỉ đọc các tệp sau, không sửa tệp, không chạy shell hoặc giao dịch:

- AGENTS.md
- dich-nguoc/khoi-phuc/PHAN-TICH-CHUOI-LOI-BOT-1-3.md
- dich-nguoc/khoi-phuc/bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/Bot1TradeErrors.mqh
- dich-nguoc/khoi-phuc/bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/Bot3TradeErrors.mqh
- dich-nguoc/khoi-phuc/bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/Bot1TradeErrorsCheck.mq5
- dich-nguoc/khoi-phuc/bot-cua-toi-3/source/MQL5/Scripts/bot-cua-toi-3/Bot3TradeErrorsCheck.mq5
- dich-nguoc/khoi-phuc/cong-cu/kiem-chuoi-loi-bot-1-3.py
- dich-nguoc/khoi-phuc/bot-cua-toi-1/bang-chung/kiem-chuoi-loi/errors-20261024-r2/analysis.json
- dich-nguoc/khoi-phuc/bot-cua-toi-3/bang-chung/kiem-chuoi-loi/errors-20261024-r2/analysis.json

Kiểm: tăng bộ đếm uint32 trước mọi nhánh và quay về 0, int32 có dấu ở
nhánh mặc định, toàn bộ 92 mã/chuỗi phải chính xác, phần so kết quả có
độc lập với mã mới không, thay chuỗi cũ có thể bị bỏ sót chỗ nào, kiểm
biên dịch/nguồn/kết quả có đủ chắc không. Nêu lỗi có bằng chứng file:dòng,
mức ảnh hưởng và cách kiểm. Phân biệt lỗi đã chứng minh với giới hạn
chưa kiểm; không gọi 1.725 ca thành toàn bộ bot đạt 100%.

Trả lời tiếng Việt ngắn gọn. Nếu không có lỗi đã chứng minh, nêu rõ
phạm vi đã đọc và các giới hạn còn lại. Nguồn này chưa được ghép vào EA.
