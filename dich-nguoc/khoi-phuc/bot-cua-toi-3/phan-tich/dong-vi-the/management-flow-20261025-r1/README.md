# Kiểm cả vòng quản lý bot3

Hiện hành: manager-flow-claude-20261025-r1, **364/364 khớp**, bản dựng
b3-position-management-flow-03: **0 lỗi/0 cảnh báo**. Kết quả hai bên cùng SHA
fc6a803d25990d0ea008bb8637f8f62d4dac076f345a9844465586e8751ff31b.
Hai thân mua 32f60/bán 37590 chạy từ đầu tới trả về thật, gồm vòng nhiều
vị thế và đổi chế độ thật/ảo. Không dùng đầu ra nguồn mới làm mong đợi.

So 20 trường: kết quả/cờ/bộ đếm/chế độ/chỉ số/lỗi/vé/giá và số lời gọi;
băm thứ tự/đối số, bảng mốc 200 ô, bảng dừng-chốt 2.500 ô và vé sống theo thứ tự.
Có 11 nhóm: thường, nhiều vị thế, rỗng, đổi chế độ sau lấy số chữ số,
chép cờ đầu hàm, sửa lỗi, đóng lỗi, vé 64 bit, lấy giá lỗi, tràn đếm lỗi,
đã đủ thời gian chờ. Số ca mỗi nhóm ở verification-summary.json.

Giới hạn: Modify/TryClose/StopLevel/TakeLevel/Delay/Stamp được cấp trả lời
và tác dụng phụ đã ghi trong CONTRACT. Dịch vụ MT5 được cấp dữ liệu. Thân
đổi lỗi, ghép chuỗi và in gốc chạy; đổi số thực thành chữ được đo riêng
bằng MT5. Chưa thay bằng toàn bộ hàm con hoặc chạy cặp EA. Chưa kiểm mọi
đầu vào/nhánh hay lỗi cấp bộ nhớ; không gọi364 ca là 100% bot.

## Lỗi thật đã sửa

Lượt manager-flow-initial-20261025-r1 khớp 134/136; hai ca bán 11/12 khác
Last Ask/Last Bid. Root đã đọc sai nhãn khi viết mô tả, Claude làm đúng
mô tả sai. Chuỗi 5e368 và lệnh 3b55e/3b6fb xác nhận Last Ask: ở bán.
Sửa nhãn trong Bot3ManagementRealStart.mqh, giữ nguyên TASK/đề xuất Claude,
nguồn thử và kết quả lỗi. Lượt 136 ca r2 khớp; hai lượt mở rộng Root cũng
khớp 364 ca trước khi ghép tệp đầu vào Claude. Không sửa đầu ra gốc để khớp.
Hai ghi chú mã nói chưa biên dịch/kiểm đã sửa thành mô tả trách nhiệm dữ liệu.

## Phân công và rà

Hai phiên Claude kết thúc vì lỗi 429 usage_limit_reached, hẹn 23:50 giờ Việt Nam.
Phiên tạo ca kịp Write tệp 356 ca trước lỗi, không có SUMMARY. Root đã kiểm
mọi giá trị khởi tạo với bản mô tả, sửa 2 tên khóa mảng nến cho giao diện và
thêm 8 ca dữ liệu chờ đã đủ. Toàn bộ 364 ca đã được chạy lại sau ghép.
Phiên viết bộ kiểm MQL5 chưa giao mã; Root viết phần này và bộ chạy gốc.
Biên nhận cho 24 yêu cầu thật đều Opus 5.5 max; chưa có bằng chứng Ultracode.

Rà độc lập Codex không thấy lỗi chức năng đáng kể trong bộ kiểm 136 ca;
364 ca là lượt Root kiểm tiếp, không gọi là rà độc lập toàn EA.
Xem danh-gia-doc-lap/parent-flow-20261025-r1/review.json từ gốc khoi-phuc.

## Nối vào chương trình chính

Đã xác nhận byte 1d6fa0 là input UseHL_TrailingSL bằng cài đặt đã đo 720 lần.
EnableVirtualSLTP=false cho mode 1, true cho mode 2 theo 2-(input==0).
C hiện có gọi quản lý từ 20ef0 sau thay đổi thời gian nến, không phải e0f0.
Còn kiểm lệnh máy nơi gọi, nguồn các tham số/trạng thái khác và nối EA.
settings-origin.json giữ mã kiểm tra và giới hạn; chưa chứng minh bộ nạp input.
