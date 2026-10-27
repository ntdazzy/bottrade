# Tìm lịch tin NFP từ lịch kinh tế MT5

| Phần | Bot 1 | Bot 3 |
|---|---|---|
| Hàm gốc | `61b0..65f3` | `6ad0..6f13` |
| Nơi ghi mã lỗi | `6a410` | `1d6e10` |
| Nơi nhận kết quả trong evaluator | `6a360` | `1d6c70` |
| Điểm người gọi | `1b4fe` | `237ce` |

Hai hàm cùng cách xử lý. Bản liệt kê và SHA được lưu trong
native-evidence.json. Đã đối chiếu chữ ký dịch vụ và cấu trúc với
[tài liệu CalendarEventByCurrency](https://www.mql5.com/en/docs/calendar/calendareventbycurrency),
[CalendarValueHistoryByEvent](https://www.mql5.com/en/docs/calendar/calendarvaluehistorybyevent)
và [cấu trúc lịch](https://www.mql5.com/en/docs/constants/structures/mqlcalendar).

1. TimeTradeServer được gọi một lần. Sau đó gọi CalendarEventByCurrency
   với chuỗiUSD và mảng MqlCalendarEvent. Kết quả<=0 thì trả0, không
   tra lịch sử. Mảng là dữ liệu dịch vụ, không tự tạo ngày tin theo lịch thứ Sáu.
2. Khi có sự kiện, đầu khoảng=giờ máy chủ-86400, cuối=giờ máy chủ+5961600
   (69ngày), giữ kiểu64bit và cách tràn của bản gốc.
3. Duyệt đúng số lượng dịch vụ trả. Tìm chuỗi phân biệt hoa/thường
   `Nonfarm Payrolls` ở bất kỳ vị trí trong tên. Dừng ở kết quả khớp
   đầu tiên theo chỉ số logic. Mã sự kiện lấy từ ôid64bit.
4. Nếu không thấy tên hoặc mã tìm được bằng0, vẫn dùng mã dự phòng
   `840030016` (`0x3211d740`) để tra lịch sử; không trả0 sớm.
5. Gọi CalendarValueHistoryByEvent với mã đã chọn, mảng giá trị và
   đúng hai đầu khoảng. Nếu trả<=0 thì kết quả0. Nếu có, duyệt đúng
   số lượng trả; chỉ xét time>đầu khoảng và chọn số nhỏ nhất. Không
   tự kiểm lại time<=cuối khoảng: bản gốc giao việc lọc khoảng cho dịch vụ.
6. StringFind là hàm MQL5 thật, nên tênNULL/rỗng giữ tác dụng phụ lên
   GetLastError. Không xóa lỗi ở đầu/cuối hàm. Giá trị lỗi cuối là
   một phần bắt buộc của phép so; không chỉ so thời điểm tìm được.
7. MQL5 truy cập events[i]/values[i] tự áp dụng cờ đọc ngược (AS_SERIES).
   Không tự đảo thêm. Bộ kiểm cấp cả4tổ hợp cờ xuôi/ngược cho hai mảng,
   gồm số lượng trả nhỏ hơn kích thước mảng. Đã đo trực tiếp
   ArraySetAsSeries trên hai kiểu cấu trúc này: đều hỗ trợ, chỉ số0
   đọc phần tử vật lý cuối khi bật. Probe lưu riêng để nêu đúng bằng chứng.
8. Dịch vụ báo số lượng lớn hơn mảng thì phép truy cập phải dừng lỗi
   `array out of range`; không chặn rồi trả0 thay lỗi. Mọi nguồn được
   biên dịch0lỗi/0cảnh báo.

## Cách kiểm và giới hạn

Mã máy nguyên của helper, thao tác chuỗi, vòng chọn và giải phóng
mảng đều được chạy. Chỉ cấp thời gian, các trả lời lịch, cấp phát/giải
phóng thành công. Bộ kiểm so từng byte thời điểm trả, GetLastError
và thứ tự/đối số/kết quả dịch vụ. Ca mảng thiếu chạy riêng, so nhật ký
mới, mã ca, dừng thật và toàn chuỗi dịch vụ trước lỗi.

Hai mã kiểu mảng16bit nằm ngoài vùng chụp của mỗi bot. Mã máy chỉ sao
chép chúng vào mô tả mảng chuyển cho SDK, không dùng để chọn thuật toán.
Bộ kiểm cấp các giá trị thay đổi theo mã ca ở đúng ranh giới dữ liệu
SDK; giữ stride128, cờseries, số lượng và dữ liệu tên/id/time. Đây
chưa chứng minh toàn bộ quản lý kiểu/bộ nhớ nội bộ của nền tảng.

Trả lời lịch được cấp: chưa chứng minh lịch trực tuyến, lỗi cấp phát
thực, nhánh gọi cập nhật lịch trong evaluator hay hủy/đóng lệnh theo
tin. Chưa cóEAchính hoặc phép chạy haiEAhoàn chỉnh song song.
