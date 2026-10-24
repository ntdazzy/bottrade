# Quét/chọn vị thế qua đóng — bot 1 và bot 3

Đã dựng bốn hàm quét, ghép qua toàn bộ kiểm điều kiện, đóng, chọn
cách khớp, gửi và thông báo. R3 khớp **4.600/4.600 ca mỗi bot** ở mã
gốc, MQL5 và máy đo quá khứ; có 2.300 ca mỗi chiều. Hai bản biên dịch
0 lỗi, 0 cảnh báo; chưa hoàn thành toàn bot.

| Phần | Bot 1 | Bot 3 | Nguồn/bằng chứng |
|---|---|---|---|
| Quét nhánh mua | `0x2fa00` | `0x3ce40` | `BotNCloseFilteredBuyPositions` trong `BotNPositionSelection.mqh` |
| Quét nhánh bán | `0x2fce0` | `0x3d220` | `BotNCloseFilteredSellPositions` cùng tệp |
| Kiểm điều kiện rồi đóng | `0x3d010`, `0x22c40` | `0x47d20`, `0x2e370` | Dùng nguyên phần đóng đã dựng, không thay bằng hàm cấp kết quả |
| Mã gốc đã tách | 355 lệnh máy | 467 lệnh máy | `phan-tich/dong-vi-the/scan-20261025-r1/`: C, lệnh máy, danh sách nhánh và biên nhận |

Danh sách nhánh được lưu trước khi viết nguồn:
[bot 1](bot-cua-toi-1/phan-tich/dong-vi-the/scan-20261025-r1/semantics.json),
[bot 3](bot-cua-toi-3/phan-tich/dong-vi-the/scan-20261025-r1/semantics.json).

## Những điểm giữ nguyên

1. Đọc tổng vị thế một lần. Tổng âm thì thoát; còn lại quét từ tổng
   xuống **cả 0**. Ghi lại vé đầy đủ 64 bit sau mọi lần hỏi, kể cả vé 0.
2. Sau lần đọc tổng, chụp mã cơ sở một lần. Bot 1 nhận các khoảng bù
   1–8, bot 3 nhận 1–15. Cộng theo 32 bit rồi mở rộng có dấu lên 64 bit.
   Mỗi phép so lại đọc mã vị thế; dừng ở lần khớp đầu tiên.
3. Chỉ sau khi khớp mã mới đọc chuỗi. Giữ biến chuỗi cục bộ qua các
   vòng; so đúng từng ký tự UTF-16 và trạng thái không có chuỗi.
   Không đổi chữ hoa/thường hoặc chụp chuỗi mục tiêu trước vòng.
4. Đọc loại vị thế đủ 64 bit: mua nhận 0, bán nhận 1. Đọc khối lượng
   rồi bỏ kết quả, nhưng vẫn giữ lời gọi này.
5. Đọc lại vé sau lời gọi khối lượng, rồi gọi nguyên phần kiểm đóng.
   Tiếp tục quét sau khi phần đóng trả về; không dừng ở vé đầu tiên.

Đầu vào kiểm có tổng âm/0, vé và mã 64 bit, phép cộng tràn 32 bit,
15 lần trả mã khác nhau, chuỗi rỗng/không có chuỗi/tiếng Việt/ký tự
hai đơn vị UTF-16, loại có 32 bit cao khác 0, số không xác định và
thay đổi dữ liệu ở các lần đọc. Có thêm 360 ca đổi cách khớp/ưu tiên
trong đường có thể gọi hai lần đóng, gồm ưu tiên 1. R3 thêm hai ca
đổi mã cơ sở và chuỗi mục tiêu sau lần kiểm đóng đầu. Đây không phải
mọi tổ hợp.

## Phạm vi phép so

So 35 trường giao dịch, bốn chuỗi/cờ không có chuỗi, độ lệch giá, bốn
số dùng chung, vé cuối, mã cơ sở, chuỗi mục tiêu, trạng thái chọn và
số lần gọi phần kiểm đóng. So cả trạng thái trước truy vấn, sau gửi
và khi phần kiểm đóng bắt đầu/kết thúc. So thứ tự và đối số gọi.

Bộ kiểm chỉ đặt lại bộ đếm đọc dữ liệu cấp sẵn ở đầu mỗi lần gọi phần
kiểm đóng; không đặt lại trạng thái của bot. Phần thuật toán gốc và
nguồn MQL5 thật vẫn chạy trọn. Dữ liệu truy vấn/kết quả gửi được cấp;
định dạng được đo trong MT5. Không gửi lệnh thật.

## Các lượt kiểm

| Lượt | Thay đổi | Kết quả |
|---|---|---|
| r1 | Bộ ca đầu | 4.598 ca mỗi bot khớp ở mã gốc/MQL5/máy đo quá khứ. Bộ đọc dữ liệu kiểm còn nhận tệp thiếu 2/4 byte cuối: [trước sửa](danh-gia-doc-lap/chon-vi-the-dong-20261025/parser-eof-r1.json) |
| r2 | Chỉ sửa công cụ kiểm: đọc hết đúng tệp, kiểm ngăn xếp khi phần kiểm đóng trả về | 4.598 ca mỗi bot khớp; chín tệp cắt cụt mỗi bot bị từ chối: [sau sửa](danh-gia-doc-lap/chon-vi-the-dong-20261025/parser-eof-r2.json) |
| r3 | Giữ các ca cũ, thêm hai ca id 4.598/4.599 (mua/bán) | 4.600 ca mỗi bot khớp ở mã gốc/MQL5/máy đo quá khứ |

Ba lượt dùng cùng nguồn MQL5 và bản biên dịch `bN-position-selection-01`;
chỉ công cụ kiểm thay đổi. Mỗi lượt giữ nguồn và kết quả riêng.

Ở r1/r2, kịch bản 5 đổi mã cơ sở và chuỗi mục tiêu sau lần kiểm đóng
cuối, nên không tác động phép so nào. Hai ca r3 đặt `12/Renamed` ở
chỉ số 0 và `11/XAUUSD` ở chỉ số 1. Vòng quét gặp 11 trước và gọi kiểm
đóng; sau đó mã cơ sở thành -1, chuỗi mục tiêu thành `Renamed`. Mã
gốc vẫn dùng mã đã chụp và đọc lại chuỗi, nên gọi kiểm đóng lần hai
cho vị thế 12: [hai ca mới](danh-gia-doc-lap/chon-vi-the-dong-20261025/post-helper-change-r3.json).

Bản sai cố ý: `kiem-doc-lai-sau-dong.py` tạo riêng hai bản sai mỗi
bot — giữ chuỗi mục tiêu từ lần so đầu, hoặc tính lại mã nhận diện
sau khi kiểm đóng trả về. Mã gốc từ chối đủ 8/8 ca của bốn bản sai
(`EXTRA_NATIVE_API 18`, `API_ORDER_DIFFERS (21, 23)`):
[tóm tắt](danh-gia-doc-lap/chon-vi-the-dong-20261025/post-helper-r2/summary.json).
Bản sai chỉ nằm trong thư mục kiểm và MT5 riêng; nguồn sản xuất không đổi.

## Nguồn hai giá trị tham chiếu

[Bot 1](bot-cua-toi-1/phan-tich/dong-vi-the/refs-20261025-r1/reference-origins.json)
và [bot 3](bot-cua-toi-3/phan-tich/dong-vi-the/refs-20261025-r1/reference-origins.json)
đã tìm thấy mỗi bot mười nơi nạp địa chỉ vùng dữ liệu giá gần nhất;
bốn nơi có đủ lệnh nạp mã giá/vùng đầu ra và gọi trực tiếp đúng MT5.
Đối chứng có nguồn chốt lệch +8 là giá mua vào của nơi giao dịch
(`bid`), +16 là giá bán ra của nơi giao dịch (`ask`). Hai ô tham
chiếu nằm đúng tại hai vị trí này.

Các phép gán C trực tiếp và nơi nạp cả vùng đã được ghi riêng. Đây
chưa chứng minh đã tìm mọi lần ghi gián tiếp, thứ tự cập nhật hay xử
lý nạp giá thất bại trước mọi lần đóng. Ba hằng khoảng cách đã được
đối chứng thêm: ngưỡng dừng 31, vùng cấm sửa 32 và đơn vị điểm giá 16.
Chưa dùng bằng chứng này để tự hoàn thành các hàm quản lý vị thế lớn.

## Việc còn thiếu

Còn nơi gọi/thời điểm gọi bốn hàm, trạng thái tài khoản và mã lỗi
MT5 thật, mọi tổ hợp tham số, lỗi cấp bộ nhớ, thứ tự nạp/ghi giá ở
mọi nhánh, toàn EA, mọi cài đặt, bảng hiển thị và khởi động lại.
Bốn bản sai chỉ cho thấy bộ ca bắt được hai lỗi này, không phải mọi
cách viết sai. Số ca đạt không phải phần trăm hoàn thành toàn bot.

Lệnh chạy nằm trong [danh mục](cong-cu/BOT-1-3.md). Bản biên dịch
`bN-position-selection-01` có 0 lỗi, 0 cảnh báo; giữ nguyên bằng
chứng r1/r2 khi chạy r3.

Lượt hiện hành: `position-selection-20261025-r3`, máy đo quá khứ
`engine-position-selection-bN-r3`.
[Tổng kiểm mới](KIEM-CHUNG-CHON-VI-THE-DONG-BOT-1-3-R2.json) nối
nguồn/bản dựng/dữ liệu ba nơi chạy, phép từ chối dữ liệu sai, hai ca
mới và bốn bản sai. [Tổng kiểm r2](KIEM-CHUNG-CHON-VI-THE-DONG-BOT-1-3.json)
giữ nguyên.
[Phân tích độc lập của Claude](danh-gia-claude/position-scan-semantics-20261025-r1/parent-review.md)
được đối chiếu lại bằng mã gốc; chưa dùng nhận xét thay cho kết quả chạy.
[Lượt Claude đọc bộ kiểm r1](danh-gia-claude/position-selection-check-20261025-r1/parent-review.md)
nêu hai lỗi của bộ kiểm (L1/L2); r2/r3 đã sửa. Lượt đó chỉ đọc bản r1.
