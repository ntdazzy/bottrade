# Sửa chỗ nối bình luận khởi động bot 1

Đối chiếu nơi gọi chuẩn bị thật phát hiện bản nối trước dùng nhầm
`p.comment`. Đây là hai vùng riêng trong mã gốc:

| Vị trí | Vai trò | Bằng chứng lệnh máy |
|---|---|---|
| `0x62470` | Bình luận giao dịch dùng ghép `B1/B2/S1/S2` | Nạp nguồn tại `0x4e56`, gọi sao chép tại `0x4e77` |
| `0x62480` | Bình luận của bước chuẩn bị `p.comment` | Nạp đích tại `0x7e40`, gọi sao chép tại `0x7e4e`; nguồn là `0x622d0` |

`Bot1InitializeStartupPostPreparation` nay nhận `order_comment` riêng.
Bộ kiểm so cả hai chuỗi ở đúng hai vị trí, gồm 16 tổ hợp NULL, rỗng,
chữ thường và UTF-16. Mã gốc chạy liên tục, không đặt lại điểm nối.

- Lượt `b1-startup-joined-20261028-r2`: **655/655 ca**, 125 giá trị,
  1.800 ô bảng, 24.419 lời gọi và 19.623 phép số học CPU khớp.
- Bản cố ý dùng nhầm `p.comment`: phát hiện **651/655 ca** khác.
- Bản đối chứng không cài lỗi: **0/655 ca** khác.
- Bốn lỗi nối cũ vẫn bị phát hiện: khối lượng 655, chỉ số 385,
  khối lượng ban đầu cũ 3, vé lệnh 2 ca.
- Hai chương trình kiểm và bộ ghép 103 tệp đều biên dịch 0 lỗi,
  0 cảnh báo (`joined-check-r2`, `negative-check-r2`, `all-headers-r26`).

655 ca vẫn chỉ chứng minh đoạn sau chuẩn bị đến trả về. Hai hàm tìm
mức và ba hàm bảng dùng bộ ghi, phản hồi MT5/cấp phát thành công được
cấp. Còn thân chuẩn bị trong phép chạy nối, phần trước OnInit, lỗi,
cài đặt và các sự kiện; chưa có EA hoàn chỉnh hay chạy cặp toàn bot.

Giữ nguyên bằng chứng r1 để truy lỗi. 639 ca cũ không chứng minh đúng
liên kết với `Bot1PreparationState.comment`, vì bộ kiểm cũ gán trường
này vào sai vùng gốc. Bảng theo dõi hiện hành dùng kết quả r2.

[Kết quả và mã kiểm](verification.json). [Danh sách tệp](manifest.txt).
