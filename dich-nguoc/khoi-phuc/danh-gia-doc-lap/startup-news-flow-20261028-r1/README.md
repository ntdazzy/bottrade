# Nối phần tin đến cuối khởi động bot 1

`Bot1StartupNewsFlow.mqh` chạy từ phần hỏi lịch tin sau cổng kiểm
quyền, qua vốn/lịch dự phòng/ngữ cảnh/chuẩn bị đến cuối khởi động.
Mã gốc chạy liên tục `0xd60..0x5658`, giữ bộ nhớ và ngăn xếp ở mọi
chỗ nối. Đây chưa gồm cổng kiểm quyền hoặc toàn bộ EA.

## Kết quả

- `b1-startup-news-flow-20261028-r2`: **239/239 ca khớp**, 248 giá trị,
  1.800 ô bảng, 900 ô lịch, 17.346 lời gọi và 13.318 phép số học CPU.
- Ba cổng bật/tắt tin, thời điểm trả về, số phút sau tin, chọn mốc
  và nhãn tin, định dạng thông báo, tràn số phút và cờ khác 0/1.
- Giữ trạng thái khi các lời gọi tin thay đổi cờ, mốc tin, vốn nhập
  tay, cách chọn vốn, cờ đặt lại vốn và mã nhận diện gốc.
- Các tình huống phần vốn của lượt trước chạy tiếp trong luồng mới.
- Bản kiểm `b1-startup-news-flow-check-20261028-r2` và bộ ghép 107
  tệp `b1-all-headers-api-20261028-r30` biên dịch 0 lỗi/cảnh báo.
- Codex kiểm độc lập không phát hiện lỗi trọng yếu trong phần nối.

## Sai khác đã xử lý

Bản r1 truyền vốn nhập tay bằng giá trị, nên chép nó trước khi chạy
phần tin. Ca 235 đổi vốn nhập tay thành 7777 trong lời gọi thông báo;
gốc đọc 7777 sau phần tin, nguồn cũ vẫn dùng 10000 từ số dư. Bằng
chứng được giữ tại `b1-startup-news-flow-20261028-r1/first-failure.json`.

Nguồn nay nhận ba cài đặt vốn bằng tham chiếu, rồi đọc khi gọi phần
tài khoản sau khi khởi tạo tin. Hai ca bổ sung đổi cách chọn vốn và
cờ đặt lại cũng khớp, không còn lỗi chép giá trị sớm.

## Giới hạn

Ba thân hàm lấy lịch được thay bằng lời đáp cấp sẵn; bộ chọn tin
`0x7310`, ghép chuỗi, phần vốn, lịch dự phòng, ngữ cảnh và chuẩn bị
gốc chạy thật. Chuỗi ngày được đo bằng phép đổi của MQL5 rồi cấp ở
ranh giới dịch vụ gốc; kiểm đúng đầu vào và thông báo đầy đủ.

Hai hàm tìm mức và ba hàm bảng cũng dùng bộ ghi. Tài khoản/lưu trữ
và dữ liệu MT5 được cấp; không giao dịch hay ghi biến MT5 thật. Còn
cổng quyền dùng, thân lấy lịch trong phép kiểm nối, mọi lỗi/cấp
phát, cài đặt ban đầu, sự kiện và chạy cặp toàn EA.

Bộ ghép 107 tệp dùng nguồn tại máy; ba tệp vốn cũ chỉ khác ký tự
xuống dòng so với Git được giữ nguyên. Phép công bố kiểm từng byte
phần mới và các tệp mà chương trình kiểm sử dụng.

## Chạy lại

`cong-cu/kiem-noi-tin-khoi-dong-bot-1.py`: `generate`, `prepare RUN`,
`mql5 RUN --build BUILD`, `original RUN`, `compare RUN`.
Dùng tên lượt mới và MT5 thử riêng; không ghi đè bằng chứng cũ.

[Kết quả tổng hợp](verification.json), [danh sách tệp](manifest.txt).
