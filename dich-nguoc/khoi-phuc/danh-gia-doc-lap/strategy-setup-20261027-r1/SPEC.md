# Nối nạp cấu hình → ngữ cảnh → chuẩn bị

Phân tích trước khi ghép. Dùng đúng hai EX5 đã chốt trong bảng theo dõi;
không sửa bản gốc. Các khối có nguồn và bằng chứng riêng tại
`profile-preparation-20261027-r1` và `strategy-context-20261027-r1` của
mỗi bot. Phép so mới phải chạy cả ba thân gốc liên tục trong cùng bộ
nhớ, qua lời gọi chuẩn bị thật của hàm điều phối; chưa chạy đánh giá
chiến lược hoặc toàn bộ EA.

## Giao diện và thứ tự

`BotNSetupStrategy` nhận chỉ số hợp lệ, các điều chỉnh, đầu vào chuẩn bị,
đầu vào ngữ cảnh, trạng thái hạt giống/cấu hình, trạng thái ngữ cảnh và
trạng thái chuẩn bị. Bot 1 có thêm cờ HL. Dùng nguyên các kiểu hiện có,
không tự khởi tạo lại trạng thái hoặc thêm nhánh cho phép/bỏ giao dịch.

1. Nạp cấu hình đầy đủ bằng `BotNLoadRuntimeProfile` vào đầu vào chuẩn
   bị; giữ cập nhật hạt giống 32 bit và các trường phụ như bản gốc.
2. Gọi `BotNLoadStrategyContext`, giữ các lần đọc tiền tài khoản và giá,
   cập nhật ghi chú/mã/số tiền. Bot 3 truyền đúng `inputs.reference` bằng
   tham chiếu; khi bật `native_1d6f28`, hàm sửa ô này rồi đổi tiền lần hai.
3. Gọi `BotNPrepareStrategy` bằng cùng đầu vào, chỉ số và trạng thái đã
   truyền. Chưa gọi thân đánh giá chiến lược trong phạm vi lần ghép này.

Bot 3 có thêm một bước nối dữ liệu trước ba lời gọi: `native_1d6f28`
của đầu vào ngữ cảnh và `variable_distances` của đầu vào chuẩn bị đều
đại diện cùng byte `1d6f28`. Hàm ghép sao cờ từ ngữ cảnh sang trường
chuẩn bị trước khi nạp cấu hình; không để hai bản sao khác nhau. Mã
gốc tại `e23f..e252` đọc lại đúng byte đã đọc trong đoạn ngữ cảnh.
Phép ghép r2 phát hiện đủ 1.170 ca cờ=0 bị lệch, trong khi 936 ca
cờ=255 khớp vì cả hai trường khi đó cùng bật. Giữ bản nguồn trước sửa
và số liệu ở `failed-r2/`; không dùng lượt r2 bot 3 làm bằng chứng đạt.

Các phép tính, làm tròn và xử lý lỗi vẫn nằm trong ba khối đã chốt;
hàm ghép chỉ gọi đúng thứ tự. Ghi chú lệnh `62470`/`6d568` phải tách khỏi
chuỗi chuẩn bị `62480`/`6d578`, được sao từ `622d0`/`6d308`. Không gán
ghi chú lệnh vào `inputs.comment`. Không lưu lại tên tiền tài khoản để
bỏ các lần đọc của bản gốc.

## Điểm đầu và cuối của phép chạy gốc

Dùng cùng các điểm đầu khối cấu hình và các lần nạp hằng số đã kiểm
trong `check-profile-preparation.py`. Các giá trị thanh ghi chung của
đoạn được cấp bằng cách chạy đúng lệnh nạp hằng gốc trước điểm đầu:

- Bot 1: `123fd` (RBP=5c0), `12438` (RBX=47d20), `12442` (R12=69f70),
  `1244c` (R13=7500), `12456` (R15=18aa0).
- Bot 3: `1a7d7` (R12=5c0).

Giữ nguyên lệnh so và cờ của khối cấu hình khi chạy tiếp sang ngữ cảnh;
không nạp lại thanh ghi hoặc tự đặt cờ ở ranh giới hai khối. Khung ngăn
xếp đầu đoạn được cấp, thẳng hàng 16 byte trước lời gọi con. Câu trả lời
MT5 và cấp chuỗi thành công được cấp như các phép kiểm trước.

Ở đầu `7500`/`e0c0`, kiểm chỉ số RCX và địa chỉ quay về trên ngăn xếp
đúng lời gọi của từng chiến lược. Để thân chuẩn bị chạy và quay về tự
nhiên; dừng ngay sau lời gọi, trước phần đánh giá. Kiểm mỗi ca chỉ gọi
chuẩn bị một lần. Không gọi chuẩn bị lần thứ hai từ bộ kiểm.

So trạng thái đã nạp, toàn bộ trạng thái chuẩn bị đã kiểm trước, đối
số chỉ báo, ghi chú lệnh UTF-16 đầy đủ, mã/số tiền/Reference, số lần và
thứ tự đọc tiền/giá cùng thứ tự gọi dịch vụ xuyên cả luồng. Các đầu vào
điều chỉnh giữ bộ 432/2.106 ca trước, bổ sung ngữ cảnh có byte 0/1/255,
mã gốc âm/0/tràn và nhiều loại tiền; phải kiểm đủ các lựa chọn ở mỗi
chỉ số. Chỉ được ghi đạt sau khi nguồn biên dịch và kết quả khớp.

Giới hạn: các thanh ghi đi vào đầu đoạn vẫn được cấp theo hợp đồng
kiểm từng phần; chưa chứng minh mọi đường từ đầu hàm điều phối, khởi
tạo mã giá, lựa chọn chiến lược, nhánh lỗi của toàn chuỗi hoặc toàn EA.
Bot 3 tiếp tục dùng đối chứng CPU đã đo cho phép tính có hai NaN như
phép kiểm cấu hình trước; không gọi đó là chạy toàn bản gốc trên CPU.
