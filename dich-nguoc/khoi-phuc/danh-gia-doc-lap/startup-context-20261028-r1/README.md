# Ngữ cảnh trước lần chuẩn bị đầu — bot 1

Đã viết `Bot1InitializeStartupContext` cho nguyên đoạn OnInit
`0x3827..0x3c9d`, dừng trước lời gọi chuẩn bị đầu tại `0x3ca9`:

- Sao chép bình luận gốc; không thêm đuôi chiến lược ở nơi này.
- Đặt vốn đỉnh ngày và cờ dừng ngày về 0; giữ số nến ngày đã có.
- Đặt mốc bảng về 0, mã chiến lược bằng mã gốc chưa cộng 1.
- Bộ đếm lịch sử: tổng `-1`, số vị thế lưu `0`; không xóa các dãy.
- Bật cờ dọn mở rộng, tính lại vị trí ô bảng theo đúng thứ tự nhân.
- Sao chép mã giá; chỉ khi đuôi đang là chuỗi rỗng mới lấy tối đa
  10 ký tự từ vị trí 6. Giữ khác biệt giữa NULL và chuỗi rỗng, cả mã lỗi.

Lượt `b1-startup-context-20261028-r1`: **298/298 ca khớp**, 30 lần in
thông báo, 1.192 phép nhân trên CPU thật. So 17 trường, năm chuỗi,
mã lỗi, trạng thái trước in và trạng thái cuối. Có giới hạn số nguyên,
byte 0/1/2/255, Unicode, tên ngắn/dài/rỗng/NULL, số không có dấu khác
nhau, vô cực và NaN với dấu/phần trị riêng. Bộ kiểm biên dịch 0 lỗi,
0 cảnh báo. Không nới sai số.

Bản gọi trực tiếp dịch vụ `b1-startup-context-api-20261028-r1` và
bản ghép 99 tệp `.mqh` `b1-all-headers-api-20261028-r21` cũng biên
dịch 0 lỗi, 0 cảnh báo.

## Các giá trị nối từ phần trước

Phép so cấp hai giá trị nối theo phần vốn đã phân tích; chưa chạy
liên tục từ đầu khối vốn tới đoạn này:

- `XMM6` là `+0.0`: OnInit ghi tại `0x1925`, sau đó khối dữ liệu lịch
  không thay đổi nó. Vì vậy nhánh không dùng kích thước ô vẫn giữ
  phép nhân số 0, kể cả với giá trị không hữu hạn.
- Vùng chuỗi trả về của SDK chứa chuỗi số tài khoản không rỗng từ
  lần `IntegerToString` trước đó. Bộ kiểm đặt chuỗi `12345` ở vùng
  tương ứng. Giá trị chữ số không tham gia kết quả đoạn này.

Mã gốc, các hàm sao chép/cắt/ghép chuỗi chạy nguyên. Do Unicorn xử lý
NaN có thể khác CPU, bốn lệnh `MULSD` đã được kiểm đúng byte/vị trí
và thực hiện trên CPU. Cấp phát chuỗi luôn được cấp thành công.
Chưa kiểm cấp phát thất bại, toàn bộ khởi tạo tĩnh, toàn OnInit hay EA.

Tên các trường dùng lại từ `Bot1DailyLossState`, `Bot1PanelCreationState`,
`Bot1StrategyContextState` và `Bot1StrategyHistoryCache`; không tạo
lại các trạng thái đó riêng trong mỗi lần gọi.

## Phần cần nối tiếp

Khởi tạo tĩnh `0x20a00..0x2274f` khác OnInit. Đã xác nhận bằng lệnh
gốc rằng đầu vào iATR ban đầu có chu kỳ `30` (`0x21b7d`), dùng ngày
(`0x21b6d`) và giá tham chiếu `0.0` (`0x21c09`). Chưa dựng toàn bộ
mặc định số/chuỗi và phần nối với đầu vào người dùng; không thay
chúng bằng cấu hình chiến lược 0 khi gọi chuẩn bị đầu.

Sau đó còn phần sau chuẩn bị, các mảng lệnh, lịch sử và ba bước bảng
cuối OnInit. Bộ điều phối đầy đủ, các sự kiện và so cặp EA vẫn chưa có.

## Chạy lại

Biên dịch `Bot1StartupContextCheck.mq5` bằng `bien-dich.ps1`, rồi gọi
`kiem-ngu-canh-khoi-dong-bot-1.py prepare RUN`,
`mql5 RUN --build BUILD`, `original RUN`, `compare RUN`.
Dùng tên lượt mới và MT5 riêng; `generate` chỉ dùng khi chưa có tệp kiểm.
