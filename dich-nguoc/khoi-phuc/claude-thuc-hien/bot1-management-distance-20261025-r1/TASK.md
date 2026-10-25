# Viết nhánh dời dừng ảo theo khoảng cách bot 1

Đây là phần phục hồi nguồn bot giao dịch. Codex đã đọc mã máy gốc và
chốt hợp đồng ở `dich-nguoc/khoi-phuc/bot-cua-toi-1/phan-tich/dong-vi-the/management-prelude-20261025-r1/virtual-distance-contract.md`.
Bạn chỉ viết phần MQL5 theo hợp đồng; không cần tự phân tích EX5.
Không đọc EX5/C/bản chụp, không lệnh/MT5/git/kỹ năng lồng nhau, chỉ
Read/Grep/Glob/Edit/Write trong thư mục này. Không ghi ngoài thư mục.

Viết mã thật: `Bot1ManagementDistance.mqh` và `SUMMARY.md`. Tên hàm:
`bool Bot1AdvanceDistanceVirtualStop(...)`, giữ rõ các tham số và cờ
thay đổi. Không tự thêm điều kiện chốt lời. Không hỏi số chữ số,
không sửa dừng và không ghi giờ trong phần này. Giữ thứ tự đọc sau
SymbolInfoDouble(SYMBOL_POINT), kiểu số, so dấu `<`, NaN làm sai.

Hợp đồng: chỉ chạy trail_distance>0; khoảng=(trail_step+trail_distance)
*unit; mua điều kiện mức+point+distance<Bid, trail_start*unit+anchor<Bid,
mức < trail_limit*unit+open; ghi Bid-trail_distance*unit. Bán điều
kiện Ask<(mức-point)-distance, Ask<anchor-trail_start*unit,
open-trail_limit*unit<mức; ghi trail_distance*unit+Ask. Sau ghi đọc
`0x66a80 + uint(strategy_index)*8`, nhân với +0 rồi làm tròn hai chữ
số; bật changed. Nếu lượng tính < volume vị thế, gọi volume min=34;
đóng khi volume tính >= min, kể cả bằng; NaN không đóng. Dùng vé địa
phương. Ghi giới hạn chỉ số 0..7 và nhánh còn thiếu trong SUMMARY.
