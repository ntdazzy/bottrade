# Vòng tạo lại lệnh chờ bot1 sau thay đổi khối lượng

**278/278 ca khớp từng byte**, bộ đọc cấu trúc cũng278/278; hai bản
dựng API/bộ kiểm đều0lỗi/0cảnh báo. Lượt `b1-eval-resize-20261027-r1`
chạy mã gốc bot1 riêng; không dùng đầu ra bot3 làm kết quả mong đợi.

Đã giữ vòng từ chỉ sốOrdersTotal xuống0, hai lần đọc loại4/5 độc lập,
đọc khối lượng7 và các mức/thời hạn/ghi chú trước xóa, bản chụp vé,
xóa34150 rồi gọi đầy đủ32dd0 qua gửi950 tại3363d. Hàm xóa bot1 trảvoid,
khácbot3; nơi gọi bỏ kết quả xóa và vẫn mở lại như gốc.
Mảng khối lượng có8ô, chỉ số/tên/mức đọc lại sau dịch vụ; bảng100x2
dò theo vé bị ép int32có dấu, chỉ đổi ô0 của dòng đầu trùng.

So đủ200ô bảng,35trường/4chuỗi trạng thái ở các ranh giới xóa/mở/gửi
và khi ra, vé cuối, chỉ số/mảng khối lượng, chuỗi thông báo và chờ1000ms.
Có các ca ký số64bit, NULL/rỗng/tiếng Việt, số lượngâm/0/nhiều, lỗi
xóa/mở/gửi, cài đặt thay trong dịch vụ và đọc lại loại sau xử lý mua.
Chuỗi chuyển số được đo trong MT5 rồi kiểm đầu vào/kiểu tại native.

Giới hạn: bắt đầu1a817 sau tính khối lượng với vùng tạm/thanh ghi/
dữ liệu đầu đã cấp. Chưa ghép cổng vốn hoặc phần quản lý trước đó,
chưa làEA. Câu trả lời MT5 và cấp chuỗi thành công được cấp; gửi log0,
không phát lệnh thật, chưa kiểm lỗi cấp bộ nhớ hoặc mọi giao diện/
lưu trạng thái. Không sửa EX5 gốc hay cờ bản quyền.

[Đặc tả](SPEC.md), [mã kiểm gốc](native-evidence.json),
[nguồn](../../../source/MQL5/Include/bot-cua-toi-1/Bot1EvaluationPendingResize.mqh),
[bộ so](../../../tests/check-evaluation-pending-resize.py),
[kết quả](../../../bang-chung/kiem-quan-ly-vi-the/b1-eval-resize-20261027-r1/comparison.json).
