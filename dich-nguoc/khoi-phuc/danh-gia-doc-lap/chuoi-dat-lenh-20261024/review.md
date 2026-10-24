# Rà độc lập chuỗi hàng đợi → tạo → gửi

Hai agent chỉ đọc đã kiểm bộ kiểm gốc và bản chạy trong máy đo quá
khứ. Agent chính đã đọc lại mã, chạy và đối chiếu các nhận xét.

- Thân hàm tạo lệnh gốc chạy thật. Điểm theo dõi đầu hàm không sửa
  thanh ghi trả về, địa chỉ chạy hoặc ngăn xếp. Chỉ nhận đã trả về
  khi đúng địa chỉ gọi trong hàng đợi và đúng độ cao ngăn xếp.
- Mã gốc tự tính kết quả đúng/sai. Trạng thái 35 trường và bốn chuỗi
  được quan sát trước/sau để so, không được chép vào trạng thái gốc.
- Bảng hàng đợi so đủ 500 số theo byte, kể cả phần dữ liệu của số
  không xác định. Thay đổi ca kiểm chỉ áp dụng sau hàm tạo lệnh trả.
- Đã sửa khoảng kiểm thuộc tính: so giá trị/trạng thái trả về với
  đầu vào ca, trước khi chạy mã gốc và khi so lại. Mã thuộc tính cách
  khớp là 50, đã đối chiếu bộ kiểm chuẩn bị cũ và dữ liệu MT5 thật.
- `accepted` đầu vào nay bị ràng bằng kết quả gửi dự kiến đầu tiên;
  chuỗi thử lại chọn theo số lần tạo lệnh. Không tính nó là một trục
  kiểm độc lập. Kết quả gửi cũng bị ràng trực tiếp với dữ liệu ca.
- Đã giữ mã kiểm Python, bố cục trường, bảng hàm, bản chụp vùng nhớ,
  bộ máy quan sát và bằng chứng số không xác định trong chuỗi mã băm.
- Bản máy đo quá khứ giữ các hàm thay thế gửi/gửi không chờ. Tệp hỗ
  trợ chỉ đổi đường include; nguồn giao dịch không đổi. Không thấy
  đường gửi lệnh thật trong bản kiểm.
- Bản biên dịch hiện hành của chương trình kiểm là
  `b1-pending-pipeline-02`/`b3-pending-pipeline-02`. MetaEditor trả
  mã tiến trình 1 nhưng nhật ký 0 lỗi/0 cảnh báo và bản EX5 đã chạy
  xong đủ ca; không dùng riêng mã tiến trình làm bằng chứng biên dịch.

Kết quả kiểm tổng hợp: 818/818 ca mỗi bot, trùng mã gốc/chương trình
MQL5/máy đo quá khứ; sáu loại dữ liệu cấp sai bị từ chối. Xem
`../../KIEM-CHUNG-CHUOI-DAT-LENH-BOT-1-3.json` và
`../../PHAN-TICH-CHUOI-DAT-LENH-BOT-1-3.md`.

Giới hạn còn nguyên: dịch vụ MT5 được cấp dữ liệu, chưa kiểm nơi
giao dịch, toàn EA, tất cả cài đặt, hiển thị, khởi động lại và lỗi
cấp bộ nhớ/CPU. Đây không phải kết luận hoàn thành toàn bộ bot.
