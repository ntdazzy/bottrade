# Ghép lịch tin và tìm điểm vào trong khởi động — bot 3

`Bot3StartupNewsFlow.mqh` nối từ `0xd60` tới trả về `0x5f34`,
sau cổng quyền dùng/chế độ kiểm thử. Cùng trạng thái được giữ qua
ba lịch tin → chọn tin → vốn → lịch dự phòng → chọn tần suất →
ngữ cảnh → chuẩn bị → tìm điểm vào → đuôi khởi động.

| Phép kiểm | Kết quả | Thân mã được chạy |
|---|---|---|
| `b3-startup-news-flow-20261029-r1` | 254/254 ca; 37.576 lời gọi; 15.494 phép tính | Phần nối, bộ chọn tin và các phần khởi động đã ghép; cấp kết quả ba lịch |
| `b3-startup-real-calendars-20261029-r2` | 158/158 ca; 24.703 lời gọi; 9.638 phép tính | Thêm nguyên ba thân lấy lịch |
| `b3-startup-real-entry-20261029-r1` | 85/85 ca; 17.417 lời gọi; 7.211 phép tính | Thêm hai thân tìm điểm vào và hai thân kiểm lệnh chờ gần giá |

Mỗi lượt so 284 trường, dãy chỉ báo, 2.800 ô bảng và 900 ô lịch;
so trạng thái, đối số, thứ tự lời gọi, kết quả và mã lỗi. Chưa chạy
ba thân bảng hiển thị trong các lượt trên. Không đặt lại trạng thái
giữa các đoạn nối.

## Bằng chứng gốc

Nền mã bot 3: `0x17156250000`. EX5 SHA-256:
`ee063d3d87490afe24e2f4ce85f6b05659320e297b102efd70207f71ca2feb83`.

- `0xd95` đặt mốc hỏi lịch `0x1d6cb8` về 0.
- Ba thân lịch: `0x6ad0`, `0x6f20`, `0x73b0`; gọi bộ chọn tại
  `0x1277`, vào phần vốn `0x1279`. Bộ kiểm buộc đoạn tin tự nạp
  các thanh ghi dịch vụ trước khi vào phần vốn.
- Tìm điểm mua/bán: `0x31cd0..0x3208b`, `0x32090..0x3244b`.
- Kiểm lệnh chờ gần giá: `0x47380..0x475d7`, `0x475e0..0x4783b`.
  Giữ vòng duyệt từ `OrdersTotal()` xuống 0 và phép so khoảng cách `<`.
- Bộ kiểm giữ vùng chuỗi `0x1d6e3c`, số `0x1d6e48`, lỗi `0x1d6e10`.

Lượt lịch `r1` dừng do bộ ghi giữ lỗi cũ 0, che lỗi mới 5035 từ
`StringSubstr("XAUUSD.a",6,10)`. Mã gốc ghi lỗi này tại `0x3f99`.
Đã sửa bộ ghi: nhận lỗi mới nếu có, giữ lỗi trước nếu lời gọi không
tạo lỗi mới. Không đổi luật nguồn bot. Giữ nguyên bằng chứng lượt lỗi.

Ba nguồn kiểm và bộ ghép 116 tệp `.mqh` biên dịch **0 lỗi, 0 cảnh báo**.
Ở các lượt này MetaEditor trả mã tiến trình 1, còn nhật ký ghi 0 lỗi/
0 cảnh báo và có EX5 mới. Lệnh biên dịch trả 0 theo kết quả nhật ký;
mã kiểm tra EX5 được lưu để đối chiếu. Không sửa biên nhận để che
mã tiến trình của MetaEditor.

Ba tệp cũ `Bot3AccountStateVolume.mqh`, `Bot3AccountVolume.mqh`,
`Bot3Withdrawal.mqh` chỉ khác ký tự xuống dòng giữa Git và nguồn
đã biên dịch. Lưu nguyên byte nguồn đã kiểm vào Git; không đổi mã
hoặc biên dịch lại. Toàn bộ 116 tệp phải khớp mã kiểm tra biên nhận.

Kiểm độc lập không thấy lỗi trong phần nối, cách ghi lỗi và ánh xạ
các lời gọi. Mã gốc và bằng chứng cũ được giữ nguyên.

## Cách chạy lại và giới hạn

Ba công cụ `kiem-noi-tin-khoi-dong-bot-3.py`,
`kiem-noi-lich-that-khoi-dong-bot-3.py`,
`kiem-noi-muc-gia-that-khoi-dong-bot-3.py` có cùng thứ tự:
`generate`, `prepare RUN`, `mql5 RUN --build BUILD`, `original RUN`,
`compare RUN`. Dùng tên lượt mới và MT5 bot 3 riêng.

Dịch vụ tài khoản, kho lưu, đồng hồ, lịch, giá và lệnh được cấp dữ
liệu trong bộ kiểm; không gửi lệnh thật. Cấp phát thành công và chuỗi
định dạng đo từ MQL5 được cấp. Không chạy quyền dùng hoặc thay kết
quả của phần bảo vệ. Còn lỗi cấp phát, toàn trạng thái tại lỗi,
ba thân bảng/ảnh vẽ thật và EA đầy đủ. Chưa là chạy cặp hai bot đầy đủ.

[Số liệu](verification.json), [danh sách tệp](../startup-news-entry-bot3-20261029-r1-manifest.txt).
