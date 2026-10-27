# Phân tích vòng đời bot 1 và bot 3

Đây là bước phân tích trước khi viết mã. Bằng chứng lấy từ bản C trung gian
và bảng hàm của đúng EX5 gốc; chưa gọi là đã khôi phục toàn bộ vòng đời.

## Hàm dọn khi thoát

| Bot | RVA | Bằng chứng |
|---|---:|---|
| Bot 1 | `0x1f5e0..0x2094e` | `ma-trung-gian.c`, dòng 14032–14781 |
| Bot 3 | `0x2a800..0x2bb7f` | `ma-trung-gian-day-du.c`, dòng 19638–20364 |

Thứ tự chung đã đọc được:

1. Xóa các tên cố định của bảng: bot 1 là `line1`, `linec`, `line2`,
   `lines`, `lineTradeStart`; bot 3 thêm `linet` trước `lineTradeStart`.
2. Xóa `linenfp0`.
3. Với chỉ số ngoài `0..99`, mỗi vòng xóa theo thứ tự
   `lineopl`, `linea`, `lineto`, `linetp`, `linetq`. Sau đó chỉ số trong
   `0..9` xóa `tabel_info` với số `ngoài*100 + trong`. Mã gốc so vòng
   bằng điều kiện kết thúc bằng 100 và 10, không phải số suy ra từ số
   chiến lược.
4. Xóa `infopanel_rectangle`. Vòng 10 tiếp theo xóa lần lượt
   `tabel_heading` và `tabel_totals`.
5. Khi cờ native tương ứng bằng 1, chạy vòng 300; mỗi lượt xóa hai tên
   có chỉ số, `horizontalrect` và `info_ea`. Điều kiện dừng là cờ vẫn bằng
   1 và chỉ số trước đó nhỏ hơn 299.
6. Nếu tay cầm chỉ báo khác `-1`, gọi `IndicatorRelease` rồi ghi lại `-1`.
7. Cuối hàm gọi `ObjectsDeleteAll(0,-1,-1)`; đây là lời gọi xóa toàn biểu đồ, không được thay bằng một vòng `ObjectDelete`.

Các lời gọi `IntegerToString` đều ghi vào vùng chuỗi dùng chung trước khi
ghép tên; `ObjectDelete` nhận biểu đồ 0 và chuỗi đã ghép. Không được đổi
thứ tự hoặc bỏ nhánh cờ 300.

## Phần khởi tạo còn thiếu

Bảng hàm xác nhận bot 1 có khối `0xc30` và các khối `0x20a00`, `0x22750`;
bot 3 có `0xc30`, `0x2bb80`, `0x2dd30`. Đoạn nạp vốn 616/616 ca mỗi
bot đã có bằng chứng riêng, nhưng toàn bộ tạo chỉ báo, tạo bảng, đăng ký
sự kiện, xử lý lỗi và nối vào `OnInit` chưa được kiểm. Vì vậy chưa viết
hàm khởi tạo giả.

## Cách kiểm kế tiếp

Bộ kiểm vòng đời phải ghi toàn bộ tên/ thứ tự `ObjectDelete`, giá trị cờ
hánh 300, lời gọi `IndicatorRelease` và trạng thái tay cầm; sau đó so thân
EX5 gốc với hàm MQL5 trong MT5 riêng. Chỉ khi kết quả hai bên khớp ở cả
hai giá trị cờ và tay cầm mới ghép vào EA.
