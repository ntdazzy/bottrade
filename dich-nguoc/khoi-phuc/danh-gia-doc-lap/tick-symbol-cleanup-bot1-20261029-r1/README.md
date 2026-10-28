# Nối chọn mã giá và dọn bảng — bot 1

`Bot1TickStrategyPreparation.mqh` gọi phần chọn mã đã phục hồi, rồi
gọi nguyên `Bot1DropClosedVirtualStops` khi đi vào nhánh chiến lược
và cờ `0x6a600` khác 0. Nhánh trực tiếp trả `false` để phần gọi tiếp
tục đánh giá; hàm này chưa gọi bộ đánh giá hoặc vòng chiến lược.

| Phần | Bằng chứng gốc | Cách kiểm | Kết quả/còn thiếu |
|---|---|---|---|
| Chọn mã, sao chép mã | Từ `0x11f3f`, cả các nhánh tìm chuỗi ngoài đoạn liền | Theo đúng nhánh nhảy từ lệnh gốc, dừng trước `0x12004` hoặc đi `0x12409` | Khớp cả 11 mẫu, NULL/rỗng, Unicode, tiền/hậu tố |
| Cổng dọn bảng | `0x12409`, cờ `0x6a600`, gọi `0x18790` | Cờ 0/1/2/255; kiểm số lần gọi đúng từng ca | Nhánh trực tiếp và cờ 0 đều không gọi dọn |
| Dọn bảng thật | Thân `0x18790`; bảng `0x62590`, cờ `0x66410`, mảng `0x6a3c0` | Không đặt lại vùng nhớ; so trước/sau dịch vụ, 1.500 ô và cả mảng | Khớp; phản hồi vị thế được cấp |
| Điểm kết thúc | `0x12004` hoặc `0x12424` | Dừng trước đánh giá trực tiếp/vòng chiến lược | Chưa phải toàn xử lý giá mới |

## Kết quả

- Lượt `b1-tick-cleanup-live-20261029-r4`: **522/522 ca khớp từng
  byte**; gồm 484 ca chọn mã/cờ và 38 ca về bảng/danh sách lệnh.
- Có mã lỗi ban đầu, chuỗi NULL/rỗng, cờ khác 1, lệnh không còn mở,
  loại vị thế, mảng tăng từ 64 lên 128, mảng đảo thứ tự, cấp lại
  mảng thất bại rồi thử lại và dữ liệu cũ còn ở cuối mảng.
- Bộ kiểm chỉ cho đi vào các lệnh tìm chuỗi đạt được từ điểm bắt
  đầu, đoạn cổng và thân dọn; bốn điểm quyền dùng vẫn bị chặn.
- Nguồn kiểm `b1-tick-cleanup-live-check-20261029-r1` và bộ ghép
  `b1-all-headers-api-20261029-r3`: 0 lỗi, 0 cảnh báo; đủ 109 tệp
  `.mqh`. Bản lưu công cụ và nguồn của r4 khớp mã SHA biên nhận.

## Giới hạn

Không dùng bản chỉ chạy MQL5 hoặc phép so riêng 121 ca làm bằng
chứng cho phần nối. Các lượt cũ được giữ để tra cứu. Trong r4,
thân dọn chạy thật; các lần tăng mảng thành công được đo trong MQL5
rồi cấp cho mã máy sau khi kiểm đúng đối số và dữ liệu trước/sau.
Phản hồi tăng mảng thất bại được cấp riêng trong các ca tương ứng.

Chưa chạy tài khoản thật, kiểm các lỗi mảng làm dừng chương trình,
mọi lỗi cấp phát/lỗi dịch vụ, bộ đánh giá, vòng chiến lược hoặc EA
hoàn chỉnh. Đây chưa phải phép chạy cặp toàn bot.

Chạy lại: `cong-cu/kiem-noi-ma-gia-don-bang-bot-1.py generate`,
`prepare RUN`, `mql5 RUN --build BUILD`, `original RUN`, `compare RUN`.
Dùng tên lượt mới và máy thử riêng bot 1; chạy MQL5 trước mã máy.

[Số liệu/mã kiểm tra](verification.json), [danh sách tệp](../tick-symbol-cleanup-bot1-20261029-r1-manifest.txt).
