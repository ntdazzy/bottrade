# Phân loại mã giá trước vòng chiến lược bot 1

Đã phục hồi `Bot1PrepareTickSymbol` từ đoạn điều phối bắt đầu
`0x11f3f`. Cả hai đường đều chép mã biểu đồ vào mã đang xử lý:

- Khớp một mẫu được nhận diện: tới `0x12409`, trước kiểm cờ dừng
  do bot quản lý và vòng chiến lược đã cấu hình.
- Không khớp hoặc mã NULL: tới `0x12004`, trước lần đánh giá trực
  tiếp với chỉ số 0. Chưa chạy thân đánh giá trong lượt này.

11 chuỗi lấy từ byte gốc tại `0x529fc..0x52b3c`: `XAUUSD`, `xauusd`,
`GOLD`, `gold`, `Gold`, `XAU`, `xau`, `XAG`, `xag`, `GC`, `gc`.
Tám chuỗi đầu dừng ngay khi khớp. Hai lần tìm `xag` và `GC` đều chạy
trước phép kiểm bit có dấu; cuối cùng mới tìm `gc` nếu cần.
Không đổi thành tìm không phân biệt hoa thường hoặc chỉ nhận vàng.

## Bằng chứng

- `b1-tick-symbol-20261029-r2`: **121/121 ca khớp** cờ chọn đường,
  mã lỗi, chuỗi đầu vào và chuỗi đã chép. Có NULL/rỗng, tiền tố/
  hậu tố, UTF-16, chữ hoa thường khác nhau và chuỗi dài.
- Mã gốc chạy nguyên các nhánh tìm chuỗi, gồm các nhánh nằm ngoài
  dòng chính đến `0x17276`. Dừng ở hai điểm đã nêu trước khi gọi
  đánh giá/dọn bảng/vòng chiến lược.
- Nguồn kiểm `b1-tick-symbol-check-20261029-r2` biên dịch 0 lỗi,
  0 cảnh báo; bộ ghép hiện hành có 108 tệp, cũng biên dịch sạch.
- Codex kiểm độc lập không phát hiện lỗi trọng yếu.

Đây là chọn đường theo sản phẩm giao dịch, không phải kiểm tài
khoản/quyền dùng. Bộ chạy chặn nếu tới `0xc30`, `0x5880`, `0x3d6c0`
hoặc `0x4d260`. Cấp phát chuỗi thành công được cung cấp; chưa kiểm
lỗi cấp phát hoặc toàn bộ luồng khi có giá mới/EA.

## Chạy lại

`cong-cu/kiem-ma-gia-dieu-phoi-bot-1.py`: `generate`, `prepare RUN`,
`mql5 RUN --build BUILD`, `original RUN`, `compare RUN`. Dùng tên
lượt mới và máy MT5 riêng; không ghi đè bằng chứng.

[Kết quả tổng hợp](verification.json), [danh sách tệp chung](../dispatch-and-bot3-context-20261029-r1-manifest.txt).
