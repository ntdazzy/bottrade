# Hàm tạo ô chữ của bảng hiển thị

Đã viết và đối chiếu nguyên thân hàm `45b70..4773b` của bot 1 và
`53a10..555db` của bot 3. Mỗi ca có 15 lần đổi chỉ số sang chữ và 15 lời
gọi tạo/đặt thuộc tính đối tượng, giữ cả thao tác đặt chiều cao lặp.

| Bot | Ca gốc/MQL5 khớp | Dịch vụ đã so |
|---|---:|---:|
| 1 | 172/172 | 5.160 |
| 3 | 172/172 | 5.160 |

Kiểm số âm/sát giới hạn, số không hữu hạn, chuỗi UTF-16 và NULL/chuỗi
rỗng, màu đặc biệt, bit chọn cỡ chữ, thay trạng thái trong dịch vụ và mã
lỗi. So đủ gói tạo đối tượng, tên, kiểu, thuộc tính, chuỗi và thứ tự.
Đúng thời điểm chụp độ rộng/chiều cao/cờ trước khi tạo lại tên được giữ
nguyên; mỗi lời gọi đọc tiếp trạng thái sống như bản gốc.

Lượt đạt `bN-panel-cell-20261028-r2`, bản kiểm
`bN-panel-cell-check-20261028-r1`; API chỉ biên dịch
`bN-panel-cell-api-20261028-r5`, đều 0 lỗi/0 cảnh báo. Lượt r1 dừng ở
ca chuỗi rỗng vì bộ đối chứng đã gộp chuỗi rỗng với NULL; đã sửa cách nạp
đầu vào của bộ đối chứng, không sửa nguồn ô chữ.

Đây là hàm con dùng để tạo bảng, chưa phải toàn hàm tạo bảng. Còn ghép
các dòng/thống kê, ảnh thật, khởi tạo, lỗi cấp phát và EA đầy đủ.
