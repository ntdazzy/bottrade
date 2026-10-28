# Trạng thái giao dịch sau chuẩn bị đầu — bot 1

Đã dựng `Bot1StartupTradingState.mqh` từ đoạn OnInit gốc
`0x3cab..0x4e77`, gồm các nhánh đi qua `0x4f11..0x4f4b`.
Địa chỉ được tính bằng phép trừ đầu vùng mã, không lấy đuôi tên biến.
[Bảng vị trí 54 trường](storage-map.json).

## Phần đã kiểm

- Hai lần đọc số nến, thời gian, chênh lệch mua/bán và khối lượng đầu.
- Làm tròn xuống khối lượng, đọc lại bước/tối thiểu/tối đa, thông báo.
  Giữ nguyên chuỗi gốc, kể cả `lots!!` không thêm khoảng trắng.
- Đọc số dư, giới hạn dừng/đóng băng, khoảng dừng/chốt/dời dừng,
  thời hạn 32 bit và ba cờ tin.
- Mốc nến tuần `PERIOD_W1` và hai lần đọc mốc nến phút.
- Gọi tìm mức mua/bán, làm tròn lại theo hai lần đọc chữ số riêng,
  đặt lại bộ đếm và trạng thái.
- Bảng dừng do bot theo dõi: xóa 1.500 ô chỉ khi cờ đúng bằng 1.
- Bảng lệnh: xóa đủ 300 ô khi cờ đúng bằng 1; luôn xóa hai cột đầu
  của 100 hàng, giữ cột thứ ba nếu không chạy nhánh xóa cả bảng.
  Bảng kết quả kế tiếp và dữ liệu khác không bị gộp vào vùng xóa.

Lượt `b1-startup-trading-20261028-r6`: **315/315 tình huống khớp**,
**7.971 lần gọi**, **9.455 phép số học bằng CPU thật**. So 54 giá trị,
8 ô khối lượng, chuỗi/mã lỗi và dữ liệu bảng. Trước mỗi lời gọi so
trạng thái và mã kiểm toàn bảng; khi kết thúc so từng byte của đủ
1.800 ô. Kiểm toàn bộ đối số của hai hàm tìm mức được cấp kết quả.

Có các ca khối lượng âm có phần lẻ, tràn thời hạn, đổi giá trị giữa
lời gọi, hai số không hợp lệ cùng xuất hiện và giữ cột thứ ba.
Khối `native_624f8` chỉ chạy khi lớn hơn 0; đã kiểm cả giá trị âm,
0, dương và số không hợp lệ với khoảng cách ban đầu âm.

Bộ kiểm đã phát hiện và sửa hai lỗi trong bản viết đầu: đọc nhầm
tiền còn đặt lệnh thay cho số dư, và dùng khung ngày thay cho tuần.
[Hai bản biên dịch sai cũ bị từ chối](negative-controls.json).
Các lượt thất bại và lượt kiểm nhỏ hơn được giữ để tra cứu.

Nguồn kiểm `b1-startup-trading-check-20261028-r5` biên dịch 0 lỗi,
0 cảnh báo. Toàn bộ 101 `.mqh` tại `b1-all-headers-api-20261028-r23`
cũng biên dịch 0 lỗi, 0 cảnh báo.

## Giới hạn

Đây là đoạn chương trình sau lần chuẩn bị đầu, với trạng thái đầu
được cấp. Mã gốc chạy trong bộ mô phỏng từ bản chụp đúng SHA-256;
các phép cộng/trừ/nhân/chia dùng CPU thật. Dữ liệu dịch vụ MT5 và kết
quả hai hàm tìm mức được cung cấp. Chưa kiểm lỗi chia cho 0/cấp phát,
phần tên đối tượng/lịch sử/hiển thị sau đoạn này, toàn OnInit hoặc EA.

Không gọi hàm này thay cho khởi tạo tĩnh. Chưa có EA chính hoàn chỉnh
hoặc lần chạy cặp toàn bot; 315 ca không phải phần trăm hoàn thành.

## Chạy lại

`kiem-trang-thai-giao-dich-khoi-dong-bot-1.py` có các bước:
`generate`, `prepare RUN`, `mql5 RUN --build BUILD`, `original RUN`,
`compare RUN`. `generate` chỉ dùng khi chưa có nguồn kiểm. Dùng tên
lượt mới; không ghi đè bằng chứng cũ.

Sau khi biên dịch tệp ghép toàn bộ, máy thử có thể đã thay thư mục
nguồn và bỏ EX5 kiểm trước. Chỉ khôi phục đúng EX5 kiểm đã lưu sau
khi so SHA-256 với biên nhận; không lấy một bản EX5 khác để chạy.
