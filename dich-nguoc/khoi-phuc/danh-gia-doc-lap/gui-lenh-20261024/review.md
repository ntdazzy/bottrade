# Kiểm độc lập phần gửi và ghép tạo yêu cầu

Agent nội bộ chỉ đọc đã so mã C, mã chụp, nguồn dựng lại và bộ kiểm.
Đây không phải đánh giá của Claude. Không thấy lỗi nguồn đã chứng minh
trong phạm vi đã giao sau khi sửa tiền tố `request` ở lượt kiểm đầu.

Hai bot khớp 1.201/1.201 ca gửi/thông báo và 1.687/1.687 ca ghép tạo
yêu cầu → gửi → thông báo. Lượt ghép so 35 trường, số nhận diện, cách
khớp, thứ tự/đối số có kiểu và chữ thông báo; kết quả gửi được cấp sẵn.

Hai điểm yếu đã nêu và được bổ sung bằng bằng chứng mới:

- Trước đây chỉ so 35 trường đã biết. `native-storage-audit.json` của
  mỗi bot kiểm thêm 628 byte lưu gốc ở đủ 1.687 ca: sau chuẩn bị thường,
  364 byte riêng bằng 0; nhánh dừng chỉ đổi mã kết quả trong vùng này.
  Chưa so byte đệm riêng của lớp MQL5.
- Bộ kiểm ghép nay kiểm lại điều kiện xác nhận sơ đồ trường, các vị
  trí 0/240/436, dấu cuối 628 và mã nguồn của chương trình đo sơ đồ.

Hai lượt kiểm bổ sung đều đạt; mã công cụ
`a6e265a8c1ab22ba1bcdcdd44695e9ef325cfe0bb6eb4465f75a37d23b6b59bd`.
Kết quả ghép gốc/MQL5 có cùng SHA-256
`611bc8a0bc38c3f7a22a632d639617296fd6f198230cda11ff0390bfb533570d`.

Các tổ hợp hành động/mã giá rỗng/NULL/dừng/chốt còn thiếu trong 697 ca
ban đầu đã được thêm thành bộ 1.201 ca. Không kết luận mọi tổ hợp đầu
vào đều đã được thử. Chưa kiểm nơi giao dịch, lỗi cấp bộ nhớ, hàng đợi,
thử lại hoặc toàn EA. [Biên nhận nguồn và kết quả](../../KIEM-CHUNG-GUI-LENH-BOT-1-3.json).
