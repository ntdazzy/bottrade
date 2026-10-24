# Chọn thời điểm chặn tin — bot 1 và 3

Đã dựng riêng phần chọn thời điểm chặn tin từ hai hàm gốc:

- Bot 1: `0x7310`, đoạn gốc kết thúc tại `0x74f8`.
- Bot 3: `0x7c30`, đoạn gốc kết thúc tại `0x7e18`.

| Bot | Ca gốc | Ca MQL5 khớp | Biên dịch |
|---|---:|---:|---|
| 1 | 1.620 | 1.620/1.620 | 0 lỗi, 0 cảnh báo |
| 3 | 1.620 | 1.620/1.620 | 0 lỗi, 0 cảnh báo |

[Bằng chứng tổng](KIEM-CHUNG-CHAN-TIN-BOT-1-3.json),
[công cụ kiểm](cong-cu/phan-tich-chan-tin-bot-1-3.py).

## Quy tắc đã chốt từ mã gốc

Mỗi loại tin có ba giá trị: bật/tắt, thời điểm tin và số phút chặn sau
tin. Một loại tin được xét khi:

```text
bật
và thời điểm tin > 0
và thời điểm tin + số phút × 60 > giờ máy chủ
```

Nếu còn hiệu lực, bot lưu **thời điểm tin**, không lưu thời điểm kết thúc.
Khi có nhiều loại tin, bot giữ thời điểm tin nhỏ nhất. Mọi phép so đều
dùng dấu `>`; đúng bằng thời điểm hết chặn thì không còn hiệu lực.

Thứ tự trong mã là NFP, lãi suất, CPI. Vì kết quả lấy thời điểm nhỏ
nhất nên thứ tự không làm đổi kết quả khi hai tin cùng tồn tại; nó vẫn
được giữ trong nguồn để khớp tác dụng phụ và chuỗi hiển thị sau này.

Nguồn dựng lại:

- [Bot1NewsBlock.mqh](bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/Bot1NewsBlock.mqh)
- [Bot3NewsBlock.mqh](bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/Bot3NewsBlock.mqh)

Hai chương trình kiểm chỉ đọc các ca nhị phân và trả thời điểm đã chọn;
không gọi lịch tin, mạng, đóng vị thế hay hủy lệnh.

## Phạm vi chưa làm

Các hàm trước đó mới là phần **tìm sự kiện**:

- NFP dùng lịch theo tiền tệ USD và tìm tên sự kiện bắt đầu bằng `N`.
- Lãi suất dùng lịch theo quốc gia US và tìm tên bắt đầu bằng `F`.
- CPI dùng lịch theo tiền tệ USD và lọc nhiều mẫu bắt đầu bằng `C`, `e`, `(`.

Các chi tiết này đã thấy trong mã C nhưng chưa dựng lại vì còn cần chốt
định dạng danh sách lịch, mã sự kiện, lỗi thiếu dữ liệu và thời gian bắt
đầu/kết thúc. Hàm đọc UTC qua mạng (`0x17d20`/`0x20150`) cũng chưa ghép.
Hành động khi đang trong cửa sổ tin (đóng lệnh đang mở, hủy lệnh chờ)
chưa kiểm toàn bộ. Do đó phần này chưa chứng minh toàn bộ bộ lọc tin.
