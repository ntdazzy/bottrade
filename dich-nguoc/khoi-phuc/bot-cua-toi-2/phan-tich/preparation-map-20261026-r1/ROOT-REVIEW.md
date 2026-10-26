# Bản nháp chưa được chấp nhận để giao viết mã

Root đọc lại trực tiếp bytes hàm `0x7550..0x83c4` từ bản chụp mới,
SHA `dcd19e9d1581d0d4e68a1f8c1e293a83c1a4cb1f17de08a506e1e74f4d762141`.
README.md và native-scale-review.md bên cạnh có sai về nhánh và tên
giá trị. Không dùng các tệp đó làm đặc tả đã chốt.

- `0x7679 xorpd xmm7,xmm7` tạo số0; `0x7687` đọc reference vào xmm0.
  `0x7690 ucomisd xmm0,xmm7`; `0x7698 jbe 0x76e0` **bỏ qua** iOpen
  khi reference<=0 hoặcNaN. Chỉ reference>0 mới gọi iOpen ở `0x76c4`.
- `0x76c6 movsd xmm0,[rdi]` đọc **reference mới**, không đọc kết quả
  iOpen. `0x76ca..0x76d0` kiểm reference mới bằng0 trước phép chia.
  Kết quả iOpen được lấy qua `[r12]` ở `0x76d6`; `0x76dc` chia nó
  cho reference mới. Không có phép kiểm kết quả iOpen bằng0 tại đây.
- Các bước đọc SYMBOL_POINT/SYMBOL_DIGITS sau đó ghi point/đơn vị giá,
  chưa có căn cứ gọi các ô này là hệ số khối lượng.
- JSON native-scale-review.json ghi các câu diễn giải; nó không chứa
  danh sách lệnh máy nguyên dạng như yêu cầu. Không dùng tên tệp làm
  bằng chứng rằng mọi công thức đã được đối chiếu.

Chưa viết hoặc giao Claude viết khối này. Tệp gốc và bản nháp được giữ
nguyên để truy lại sai lệch. Cần phân tích tiếp toàn bộ các trường,
thứ tự đọc/ghi và lỗi trước khi chốt đặc tả.
