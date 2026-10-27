# Luồng từ đầu đánh giá tới hết tạo lệnh

Đã nối liên tục: giờ/phiên → giá → dọn lệnh chờ riêng bot3 → bổ sung
dừng/chốt → quản lý vị thế → bảng thông tin → vốn/khối lượng/chỉnh lệnh
chờ → điều kiện dừng → lọc tin → mức giá và tạo lệnh.

| Phép so | Bot1 | Bot3 |
|---|---:|---:|
| Toàn đoạn ghép, kể cả nhánh thật/ảo và sát ngưỡng đóng mua | 61/61 ca | 57/57 ca |
| Lời gọi MT5 trong đoạn ghép | 5.844 | 5.339 |
| Kiểm lại quản lý với 18 nhóm giá trị ngoài | 352/352 ca | 364/364 ca |
| Kiểm lại giao diện điều phối cũ, kết quả hai hàm quản lý được cấp | 1.536/1.536 ca | 384/384 ca |

Lượt ghép thân chính là `bN-evaluation-20261027-r7`; phần nối thống kê/hiển thị cuối được kiểm riêng ở `bN-evaluation-display-20261028-r1`.
Hai nguồn gọi dịch vụ thật là `bN-evaluation-api-20261027-r2`.
Lượt quản lý riêng `bN-manager-fields-20261027-r4`, điều phối tương thích
`bN-router-compat-20261027-r1`. Các bản biên dịch bàn giao đều0lỗi/0cảnh báo.

Bản gốc chạy từ `18aa0`/`20ef0` tới trước `1e94f`/`29c88`, các thân con
quản lý, bảng dừng, sửa/đóng/gửi chạy nguyên. Không đặt lại dữ liệu giữa
các bước. Đã đo lần gọi thật ở từng nhánh, không lấy tên ca kiểm làm bằng
chứng: bot1 gọi quản lý mua/bán56/56lần, sửa40/đóng9/gửi107/dọn bảng9;
bot3 tương ứng56/56,sửa36/đóng11/gửi93/dọn bảng8.

Giữ hai chỉ số khác nhau: chỉ số chụp từ nơi gọi để chọn thời gian nến,
và chỉ số hiện hành để đọc/ghi mức giá, khối lượng. Cờ phiên/cờ caller
bot3 giữ đúng tác dụng. Kiểm quyền dùng bot1 giữ nguyên, không đặt hợp lệ
hoặc bỏ nhánh. Prelude và manager nhận cùng `execution.tick`, bảng mức
dùng `queue.results`, đếm lỗi/vé/khối lượng/thiết lập dùng cùng tham chiếu.

Rà độc lập bắt lỗi nhánh mua còn đọc `settings.emergency_offset`; đã sửa
để đọc giá trị chung `spread`. Bốn ca giá sát ngưỡng được thêm. Chạy lại
EX5 bộ kiểm cũ với ca `bid=-20.5, ask=-19.5` xác nhận cả hai bản cũ lệch
thứ tự gọi với native; bản mới khớp. `negative-old-binary.json` giữ mã
kiểm tra bản cũ/dữ liệu và điểm lệch; không dùng chính mã mới làm đáp án.

## Giới hạn

Đây vẫn là **kiểm đoạn chương trình**. Phần thống kê/hiển thị cuối hàm đã
được nối và đối chiếu riêng; khởi tạo/thoát, bộ điều phối chiến lược bên
ngoài, menu/tài nguyên và chạy cặp EA hoàn chỉnh vẫn còn. Vì vậy chưa xác
nhận toàn evaluator hoặc bot hoàn thành. Không sửa EX5 gốc hay MT5 chính.

Luồng ghép dùng dữ liệu MT5 được cấp, chế độ khối lượng0, rút tiền tắt,
ghi thông báo gửi0 và các danh sách vị thế/lệnh đơn giản. Có kiểm lỗi
lấy giá, phiên đóng, báo phiên, vị thế trống/khác hướng, chế độ quản lý
thật/ảo, bảng mở/tắt và ba tin chặn. Phần tính khối lượng năm chế độ đã
có phép so riêng trước đó, chưa gọi là đã phủ cả năm trong lượt ghép này.
ArrayResize chạy thật trong MQL5; trạng thái mảng sau cấp phát được đo
rồi cấp cho native. Cấp phát chuỗi thành công, không phủ mọi lỗi bộ nhớ.
Byte ngữ cảnh ban đầu của bot1 được cấp rõ, còn phải nối từ nơi gọi EA.

## Chạy lại

Chọn RUN/BUILD mới; không ghi đè lượt cũ.

1. `python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/tao-bo-kiem-danh-gia-lien-tuc.py`
2. Biên dịch `BotNEvaluationCheck.mq5` trong MT5 riêng bằng
   `cong-cu/bien-dich.ps1`, bật `-CheckFloatingPointDividers`.
3. `kiem-danh-gia-lien-tuc-bot-1-3.py prepare N RUN`
4. `kiem-danh-gia-lien-tuc-bot-1-3.py mql5 N RUN --build BUILD`
5. `kiem-danh-gia-lien-tuc-bot-1-3.py original N RUN`
6. `kiem-danh-gia-lien-tuc-bot-1-3.py compare N RUN`

Nếu vừa biên dịch bộ kiểm khác, chỉ phục hồi đúng EX5 kiểm đã lưu, kiểm
SHA-256 theo biên nhận rồi chạy; công cụ từ chối khi nguồn/EX5 thay đổi.
Các tệp trong `attempt-*` là ghi chú/mã trung gian giữ trong lúc sửa bộ
kiểm, không thay cho mã kiểm tra và kết quả của từng lượt trong biên nhận.
