# Ghi chú khi ghép nguồn

Ba thân hàm từ Claude được giữ nguyên khi ghép Bot3ManagementVirtual.mqh.
Lượt virtual-20261025-r1 khớp 560/560 ca; nguồn, biên nhận và kết quả được
nối bằng SHA-256 trong final-verification.json. Chưa phải toàn hàm quản lý.

SUMMARY.md của đề xuất timed có một dòng gán current_level cho mốc H
ở ngăn xếp. Dòng đó sai: current_level nối với P tại RVA 0x6d670.
H là mốc riêng ở stack mua+0x78/bán+0x88, truyền vào tham số anchor
của nhánh khoảng giá. Khi ghép tiếp phải dùng contract.md và bản đồ
RVA đã đối chiếu; không dùng dòng mô tả sai của đề xuất. Giữ nguyên
đề xuất để không thay đổi bằng chứng Claude đã giao.
