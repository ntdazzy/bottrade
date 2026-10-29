# Thân đánh giá với trạng thái gốc giữ nguyên — bot 1

Lượt `b1-observed-evaluation-20261029-r2`: **57/57 ca khớp**,
13.606 lời gọi dịch vụ. Mã gốc chạy thân `0x18aa0` qua quản lý
lệnh, xét lệnh mới, cập nhật bảng lịch sử và dọn bảng theo giờ.

| Hàm đã chạy trong bản gốc | Số lần |
|---|---:|
| Đánh giá | 57 |
| Quản lý mua/bán | 56 / 56 |
| Tạo yêu cầu / sửa / đóng | 107 / 40 / 9 |
| Dọn bảng dừng lỗ ảo | 9 |
| Cập nhật bảng lịch sử / dọn theo giờ | 38 / 38 |

Phản hồi dịch vụ giao dịch do bộ kiểm cung cấp; không gửi lệnh lên
tài khoản thật. So trạng thái, đối số, thứ tự gọi, chuỗi, kết quả
và mã lỗi theo dữ liệu ghi từ MQL5. Chưa nối với vòng chuẩn bị và
lịch sử thật trong cùng lượt này.

## Nguồn trạng thái và hàng rào kiểm

Bản chụp `luot-20261023-r1` có `0x6216c=1`, `0x67470=1`. Biên
nhận EX5, tiến trình, máy thử và tệp chụp khớp nhau. Chỉ có ba
đầu vào GMT được truyền trong công việc đã lưu; không có đầu vào
để đặt quyền dùng. Mã tệp và dữ liệu được ghi ở `provenance.json`.

Trong `OnInit` gốc: `0xca8` ghi cờ `0x67470` về 0; gọi `0x5880`
tại `0xcb8`; kiểm kết quả tại `0xcba`; nhánh từ chối đi tại
`0xcc6`; nhánh còn lại mới ghi 1 tại `0xce1`. Lượt chụp bị dừng
sau khi lấy dữ liệu, không phải kết quả chạy toàn bot hoàn tất.

Bộ kiểm mới:

- Bỏ thao tác ghi riêng cờ `0x67470` của bộ kiểm cũ.
- Chỉ cho khôi phục nguyên khối dữ liệu đã chụp; ghi riêng hai
  byte trên bị từ chối, kể cả ghi lại cùng giá trị 1.
- Chặn mọi lệnh ghi của mã máy vào hai byte và chặn điểm vào
  `0xc30`, `0x5880`, `0x3d6c0`, `0x4d260`.
- So hai byte sau mỗi ca; đủ 57 lần khôi phục đúng khối gốc.
  Bốn phép thử ghi riêng đều bị chặn và giữ nguyên dữ liệu.
- MQL5 chỉ nhận giá trị trạng thái đã quan sát trong bản chụp.

Đây là kiểm thân nghiệp vụ với trạng thái đầu vào đã quan sát;
không chạy lại, giả phản hồi hoặc xác nhận cơ chế kiểm quyền.
Nguồn tạo cờ lưu `0x6216c` và toàn chuỗi xác thực vẫn chưa chốt.

## Lặp lại và giới hạn

`kiem-danh-gia-trang-thai-goc-bot-1.py`: `generate`, `prepare RUN`,
`mql5 RUN --build BUILD`, `original RUN`, `compare RUN`.
Dùng tên lượt mới và máy thử bot 1 riêng. Bản biên dịch
`b1-observed-evaluation-check-20261029-r1`: **0 lỗi, 0 cảnh báo**.

Kiểm độc lập đã yêu cầu thêm đối chiếu mã vùng mã với `capture.json`;
đã bổ sung và chạy lượt `r2`. Giữ lượt `r1` và công cụ của lượt đó.

Còn ghép chuẩn bị/đánh giá/lịch sử liên tiếp, điều chỉnh số dư khi
rút tiền, các nhánh lỗi, hình ảnh giao diện, vòng đời và EA đầy đủ.
Chưa phải phép chạy cặp hai EA hoặc xác nhận toàn bộ quyền dùng.

[Số liệu](verification.json), [nguồn trạng thái](provenance.json),
[bốn phép chặn ghi](write-guards.json),
[danh sách tệp](../observed-evaluation-bot1-20261029-r1-manifest.txt).
