# Dời mức ảo theo khoảng cách

Mô tả trước nguồn; mua `0x29aab..0x29c64`, bán `0x2d1fd..0x2d3d1`.

- Chỉ chạy nếu `0x624a8 > 0`. Chụp mức `0x62580` và giá (mua giá
  bán, bán giá mua), rồi hỏi điểm giá. Các tham số phía sau đọc lại.
- Khoảng = (`0x624c0` + `0x624a8`) × đơn vị `0x66d98`.
- Mua cần mức đã chụp + điểm + khoảng < giá đã chụp;
  `0x624b0`×đơn vị + mốc đã chọn < giá bán hiện tại;
  mức hiện tại < `0x624b8`×đơn vị + giá mở.
  Ghi mức = giá bán hiện tại − `0x624a8`×đơn vị.
- Bán cần giá đã chụp < (mức đã chụp − điểm) − khoảng;
  giá mua hiện tại < mốc đã chọn − `0x624b0`×đơn vị;
  giá mở − `0x624b8`×đơn vị < mức hiện tại.
  Ghi mức = `0x624a8`×đơn vị + giá mua hiện tại.
- Sau khi ghi: đọc double tại `0x66a80 + uint(0x678f4)*8`, nhân
  với dương 0 rồi làm tròn hai chữ số bằng công thức gốc. Không thay
  bằng hằng 0: dữ liệu có thể là NaN/vô hạn. Bật cờ thay đổi.
- Nếu lượng tính được < khối lượng vị thế đã chụp, hỏi khối lượng
  nhỏ nhất (`SYMBOL_VOLUME_MIN=34`). Chỉ đóng khi lượng tính được >=
  mức nhỏ nhất, kể cả bằng nhau; NaN không thỏa. Đóng dùng vé địa
  phương và không lấy giá lại trong chính nhánh này.
- Không hỏi số chữ số, không sửa dừng và không ghi giờ trong đoạn này.
  Không thêm điều kiện cách chốt lời vào đây: lệnh máy không có.
- Bảng lượng có tám ô theo luồng chiến lược đã chụp; phép so này chỉ
  kiểm chỉ số 0..7. Chỉ số ngoài vùng chưa có bằng chứng lỗi MQL5/gốc.

Sau đoạn này vẫn còn nhánh theo ngưỡng phụ, mức cao/thấp, khóa lời,
bộ đếm và ghi bảng. Chưa phải toàn bộ quản lý hoặc EA hoàn chỉnh.
