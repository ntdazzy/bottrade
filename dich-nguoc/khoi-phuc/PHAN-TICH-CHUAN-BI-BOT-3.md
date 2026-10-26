# Chuẩn bị cài đặt chiến lược bot3

Đã viết cả khối chuẩn bị `Bot3Preparation.mqh`: lấy chỉ báo/giá/thời gian,
chép cài đặt, tính khoảng cách, áp mức tối thiểu và hạn lệnh. Nguồn thật
và chương trình kiểm đều biên dịch **0 lỗi/0 cảnh báo**.

Lượt `b3-preparation-full-20261026-r1` chạy cả thân gốc `0xe0c0..0xef3f`
và nguồn MQL5 mới: **1.016/1.016 ca khớp**, so76giá trị gồm35kết quả
số trước đây,22trường bổ sung,12trạng thái/chuỗi/mảng và7số lần gọi
dịch vụ. Hai kết quả cùngSHA:
`465601457c2dab5b3ba994fe8d2408ff71a11739d1c39c6934f54044ae87229d`.
[Kết quả](bot-cua-toi-3/bang-chung/kiem-quan-ly-vi-the/b3-preparation-full-20261026-r1/comparison.json).

Claude viết khối chuẩn bị và chương trình kiểm theo mô tả Codex chốt;
Codex kiểm lại mã, tự nối thân gốc, chốt vị trí/kiểu dữ liệu và so kết quả.
Hai phiên dùng Opus5.5max, đã đối chiếu nhật ký thực tế8và24yêu cầu.
Đã yêu cầu ultracode, chưa có bằng chứng độc lập xác nhận lúc chạy.
Rà độc lập chưa thấy lỗi trong phạm vi được giao.

Bộ mới chọn1.016ca gốc chạy bình thường từ bộ1.034ca cũ;18ca phát lỗi
được giữ riêng, chưa chạy qua khối mới ở lượt này. Dữ liệu chỉ báo, tick,
thời gian và thuộc tính được cấp. Chưa kiểm lỗi tạo chỉ báo, CopyBuffer
trả0/âm, mảng ngắn, lỗi cấp phát, mọi lần đổi dữ liệu giữa các truy vấn,
toàn bộ tick/lịch, giá trị mảng hoặc trực tiếp trường virtual_expiration.
Không dùng số ca để suy ra đã phục hồi toàn bộ chức năng hay EA.

Nguồn [Bot3Preparation.mqh](bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/Bot3Preparation.mqh).
Chưa nối đầy đủ nơi nạp tham số và nơi gọi trong EA chính. Tiếp theo:
kiểm các đường trả sớm/lỗi và trạng thái trước lỗi, ghép vào luồng chọn
chiến lược rồi điều kiện mua/bán và quản lý.

## Đã kiểm thêm lỗi chia0 và cách biên dịch

18/18ca gốc gây chia0 đã chạy riêng từng ca trong MT5: khớp lớp lỗi
và dừng trước khi có kết quả thường. Lượt b3-preparation-errors-20261026-r2
không khẳng định so đủ trạng thái trước lỗi hay số dòng lỗi.

Nguyên nhân lượt đầu chạy tiếp là biên dịch trực tiếp chưa bật kiểm chia0.
Đã đo6ca không bật và6ca bật bằng tệp dự án; bật thì5ca0/-0 dừng đúng,
ca chia2 vẫn trả bình thường. Không thêm luật chặn hoặc đổi công thức
trong header sản phẩm. Bản mới biên dịch cùng `fpzerocheck=1` và1.016ca
thường vẫn giữ nguyên kết quả465601...229d.

Bắt buộc dùng `bien-dich.ps1 -CheckFloatingPointDividers` cho khối này khi
cần hành vi lỗi như bản gốc. Dự án và SHA được giữ trong từng biên nhận;
[mô tả chính thức](https://www.mql5.com/en/book/advanced/project/project_mqproj).
Tùy chọn mới không đổi lượt cũ hoặc MT5 chính. Hồ sơ thường/lỗi ban đầu
được giữ nguyên; trạng thái mới nằm trong project-error-verification.json.
