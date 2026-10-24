Đã kiểm thêm, không trùng việc với các tác tử phụ:

- Hai bản chụp bot 1 và bot 3 cùng dùng máy thử có SHA-256 `5033d9d4…` và cùng địa chỉ nạp. Đây là bản máy thử đã dùng khi gắn nhãn API (`import.json:7-8`, `tao-ho-so-ma-chup.py:25-26`).
- Các hằng `ORDER_MAGIC=15`, `ORDER_TYPE=4`, `ORDER_SYMBOL=0`, `ORDER_PRICE_OPEN=9`, `BUY_STOP=4`, `SELL_STOP=5` có bằng chứng từ hai nguồn: bảng enum, và phép kiểm `entry-20261023-r3` (khớp 1.096/1.096 ca). Trong phép kiểm này, chương trình MQL5 tự ghi các hằng và bộ so kiểm từng giá trị (`Bot1EntryLevelsCheck.mq5:97-98`, `kiem-gia-vao-bot-1-3.py:23,232`).
- Cùng tệp C có chỗ so mã nhận diện bằng `(int)` (ví dụ C 17239). Hai hàm đếm thì không có `(int)`, nên nhiều khả năng so 64 bit. Điểm này vẫn cần xem byte máy hoặc chạy một ca kiểm riêng mới chốt được.

Ba tác tử phụ vẫn đang chạy. Tôi chờ kết quả rồi đối chiếu với phần tự đọc trước khi trả báo cáo.