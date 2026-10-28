# Đuôi khởi động bot 3

`Bot3StartupTail.mqh` dựng đoạn gốc `0x574c..0x5f34`, từ đặt lại
cờ tới lệnh trả về. Địa chỉ tính từ nền `0x17156250000`. Tệp gốc
và toàn đoạn OnInit được kiểm mã SHA-256 trước chạy.

| Phần | Bằng chứng gốc | Nguồn/kiểm | Kết quả/còn thiếu |
|---|---|---|---|
| Cờ và bốn chuỗi | Cờ `0x744a0`; bình luận `0x6d568`; đích `0x74438/48/58/68` | Đặt cờ 0 trước ghép B1/B2/S1/S2; chuỗi máy gốc chạy thật | Khớp, gồm NULL/rỗng/UTF-16/dài |
| Giờ và nến giá | `0x74488 = 0x747dc`; đặt `0x73470=0` | Giữ 9 ô; chỉ đặt ô đầu về 0 | Khớp; không nhầm dãy M1 ở `0x73790` |
| Khối lượng | Chỉ số `0x74934`, mức đầu `0x6d620`, dãy `0x73ac0` | Đọc sau SymbolInfoInteger rồi giới hạn dưới | Khớp cả 9 vị trí và NaN |
| Lịch sử | Cổng `0x1d6f38`, sao `0x6d43c`, cửa sổ `0x6d43d` | Quét ngược, mốc 90 ngày, đọc magic/khối lượng theo đúng điều kiện | Khớp; không có cổng chế độ kiểm thử ở phần gọi này |
| Thứ tự bảng | `0xef40 → 0x14fa0 → 0x16e80` | So đầy đủ đối số, thử đổi dữ liệu sau từng hàm | Khớp thứ tự/đối số; thân bảng được thay bằng bộ ghi |

## Kết quả

- `b3-startup-tail-20261029-r1`: **222/222 ca khớp**, 80 trường,
  1.371 lần gọi; so trước mỗi lần gọi và khi trả về.
- Ca gồm cờ byte khác 0, số mục lịch sử âm/sát giới hạn, thời gian
  tràn 64 bit, đúng/sai magic, ticket 0, các chuỗi và thay đổi dữ
  liệu giữa các lần gọi. Kiểm riêng các đối số bảng của bot 3.
- `b3-startup-tail-check-20261029-r1` và
  `b3-all-headers-api-20261029-r3`: 0 lỗi, 0 cảnh báo. Bộ ghép chứa
  đủ 109 tệp `.mqh` hiện hành.
- Kiểm độc lập không thấy lỗi trọng yếu trong phạm vi này; mã đã
  kiểm khớp với biên nhận và dữ liệu đối chiếu.

## Giới hạn và bước tiếp

Các chuỗi tạm ban đầu rỗng và cấp phát thành công được cấp; chưa
kiểm lỗi cấp phát ở nhánh ngoài. Phản hồi dịch vụ và tác dụng của
ba hàm bảng được cấp để kiểm phần gọi; chưa so ảnh bảng hoặc chạy
thân bảng trong phép kiểm nối. Giữ bộ chặn quyền dùng.

Còn chuẩn bị đầu/đoạn giữa `0x4580..0x574c`, ghép với phần trước,
các nhánh lỗi và EA đầy đủ. Đây chưa là phép chạy cặp hai bot.

Chạy lại bằng `cong-cu/kiem-duoi-khoi-dong-bot-3.py`: `generate`,
`prepare RUN`, `mql5 RUN --build BUILD`, `original RUN`, `compare RUN`.
Dùng tên lượt mới và MT5 bot 3 riêng; MQL5 chạy trước mã máy gốc.

[Số liệu và địa chỉ](verification.json), [danh sách tệp](../startup-tail-bot3-20261029-r1-manifest.txt).
