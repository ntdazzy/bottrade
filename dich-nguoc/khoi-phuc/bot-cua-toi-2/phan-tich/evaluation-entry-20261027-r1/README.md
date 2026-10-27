# Đầu hàm đánh giá bot2 — bằng chứng bổ sung

Đã kiểm lại đúng EX5 đã cài390d8... và thân hàm `186c0..1f2b3`,
SHA `6daf563f...beb951`. Bản liệt kê đủ5.453lệnh của dải này được lưu
nguyên từ các byte đã kiểm. Số lệnh này không chứng minh đã hiểu toàn hàm.

Các điểm đầu đã chốt bằng raw:

- `18721`: nhận chỉ số người gọi ởECX32bit, lưu tại stack+0xc4.
- `1889b`: gọi địa chỉ engine+0x7d1ce0 (TimeTradeServer); `188b2`
  lưu giờ tại stack+0xf8, `188ba` gọi engine+0x7d1f60 (TimeToStruct)
  với mảng lịch tại stack+0x48.
- `188bc..18985`: so tên mã hiện tại với chuỗi cố định, chọn mô tả
  tên mã hoặc dữ liệu dự phòng rồi sao chép chuỗi. Cần đọc chuỗi gốc
  để chốt ý nghĩa; chưa tự đặt tên thành một mã cố định.
- `18987/18991`: đọc và kiểm byte tạiRVA682f8 trước nhánh thông báo;
  chưa đặt tên ý nghĩa cờ nếu chưa so luồng đầy đủ.

Hàm có các lời gọi lịch phiên và quản lý/tạo mức vị thế như agent đã
chỉ ra trong bản C; các điểm sau này còn phải chốt bằng raw và phép
chạy trước khi viết MQL5. Đặc biệt chưa xác nhận ý nghĩa mọi cờ, công
thức, thứ tự và mọi đường thoát. Chưa cóEA hoặc mã nguồn được chấp
nhận cho đoạn này; không lấy sự giống bố cục với bot1/3 làm thuật toán.

[Bằng chứng/mã kiểm](evidence.json), [raw](native-186c0-1f2b3.txt).
