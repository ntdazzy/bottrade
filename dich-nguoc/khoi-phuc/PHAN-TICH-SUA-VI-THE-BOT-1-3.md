# Sửa dừng lỗ/chốt lời vị thế theo vé — bot 1 và bot 3

Đã dựng một hàm mỗi bot: kiểm chương trình dừng, chọn vị thế theo vé,
tạo yêu cầu sửa dừng lỗ/chốt lời rồi gọi khối gửi/thông báo đã dựng.
Mỗi bot khớp **1.596/1.596 ca** với mã máy gốc, chương trình MQL5 và
máy đo quá khứ. Bốn bản biên dịch đều 0 lỗi, 0 cảnh báo. Chưa hoàn
thành toàn bộ bot; trả lời truy vấn và kết quả gửi trong bộ kiểm được cấp.

| Phần | Bot 1 | Bot 3 | Nguồn dựng lại và phần còn thiếu |
|---|---|---|---|
| Sửa theo vé | `0x26d20`..`0x271e7`, C 16977–17100 | `0x32a90`..`0x32f57`, C 22819–22942 | `Bot1ModifyPosition` / `Bot3ModifyPosition` trong [Bot1PositionModify.mqh](bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/Bot1PositionModify.mqh), [Bot3PositionModify.mqh](bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/Bot3PositionModify.mqh) |
| Gửi và thông báo | `0x950` và các hàm định dạng | `0x950` và các hàm định dạng | Dùng lại `BotNSendTrade` đã kiểm; không thêm nguồn mới |
| Nơi gọi | 19 nơi: `0x18aa0` (1), `0x271f0` (9), `0x2abc0` (9) | 21 nơi: `0x20ef0` (1), `0x32f60` (10), `0x37590` (10) | Chỉ đọc tĩnh; chưa dựng, chưa chạy |

Phân tích được lưu trước khi viết nguồn:
[bot 1](bot-cua-toi-1/phan-tich/dong-vi-the/modify-20261025-r1/analysis.md),
[bot 3](bot-cua-toi-3/phan-tich/dong-vi-the/modify-20261025-r1/analysis.md),
[bảng ngữ nghĩa](bot-cua-toi-1/phan-tich/dong-vi-the/modify-20261025-r1/semantics.json)
(cùng nội dung ở thư mục bot 3). Mỗi hàm có 196 lệnh máy.

## Thứ tự xử lý phải giữ

1. Đọc cờ chương trình dừng **trước khi chọn vé**. Nếu dừng: in
   `CTrade::PositionModify: MQL5 program is stopped. Trading is disabled`
   qua `PrintFormat("%s: ...","CTrade::PositionModify")`, chỉ đổi mã kết
   quả thành 10027 và trả `false`; không chọn vé, không xóa cấu trúc.
2. `PositionSelectByTicket(ticket)`. Thất bại thì trả `false`, giữ nguyên
   yêu cầu/kết quả/kiểm cũ.
3. Xóa ba cấu trúc yêu cầu/kết quả/kiểm (628 byte ở mã gốc, gồm vùng đệm).
4. Ghi hành động 6 (`TRADE_ACTION_SLTP`) và vé vị thế.
5. Sau đó mới đọc `PositionGetString(POSITION_SYMBOL)` làm mã giá.
6. Đọc mã nhận diện đã lưu **sau** lần đọc mã giá.
7. Ghi dừng lỗ, chốt lời cuối cùng; gọi toàn bộ khối gửi và trả đúng
   giá trị đúng/sai của khối gửi.

Hàm không kiểm cách khớp, không ghi độ lệch giá, khối lượng hay giá.
Mã nhận diện, độ lệch giá, cách khớp ưu tiên, tùy chọn gửi và cờ dừng
chỉ được đọc; bộ kiểm chặn mọi lần mã gốc ghi vào các ô này.
Đối số: vé ở `RCX` (64
bit), dừng lỗ ở nửa thấp `XMM1`, chốt lời ở nửa thấp `XMM2`; các thanh
ghi khác mang giá trị đánh dấu và không được dùng. Kết quả trả là `AL`
mở rộng 0.

## Kết quả và cách kiểm lại

- Lượt `position-modify-20261025-r1`: 1.596 ca mỗi bot, gồm 83 ca dừng,
  33 ca chọn vé thất bại, 1.480 ca gửi. Có vé/mã nhận diện 64 bit, 196
  cặp dừng lỗ/chốt lời gồm `NaN`, vô hạn, `-0`, mã giá trống/không có
  chuỗi/Unicode/dài tới 2.048 ký tự, 1.201 ca gửi/thông báo dùng lại và
  28 ca đổi dữ liệu tại các lần gọi ngoài. Số ca không phải tỷ lệ hoàn
  thành toàn bot. [Bot 1](bot-cua-toi-1/bang-chung/kiem-sua-vi-the/position-modify-20261025-r1/comparison.json),
  [bot 3](bot-cua-toi-3/bang-chung/kiem-sua-vi-the/position-modify-20261025-r1/comparison.json).
- So giá trị trả, 35 trường công khai, bốn chuỗi/cờ không có chuỗi, mã
  nhận diện/cách khớp/độ lệch đã lưu, tùy chọn gửi và trạng thái trước
  mỗi lần gọi ngoài, sau gửi và khi trả về. Mã gốc chạy đủ 196/196 lệnh
  máy. Chụp kết quả trước khi dọn chuỗi bằng hàm gốc; sau đó kiểm cân
  bằng cấp/giải phóng, ngăn xếp và thanh ghi phải giữ.
- Bản `b1-position-modify-01` / `b3-position-modify-01` và hai bản máy
  đo quá khứ: MetaEditor trả mã thoát 1, nhật ký ghi 0 lỗi/0 cảnh báo.
  Không dùng riêng mã thoát để kết luận; tổng kiểm dựa vào số lỗi/cảnh
  báo, mã EX5 và lần chạy hoàn tất.
- Máy đo quá khứ `engine-modify-b1-r1` / `engine-modify-b3-r1`: chạy
  trên tài khoản demo, mã thoát 0, nhật ký có
  `POSITIONMODIFY_NATIVE_CHECK_EXIT:0`; 1.596/1.596 ca, kết quả giống
  từng byte với mã gốc và chương trình MQL5 (`76f88d45…`).
  [Bot 1](doi-chung-mt5/sua-vi-the-20261025/engine-modify-b1-r1/comparison.json),
  [bot 3](doi-chung-mt5/sua-vi-the-20261025/engine-modify-b3-r1/comparison.json).
  Runner lưu bản chính nó thành `tester-check-tool.py` trong lượt.
- [Tổng kiểm](KIEM-CHUNG-SUA-VI-THE-BOT-1-3.json) không mở MT5: kiểm
  nguồn/bản dựng/công cụ/máy, tính lại ba đường đi và yêu cầu lúc gửi
  của cả 1.480 ca gửi, chạy lại 45 ca bằng mã gốc (đủ 196/196 lệnh),
  từ chối 22 kiểu dữ liệu sai, 12 tệp sai và 18 tệp cắt cụt mỗi bot.

Các mã băm trên lấy từ tệp do Codex chạy; Claude chỉ đọc tệp, không
tự chạy hoặc tính lại băm.

Lệnh: `kiem-sua-vi-the-bot-1-3.py prepare|mql5|original|compare BOT RUN`;
biên dịch giữa `prepare` và `mql5`, truyền `--build BUILD` cho `mql5`.
Sau đó `kiem-hang-doi-trong-may-thu.py BOT NEW_RUN --component-run RUN
--build BUILD --modify`; tổng kiểm `kiem-chung-sua-vi-the-bot-1-3.py
NEW_JSON`. Tên lượt/đầu ra phải mới. [Danh mục](cong-cu/BOT-1-3.md).

## Nơi gọi đã thấy

`phan-tich-goi-sua-vi-the-bot-1-3.py`, lượt `modify-callers-20261025-r1`
([bot 1](bot-cua-toi-1/phan-tich/dong-vi-the/modify-callers-20261025-r1/caller-sites.json),
[bot 3](bot-cua-toi-3/phan-tich/dong-vi-the/modify-callers-20261025-r1/caller-sites.json)),
chỉ đọc mã máy theo từng đoạn lệnh thẳng. Số nơi gọi khớp số dòng gọi
trong C và danh sách hàm gọi của bản đồ. Vé (`RCX`) và chốt lời
(`XMM2`) được ghi ngay trong đoạn ở mọi nơi; dừng lỗ (`XMM1`) ở 17/19
nơi bot 1 và 19/21 nơi bot 3, còn 2 nơi mỗi bot được nạp trước đoạn,
chưa lần ngược. Trường `return_use` chỉ là quét tuyến tính (có lệnh
`nop` dùng `rax` bị tính là đọc), không dùng làm bằng chứng nơi gọi
dùng giá trị trả về.

## Cấu hình Claude và phần còn thiếu

[Biên nhận lượt viết](danh-gia-claude/position-modify-implementation-20261025-r1/receipt.json):
118/118 yêu cầu ghi `claude-opus-5-5`, mức `max`; Ultracode được yêu
cầu nhưng chưa hoàn thành quy trình riêng; không ghi tệp ngoài thư mục
giao. [Lượt nối máy thử/tổng kiểm](danh-gia-claude/position-modify-stage2-20261025-r1/receipt.json)
có 75/75 yêu cầu dùng đúng mô hình/mức trên, không ghi ngoài `stage2/`;
phần nhật ký lượt trước giữ nguyên. Codex đã chạy bản đồ r4 và kiểm
chỉ hai dòng hàm sửa vị thế thay đổi so với r3.
[Đối chiếu lượt 1](danh-gia-claude/position-modify-implementation-20261025-r1/parent-review.md),
[đối chiếu lượt 2](danh-gia-claude/position-modify-stage2-20261025-r1/parent-review.md).
Khối điều phối bot 1 `0x10f60` vẫn bị từ chối như đã ghi
([biên nhận](danh-gia-claude/bot1-coordinator-20261025-r1/receipt.json));
phần này không đụng tới khối đó.

Còn phải chứng minh: 19/21 nơi gọi và nguồn giá trị dừng lỗ/chốt lời
truyền vào, cả hai chiều quản lý, đặt sau khớp, kết quả sửa trên tài
khoản/nơi giao dịch thật, `_LastError`, lỗi cấp bộ nhớ, toàn EA, mọi
cài đặt/menu, bảng hiển thị, khởi động lại/trạng thái lưu. Chưa so byte
đệm riêng của MQL5. Không gửi lệnh thật trong bộ kiểm. Không xác nhận
hoàn thành 100%. [Bản đồ](BAN-DO-TOAN-BO-BOT-1-3.md), hàng P20.
