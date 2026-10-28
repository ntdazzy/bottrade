# Nối phần sau chuẩn bị đầu tới trả về — bot 3

`Bot3StartupTradingState.mqh` dựng đoạn `0x458e..0x574c`, gồm các
nhánh ngoài `0x5811..0x5873`. `Bot3StartupPostPreparation.mqh` nối
ngay với `Bot3StartupTail.mqh` tới lệnh trả về `0x5f34`. Địa chỉ
tính từ nền `0x17156250000`; EX5 và đoạn khởi tạo được kiểm mã SHA.

| Phần | Bằng chứng gốc | Cách kiểm | Kết quả/còn thiếu |
|---|---|---|---|
| Chênh lệch giá, khối lượng | `0x463e..0x4f99`; dãy `0x73ac0` | Đọc lại mức nhỏ/lớn nhất và bước; so số thường/NaN, thứ tự in và ghi | Khớp 9 khối lượng |
| Đơn vị và khoảng dừng/chốt | `0x4f99..0x5307` | Giữ nhân/chia/cộng và điều kiện máy gốc; không suy NaN từ C | Khớp trong các ca đã kiểm; chưa kiểm lỗi chia 0 |
| Hết hạn và nến | `0x5307..0x540d` | Nhân 32 bit với 3.600, đọc lại sau dịch vụ; W1 rồi M1 hai lần | Khớp; W1 là `0x8001` |
| Hai mức giá và làm tròn | `0x5433..0x55ce` | Đối số, đọc lại cài đặt, kết quả và số chữ số riêng từng phía | Khớp phần gọi; thân tìm mức được thay bằng bộ ghi |
| Ba bảng và cờ | `0x55ce..0x574c`, nhánh `0x5811..0x5873` | 500×3 ô dừng lỗ, 500×2 ô chốt lời, 100×3 ô hàng đợi | Khớp 2.800 ô; chỉ xóa cả bảng khi cờ đúng 1 |
| Nối đoạn đuôi | `0x574c..0x5f34` | Chung vùng nhớ, không đặt lại tại điểm nối; bình luận lệnh tách bình luận chuẩn bị | Khớp; ba thân bảng được thay bằng bộ ghi |

## Kết quả

- Riêng đoạn giữa `b3-startup-trading-20261029-r1`: **315/315 ca**,
  53 trường, 7.971 lần gọi và 9.455 phép tính trên CPU.
- Chạy nối `b3-startup-joined-20261029-r1`: **569/569 ca**, 130
  trường, 21.354 lần gọi và 17.039 phép tính trên CPU. Mỗi ca đi qua
  điểm nối đúng một lần; kết quả cuối và trạng thái tại lời gọi khớp.
- Có ca thay đổi dữ liệu sau lời gọi, cả 9 chỉ số, các cờ byte,
  sát ngưỡng, vô cực/NaN, chuỗi rỗng/NULL/UTF-16, thời gian tràn,
  giữ cột 2 của hàng đợi khi cờ không phải 1 và hai vùng bình luận riêng.
- Hai nguồn kiểm và bộ ghép `b3-all-headers-api-20261029-r4`:
  0 lỗi, 0 cảnh báo; bộ ghép chứa đủ 111 tệp `.mqh`.
- Kiểm độc lập không thấy lỗi cần sửa trong phạm vi đã dựng.

## Giới hạn và bước tiếp

Cấp phản hồi dịch vụ, kết quả/tác dụng hai hàm tìm mức và ba hàm
bảng. Chuỗi tạm ban đầu rỗng, cấp phát thành công được cấp. Phép
kiểm không chạy quyền dùng; các điểm bảo vệ vẫn bị chặn.

Còn ghép lần chuẩn bị đầu `0xe0c0`, phần trước `0x3840..0x4580`,
các thân con vào phép kiểm nối, lỗi chia 0/cấp phát và toàn EA.
Đây chưa phải chạy hai bot hoàn chỉnh cùng dữ liệu.

Chạy lại hai công cụ `kiem-trang-thai-giao-dich-khoi-dong-bot-3.py`
và `kiem-noi-khoi-dong-bot-3.py`: `generate`, `prepare RUN`,
`mql5 RUN --build BUILD`, `original RUN`, `compare RUN`. Dùng tên
lượt mới và MT5 bot 3 riêng; MQL5 chạy trước mã máy gốc.

[Số liệu/địa chỉ](verification.json), [danh sách tệp](../startup-post-preparation-bot3-20261029-r1-manifest.txt).
