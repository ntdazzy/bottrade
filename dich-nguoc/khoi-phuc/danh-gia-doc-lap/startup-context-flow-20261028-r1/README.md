# Nối ngữ cảnh, chuẩn bị đầu và cuối khởi động bot 1

`Bot1StartupContextFlow.mqh` chạy liên tục ngữ cảnh khởi động,
chuẩn bị chiến lược 0 và phần cuối. Mã gốc chạy từ `0x3827` đến
lệnh trả về `0x5658`, qua lời gọi `0x7500` tại `0x3ca9`.

## Kết quả

- `b1-startup-context-flow-20261028-r1`: **459/459 ca khớp**,
  238 giá trị, 1.800 ô bảng, 25.100 lời gọi và 25.619 phép số học
  CPU thật. Bản gốc không bị đặt lại bộ nhớ hoặc thanh ghi tại hai
  chỗ nối. Bộ kiểm gồm 161 ca chuẩn bị và 298 ca ngữ cảnh đã có.
- Bình luận giao dịch `0x62470` và mã chiến lược `0x6246c` được giữ
  trong cùng `Context`; mã gốc `0x6a610` nằm trong `ContextInputs`.
  Mã giá `0x67918` được ngữ cảnh ghi thẳng vào `Inputs.symbol`.
- Ba bình luận tiếp tục tách riêng: đầu vào chuẩn bị `0x622d0`,
  đầu ra chuẩn bị `0x62480`, bình luận giao dịch `0x62470`.
- Đuôi mã rỗng/có sẵn, mã giá ngắn/dài/NULL/UTF-16, số không hợp lệ
  trong kích thước bảng và các lần chuẩn bị trả sớm đều được so.
- Chương trình kiểm `b1-startup-context-flow-check-20261028-r2` và
  bộ ghép 105 tệp `b1-all-headers-api-20261028-r28` biên dịch 0 lỗi,
  0 cảnh báo. Codex kiểm độc lập không phát hiện lỗi trong phần nối.

## Điều kiện đầu vào và giới hạn

Phần tài khoản phía trước chưa nằm trong lượt kiểm này. Bộ chạy
cấp điều kiện `XMM6=+0.0`, vùng trả chuỗi số đã nạp và các chuỗi tạm
trên ngăn xếp ban đầu rỗng, giống điều kiện của phép kiểm ngữ cảnh
trước đó. Không gọi đây là chạy từ đầu `OnInit`.

Hai hàm tìm mức và ba hàm bảng vẫn dùng bộ ghi đối số/thay đổi;
phản hồi MT5 và cấp phát chuỗi thành công được cấp. Các cài đặt
chế độ/rủi ro/bước vốn dùng cùng giá trị cho đầu vào chuẩn bị và bảng
trước khi chạy, không thay đổi trong lời gọi. Chưa kiểm cấp phát
lỗi, trạng thái cuối khi lỗi, khởi tạo trước `0x3827` hoặc toàn EA.

Bằng chứng ba lỗi mảng/chia 0 trong đoạn từ chuẩn bị đầu vẫn được
giữ tại [lượt chuẩn bị](../startup-preparation-flow-20261028-r1/README.md);
chưa gọi đó là ba phép kiểm lỗi bắt đầu từ ngữ cảnh.

Bốn tệp vốn cũ có khác biệt ký tự xuống dòng so với Git. Bộ ghép
105 tệp kiểm nguồn tại máy; phép công bố riêng kiểm đúng từng byte
phần mới và các tệp được chương trình kiểm sử dụng.

## Chạy lại

`cong-cu/kiem-noi-ngu-canh-khoi-dong-bot-1.py`:
`generate`, `prepare RUN`, `mql5 RUN --build BUILD`, `original RUN`,
`compare RUN`. Dùng MT5 riêng và tên lượt mới, giữ bằng chứng cũ.

[Mã kiểm và kết quả](verification.json), [danh sách tệp](manifest.txt).
