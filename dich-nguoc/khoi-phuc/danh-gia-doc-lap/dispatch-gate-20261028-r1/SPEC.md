# Điều kiện chạy theo giờ/nến — bot 1 và 3

Đã đọc toàn đoạn đầu hàm điều phối, từ điểm vào thực tế đến trước cờ
hoạt động/kiểm quyền dùng. Không chạy hoặc thay đổi phần kiểm quyền dùng.

| Trường | Bot 1 | Bot 3 |
|---|---|---|
| Điểm vào hàm | `10f60` | `17f00` |
| Tiếp tục sau điều kiện | `1107c` | `18044` |
| Dừng lượt gọi | `16d74` | `1fb27` |
| Chế độ, byte | `621e0` | `6d1e8` |
| Cờ nến M1, byte | `621c9` | `6d1d0` |
| Giờ đã nhớ, int64 | `621d0` | `6d1d8` |
| Nến đã nhớ, int64 | `621d8` | `6d1e0` |
| Chuỗi mã giá biểu đồ | `517c0` | `59d00` |

Địa chỉ là độ lệch, đã trừ đúng địa chỉ đầu bản chụp. Chuỗi ở đây là
mã giá biểu đồ, khác ô mã giá của phần chuẩn bị chiến lược. Mã máy,
SHA-256 toàn hàm ngoài và các vị trí lưu trong `botN-native.json`,
`botN-raw.txt` cùng thư mục.

1. Nếu chế độ ban đầu đúng byte 1, gọi TimeCurrent. Sau dịch vụ mới
   đọc lại chế độ và giờ đã nhớ; cộng unsigned64 rồi so có dấu64.
   Nếu giờ hiện tại không vượt tổng này, giữ cờ dừng=1. Nếu vượt,
   cờ dừng=0, gọi TimeCurrent lần nữa, đọc lại chế độ rồi ghi giờ mới.
2. Nếu chế độ ban đầu khác 1, cờ dừng lấy nguyên byte cờ M1; giá trị
   chế độ dùng để quyết định đọc nến bằng 0.
3. Nếu cờ M1 hiện tại khác 0 hoặc bit thấp của chế độ đã giữ bằng 1,
   gọi iTime với khung M1, lệch 1. So kết quả với nến đã nhớ sau dịch
   vụ. Nếu lớn hơn, gọi iTime lần nữa để ghi nến rồi **đi tiếp ngay**,
   bỏ qua cờ dừng. Đây là nhánh bắt buộc, không được gom về cuối hàm.
4. Ngoài nhánh nến mới, chỉ dừng nếu bit thấp của cờ dừng bằng 1.
   Do đó byte 2 khác byte 1/255. Không đổi thành phép so `!=0`.

Nguồn: `BotNDispatchGate.mqh`. Bộ kiểm
`kiem-cong-dieu-phoi-bot-1-3.py` chạy từ điểm vào hàm ngoài thật,
so thứ tự và đối số hai dịch vụ, trạng thái ngay trước dịch vụ và
kết quả cuối. Có ca tràn số64, byte ngoài0/1, hai phản hồi khác nhau,
và thay đổi cờ/trạng thái trong dịch vụ. Không đưa kết quả của thuật
toán con vào bộ so; chỉ cấp phản hồi thời gian/nến.

Lượt `bN-dispatch-gate-20261028-r2`: **640/640 ca mỗi bot**,
**1.159 lời gọi dịch vụ mỗi bot**. Hai bản kiểm và hai bản gọi trực tiếp
dịch vụ MT5 đều biên dịch 0 lỗi, 0 cảnh báo.

Giới hạn: chưa ghép các đoạn kiểm tài khoản, vốn, giờ mùa hè, vòng
chiến lược và toàn EA. Bản đọc vị trí chuỗi ở lượt r1 lệch `0x10000`,
bị phép so đối số từ chối ngay; giữ bằng chứng cũ, dùng lượt r2 đã sửa.
