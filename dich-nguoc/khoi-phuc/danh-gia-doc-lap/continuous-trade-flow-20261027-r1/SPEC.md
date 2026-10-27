# Ghép xử lý tin tới hết vòng tạo lệnh

Nguồn `BotNEvaluationTradeFlow.mqh` nối nguyên các phần đã phục hồi:
NFP/lãi suất/CPI → đóng cuối tuần → lưu/hủy/đặt lại khi chênh lệch
giá thay đổi → giới hạn lệnh → cổng/nến/mức giá → vòng tạo lệnh.

Mã gốc chạy liên tục từ B1 `0x1b44f`, B3 `0x2372b` tới trước helper
thống kê/hiển thị tại `0x1e94f`/`0x29c88`. Các nhánh dừng sớm tại
`0x1a63a`/`0x22875` vẫn được bắt riêng. Không đặt lại trạng thái ở
giữa và không cấp kết quả hàm con. Các đối tượng execution/restore/
queue/volume, chỉ số và mảng khối lượng dùng chung suốt cả luồng.

Chỉ khi quyết định nến mới bằng2mới vào vòng tạo lệnh. Kết quả0là
dừng sớm,1là cùng nến,2là đã qua nhánh nến mới; không đổi thành bool.
`restore` ở giao diện ngoài có thể ghi vì vòng tạo lệnh cập nhật hạn.

`kiem-luong-danh-gia-giao-dich.py prepare|mql5|original|compare BOT RUN`;
`mql5` cần `--build BUILD`. Bộ ghi tạo bởi
`tao-bo-kiem-luong-danh-gia-giao-dich.py`.

R2: **175/175ca bot1**, **267/267ca bot3**, so **19.788/32.649 lần gọi
dịch vụ**; nguyên các thân tin/khối lượng/giờ/giá/vị thế/hủy/mở/ký
quỹ/gửi/lỗi gốc tự chạy. Cả bộ kiểm và nguồn gọi MT5 trực tiếp biên
dịch0lỗi/0cảnh báo. Không chỉ so lợi nhuận hay kết quả gửi cuối.

Mỗi bộ gồm toàn bộ tình huống vòng tạo lệnh riêng cùng cổng dừng,
cùng nến và ba loại tin thực sự chặn. `audit-decisions.py` chạy lại
từng ca kiểm soát, lưu địa chỉ kết thúc và quyết định, yêu cầu đúng
nhánh. Các tệp `decision-audit.json` R2 xác nhận:

- cùng nến tới điểm helper hiển thị, quyết định1;
- cổng vào/cờ tắt/đã đóng cuối tuần/tin nóng tới điểm thoát chung,
  quyết định0;
- các đường nến mới qua mốc vào vòng rồi mới tới điểm hiển thị,
  quyết định2.

Rà độc lập nêu nghi vấn bộ so gán dừng thành cùng nến. Đối chiếu
Parent.visit và địa chỉ kết thúc thực tế bác bỏ lỗi ánh xạ đó: hai
địa chỉ thoát khác nhau. Audit R1 đồng thời tìm được thiếu phủ: ba
ca có tên chặn tin còn dùng lịch dự phòng nên chưa chặn. R2 sửa dữ
liệu sang lịch kinh tế và giờ nằm trong cửa sổ; không sửa luật bot
hoặc bỏ so quyết định. Bản cũ/audit cũ giữ để kiểm lại.

Snapshot ghép so dữ liệu các phần và dữ liệu thực dùng/ghi của vòng.
Ô99của vùng cache cấp giả trùng scalaractive_step0x673e8/0x74428,
nên ghi theo đúng alias. Các chỉ số chiến lược hợp lệ chỉ0..7/0..8.
Không coi padding là biến chiến lược độc lập.

Lượt ghép dùng chế độ khối lượng0và tắt rút tiền. Những chế độ khác
có bộ kiểm riêng nhưng chưa ghép lại trong lượt này. Khung đầu đoạn,
giá/tài khoản/trả lời/lỗi dịch vụ/cấp phát thành công được cung cấp;
chờ chỉ được ghi. Chưa gồm phần đầu evaluator, thống kê/hiển thị,
khởi tạo/các sự kiện EA/lỗi cấp phát/nguồn vốn thật. Chưa có EA đầy
đủ hoặc chạy cặp toàn bot; các tỷ lệ ca không là phần trăm hoàn thành.
