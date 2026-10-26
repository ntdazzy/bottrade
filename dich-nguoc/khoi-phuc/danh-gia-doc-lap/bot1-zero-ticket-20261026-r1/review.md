# Rà độc lập bản sửa vé0 đầu của bot1

Tác tử chỉ đọc `/root/review_bot3_parent_flow` đã đọc bản sửa và bộ kiểm,
không sửa mã hoặc chạy lại. Không tìm thấy lỗi vận hành hay khớp giả
trong phạm vi ba lượt352ca mới.

- Cờ bắt buộc, không mặc định; chỉ dùng khi index0 và vé0, helper vẫn
  trảfalse nội bộ để vòng ngoài tích lũy kết quả.
- Router nhánh từng lần nhận giá cấptrue; nhánh nến mới nhận cờ từ bên
  gọi. Không thay nhánh kiểm cấp phép.
- Bộ chạy chuỗi không ghi đè R12 khi thật sự vào hàm quản lý từ router;
  chạy nguyên thân nơi gọi, hai hàm quản lý và các hàm con đã bật.
- Kết quảfalse/true và chuỗi đều352/352khớp, giữ đúng giới hạn dữ liệu
  dịch vụ MT5 được cấp và chưa có EA đầy đủ.

Chưa chốt nguồn cờ vé0 của nhánh nến mới từ toàn chương trình chính.
Cờfalse ghi trong lượtcaller-chain không chứng minh nhánh nến mới vì
lượt đó đi nhánh theo từng lần nhận giá, nơi router cấptrue riêng.
