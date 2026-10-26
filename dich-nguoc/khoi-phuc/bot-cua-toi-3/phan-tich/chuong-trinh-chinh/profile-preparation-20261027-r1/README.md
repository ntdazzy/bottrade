# Bot 3 — phép so nạp cấu hình nối với chuẩn bị dữ liệu

Nguồn hiện hành `Bot3LoadRuntimeProfile` và `Bot3PrepareStrategy` được gọi
nối tiếp bằng cùng `Bot3PreparationInputs`. Bộ kiểm mới xuất dữ liệu thật
từ hai hàm, không có giá trị kết quả điền sẵn.

`b3-profile-preparation-20261027-r1`: **2.106/2.106 ca khớp** 124 giá trị
theo từng bit, gồm dữ liệu nạp, trạng thái chuẩn bị, giá/thời gian, thứ tự
dịch vụ và đối số ATR. Hai thân native chạy trong cùng bộ nhớ. Kết quả hai
phía cùng SHA-256:
`c9db2f15e64ab604f9df5650a4705f18a53542b0d5ae286fcad1a19e49244b5a`.
Script kiểm và Script API biên dịch **0 lỗi, 0 cảnh báo**.

Ô `native_6d2e4` được giữ riêng; `management_timeframe` nhận giá trị từ
`0x6d324`. Phép so nối kiểm cả hai ô nên không dựa vào hai kiểm rời nhau để
suy ra chúng đã được truyền đúng.

213 phép có hai NaN ở native dùng kết quả CPU đã đối chứng bằng 363 mẫu
phép số riêng. Không sửa byte mã gốc hoặc chuẩn hóa NaN để che lệch. Chưa
so cờ trạng thái CPU và mọi lỗi bộ nhớ.

Đoạn tên mã, comment, đổi tiền/vốn ở giữa hai khối được cấp cùng dữ liệu;
chưa chạy toàn đoạn đó hoặc toàn dispatcher. Khởi tạo seed, nơi gọi EA,
menu, hiển thị, trạng thái khởi động lại và phép chạy cặp toàn EA vẫn còn
phải làm. Đây chưa phải xác nhận bot 3 hoàn thành.
