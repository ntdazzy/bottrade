# Nối bước chuẩn bị đầu với phần cuối khởi động bot 1

`Bot1StartupPreparationFlow.mqh` gọi `Bot1PrepareStrategy(0,...)`,
rồi chạy phần sau trên cùng trạng thái. Mã gốc gọi tại `0x3c9d..0x3ca9`;
thân chuẩn bị `0x7500..0x831d` có SHA-256
`8679070031fe7f3309378147c8afc4bf2d4ab596b3ee22a73e8e6386db6c9d0d`.
Bộ kiểm chạy liên tục từ nơi gọi đến lệnh trả về `0x5658`, không đặt
lại trạng thái sau chuẩn bị.

## Kết quả và giới hạn

- `b1-startup-prep-flow-20261028-r2`: **161/161 ca khớp**, 224 giá trị,
  1.800 ô bảng, 8.988 lời gọi, 8.287 phép số học CPU thật. So cả
  dữ liệu chỉ báo, chiều đọc mảng, toàn bộ giá/lịch và ba bình luận.
- Cả 161 ca đều tạo chỉ báo đúng một lần rồi đi qua phần giao dịch
  và phần cuối. Trong đó có 2.479 lời gọi thuộc thân chuẩn bị.
- Hai ca tạo chỉ báo thất bại và một ca sao chép dữ liệu trả 0 vẫn
  chạy tiếp, giữ đầu ra chưa bị ghi, giống nơi gọi gốc.
- `b1-startup-prep-errors-20261028-r1`: **3/3 ca dừng lỗi khớp**:
  mảng 0 phần tử, mảng 1 phần tử, đơn vị giá bằng 0. So 2/2/14 lời
  gọi trước lỗi; cả hai bản không chạy đến phần cuối và không ghi
  kết quả bình thường. Chưa so toàn trạng thái tại đúng lệnh lỗi.
- Nguồn kiểm `b1-startup-prep-flow-check-20261028-r2` và bộ ghép
  104 tệp `b1-all-headers-api-20261028-r27` biên dịch 0 lỗi/cảnh báo.

Ba đầu vào `0x6a748/0x6a750/0x6a768` cũng là chế độ/rủi ro/bước vốn
của bảng. Bộ kiểm nạp cùng giá trị cho hai giao diện trước khi chạy;
không thay đổi ba cài đặt này trong lúc gọi dịch vụ. Trạng thái đầu ra
`0x62540/0x62548/0x62550` vẫn là các vùng riêng. Bình luận chuẩn bị
`0x622d0` được chép tới `0x62480`; bình luận giao dịch ở `0x62470`.

Hai hàm tìm mức và ba hàm bảng vẫn được thay thân bằng bộ ghi. Phản
hồi MT5, cấp phát chuỗi thành công và trạng thái trước lần chuẩn bị
được cấp. Chưa gồm khởi tạo trước `0x3c9d`, toàn bộ lỗi/cấp phát,
cài đặt và sự kiện EA. Đây chưa phải bot hoàn chỉnh hoặc chạy cặp EA.

Giữ r1 và bản biên dịch có cảnh báo để tra; r2 là lượt hiện hành.
Bốn tệp vốn cũ vẫn có ký tự xuống dòng khác Git; bộ ghép 104 tệp
kiểm bản tại máy. Phép công bố riêng kiểm từng byte phần mới và mọi
tệp nguồn mà chương trình kiểm sử dụng.

## Chạy lại

`cong-cu/kiem-noi-chuan-bi-khoi-dong-bot-1.py` dùng các bước
`generate`, `prepare RUN`, `mql5 RUN --build BUILD`, `original RUN`,
`compare RUN`; thêm `errors RUN --build BUILD` cho ba ca dừng lỗi.
Dùng MT5 riêng và tên lượt mới; không ghi đè bằng chứng cũ.

[Kết quả tổng hợp](verification.json), [danh sách tệp](manifest.txt).
