# Sửa cách ghi đầu vào và phạm vi sống của chỉ số

R2 B1 ca1097: băng ghi OTHER trong đối số iTime, trong khi trạng thái
trướcSDKvà đối số gốc đều XAUUSD. Bộ giả lập dịch vụ đổi tên mã trước
khi ghi đối số string đang tham chiếu. R3 ghi đủ đối số/trả lời trước
khi thực hiện thay trạng thái, rồi vẫn thay trước khi dịch vụ trả về.
Nguồn thuật toán không đổi.

R2 B3 ca434: ô ngăn xếp+0x88đã được nhánh chênh lệch cao dùng làm ô
tạm (38), nhánh này thoát trước khi cần chỉ số caller. Chỉ số caller
của giao diện nguồn là đầu vào bất biến; R3 ghi đúng đầu vào đó và
kiểm riêng giá trị ô ngăn xếp khi tới cổng đang sử dụng nó26e3e/1c8c7.
Không lấy ô chết trên nhánh thoát làm trạng thái chiến lược.

Khác biệt có chẩn đoán trongfirst-mismatch-r2.json. Mã/bộ ghiR2giữ
riêng. Không thay luật gốc, kết quả kỳ vọng hoặc bỏ so trạng thái.
