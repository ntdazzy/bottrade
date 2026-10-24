# Kiểm nguyên nhân bốn ca lệch

Mục tiêu: hàng đợi giữ đúng thứ tự gọi, trạng thái và phép tính gốc,
kể cả byte số không xác định; không tăng sai số để bỏ khác biệt.

- Lượt `queue-20261024-r1`: 232/236 ca khớp, bốn ca 66/80/185/192
  chỉ khác bit dấu của `NaN` ở dừng/chốt truyền vào hàm tạo lệnh.
- Đã đọc phép tính gốc: cộng 0 vào khoảng dừng, nhân khoảng chốt với
  đơn vị, nhân khoảng dừng, cộng/trừ với giá. Đã giữ nguyên bản nguồn
  lúc lệch rồi tách các bước theo thứ tự đó trong lượt `r2`.
- `r2` vẫn có đúng bốn khác biệt; giả thuyết chỉ do biểu thức điều
  kiện gộp hoặc thiếu bước cộng 0 không giải thích được kết quả.
- Đã chạy cùng nguồn/bộ kiểm trong chính máy đo lại quá khứ, cùng
  `metatester64.exe` SHA `5033d9d4…104efb`. Kết quả vẫn là bốn ca
  lệch giống hệt; giả thuyết chỉ khác chế độ chạy script bị bác bỏ.
- Chưa xác định đó là cách trình biên dịch tạo phép trừ hay một khác
  biệt ở vùng chuyển dữ liệu. Chưa xem phần hàng đợi là đã đạt.
- Bằng chứng nhỏ nhất còn thiếu: mã máy thực tế của phép tính MQL5
  mới và lời gọi đổi số có kiểu rõ ràng.
- Hướng kiểm mới: nạp thư viện có nguồn, chỉ thực thi `Anchor`, chụp
  các hàm phép trừ và hàm hàng đợi đã biên dịch. Đọc các lệnh và đối
  số thật trước khi sửa tiếp. Không thêm điều kiện đoán theo kết quả.

Giới hạn riêng đã sửa trong bộ mô phỏng: lần đầu thiếu dịch vụ xóa
vùng nhớ tại mã máy MT5 `0xacad20`. Đã đọc thân dịch vụ từ đúng EXE,
kiểm đối số phải là địa chỉ hàng đợi/0/2400 rồi mới cấp dịch vụ đó.
Đây là giới hạn phép kiểm, không phải sửa EX5 hoặc mã bot gốc.

Đã chốt nguyên nhân: bản chụp `queue-native-r2` cho thấy trình biên
dịch dùng `xorpd` đổi dấu khoảng dừng/chốt, sau đó cộng với giá ở cả
hai chiều. Gốc dùng `subsd` với giá ở toán hạng đầu. Phép trừ thường
của nguồn đối chứng giữ nguyên `subsd`; lỗi đến từ việc gộp nhánh.

Đã đo 25 cặp số trực tiếp trong MT5 và ghi bằng số nguyên 64 bit để
giữ mọi bit. Một điểm yếu khác của bộ mô phỏng được phát hiện: khi
cả hai số là `NaN`, CPU thật ưu tiên toán hạng đầu, bộ mô phỏng đôi
khi chọn phần dữ liệu khác. Đã lưu cả hai kết quả, sửa đúng quy tắc
đó trong bộ kiểm, không đổi phép tính thường.

Nguồn mới dùng các hàm cộng/nhân/trừ giữ thứ tự và phần `NaN` gốc.
Lượt `queue-20261024-r3` khớp 374/374 ở cả hai bot; chạy thêm trong
đúng máy đo lại quá khứ cũng khớp từng byte. Việc thử lại, bảng dữ
liệu và lời gọi được so như cũ; không nới sai số hoặc bỏ bốn ca lỗi.
