# Nối ba bước trước khi đánh giá chiến lược

| Phần | Bot 1 | Bot 3 |
|---|---|---|
| Nạp cấu hình → ghi chú/mã/đổi tiền → chuẩn bị | 432/432 ca | 2.106/2.106 ca |
| Giá trị so mỗi ca | 127 và toàn bộ ghi chú UTF-16 | 132 và toàn bộ ghi chú UTF-16 |
| Lượt đạt | b1-strategy-setup-20261027-r2 | b3-strategy-setup-20261027-r3 |
| Biên dịch bản kiểm và bản dùng dịch vụ thật | 0 lỗi/0 cảnh báo | 0 lỗi/0 cảnh báo |

Ba thân gốc chạy liên tục trong cùng bộ nhớ. Không đặt lại thanh ghi,
cờ hoặc ngăn xếp ở giữa. Bản gốc tự gọi chuẩn bị rồi quay về; mỗi ca
kiểm chỉ số, địa chỉ quay về và đúng một lần gọi. Có kiểm thứ tự đọc
tiền/giá và dịch vụ xuyên cả ba bước. Nguồn ghép chỉ gọi các khối đã có
theo thứ tự, cộng bước nối cờ dùng chung của bot 3.

Lỗi ghép r2 của bot 3 đã được xử lý: hai trường ở hai kiểu đầu vào cùng
đại diện byte `1d6f28`. Nếu không nối lại, 1.170 ca tắt điều chỉnh
khoảng cách bị lệch; 936 ca bật vẫn khớp. Bản sửa sao đúng byte trước
ba lời gọi. `failed-r2/` giữ nguồn trước sửa và thống kê; báo cáo r2
không được xem là kết quả đạt. Hai chuỗi ghi chú lệnh/chuẩn bị vẫn riêng.

Người rà qua tác vụ Codex riêng không thấy lỗi có thể kết luận trong
nguồn ghép/bộ kiểm. Lúc rà, báo cáo so cuối của bot 3 chưa được tạo;
Codex chính đã chạy so sau khi lượt gốc r3 hoàn tất và nhận 2.106/2.106.
Không có lượt viết/rà Claude trong phần này.

Giới hạn: các hằng thanh ghi trước điểm đầu, khung ngăn xếp, cấp chuỗi
thành công và dịch vụ MT5 vẫn được cấp. Bot 3 có 213 phép tính hai NaN
dùng đối chứng CPU đã đo; không phải toàn bản gốc chạy trực tiếp trên CPU.
Chưa chạy phần đánh giá, mọi đường từ đầu hàm điều phối, lỗi tổng hợp,
giao diện/khởi động lại hoặc EA đầy đủ. Chưa chạy cặp hai EA hoàn chỉnh.

[Đặc tả](SPEC.md), [bằng chứng vị trí nối](native-join-points.txt),
[mã kiểm và kết quả](verification.json). Dữ liệu nhị phân/EX5 đo giữ
tại máy; bộ đầu vào được sinh lại từ công cụ và các tệp ca đã ghi mã kiểm.

Bước tiếp: chốt phần đầu đánh giá của bot 3 và ngữ cảnh quản lý theo
nến của bot 1, rồi nối các khối còn thiếu. Mục tiêu vẫn là EA đầy đủ
và so toàn bộ với bản gốc; số ca đạt ở đây không phải % hoàn thành bot.
