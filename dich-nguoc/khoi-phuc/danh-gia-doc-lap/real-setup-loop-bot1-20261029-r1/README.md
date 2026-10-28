# Chuẩn bị và thống kê qua nhiều chiến lược — bot 1

Lượt `b1-real-setup-loop-20261029-r2`: **88/88 ca khớp**, gồm
**457 lần chuẩn bị chạy thật**. Mã gốc chạy từ `0x12424` tới
`0x16730`, giữ trạng thái giữa các chiến lược. Nguồn MQL5 dùng
`Bot1RunEnabledStrategies` và `Bot1SetupEvaluateAndUpdateStatistics`.

| Phần | Phạm vi đã kiểm |
|---|---|
| Tám cổng chọn | Tắt hết, bật hết, từng chiến lược, bỏ từng chiến lược, xen kẽ và đổi cờ sau lời gọi |
| Nạp cấu hình | Nguyên các đoạn gốc, giữ số ngẫu nhiên qua nhiều lần; 24 tổ hợp hữu hạn về hệ số, hạt giống và cờ |
| Ghi chú/mã nhận diện/đổi tiền | Nguyên thân ngữ cảnh và đổi tiền; không đặt lại các giá trị sau mỗi chiến lược |
| Chuẩn bị | Gọi thật `0x7500` từ từng đoạn và quay về tự nhiên; không nhảy qua thân hàm |
| Đánh giá | Bộ ghi tại `0x18aa0`; chưa chạy phần giao dịch |
| Thống kê | Chạy nguyên đoạn sau đánh giá; bật/tắt theo cờ giờ thay đổi; so đủ 8 số đếm, 8 tổng và 8 trung bình |
| Lấy lịch sử | Cấp kết quả/số đếm tại `0x1efa0`; chưa chạy thân lịch sử trong lượt này |

Trước mỗi lần đánh giá so **127 giá trị**, toàn bộ chuỗi ghi chú
và mảng chỉ báo theo thứ tự vật lý. Cuối mỗi ca so các cờ còn lại,
số lần lấy lịch sử và toàn bộ bảng thống kê. So từng byte, không
nới sai số. Kết quả hai phía cùng mã SHA-256 trong `verification.json`.

Chỉ khởi tạo đầu ca; không đặt lại thanh ghi, mảng hoặc số ngẫu
nhiên giữa các chiến lược. Thanh ghi gọi chép chuỗi `RBP=base+0x5c0`
được cấp ở đầu, theo đoạn gọi đã chốt. Cờ dừng lỗ ảo giữ nguyên.
Đoạn chọn mã/dọn bảng phía trước đã có phép kiểm riêng, chưa chạy
liền với các thân chuẩn bị trong lượt này.

## Sai lệch đã tìm và xử lý

Lượt `r1` có 86/88 ca lệch do bộ kiểm, không phải luật bot:

- Ép byte `0x6a600` về 0 để bỏ qua dọn bảng làm đổi chế độ chuẩn bị.
  Đã bắt đầu đúng tại vòng `0x12424`, giữ nguyên byte đầu vào.
- Bộ cấp dữ liệu chỉ báo ghi bằng chỉ số logic khi mảng đã đảo
  chiều. Đã ghi theo thứ tự vật lý và giữ cờ mảng; phần xuất dữ
  liệu cũng so theo cùng thứ tự vật lý.

Bằng chứng và hai tệp mã của lượt lỗi vẫn giữ trong thư mục `r1`.
Lượt biên dịch đầu cũng phát hiện tên biến cục bộ trùng tên trạng
thái chuẩn bị; đã sửa riêng bộ sinh script. Không sửa nguồn bot.

`b1-real-setup-loop-check-20261029-r3`: **0 lỗi, 0 cảnh báo**.
Kiểm độc lập không thấy lỗi cần sửa trong phạm vi này. Bộ nguồn
110 tệp `.mqh` vẫn giữ nguyên so với lần biên dịch sạch trước đó.

## Lặp lại và phần còn thiếu

`kiem-vong-chuan-bi-that-bot-1.py`: `generate`, `prepare RUN`,
`mql5 RUN --build BUILD`, `original RUN`, `compare RUN`. Dùng tên
lượt mới và MT5 bot 1 riêng. MQL5 chạy trước bản gốc.

Còn ghép thân đánh giá/lịch sử thật, phần chọn mã/dọn bảng phía
trước, đoạn sau `0x16730`, các trường hợp không hữu hạn/lỗi, giao
diện và EA đầy đủ. Phản hồi dịch vụ/cấp phát thành công được cấp;
không gửi lệnh thật và không chạy quyền dùng. Đây chưa phải chạy
cặp hai EA, cũng không chứng minh hoàn thành toàn bot.

[Số liệu](verification.json), [danh sách tệp](../real-setup-loop-bot1-20261029-r1-manifest.txt).
