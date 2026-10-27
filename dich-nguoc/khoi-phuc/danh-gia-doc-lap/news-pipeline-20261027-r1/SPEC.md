# Ghép đầy đủ phần xử lý ba loại tin

Bot 1: `0x1b44f..0x1c6f1`, dừng sớm `0x1a63a`.
Bot 3: `0x2372b..0x24f8d`, dừng sớm `0x22875`.
Mã kiểm tra bản gốc và bản liệt kê nằm trong `native-bindings.json`.
Giữ nguyên EX5; không dùng tài khoản thật hoặc sửa khóa bản quyền.

## Nguồn và thứ tự

- `BotNNewsFilterPipeline.mqh`: NFP → lãi suất → CPI → chọn lịch gần nhất.
- `BotNReleaseFilters.mqh`: hai nhánh lãi suất/CPI dùng chung cờ lịch,
  cờ chờ 900 giây, mốc UTC và dữ liệu giao dịch đang sống của nhánh NFP.
- Giữ đúng các lần đọc giờ, truy vấn lịch, thông báo, hủy lệnh chờ,
  đóng vị thế, chọn cách khớp và gửi. Không đặt lại trạng thái giữa các phần.
- Có lịch dương: lãi suất/CPI kiểm khoảng trước/sau tin rồi thoát nhánh.
  Không có lịch: báo một lần rồi tìm ngày dự phòng. Năm được đọc trước
  hàm giờ mùa; sau 2026 giữ byte chặn cũ. Đây là điểm khác nhánh NFP.
- Lịch dự phòng lãi suất/CPI: quét đủ tối đa 300 ô, chọn ô đầu cùng năm/
  tháng; chỉ dùng ngày dương, không thấy ngày thì xóa cờ chặn.
  Tính mốc theo giờ máy chủ, độ lệch giờ mùa và mốc UTC đúng thứ tự gốc.
- Phút nhân 60 bằng số nguyên 32 bit rồi mới đổi lên 64 bit; không nhân
  bằng 64 bit hoặc đổi dấu phút trước phép nhân.
- Bộ chọn lịch nhận tham chiếu đến từng trường đang sống, giữ việc đọc
  lại ngày tin sau lời gọi giờ máy chủ. Hàm nhận hai cấu trúc cũ vẫn gọi
  cùng thân này; bản trước sửa được giữ trong `BotNNewsSelector-before.mqh.txt`.
- Kết quả chặn: byte NFP khác 0, hoặc bit thấp của byte lãi suất/CPI bằng 1.
  Không đổi thành phép kiểm cả ba byte khác 0.

## Phép so

`kiem-chuoi-tin-bot-1-3.py prepare|mql5|original|compare BOT RUN`.
Bước `mql5` cần `--build BUILD`. Bộ kiểm được tạo bởi
`tao-bo-kiem-chuoi-tin.py`; dùng lại bộ ghi dịch vụ NFP đã kiểm.

MT5 riêng chạy mã MQL5 mới, chỉ ghi trả lời dịch vụ. Mã máy gốc tự chạy
thuật toán và phải khớp từng trạng thái trước dịch vụ, loại dịch vụ,
đối số, chuỗi, trạng thái lỗi và kết quả cuối. Không cấp kết quả của các
hàm lịch, hủy, đóng hoặc gửi thay thân gốc.

Lượt `b1/b3-news-pipeline-20261027-r7`: **133/133 ca mỗi bot**, so
**10.243 lần gọi dịch vụ mỗi bot**. Gồm 8 tổ hợp bật/tắt ba loại tin,
biên 900 giây, giờ dự phòng, trạng thái 0/1/2/3/255, phút tràn số,
chọn lịch sớm nhất và hủy/đóng hai chiều. Nguồn trực tiếp cùng bộ kiểm
biên dịch 0 lỗi/0 cảnh báo. Kết quả chi tiết trong `verification.json`.

Đánh giá độc lập `news_pipeline_review`: không có lỗi đáng kể trong
phạm vi nguồn, bộ ghi và bằng chứng r7. Không coi đánh giá là thay phép so.

## Giới hạn

Chỉ phần xử lý tin đã được ghép và kiểm. Khung đầu đoạn, lịch đã lưu,
trả lời dịch vụ và cấp phát thành công được cung cấp. Ba mảng ngày
được cấp rõ ở đầu ca; chưa chứng minh toàn bộ khởi tạo từng mảng.
Chưa kiểm máy chủ lịch trực tuyến, lỗi cấp phát, nhánh sau tin hoặc
EA đầy đủ. Chưa chạy cặp toàn bot gốc/dựng lại trong hai môi trường.
Các đề xuất của agent chưa đạt và bản nguồn kiểm r6 được giữ riêng,
không dùng làm bằng chứng đạt r7.
