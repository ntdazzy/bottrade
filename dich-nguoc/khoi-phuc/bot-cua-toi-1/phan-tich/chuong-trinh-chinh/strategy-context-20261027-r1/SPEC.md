# Ghi chú, mã nhận diện và số tiền dùng cho chiến lược

Phân tích trước khi viết mã. Đúng bản cài đặt SHA-256
`a3b0de423a06e10ebedc279307b93d7cb9188ba2bb5de77131a913c865b0e922`.
Hàm gọi `0x10f60..0x173e4`, SHA-256
`f5edd0f5e9033ddddb289a3419406c06292ce22bff197bea6d10acea1756c721`.

| Chỉ số | Bắt đầu | Trước gọi chuẩn bị | Hằng đưa vào đổi tiền | Vị trí hằng |
|---|---|---|---|---|
| 0 | 12aec | 12f49 | 60 | 4fe80 |
| 1 | 136b5 | 1385d | 90 | 4feb8 |
| 2 | 13ecb | 1407e | 27 | 4fee0 |
| 3 | 145da | 14782 | 37 | 4fef0 |
| 4 | 14cdc | 14ea3 | 16 | 4ff18 |
| 5 | 15607 | 157af | 30 | 4ff30 |
| 6 | 15cea | 15e8f | 25 | 4ff48 |
| 7 | 1652c | 166d1 | 37 | 4fef0 |

Các vị trí đều tính từ đầu bản chụp `0x23e5aa10000`.

1. Nếu byte `6a628 == 0`, sao chép chuỗi `6a618`, nối hậu tố
   `_XAUUSD_1` tới `_XAUUSD_8`, ghi chuỗi vào `62470`. Chiều dài hậu
   tố lưu ở `5c548 + 0x20*chỉ_số`, ký tự ngay sau 4 byte chiều dài.
   Nếu byte khác 0 thì giữ nguyên chuỗi trước đó. Không đổi sang tên
   mã giá đang chạy; bản gốc dùng đúng chữ XAUUSD này.
2. Ghi số nguyên 32 bit `6a610 + chỉ_số + 1` vào `6246c`, giữ việc
   tràn 32 bit. Ví dụ `12f1c..12f1e`, `1382c..1382f`.
3. Gọi nguyên hàm `47d20` với hằng double qua XMM0, đổi từ USD sang
   tiền tài khoản; hậu tố mã giá nằm ở `62208`. Ghi kết quả double vào
   `69f70`, một ô chung cho cả 8 chiến lược. Giữ các lần đọc giá lặp
   của CHF trong `Bot1Currency.mqh`.
4. Hủy chuỗi tạm bằng hàm `0`, rồi mới gọi chuẩn bị `7500`. Lỗi chia
   0 trong đổi tiền dừng chương trình trước khi ghi số tiền đầu ra.

Ghi chú lệnh `62470` khác chuỗi do bước chuẩn bị sao từ `622d0` sang
`62480`. Không gán hai ô này vào cùng một trường khi nối các phần.

Giao diện dự kiến: đầu vào gồm chỉ số hợp lệ 0..7, byte giữ ghi chú,
chuỗi tiền tố, số nguyên mã gốc, hậu tố mã giá. Đầu ra gồm chuỗi ghi
chú, số nguyên mã nhận diện và double đã đổi tiền. Đọc tiền tài khoản
trong từng lần đổi tiền, không lưu lại để bỏ các lần đọc của bản gốc.

Phạm vi phép kiểm: chạy nguyên đoạn lệnh máy từ cột bắt đầu tới trước
gọi chuẩn bị, cùng các hàm sao chép/cấp chuỗi/đổi tiền/dọn chuỗi gốc.
Đầu vào thanh ghi của đoạn được cung cấp: RCX=6a628, RBP=5c0,
RBX=47d20, R12=69f70; đây là hợp đồng kiểm từng đoạn, chưa chứng minh
mọi đường đi từ đầu hàm gọi. Cấp phát thành công và câu trả lời MT5
được cung cấp. Chưa phải toàn bộ chương trình chính hoặc EA đầy đủ.

## Chi tiết chốt thêm bằng phép so

Hàm đổi tiền gốc có 54 nơi gọi đọc tiền tài khoản. Đầu tiên đọc để
so `USD`; nếu khác thì đọc thêm một lần và bỏ kết quả. Sau đó đọc mới
ở từng phép so mã tiền viết hoa/viết thường, không giữ một chuỗi rồi
dùng cho tất cả điều kiện. JPY/YEN là hai tên trong cùng một điều kiện:
nếu JPY khớp thì bỏ cả hai phép đọc so YEN. CHF có hai điều kiện độc
lập kế tiếp, mỗi điều kiện đọc lại tiền và giá. Khi tài khoản đổi câu
trả lời giữa các lần đọc, mỗi nhánh dùng số tiền đầu vào gốc, không
dùng kết quả đổi tiền của nhánh trước. `Bot1CurrencyPair` được dùng
lại; hàm nhận chuỗi tiền tài khoản có sẵn không thay thế toàn bộ hàm gốc.

Một số điểm bắt đầu là lệnh nhảy, phép so nằm trước lần ghi cuối của
khối nạp cấu hình. Bộ kiểm phải chạy thêm đúng phép so gốc:
chỉ số 2: `13ec5`, 4: `14cd6`, 6: `15ce4`, 7: `16526`.
Mỗi lệnh là `80 39 00`, so byte tại RCX với 0; không tự đặt cờ theo
kết quả mong đợi. Sau đó mới chạy đoạn trong bảng, không viết lại
các ô cấu hình nằm giữa phép so và điểm bắt đầu.

Nguồn hiện hành khớp **760/760 ca**, gồm đủ 8 chỉ số, byte 0/1/255,
mã gốc -2147483648/0/2147483647, chuỗi trống/tiếng Việt/ký tự ghép/300
ký tự, các mã tiền, giá 0/âm/NaN/vô cực và tiền tài khoản thay đổi.
Chuỗi ghi chú UTF-16 được so toàn bộ; số tiền so từng bit, kiểm cả số
lần và thứ tự đọc. Thêm 2/2 ca chia 0 khớp loại lỗi và không ghi kết
quả bình thường; chưa so toàn bộ trạng thái trước lỗi.
Lượt đạt: `b1-strategy-context-20261027-r3`, lỗi:
`b1-context-errors-20261027-r1`. Hai lượt trước còn sai, giữ để xem lại.

[Nguồn](../../../source/MQL5/Include/bot-cua-toi-1/Bot1StrategyContext.mqh),
[kết quả thường](../../../bang-chung/kiem-quan-ly-vi-the/b1-strategy-context-20261027-r3/comparison.json),
[kết quả lỗi](../../../bang-chung/kiem-quan-ly-vi-the/b1-context-errors-20261027-r1/error-comparison.json).
