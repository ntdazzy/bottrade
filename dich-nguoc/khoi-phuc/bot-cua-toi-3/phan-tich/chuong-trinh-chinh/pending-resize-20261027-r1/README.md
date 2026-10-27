# Vòng tạo lại lệnh chờ sau thay đổi khối lượng

**278/278 ca khớp từng byte**, đọc lại cấu trúc từng ca cũng278/278.
Hai bản dựng API/bộ kiểm đều0lỗi/0cảnh báo. Chưa là EA đầy đủ.
Lượt hiện hành `b3-eval-resize-20261027-r5`; nguồn và phụ thuộc có SHA
trong biên nhận, không dùng lượt lỗi trước làm kết quả đạt.

Đã phục hồi vòng22a59..235f7: lấy tổng1lần và duyệt gồm cả chỉ sốtotal,
lọc mã/tên, xử lý mua rồi đọc lại loại để xử lý bán, giữ dữ liệu lệnh
qua lần xóa, gọi tạo lại/gửi, cập nhật ô đầu bảng, thông báo và chờ.
Thân xóa32450, đầy đủ hàm mở3e580, chọn cách khớp/kiểm hạn dùng và
gửi950 đều chạy nguyên trong phép đối chiếu; không cấp sẵn kết quả
các hàm con. Native3e580 CÓ gọi950 ở3eded; phần MQL5 tên Prepare chỉ
là đoạn tách trước gửi, nguồn vòng này dùng đúng Bot3OpenPending.

Phạm vi kiểm có tổngâm/0/nhiều, các loại64bit, vé bị cắt xuống32bit
khi dò bảng như mã gốc, dòng0/99/trùng, tênNULL/rỗng/tiếng Việt, mức
khối lượngNaN và các cờ gửi/xóa. Có các trường hợp xóa không thành
công nhưng vẫn tạo lại, tạo lại thất bại vẫn thông báo/chờ1000ms.
Khối lượng/chỉ số/tên mã/loại được thay sau dịch vụ để kiểm dữ liệu
được đọc lại đúng lúc. So đủ200ô bảng,35trường/4chuỗi trạng thái,
vé cuối, mảng khối lượng và mọi đối số/thứ tự dịch vụ.

Hai lỗi đã được sửa trước khi chốt: dùng nhầm trường khối lượng8
thay vì7 của gốc; bộ dữ liệuNULL/rỗng chưa ghi cùng tên mã cho hai
phía. Các lượt r3/r4 và nguồn trước sửa được giữ riêng. Lỗi khởi tạo
ngữ cảnh của bộ chạy và mã thuộc tính71 cũng được sửa, giữ bản cũ;
không sửa EX5 gốc hoặc nới phép so để che chỗ lệch.

Giới hạn: kiểm bắt đầu ở22a59 với đầu ra tính khối lượng, các biến,
vùng tạm và thanh ghi vào đã cấp. Chưa ghép hàm tính khối lượng hoặc
các bước quản lý/cổng cho phép trước đó. Câu trả lời truy vấn/chọn/gửi
được cấp, cấp bộ nhớ thành công. Chuyển số sang chuỗi được đo trong
MT5 rồi kiểm giá trị/kiểu ở lời gọi gốc. Gửi log0, chưa nối các nhánh
định dạng của hàm gửi trong lượt này; không gửi lệnh thật, chưa chứng
minh lỗi cấp bộ nhớ hoặc toàn bộ EA/cài đặt/hiển thị.

[Đặc tả](SPEC.md), [mã kiểm gốc/chuỗi](native-evidence.json),
[nguồn](../../../source/MQL5/Include/bot-cua-toi-3/Bot3EvaluationPendingResize.mqh),
[bộ so](../../../tests/check-evaluation-pending-resize.py),
[kết quả](../../../bang-chung/kiem-quan-ly-vi-the/b3-eval-resize-20261027-r5/comparison.json).
