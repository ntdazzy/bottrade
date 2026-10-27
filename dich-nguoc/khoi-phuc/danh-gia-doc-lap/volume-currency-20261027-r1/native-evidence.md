# Bằng chứng đọc lại tiền tài khoản

Bản liệt kê đầy đủ và mã SHA-256 của các thân gốc nằm tại
[volume-runtime-20261027-r1/native-evidence.json](../volume-runtime-20261027-r1/native-evidence.json).

Bot1: gọi AccountInfoString tại `362d1`, soUSD, nếu khác thì gọi lại
ở `3637b`; sau đó gọi mới tại `363bc` trước điều kiệnEUR. Bot3 có hai
lần gọi đầu tương ứng `83b1`, `845b`. Các điều kiện tiếp tục gọi lại;
không dừng sau mã tiền đầu tiên khớp.

Thứ tự hướng đổi sangUSD của cả hai bot là EUR,GBP,AUD,JPY/YEN,CHF,
CZK,HKD,RUB,CNH,CNY,SGD rồi các tiền số. Kết quả được làm tròn ở cuối.
Hướng đổi ngược của bot3 dùng thân `41780` đã so riêng trong nguồn
Bot3StrategyContextAmount. Bộ kiểm mới so cả thứ tự/đối số/chuỗi
và trạng thái, gồm tiền tài khoản thay đổi giữa các lần đọc.
