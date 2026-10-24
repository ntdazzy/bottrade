# Rà phần đóng vị thế

Hai lượt đọc độc lập đã rà công cụ chạy mã gốc, hai chương trình kiểm
MQL5 và công cụ tổng kiểm. Cha kiểm lại bằng lệnh máy và đối chứng có
nguồn; không coi ý kiến của agent là bằng chứng thay cho mã gốc.

- Đã sửa các nhận định phân tích ban đầu sai của agent: hàm đóng có
  gọi chọn cách khớp; lần so thứ hai dùng tham chiếu A đọc lại; thuộc
  tính 6 là dừng lỗ. Mã máy và chương trình đối chứng xác nhận các điểm này.
- Bản r4 có 2.589 ca mỗi bot; nguồn/bản biên dịch/công cụ đúng mã
  kiểm tra. Mã gốc, MQL5 và máy đo quá khứ khớp nguyên dữ liệu đầu ra.
- Các lượt đọc r3/r4 không tìm thấy lỗi còn lại đã chứng minh trong
  bố cục dữ liệu, chuỗi/cờ trống, chụp trạng thái, thời điểm dọn chuỗi
  và bộ đếm hai lần đóng. Đây là phạm vi được rà, không phải bảo đảm
  không có lỗi với mọi đầu vào.
- Tổng kiểm dựng lại đúng thân chương trình dùng trong máy đo quá
  khứ, kiểm bảy tệp nguồn, dữ liệu và EX5 đã chạy. Mọi lệnh gửi trong
  chương trình kiểm đều được thay bằng hàm cấp kết quả.
- MetaEditor ở hai lượt máy thử trả mã thoát 1, nhưng tạo EX5 đúng mã
  kiểm tra, nhật ký ghi 0 lỗi/0 cảnh báo và EX5 chạy đủ ca. Không suy
  ra ý nghĩa chung của mã thoát; kết luận dựa trên đủ ba bằng chứng này.
- Kiểm từng bản ghi đầu vào không tự chứng minh đã có đủ lời gọi;
  phần chạy mã gốc còn yêu cầu dùng hết bản ghi, kết thúc đúng vị trí,
  so trạng thái/đối số và so kết quả với MQL5. Tổng kiểm còn so băm tệp
  và dữ liệu nguyên vẹn của ba nơi chạy.

Chưa có bằng chứng toàn EA, nguồn tham chiếu/ngưỡng từ nơi gọi, mọi
cài đặt, bảng hiển thị, khởi động lại, tài khoản/nơi khớp thật, lỗi
cấp bộ nhớ và toàn bộ byte đệm riêng của MQL5. Kết quả đã chạy nằm
trong `KIEM-CHUNG-DONG-VI-THE-BOT-1-3-R2.json`; không quy đổi ra phần trăm
hoàn thành toàn bộ bot.

Khi kiểm ảnh hưởng từ tùy chọn `--close` mới, cha tái hiện được lỗi
`NEGATIVE_CLI_TOOL_CHANGED` trong tổng kiểm chọn lệnh cũ. Nguyên nhân:
băm công cụ chạy kiểm dữ liệu sai được so với runner hiện hành, thay
vì đúng bản runner đã lưu lúc chạy. Đã đổi sang hai bản lưu theo bot;
không sửa dữ liệu/bằng chứng cũ. Tổng kiểm chọn lệnh mới được lưu ở
`KIEM-CHUNG-CHON-LENH-HUY-BOT-1-3-R3.json`. Tổng kiểm đóng cũng dùng
đúng runner đã lưu, để việc bổ sung phần sau không làm sai lịch sử.
