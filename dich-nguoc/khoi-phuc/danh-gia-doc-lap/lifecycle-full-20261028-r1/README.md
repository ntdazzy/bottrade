# Sửa và kiểm lại hàm dọn khi thoát

Đã sửa cờ dọn mở rộng thành `uchar` đọc qua tham chiếu. Nhánh 300 chỉ
chạy khi cờ bằng đúng 1 và đọc lại cờ sau mỗi cặp xóa, như thân EX5. Mã
trước dùng `bool` và chỉ có bốn ca 0/1 nên chưa bắt được khác biệt này.

| Bot | Ca gốc/MQL5 khớp | Lời gọi dịch vụ đã so |
|---|---:|---:|
| 1 | 62/62 | 208.288 |
| 3 | 62/62 | 208.350 |

Bộ mới kiểm cờ 0/1/2/255, số chỉ báo 32 bit âm/dương sát giới hạn,
đổi cờ/số chỉ báo giữa các dịch vụ, mã lỗi, thứ tự đầy đủ và trạng thái
cuối. Mã băm khóa cả header, script, công cụ, thân native và EX5 gốc.
Không cập nhật bằng tay mã băm của lượt cũ.

`negative-old-source.py` lấy đúng thân MQL5 trước sửa ở `b9c7f77`, nhúng
vào bộ ghi mới rồi biên dịch riêng. Với cờ 2, native bỏ nhánh 300 còn mã
cũ đi vào; cả hai bot bị bắt lệch thứ tự dịch vụ tại lời gọi 3048/3049.
Các tệp `botN-negative.json` và nguồn `.mq5.txt` giữ bằng chứng. Tệp kiểm
tạm trong nguồn đã được xóa sau khi so đúng mã băm.

Bằng chứng mới: `bN-lifecycle-full-20261028-r1`, bản kiểm
`bN-lifecycle-full-check-20261028-r1`, bản API chỉ biên dịch
`bN-lifecycle-api-20261028-r3`. Tất cả 0 lỗi/0 cảnh báo.

Còn khởi tạo đầy đủ, ảnh biểu đồ, lỗi cấp phát và toàn EA. Đây là kiểm
hàm dọn khi thoát, chưa phải chạy cặp toàn bot.
