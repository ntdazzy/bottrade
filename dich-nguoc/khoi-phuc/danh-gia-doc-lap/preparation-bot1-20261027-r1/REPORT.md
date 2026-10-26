# Bàn giao lượt chuẩn bị bot 1 ngày 27/10/2026

- Thêm nguồn `Bot1Preparation.mqh` cho thân gốc `0x7500..0x831d`.
- Bỏ hai tệp mã của `Bot1PreparationNumeric` cũ: nó trả về khi lấy giá lỗi,
  trong khi gốc in thông báo rồi tiếp tục. Lịch sử và biên nhận cũ được giữ.
- `b1-preparation-full-20261027-r3`: 1.060/1.060 ca, 87 giá trị và thứ tự
  dịch vụ khớp. Mã kiểm kết quả gốc/MQL5: `3958df84...`.
- `b1-prep-errors-20261027-r1`: 12/12 ca khớp loại lỗi và không ghi kết quả
  bình thường; chưa so đủ trạng thái trước lỗi hoặc dòng/cột báo lỗi.
- `b1-runtime-profile-20261027-r1`: 432/432 ca khớp sau khi sửa bộ dò; đủ
  127 byte của 22 trường, đúng tiền nạp nguyên lệnh và không đọc thanh ghi
  chưa ghi. Lượt này có danh sách mã kiểm từng báo cáo native.
- Biên dịch Script API và các Script kiểm: 0 lỗi, 0 cảnh báo. Hai EX5 cài
  đặt chỉ được đọc; không có lệnh gửi lên tài khoản thật.

## Rà độc lập

Đã kiểm thêm mẫu chỉ báo có giá trị khác nhau ở mảng dài 3/4 để chứng minh
hướng đọc mảng. Phản biện rằng tham chiếu bằng 0 phải báo lỗi đã được bác
bằng nhánh `JBE` tại `0x763f` và ca chạy gốc: nhánh này bỏ phép chia. Ca mảng
ngắn và chia 0 đã được đo thật trong MT5 riêng, không kết luận chỉ từ mã C.

Claude không có mã bàn giao: phản hồi 403 `oauth_not_allowed_for_organization`;
đã lưu biên nhận riêng. Theo yêu cầu người dùng, Codex trực tiếp viết tiếp.

## Chưa hoàn thành

Chưa nối khối nạp cấu hình với chuẩn bị và điều kiện vào lệnh trong EA chính.
Chu kỳ/cờ chỉ báo, các ô phụ, tên mã, comment và phần vốn cần được nạp đúng
ở nơi gọi. Menu, hiển thị, vòng đời và phép chạy cặp toàn EA vẫn phải kiểm.
Không dùng các số ca trên làm tỷ lệ hoàn thành của bot.
