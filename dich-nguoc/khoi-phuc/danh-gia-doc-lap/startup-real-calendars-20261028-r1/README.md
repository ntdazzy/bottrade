# Ba thân hàm lịch thật trong luồng khởi động bot 1

Lượt này dùng nguyên nguồn `Bot1NfpCalendar.mqh` và
`Bot1ReleaseCalendars.mqh` trong luồng `0xd60..0x5658`. Phía gốc
chạy cả ba thân `0x61b0`, `0x6600`, `0x6a90`; móc vào đầu hàm chỉ
ghi nhận loại lịch, không trả kết quả sẵn hoặc nhảy qua thân hàm.
Không cần sửa lại mã bot: các thân đã phục hồi được ghép vào phép
chạy chung để kiểm chúng với phần phía sau.

## Kết quả

- `b1-startup-real-calendars-20261028-r3`: **158/158 ca khớp**,
  248 giá trị, 1.800 ô bảng, 900 ô lịch, 12.853 lời gọi và 8.848
  phép số học CPU. So thứ tự/đối số dịch vụ, chuỗi và mã lỗi.
- Tìm tên tin, mã dự phòng khi mã sự kiện bằng 0, mảng đọc xuôi/
  ngược, số lượng dịch vụ trả khác độ dài mảng, mốc thời gian sát
  biên, lỗi chờ lịch và việc truyền kết quả sang chọn tin/vốn.
- Dữ liệu sự kiện và giá trị lịch do dịch vụ thử cấp. Thuật toán
  chọn sự kiện, lọc thời gian, mã dự phòng và xử lý lỗi chạy thật
  ở cả nguồn MQL5 lẫn bản chụp mã gốc.
- Bản kiểm `b1-startup-real-cal-check-20261028-r3` biên dịch 0 lỗi,
  0 cảnh báo. Các header bot không thay đổi trong lượt này.

## Lỗi bộ kiểm đã sửa

Bộ ghi r2 từng giữ lỗi chờ lịch `5401` sau khi thao tác tìm tên tin
đã sinh lỗi mới `4009`. Ca 152 với tên NULL phát hiện khác biệt tại
dịch vụ lấy giá trị lịch tiếp theo. Giữ
`b1-startup-real-calendars-20261028-r2/first-failure.json` để tra.

Bản ghi hiện hành đo kết quả/lỗi của `StringFind` MQL5 thật, giữ mã
lỗi cũ chỉ khi không có lỗi mới. Sáu ca 152–157 kiểm tên NULL, rỗng
và không khớp sau lỗi 5401; cả sáu đều khớp mã gốc. Đây là sửa bộ
ghi kiểm thử, không thay thuật toán của bot. Codex kiểm độc lập đã
đọc lại bằng chứng và xác nhận điểm này được xử lý.

## Giới hạn

Chưa gửi yêu cầu lịch qua mạng thật. Phản hồi dữ liệu/mã lỗi/cấp
phát của MT5 được cấp tại ranh giới dịch vụ; thân lịch gốc vẫn chạy.
Các mã kiểu mảng ngoài bản chụp được cấp như phép kiểm lịch riêng
trước đây. Chưa kiểm lỗi mảng quá ngắn trong phép chạy ghép này.

Hai hàm tìm mức và ba hàm bảng còn dùng bộ ghi. Còn cổng quyền dùng,
khởi tạo trạng thái trước cổng, các lỗi/cấp phát khác, toàn bộ sự
kiện/cài đặt và chạy cặp hai EA. Chưa hoàn thành bot hay ba bot.

## Chạy lại

`cong-cu/kiem-noi-lich-that-khoi-dong-bot-1.py`: `generate`,
`prepare RUN`, `mql5 RUN --build BUILD`, `original RUN`, `compare RUN`.
Dùng tên lượt mới và MT5 thử riêng; giữ các lượt cũ.

[Kết quả và mã kiểm](verification.json), [danh sách tệp](manifest.txt).
