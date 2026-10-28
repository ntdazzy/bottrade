# Kiểm đủ cây số tài khoản của hàm quyền dùng bot 1

Đã xác định chính xác nhánh số trong hàm gốc `0x3d6c0..0x457cb`.
Cây số ở `0x407d2..0x457cb` cho phép **1.075 giá trị**, còn lại
từ chối. Bộ trích từ mã C trước đó chỉ tìm được 1.028 giá trị và
đã bỏ sót 47 giá trị trong các nhánh máy. Không dùng bảng C đó để
dựng hàm quyền dùng.

## Bằng chứng

- Bộ giải Z3 5.3.2 theo từng lệnh máy, từng nhánh và bảng nhảy.
  Giữ đúng phép so có dấu/không dấu, tràn 64 bit, thanh ghi 8/16/32/
  64 bit, phép kiểm bit và các lệnh đặt cờ. Lệnh chưa hỗ trợ phải
  dừng lỗi, không được bỏ qua.
- Bắt đầu với toàn miền 64 bit; chỉ byte thấp của `RSI` bằng 1 theo
  lệnh gốc `0x3d926`, các bit cao và thanh ghi khác không bị ép giá
  trị. Kết quả được chứng minh chỉ phụ thuộc số đầu vào.
- Phủ 1.547 đường tới kết thúc, 1.313 nhánh điều kiện và 217 lần
  tách theo bảng nhảy. Bộ giải xác nhận không còn miền đầu vào
  chưa đi tới kết thúc. Các khoảng cho phép được liệt kê đầy đủ.
- Chạy lại hàm gốc với **5.000 đầu vào**: toàn bộ 1.075 giá trị được
  cho phép, 3.925 giá trị sát biên/giữa khoảng/giới hạn số bị từ chối.
  **0 sai khác**. Đây là phép đối chiếu bổ sung, không thay chứng
  minh toàn miền ở trên.
- SHA-256 dãy số cho phép, thứ tự tăng và mỗi số 8 byte:
  `06640c9e395c2e8601daa5252eb7ee1047bea5428dac57313b951866a1c4dc1e`.
- Đã có Codex kiểm độc lập cách xử lý cờ, độ rộng thanh ghi, miền
  đầu vào và điều kiện dừng của công cụ.

## Dữ liệu riêng và giới hạn

Tên và số tài khoản chỉ nằm trong `.local/`, không đưa lên Git.
Bộ dữ liệu hiện hành:
`.local/bot1-auth-verified-login-data-20261028-r1/data.private.json`.
Nó chứa cây số đã chứng minh và 226 cặp chuỗi còn chờ kiểm đầy đủ.
Giữ nguyên các bản trích và thử nghiệm cũ để tra sai khác.

Đây chỉ là nhánh số của một hàm kiểm quyền. Chưa phục hồi/kiểm đủ
226 cặp chuỗi, hàm quyền dùng bên ngoài, mạng/nhánh dự phòng, vòng
đời hoặc EA. Không được thay toàn hàm quyền dùng bằng phép tìm số
trong bảng này hoặc bằng nhánh kiểm thử trả về đúng.

## Chạy lại

1. `trich-dieu-kien-tai-khoan-bot-1.py NEW_RUN` trích các cặp chuỗi
   và ứng viên từ C vào `.local/NEW_RUN/data.private.json`. Kết quả
   số của bước này được đánh dấu chưa đủ; không ghi đè lượt cũ.
2. `kiem-cay-tai-khoan-goc-bot-1.py NEW_RUN` chứng minh từ lệnh máy
   rồi so với hàm gốc. Kết quả và dãy số chỉ ghi trong `.local/NEW_RUN`.

Bước 2 đọc bản trích `bot1-auth-original-data-20261028-r1` để báo
sai khác với cách trích cũ; bản đó không phải chuẩn của chứng minh.

Công cụ thứ hai dùng `z3-solver==5.3.2.0` cài tại
`.local/auth-symbolic-runtime`; Python nạp đúng thư mục đó. Mọi bản
chụp được kiểm mã băm; EX5 gốc cũng phải đúng mã băm trước đối chiếu.
[Biên nhận không chứa dữ liệu riêng](verification.json).
