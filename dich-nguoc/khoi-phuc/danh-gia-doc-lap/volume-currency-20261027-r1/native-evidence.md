# Bằng chứng raw

- Bot1 `0x36220`: lệnh gọi `AccountInfoString` ở `0x362d1`, kiểm USD ở
  `0x36301`, đọc lại nếu khác ở `0x3636c`, rồi đọc mới tại `0x363bc`.
  Các nhánh tiếp theo đọc chuỗi mới ở `0x36473`, `0x36527`, và các nhánh
  sau; thân dùng `iClose(...,0x4018,1)` rồi chỉ đọc lần hai khi giá dương.
- Bot3 `0x8300`: cùng mẫu ở `0x83b1`, `0x83e1`, `0x844c`, `0x847c`;
  nhánh đổi giá bắt đầu tại `0x8753`. Cổng `0x41780` lặp mẫu ở
  `0x41831`, `0x41861`, `0x418cc`, `0x4191c`; nhánh chia trực tiếp khi
  giá đã dương ở `0x41c36` và `0x41f42`.
- Raw cho thấy các điều kiện tiếp nối bằng nhánh riêng; mã phục dựng
  không dùng `break` sau lần khớp đầu.
