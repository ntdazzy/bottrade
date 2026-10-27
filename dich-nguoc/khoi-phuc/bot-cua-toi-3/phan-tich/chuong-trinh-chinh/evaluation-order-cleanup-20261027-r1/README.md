# Dọn lệnh chờ đã nối với đầu đánh giá và bổ sung mức dừng/chốt

**339/339 ca khớp từng byte**, đọc lại cấu trúc từng ca cũng339/339.
Biên dịch API và bộ kiểm đều0lỗi/0cảnh báo. Đầu ra hai phía cùng SHA
`6fd90f4126cfacb45e419af5840f319f37a68af60051b05e2e1f04860f1f2f80`.
Phải xem mã SHA trong biên nhận là nguồn chính khi đối chiếu lại.

Nguyên evaluator chạy từ20ef0 qua lấy giờ/phiên/giá, vòng dọn lệnh
chờ212ff..214ee, rồi vòng bổ sung dừng/chốt tới227c0. Thân xóa32450,
sửa32a90 và gửi950 đều chạy thật; không cấp sẵn kết quả các hàm con.
Không đặt lại thanh ghi/ngăn xếp hoặc các đầu vào giữa các bước.
Câu trả lời dịch vụ MT5, trạng thái đầu và cấp chuỗi thành công được cấp.

Kiểm cờ0/1/255, số lệnh âm/0/nhiều, phần thấp32bit của loại lệnh,
mã có dấu64/32bit, chuỗiNULL/rỗng/tiếng Việt/dài, vé lớn qua53bit và
63bit, xóa thất bại/thành công, gần mức khóa xóa và chương trình dừng.
So đầy đủ35trường và4chuỗi yêu cầu/kết quả/kiểm trước/sau gọi hàm con,
thứ tự/đối số truy vấn, bool xóa và toàn bộ200ô bảng. Có dòng0/99,
dòng trùng, NaN/vô cực/±0; chỉ dòng đầu tiên trùng vé bị xóa sau khi
hàm xóa báo thành công. Các ca cuối nối cả nhiều lệnh và nhiều vị thế.

Khi cờ0, vòng dọn lệnh chờ bỏ qua hoàn toàn. Khi cờ khác0, gọi tổng
đúng1lần và duyệt từ cuối về đầu. Không tự thay bước này bằng chọn
lệnh cao/thấp, không sửa vé cuối cùng toàn cục. Bảng dùng cùng địa chỉ
72e10 với bảng kết quả hàng đợi hiện có; không tạo bảng nghiệp vụ mới.

Giới hạn: chưa quản lý sau227c0, EA đầy đủ, môi trường gửi thật, lỗi
cấp bộ nhớ và toàn bộ giao diện/lưu trạng thái. Thông báo gửi log0;
nhánh định dạng có phép so riêng. Chưa chạy hai EA hoàn chỉnh song song.
Không sửa EX5 gốc hay cờ bản quyền.

[Đặc tả](SPEC.md), [mã kiểm gốc](native-evidence.json),
[nguồn](../../../source/MQL5/Include/bot-cua-toi-3/Bot3EvaluationPendingCleanup.mqh),
[bộ so](../../../tests/check-evaluation-pending-cleanup.py),
[kết quả](../../../bang-chung/kiem-quan-ly-vi-the/b3-eval-cleanup-20261027-r1/comparison.json).
