# Ghi chú, mã nhận diện và số tiền dùng cho chiến lược

Phân tích trước khi viết mã. Bản cài đặt SHA-256
`ee063d3d87490afe24e2f4ce85f6b05659320e297b102efd70207f71ca2feb83`.
Hàm `17f00..1fcf9`, SHA-256
`ad9ba21d686c6f054138072d755e4851473ddc903acc6f1fc3bf7fe0cad1f714`.
Các vị trí tính từ đầu bản chụp `0x17156250000`.

| Chỉ số | Bắt đầu | Trước chuẩn bị | Cộng mã gốc | Tiền ban đầu | Tiền khi bật 1d6f28 | Reference khi bật |
|---|---|---|---|---|---|---|
| 0 | 1ae06 | 1affc | 1 | 145 | 60 | 2000 |
| 3 | 1b6af | 1b8ad | 2 | 52 | 52 | 1600 |
| 1 | 1bf4f | 1c143 | 5 | 30 | 30 | 2000 |
| 2 | 1c7e9 | 1c9e7 | 8 | 35 | 35 | 2000 |
| 5 | 1d071 | 1d268 | 9 | 348 | 140 | 2400 |
| 4 | 1d8e5 | 1dadc | 12 | 281 | 110 | 2600 |
| 8 | 1e160 | 1e35a | 13 | 968 | 700 | 1900 |
| 6 | 1ea03 | 1ebfd | 14 | 149 | 90 | 2600 |
| 7 | 1f28e | 1f492 | 15 | 276 | 130 | 2800 |

1. Byte `1d7008 == 0`: nối chuỗi `1d6ff8` với hậu tố `_XAUUSD_n`,
   trong đó n=chỉ số+1, ghi vào `6d568`. Khác 0 giữ nguyên ghi chú.
   Chiều dài hậu tố tại `667c8 + 0x20*thứ_tự_trong_bảng`; ký tự ở +4.
2. Ghi `int32(1d6ff0 + số_cộng_trong_bảng)` vào `6d564`.
   Không thay số cộng này bằng chỉ số+1.
3. Gọi `41780` đổi số tiền ban đầu từ USD sang tiền tài khoản, hậu tố
   mã giá `6d230`; ghi vào ô chung `76fa0`.
4. Nếu byte `1d6f28 != 0`, ghi Reference mới vào `6d1b8`, rồi gọi
   `41780` lần nữa với cột tiền khi bật; ghi đè `76fa0`. Vẫn gọi lần
   hai khi số tiền hai cột bằng nhau; vẫn đọc lại tiền tài khoản/giá.
   Giữ thứ tự lần đầu đã ghi tiền, rồi sửa Reference, rồi đổi lần hai.
5. Hủy chuỗi tạm bằng hàm `0`, sau đó gọi `e0c0`. Chia 0 trong đổi
   tiền dừng chương trình, không tiếp tục sang chuẩn bị.

Ghi chú lệnh `6d568` khác chuỗi do chuẩn bị sao từ `6d308` sang
`6d578`. Giữ hai trường riêng khi nối; chỉ Reference truyền trực tiếp
vào cùng ô `6d1b8` của đầu vào chuẩn bị.

Giao diện: chỉ số hợp lệ 0..8, byte giữ ghi chú, tiền tố, int mã gốc,
hậu tố mã giá, byte `native_1d6f28`; Reference truyền bằng tham chiếu
để giữ đúng tác dụng phụ. Đầu ra chuỗi ghi chú/int mã/double tiền.

Phép kiểm từng đoạn cung cấp RCX=1d7008, R12=5c0 và khung ngăn xếp;
chạy các đoạn gốc cùng hàm chuỗi/đổi tiền/dọn chuỗi gốc. Đây chưa phải
chứng minh mọi đường từ đầu hàm gọi. Cấp phát thành công, câu trả lời
MT5 được cung cấp; chưa kiểm toàn bộ EA, giao diện hoặc tài khoản thật.

## Chi tiết chốt thêm bằng phép so

Hàm đổi tiền có 54 nơi đọc tiền tài khoản. Đọc so USD trước; nếu khác
thì đọc thêm một lần, bỏ kết quả. Mỗi phép so mã tiền phía sau đọc lại
tiền tài khoản, viết hoa trước rồi viết thường nếu chưa khớp. JPY/YEN
là hai tên trong cùng một điều kiện; JPY đã khớp thì bỏ phép so YEN.
Thứ tự sau CHF là CZK, rồi HKD/RUB/SGD/BTC/ETH và các mã còn lại.
Các điều kiện độc lập; không dừng vòng sau mã khớp. Mỗi nhánh dùng số
tiền đầu vào gốc. Chỉ dùng lại `Bot3CurrencyPair`; hàm nhận sẵn chuỗi
tiền tài khoản không bao gồm chuỗi lời gọi đọc mới của bản gốc.

Hai điểm bắt đầu 4/5 là lệnh nhảy, phép so nằm trước lần ghi cuối của
khối cấu hình. Bộ kiểm chạy thêm phép so gốc `1d8dd` / `1d069` (cùng
byte lệnh `80 39 00`), dùng RCX=1d7008 và byte đầu vào thực tế. Không
tự đặt cờ hoặc chạy lại lần ghi cấu hình nằm giữa.

Nguồn hiện hành khớp **1.818/1.818 ca**: đủ 9 chỉ số, byte 0/1/255,
cả hai chế độ đổi tiền, mã gốc tràn 32 bit, chuỗi trống/tiếng Việt/
ký tự ghép/300 ký tự, mã tiền và giá 0/âm/NaN/vô cực. Có các câu trả
lời tiền tài khoản thay đổi giữa các lần đọc. So chuỗi UTF-16 đầy đủ,
số tiền từng bit, Reference và số lần/thứ tự gọi. Thêm 3/3 ca chia 0
dừng đúng lớp lỗi, gồm lỗi ở lần đổi tiền thứ hai; chưa so toàn bộ
trạng thái trước lỗi.
Lượt đạt `b3-strategy-context-20261027-r3`, lỗi:
`b3-context-errors-20261027-r1`. Hai lượt trước chưa đạt, được giữ lại.

[Nguồn](../../../source/MQL5/Include/bot-cua-toi-3/Bot3StrategyContext.mqh),
[kết quả thường](../../../bang-chung/kiem-quan-ly-vi-the/b3-strategy-context-20261027-r3/comparison.json),
[kết quả lỗi](../../../bang-chung/kiem-quan-ly-vi-the/b3-context-errors-20261027-r1/error-comparison.json).
