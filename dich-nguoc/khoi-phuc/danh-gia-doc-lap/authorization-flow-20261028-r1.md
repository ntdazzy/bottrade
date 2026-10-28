# Nhánh kiểm quyền dùng

Đã đọc trực tiếp hai thân hàm gốc và lưu mã băm, không ghi lại khóa,
chuỗi yêu cầu hoặc dữ liệu tài khoản.

| Bot | Hàm | Kích thước | SHA-256 thân hàm |
|---|---:|---:|---|
| 1 | `0x5880..0x61a9` | 2.345 byte | `1caa57050b49fa9922677958447c643a454f9fb0d861b4b646340bd7ca097581` |
| 3 | `0x61a0..0x6ac9` | 2.345 byte | `fdea6900667316df733ecd0a459144887c227f737188521a0f67c9b84c65bb8e2` |

Thứ tự chung đã xác nhận:

1. Nếu cờ trạng thái khác 0 thì hàm trả về giá trị cho phép ngay.
2. Đọc mã tài khoản và gọi hàm phụ kiểm điều kiện tài khoản. Nếu hàm
   phụ trả khác 0 thì trả về giá trị cho phép. Nếu trả 0 thì đọc mã
   tài khoản lần nữa và tiếp tục gửi yêu cầu.
3. Đổi mã tài khoản thành chuỗi, ghép vào dữ liệu yêu cầu, chuyển sang
   mảng byte và gọi `WebRequest`.
4. Với mã HTTP 200, đổi phản hồi thành chuỗi và tìm mẫu phản hồi nguyên
   bản. Nếu không tìm thấy mẫu thì gọi hàm kiểm dự phòng. Với phản hồi
   khác 200 hoặc lỗi gọi mạng, mã gốc cũng gọi hàm kiểm dự phòng. Chưa
   đủ bằng chứng để khẳng định tất cả trường hợp này đều bị từ chối.
5. Dọn toàn bộ chuỗi/mảng tạm trước khi trả về.

Tệp `authorization-flow-20261028-r1.json` lưu mã băm thân hàm; không
chứa nội dung khóa. Không sửa EX5 hay thay kết quả kiểm quyền.

Chưa đưa hàm này vào EA nguồn vì cần xác định đầu vào cấp phép hợp lệ
và cách cấp `WebRequest` trong môi trường được phép. Cổng khởi tạo hiện
nhận kết quả kiểm quyền từ bên ngoài và giữ nhánh từ chối đúng hành vi.

Đã chốt riêng cây số trong hàm con bot 1 `0x3d6c0`: **1.075 giá trị**
được phép, chứng minh trên toàn miền 64 bit và đối chiếu 5.000 đầu
vào với mã gốc, 0 sai khác. Bộ trích C cũ thiếu 47 giá trị nên không
được dùng làm bảng hoàn chỉnh. Dữ liệu riêng giữ ở `.local/`;
[bằng chứng và phạm vi](authorization-login-tree-20261028-r1/README.md).
226 cặp chuỗi cùng các nhánh mạng/dự phòng vẫn chưa kiểm đủ.
