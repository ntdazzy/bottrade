# Phục hồi bộ chọn chiến lược bằng MQL5 — bot 1 và bot 3

Phần này chỉ phục hồi đoạn chọn cờ/chế độ trước khi chạy thân chiến lược.
Nó không phải EA hoàn chỉnh và không đặt lệnh.

| Bot | Nguồn gốc | Ca dùng lại | Kết quả MQL5 | Biên dịch |
|---|---|---:|---:|---|
| 1 | 8 cổng tại `0x10f60` | 256 | 256/256 | 0 lỗi, 0 cảnh báo |
| 3 | Hai đoạn `0x3892..0x3ce6`, `0x18c50..0x19084` | 7.724 | 7.724/7.724 | 0 lỗi, 0 cảnh báo |

Bằng chứng đầy đủ nằm trong [KIEM-CHUNG-CHON-CHIEN-LUOC-MQL5-BOT-1-3.json](KIEM-CHUNG-CHON-CHIEN-LUOC-MQL5-BOT-1-3.json).
Công cụ chạy lại là [kiem-chon-chien-luoc-bot-1-3.py](cong-cu/kiem-chon-chien-luoc-bot-1-3.py).

## Bot 1

`Bot1SelectStrategies` giữ đúng thứ tự tám cờ `RunStrategyA` đến
`RunStrategyH`, tương ứng bit 0 đến bit 7. Mỗi cờ chỉ được so với 0;
phần dựng lại trả về mặt nạ cờ để phần điều phối dùng tiếp.

## Bot 3

`Bot3SelectStrategies` giữ các hành vi đã thấy trong hai đoạn gốc:

- Chế độ 0–4 chỉ thay sáu cờ sau, giữ nguyên ba cờ đầu.
- Hệ số thay đổi theo `UseVariableValues`: lần lượt
  `3/2.4`, `4/3.4`, `5/4.1`, `5.6/4.8`, `6/5.1`.
- Chế độ 5 chỉ tự chọn khi `Risk=1234`; ngân sách là
  `(MaxAllowedDD/100) × converted_balance`, so ngưỡng theo thứ tự 810,
  560, 330 và dùng dấu `>`.
- Chế độ 6 nối mặt nạ menu theo thứ tự nội bộ
  `0,1,2,3,5,4,7,8,6`.
- Giá trị tần suất ngoài các nhánh trên được giữ nguyên cùng cờ/hệ số.

`converted_balance` và ba cờ ngưỡng được truyền vào như ranh giới dữ
liệu đã đo từ mã gốc. Nguồn chưa tự nối phần đổi tiền, sự kiện MT5,
thân chiến lược, quản lý vị thế hoặc điều kiện vào lệnh.

## Cách kiểm

Lượt `strategy-20261024-r1` dùng đúng 256 ca đã kiểm của bot 1 và 7.724
ca của bot 3. Hai chương trình kiểm được biên dịch trong MT5 riêng, chạy
với giao dịch bị tắt, rồi so mặt nạ, chế độ và bit hệ số với kết quả gốc.

Giới hạn vẫn còn: phần này chưa chứng minh thứ tự gọi toàn bộ EA, quản lý
vị thế khi chiến lược tắt, điều kiện mua/bán, bảng hiển thị hay các lỗi
ngoài đoạn chọn.
