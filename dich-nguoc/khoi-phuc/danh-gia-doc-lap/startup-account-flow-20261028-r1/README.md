# Nối vốn và lịch tin vào khởi động bot 1

`Bot1StartupAccountFlow.mqh` chạy phần tài khoản, nạp lịch dự phòng,
ngữ cảnh, chuẩn bị đầu và phần cuối trên cùng trạng thái. Bản gốc
chạy liên tục `0x126c..0x5658`; không đặt lại tại các chỗ nối.

## Kết quả

- `b1-startup-account-flow-20261028-r2`: **93/93 ca khớp**, 247 giá trị,
  1.800 ô bảng, 900 ô lịch, 5.994 lời gọi và 5.142 phép số học CPU.
- So trước mỗi dịch vụ: trạng thái, chuỗi, mã lỗi, mã kiểm các bảng
  và lịch. Khi kết thúc so từng byte đủ 2.700 ô, kể cả đuôi lịch
  không được ghi lại.
- Kiểm chọn số dư/vốn chủ sở hữu, đặt lại vốn cao nhất, vốn nhập tay,
  dữ liệu lưu thiếu/có sẵn, mã tài khoản rộng, NaN/vô cực, thời gian
  lưu, dữ liệu lịch ban đầu khác nhau và chuẩn bị trả về sớm.
- Hai điều kiện trước đây được cấp cho ngữ cảnh nay do đoạn tài
  khoản thật tạo: `XMM6=+0.0` tại `0x1925`, vùng trả chuỗi số có dữ
  liệu từ các lời gọi chuyển mã tài khoản. Bộ chạy xác nhận chúng
  ngay trước ngữ cảnh, không gán lại ở chỗ nối.
- Nguồn kiểm và bộ ghép 106 tệp biên dịch 0 lỗi, 0 cảnh báo.

## Lỗi phát hiện và sửa

Lượt r1 phát hiện nguồn ghi `highest_balance` tại `0x6a328` trước khi
in thông báo. Gốc in tại `0x16b3`, rồi mới ghi vốn tại `0x16e5`.
Kết quả cuối có thể giống nhau nhưng trạng thái trong lời gọi khác.
Nguồn nay dùng biến tạm để chọn vốn rồi ghi một lần sau thông báo.
Giữ r1 và `first-failure.json` làm bằng chứng bản cũ bị phát hiện.

Đã kiểm lại **616/616 ca vốn cũ** tại
`kiem-khoi-tao-von/b1-account-regression-20261028-r1`. Giá trị vốn,
chuỗi tên lưu, thời gian và thứ tự dịch vụ vẫn khớp kết quả mã gốc
đã lưu. Bộ kiểm cũ không so trạng thái giữa các lời gọi; lượt r2
mới bổ sung bằng chứng đó.

## Giới hạn

Tài khoản, thời gian và nơi lưu trạng thái dùng dữ liệu thử, không
đọc/ghi tài khoản thật. Số nguyên chuyển chuỗi được kiểm đối số;
chuỗi định dạng số thực trong thông báo lấy từ kết quả MQL5 đã chạy,
đồng thời kiểm giá trị đầu vào của phép đổi gốc. Ghép chuỗi gốc vẫn
chạy thật, cả chuỗi thông báo cuối được so.

Hai hàm tìm mức và ba hàm bảng dùng bộ ghi; dữ liệu MT5 và cấp phát
thành công được cấp. Ngăn xếp tạm ban đầu rỗng. Còn đoạn trước
`0x126c`, gồm kiểm quyền và khởi tạo lịch trực tuyến, toàn lỗi/cấp
phát, cài đặt/sự kiện và chạy cặp toàn EA. Chưa hoàn thành bot.

Bộ ghép 106 tệp dùng nguồn tại máy. Ba tệp vốn/rút tiền cũ còn khác
ký tự xuống dòng so với Git; không sửa ngoài phạm vi. Phần mới và
nguồn mà bộ kiểm sử dụng được kiểm Git từng byte riêng.
Chương trình kiểm vốn cũ cũng chỉ khác ký tự xuống dòng so với Git;
lượt 616 ca dùng đúng nguồn và EX5 tại máy đã ghi trong biên nhận.
Không tính bản kiểm cũ này vào phép so Git từng byte của luồng mới.

## Chạy lại

`cong-cu/kiem-noi-von-khoi-dong-bot-1.py`: `generate`, `prepare RUN`,
`mql5 RUN --build BUILD`, `original RUN`, `compare RUN`.

Kiểm lại vốn cũ dùng `kiem-khoi-tao-von-bot-1-3.py` với các bước
`prepare|mql5|compare 1 RUN --build BUILD`. Lượt này đặt
`settings.MT` về `.local/mt5-bot1-thread-20261025` trước khi gọi
`main()`, dùng đúng máy thử và bản biên dịch mới.

[Biên nhận tổng hợp](verification.json), [danh sách tệp](manifest.txt).
