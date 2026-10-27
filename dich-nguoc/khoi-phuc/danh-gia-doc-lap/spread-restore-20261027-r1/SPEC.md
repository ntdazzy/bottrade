# Ghép tin, cuối tuần, chênh lệch giá và đặt lại lệnh

Nguồn mới: `BotNPendingQueueLive.mqh`, `BotNNewsFridaySpreadRestoreFlow.mqh`.
Giữ nguyên EX5; các thân lịch, hủy, mở, chọn khớp, gửi và báo lỗi gốc
tự chạy. Không cấp kết quả hàm con thay thuật toán.

Luồng đã ghép: tin → cuối tuần → lưu/hủy khi chênh lệch cao → đặt lại
lệnh khi chênh lệch thấp. Dừng trước giới hạn lệnh: B1 `0x1c85c`,
B3 `0x269fb`. Vùng gốc và mã kiểm tra trong `native-bindings.json`.

- Cổng dưới dùng `unit*minimum >= spread`; NaN không qua.
- Tránh đặt lại cuối tuần dùng bit thấp cờ bật và ngày/giờ, theo
  `AND AL,CL`. Nhánh đóng cuối tuần đầu tiên vẫn so cờ đúng 1.
- Hàng đợi vào khi cờ đúng 1; quét 100 ô, so giá với `threshold_a`
  (`0x66a70/0x73ab0`), khác khoảng cách của nhánh hủy tin.
- Hai nhánh mua/bán độc lập. Sau thông báo, mỗi lần gửi/thử lại lấy
  mới ghi chú, hạn, mức dừng/chốt, đơn vị, mã sản phẩm/mã chiến lược.
  Ngữ cảnh cục bộ chỉ dùng cho một lần gửi.
- Thất bại: còn lỗi132 thì chờ2500 và gửi lại; sau vòng báo lỗi,
  tăng bộ đếm đúng thứ tự. Không tự thêm giới hạn thử lại.
- Đọc lại bit thấp cờ hàng đợi sau mỗi hàng; nếu còn bật thì xóa đúng
  100×3 số của bảng lệnh, giữ bảng kết quả.

`kiem-khoi-phuc-lenh-da-luu-bot-1-3.py prepare|mql5|original|compare BOT RUN`;
`mql5` cần `--build BUILD`. Bộ ghi tạo bằng
`tao-bo-kiem-khoi-phuc-lenh-da-luu.py`.

R2: **801/801 ca mỗi bot**, so **19.260/19.635 lần gọi dịch vụ**,
500 ô bảng, toàn bộ trường giao dịch/chuỗi/trạng thái trước dịch vụ
và cuối đoạn. Nguồn trực tiếp và bộ kiểm đều 0 lỗi/0 cảnh báo.

Có cờ0/1/2/3/255, hàng0/1/50/99, gửi đồng bộ/bất đồng bộ, nhận/từ chối,
lỗi0/3/132/999, thử lại một/hai lần, bộ đếm tràn và hạn0/1/255.
Dịch vụ đổi dữ liệu sau thông báo/gửi/chờ để bắt việc giữ bản sao cũ;
hai nhánh cùng hàng vẫn chạy nếu dịch vụ đổi loại lệnh giữa chừng.

Mã lỗi được cấp tại rìa dịch vụ vì MQL5 không cho đặt mã lỗi hệ thống
bất kỳ. Nguồn bàn giao gọi GetLastError thật; bộ ghi chỉ thay khi cần.
Đổi số thành chữ đo thật trong MT5, kiểm bảo toàn mã lỗi bằng
SetUserError(7); 0xffffffff trong dữ liệu đổi kiểu là cờ bảo toàn lỗi.
Mã gốc phải yêu cầu đúng loại và giá trị số.

Lời chờ được ghi đúng2500, không chờ thật. Điền bộ nhớ chỉ cấp đúng
hợp đồng `(địa chỉ bảng lệnh,0,2400)`. Không đặt lại trạng thái giữa
các phần. Ô tạm trả chuỗi được cấp rỗng ở đầu đoạn; xem `CACHE-FIX.md`.
Rà độc lập `friday_flow_review` không thấy lỗi đáng kể trong nguồn,
cổng, số học và bộ ghi; nhận xét không thay phép so.

Chưa ghép giới hạn lệnh và các cổng vào phía sau. Khung đầu đoạn,
lịch, trả lời/lỗi dịch vụ và cấp phát thành công được cấp. Chưa kiểm
mạng lịch, lỗi cấp phát hoặc đầy đủ khởi tạo. Chưa có EA đầy đủ;
chưa chạy cặp toàn bot. Số ca đạt không phải tỷ lệ hoàn thành bot.
