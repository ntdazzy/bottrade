# Phân tích bước chọn chiến lược bot 3 — 23/10/2026

Hai đoạn chọn chiến lược trong mã gốc khớp **7.724/7.724 ca** với bảng
luật phân tích dưới đây. Chưa viết thêm MQL5 cho phần này.

| Nơi chạy | Đoạn mã gốc, cuối không tính | Số ca khớp |
|---|---|---|
| Khởi tạo, hàm `0xc30` | `0x3892..0x3ce6` | 3.862/3.862 |
| Điều phối, hàm `0x17f00` | `0x18c50..0x19084` | 3.862/3.862 |

[Kết quả và mã kiểm tra](bot-cua-toi-3/phan-tich/chon-chien-luoc/select-20261023-r1/summary.json),
[từng ca](bot-cua-toi-3/phan-tich/chon-chien-luoc/select-20261023-r1/results.jsonl),
[công cụ](cong-cu/phan-tich-chon-chien-luoc-bot-3.py).

## Chọn thủ công: phải nối đúng thứ tự

Khi `TradeFrequency=6`, hai đoạn mã gốc cùng nối như sau. Chỉ số bên
trong tính từ 0, đúng chỉ số truyền vào hàm xử lý chiến lược.

| Cài đặt | Chỉ số chiến lược bên trong |
|---|---|
| `RunStrat1` | 0 |
| `RunStrat2` | 1 |
| `RunStrat3` | 2 |
| `RunStrat4` | 3 |
| `RunStrat5` | 5 |
| `RunStrat6` | 4 |
| `RunStrat7` | 7 |
| `RunStrat8` | 8 |
| `RunStrat9` | 6 |

Đã chạy đủ **512 tổ hợp bật/tắt**, mỗi tổ hợp với hai giá trị
`UseVariableValues` và ba trạng thái ban đầu, ở cả hai đoạn mã: 6.144 ca.
Chọn thủ công ghi đủ 9 cờ, giữ nguyên hệ số tính khối lượng đang lưu.

Thứ tự xử lý tìm được trong hàm điều phối là chỉ số
`0,3,1,2,5,4,8,6,7`, tương ứng thứ tự cài đặt `1,4,2,3,5,6,8,9,7`.
Chưa coi thứ tự gọi này là bằng chứng đã phục hồi luật giao dịch.

## Các chế độ cố định

Các chế độ 0–4 chỉ ghi lại sáu cờ có chỉ số 3–8; **giữ nguyên ba cờ
đầu**. Không được tự thêm thao tác đặt lại ba cờ đó vào bản dựng.

| Giá trị `TradeFrequency` | Mục được bật thêm ngoài ba cờ đầu | Hệ số khi `UseVariableValues=true` / `false` |
|---|---|---|
| 0 | không có | 3,0 / 2,4 |
| 1 | 4, 5 | 4,0 / 3,4 |
| 2 | 4, 5, 6, 7 | 5,0 / 4,1 |
| 3 | 4, 5, 6, 7, 8 | 5,6 / 4,8 |
| 4 | 4, 5, 6, 7, 8, 9 | 6,0 / 5,1 |

Các mục còn lại trong sáu cờ được tắt. Hệ số lưu ở vị trí `0x76fa8`,
được hàm tính khối lượng sử dụng; không phải khối lượng cuối cùng.

## Chế độ tự chọn

Chỉ vào nhánh tự chọn khi **đồng thời** `TradeFrequency=5` và
`Risk=1234`. Số dùng so ngưỡng được tính theo đúng thứ tự:

```text
(MaxAllowedDD / 100) × số dư sau hàm đổi tiền 0x8300
```

Khi ba cờ ngưỡng bên trong đều bật, chọn chế độ:

- Lớn hơn 810: chế độ 3.
- Nếu không, lớn hơn 560: chế độ 2.
- Nếu không, lớn hơn 330: chế độ 1.
- Còn lại: chế độ 0.

**Bằng ngưỡng chưa chuyển lên chế độ cao hơn.** Nhánh này không chọn
chế độ 4. Khi một cờ ngưỡng tắt, ngưỡng tương ứng trở thành 0. Đã so
cả tám tổ hợp ba cờ, các giá trị ngay dưới/bằng/ngay trên ngưỡng, số 0,
số âm và số không hữu hạn. Việc nạp và duy trì các cờ trong toàn bộ EA
vẫn cần kiểm riêng.

Nếu `TradeFrequency=5` nhưng `Risk` khác 1234, đoạn chọn giữ nguyên các
cờ và hệ số, ghi chế độ đang lưu là 5. Giá trị ngoài bảng cũng giữ các
cờ/hệ số; các ca kiểm gồm -1 và 7. Đây là hành vi đã thấy, không phải
khuyến nghị cho phép người dùng nhập các giá trị đó.

## Phạm vi đã kiểm và còn thiếu

Mỗi đoạn có 248 ca chế độ cố định/ngoài bảng, 3.072 ca thủ công,
512 ca ngưỡng tự chọn và 30 ca thứ tự tính phần trăm. Chạy đúng byte mã
chụp; các giá trị nạp sẵn của thanh ghi lấy từ lệnh gốc, có vị trí trong
biên nhận. Theo dõi nơi ghi để phát hiện tác dụng ngoài vùng dự kiến.

Phép kiểm **cấp sẵn số dư và kết quả đổi tiền** tại hai ranh giới gọi
hàm; phần đổi tiền đã có bộ kiểm riêng trước đó. Vì vậy chưa chứng
minh toàn bộ luồng khởi tạo/điều phối đã ghép đúng. Chưa kiểm tên lựa
chọn trên cửa sổ cài đặt, điều kiện tiếp tục quản lý vị thế của chiến
lược đã tắt, toàn bộ cách cấp tham số, điều kiện vào lệnh hay sự kiện
ngoài máy thử. Các phần này vẫn thuộc P03/P04/P11/P17 trong bản đồ.
