# Rà năm hàm quét/đếm/giới hạn

Hai agent chỉ đọc đã rà nguồn và bộ kiểm. Agent chính đã chạy đối
chiếu, đọc lệnh máy và kiểm lại các kết luận:

- Năm hàm gốc chạy thật, không cấp sẵn kết quả. Bộ kiểm giới hạn
  vùng chạy theo bảng hàm và dừng khi ra ngoài vùng/API đã khai báo.
- Hai hàm đếm lấy đủ EAX có dấu; giới hạn lấy byte bool; dọn bảng
  không dùng giá trị trả về không xác định của hàm gốc.
- `cvttsd2si` chạy nguyên bản; không tự viết luật thay cho số không
  xác định/vô hạn. So đủ 1.600 byte của 200 số sau từng ca.
- Mã nhận diện/mã giá được truyền tham chiếu, các ca thay chúng sau
  lời gọi đã bắt đúng thời điểm đọc. Dọn bảng ép số trước hỏi tổng.
- Quét đủ total..0, không dừng sau khi khớp vé; xóa ghi +0.0 cho cả
  hai ô, giữ nguyên bit khi tìm được vé khác 0.
- Cả nguồn MQL5 và cùng thân kiểm trong máy đo quá khứ khớp:
  bot 1 307/307, bot 3 215/215. Hai bản biên dịch 0 lỗi/cảnh báo.

Nguồn hiện hành: `Bot1OrderScan.mqh`, `Bot3OrderScan.mqh`.
Lượt `scan-20261024-r2`, máy đo quá khứ `engine-scan-bN-r2`.
Kiểm chứng: `../../KIEM-CHUNG-QUET-LENH-BOT-1-3.json`.

Không có lỗi cần sửa đã chứng minh trong phạm vi này. Trạng thái
chọn lệnh là mô hình cấp sẵn, chưa đo riêng tác dụng của đọc vé 0
trên tài khoản thật. Chuỗi/mảng bị giới hạn trong bộ kiểm; chưa có
toàn EA, lỗi cấp bộ nhớ hoặc tất cả dữ liệu thực tế. Không coi số ca
đạt là tỷ lệ hoàn thành toàn bot.
