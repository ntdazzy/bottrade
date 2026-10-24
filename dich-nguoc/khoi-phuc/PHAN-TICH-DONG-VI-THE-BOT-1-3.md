# Đóng vị thế — bot 1 và bot 3

Đã dựng hai hàm mỗi bot, ghép qua chọn cách khớp, gửi và thông báo.
Mỗi bot khớp **2.589/2.589 ca** với mã máy gốc, chương trình MQL5 và
máy đo quá khứ. Hai bản biên dịch đều 0 lỗi, 0 cảnh báo. Chưa hoàn
thành toàn bộ bot; dữ liệu truy vấn và kết quả gửi trong bộ kiểm được cấp.

| Phần | Bot 1 | Bot 3 | Bằng chứng và phần còn thiếu |
|---|---|---|---|
| Tạo/gửi đóng theo vé | `0x22c40`, C 15404–15541 | `0x2e370`, C 21093–21230 | Đã dựng `BotNClosePosition`; còn ghép nơi gọi và kiểm nơi giao dịch |
| Kiểm hai ngưỡng rồi gọi đóng | `0x3d010`, C 27063–27108 | `0x47d20`, C 31922–31967 | Đã dựng `BotNTryClosePosition`; lượt sau đã nối hai ô giá với vùng dữ liệu giá gần nhất, còn thứ tự nạp/ghi ở mọi nhánh quản lý |
| Chọn cách khớp, gửi và thông báo | `0x231c0`, `0x950` và các hàm định dạng | `0x2e8f0`, `0x950` và các hàm định dạng | Dùng nguồn đã dựng, so cả trạng thái và thứ tự gọi; chưa có toàn EA |

Phân tích và danh sách nhánh được lưu trước khi viết nguồn:
[bot 1](bot-cua-toi-1/phan-tich/dong-vi-the/close-20261024-r1/semantics.json),
[bot 3](bot-cua-toi-3/phan-tich/dong-vi-the/close-20261024-r1/semantics.json).
Các thư mục này giữ mã C, 332 lệnh máy mỗi bot, vị trí gốc và mã kiểm tra.
`runtime_verified:false` trong bản phân tích là trạng thái lúc phân tích;
kết quả chạy về sau nằm ở các biên nhận riêng bên dưới.

## Thứ tự xử lý phải giữ

Hàm đóng trực tiếp kiểm chương trình đã dừng **trước khi chọn vé**.
Nếu dừng, in `CTrade::PositionClose` và chỉ đổi mã kết quả thành 10027.
Nếu chọn vé thất bại, giữ nguyên yêu cầu/kết quả/trạng thái kiểm cũ.

Khi chọn được vé: đọc mã giá, xóa ba cấu trúc, gọi chọn cách khớp khi
hành động còn bằng 0. Nếu bị từ chối thì dừng tại đó. Sau đó mới đọc
loại vị thế, chọn chiều đóng và giá, ghi hành động 1, vé, mã giá,
khối lượng, mã nhận diện và độ lệch giá 64 bit, rồi gọi toàn bộ khối gửi.
Loại vị thế ở hàm này chỉ dùng 32 bit thấp; không được đổi thành so đủ
64 bit. Hàm không trả lại kết quả đúng/sai của khối gửi.

Hàm kiểm điều kiện chọn vé rồi đọc mã nhận diện. Nó đọc loại vị thế
đủ 64 bit hai lần riêng. Nhánh loại 0 dùng giá trị tham chiếu A cho
cả hai lần so; nhánh loại 1 dùng B ở lần đầu và **A ở lần sau**.
Mỗi lần đọc tham chiếu nằm trước lần đọc dừng lỗ; ngưỡng được đọc sau.
Phép so là `abs(tham_chiếu - dừng_lỗ) > ngưỡng`: bằng nhau hoặc số
không xác định thì bỏ nhánh. Không gán tên “giá mua/bán hiện tại” cho
A/B khi nguồn cấp chưa được chốt. Hai nhánh có thể gọi đóng hai lần
trong bộ dữ liệu kiểm có loại thay đổi; đây không phải khẳng định
vị thế trên tài khoản thật đổi loại giữa hai lần đọc.

[Đối chứng có nguồn](doi-chung-mt5/dong-vi-the-20261024/close-api-r1/api-contract.json)
đã chốt 12 hằng, các lời gọi MT5 và mặt nạ trị tuyệt đối. Thuộc tính 6
là dừng lỗ; thuộc tính 5 mới là giá hiện tại. Mã thuộc tính cách khớp
là 33/50, khác cặp 17/33 dùng để định dạng thông báo.

## Kết quả và cách kiểm lại

- Lượt `close-20261025-r4`: 1.698 ca gọi trực tiếp, 891 ca gọi qua kiểm
  điều kiện, tổng 2.589 ca mỗi bot. Có số sát ngưỡng, số không xác định,
  chuỗi trống/không có chuỗi, mã 64 bit, dừng, chọn thất bại, hai lần
  đóng và thay đổi dữ liệu giữa các lần đọc. Số ca không phải tỷ lệ
  hoàn thành toàn bot.
- So 35 trường công khai, bốn chuỗi đầy đủ/cờ không có chuỗi, độ lệch
  giá và bốn số dùng chung. So thêm trạng thái trước truy vấn và sau
  gửi, đối số/thứ tự gọi, nội dung thông báo, số lần đóng/gửi. Chụp kết
  quả trước khi dọn chuỗi kết quả bằng hàm gốc; sau dọn kiểm cân bằng
  số lần cấp/giải phóng. Chưa chứng minh mọi phép dùng bộ nhớ đều hợp lệ.
- Bản `b1-position-close-02` / `b3-position-close-02`; máy đo quá khứ
  `engine-close-b1-r2` / `engine-close-b3-r2`. MetaEditor trả mã thoát
  1 ở các lượt này; nhật ký ghi 0 lỗi/0 cảnh báo, EX5 đúng mã kiểm tra
  đã chạy đủ ca. Không dùng riêng mã thoát để kết luận biên dịch đạt.
- [Tổng kiểm](KIEM-CHUNG-DONG-VI-THE-BOT-1-3-R2.json) kiểm nguồn/bản dựng,
  dữ liệu ba nơi chạy, nguồn gốc công cụ và 28 kiểu sửa dữ liệu sai;
  từ chối thêm chín trường hợp cắt cụt tệp mỗi bot.

Lệnh: `kiem-dong-vi-the-bot-1-3.py prepare|mql5|original|compare BOT RUN`;
biên dịch giữa `prepare` và `mql5`, truyền `--build BUILD` cho `mql5`.
Sau đó chạy `kiem-hang-doi-trong-may-thu.py BOT NEW_RUN --component-run RUN
--build BUILD --close`. Tổng kiểm không mở MT5:
`kiem-chung-dong-vi-the-bot-1-3.py NEW_JSON`. Tên lượt/đầu ra phải mới.
[Danh mục](cong-cu/BOT-1-3.md).

R1 dừng do bộ kiểm dùng sai 17/18; r2 dừng do cách kiểm bộ nhớ của
chương trình kiểm; r3 khớp 2.369 ca. Đã giữ nguyên các lượt và nguồn
đã kiểm. [Claude](danh-gia-claude/position-close-check-20261025-r1/receipt.json)
đọc độc lập bằng Opus 5.5, mức `max` được xác nhận từ nhật ký 18 yêu
cầu. [Đối chiếu lại nhận xét](danh-gia-claude/position-close-check-20261025-r1/parent-review.md)
phân biệt lỗi r1 với các sửa đổi sau đó. Bật cài đặt Ultracode chưa
phải bằng chứng hoàn thành một quy trình Ultracode riêng.

[Lượt Claude đọc lại r4](danh-gia-claude/position-close-check-20261025-r2/parent-review.md)
đã xác nhận các sửa đổi; không tìm thấy lỗi còn lại có thể chứng minh.
Năm yêu cầu mới được xác nhận dùng đúng Opus 5.5 `max`. Báo cáo chỉ
đọc tệp; cha đã tự kiểm băm và chạy so. Còn phép ghép mọi cặp cờ cách
khớp khác nhau và ưu tiên 1 trong nhóm hai lần đóng; không bỏ các mục này.

[Lượt quét/chọn mới](PHAN-TICH-CHON-VI-THE-DONG-BOT-1-3.md) đã ghép
bốn hàm quét qua phần đóng này; lượt r3 khớp 4.600 ca mỗi bot (2.300
mỗi chiều). Đã bổ sung bằng chứng hai ô giá thuộc vùng dữ liệu giá gần
nhất và ba hằng khoảng cách. Còn thứ tự nạp/ghi giá/ngưỡng trong mọi
nhánh quản lý, nơi/thời điểm gọi, toàn EA, mọi cài đặt, bảng hiển thị,
khởi động lại/trạng thái lưu, tài khoản/nơi khớp/mã lỗi MT5 thật và
lỗi cấp bộ nhớ. Chưa chứng minh toàn bộ byte đệm riêng của MQL5. Không
gửi lệnh thật trong bộ kiểm.
