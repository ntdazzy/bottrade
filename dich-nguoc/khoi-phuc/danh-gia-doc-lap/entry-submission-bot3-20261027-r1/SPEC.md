# Bot3: vòng phát sinh lệnh sau nến mới

Nguồn `Bot3EntryLoop.mqh`, `Bot3EntrySubmissionLive.mqh`; vùng gốc
`0x26f9e..0x29c88`, dừng trước thống kê/hiển thị. EX5 giữ nguyên.

- Nhóm15mã dựng một lần từ magic_base, cộng32bit rồi mở rộng dấu64bit.
  Cờ mua/bán cũng chụp một lần; giới hạn vòng đọc lại sau mỗi lượt.
- Chạy nguyên hàm khối lượng `0x3f900`, áp max_lots, cập nhật hạn và
  xóa quá hạn theo thuộc tính1/số giây32bitkhôngdấu như bản gốc.
- Trước mỗi hướng, kể cả cờ hướng tắt: đếm vị thế của mã hiện hành
  từ tổng xuống0. Đạt giới hạn int0x6d2e4thì hủy lệnh xa cùng hướng.
  Nếu chưa đạt, đếm lệnh nhóm15mã theo từng lần đọc magic; chỉ tiếp
  khi count<double0x6d240là so có thứ tự. NaN cũng chuyển sang hủy.
- Sau cổng trên mới đọc cờ hướng đã chụp; cổng vị thế cùng hướng
  đi tăng và đọc tổng ở cuối. Tìm mức→nearby→đếm cùng mã→đổi tại
  count==maximum→làm tròn/offset giữ các công thức và lần đọc gốc.
- Có thêm quét chặn giá sau offset: mua bị chặn khi giá lệnh<=giá mới,
  bán bị chặn khi giá mới<=giá lệnh. NaN không qua phép chặn có thứ tự.
- Ký quỹ/kiểm khối lượng/AllowsPendingOrder/khoảng cách/gửi chạy thật.
  Mọi lần gửi đọc expiration trước omit. Nhận lần đầu ghi bool1/giá
  cơ sở; retry132giữ giá, đọc lại cấu hình, chờ2500và bỏ bool retry.

`Bot3EntryLevels.mqh` chỉ đổi dữ liệu toàn cục sang tham chiếu hằng;
khung dò truyền bằng giá trị. Thân hàm giữ nguyên, bản trước có sẵn
trong `Bot3EntryLevels-before.mqh.txt`.

`kiem-vong-phat-sinh-lenh-bot-3.py prepare|mql5|original|compare 3 RUN`;
`mql5` cần `--build BUILD`. Bộ ghi:
`tao-bo-kiem-vong-phat-sinh-lenh-bot-3.py`.

R1: **260/260ca khớp**, **23.556 lần gọi dịch vụ**; mọi thân con gốc
tự chạy. So trạng thái thực dùng/ghi, đối số và giao dịch trước từng
dịch vụ/cuối vòng. Nguồn gọi trực tiếp/bộ kiểm0lỗi/0cảnh báo.

Có giới hạn âm/0/dương, cờ0/1/255, vị thế/magic64bit, lệnh gần/thay,
hạn không dấu, ký quỹ/SLTP/hạn ảo/gửi hai kiểu/lỗi/retry; riêng B3
gồm giới hạn nhómNaN/vô cực, đủ15mã và tràn số nền32bit.

Rà độc lập `friday_flow_review`: không thấy sai khác cụ thể trong
cổng riêng B3, thứ tự quét/giá và gửi; không thay phép so.

Lượt ghép dùng chế độ khối lượng0và tắt rút tiền; những chế độ khác
có bộ kiểm riêng, chưa ghép lại trong lượt này. Dịch vụ/lỗi/chờ/giá
được cấp; không gửi lên tài khoản thật. Không phải toàn evaluator,
khởi tạo/hiển thị/EA hoặc cặp toàn bot. Không đổi260ca thành phần trăm.
