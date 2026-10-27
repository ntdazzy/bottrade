# Quét và hủy lệnh chờ theo khoảng cách

| Chức năng | Bot 1 | Bot 3 |
|---|---|---|
| Mua | `2f5c0..2f7dd` | `3ca00..3cc1d` |
| Bán | `2f7e0..2f9fd` | `3cc20..3ce3d` |
| Giá tham chiếu mua/bán | `67760/67758` | `747a0/74798` |
| Khoảng cách | `67468` | `744a8` |
| Vé cuối | `677f8` | `74838` |
| Mã nhận diện | `6246c` | `6d564` |
| Hủy/gửi con | `34150→950` | `32450→950` |

Mỗi hàm nhận cờ int32; chỉ đúng1 mới làm việc (2/255/số âm đều bỏ).
Đọc OrdersTotal một lần, âm thì bỏ; còn lại quét từtotal đến0, gồm
chỉ số bằngtotal. Mỗi lần OrderGetTicket ghi lại vé cuối, kể cả0.
Vé0 bỏ; mã nhận diện64bit của lệnh phải bằng mã chiến lượcint32 đã
mở rộng dấu; tên mã so đầy đủ, giữ khác biệt NULL/rỗng; loại lệnh
64bit phải đúng4mua hoặc5bán, không chỉ xét32bit thấp.

Sau khi loại lệnh khớp, chụp giá tham chiếu TRƯỚC gọi OrderGetDouble9.
Sau lần gọi này mới đọc khoảng cách hiện tại. Mua: `price-gap>quote`;
bán: `quote>price+gap`, so chặt, giữ thứ tự cộng/trừ và các sốNaN/vô cực.
Không chuyển sang so cùng một khoảng cách theo biểu thức khác.
Đủ điều kiện thì đọc lại vé cuối và gọi nguyên hàm hủy/gửi. Không thêm
xóa bảng, in thông báo hoặc dùng kết quảbool để đổi luồng sau đó.

Nguồn dùng hàm BotNCancelDistantPending với tham chiếu đến mã chiến
lược, tên mã, giá tham chiếu, khoảng cách và vé cuối. Bộ kiểm cấp cùng
trả lời MT5 cho bản gốc và nguồn đã biên dịch. Có thay giá tham chiếu/
khoảng cách/vé trong OrderGetDouble, thay mã nhận diện sau OrderGetInteger,
thay tên mã sau OrderGetString; giá tham chiếu đã chụp phải giữ nguyên,
còn các ô chưa đọc phải nhận giá trị mới đúng thời điểm.

698ca mỗi bot (349ca mỗi chiều): kế thừa các ca hủy/gửi, số lệnh/chỉ
số, vé64bit, tên mãNULL/rỗng/Unicode, giới hạn vùng cấm hủy, gửi đồng
bộ/bất đồng bộ, bị dừng và kết quả gửi được cấp; thêm cờ bật chính xác,
sát ngưỡng/NaN/vô cực và thay trạng thái giữa dịch vụ. So từng byte
toàn bộ thứ tự dịch vụ,35trường/4chuỗi giao dịch tại ranh giới và cuối,
trạng thái chọn lệnh/vé cuối cùng/giá tham chiếu/khoảng cách/mã/tên mã.

Mã gốc chạy nguyên vòng quét cùng hàm hủy và gửi; không cấp sẵn kết
quả hàm con. Chỉ cấp dữ liệu/trả lời dịch vụ MT5 và cấp phát thành
công. log_level0: chưa chứng minh mọi thông báo của hàm gửi ở đây.
Không gửi lệnh lên tài khoản thật. Còn nối nhánh gọi NFP/giờ tin,
đóng vị thế, lỗi cấp phát, chọn lệnh trên tài khoản thật và toànEA.
