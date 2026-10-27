# Đầu đánh giá bot 3 đã nối qua giờ giao dịch và cập nhật giá

**1.594/1.594 ca khớp**, so 31 giá trị và toàn bộ lời gọi dịch vụ theo
thứ tự, gồm các đối số và chuỗi UTF-16/NULL. Hai bản dựng API và bộ
kiểm đều 0 lỗi/0 cảnh báo. Đúng các nguồn đã được ghi SHA trong lượt
`b3-evaluation-prelude-20261027-r1`; chưa có EA hoàn chỉnh.

Mã gốc chạy liên tục từ `20ef0` tới trước `212ff`: đọc giờ máy chủ,
đổi lịch, chọn tên mã, kiểm cờ/in các phiên khi cần, kiểm ngày/phiên,
hủy tên mã tạm, lấy giá, báo lỗi giá nhưng tiếp tục, tính chênh lệch
và lấy lịch hiện tại. Cả các nhánh ngoài khoảng liên tục được chạy;
không chèn kết quả vào helper ghép/hủy chuỗi hoặc thay nhánh giữa chừng.
Đã đi qua 744 lệnh máy khác nhau trong thân gốc và 19 mốc bắt buộc.

Giữ các trường hợp riêng của bản gốc:

- Phiên đầu không tìm thấy cho cờ 0; các phiên sau không tìm thấy
  hoặc hết mười phiên cho cờ 1. Cả hai đều tiếp tục lấy giá.
- Ngày 0/6 bỏ gọi kiểm phiên sau phần thông báo, đặt cờ 1.
- Giờ kết thúc bằng 0/âm hoặc từ 86.340 đến 86.400 được điều chỉnh
  thành 86.400. Giờ kết thúc lớn hơn 86.400 dùng nhánh qua nửa đêm
  như mã gốc, kể cả khi hai đầu sau chia dư không đảo nhau.
- Thông báo đầu dùng ba đối số; mỗi ngày dùng một dòng đầy đủ, tối
  đa phiên 0..9. Chỉ thêm ` none` khi lần gọi phiên 0 trả false.
- Chọn tên mã thay thế cho thông báo/kiểm phiên, nhưng lấy giá bằng
  tên mã gốc. Phân biệt NULL, chuỗi rỗng và chuỗi tiếng Việt dài.
- Khi dịch vụ giá/lịch không ghi, dữ liệu cũ được giữ. Có số vô cực,
  NaN và ±0 khi tính chênh lệch; so nguyên các bit số thực.

Đây là phép so thành phần có cấp dữ liệu: giờ, lịch, thông tin MQL,
các phiên, chuỗi giờ, giá và cấp chuỗi thành công. Tám trường lịch do
bộ ca cấp để kiểm cả lỗi dịch vụ, không suy từ giờ máy chủ trong lượt
này. Riêng bước đổi lịch thật đã được so ở bộ 432 ca trước đó.
Lỗi cấp bộ nhớ, phần sau `212ff`, điều kiện giao dịch còn lại, menu,
khởi động/lưu trạng thái và chạy hai EA đầy đủ vẫn chưa được chứng minh.
Không sửa EX5 gốc hay cờ bản quyền.

[Đặc tả trước khi viết mã](SPEC.md), [mã kiểm gốc/chuỗi](native-evidence.json),
[nguồn](../../../source/MQL5/Include/bot-cua-toi-3/Bot3EvaluationPrelude.mqh),
[bộ kiểm](../../../tests/check-evaluation-prelude.py),
[kết quả](../../../bang-chung/kiem-quan-ly-vi-the/b3-evaluation-prelude-20261027-r1/comparison.json).
