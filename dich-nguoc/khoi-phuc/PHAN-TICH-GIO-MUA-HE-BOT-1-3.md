# Giờ theo mùa — phân tích trước khi dựng nguồn

Trạng thái: **đã đọc thân hàm và 4 hằng số; chưa chạy đối chiếu hàm gốc**.

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

Các điểm phải giữ khi dựng/kiểm:

- Đọc giờ máy chủ; gọi `TimeCurrent()` tối đa ba lần, không gộp các lần.
- Năm trước 1987 in `AmericanDST(): Invalid year.` rồi trả sai.
- Dùng hai công thức khác nhau trước/từ năm 2007.
- Chỉ so thứ tự ngày trong năm, dùng dấu `<` ở cả hai biên; loại toàn
  bộ ngày bắt đầu và ngày kết thúc, dù có cộng mốc 02:00.
- Giữ phép tính số nguyên trước khi đổi sang số thực và thứ tự ghép/
  đổi hai chuỗi ngày. Mã gốc không kiểm giá trị trả về của các hàm đổi ngày.

Việc còn lại: dựng MQL5 đầy đủ từ phần đã rõ, chạy hàm gốc trên các mốc
trước/bằng/sau ngày biên; so số lần/thứ tự gọi, trường hợp đổi năm giữa
các lần đọc và lỗi dữ liệu. P26 vẫn chưa hoàn tất.
