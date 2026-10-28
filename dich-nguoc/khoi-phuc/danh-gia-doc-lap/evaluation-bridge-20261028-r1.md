# Nối chuẩn bị → đánh giá

Đã thêm hai tệp nối dùng chung:

- `Bot1EvaluationBridge.mqh`
- `Bot3EvaluationBridge.mqh`

Sau mỗi lần chuẩn bị chiến lược, nối này chép các trường đã có bằng chứng
trực tiếp vào cùng các đối tượng mà hàm đánh giá nhận bằng tham chiếu:

| Nhóm | Trường được nối |
|---|---|
| Thực thi | mã chiến lược, mã gốc, mã giá, giá mua/bán, giới hạn dừng, giới hạn đóng băng, độ trượt |
| Khôi phục lệnh | khoảng dừng, khoảng chốt, thời điểm hết hạn, bình luận, hết hạn ảo |
| Vòng vào lệnh | kiểm vốn, bỏ dừng/chốt thật, khung xác nhận, độ rộng cũ/mới, độ lệch, thời hạn, khoảng cách và vùng gần |
| Bộ nhớ nến/mức | khung, độ rộng phụ, chỉ số nến, độ lệch phụ |

Các ô giới hạn dừng/đóng băng được đối chiếu với `0x66a70/0x67468`
(bot 1) và `0x73ab0/0x744a8` (bot 3). Mã chiến lược dùng `context.magic`;
mã gốc dùng riêng `magic_base`. Không tạo lại các đối tượng trong từng vòng.

Kiểm mới:

- Bộ chuẩn bị liên tục: bot 1 **432/432**, bot 3 **2.106/2.106** ca khớp
  mã gốc và nguồn MQL5.
- Tệp API nối của cả hai bot: **0 lỗi, 0 cảnh báo**.
- Toàn bộ header hiện có sau khi thêm nối: **0 lỗi, 0 cảnh báo**.

Phạm vi này chưa phải EA hoàn chỉnh. Còn thứ tự OnInit đầy đủ, cổng kiểm
quyền dùng, sự kiện OnTick, phần điều phối ngoài còn lại, giao diện/tài
nguyên và chạy đối chiếu hai EA hoàn chỉnh.
