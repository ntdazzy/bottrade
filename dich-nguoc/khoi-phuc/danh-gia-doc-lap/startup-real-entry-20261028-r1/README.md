# Hai hàm tìm mức thật trong luồng khởi động bot 1

Lượt này chạy nguyên `Bot1EntryLevel` và `Bot1NearbyPending` từ
`Bot1EntryLevels.mqh` trong luồng khởi động sau cổng quyền dùng.
Phía gốc chạy cả hai thân tìm mức `0x265a0`, `0x26960` và hai thân
kiểm lệnh gần `0x3c670`, `0x3c8d0`. Không cấp sẵn kết quả mức giá.
Ba thân lấy lịch thật của lượt trước vẫn nằm trong cùng phép chạy.

## Bằng chứng

- `b1-startup-real-entry-20261028-r1`: **85/85 ca khớp**, 248 giá trị,
  2.700 ô bảng/lịch, 11.127 lời gọi và 6.786 phép số học CPU thật.
- Cả 85 ca có đọc giá theo hai chiều: 1.873 lần đọc giá cao và
  1.607 lần đọc giá thấp. Không có lần cấp kết quả qua bộ ghi mức
  giá cũ. 80 ca đi tới kiểm lệnh gần; 150 lần đọc tổng lệnh và
  212 lần đọc vé lệnh.
- Kiểm độ rộng nến/giới hạn quét, dữ liệu nến ngắn/rỗng, số chữ số,
  giá đặc biệt, chặn một/hai ứng viên, giá sát ngưỡng, vé 0 và lệnh
  không khớp mã nhận diện/mã giá/loại. Giữ vòng quét bắt đầu ở
  `OrdersTotal()`, kể cả lần đọc chỉ số ngoài phạm vi trả vé 0.
- Sáu ca lỗi lịch từ lượt trước được nối qua các hàm tìm mức thật.
- Bản kiểm `b1-startup-real-entry-check-20261028-r1` biên dịch 0 lỗi,
  0 cảnh báo. Codex kiểm độc lập không thấy lỗi trọng yếu.

Mã bot không đổi trong lượt này; thay các lời đáp mức giá bằng thân
mã đã phục hồi để kiểm cách chúng dùng chung trạng thái khi ghép.

## Giới hạn

Dịch vụ giá nến, danh sách/thuộc tính lệnh, lịch, tài khoản, lưu trữ
và cấp phát thành công được cấp dữ liệu thử. Không gửi lệnh giao
dịch. Ba hàm bảng còn dùng bộ ghi. Còn cổng quyền dùng, trạng thái
ban đầu trước cổng, các lỗi chưa phủ, sự kiện/cài đặt/giao diện và
chạy cặp toàn EA. 85 ca không phải tỷ lệ hoàn thành bot.

## Chạy lại

`cong-cu/kiem-noi-muc-gia-that-khoi-dong-bot-1.py`: `generate`,
`prepare RUN`, `mql5 RUN --build BUILD`, `original RUN`, `compare RUN`.
Dùng tên lượt mới và MT5 riêng; giữ bằng chứng cũ.

[Kết quả và mã kiểm](verification.json), [danh sách tệp](manifest.txt).
