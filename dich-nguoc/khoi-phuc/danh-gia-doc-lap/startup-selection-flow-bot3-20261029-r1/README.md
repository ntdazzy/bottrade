# Nối chọn tần suất tới trả về — bot 3

`Bot3StartupSelectionFlow.mqh` nối đổi giờ/chọn tần suất, tạo ngữ
cảnh, chuẩn bị đầu và phần khởi động còn lại. Mã gốc chạy từ
`0x3840` tới lệnh trả về `0x5f34`, nền `0x17156250000`.

| Phần | Bằng chứng gốc | Cách kiểm | Kết quả/còn thiếu |
|---|---|---|---|
| Đổi giờ | Thân `0x7e20..0x82f7` và đoạn gọi `0x3840` | Ngày sát mốc, trước/sau 1987/2007, nhân giờ theo 32 bit | Thân thật, 224 lần, đúng một lần mỗi ca |
| Đổi tiền/chọn tần suất | Thân `0x8300..0xe0b5`; chọn tới `0x3ce6` | Số dư/ngưỡng/cờ/cặp tiền, đọc lại dữ liệu sau lời gọi | Thân đổi tiền chạy 100 lần, đúng điều kiện từng ca |
| Ngữ cảnh và chuẩn bị | `0x3ce6..0x458e`, thân `0xe0c0` | Cùng mã giá, đuôi, bình luận, mã nhận diện và biến dùng chung | Khớp; không đặt lại vùng nhớ ở điểm nối |
| Phần sau tới trả về | `0x458e..0x5f34` | So trước mỗi dịch vụ và cuối lượt, đủ dãy/bảng | Khớp; hai thân tìm mức và ba thân bảng được thay bằng bộ ghi |

Lượt `b3-startup-selection-flow-20261029-r1`: **224/224 ca khớp**,
274 trường, dãy chỉ báo và 2.800 ô; 21.624 lần gọi, 13.403 phép
tính CPU. Mỗi ca qua điểm nối đuôi đúng một lần.

Ca kiểm giữ đúng tần suất đã đọc trước khi số dư được hỏi; đồng
thời kiểm lại mức lỗ, rủi ro, cờ tính theo tỷ lệ và cờ ngưỡng sau
các lần đọc tiền tệ/tỷ giá. Có chế độ thủ công với byte 2/255,
các ngưỡng sát nhau, NaN/vô cực và đuôi mã trước/sau khi tự nhận diện.

Nguồn kiểm `b3-startup-selection-flow-check-20261029-r1` và bộ ghép
`b3-all-headers-api-20261029-r7` biên dịch 0 lỗi, 0 cảnh báo; đủ
114 tệp `.mqh`. Kiểm độc lập đã xác nhận kết quả và mã nguồn.

## Giới hạn

Thời gian, tiền tệ và tỷ giá là dữ liệu cấp cho dịch vụ. Các hàm
lịch, ghép/đọc chuỗi ngày và phép chia dư chạy thật trong MQL5 rồi
được cấp cho mã máy sau khi so đúng đối số/thứ tự. Ba thân nghiệp
vụ mùa hè/đổi tiền/chuẩn bị chạy nguyên bản; không cấp kết quả cuối
thay cho chúng. Bộ chặn quyền dùng vẫn được giữ.

Còn phần tài khoản/lịch tin trước `0x3840`, hai thân tìm mức/ba thân
bảng trong phép kiểm nối, các nhánh lỗi toàn luồng, ảnh giao diện
và EA đầy đủ. Chưa phải phép chạy cặp hai bot hoàn chỉnh.

Chạy lại `cong-cu/kiem-noi-chon-toan-khoi-dong-bot-3.py`: `generate`,
`prepare RUN`, `mql5 RUN --build BUILD`, `original RUN`, `compare RUN`.
Dùng tên lượt mới và MT5 bot 3 riêng; MQL5 chạy trước mã máy.

[Số liệu/địa chỉ](verification.json), [danh sách tệp](../startup-selection-flow-bot3-20261029-r1-manifest.txt).
