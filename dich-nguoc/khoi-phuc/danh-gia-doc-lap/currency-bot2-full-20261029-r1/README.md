# Hai chiều đổi tiền — bot 2

`Bot2CurrencyConversion.mqh` dựng từ đúng bản EX5 đã cài SHA
`390d8ab14fc213ff4b8cbe5084bec545526e62c6028516fe21219a59398ce795`.
Nền bản chụp là `0x253f2620000`; hai thân và các hàm chuỗi giữ
nguyên mã máy trong bộ kiểm. Không dùng bản thăm dò đã thay `0x5c0`.

| Phần | Bằng chứng gốc | Nguồn/kiểm | Kết quả/còn thiếu |
|---|---|---|---|
| Tiền tài khoản → USD | `0x371f0..0x3cfa5`, EUR nhân tại `0x37693` | Giữ làm tròn cuối, đọc lại tiền/tỷ giá, CNH/CNY và cặp dự phòng | Khớp |
| USD → tiền tài khoản | `0x45400..0x4a936`, EUR chia tại `0x458c4` | Giữ phần lẻ; không thêm nhánh CNH/CNY | Khớp |
| CHF lặp ở chiều từ USD | Hai nhánh `0x46383`, `0x46685`; chuỗi `0x5753c/0x5755c/0x57590` là CHF/chf/USDCHF | Giữ hai lần kiểm độc lập; không thay nhánh thứ hai bằng CZK | Khớp; đây là hành vi gốc |
| Chuỗi và giá | Đuôi `0x5e1f0`, ô trả chuỗi `0x6843c`, ô giá `0x68448` | Chạy hàm sao chép chuỗi gốc; so mã cặp, D1, độ lùi 1 và từng giá trả về | Khớp |
| Chia 0 | Mã lỗi thấp `0x1f7` | So chuỗi gọi tới trước lỗi và việc không ghi kết quả thường | 4/4 ca; chưa so trạng thái cuối chính xác tại lỗi |

## Kết quả

- `b2-currency-full-20261029-r3`: **1.650/1.650 ca khớp từng byte**;
  91.359 lần đọc tiền tệ, 1.983 lần đọc giá, 525 phép tính CPU.
- Gồm mã hoa/thường/không hỗ trợ/rỗng, hậu tố thường/Unicode/dài,
  làm tròn âm/dương, vô cực/NaN, thứ tự toán hạng NaN, giá thay đổi
  giữa hai lần đọc, tiền tệ thay đổi giữa các phép so và cặp dự phòng.
- Hai phía có cùng mã SHA kết quả; kiểm mã máy trước/sau từng ca
  xác nhận không sửa hai thân đang chạy hoặc các hàm chuỗi.
- `b2-currency-errors-20261029-r1`: JPY/CNH dự phòng khi đổi sang USD,
  EUR/BTC khi đổi từ USD. Cả bốn ca dừng do chia 0; các lần gọi trước
  lỗi khớp từng byte. Đây là lỗi cố ý trong dữ liệu kiểm.
- `b2-currency-full-check-20261029-r2` và
  `b2-all-headers-api-20261029-r1`: 0 lỗi, 0 cảnh báo. Cả hai tệp
  `.mqh` hiện hành biên dịch chung được.
- Kiểm độc lập đã xác nhận hết sai khác CHF/CZK và mã nguồn khớp
  bản đã biên dịch. Các lượt lỗi và bản nháp cũ được giữ riêng.

## Giới hạn

Tiền tệ/tỷ giá là phản hồi được cấp. Các phép tính số thực chạy
trên CPU để giữ đúng các bit NaN; nhánh và hàm chuỗi vẫn chạy mã gốc.
Bộ nhớ trả chuỗi của dịch vụ và cấp phát thành công được cấp; chưa
chứng minh toàn bộ vòng đời bộ nhớ dịch vụ hoặc lỗi cấp phát.

Chưa ghép vào EA đầy đủ, chưa chạy tài khoản thật hoặc so cặp toàn
bot. Số ca này không phải tỷ lệ hoàn thành bot 2.

Chạy lại `cong-cu/kiem-doi-tien-bot-2.py`: `prepare RUN`,
`mql5 RUN --build BUILD`, `original RUN`, `compare RUN`;
`errors ERROR_RUN --build BUILD` dùng lượt riêng. Dùng tên mới và
máy thử `dich-nguoc/.local/mt5-bot1-thread-20261025`.

[Mã kiểm tra và số liệu](verification.json), [danh sách tệp](../currency-bot2-full-20261029-r1-manifest.txt).
