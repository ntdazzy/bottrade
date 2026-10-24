# Hủy lệnh chờ — phân tích trước khi viết mã

Đã dựng hàm hủy một vé của mỗi bot: 964/964 ca khớp mã gốc, chương
trình MQL5 và máy đo quá khứ. Hai bản biên dịch đều 0 lỗi, 0 cảnh báo.
Đã giữ mã C/lệnh máy của ba hàm mỗi bot và kiểm SHA-256 EX5 gốc.
Đã ghép thêm hai hàm chọn vé của mỗi bot với hủy/gửi và dọn bảng:
2.522/2.522 ca mỗi bot khớp cả ba nơi chạy. Các hàm sửa lệnh và ghép
toàn EA vẫn chưa phục hồi đủ.

| Phần | Bot 1 | Bot 3 | Còn thiếu |
|---|---|---|---|
| Kiểm vùng cấm rồi tạo/gửi hủy | `0x34150` | `0x32450` | Đã nối dữ liệu giá bằng nguồn đối chứng, dựng và so 964 ca mỗi bot; còn ghép nơi gọi, dữ liệu nơi giao dịch và toàn EA |
| Chọn vé nhánh mua rồi hủy, dọn bảng, in | `0x32110` | `0x3da90` | Đã dựng và ghép nguyên luồng; bộ 2.522 ca mua/bán mỗi bot khớp. Còn trạng thái chọn/dữ liệu tài khoản thực và ghép EA |
| Chọn vé nhánh bán rồi hủy, dọn bảng, in | `0x325b0` | `0x3dd60` | Cùng bộ kiểm phía trên; còn các giới hạn tương tự |

Hai hàm chọn vé gọi trực tiếp hàm hủy phía trên. Không thay khối này
bằng lời hủy đơn giản: khối hủy còn chọn lại lệnh, đọc dữ liệu giá,
kiểm khoảng cách, xử lý dừng và dựng yêu cầu trước khi tới `0x950`.
Các vòng quét vẫn bắt đầu ở tổng lệnh và đi xuống 0, đủ hai đầu.

Trong hàm hủy, thứ tự quan sát được:

1. Chọn vé. Nếu chọn được: đọc mã giá, thuộc tính số 16 (`P`), dữ
   liệu giá gần nhất, thuộc tính nguyên số 32 (`L`). Các bước sau phụ
   thuộc kết quả bước trước. Đối chứng có nguồn mới đã chốt `A` là
   giá mua vào của nơi giao dịch (`bid`, lệch +8), `B` là giá bán ra
   (`ask`, lệch +16) trong dữ liệu `MqlTick`.
2. Tính `F=P*(double)L`. Mã máy chọn `F` nếu `F>0` **hoặc F không xác
   định**; trường hợp còn lại chọn `B-A`, gọi kết quả là `D`.
3. Với `D` thích hợp, đọc giá lệnh (`Q`, thuộc tính 9) và loại lệnh
   (thuộc tính 4). Chỉ dùng 32 bit thấp của loại lệnh.
4. Loại 2 dùng `B-Q`; loại 3 dùng `Q-A`; loại 4/6 dùng `Q-B`; loại
   5/7 dùng `A-Q`. Khoảng cách nhỏ hơn/bằng `D` thì trả về, giữ trạng
   thái giao dịch cũ. Không được đổi bằng dấu so sánh khác.
5. Nếu không bị chặn: khi chương trình dừng, in thông báo
   `CTrade::OrderDelete`, ghi mã kết quả 10027. Nếu không dừng, xóa
   cấu trúc yêu cầu/kết quả/kiểm, đặt hành động 8, mã nhận diện đã lưu
   8 byte và vé cần hủy, rồi gọi đầy đủ khối gửi `0x950`.

Điều kiện với số không xác định phải theo lệnh máy, không chép máy
móc điều kiện từ mã C trung gian:

| Điểm kiểm | Lệnh và vị trí bot 1 / bot 3 | Hành vi cần giữ |
|---|---|---|
| `P` trước đọc dữ liệu giá | `ucomisd` rồi `jae`, `0x34242/0x34246` / `0x32542/0x32546` | `P<=0` có thứ tự thì bỏ tiền kiểm; số không xác định vẫn gọi bước kế |
| Chọn `F` hay `B-A` | `cmpnlesd`, `0x342af` / `0x325af` | Số không xác định cũng chọn `F`, không chọn chênh lệch |
| `D` trước đọc giá/loại lệnh | `ucomisd` rồi `jae`, `0x342c6/0x342ca` / `0x325c6/0x325ca` | `D<=0` có thứ tự thì bỏ tiền kiểm; số không xác định vẫn đọc giá/loại |
| So khoảng cách cuối | `ucomisd` rồi `jb`, `0x34771/0x34775` / `0x32a78/0x32a7c` | Khoảng cách lớn hơn `D`, hoặc một vế không xác định, đều đi tạo hủy |

Nhận định ban đầu của agent đã đảo hai nhánh chọn ngưỡng. Đã đọc
lại phép ghép bit trong C và lệnh máy, sửa thành bảng trên. Bot 1
không có giá trị trả về dùng được; bot 3 có byte trả về, nhánh không
gửi/dừng trả 0, nhánh gửi dùng kết quả của hàm gửi. Phép so chạy mới
đã kiểm khác biệt này; bot 1 không bị gán thêm giá trị trả về.

- [Mã C/lệnh máy bot 1](bot-cua-toi-1/phan-tich/huy-lenh-cho/cancel-20261024-r1/analysis.json).
- [Mã C/lệnh máy bot 3](bot-cua-toi-3/phan-tich/huy-lenh-cho/cancel-20261024-r1/analysis.json).

Trước viết mã, đã đối chứng hai trường giá và hằng thuộc tính:
`SYMBOL_POINT=16`, `SYMBOL_TRADE_FREEZE_LEVEL=32`, trên đúng máy
MT5 có SHA-256 đã chốt. Bản có nguồn chỉ gọi `Anchor`; hàm mẫu bid/
ask cho thấy con trỏ dữ liệu và lệnh đọc ở +8/+16, không dựa tên biến.
[Bằng chứng](doi-chung-mt5/huy-lenh-cho-20261024/cancel-tick-api-r1/tick-fields.json).
Đã đọc lại đủ sáu địa chỉ trong bảng nhảy mỗi bot để nối loại 2..7.
Đã so chọn vé thất bại, đọc giá thất bại, số âm/0/sát ngưỡng/không xác
định/vô hạn, loại có phần 32 bit cao, dừng, trạng thái cũ và gửi thành
công/thất bại. Hai hàm chọn vé đã ghép trong lượt mới bên dưới;
còn các hàm sửa lệnh, nơi gọi phía trên và toàn EA.

## Nguồn và kết quả kiểm

| Bot | Nguồn hủy một vé | Lượt so mã gốc/MQL5 | Lượt máy đo quá khứ |
|---|---|---|---|
| 1 | [Bot1OrderCancel.mqh](bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/Bot1OrderCancel.mqh) | [964/964](bot-cua-toi-1/bang-chung/kiem-huy-lenh-cho/cancel-20261024-r2/comparison.json) | [964/964](doi-chung-mt5/huy-lenh-cho-20261024/engine-cancel-b1-r2/comparison.json) |
| 3 | [Bot3OrderCancel.mqh](bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/Bot3OrderCancel.mqh) | [964/964](bot-cua-toi-3/bang-chung/kiem-huy-lenh-cho/cancel-20261024-r2/comparison.json) | [964/964](doi-chung-mt5/huy-lenh-cho-20261024/engine-cancel-b3-r2/comparison.json) |

So giá trị trả về, 35 trường giao dịch, đủ bốn chuỗi, thứ tự/đối số
truy vấn, số lần gửi và thông báo. Mã gốc chạy hết hàm hủy và khối gửi,
không thay kết quả của thuật toán. Nguồn giao dịch chạy trực tiếp bằng
MQL5; chỉ chương trình kiểm mới thay lời gọi truy vấn/gửi bằng dữ liệu
cấp sẵn. Định dạng thông báo được đo trong MT5.

[Tổng kiểm](KIEM-CHUNG-HUY-LENH-CHO-BOT-1-3.json) xác nhận lại mã tệp,
bản biên dịch, nguồn đã lưu, dữ liệu ba lượt chạy và 12 kiểu sửa đầu
vào sai phải bị từ chối. Không so các byte đệm riêng của cấu trúc MQL5.
964 ca không chứng minh mọi đầu vào, lỗi cấp bộ nhớ, trạng thái chọn
trên tài khoản thực, các hàm gọi, mọi cài đặt hoặc toàn bot.

Lượt `cancel-20261024-r1` dừng ở kiểm thu hồi chuỗi tạm trong bộ kiểm.
Đã đo đúng nguyên nhân: chuỗi kết quả còn trong ô trả về của dịch vụ.
Lượt r2 thu hồi ô tạm sau khi hàm trả về rồi kiểm cân bằng bộ nhớ;
không sửa thuật toán MQL5 để làm phép so đạt. Bằng chứng r1 được giữ.

## Chọn lệnh cần hủy và dọn trạng thái

Trước viết mã, đã đọc lại lệnh máy, kiểm mã tệp gốc và giá trị khởi
đầu ở cả hai bot. [Phân tích bot 1](bot-cua-toi-1/phan-tich/huy-lenh-cho/selection-20261024-r1/analysis.json),
[bot 3](bot-cua-toi-3/phan-tich/huy-lenh-cho/selection-20261024-r1/analysis.json).

- Chỉ đọc tổng lệnh một lần; quét từ tổng xuống 0, đủ hai đầu.
- Mã nhận diện chiến lược được đọc theo số nguyên có dấu 32 bit sau
  lời gọi truy vấn; loại lệnh so đủ 64 bit. Mã giá so đúng từng ký tự.
- Nhánh mua chọn giá lớn nhất trên 0; nhánh bán chọn giá nhỏ nhất dưới
  **9999**, giữ đúng hằng của bản gốc. Bằng giá không đổi vé đã chọn.
- Đọc giá lần đầu để so; khi chọn thì đọc lần hai để lưu mốc mới.
  Hai lần đọc khác nhau, hoặc lần hai ra số không xác định, vẫn được giữ.
- Gọi nguyên hàm hủy một vé rồi bỏ giá trị trả về. Dù bị chặn, dừng
  hay gửi thất bại, vẫn tìm xóa hàng đầu trùng vé rồi in thông báo.
- Vé được hiểu theo số nguyên có dấu 64 bit trước khi đổi sang số
  thực để so với bảng. Chỉ xóa hai ô của hàng trùng đầu tiên, giữ các
  hàng còn lại. Vé dùng chung vẫn là kết quả lần quét cuối, không bị
  thay bằng vé đã chọn để hủy.

Nguồn [Bot1PendingSelection.mqh](bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/Bot1PendingSelection.mqh)
và [Bot3PendingSelection.mqh](bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/Bot3PendingSelection.mqh)
đã biên dịch 0 lỗi/cảnh báo. Bộ 2.522 ca mỗi bot có 1.261 ca mỗi chiều,
gồm đọc giá lần hai, bằng giá, vé sát các mốc lớn, hàng trùng/đầu/cuối,
số không xác định/vô hạn, chuỗi rỗng/null/tiếng Việt và đổi trạng thái
trong lúc truy vấn. Các ca hủy cũ được ghép chạy nguyên luồng.

| Bot | Mã gốc và chương trình MQL5 | Máy đo quá khứ |
|---|---|---|
| 1 | [2.522/2.522](bot-cua-toi-1/bang-chung/kiem-chon-lenh-huy/selection-20261024-r2/comparison.json) | [2.522/2.522](doi-chung-mt5/chon-lenh-huy-20261024/engine-selection-b1-r2/comparison.json) |
| 3 | [2.522/2.522](bot-cua-toi-3/bang-chung/kiem-chon-lenh-huy/selection-20261024-r2/comparison.json) | [2.522/2.522](doi-chung-mt5/chon-lenh-huy-20261024/engine-selection-b3-r2/comparison.json) |

So đủ 200 số trong bảng, vé dùng chung, mã nhận diện/mã giá, 35 trường
giao dịch, bốn chuỗi kèm cờ null và dấu vết truy vấn/gửi/thông báo theo thứ tự.
[Tổng kiểm](KIEM-CHUNG-CHON-LENH-HUY-BOT-1-3-R2.json) còn kiểm 24 kiểu sửa
dữ liệu cấp sai phải bị từ chối; lời in một đối số phải chặn số đối số
0 và 2. Dữ liệu truy vấn/kết quả gửi vẫn được cấp trong bộ kiểm; chưa
chứng minh trạng thái chọn trên tài khoản thực, mọi nơi gọi, lỗi cấp
bộ nhớ hoặc toàn EA. 2.522 ca không phải tỷ lệ hoàn thành toàn bộ bot.

Claude đã [chỉ ra hai thiếu sót ở bộ kiểm](danh-gia-claude/selector-check-ultracode-20261024-r2/response.md):
biên nhận biên dịch thiếu kết quả vẫn có thể lọt, và bước MQL5 chưa
ràng/ghi mã kiểm tra của chính công cụ. Đã sửa cả hai. Bảy phép thử
bằng lệnh thật đều bị chặn đúng trước khi mở MT5: ba biên nhận thiếu
kết quả ở MQL5, ba ở máy thử và một bản công cụ bị sửa.
[Bằng chứng](danh-gia-doc-lap/chon-lenh-huy-20261024/negative-cli-r2.json).

Lượt r1 có 2.474 ca được giữ nguyên. Lượt r2 thêm 48 ca phân biệt
chuỗi rỗng/null, so cả cờ null của bốn chuỗi, chặn tệp ghi thiếu,
ràng đủ tám nguồn và dựng lại văn bản kiểm trong máy thử để so.
Mỗi lượt máy thử dùng thư mục kết quả mới riêng; không dùng tệp cũ.
Không đổi thuật toán của bốn hàm giao dịch để làm phép so đạt.
[Agent chính đã đối chiếu các nhận xét của Claude](danh-gia-claude/selector-check-ultracode-20261024-r2/parent-review.md).

Đã kiểm nhật ký thực tế: phiên chính và ba luồng phụ dùng Opus 5.5
`max`. Ultracode được bật trong cấu hình nhưng bước workflow báo
`Review dynamic workflow before running`, nên **chưa chạy workflow
Ultracode**. Ba luồng đọc riêng không gửi kết luận trước khi lượt đầu
dừng; không dùng chúng làm xác nhận. Lượt nối lại của Claude có báo
cáo trực tiếp nêu trên. [Cấu hình r1](danh-gia-claude/selector-check-ultracode-20261024-r1/receipt.json),
[cấu hình r2](danh-gia-claude/selector-check-ultracode-20261024-r2/receipt.json).

Claude đã từ chối đánh giá bảng điều kiện này ở lượt
`cancel-guards-ultracode-20261024-r1`; [phản hồi](danh-gia-claude/cancel-guards-ultracode-20261024-r1/response.md).
Đã kiểm thực tế Opus 5.5 `max`, Ultracode bật nhưng không có luồng
phụ chạy. Không dùng phản hồi từ chối làm xác nhận, không đổi cách
hỏi để vượt chặn. Phân tích trên do agent chính và hai agent đọc
mã trực tiếp. Kiểm chạy và đối chứng có nguồn nêu trên là bằng chứng
của lượt này; chưa có xác nhận từ Claude cho phần hủy.
