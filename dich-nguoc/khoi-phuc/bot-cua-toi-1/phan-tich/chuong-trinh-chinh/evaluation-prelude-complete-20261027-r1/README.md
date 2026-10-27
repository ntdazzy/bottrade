# Đầu đánh giá bot 1 đã so qua giờ giao dịch và cập nhật giá

**1.594/1.594 ca khớp**, so 30 giá trị và toàn bộ thứ tự/đối số/chuỗi
UTF-16/NULL của dịch vụ. Hai bản biên dịch API/bộ kiểm đều 0 lỗi/0 cảnh báo.
Lượt `b1-evaluation-prelude-20261027-r1` chạy nguyên mã gốc bot1 từ
`18aa0` tới trước `18eb1`, gồm cả các nhánh báo/kiểm phiên ngoài khoảng
liên tục. Đi qua 744 lệnh máy trong thân hàm và 19 mốc bắt buộc.

Đầu vào trực tiếp chỉ có chỉ số chiến lược 32bit; không thêm cờ người
gọi DL của bot3. Giữ thứ tự đọc giờ máy chủ, đổi lịch, chọn tên mã,
kiểm thông tin7, ghi cờ trước thông báo, báo đủ7ngày, kiểm tối đa10phiên,
hủy tên mã tạm, lấy giá/tính chênh lệch rồi lấy lịch hiện tại.
Phiên0 không tìm thấy khác với các phiên sau không tìm thấy; cả hai
vẫn tiếp tục lấy giá. Không sửa các điều kiện giờ kết thúc gần nửa đêm.

Bộ ca có lịch không ghi khi báo lỗi, dữ liệu giá/lịch cũ, NULL/chuỗi
rỗng, tên mã/chuỗi giờ tiếng Việt dài, phiên0..9, các biên số64bit,
NaN/vô cực/±0 khi tính chênh lệch. Dùng lại bộ đầu vào của bot3 để giữ
cùng phạm vi kiểm; đầu ra mong đợi chạy từ thân gốc bot1 riêng.

Các câu trả lời dịch vụ MT5, lịch ban đầu và cấp chuỗi thành công
được cấp. Đây chưa phải chạy EA hoàn chỉnh trên thị trường, chưa kiểm
lỗi cấp bộ nhớ, mọi nhánh từ `18eb1`, menu/hiển thị/khởi động lại hoặc
lưu trạng thái. Ngữ cảnh thanh ghi truyền qua phần sau tới quản lý vị
thế còn phải kiểm trong luồng nối; không dùng kết quả này để tự chốt
cờ của đường vé0. Không sửa EX5 gốc hay cờ bản quyền.

[Đặc tả trước khi viết mã](SPEC.md), [mã kiểm gốc/chuỗi](native-evidence.json),
[nguồn](../../../source/MQL5/Include/bot-cua-toi-1/Bot1EvaluationPrelude.mqh),
[bộ kiểm](../../../tests/check-evaluation-prelude.py),
[kết quả](../../../bang-chung/kiem-quan-ly-vi-the/b1-evaluation-prelude-20261027-r1/comparison.json).
