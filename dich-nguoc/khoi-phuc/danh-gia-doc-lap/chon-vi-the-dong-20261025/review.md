# Rà quét/chọn vị thế qua đóng

Cha và hai lượt đọc độc lập đã đối chiếu kiểu số, dữ liệu vào/ra,
cờ chuỗi trống, phép cộng mã, thứ tự truy vấn và việc nối toàn bộ phần
đóng. Các ý kiến đều được kiểm lại bằng tệp hiện hành và mã gốc.

- Nguồn MQL giữ tổng..0, mã cộng 32 bit rồi mở rộng có dấu, so mã/loại
  đủ 64 bit, đọc lại mã mỗi phép so và đọc lại vé sau truy vấn khối lượng.
- Một nhận xét nói thiếu phần cuối hàm ghi trạng thái đã được rút lại:
  đọc đủ hàm và so băm với biên nhận cho thấy nguồn đã ghi đủ. Không
  sửa mã theo nhận xét sai đó.
- R1 khớp dữ liệu đầy đủ ở mã gốc/MQL5/máy đo quá khứ. Tổng kiểm
  sau đó phát hiện bộ đọc có thể nhận tệp thiếu 2/4 byte cuối. Bằng
  chứng trước/sau sửa nằm trong `parser-eof-r1.json`/`parser-eof-r2.json`.
- R2 thêm điều kiện đọc đúng hết tệp và kiểm ngăn xếp khi phần kiểm
  đóng trả về. MQL5 không đổi. Nguồn và dữ liệu từng lượt giữ riêng.
- Trạng thái được so trước truy vấn, sau gửi và ở hai đầu phần kiểm
  đóng. Chỉ đặt lại bộ đếm dữ liệu cấp sẵn khi bước vào phần ấy;
  không thay thuật toán hoặc đặt lại trạng thái bot.
- Các thử dữ liệu sai hiện từ chối 36 kiểu giá trị/dấu gọi và chín
  trường hợp cắt cụt tệp mỗi bot. Kết quả chạy lại r2 phải lấy ở biên
  nhận r2, không dùng kết quả r1 để gọi r2 đạt. R2 đã chạy lại và khớp
  4.598/4.598 ca mỗi bot ở mã gốc/MQL5/máy đo quá khứ; tổng kiểm đạt.

Vẫn chưa có bằng chứng cho mọi trạng thái chọn/mã lỗi MT5 thật,
mọi đường nạp/ghi giá, mọi tham số, lỗi cấp bộ nhớ hoặc toàn EA.
Số lần cấp/giải phóng cân bằng chưa chứng minh mọi phép dùng bộ nhớ
đều hợp lệ. Có kiểm địa chỉ và ngăn xếp khi phần kiểm đóng trả về;
chưa coi đó là phép chứng minh mọi đường gọi gián tiếp trong EX5.
