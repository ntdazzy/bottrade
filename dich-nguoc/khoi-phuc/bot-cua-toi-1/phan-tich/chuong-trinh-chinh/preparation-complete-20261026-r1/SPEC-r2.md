# Khối chuẩn bị bot 1 — nguồn và đối chiếu ngày 27/10/2026

Nguồn hiện hành: `Bot1Preparation.mqh`. Thân gốc `0x7500..0x831d`, SHA-256
`8679070031fe7f3309378147c8afc4bf2d4ab596b3ee22a73e8e6386db6c9d0d`.
EX5 cài đặt giữ SHA-256 `a3b0de423a06e10ebedc279307b93d7cb9188ba2bb5de77131a913c865b0e922`.

## Thứ tự đã dựng

1. Tạo ATR: chu kỳ từ `0x621c4`, cờ byte `0x621c8` chọn D1 hoặc khung hiện
   tại; kết quả âm thì in lỗi rồi trả về.
2. Sao chép 100 mẫu. Chỉ kết quả bằng 0 trả về; kết quả âm vẫn kiểm mảng.
   Mảng ngắn hơn hai phần tử phải dừng. Sau khi đặt dạng chuỗi, dùng mẫu
   logic thứ 1, tương ứng phần tử vật lý `size-2`.
3. Tham chiếu dương mới chia mẫu/tham chiếu. Tham chiếu 0, âm hoặc NaN đi
   nhánh `JBE` tại `0x763f`, bỏ phép chia. Chọn hệ số, thay hệ số 0 bằng 1
   rồi mới tính hệ số khối lượng. Không lấy nhánh từ diễn giải C khi khác
   lệnh máy.
4. Ghi chỉ số, đọc giá. Giá lỗi vẫn in thông báo rồi đọc thời gian, điểm và
   chữ số; giữ số lần đọc chữ số tùy nhánh. Chép đủ cài đặt, trạng thái đặt
   lại và comment theo thứ tự; các byte không đổi thành bool nếu gốc chép
   nguyên byte.
5. Đọc điểm, mức dừng và đóng băng riêng từng lần. Chuẩn hóa khoảng giá, độ
   rộng, mức dừng/chốt rồi tính thời hạn với phép nhân tràn uint32. Không
   thêm cách làm tròn.

## Kết quả và phạm vi

- `b1-preparation-full-20261027-r3`: **1.060/1.060 ca**, so 87 giá trị
  (trạng thái, comment, mảng/chỉ số, giá/thời gian và số lần/thứ tự gọi).
  Bao gồm 20 ca lỗi dịch vụ, mảng dài 3/4 có mẫu khác nhau, NaN/vô cực và
  cờ byte 255. Mã kiểm hai tệp:
  `3958df845e1a8470f7dbc7f9991c9cb6a630d931b4f22e4d42f0a348552b53ed`.
- `b1-prep-errors-20261027-r1`: **12/12 ca** khớp loại lỗi/dừng và không có
  kết quả bình thường: 10 ca chia cho 0, hai ca mảng dài 0/1. Chưa so đủ
  trạng thái trước lỗi, dòng/cột hoặc toàn bộ nội dung lỗi.
- Hai Script API/kiểm biên dịch 0 lỗi, 0 cảnh báo. Bật kiểm chia 0 bằng
  `bien-dich.ps1 -CheckFloatingPointDividers` để giữ cách dừng như gốc.

Các trả lời ATR, giá, thời gian và thông tin mã giao dịch được bộ kiểm
cấp. Đây là thân chuẩn bị đầy đủ với các đầu vào đã kiểm, chưa phải toàn
EA, toàn chỉ báo hoặc tài khoản thật. Còn nối đầu vào cấu hình, nơi gọi,
khởi động lại, hiển thị và so hai EA hoàn chỉnh.

`Bot1PreparationNumeric` cũ đã bị bỏ khỏi nguồn vì làm dừng sai khi tick lỗi.
Bằng chứng cũ giữ nguyên; không dùng bản ghép đó làm nguồn bàn giao.
