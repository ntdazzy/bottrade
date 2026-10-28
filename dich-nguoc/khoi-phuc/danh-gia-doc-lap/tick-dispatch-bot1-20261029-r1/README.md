# Nối chọn mã, dọn bảng và vòng chiến lược — bot 1

`Bot1RunConfiguredTick` dùng chung mã giá, bảng dừng lỗ ảo, danh
sách vé và cờ chọn chiến lược. Không tạo bản sao tại chỗ ghép.
Không nhận diện mã giá thì trả `false`, để bên gọi xử lý đường
đánh giá trực tiếp. Nhận diện được thì dọn bảng khi cờ khác 0,
sau đó đọc lần lượt 8 cờ và gọi đúng chiến lược được bật.

| Phần | Bằng chứng gốc | Kết quả |
|---|---|---|
| Chọn mã và chép chuỗi | `0x11f3f`; mã biểu đồ `0x6a428`, mã đang xử lý `0x67918` | Giữ đúng hoa thường, NULL/rỗng và đường đi |
| Cờ dọn bảng | `0x12409`, byte `0x6a600` | Khác 0 gọi nguyên thân `0x18790` một lần |
| Bảng/danh sách vé | `0x62590`, `0x6a3c0` | So 1.500 ô và toàn bộ mảng vật lý, cả ở mỗi lần gọi chiến lược |
| Vòng chọn chiến lược | `0x12424..0x16730`, cờ `0x6a580+8*i` | 256 tổ hợp; đọc cờ mới ngay trước mỗi lần gọi |
| Đổi cờ khi đang chạy | Trong dịch vụ dọn bảng hoặc sau lời gọi chiến lược | 24 ca đổi trong dọn bảng; 54 ca đổi giữa các chiến lược |
| Đường đánh giá riêng | `0x12004` | Dừng đúng chỗ, không chạy hoặc giả kết quả đánh giá |

Lượt **`b1-tick-dispatch-20261029-r2`: 856/856 ca khớp**; ghi 2.914
lần gọi chiến lược và 2.915 lời gọi dịch vụ dọn bảng. Mã gốc
chạy liền từ chọn mã tới hết vòng gọi; không đặt lại thanh ghi
hoặc dữ liệu ở `0x12424`. Thân dọn bảng chạy thật. Tám thân chiến
lược được thay bằng bộ ghi ở cả hai phía để so đúng chỗ ghép.

Mỗi lần ghi chiến lược so chỉ số, cờ đang bật, mã giá, toàn bộ bảng
và danh sách vé. Cũng so mã lỗi, trạng thái chọn vị thế, thứ tự và
đối số dịch vụ. Dữ liệu mảng sau thay kích thước được đo từ MQL5.

Nguồn kiểm `b1-tick-dispatch-check-20261029-r1` và bộ ghép 110 tệp
`.mqh` `b1-all-headers-api-20261029-r4`: **0 lỗi, 0 cảnh báo**.
Kiểm độc lập không thấy lỗi trong phần ghép. Lượt dữ liệu `r1`
đã chạy MT5 nhưng bộ đọc kết quả lỗi tên biến Python; giữ bằng
chứng cũ, sửa bộ đọc và chạy lượt `r2` bằng cùng EX5 đã biên dịch.

Ba tệp cũ `Bot1AccountStateVolume.mqh`, `Bot1AccountVolume.mqh`,
`Bot1Withdrawal.mqh` chỉ khác ký tự xuống dòng giữa Git và nguồn
đã kiểm. Lưu nguyên byte nguồn đã biên dịch, không đổi luật bot.

## Chạy lại và giới hạn

`kiem-noi-don-bang-vong-bot-1.py`: `generate`, `prepare RUN`,
`mql5 RUN --build BUILD`, `original RUN`, `compare RUN`.
Dùng tên lượt mới và MT5 bot 1 riêng; chạy MQL5 trước mã gốc.

EX5 chuẩn giữ nguyên SHA-256
`a3b0de423a06e10ebedc279307b93d7cb9188ba2bb5de77131a913c865b0e922`.
Các vùng quyền dùng bị chặn, không gửi lệnh thật. Phản hồi dịch
vụ và thay đổi trong lời gọi được cấp bằng dữ liệu kiểm.

Còn thân 8 chiến lược trong phép kiểm nối, đường đánh giá trực
tiếp, đoạn sau `0x16730`, lỗi cấp phát/toàn trạng thái tại lỗi và
EA đầy đủ. Đây chưa phải chạy cặp hai EA hoàn chỉnh.

[Số liệu](verification.json), [danh sách tệp](../tick-dispatch-bot1-20261029-r1-manifest.txt).
