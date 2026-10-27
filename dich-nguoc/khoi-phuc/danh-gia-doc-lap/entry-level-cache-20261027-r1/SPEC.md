# Ghép cổng vào và lưu mức giá

Nguồn mới: `BotNEntryLevelCache.mqh`, `BotNEvaluationEntryLevels.mqh`.
Luồng trước đó qua tin/cuối tuần/chênh lệch/đặt lại/giới hạn lệnh giữ
chung trạng thái. Chỉ nối tới B1 `0x1ca24`, B3 `0x26f9e`.

- Dừng khi cờ đóng cuối tuần khác0, cờ lệnh khác1 hoặc cờ phụ khác0.
- Chụp timestamp cũ trước lần gọi iTime đầu tiên. Bằng nhau thì trả
  quyết định cùng nến, dừng trước helper thống kê/hiển thị.
- Khác nhau: gọi iTime lần hai bằng mã/khung hiện tại, ghi timestamp
  theo chỉ số caller đã chụp. Chỉ khi aux_older dương mới tính mức.
- Gọi nguyên thân Upper rồi Lower. Chỉ số ghi giá là chỉ số toàn cục
  đọc mới sau mỗi helper; khác chỉ số caller dùng cho timestamp.
- `upper = offset*unit + (upper_result + spread)`;
  `lower = lower_result - offset*unit`. Giữ thứ tự toán hạng/số thực.
- Source PriceLevels trước đây nhận bản sao của symbol/last_shift/
  quote/gap. Mã gốc giữ địa chỉ dữ liệu và đọc lại sau dịch vụ. Hai
  chữ ký đổi sang tham chiếu hằng; thân tìm mức/làm tròn giữ nguyên.
  Bản trước sửa được giữ nguyên byte trong `BotNPriceLevels-before.mqh.txt`.
  Upper mặc định9999, Lower mặc định0.

Chỉ số caller là đầu vào bất biến. Ô ngăn xếp chứa nó có thể được
nhánh thoát sớm tái sử dụng; bộ so kiểm ô thật khi tới đúng cổng đang
dùng chỉ số. Không lấy ô đã hết dùng làm trạng thái chiến lược.

`kiem-cap-nhat-muc-gia-bot-1-3.py prepare|mql5|original|compare BOT RUN`;
`mql5` cần `--build BUILD`. Bộ ghi tạo bằng
`tao-bo-kiem-cap-nhat-muc-gia.py`.

R4: **1.128/1.128 ca mỗi bot**, so **22.551/22.926 lần gọi dịch vụ**,
toàn bộ800ô bảng cùng trạng thái/chuỗi/yêu cầu. Nguồn trực tiếp và
bộ kiểm0lỗi/0cảnh báo. Nguyên các thân tìm mức/làm tròn gốc tự chạy; iHigh/iLow/iTime và
các dịch vụ MT5 được cấp trả lời.

Có cổng đóng/bật/cờ phụ, timestamp bằng/khác/âm, ô0/7/8/99, aux_older
âm/0/dương, vòng dò/độ chính xác/NaN/vô cực và dữ liệu thay ở rìaSDK:
timestamp, symbol/khung, quote/gap, phạm vi dò, chỉ số, độ lệch/đơn vị/
chênh lệch và giá cuối sau khi đọc chữ số. Mọi đối số và trạng thái
trước dịch vụ phải khớp, không chỉ giá cuối.

Các lượt chưa đạt được giữ riêng. `RECORDER-FIX.md` giải thích ghi
đối số string trước tác động của dịch vụ và phạm vi sống ô ngăn xếp.
`READER-PERFORMANCE.md` ghi phép đo: ca79 đọc đủ13.670.524byte giảm
từ11,047giây xuống0,611giây bằng cách tránh chép lặp phần băng còn lại;
không đổi giới hạn chạy hoặc phép so. Khối dữ liệu được kiểm theo
số byte còn lại trong tệp. Không nới kết quả để bỏ sai khác.

Rà độc lập `friday_flow_review` không thấy lỗi đáng kể trong nguồn,
thứ tự tính/đọc và bộ ghi. Nhận xét không thay phép so.

Chưa chạy helper thống kê cùng nến, nhánh phát sinh lệnh phía sau,
đầy đủ khởi tạo/hiển thị/lỗi cấp phát/mạng lịch hoặc toànEA. Khung đầu
đoạn, dịch vụ/lỗi dịch vụ, định dạng số và cấp phát thành công được
cấp. Chưa có cặp toàn bot; số ca đạt không phải tỷ lệ hoàn thành bot.
