# Nối chuẩn bị đầu tới trả về — bot 3

`Bot3StartupPreparationFlow.mqh` gọi chuẩn bị với chỉ số 0 tại
`0x4580..0x458e`, rồi chạy phần khởi động còn lại tới `0x5f34`.
Thân chuẩn bị `0xe0c0..0xef3f` chạy thật trong phép so mã máy.

| Nội dung | Bằng chứng gốc | Cách nối/kiểm | Kết quả/còn thiếu |
|---|---|---|---|
| Chỉ báo và giá mở | Dãy `0x6d180`; `iOpen(D1,1)` tại `0xe220` | Giá mở được cấp riêng, không lấy mẫu chỉ báo thay thế | Khớp cả khi hai giá trị khác nhau |
| Khối lượng cài đặt/chuẩn bị | `0x1d7138` và `0x6d620` là hai ô riêng | Truyền tham chiếu cài đặt; giữ riêng đầu ra chuẩn bị | Khớp khi chuẩn bị thành công hoặc trả về sớm |
| Hai cách đọc chế độ | `0x6d630` là cùng ô 32 bit | Ghi cùng lúc qua tham chiếu; ép kiểu giữ bit giữa `int` và `uint` | Khớp cả số âm, sát giới hạn và thay đổi sau lời gọi |
| Chuẩn bị → đoạn sau → đuôi | `0x4580..0x5f34` | Không đặt lại vùng nhớ ở điểm nối; giữ ba vùng bình luận riêng | **233/233 ca khớp** |
| Cách gọi cũ | `Bot3PrepareStrategy` ba tham số | Giữ hàm gọi cũ, kiểm lại bộ ca độc lập | **1.016/1.016 ca khớp** |
| Lỗi dừng | Mã lỗi mảng `0x1f6`, chia 0 `0x1f7` | So lời gọi tới trước lỗi và loại lỗi, không sinh kết quả thường | **3/3 ca khớp**; chưa so toàn trạng thái đúng lúc lỗi |

## Kết quả

- `b3-startup-prep-flow-20261029-r2`: 234 trường, dãy chỉ báo,
  2.800 ô, 12.917 lời gọi, 12.018 phép tính CPU; 233 lần qua điểm
  nối, đúng một lần mỗi ca. Hai thân tìm mức và ba thân bảng được
  thay bằng bộ ghi trong phép kiểm này.
- `b3-preparation-compat-20261029-r1`: kiểm lại 1.016 ca cũ của
  toàn thân chuẩn bị; không thay đổi kết quả của cách gọi cũ.
- `b3-startup-prep-errors-20261029-r1`: dãy có 0/1 phần tử và đơn
  vị giá 0. MT5 dừng đúng loại lỗi, không vào đuôi và không ghi kết
  quả thường; các lời gọi trước lỗi khớp. Đây là lỗi cố ý trong bộ ca.
- Hai nguồn kiểm và `b3-all-headers-api-20261029-r5` biên dịch
  0 lỗi, 0 cảnh báo; đủ 112 tệp `.mqh`.
- Kiểm độc lập không thấy lỗi cần sửa trong phần nối dùng chung.

## Giới hạn

Phản hồi thị trường, chỉ báo và các thân tìm mức/bảng được cấp.
Cấp phát chuỗi thành công được cấp. Chưa kiểm mọi lỗi cấp phát,
toàn trạng thái ở đúng điểm lỗi, phần khởi động trước `0x4580`,
ảnh bảng, EA đầy đủ hoặc phép chạy cặp hai bot hoàn chỉnh.

Chạy lại: `cong-cu/kiem-noi-chuan-bi-khoi-dong-bot-3.py generate`,
`prepare RUN`, `mql5 RUN --build BUILD`, `original RUN`, `compare RUN`;
`errors ERROR_RUN --build BUILD` dùng lượt riêng. MQL5 chạy trước
mã máy; dùng tên lượt mới và MT5 bot 3 riêng.

[Số liệu và mã kiểm tra](verification.json), [danh sách tệp](../startup-preparation-flow-bot3-20261029-r1-manifest.txt).
