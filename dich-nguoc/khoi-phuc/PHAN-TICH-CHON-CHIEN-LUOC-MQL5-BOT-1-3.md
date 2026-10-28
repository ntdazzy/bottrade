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

Làm rõ ngày 28/10: các bit trong `enabled_mask` là vị trí cờ ở
`0x6d220..0x6d228`, khác chỉ số truyền vào hàm đánh giá. Các phép so
dưới đây so vị trí cờ thật; cần nối vị trí sang chỉ số khi chạy vòng.
[Bảng nối](danh-gia-doc-lap/strategy-loop-20261028-r1/bot3-gate-mapping.json).

`Bot3SelectStrategies` giữ các hành vi đã thấy trong hai đoạn gốc:

- Chế độ 0–4 chỉ thay sáu cờ sau, giữ nguyên ba cờ đầu.
- Hệ số thay đổi theo `UseVariableValues`: lần lượt
  `3/2.4`, `4/3.4`, `5/4.1`, `5.6/4.8`, `6/5.1`.
- Chế độ 5 chỉ tự chọn khi `Risk=1234`; ngân sách là
  `(MaxAllowedDD/100) × converted_balance`, so ngưỡng theo thứ tự 810,
  560, 330 và dùng dấu `>`.
- Chế độ 6 nối mặt nạ menu vào các ô cờ
  `0,1,2,3,5,4,7,8,6`.
- Giá trị tần suất ngoài các nhánh trên được giữ nguyên cùng cờ/hệ số.

`converted_balance` và ba cờ ngưỡng được truyền vào như ranh giới dữ
liệu đã đo từ mã gốc. Nguồn chưa tự nối phần đổi tiền, sự kiện MT5,
thân chiến lược, quản lý vị thế hoặc điều kiện vào lệnh.

## Cách kiểm

Lượt hiện hành `strategy-20261024-r2` dùng đúng 256 ca đã kiểm của bot 1 và 7.724
ca của bot 3. Hai chương trình kiểm được biên dịch trong MT5 riêng, chạy
với giao dịch bị tắt, rồi so mặt nạ, chế độ và bit hệ số với kết quả gốc.

Claude Opus 5.5, mức `max`, đã [kiểm độc lập](danh-gia-claude/selector-20261024-r1/review.md).
Mình đã đối chiếu các nhận xét và sửa bộ kiểm: lấy trực tiếp
`original_selected_profiles`/`original`, kiểm mã băm kết quả gốc, từ chối
ca gốc chưa khớp, nối đúng nguồn/EX5 với biên nhận biên dịch và kiểm độ
dài tệp đầu vào. Kết quả vẫn là 256/256 và 7.724/7.724; không sửa công
thức MQL5 vì chưa thấy sai trong phần này.

7.724 là hai đoạn mã gốc × 3.862 đầu vào khác nhau, không phải 7.724 đầu
vào độc lập. Bot 1 trả đúng mặt nạ đầu vào nên hai tệp nhị phân có thể
cùng mã băm; kết quả mong đợi nay lấy từ đích nhánh mã gốc đã quan sát,
không lấy trực tiếp mặt nạ đầu vào.

Giới hạn vẫn còn: phần này chưa chứng minh thứ tự gọi toàn bộ EA, quản lý
vị thế khi chiến lược tắt, điều kiện mua/bán, bảng hiển thị hay các lỗi
ngoài đoạn chọn.

Khi ghép bot 1 phải giữ thứ tự kiểm A→H và chạy khối tham số ngay sau
cổng đang bật. Bot 3 chỉ được đọc số dư/đổi tiền trong nhánh tần suất 5,
rủi ro 1234; ba cờ ngưỡng tương ứng byte 1–3 của mảng năm cờ dùng ở phần
khối lượng, khác với mặt nạ chín chiến lược. `initial_mode` luôn bị ghi
đè trong đoạn chọn; các giá trị cần giữ là mặt nạ đang lưu và hệ số.
