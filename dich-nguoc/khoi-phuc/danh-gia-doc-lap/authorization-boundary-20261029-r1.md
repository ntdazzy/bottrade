# Ranh giới kiểm quyền — đối chiếu tĩnh 29/10/2026

Lượt này chỉ đọc và giải mã byte đã băm, không chạy helper quyền,
không gửi mạng và không đặt tài khoản/cờ kiểm thử/kết quả cấp quyền
giả lập. Bằng chứng số tài khoản trước đây chỉ chứng minh nhánh số,
không cấp quyền thực thi toàn bộ cơ chế bảo vệ.

Địa chỉ dưới đây là **RVA = địa chỉ tuyệt đối - `0x23e5aa10000`**.
Giải mã từ đầu hàm rồi lọc lệnh; không bắt đầu giữa một lệnh máy.

| Phần | Byte/lệnh đã xác nhận | Giới hạn |
|---|---|---|
| Cờ lưu quyền `0x6216c` | Constructor `0x20a00` nạp địa chỉ tại `0x21c48`, ghi byte 1 tại `0x21c76`; hàm quyền so cờ tại `0x58d5`, rẽ tại `0x58d8` | Chưa chứng minh thứ tự khởi tạo thực tế và nguồn trạng thái trong môi trường có quyền hợp lệ; không tự đặt cờ để chạy |
| Kiểm tài khoản cục bộ | Đọc tài khoản tại `0x58f4`, gọi `0x3d6c0` tại `0x5903`, xét byte thấp tại `0x5905` | Cần đủ ngữ nghĩa dữ liệu tên/môi trường, 226 cặp chuỗi và nhánh số; không dùng riêng bảng số thay toàn hàm |
| Phản hồi mạng | Nhánh tại `0x6167` kiểm bit thấp của `r11b`; `0x6171` xét kết quả tìm mẫu; qua `0x6179` thì `0x6181` đặt `bl=1`, `0x6183` tới dọn chung `0x6060` | HTTP 200 riêng lẻ chưa đủ; không giả phản hồi chấp nhận |
| Nhánh dự phòng `0x4d260` | Điểm trả ở `0x4df20`, nạp kết quả từ `esi` tại `0x4df0b`; có nhiều lần ghi `rsi/esi/sil`, kể cả nhánh ngoài dòng chính | Không đủ để nói “luôn trả 0” nếu chưa nối hết đường đi; nhận xét C trước đó không được dùng thay bằng chứng |

Trước bất kỳ phép chạy phần kiểm quyền nào, phải làm rõ toàn luồng
và nguồn hợp lệ của mọi dữ liệu quyết định quyền: cờ lưu, thuộc tính
tài khoản/môi trường, yêu cầu/phản hồi mạng, nhánh dự phòng và từ chối.
Không đi tiếp chỉ vì mã cuối cùng dự định dùng API MQL5 chính thức.

Các phép kiểm thuật toán/hiển thị tiếp tục từ sau cổng, có chặn nếu
đi vào các hàm quyền. Phần chưa rõ vẫn nằm ở P30 trong bảng chung.

## Trạng thái quan sát cho thân nghiệp vụ

Lượt `b1-observed-evaluation-20261029-r2` dùng nguyên hai byte
`0x6216c/0x67470` từ khối dữ liệu gốc đã băm; bỏ thao tác đặt cờ
riêng của bộ kiểm cũ. Chỉ khôi phục nguyên khối đã chụp, chặn ghi
riêng/ghi từ mã máy vào các byte này và chặn cả bốn điểm vào quyền.
57/57 ca thân đánh giá khớp, bốn thử ghi riêng đều bị chặn.

Đây không thay thế việc chốt nguồn cờ lưu hoặc toàn luồng xác thực.
Chỉ kiểm thuật toán sau cổng với trạng thái đã quan sát; không gọi
helper quyền hay cấp phản hồi quyền giả.
[Bằng chứng và giới hạn](observed-evaluation-bot1-20261029-r1/README.md).
