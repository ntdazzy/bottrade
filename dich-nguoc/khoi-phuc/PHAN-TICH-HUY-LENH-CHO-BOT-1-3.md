# Hủy lệnh chờ — phân tích trước khi viết mã

Chưa có MQL5 hoặc phép so chạy cho nhóm này. Đã giữ riêng toàn bộ
mã C và lệnh máy của ba hàm mỗi bot bằng công cụ
`phan-tich-huy-lenh-cho-bot-1-3.py`; đã kiểm lại SHA-256 EX5 gốc.

| Phần | Bot 1 | Bot 3 | Còn thiếu |
|---|---|---|---|
| Kiểm vùng cấm rồi tạo/gửi hủy | `0x34150` | `0x32450` | Nối tên/trường dữ liệu giá từ MT5 bằng nguồn đối chứng; dựng và so mọi nhánh |
| Chọn vé nhánh mua rồi hủy, dọn bảng, in | `0x32110` | `0x3da90` | Chốt toàn bộ điều kiện chọn giá/vé, tác dụng phụ và ghép hàm hủy |
| Chọn vé nhánh bán rồi hủy, dọn bảng, in | `0x325b0` | `0x3dd60` | Cùng các điểm trên |

Hai hàm chọn vé gọi trực tiếp hàm hủy phía trên. Không thay khối này
bằng lời hủy đơn giản: khối hủy còn chọn lại lệnh, đọc dữ liệu giá,
kiểm khoảng cách, xử lý dừng và dựng yêu cầu trước khi tới `0x950`.
Các vòng quét vẫn bắt đầu ở tổng lệnh và đi xuống 0, đủ hai đầu.

Trong hàm hủy, thứ tự quan sát được:

1. Chọn vé. Nếu chọn được: đọc mã giá, thuộc tính số 16 (`P`), dữ
   liệu giá gần nhất, thuộc tính nguyên số 32 (`L`). Các bước sau phụ
   thuộc kết quả bước trước; chưa đo tên/trường của dữ liệu giá nên
   tạm gọi hai số lấy ở đó là `A` và `B`.
2. Tính `F=P*(double)L`. Mã máy chọn `F` nếu `F>0` **hoặc F không xác
   định**; trường hợp còn lại chọn `B-A`, gọi kết quả là `D`.
3. Với `D` thích hợp, đọc giá lệnh (`Q`, thuộc tính 9) và loại lệnh
   (thuộc tính 4). Chỉ dùng 32 bit thấp của loại lệnh.
4. Loại 2 dùng `B-Q`; loại 3 dùng `Q-A`; loại 4/6 dùng `Q-B`; loại
   5/7 dùng `A-Q`. Khoảng cách nhỏ hơn/bằng `D` thì trả về, giữ trạng
   thái giao dịch cũ. Không được đổi bằng dấu so sánh khác.
5. Nếu không bị chặn: khi chương trình dừng, in thông báo
   `CTrade::OrderDelete`, ghi mã kết quả 10027. Nếu không dừng, xóa
   cấu trúc yêu cầu/kết quả/kiểm, đặt hành động 8, mã nhận diện đã lưu
   8 byte và vé cần hủy, rồi gọi đầy đủ khối gửi `0x950`.

Điều kiện với số không xác định phải theo lệnh máy, không chép máy
móc điều kiện từ mã C trung gian:

| Điểm kiểm | Lệnh và vị trí bot 1 / bot 3 | Hành vi cần giữ |
|---|---|---|
| `P` trước đọc dữ liệu giá | `ucomisd` rồi `jae`, `0x34242/0x34246` / `0x32542/0x32546` | `P<=0` có thứ tự thì bỏ tiền kiểm; số không xác định vẫn gọi bước kế |
| Chọn `F` hay `B-A` | `cmpnlesd`, `0x342af` / `0x325af` | Số không xác định cũng chọn `F`, không chọn chênh lệch |
| `D` trước đọc giá/loại lệnh | `ucomisd` rồi `jae`, `0x342c6/0x342ca` / `0x325c6/0x325ca` | `D<=0` có thứ tự thì bỏ tiền kiểm; số không xác định vẫn đọc giá/loại |
| So khoảng cách cuối | `ucomisd` rồi `jb`, `0x34771/0x34775` / `0x32a78/0x32a7c` | Khoảng cách lớn hơn `D`, hoặc một vế không xác định, đều đi tạo hủy |

Nhận định ban đầu của agent đã đảo hai nhánh chọn ngưỡng. Đã đọc
lại phép ghép bit trong C và lệnh máy, sửa thành bảng trên. Bot 1
không có giá trị trả về dùng được; bot 3 có byte trả về, nhánh không
gửi/dừng trả 0, nhánh gửi dùng kết quả của hàm gửi. Chưa gọi đây là
kết quả kiểm chạy.

- [Mã C/lệnh máy bot 1](bot-cua-toi-1/phan-tich/huy-lenh-cho/cancel-20261024-r1/analysis.json).
- [Mã C/lệnh máy bot 3](bot-cua-toi-3/phan-tich/huy-lenh-cho/cancel-20261024-r1/analysis.json).

Trước viết mã: đối chứng bố cục dữ liệu giá và tên thuộc tính 16/32;
kiểm lại các nhánh loại lệnh bằng bảng nhảy; lập đủ đầu vào/đầu ra.
Sau đó phải so chọn vé thất bại, dữ liệu giá thiếu, số âm/0/sát ngưỡng/
không xác định/vô hạn, loại có phần 32 bit cao, dừng, trạng thái cũ và
gửi thành công/thất bại. Cuối cùng ghép với hai hàm chọn vé và toàn EA.

Claude đã từ chối đánh giá bảng điều kiện này ở lượt
`cancel-guards-ultracode-20261024-r1`; [phản hồi](danh-gia-claude/cancel-guards-ultracode-20261024-r1/response.md).
Đã kiểm thực tế Opus 5.5 `max`, Ultracode bật nhưng không có luồng
phụ chạy. Không dùng phản hồi từ chối làm xác nhận, không đổi cách
hỏi để vượt chặn. Phân tích trên do agent chính và hai agent đọc
mã trực tiếp; vẫn phải có đối chứng có nguồn và kiểm chạy trước bàn giao.
