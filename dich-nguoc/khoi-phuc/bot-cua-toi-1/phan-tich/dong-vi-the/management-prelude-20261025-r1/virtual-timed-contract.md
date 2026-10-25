# Dời mức ảo sau thời gian chờ

Mô tả trước nguồn. Mua bắt đầu `0x29a67`; khi đủ giờ nhảy tới
`0x29e01..0x29ea9`. Kết thúc trước `0x29aab` hoặc `0x2a38b`.
Bán tương ứng `0x2d1b6`, `0x2d572..0x2d61a`, kết thúc trước
`0x2d1fd` hoặc `0x2db0a`. Các địa chỉ kết thúc là trước bước dời tiếp.

- Chỉ chạy khi double `0x624f8 > 0`; NaN không thỏa.
- Gọi `TimeCurrent(NULL)`. Sau lời gọi mới đọc int có dấu 32 bit ở
  `0x6745c`, mở rộng 64 bit, cộng thời gian mở đã chụp. Chỉ tiếp tục
  khi giờ hiện tại >= tổng; giữ cách cộng 64 bit của mã gốc.
- Chụp mức `0x62580` và giá hiện tại (mua giá bán, bán giá mua), rồi
  gọi `SymbolInfoDouble(SYMBOL_POINT=16)`. Sau lời gọi mới đọc khoảng
  `0x62500` và đơn vị `0x66d98`, tính khoảng×đơn vị.
- Mua cần `mức_đã_chụp + điểm + khoảng×đơn_vị < giá_đã_chụp`.
  Sau đó cần giá bán hiện tại < chốt lời đã chụp − `0x67468`.
  Nếu đạt, bật cờ thay đổi và ghi mức = giá bán hiện tại − khoảng×đơn_vị.
- Bán cần `giá_đã_chụp < (mức_đã_chụp − điểm) − khoảng×đơn_vị`.
  Sau đó cần `0x67468` + chốt lời đã chụp < giá mua hiện tại.
  Nếu đạt, bật cờ thay đổi và ghi mức = khoảng×đơn_vị + giá mua hiện tại.
- Mọi phép so phải có thứ tự, NaN làm điều kiện sai. Không có làm tròn,
  lời gọi sửa/đóng hoặc ghi giờ trong chính đoạn này. Cờ đã bật từ trước
  vẫn giữ nếu điều kiện không đạt. Đọc lại giá sau lời gọi lấy điểm.

Chưa phải toàn bộ phần dời dừng ảo. Còn các nhánh theo khoảng cách,
ngưỡng phụ, mức cao/thấp, khóa lời và bộ đếm, cùng việc ghi lại bảng.
