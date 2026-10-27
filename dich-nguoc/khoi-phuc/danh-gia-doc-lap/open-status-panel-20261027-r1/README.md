# Kết quả phần cập nhật chữ

- Bot1: `b1-open-panel-20261027-r3`, **297/297 ca**, 6.087 lời gọi dịch vụ.
- Bot3: `b3-open-panel-20261027-r2`, **324/324 ca**, 7.270 lời gọi dịch vụ.
- Hai bộ kiểm và hai nguồn gọi dịch vụ thật đều biên dịch **0 lỗi, 0 cảnh báo**.
- Thân gốc chạy nguyên, gồm chọn tin, sao chép/ghép chữ và phép cộng lãi/lỗ;
  chỉ cấp trả lời MT5 và cấp bộ nhớ thành công. Cách đổi số/ngày thành chữ
  được đo từ MT5 rồi cấp cho bản gốc. So tham số, chữ UTF-16, thứ tự gọi,
  mọi giá trị theo dõi trước mỗi dịch vụ và khi hàm trả về.
- Có cờ bảng/tắt hiển thị khi đo quá khứ, nhóm8/15mã, mã tràn32bit, vị thế
  không đúng nhóm/mã/loại, vé0, lần chọn thất bại, sốNaN/vô cực, thứ tự cộng,
  tin sát thời điểm và dữ liệu thay đổi sau dịch vụ.

Nguồn: `Bot1OpenStatusPanel.mqh`, `Bot3OpenStatusPanel.mqh`.
Xem `SPEC.md` để nối từng dữ liệu với vị trí gốc.
`first-run-findings.json` giữ phát hiện lượt đầu: nhầm NULL/chuỗi rỗng
ở bộ nối kiểm và chụp mã nhóm bot1 trước lời gọi lấy tổng vị thế.
Lượt B1r2 chạy native xong; r3 chỉ chuẩn hóa thụt dòng và kiểm lại đúng
mã tệp bàn giao. Giữ toàn bộ dữ liệu cũ, không coi lượt thiếu báo cáo là đạt.

Đây là **kiểm từng phần**. Chưa tạo toàn bộ đối tượng/màu/vị trí trên biểu đồ,
chưa so ảnh bảng, thống kê lịch sử, khởi động/thoát hoặc toànEA; không đổi
EX5 gốc và không gửi lệnh lên tài khoản thật.

## Chạy lại

Chọn RUN và BUILD mới; không ghi đè bằng chứng cũ.

1. `python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/tao-bo-kiem-bang-thong-tin-mo-bot-1-3.py`
2. Biên dịch `BotNOpenStatusPanelCheck.mq5` bằng `cong-cu/bien-dich.ps1`
   trong MT5 riêng, bật `-CheckFloatingPointDividers`.
3. `kiem-bang-thong-tin-mo-bot-1-3.py prepare N RUN`
4. `kiem-bang-thong-tin-mo-bot-1-3.py mql5 N RUN --build BUILD`
5. `kiem-bang-thong-tin-mo-bot-1-3.py original N RUN`
6. `kiem-bang-thong-tin-mo-bot-1-3.py compare N RUN`
