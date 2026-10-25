# Bộ kiểm ghép sửa và đóng vào quản lý bot3

Claude đã mở rộng bộ kiểm MQL5 hiện có, Root đọc phần gửi lệnh và giữ
nguyên thân khi ghép. Toàn bộ OrderSend/OrderSendAsync được đổi sang
dịch vụ giả trước include headers. Không gửi lệnh tới người môi giới.
Bản b3-management-trade-check-20261026-r1 biên dịch0lỗi/0cảnhbáo.

Đã chạy lại HAI CHẾ ĐỘ CŨ trên nguồn mới, cùng364ca mỗi chế độ:
- manager-trade-legacy-20261026-r1: khớp364/364, SHAfc6a...f31b.
- manager-trade-regression-20261026-r1: khớp364/364, SHA5701...4478.

Nhánh mới ExecuteTradeChildren đã biên dịch, CHƯA chạy so. Bộ chạy
Python hiện buộc cờ nàyfalse khi kiểm hai chế độ cũ. Không lấy hai bộ
364ca cũ làm bằng chứng nhánh mới đã đạt hoặc quản lý đã xong.
Còn viết phía chạy gốc choSelectByTicket/gửi lệnh/khởi tạo CTrade,
đọc đủ35trường request/result/check và trạng thái phụ để so.
Các vị trí đã chốt ởmanagement-integrated-tables-20261025-r1/trade-next-bindings.json.

Hợp đồng nhánh mới nằm ởTASK.md của đề xuất Claude:
version3,192byte/ca; băm từng yêu cầu gửi, trạng thái trước/sau, toàn
trạng thái công khai và số lần gửi. IsStopped=false, kiểu khớpFOK,
log0 và kết quả dịch vụ đều là dữ liệu cấp; chưa phải tài khoản thật.
Guard overloadSymbolInfoInteger3đối số chỉ dùng để báo lỗi nếu đường
ngoài phạm vi xuất hiện, không tự tạo kết quả cho nhánh chưa biết.

Ghi đúng những việc còn phải làm: chạy mới cả sửa/đóng thật qua bộ gửi,
kiểm sát ngưỡng/lỗi/trạng thái liên tiếp; kiểm hai phần bot1 mới; rồi
nối nguồn cấu hình/sự kiện/vào lệnh/hiển thị/lưu trạng thái thành EA.
Chưa bot nào được xác nhận hoàn chỉnh.
