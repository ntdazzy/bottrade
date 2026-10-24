Đây là dự án phục hồi mã bot MT5 của chủ dự án đã xác nhận quyền sở
hữu và mất nguồn. EX5 gốc giữ nguyên; không thay khóa/giới hạn dùng.
Chỉ dùng MT5 riêng, tắt giao dịch, các lời gọi gửi được thay bằng dữ
liệu kiểm. Tôi cần đánh giá bộ kiểm do chúng tôi tự viết, không yêu
cầu vượt biện pháp bảo vệ. Nếu không thể đánh giá, nêu rõ giới hạn.

Chỉ đọc, không sửa tệp và không chạy shell/MT5. Các tệp cần đọc:

- AGENTS.md
- dich-nguoc/khoi-phuc/PHAN-TICH-CHUOI-DAT-LENH-BOT-1-3.md
- dich-nguoc/khoi-phuc/cong-cu/kiem-chuoi-dat-lenh-bot-1-3.py
- dich-nguoc/khoi-phuc/cong-cu/kiem-hang-doi-bot-1-3.py
- dich-nguoc/khoi-phuc/cong-cu/kiem-gui-lenh-bot-1-3.py
- dich-nguoc/khoi-phuc/bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/Bot1PipelineApi.mqh
- dich-nguoc/khoi-phuc/bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/Bot1PendingPipelineCheck.mq5
- dich-nguoc/khoi-phuc/bot-cua-toi-3/source/MQL5/Scripts/bot-cua-toi-3/Bot3PipelineApi.mqh
- dich-nguoc/khoi-phuc/bot-cua-toi-3/source/MQL5/Scripts/bot-cua-toi-3/Bot3PendingPipelineCheck.mq5
- dich-nguoc/khoi-phuc/bot-cua-toi-1/bang-chung/kiem-chuoi-dat-lenh/pipeline-20261024-r1/comparison.json
- dich-nguoc/khoi-phuc/bot-cua-toi-3/bang-chung/kiem-chuoi-dat-lenh/pipeline-20261024-r1/comparison.json (nếu chưa có, ghi chưa có)
- Có thể đọc các .mqh hiện hành được nạp trong hai chương trình kiểm.

Mục tiêu rà:

1. Bộ kiểm có thật để hàm tạo yêu cầu/kiểm cách khớp/gửi/thông báo
   chạy hết hay vẫn có chỗ trả sẵn kết quả của cả hàm tạo lệnh?
2. Theo dõi return-address và RSP có nhầm lời trả bên trong không?
3. Có so đủ 35 trường, 4 chuỗi trước/sau mỗi call, 500 số của hai bảng,
   trạng thái, thứ tự/đối số có kiểu và lỗi cuối không?
4. Có vòng tự lấy kết quả từ nguồn mới làm đáp án của thuật toán gốc
   không? Phân biệt API được cấp dữ liệu với thuật toán phải tự chạy.
5. Lỗi gửi được cấp đúng lúc lời gọi gửi kết thúc, lỗi thuộc tính ở
   API trả sai; thay dữ liệu hàng đợi chỉ sau builder trả. Có chỗ sai
   thứ tự hoặc mất trạng thái giữa nhiều lần gọi không?
6. Kiểm mã nguồn, bản biên dịch, chuỗi bằng chứng và độ bao phủ có điểm
   yếu gì? Tránh gọi số ca đạt là toàn bot đạt 100%.

Nêu lỗi đã chứng minh bằng file:dòng, ảnh hưởng và cách kiểm; tách
giới hạn chưa kiểm khỏi lỗi. Chưa có EA chính đầy đủ, kết quả nơi
giao dịch, toàn bộ cài đặt/hiển thị/khởi động lại hoặc lỗi cấp bộ nhớ.
Không cần đọc các cases.json rất lớn: dùng hàm tạo ca và biên nhận.

Trả lời tiếng Việt ngắn gọn. Tôi sẽ đối chiếu lại mọi nhận xét bằng
bằng chứng, không dùng đánh giá này thay phép so với bản gốc.
