# Bot 1 và 3 — ghép trạng thái vốn và kiểm tiền ký quỹ

Đã ghép phần cập nhật vốn sau khi rút tiền với phần chọn vốn, đổi tiền
và tính khối lượng. Đã kiểm riêng hai hàm kiểm tiền ký quỹ. Chưa có EA
hoàn chỉnh. [Bản đồ các phần của bot](BAN-DO-TOAN-BO-BOT-1-3.md) là danh
sách chung để tiếp tục phân tích trước khi viết phần mới.

| Phép kiểm | Bot 1 | Bot 3 |
|---|---:|---:|
| Luồng trạng thái vốn → đổi tiền → khối lượng | 1.700/1.700 | 1.883/1.883 |
| Trong đó mã gốc lỗi chia cho 0, cùng từ chối kết quả | 96 | 115 |
| Kiểm tiền ký quỹ trực tiếp và qua bộ chặn vốn | 1.141/1.141 | 1.141/1.141 |
| Biên dịch hai chương trình kiểm hiện hành | 0 lỗi, 0 cảnh báo | 0 lỗi, 0 cảnh báo |

## Bằng chứng và nguồn

| Phần | Bot 1 | Bot 3 |
|---|---|---|
| Nối trạng thái vốn | [Bot1AccountStateVolume.mqh](bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/Bot1AccountStateVolume.mqh) | [Bot3AccountStateVolume.mqh](bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/Bot3AccountStateVolume.mqh) |
| So luồng vốn | [comparison.json](bot-cua-toi-1/bang-chung/kiem-luong-von-day-du/state-volume-20261023-r1/comparison.json) | [comparison.json](bot-cua-toi-3/bang-chung/kiem-luong-von-day-du/state-volume-20261023-r1/comparison.json) |
| Nguồn kiểm ký quỹ | [Bot1Margin.mqh](bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/Bot1Margin.mqh) | [Bot3Margin.mqh](bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/Bot3Margin.mqh) |
| So ký quỹ | [comparison.json](bot-cua-toi-1/bang-chung/kiem-ky-quy/margin-20261023-r2/comparison.json) | [comparison.json](bot-cua-toi-3/bang-chung/kiem-ky-quy/margin-20261023-r2/comparison.json) |

Các chương trình kiểm chỉ dùng MT5 riêng, không gửi lệnh hoặc ghi mục
trạng thái thật. Dữ liệu lịch sử/giá/tài khoản và các phép ghi được cấp
sẵn hoặc ghi nhận trong phép kiểm.

## Luồng vốn đã kiểm

Chạy nguyên hàm khối lượng gốc cùng hàm rút tiền và hàm đổi tiền gốc.
So cả giá trị số đã ghi trước lỗi chia cho 0; không còn xóa các giá trị
này khỏi kết quả như bộ kiểm thành phần trước. Cũng so thời điểm kiểm,
thời điểm khoản đã xử lý, thứ tự ghi trạng thái và thứ tự đọc giá đổi tiền.

Từng phép đọc/ghi lịch sử được đưa vào mã kiểm tra thứ tự. Có dấu vết
gốc trong `native-traces.json`. Nội dung/định dạng thông báo và các bộ
đếm thông báo sau lỗi chia cho 0 vẫn nằm ngoài phạm vi.

Bên gọi vẫn phải nạp tên mục lưu và trạng thái khởi động đúng bản gốc.
Phần đó chưa được ghép trong lượt này. Các số thực trong bộ kiểm luồng
vốn là hữu hạn; lỗi được trả bằng `false`, không mô phỏng toàn bộ cách
MT5 kết thúc chương trình sau lỗi.

## Ký quỹ đã kiểm

- Loại bỏ khối lượng không dương trước bước đọc tài khoản.
- Với các tên tiền `BTC`, `btc`, `ETH`, `eth`, bỏ bước so vốn trên mỗi
  đơn vị khối lượng theo đúng nhánh gốc. Các tên khác giữ bước này.
- Bước chặn vốn so vốn hiện tại và tiền khả dụng trên khối lượng chia
  cho 0,01 với mức 70. Giữ thứ tự đọc và dấu so sánh.
- Sau đó đọc giá, tính số tiền cần giữ để mở lệnh và so tiền khả dụng.
  Thiếu tiền hoặc phép tính thất bại thì trả `false`.
- Loại lệnh bán dùng giá bán, các loại khác đi theo nhánh giá mua của
  hàm gốc. Các loại ngoài mua/bán cũng được đưa vào bộ kiểm.

So kết quả cho phép/từ chối, số lần gọi, tham số gọi và số thông báo.
Có ca sát ngưỡng, khối lượng 0/âm, tên tiền khác chữ hoa/thường, phép
tính thất bại và 36 ca dùng số không hữu hạn. Khi mô phỏng đọc giá báo
thất bại, bộ kiểm vẫn cấp nội dung giá; chưa chứng minh trường hợp bộ
nhớ kết quả giá không được ghi.

Vị trí gốc: bot 1 `0x3cb30`, `0x457d0`; bot 3 `0x47840`, `0x53670`.
Hàm kiểm khối lượng min/max/bước riêng vẫn chưa dựng. Kiểm ký quỹ chưa
được nối vào luồng đặt lệnh vì phần gửi lệnh còn đang phân tích.

Lượt ký quỹ `r2` chỉ đổi tên một biến trong chương trình kiểm để bỏ
cảnh báo che tên. Kết quả mã gốc `r1` được dùng lại với đầu vào và công
cụ gốc không đổi; việc dùng lại được ghi trong `original-reuse.json`.
