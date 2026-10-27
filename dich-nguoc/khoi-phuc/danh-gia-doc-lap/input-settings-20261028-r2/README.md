# Đủ đầu vào và kiểm nạp bộ cài đặt trong MT5

Đã bổ sung `lijntje`, giữ đúng thứ tự 72/80 đầu vào. Bảy menu dùng số và
nhãn của `verified-menu.json`; tên kiểu MQL5 mới có tiền tố từng bot vì
tên kiểu gốc chưa biết. MQL5 cho phép dùng chú thích thành viên để hiện
nhãn menu, theo [tài liệu chính thức](https://www.mql5.com/en/docs/basis/variables/inputvariables).

| Bot | Đầu vào | Bộ .set đã nạp | Giá trị thực đo khớp |
|---|---:|---:|---:|
| 1 | 72 | 4 | 288/288 |
| 3 | 80 | 10 | 800/800 |

Bộ ghi đọc chính các biến `input` đã nạp trong MT5 riêng, ghi tên, kiểu,
thứ tự và giá trị. Đối chiếu với bộ mặc định xuất từ EX5 gốc và các tệp
thay lựa chọn đã được đọc trên cửa sổ gốc. Tệp lựa chọn chỉ có các mục
thay đổi; bộ chạy bổ sung mặc định gốc cho mục khác để tránh ảnh hưởng
thiết lập từ lượt trước. Chuỗi giữ cả dấu cách cuối. Mã EX5 được kiểm
trước và sau mỗi bộ cài đặt; header/script/generator và chứng cứ gốc
đều được khóa mã băm.

Lượt đạt: `bN-inputs-loaded-20261028-r6`; bản biên dịch
`bN-inputs-check-20261028-r4`, 0 lỗi/0 cảnh báo. Các lượt chưa đạt được
giữ riêng. Có lỗi bộ kiểm viết lặp ký tự xuống dòng Windows, đã sửa;
không sửa giá trị mặc định để làm phép so đạt.

Đã thử mở `Bot1InputsMenuCheck` để kiểm ảnh. MT5 riêng hiện hộp đăng
nhập nên không thao tác tiếp; tiến trình do lượt này tạo đã đóng. Ảnh
menu mới, tên kiểu gốc, nhãn bị ẩn và tác dụng toàn bộ đầu vào trong EA
vẫn chưa được xác nhận. Biên nhận menu 0/0 chỉ chứng minh biên dịch.

Các tệp `InputNewsMapping*.proposal.txt` là đề xuất chưa được ghép. Cờ
giới hạn tần suất hỏi lịch nằm ở trạng thái nội bộ `6a3a4/1d6cb4`, không
phải `UpdateInfoTesting`. Đề xuất đã được đưa khỏi nguồn hiện hành; còn
phải nối từ khởi tạo/nơi gọi thật trước khi dùng.

Claude Code trả lỗi quyền dùng gói tổ chức, 0 mã thông báo vào/ra; không
có mã hoặc đánh giá từ Claude ở lượt này. Codex thực hiện theo ngoại lệ
đã được người dùng xác nhận; xem `claude-access.json`.
