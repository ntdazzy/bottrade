# Tin và đóng cuối tuần trong cùng luồng

Đầu đoạn là phần NFP đã kiểm; đi liên tục qua lãi suất, CPI, chọn lịch
rồi tới Friday. Bot1 dừng trước `0x1c79a`, bot3 trước `0x25040`;
nhánh thoát sớm cùng điểm thoát đánh giá của bản gốc. Địa chỉ và
mã kiểm tra trong `native-bindings.json`. EX5 gốc giữ nguyên.

## Quy tắc đã chốt

- Chỉ đọc nhánh cuối tuần khi phần tin không yêu cầu thoát.
- Cờ bật phải đúng 1. Ngày khác thứ Sáu thì xóa cờ đã đóng; khi cờ
  bật khác 1 không xóa. Thứ Sáu, giờ chưa tới hoặc cờ đã đóng khác 0
  thì đi tiếp; chỉ lần đầu đủ giờ mới chạy đóng/hủy và thoát ngay.
- Bot1 đặt cờ đã đóng sau cả hàm con và thông báo. Bot3 đặt trước
  hàm con. Không gom hai thứ tự này thành một.
- Bot1 luôn đóng vị thế mua rồi bán, sau đó duyệt lệnh chờ.
  Bot3 có hai cờ riêng: cờ đóng khác 0 mới đóng hai chiều; sau khi
  đóng mới đọc cờ hủy, khác 0 mới duyệt lệnh chờ.
- Tổng lệnh được đọc một lần. Nếu âm thì thoát; lấy mã nền sau lời
  gọi tổng, tính trước 8/15 mã nền+1..8/15 bằng số nguyên 32 bit có dấu.
- Duyệt từ tổng xuống 0, lưu cả vé 0 rồi bỏ qua; đọc lại mã nhận diện
  cho từng phép so. So toàn bộ chuỗi mã sản phẩm; loại lệnh lần đầu
  bằng 4 hoặc lần đọc thứ hai bằng 5 thì in thông báo và hủy. Vé đưa
  vào thân hủy phải là vé hiện tại sau thông báo; không xóa bảng kết quả.
- Chuỗi gốc: `deleting pending order`, `Weekend starting! closing trades..`.
  Đọc trực tiếp qua con trỏ chuỗi của bản chụp, không suy tên từ bảng chuỗi.

Nguồn: `BotNFridayClose.mqh`, `BotNNewsFridayFlow.mqh`. Các hàm đóng,
hủy, chọn cách khớp và gửi đã có nguồn riêng; gọi trực tiếp những thân đó.
Kết quả trả của phần ghép là yêu cầu thoát ngay, chưa thay nhánh kiểm
cờ đã đóng diễn ra ở phần đánh giá phía sau.

## Đối chiếu

`kiem-tin-va-cuoi-tuan-bot-1-3.py prepare|mql5|original|compare BOT RUN`;
`mql5` cần `--build BUILD`. `tao-bo-kiem-tin-va-cuoi-tuan.py` tạo bộ
kiểm từ bộ ghi dịch vụ phần tin; không thay thuật toán nguồn.

Lượt `b1-news-friday-20261027-r3` / `b3-news-friday-20261027-r2`: **406/406 ca mỗi bot**.
Bot1 so **15.361** lời gọi; bot3 **15.736**. So trạng thái trước từng
lần gọi, đối số, chuỗi, mã lỗi và kết quả cuối. Gồm cờ 0/1/2/255,
ngày/giờ sát ngưỡng, cờ hành động riêng bot3, đủ 8/15 mã chấp nhận,
tràn số, mã 64 bit bị loại, chuỗi khác hoa/thường, hai lần đọc loại lệnh,
tổng âm/0, gửi đồng bộ/bất đồng bộ và lỗi. Có thay mã nền sau đọc tổng,
đổi mã giữa vòng so, đổi vé sau thông báo, đổi cờ hủy sau khi đóng và
đổi cờ đã đóng ở thông báo để bắt sai thứ tự ghi của hai bot.

Nguồn gọi MT5 trực tiếp và bộ kiểm đều biên dịch 0 lỗi/0 cảnh báo.
Nhận xét độc lập `friday_flow_review`: không thấy lỗi đáng kể khi so
mã nguồn/bộ kiểm với đúng bản chụp gốc và bằng chứng r2.

## Giới hạn

Chỉ phần tin và hành động cuối tuần đầu tiên. Chưa ghép chênh lệch giá,
giới hạn lệnh và các điều kiện vào lệnh phía sau. Khung đầu đoạn,
lịch và dịch vụ được cấp; chưa chứng minh mạng lịch trực tuyến,
lỗi cấp phát hoặc toàn khởi tạo. Chưa có EA đầy đủ và chưa chạy cặp
toàn bot. Số ca đạt không phải tỷ lệ hoàn thành toàn bot.

Bot1 r3 chỉ bỏ khoảng trắng cuối dòng so với r2; chạy lại đủ 406 ca,
cùng kết quả. Bản r2 đã kiểm giữ trong `r2-tested-sources/`.
