# Cờ của nhánh vé đầu0 tại nơi gọi quản lý bot1

**3.628/3.628 ca khớp**, biên dịch0lỗi/0cảnh báo. Đã chạy liên tục
nguyên evaluator18aa0 qua phần đầu, bổ sung mức, cạnh nến mới1a245,
vào thân quản lý271f0 thật và thực hiện test/cmov27357..27368.
Không đặt lại thanh ghi/ngăn xếp ở giữa; cờ bản quyền chụp1 giữ nguyên.

Đã giải thích được điểm trước đây còn mở: cờ người gọi không phải một
bool được tự đặt0 trong thân quản lý. Nó lấy từ byte thấp R12 còn sống.
Công thức thuần dùng năm đầu vào có thứ tự ưu tiên:

1. Bật bổ sung mức và tổng vị thế đã đọc>0: true (địa chỉ mã chiến lược).
2. Ngày khác0/6: true (địa chỉ vùng tạm có dư8 khi chia16, byte thấp≠0).
3. Đã báo phiên: true. Ngày6 không có phiên để lại8; có1..9phiên để
   lại1..9 do tăng chỉ số trước lần gọi trảfalse; có10phiên để lại9.
4. Còn lại giữ byte từ nơi gọi!=0.

Giả thuyết ban đầu dùngN-1 đã bị chạy mã gốc bác bỏ trước khi đóng lượt
kiểm; đặc tả/nguồn trước sửa được giữ bằng tệp riêng. Không dùng giả
thuyết sai để gán cờ false cho trường hợp báo đúng một phiên.

Bộ kiểm thay đổi cờ0/1/255, tổng vị thế trước quản lý-1/0/1, ngày0/1/6,
ba cách bỏ/chạy thông báo,0..10phiên ngày6, byte vào0/70 và16vị trí
ngăn xếp căn16. Tại ba mốc1a245/271f0/27357, mọi ca giữ cùng byte.
Có616ca false với byte vào0. Các ca cấp byte70 từ cách nạp thông thường
của hàm điều phối đều true trong bộ này; không suy thành mọi nơi gọi.

Giới hạn: lịch/giờ/phiên/iTime và dữ liệu vị thế được cấp. Tổng vị thế
tại thân quản lý là1, vé đầu0; giá trị tổng tại bước trước có thể khác
và được cấp rõ. Ngăn xếp/byte vào được cấp ở lệnh đầu evaluator, chưa
chứng minh mọi đường từ hàm điều phối. Cấp chuỗi thành công và đổi số6
sang chuỗi1ký tự được cấp. Chưa chạy phần sau27368, toàn quản lý hoặc
EA; hàm thuần còn phải nối với trạng thái thật của nguồn đánh giá.

[Đặc tả](SPEC.md), [lệnh ghi R12 và mã kiểm](native-evidence.json),
[nguồn](../../../source/MQL5/Include/bot-cua-toi-1/Bot1ManagementCallerContext.mqh),
[bộ kiểm](../../../tests/check-first-zero-caller-context.py),
[kết quả](../../../bang-chung/kiem-quan-ly-vi-the/b1-first-zero-context-20261027-r1/comparison.json),
[quan sát đã tổng hợp](../../../bang-chung/kiem-quan-ly-vi-the/b1-first-zero-context-20261027-r1/observations-summary.json).
