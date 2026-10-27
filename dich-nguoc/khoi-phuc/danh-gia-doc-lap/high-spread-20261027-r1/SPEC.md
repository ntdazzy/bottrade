# Đặc tả nhánh spread cao

- Bot1: helper native `0x30320..0x31f35`, snapshot SHA-256 `21c60f7b2f2e21bce92f1840b8025e4a1c921074b32834404439021aca11df55`.
- Bot3: thân inline native `0x250a8..0x269ab`.
- Mỗi bot gọi `OrdersTotal()` một lần; kết quả âm thì trả về. Vòng lặp duyệt từ `total` đến `0`, ghi đè ticket kể cả khi ticket bằng `0`, rồi bỏ qua ticket `0`.
- Lọc magic bằng hai lần đọc mới: `ORDER_MAGIC == execution.strategy_magic` hoặc lần đọc mới thứ hai bằng `0`. Mã sản phẩm phải so sánh đầy đủ.
- Hai lần đọc `ORDER_TYPE` là hai nhánh độc lập. Nhánh loại `4` kiểm tra giá buy; sau đó vẫn đọc lại loại để kiểm tra loại `5`.
- Buy: đọc giá lần đầu; lấy quote `reference_b`; ngưỡng là `QueueSum(QueueProduct((double)distance_points,unit),quote)`, phải lớn hơn giá lần đầu. Đọc giá lần hai; `QueueDifference(price2,gap)` phải lớn hơn quote.
- Sell: đọc giá lần đầu; lấy bid `reference_a`; ngưỡng là `QueueDifference(bid,QueueProduct((double)distance_points,unit))`, giá lần đầu phải lớn hơn ngưỡng. Đọc giá lần hai; bid phải lớn hơn `QueueSum(price2,gap)`.
- Khi đạt điều kiện: giữ thứ tự phép tính số thực của các hàm Queue; lấy `minimum` trước khi đổi spread thành chuỗi; in một dòng với tiền tố `Spread too high..(` và hậu tố tương ứng; nếu lưu thì ghi bảng `orders[100][3]`, xóa kết quả đầu tiên trùng ticket, rồi gọi xóa lệnh thật.
- Nhánh xử lý công khai chỉ chạy khi spread `reference_b-reference_a` lớn hơn `maximum*unit`; trả `false` trước các nhánh khác.

## Bằng chứng chạy và giới hạn

Nguồn `BotNHighSpread.mqh` và `BotNNewsFridaySpreadFlow.mqh` đã ghép
liên tục từ NFP, lãi suất, CPI qua đóng cuối tuần tới xử lý chênh lệch cao.
Lượt `b1/b3-high-spread-20261027-r1`: **640/640 ca mỗi bot**;
so **18.434/18.809 lần gọi dịch vụ** và toàn bộ 500 ô số của hai bảng.
Nguồn gọi MT5 trực tiếp và bộ kiểm đều 0 lỗi/0 cảnh báo.

Các ca gồm bảng đầy/trống/ô cuối/NaN/vé trùng, phép so giá sát ngưỡng,
phút/điểm âm và tràn, vé lớn/64 bit có dấu, hai lần đọc mã và hai nhánh
mua/bán độc lập. Dịch vụ có thể đổi giá tham chiếu giữa hai lần đọc,
đổi cờ lưu ở thông báo, đổi vé, sửa bảng kết quả hoặc đổi mã/symbol
ngay trong dịch vụ; bộ so yêu cầu khớp trạng thái trước mỗi lần gọi
và kết quả cuối. Thân hủy/gửi gốc tự chạy; không cấp kết quả hàm con.

Đổi số thành chuỗi được đo riêng trong MT5 cùng lượt, kiểm đúng loại
và giá trị đầu vào khi mã gốc yêu cầu, rồi so đầy đủ thông báo. Đây là
trả lời của dịch vụ đổi kiểu, không là trả lời thuật toán lưu/hủy.

Chỉ nhánh chênh lệch cao. Nhánh đặt lại lệnh khi chênh lệch thấp,
giới hạn số lệnh và điều kiện vào lệnh phía sau chưa nằm trong nguồn
ghép này. Khung đầu đoạn, dịch vụ, định dạng số và cấp phát thành công
được cấp. Chưa có EA đầy đủ, kiểm trực tuyến hoặc lỗi cấp phát.

Công cụ: `kiem-chenh-gia-cao-bot-1-3.py prepare|mql5|original|compare BOT RUN`,
`mql5` cần `--build BUILD`. `tao-bo-kiem-chenh-gia-cao.py` tạo hai Script.
Nhận xét độc lập `friday_flow_review` không thấy lỗi đáng kể trong
nguồn, số học/thứ tự gọi và vùng mã máy gốc; không thay cho phép so.
