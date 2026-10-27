# Ô chữ trong bảng hiển thị

Phân tích trước khi viết mã, đúng hai EX5 chuẩn có SHA-256 trong biên nhận
các lượt kiểm. Địa chỉ dưới đây đã trừ địa chỉ đầu bản chụp.

| Bot | Thân hàm | SHA-256 của thân |
|---|---|---|
| 1 | `45b70..4773b` | `591e2758c7f444513368726b58fde8808a3f5d2e757b9d4e9a377075fe1e1f74` |
| 3 | `53a10..555db` | `1174b2b906e77a28ad0b2105211b62eb4240227e3738e9a873c5a3715660aecd` |

Bot 1: C dòng 30224–31161. Bot 3: C đầy đủ dòng 35919–36856.
Hai thân cùng thuật toán. Tham số thứ 5/6 nằm ở ngăn xếp khi gọi, là
cột `int32` và màu `uint32`; hai tham số đầu là vị trí dọc gốc và chỉ số
`int32`, tham số thứ 3 là chuỗi, thứ 4 là dòng `int32`.

Tên đối tượng luôn tạo lại bằng `info_ea` nối `IntegerToString(index,0,32)`
trước mỗi lời gọi, tổng 15 lần đổi số. Không dùng chung tên đã tính trước.

1. `ObjectCreate(0,name,107,0,0,0.0)`.
2. Thuộc tính số `3f4 = int64(scale_x * column + 11.0)`.
3. `3f5 = int64(scale_y * row + base_y)`.
4. Chuỗi thuộc tính `6 = text`.
5. Các thuộc tính số theo thứ tự: `3=0`, `0=uint32(color)`,
   `401=17110d`, `40b=3a2a1e`, `3ea=(font_flag & 1 ? 7 : 0)`.
6. Chuỗi `3e9 = Arial Bold` khi màu bằng `c4b741`, còn lại là `Arial`.
7. Các thuộc tính số: `404=1`, `3fc=int64(scale_y)`,
   `3fb=int64(scale_x)`, `3fc=int64(scale_y)` lần nữa, `40c=2`.

Với mỗi thuộc tính đọc `scale_x`, `scale_y` hoặc `font_flag`, giá trị được
chụp **trước** lời gọi đổi số tạo tên của chính thuộc tính đó. Giữ đúng
thứ tự này khi dịch vụ đổi trạng thái. Chuỗi đầu vào vẫn được đọc qua
cùng tham chiếu. Kết quả thành công/thất bại của các dịch vụ bị bỏ qua.

Vị trí trạng thái: bot 1 `68298/682a0/682a8`, bot 3
`752d8/752e0/752e8`. Hằng 11.0 nằm ở `515f8` / `59b30`.
Lời gọi tạo dùng bộ gọi chung với thao tác `112`, 6 đối số, kiểu trả về
`550005`, các kiểu đối số lần lượt `chart`, chuỗi, số nguyên, số nguyên,
thời điểm, số thực. Bộ kiểm phải so cả các kiểu này.

Còn phải kiểm ảnh thật, toàn hàm tạo bảng, khởi tạo, lỗi cấp phát và EA.
Không coi kiểm ô chữ riêng là đã hoàn thành bảng hiển thị.
