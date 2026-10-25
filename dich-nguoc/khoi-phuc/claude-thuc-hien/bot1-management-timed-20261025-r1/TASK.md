# Viết nhánh dời dừng ảo theo thời gian bot 1

Đây là phần phục hồi nguồn bot giao dịch. Codex đã đọc mã máy gốc và
chốt hợp đồng ở `dich-nguoc/khoi-phuc/bot-cua-toi-1/phan-tich/dong-vi-the/management-prelude-20261025-r1/virtual-timed-contract.md`.
Bạn chỉ viết phần MQL5 theo hợp đồng; không cần tự phân tích EX5.
Không đọc EX5/C/bản chụp, không lệnh/MT5/git/kỹ năng lồng nhau, chỉ
Read/Grep/Glob/Edit/Write trong thư mục này. Không ghi ngoài thư mục.

Viết mã thật: `Bot1ManagementTimed.mqh` và `SUMMARY.md`. Tên hàm:
`void Bot1AdvanceTimedVirtualStop(...)`, dùng cấu trúc tham số rõ ràng
để giữ đủ dữ liệu hợp đồng. Không gọi sửa/đóng, không làm tròn, không
ghi giờ trong phần này. Có thể dùng cùng kiểu `MqlTick`/double/long
như nguồn MQL5 hiện có. Giữ thứ tự đọc sau lời gọi API, so dấu `<`,
NaN làm điều kiện sai và cờ thay đổi đã bật không tự tắt.

Hợp đồng phải giữ: bật khi activation>0; TimeCurrent trước khi đọc
lại delay; giờ hiện tại >= thời gian mở + delay; chụp mức/giá trước
SymbolInfoDouble(SYMBOL_POINT), rồi đọc lại khoảng/đơn vị; mua dùng
Bid và điều kiện mức+point+distance*unit < bid, bid < TP-freeze;
ghi Bid-distance*unit. Bán dùng Ask và điều kiện ask < mức-point-
distance*unit, freeze+TP < ask; ghi distance*unit+Ask. Nêu giới hạn
chưa có bằng chứng trong SUMMARY, không tự mở rộng nhánh.
