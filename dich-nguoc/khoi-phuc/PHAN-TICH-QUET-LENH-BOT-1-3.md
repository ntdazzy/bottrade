# Quét và đếm lệnh — phân tích trước khi viết mã

Phạm vi đầu tiên của P17: năm hàm dưới đây. Đã kiểm lại SHA-256 EX5
chuẩn, đọc mã C và lệnh máy từ bản chụp đã kiểm mã. Chưa viết MQL5
cho phần này, chưa có kết quả chạy đối chiếu. Các hàm quét/hủy/đóng
khác của P17/P18/P23 vẫn nằm trong danh sách chung.

| Phần | Vị trí gốc | Nơi đọc C | Nguồn dựng lại/kiểm | Còn thiếu |
|---|---|---|---|---|
| Đếm loại 4 | Bot 1 `0x31f40` | `ma-trung-gian.c:21235` | Chưa viết/chưa chạy | Chuỗi rỗng, lỗi chọn, giới hạn chỉ số và nơi gọi |
| Đếm loại 5 | Bot 1 `0x323e0` | `ma-trung-gian.c:21403` | Chưa viết/chưa chạy | Cùng các điểm trên |
| Dọn bảng kết quả 100 hàng | Bot 1 `0x32ce0`, bot 3 `0x3e490` | `ma-trung-gian.c:21677`, `ma-trung-gian-day-du.c:26918` | Chưa viết/chưa chạy | Ép số đặc biệt, thay danh sách giữa các hàng, trạng thái chọn |
| Kiểm giới hạn lệnh tài khoản | Bot 3 `0x47330` | `ma-trung-gian-day-du.c:31577` | Chưa viết/chưa chạy | Số ngoài 32 bit, tổng âm/0 và nơi gọi |

Hai hàm đếm của bot 1 gọi `OrdersTotal()` một lần. Tổng âm thì trả 0
và không đổi biến lưu vé. Tổng không âm thì đọc vé từ chỉ số **total
xuống 0, gồm cả hai đầu**; không tự sửa thành `total-1`. Mỗi lần ghi
vé vào biến dùng chung. Vé 0 bị bỏ qua; vé khác 0 mới đọc mã nhận
diện, mã giá rồi loại lệnh. Chỉ đếm khi cả ba cùng khớp.

Mã nhận diện tại `RVA 0x6246c` được đọc **4 byte có dấu**, rồi kéo
lên 8 byte để so với giá trị MT5 trả về. Lệnh máy `movsxd rcx,
dword ptr [r15]` ở `0x32009` và `0x324a9` chốt điều này. Kiểu biến
tạm 8 byte trong mã C không có nghĩa được đọc 8 byte từ biến gốc.
So mã giá có so con trỏ, độ dài và từng ký tự; vẫn cần kiểm riêng
chuỗi rỗng với chuỗi có con trỏ rỗng.

Hàm dọn bảng lặp đủ 100 hàng. Mỗi hàng đọc số đầu, chuyển sang số
nguyên 8 byte có dấu bằng cắt phần lẻ, rồi gọi lại `OrdersTotal()`.
Nếu tổng âm, xóa cả hai số trong hàng. Nếu không âm, quét
`PositionGetTicket()` từ total xuống 0, đủ hai đầu, không dừng sớm
khi đã thấy vé. Có vé khác 0 bằng số đã đổi thì giữ hàng; không có
thì xóa hai số. Biến vé dùng chung giữ kết quả lần đọc cuối.

**Giữ hành vi gốc:** hàm trên lấy tổng lệnh chờ nhưng đọc vé vị thế.
Địa chỉ gọi đã đối chiếu với bảng API có nguồn: `OrdersTotal`
ở `0x7d81a0`, `PositionGetTicket` ở `0x7d7df0`, tính từ đầu bộ máy
MT5. Không đổi hai lời gọi để làm thuật toán có vẻ hợp lý hơn.
Lệnh đổi số là `cvttsd2si` ở bot 1 `0x32d62`, bot 3 `0x3e512`.
Chưa kết luận hành vi MQL5 tương đương với số không xác định/vô hạn
hoặc ngoài khoảng số nguyên 8 byte; phải đo trước khi viết nhánh đó.

Hàm giới hạn bot 3 đọc `AccountInfoInteger(47)`, lấy 4 byte có dấu.
Nếu bằng 0, trả đúng và không hỏi tổng lệnh. Nếu khác 0, hỏi
`OrdersTotal()` rồi trả kết quả phép so có dấu `total < limit`.
Không lọc mã giá hoặc mã nhận diện trong hàm này.

Bằng chứng lệnh máy và mã kiểm tệp:

- [Bot 1](bot-cua-toi-1/phan-tich/quet-lenh-20261024/analysis.json).
- [Bot 3](bot-cua-toi-3/phan-tich/quet-lenh-20261024/analysis.json).

Ca bắt buộc trước khi chốt phần: tổng âm/0/nhiều, chỉ số đầu và cuối,
vé 0/vé trùng/vé lớn, mã nhận diện âm và khác phần 32 bit trên, mã giá
rỗng/có dấu/khác chữ hoa, loại không phải 4/5, toàn bộ 100 hàng,
bảng thay đổi giữa hai lần hỏi tổng và số có phần lẻ/số đặc biệt.
Phải so cả số lần/thứ tự gọi, vé cuối, hai số của mỗi hàng và trạng
thái chọn do MT5 thay đổi. Chưa có phép đo thì ghi chưa kiểm.

Một agent chỉ đọc đã kiểm riêng lệnh máy; nhận định ban đầu mã nhận
diện là 8 byte đã bị loại sau khi đọc lệnh `movsxd`. Claude đang phân
tích độc lập cùng phạm vi ở `order-scan-ultracode-20261024-r1`;
chưa có kết luận cuối nên chưa coi là được Claude xác nhận.
