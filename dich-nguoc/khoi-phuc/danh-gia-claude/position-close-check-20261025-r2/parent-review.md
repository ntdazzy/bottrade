# Đối chiếu báo cáo r4

Claude đã đọc bản nguồn r4 lưu riêng và xác nhận bảy phần sửa; không
nêu lỗi còn lại đã chứng minh. Cha đã tự chạy tổng kiểm, không chỉ
đọc các tệp JSON như Claude. Biên nhận ghi năm yêu cầu mới đều dùng
`claude-opus-5-5`, mức `max`; phần nhật ký của lượt trước giữ nguyên.

Giới hạn của báo cáo được giữ riêng:

- Các phép đổi kiểu trên hằng số có thể được trình biên dịch tính sẵn.
  Bằng chứng là đầu ra của biểu thức MQL, chưa chứng minh tất cả phép
  đổi kiểu ấy gọi cùng hàm chạy máy như bản gốc.
- Băm terminal được lấy sau khi chạy; chưa có phép bắt terminal tự
  đổi bản trong khi chạy. Đây là máy thử riêng, băm hiện hành khớp;
  không dùng điều này để khẳng định mọi lần chạy trong tương lai.
- Tổng kiểm đối chiếu từng băm nguồn với biên nhận và bản lưu riêng,
  đồng thời kiểm dữ liệu ba nơi chạy. Công cụ `compare` riêng ít chặt
  hơn tổng kiểm ở bước kiểm lại băm nguồn. Bằng chứng cố ý bị sửa đồng
  thời nhiều tệp cần thêm neo lịch sử Git, không chỉ các JSON tự ghi.
- Cân bằng số lần cấp/giải phóng bộ nhớ chưa chứng minh không có dùng
  bộ nhớ đã giải phóng. Vùng mã được phép còn chứa hàm hủy thừa kế.
- Chưa có mọi cặp cờ cách khớp khác nhau giữa hai lần đóng, hoặc chế
  độ ưu tiên 1 trong nhóm hai lần đóng. Chế độ 1 đã có trong nhóm gọi
  trực tiếp; không coi đó là thay cho phép ghép còn thiếu.
- Truy vấn/kết quả gửi được cấp; chưa có bằng chứng toàn EA, tài
  khoản/nơi khớp thật, lỗi cấp bộ nhớ hoặc 100% bot.

Không sửa bằng chứng r4 để làm mất các giới hạn này. Bảng P23 giữ các
việc cần kiểm tiếp; không quy đổi 2.589 ca thành phần trăm toàn bot.
