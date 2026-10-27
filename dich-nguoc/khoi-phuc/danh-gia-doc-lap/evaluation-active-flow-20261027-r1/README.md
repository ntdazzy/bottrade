# Kết quả ghép sau quản lý vị thế

| Phần | Bot1 | Bot3 |
|---|---:|---:|
| Luồng bảng → vốn → khối lượng → chỉnh lệnh chờ → điều kiện dừng → tin → tạo lệnh | 296/296 ca | 392/392 ca |
| Lời gọi MT5 trong lượt ghép | 34.310 | 49.511 |
| Chế độ khối lượng thực sự chạy | 0,2,3,999,9999 | 0,2,3,1234,9999 |
| Kiểm lại bảng theo giao diện cũ | 297/297 ca | 324/324 ca |

Lượt ghép cuối: `b1-active-flow-20261027-r3`, `b3-active-flow-20261027-r3`.
Lượt kiểm lại bảng: `b1-open-panel-20261027-r4`, `b3-open-panel-20261027-r4`.
Tám bản biên dịch của bộ kiểm và nguồn gọi dịch vụ thật đều **0 lỗi, 0 cảnh báo**.

Bản gốc chạy liên tục từ `1a620`/`22851` tới trước `1e94f`/`29c88`,
gồm các thân con thật; không đặt lại dữ liệu giữa các phần. Nguồn mới
dùng chung vốn, chế độ, mảng khối lượng, thông tin tin, giao dịch và bảng lệnh.
So mọi trạng thái theo dõi trước dịch vụ, đầy đủ tham số/chữ và trạng thái
cuối hàm. Bộ kiểm xác nhận sáu lần chờ1000ms của phần chỉnh lệnh mỗi bot,
không chỉ đặt tên ca mà chưa tới nhánh.

Phần mới gồm thông báo thị trường đóng, tạm chờ đầu ngày, và hai hàm ghép
`BotNEvaluateActiveFlow`. Bảng nhận cờ/phút tin trực tiếp từ bộ lọc, giữ
đúng thứ tự đọc lại. Bot3 nhận thẳng chế độ/tần suất/ngưỡng sụt vốn đang
dùng trong tính khối lượng; không tạo bản sao riêng cho bảng.

`findings.json` ghi chỗ lệch lượt đầu và cách sửa. `r1-inputs/` giữ nguồn
thử ban đầu, `r2-generator-inputs/` giữ bộ tạo trước khi sửa cảnh báo
ở nguồn kiểm biên dịch riêng. R3 chỉ lặp lại sau thay mã kiểm tra của
bộ tạo; mã chính giống lượt R2 đã khớp. `botN-native-bridge.txt` là các
đoạn lệnh gốc được root đọc lại; `SPEC.md` nối đúng địa chỉ dữ liệu.

**Còn thiếu:** phần trước quản lý vị thế trong luồng ghép, thống kê lịch sử,
khởi tạo/thoát, menu/tài nguyên và kiểm toànEA. Lượt này tắt xử lý rút tiền;
dữ liệu/trả lời MT5, lỗi dịch vụ và cấp phát thành công được cấp. Chưa so
ảnh biểu đồ, chưa chạy cặp EA hoàn chỉnh. Hai EX5 gốc giữ nguyên, không có
lệnh giao dịch lên tài khoản thật.

## Lặp lại

Chọn tên RUN/BUILD mới, không ghi đè bằng chứng cũ.

1. `python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/tao-bo-kiem-luong-sau-quan-ly.py`
2. Biên dịch `BotNEvaluationActiveFlowCheck.mq5` trong MT5 riêng bằng
   `cong-cu/bien-dich.ps1`, bật `-CheckFloatingPointDividers`.
3. `kiem-luong-sau-quan-ly-bot-1-3.py prepare N RUN`
4. `kiem-luong-sau-quan-ly-bot-1-3.py mql5 N RUN --build BUILD`
5. `kiem-luong-sau-quan-ly-bot-1-3.py original N RUN`
6. `kiem-luong-sau-quan-ly-bot-1-3.py compare N RUN`
