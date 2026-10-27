# Lịch sử từng chiến lược và bộ lưu dùng chung

Phần bắt buộc của điều phối: gọi sau từng chiến lược, lưu tiền đã đóng
và số giao dịch để tính số tiền mỗi giao dịch. Không thay bằng tổng lời/lỗ
của toàn tài khoản. Trước khi viết đã đọc nguyên thân, lời gọi và kiểu số.

| Bằng chứng | Bot 1 | Bot 3 |
|---|---|---|
| Thân hàm gốc | `0x1efa0..0x1f5df` | `0x2a1c0..0x2a7ff` |
| SHA-256 thân | `0633072a80dec3ef6ecaa0abc0d2e6856d40ed66426c3418c165d13839cad07a` | `3089eaa5351ecd00d853e4ea8153bab82c3f5a2196c724371fb84513c3ecd3b3` |
| Chỉ số chiến lược, mã hiện tại | `0x678f4`, `0x6246c` | `0x74934`, `0x6d564` |
| Dãy số lần đóng, kiểu `int32` | `0x67940` | `0x74980` |
| Tổng lịch sử trước, số mục đang lưu | `0x6a318`, `0x6a314` | `0x77358`, `0x77354` |
| Hai dãy `ulong` mã vị thế / `long` mã chiến lược | `0x6a2a0`, `0x6a2e0` | `0x772e0`, `0x77320` |
| Hàm sắp xếp đã phục hồi | `0x47950` | `0x557f0` |

Hai EX5 chuẩn và SHA-256 vẫn như bảng theo dõi chung. Bản chụp mã/dữ liệu
`luot-20261023-r1`, metadata từ `luot-20261023-data-v2` / `luot-20261023-data`.
Các lời gọi điều phối dùng chỉ số 0..7 / 0..8; đây là miền đầu vào của hàm.

1. Đọc `MQLInfoInteger(6)`; nếu đúng 1 và cờ hiển thị lúc kiểm bằng 0,
   trả +0.0 ngay, giữ toàn bộ trạng thái cũ. Cờ được đọc sau dịch vụ.
2. Còn lại, đặt số lần đóng tại chỉ số hiện tại về 0 trước khi gọi
   `HistorySelect(0,2147483647)`. Chọn không được thì trả +0.0.
3. Đọc `HistoryDealsTotal` lần đầu. Nếu khác tổng đang lưu: đặt số mục
   đang lưu về 0, lưu tổng mới, gọi `ArrayResize(...,total,0)` cho dãy
   mã vị thế trước, dãy mã chiến lược sau. Không kiểm kết quả trả về.
4. Duyệt xuôi đúng tổng vừa đọc, không đọc lại tổng trong vòng này.
   Lấy vé; nếu vé !=0, `(uint(type)&0xfffffffe)==0` và `int(entry)==0`:
   đọc mã vị thế (thuộc tính 12), rồi ghi vào vị trí số mục hiện tại;
   đọc mã chiến lược (11), ghi dãy đi kèm rồi tăng số mục theo 32 bit.
   Không lọc tên mã giá trong bước xây bộ lưu.
5. Nếu số mục đang lưu kiểu `int32` >1, sắp xếp hai dãy bằng hàm gốc
   đã phục hồi, đoạn 0..count-1. Giữ cờ đảo chiều của từng dãy riêng.
6. Luôn đọc `HistoryDealsTotal` lần thứ hai. Bắt đầu từ total-1 với
   phép trừ 32 bit, duyệt ngược đến 0. Lấy vé, lọc kiểu như bước 4,
   đọc tên mã giá và so với biến mã giá đang dùng tại thời điểm đó.
7. Đọc mã vị thế (12), đọc mã chiến lược (11). Tìm nhị phân trong
   0..count-1 bằng khóa `ulong`, giữa=(left+right)/2 theo `int32`,
   chia cắt phần dư về 0. Tìm thấy thì dùng mã trong dãy đi kèm;
   không thấy thì vẫn dùng mã đọc từ giao dịch, không tự bỏ giao dịch.
8. Nếu mã vừa chọn bằng mã hiện tại (mã hiện tại `int32` đổi sang
   `long` có dấu), đọc entry (4). Khi `(uint(entry)&0xfffffffd)==1`,
   tăng số lần đóng tại chỉ số đọc mới theo 32 bit. Các entry 1/3 đều vào.
9. Cộng lần lượt vào tổng: thuộc tính double 9, rồi 7, rồi 8. Mỗi phép
   cộng đọc phản hồi riêng, giữ thứ tự cả giữa các giao dịch.
   Phép cộng phải giữ dấu và phần dữ liệu của số không hợp lệ như
   lệnh `ADDSD` trên CPU thật. Phép `+=` mới biên dịch có thể đổi thứ
   tự hai toán hạng khi cả hai không hợp lệ; đã phát hiện qua ca 178.
10. Trả `double` và giữ hai dãy, tổng cũ, số mục đang lưu để lần gọi
    sau dùng lại. Tổng không đổi thì không xây lại, kể cả dữ liệu bên
    trong thay đổi. Đây là hành vi gốc, không tự sửa.

Các số/biến được đọc lại tại đúng vị trí sau dịch vụ; không thay bằng
một bản chụp chung từ đầu hàm. Kiểm sẽ so trạng thái trước mỗi dịch vụ,
hai dãy vật lý, cờ đảo chiều, mọi số đếm và bit kết quả trả về; gồm nhiều
lần gọi với cùng bộ lưu. Dịch vụ MT5 được cấp phản hồi, `ArrayResize`
phải đo trên MT5 thật. Thân hàm và hàm sắp xếp gốc chạy nguyên.

Chưa kiểm đủ trước khi có báo cáo. Không phải toàn bộ điều phối hay EA.
Giữ các lỗi truy cập dãy của runtime MQL5; không thêm luật né lỗi.

## Độ chính xác của công cụ tính số

Đo cùng một lệnh máy độc lập trên CPU thật và Unicorn: 15/100 cặp
số cho khác dữ liệu NaN. Vì vậy không dùng kết quả cộng NaN của
Unicorn làm chuẩn. Bộ kiểm chạy ba lệnh cộng trong hàm bằng chính
CPU thật, giữ nguyên mã gốc và phần còn lại của phép chạy; không sửa
tệp EX5 hoặc thay kết quả bằng số của nguồn mới. Mỗi lượt xác nhận
lại 100 cặp và chế độ số của CPU. Các ca kiểm cũ trước sửa bộ mô phỏng
được giữ riêng, không đổi chúng thành kết quả đạt.
