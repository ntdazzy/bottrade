# Giờ theo mùa — phân tích trước khi dựng nguồn

Trạng thái: **đã dựng MQL5 và khớp 4.737/4.737 ca mỗi bot**.
Hai bản biên dịch đều 0 lỗi, 0 cảnh báo. Kết quả và toàn bộ thứ tự/
đối số lời gọi được ghi lại trùng từng byte; chưa ghép vào EA chính.
[Biên nhận kiểm mới](KIEM-CHUNG-GIO-MUA-HE-BOT-1-3.json).

Claude Opus 5.5, mức `max`, đã phân tích riêng hàm `0x17840` của bot 1
và `0x7e20` của bot 3. [Kết quả độc lập](danh-gia-claude/season-time-20261024-r1/analysis.md).
Mình đã đọc lại hai thân hàm C và tự đo hằng trong bản chụp đã kiểm mã băm;
không dùng giả thuyết lịch thông thường để điền giá trị.

| Hằng | Bot 1 | Bot 3 | Giá trị đã đọc |
|---|---|---|---:|
| K0 | `0x4ffa0` | `0x57d80` | 7 |
| K1 | `0x4ffa8` | `0x57d88` | 14 |
| K2 | `0x4ffb0` | `0x57d90` | 1 |
| K3 | `0x4ffb8` | `0x57d98` | 31 |

[Byte gốc và giá trị](doi-chung-mt5/gio-mua-he-20261024/constants.json),
[mã băm và vị trí tệp](doi-chung-mt5/gio-mua-he-20261024/constants-proof.json).
Đã đọc thêm [12 chuỗi gốc](doi-chung-mt5/gio-mua-he-20261024/string-literals.json):
chuỗi gán ban đầu đúng là rỗng, thông báo và bốn đuôi ngày đều đã chốt.

Các điểm phải giữ khi dựng/kiểm:

- Đọc giờ máy chủ; gọi `TimeCurrent()` tối đa ba lần, không gộp các lần.
- Năm trước 1987 in `AmericanDST(): Invalid year.` rồi trả sai.
- Dùng hai công thức khác nhau trước/từ năm 2007.
- Chỉ so thứ tự ngày trong năm, dùng dấu `<` ở cả hai biên; loại toàn
  bộ ngày bắt đầu và ngày kết thúc, dù có cộng mốc 02:00.
- Giữ phép tính số nguyên trước khi đổi sang số thực và thứ tự ghép/
  đổi hai chuỗi ngày. Mã gốc không kiểm giá trị trả về của các hàm đổi ngày.

## Nguồn và phép so đã chạy

- [Nguồn bot 1](bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/Bot1AmericanDST.mqh),
  [nguồn bot 3](bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/Bot3AmericanDST.mqh).
- Claude cung cấp [đề xuất](danh-gia-claude/season-time-20261024-r2/analysis.md);
  mình đọc lại mã máy, đo chuỗi/hằng số, dựng và kiểm riêng.
- Lượt `dst-20261024-r1`: 4.383 ca theo từng ngày của 12 năm,
  216 ca sát mốc đổi giờ, 75 ca giả định lần đổi ngày sau lần đầu
  không ghi kết quả, 45 ca đổi chuỗi thành giờ trả 0, 7 ca đồng hồ
  thay đổi giữa các lần đọc và 11 ca cấp sẵn năm để kiểm phép tính số nguyên.
  Trong 75 ca đặt cờ lỗi, 65 ca đi tới nhánh lỗi, tổng cộng 80 lần
  giả định trả lỗi; 10 ca còn lại kết thúc trước khi tới nhánh đó.
- Hai bản dựng: `b1-american-dst-01`, `b3-american-dst-01`.
  [Bot 1](bot-cua-toi-1/bang-chung/kiem-gio-mua-he/dst-20261024-r1/comparison.json),
  [bot 3](bot-cua-toi-3/bang-chung/kiem-gio-mua-he/dst-20261024-r1/comparison.json).

MT5 riêng chạy nguồn mới và đo kết quả thật của phép chia dư, đổi
ngày, ghép chuỗi. Hàm gốc chạy nguyên thân cùng hai hàm sao chép/hủy
chuỗi trong bộ mô phỏng; cấp lại các kết quả MT5 vừa đo tại ranh giới
lời gọi. Mỗi lời gọi phải đúng thứ tự, kiểu và đối số; thiếu/thừa hoặc
khác một đối số đều dừng phép so. Kết quả mong đợi cuối cùng lấy từ
lệnh máy gốc, không lấy từ công thức dựng lại. Đồng hồ được cấp sẵn,
không lấy giờ máy đang chạy để quyết định kết quả.

## Phần còn thiếu

- Lần `TimeToStruct` đầu tiên thất bại và không ghi dữ liệu: mã gốc
  dùng vùng chưa khởi tạo; chưa chứng minh được kết quả tương ứng.
- Lỗi cấp bộ nhớ, mã lỗi của các hàm MT5 và những lỗi đổi ngày thực
  chưa được đo bằng một lượt gây lỗi trực tiếp. Các ca giả định trên
  chỉ kiểm cách hàm xử lý kết quả được cấp sẵn.
- Chưa nối với giờ UTC, giờ nơi giao dịch, HTTP/phương án thay thế,
  cài đặt nhập tay, lọc tin và toàn bộ khởi tạo. P26 chưa hoàn tất.

## Đánh giá bổ sung của Claude và việc phải làm tiếp

[Lượt kiểm Max với Ultracode](danh-gia-claude/season-time-ultracode-20261024-r3/analysis.md)
đã trả kết quả; [mình đã đọc và phân loại lại](danh-gia-claude/season-time-ultracode-20261024-r3/host-verdict.json).
Các kết quả 4.737 ca ở trên giữ nguyên phạm vi, chưa đủ để đóng P26:

- Các giờ sát biên hiện lấy theo Chủ nhật của lịch thường. Với năm
  2100/2400/3000, ngày biên do bot tính khác lịch thường; mới kiểm
  từng ngày lúc 12:00. Đã trích [mốc thật từ dấu vết hàm gốc](doi-chung-mt5/gio-mua-he-20261024/native-boundaries-from-r1.json)
  để bổ sung giờ sát biên; các ca bổ sung chưa chạy.
- Cần thêm năm âm được cấp sẵn, giờ 0, đổi ngày có ghi dữ liệu nhưng
  trả thất bại và ghép chuỗi thất bại không ghi. Khi đó phải kiểm cả
  0/1/2 lần hủy chuỗi; bộ hiện tại chỉ chấp nhận 0 hoặc 2.
- Cần tách hai khai báo chuỗi để khớp thứ tự khởi tạo từng ô gốc,
  rồi biên dịch và chạy lại. Đồng thời chụp bản biên dịch gọi MT5
  trực tiếp, không thay lời gọi bằng hàm kiểm, để so cách trình biên
  dịch nối các lời gọi và khởi tạo vùng ngày.

Claude chưa tự đọc bằng chứng chuỗi rỗng mới; điểm đó đã được chốt
bằng `string-literals.json`, không coi lại là giả thuyết. Công cụ tự
chia việc của Claude bị từ chối trong phiên chỉ đọc; không có tác tử
phụ kiểm độc lập. Các phiên Claude riêng do mình mở vẫn làm song song.
