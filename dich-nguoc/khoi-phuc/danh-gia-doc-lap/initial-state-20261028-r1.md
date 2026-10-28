# Khởi tạo vốn và trạng thái tài khoản

Lượt mới dùng đúng 616 đầu vào gốc của mỗi bot. Kết quả nguồn MQL5
khớp phần mã gốc đã chốt theo từng bit:

| Bot | Ca | Khớp | Biên dịch |
|---|---:|---:|---|
| 1 | 616 | 616 | 0 lỗi, 0 cảnh báo |
| 3 | 616 | 616 | 0 lỗi, 0 cảnh báo |

Đã so: số dư/vốn chủ sở hữu được chọn, vốn đỉnh, tên hai khóa lưu,
mốc thời gian cuối, thứ tự đọc tài khoản, đọc kho lưu, ghi kho lưu,
đọc giờ và thời gian ngủ. Bộ kiểm dùng kho lưu và tài khoản giả lập
trong MT5 riêng; không chạm kho lưu thật.

Lượt: `b1-initial-state-20261028-r2`, `b3-initial-state-20261028-r2`.
Biên nhận biên dịch tương ứng là `b1-initial-state-20261028-r2` và
`b3-initial-state-20261028-r2` trong thư mục `bang-chung/bien-dich`.

Giới hạn: đây là phần khởi tạo vốn độc lập. Chưa chứng minh toàn bộ
OnInit, kiểm quyền dùng, nhánh lỗi cấp phát và EA hoàn chỉnh.
