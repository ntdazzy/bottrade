# Ngữ cảnh bot1 khi lần lấy vé đầu của quản lý trả0

Mục tiêu: chốt giá trị `bar_first_zero_ticket_changed` của nơi gọi đã
phục hồi, không thay nó bằng hằngtrue/false từ vài lượt quan sát.
Hàm gốc271f0 lưu R12 nhưng chưa gán nó trước vé đầu; vé0 đi27357 test
R12B, rồi27365 chọn EBX=1 nếu khác0. Chỉ sau nhánh khác mới có xorR12D.

Đã liệt kê tất cả lệnh ghi R12/R12D trước đường nến mới1a245 trong
evaluator18aa0..1a2eb. PUSH/CMP không ghi giá trị:

- `18f13`: địa chỉbase+6246c, byte thấp6c, nếu bật bổ sung mức và tổng
  vị thế đọc lúc đó>0. Hàm sửa26d20 lưu/khôi phụcR12, không thay kết quả.
- `18f55`: con trỏ `frame+1a8`, khi ngày khác0/6. Với khung ngăn xếp
  đúng căn16byte ở thân evaluator, địa chỉ này có dư8 khi chia16, nên
  byte thấp không thể0; không cần đoán một địa chỉ ngăn xếp cố định.
- Báo phiên `19237/1924e`, `1936e/19385`: giữ độ dài phần chuỗi `day`/
  chuỗi ghép. `194d6`: xóa R12D về0 trước vòng các phiên ngày đó.
  `19b9d`: tăng bộ đếm phiên TRƯỚC lời gọi tiếp; sau ngày6 cóNphiên
  thành công, R12D=N nếu1<=N<10 (lần gọi tiếp trảfalse), hoặc9 nếuN=10.
  Không dùng N-1 cho trường hợp dừng bởi lần gọi tiếp trảfalse.
  Nếu ngày6 không có phiên, R12D=8 (với IntegerToString6
  trả đúng chuỗi1ký tự từ dịch vụ); không phải0. Mọi ngày0..6 được báo.
- `1a1ef` là nhánh đếm theo mỗi lần nhận giá, không thuộc cạnh vào1a245.
  Cả iTime và helper hủy chuỗi trên cạnh nến mới phải giữ R12 theo ABI.
- Nếu các nhánh trên không ghi thì giữ giá trị từ nơi gọi. Cạnh cấu
  hình bình thường đã nạp R12=base+69f70 (byte70), nhưng phép kiểm
  ngữ cảnh cũng cấp byte0 để chứng minh không ngầm thay bằngtrue.

## Công thức cần đối chiếu, chưa gọi đã đạt trước khi chạy

Ưu tiên theo các lần ghi cuối, không chỉ nhìn giá trị vào evaluator:

1. Nếu cờ bổ sung mức!=0 và tổng vị thế được đọc>0: true.
2. Nếu ngày hiện tại khác0/6: true (con trỏ căn16+dư8).
3. Nếu có chạy báo phiên: true trong mọi trường hợp ngày6 có0..10phiên.
4. Còn lại: byte vào từ nơi gọi!=0.

Mã nguồn phép nối cần dùng một hàm thuần với5đầu vào:
`uchar initial_levels`, `int initial_count`, `int day_of_week`,
`bool reported_sessions`, `bool incoming_changed`.
Không đọc lại PositionsTotal để dựng cờ: phải dùng kết quả đã đọc ở
bước bổ sung mức. Không thêm truy vấn hoặc sửa cờ bản quyền.

Phép kiểm chạy nguyên evaluator từ18aa0, qua phần đầu/bổ sung mức,
cạnh nến mới, tới thân271f0 thật và các lệnh27357..27368. Cấp tổng vị
thế=1 ở lời gọi đầu thân quản lý, vé đầu=0 để quan sát trực tiếp.
Lịch/phiên được cấp; biến tổng có thể khác giữa hai điểm gọi, điều này
được ghi rõ. Chỉ thay đầu vào trước lệnh đầu evaluator, không reset
thanh ghi/ngăn xếp ở giữa. Có các căn ngăn xếp khác nhau, cờ, ngày,
0..10phiên, tổngâm/0/dương và byte vào0/khác0. Mẫu phải kiểm tính liên
tục và nguyên cờ bản quyền chụp1; không tạo bypass khi cờ bằng0.

Giới hạn: cấp bộ nhớ và dịch vụ thành công theo bộ ca; không chứng
minh hỏngABI, hết bộ nhớ, mọi nhánh sau lệnh27368 hay toànEA. Chưa
ghép nguồn quản lý hoàn chỉnh từ bằng chứng này trước khi phép so đạt.
Giả thuyết N-1 ban đầu đã bị phép chạy trực tiếp bác bỏ; bản đặc tả/
nguồn trước sửa được giữ riêng để không che lịch sử phân tích.
