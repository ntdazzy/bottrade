# Ghép xử lý tin tới giới hạn lệnh chờ

Nguồn: `BotNPendingLimitStage.mqh`, `BotNEvaluationNewsAndOrders.mqh`.
Ghép tiếp phần tin/cuối tuần/chênh lệch giá/đặt lại lệnh đã kiểm;
không đặt lại trạng thái ở giữa. Dừng tại B1 `0x1c8c7`, B3 `0x26e3e`.

- Cờ bật phải đúng1. Tổng lệnh ngoài phải dương, chỉ đọc một lần.
- Đếm mua bằng tổng mới, duyệt từ tổng xuống0. Ghi cả vé0 rồi bỏ qua;
  đọc mã chiến lược sau dịch vụ, so64bit với32bit có dấu; so đủ chuỗi
  mã sản phẩm rồi loại4. Nếu số đếm lớn hơn giới hạn đang sống thì
  gọi nguyên thân xóa lệnh mua cao nhất.
- Tiếp tục đếm bán bằng tổng mới, không kiểm lại tổng ngoài hoặc cờ
  bật; loại5. Đọc lại giới hạn sau lần đếm rồi xóa lệnh bán thấp nhất.
- Bot1 dùng hai hàm đếm đã có; bot3 dựng từ hai vòng nội tuyến gốc.
  Cả hai dùng thân chọn/xóa đã kiểm, giữ cùng bảng kết quả và yêu cầu.

`kiem-gioi-han-lenh-cho-day-du.py prepare|mql5|original|compare BOT RUN`;
`mql5` cần `--build BUILD`. Bộ ghi tạo bởi
`tao-bo-kiem-gioi-han-lenh-cho.py`.

R1: **989/989ca mỗi bot**. Bot1 so **20.220**, bot3 **20.595** lần gọi
dịch vụ, trạng thái trước mỗi lần/cuối đoạn và500ô bảng. Nguồn trực tiếp
và bộ kiểm0lỗi/0cảnh báo. Các thân con tự chạy; không cấp kết quả thay.

Ca mới gồm cờ-1/0/1/2/255, giới hạn âm/0/1/2, tổng âm/0/1/2,
hai chiều, chuỗi khác hoa/thường, mã64bit không được ép về32bit.
Tám trả lời tổng độc lập mỗi ca kiểm việc đọc lại tổng giữa các vòng.
Dịch vụ thay cờ/giới hạn, đổi loại lệnh sau lần gửi mua để kiểm nhánh
bán vẫn chạy. Không lấy kết quả mã mới làm kết quả thuật toán gốc.

Giữ các điều kiện kiểm của lượt đặt lại: lỗi dịch vụ/chờ được cấp ở
rìa, đổi số thành chữ đo thật và kiểm bảo toàn lỗi; cấp phát thành công,
ô trả chuỗi ban đầu rỗng và khung đầu đoạn được cung cấp.

Rà độc lập `friday_flow_review`: không thấy lỗi đáng kể khi so nguồn,
bộ kiểm và vùng gốc; đánh giá không thay phép so. Bằng chứng chi tiết
trong `verification.json`, `native-bindings.json` và thư mục từng bot.

Chưa nối cổng vào/cập nhật mức giá/phát sinh lệnh phía sau. Chưa có EA
đầy đủ, kiểm mạng lịch/lỗi cấp phát/đầy đủ khởi tạo hoặc cặp toàn bot.
Số ca đạt không phải tỷ lệ hoàn thành bot.
