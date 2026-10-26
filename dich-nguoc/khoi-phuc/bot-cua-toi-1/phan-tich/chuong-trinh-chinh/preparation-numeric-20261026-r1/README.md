# Bot 1 — bộ chuyển dữ liệu vào khối chuẩn bị số

Đã thêm `Bot1PreparationNumeric.mqh` và Script biên dịch. Khối nhận sẵn
giá trị chỉ báo, tick, điểm, chữ số, mức dừng/đóng băng và thời gian rồi gọi
`Bot1PrepareDistances` hiện có; không gọi dịch vụ MT5, không đặt lệnh và
không phải vòng sự kiện EA.

Biên dịch Script API: **0 lỗi, 0 cảnh báo**. Chưa có bộ so native riêng cho
adapter này; vì vậy chưa gọi phần này là đã khớp toàn bộ thân chuẩn bị
`0x7500..0x831d`. Các nhánh dịch vụ, lỗi chỉ báo, bảng/comment và nơi gọi
EA vẫn còn mở.
