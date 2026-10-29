# Phần tính số học khối lượng — bot 2

Lượt `b2-volume-arithmetic-20261029-r12`: **768/768 ca khớp**,
gồm 731 ca trả kết quả thường và 37 ca mã gốc dừng do chia cho 0.
Hàm số học MQL5 trả `false` ở 37 ca đó; đây là quy ước của phần
tính toán, không phải bằng chứng MQL5 đã phát sinh lỗi dừng như EA.

Mã gốc `0x35810..0x371f0`, nền `0x253f2620000`, SHA-256:
`9638c651c1c79db6dd85d00e356f004473ff844081991567ba380e5c7167ed78`.

## Các điểm đã chốt trực tiếp từ lệnh máy

- Chế độ 3 chạy nhánh 1..998 rồi đọc lại chế độ và tính nhánh riêng.
- Chế độ 999 dùng mẫu số `0.1 × khoảng dừng`; tại `0x35d51`,
  nhánh `JBE` chuyển sang 9999 cả khi giá trị tick không xác định.
- Kiểm mẫu số bằng 0 dùng cả `JNE/JNP`: số không xác định không
  bị tự đổi thành lỗi chia cho 0.
- Giới hạn cài đặt dùng `MINSD` tại `0x367a4`; không có bước ép
  lên `start_lots` như bản Bot1 được dùng để tham khảo.
- Sau cảnh báo vượt mức lớn nhất của mã giá, `0x36dc2` đọc lại
  mức này vào giá trị cuối. Ca 11 chứng minh `0.1 → 0.01`.
- Nhánh 9999 giữ thứ tự nhân: `(0.01 × hệ số) × ((số dư / bước số dư) × 0.01)`.

So đủ 6 trạng thái cùng số cảnh báo, thông báo và lần ghi đỉnh
số dư. Chạy các chỉ số mảng 0/3/7 và kiểm các ô còn lại không đổi.
Có ca bước lạ, số 0 âm, số không xác định và vô cực.

Bộ chạy dùng lại bộ nạp/cấp phát đã kiểm, giữ nguyên mã gốc và
các hàm chuỗi. Chặn mã ngoài phạm vi; kiểm mã băm thân hàm,
ngữ cảnh dịch vụ và tham số số tiền trước đổi. Có 74 lần cấp kết
quả đổi tiền. Tệp `native-errors.json` giữ nguyên mã lỗi gốc;
37 mã đều thuộc lớp `0x1f7`, không gộp các lỗi khác vào chia cho 0.

## Bản dựng và cách lặp lại

`b2-volume-arithmetic-20261029-build-r10` và bộ ghép 4 tệp `.mqh`
`b2-all-headers-api-20261029-r3`: **0 lỗi, 0 cảnh báo**.
R12 kiểm lại nguồn/biên nhận/mã EX5 trước và sau chạy MT5, đồng
thời từ chối khi máy thử đang có tiến trình sử dụng cùng thư mục.

`kiem-tinh-khoi-luong-bot-2.py`: `prepare RUN`, `original RUN`,
`mql5 RUN --build BUILD`, `compare RUN`. Dùng tên lượt mới và máy
thử bot 3 riêng. Hai bước chạy gốc/MQL5 độc lập sau `prepare`.
Kiểm bản Git bằng `kiem-ban-git-khoi-luong-bot-2.py --arithmetic`.

## Phần còn thiếu

Đây là phần số học, chưa phải toàn bộ hàm chạy thực tế. Kết quả
đổi tiền được cấp; cài đặt điều chỉnh sau rút tiền bị tắt. Chỉ so
số lần thông báo, chưa so toàn văn thông báo hoặc việc ghi kho
MT5. Không so trạng thái cuối của ca lỗi và không tạo lỗi dừng
MQL5 trong bài kiểm này. Nguồn ghi rõ chỉ dùng kết quả khi hàm trả
`true`; còn lớp gọi dịch vụ/thông báo và EA đầy đủ phải phục hồi.

Giữ các lượt sai và nguồn trước sửa để đối chiếu; không dùng các
con số 698/768 hoặc 729/768 của bản nháp để xác nhận bản hiện hành.

[Số liệu](verification.json), [danh sách tệp](../volume-arithmetic-bot2-20261029-r1-manifest.txt).
