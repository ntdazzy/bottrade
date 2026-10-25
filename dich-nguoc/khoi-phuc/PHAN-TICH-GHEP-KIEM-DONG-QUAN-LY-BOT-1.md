# Sửa nơi gọi hàm đóng trong quản lý bot 1

Đã sửa ba nơi gọi trong Bot1ManagementPrelude.mqh: đóng theo nến,
chạm dừng ảo và nhánh khoảng giá. Trước sửa, chúng gọi Bot1ClosePosition
(0x22c40). Mã gốc gọi Bot1TryClosePosition (0x3d010), có kiểm điều kiện
trước khi đi tới hàm đóng. Không thay hàm con đã kiểm riêng.

Bằng chứng gốc: phan-tich/dong-vi-the/management-20261025-r1/analysis.json
và branch-map.md của bot 1. Hai lần gọi theo nến ở 0x27a97/0x27c20
(mua), 0x2b4a0/0x2b636 (bán); đích đóng chung ở 0x2a963/0x2e451.
Mã SHA-256 EX5 vẫn là
a3b0de423a06e10ebedc279307b93d7cb9188ba2bb5de77131a913c865b0e922.

Nguồn mới truyền hai ô giá tick.bid/tick.ask và hai ngưỡng qua tham
chiếu tới hàm kiểm đóng. Vị trí gốc: giá 0x67758/0x67760, ngưỡng
0x66a70/0x67468. Vòng quản lý đầy đủ chưa có, nên chưa xác nhận toàn
bộ nơi nạp/ghi các giá trị này.

## Kiểm sau sửa

| Phép kiểm | Kết quả | Phạm vi |
|---|---|---|
| prelude-guard-20261025-r2 | 340/340 khớp | Đọc/lọc, dừng/chốt đầu, đóng theo nến; kiểm đầy đủ đối số rồi dừng ở ranh giới hàm con |
| cache-guard-20261025-r1 | 266/266 khớp | Bảng 100 vé/giá mở, các mức và cờ |
| virtual-guard-20261025-r2 | 924/924 khớp | 364 bắt đầu dừng ảo; 156 thời gian; 220 khoảng giá; 184 kiểm trượt giá; kiểm đầy đủ đối số hàm đóng |
| close-link-20261025-r2 | 36/36 đạt | Chạy hàm kiểm đóng thật từ cả ba nơi gọi; hai chiều, giá mua/bán khác nhau, chọn vé thất bại, loại không hợp lệ, hai ngưỡng, NaN và trạng thái dừng |

Ba bộ so đầu vẫn cấp kết quả dịch vụ/hàm con tại ranh giới gọi.
Bộ 36 ca bổ sung chính chỗ mà các phép so trước chưa phân biệt:
nó không thay Bot1TryClosePosition bằng hàm giả. Nó kiểm các lần chọn
vé, đọc mã/loại/dừng và trạng thái sau hàm con. IsStopped luôn true,
nên mọi đường tới hàm đóng đều dừng trước gửi lệnh.

Cả bốn bản biên dịch thành công là 0 lỗi, 0 cảnh báo:
b1-management-guard-prefix-02, b1-management-guard-cache-01,
b1-management-guard-virtual-02, b1-management-close-link-03.
Bản close-link-01 có hai lỗi kiểu tham chiếu trong chương trình kiểm,
đã giữ lại; bản 02 sửa bằng biến uchar/uint có tên. Rà độc lập sau đó
chỉ ra giá mua/bán bằng nhau chưa bắt được truyền đảo tham chiếu;
lượt r2/bản 03 đã tách hai giá. Hai bộ lớn cũng kiểm mẫu bit của
giá, hai ngưỡng khác nhau và độ lệch có giá trị riêng trước ghi lời gọi.

Các lượt và nguồn đã kiểm ở bot-cua-toi-1/bang-chung/kiem-quan-ly-vi-the/.
Công cụ mới: bot-cua-toi-1/tests/check-management-close-link.py.
Lặp bằng RUN mới và --build trỏ tới bản biên dịch đúng nguồn; không ghi đè.

Chưa phải phép chạy cả hai hàm quản lý hay EA. Còn ghép toàn nhánh,
các nơi gọi/điều phối, kết quả khớp lệnh, nhiều vị thế, lỗi bộ nhớ,
khởi động lại, bảng hiển thị/cài đặt và so cặp hai bot đầy đủ.
