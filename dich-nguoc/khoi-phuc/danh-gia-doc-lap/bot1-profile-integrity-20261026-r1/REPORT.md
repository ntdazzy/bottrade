# Kiểm độc lập khối nạp cấu hình bot 1

## Phát hiện và sửa

- Mã native tại vùng profile 1 có lệnh nạp hằng `20.0` vào `R9` trước khi
  ghi `aux_offset` ở RVA `0x1367e`. Bộ dò cũ không nạp thanh ghi này và sinh
  `0.0`; `Bot1BaseDistances.mqh` đã giữ lại `aux_offset[1]=20.0`.
- Profile 5 có tiền nạp `R8=base+0x4ff00` trước block; nếu thiếu sẽ dừng ở
  `0x15069`. Bộ dò đã nạp đúng con trỏ.
- Các thanh ghi còn chưa xác định của profile 2/4 chỉ xuất hiện sau lần ghi
  trường profile cuối, trong phần sao chép chuỗi; bộ dò tách riêng và bắt buộc
  không có thanh ghi chưa xác định trước lần ghi cuối.

## Kết quả mới

Lượt `b1-runtime-profile-20261026-r7` chạy **432 ca native/MQL5**, gồm hai
HL, randomization hữu hạn/NaN/vô cực, bốn ô điều chỉnh hữu hạn/NaN và ba seed.
Kết quả **432/432, 0 lệch**, mã kiểm hai tệp
`6dc91e388f951cb0f81a2d6cd3086d2d5d312e104830a52bb0881401f8092784`.
Mã kiểm biên dịch **0 lỗi, 0 cảnh báo**.

Bộ dò mới ghi mã kiểm các tệp include sản phẩm, lưu raw bits của trường double,
kiểm tiền nạp, điểm dừng và không dùng kết quả MQL5 làm giá trị mong đợi.

## Giới hạn

Khối vẫn chưa có caller từ EA chính, chưa xác định khởi tạo seed của toàn
chương trình và chưa phải phép chạy hai EA hoàn chỉnh.
