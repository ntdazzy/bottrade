# Rà nguồn bảng dừng ảo bot 1 do Codex viết

Đã đọc: `AGENTS.md`, `Bot1VirtualStops.mqh`, hàm `Bot1RoundPrice` trong
`Bot1PriceLevels.mqh`, `Bot1VirtualStopsSmoke.mq5`,
`kiem-bang-dung-ao-bot-1.py`, `analysis.md`, `api-contract.json` và bốn
JSON của `virtual-smoke-20261025-r1`. Không đọc EX5, bản chụp, mã C gốc
hay hàm quản lý. Không chạy lệnh/MT5. Chưa đọc `bien-nhan.json` của
`b1-virtual-smoke-01`, `rounding.json`, `full-table-warning-schema.json`
và `analysis.json`; các ý dựa trên chúng ghi là chưa xác minh.

## Kết luận

- **Không thấy lỗi nguồn chắc chắn** so với hợp đồng viết trong
  `analysis.md`. Hợp đồng còn vài chỗ chưa rõ (F5, F6, F8).
- 7/7 chỉ là chuỗi khởi đầu. Một số mục "đã so" yếu hơn tên gọi: công
  thức hướng 2 chưa chạy, làm tròn chưa được phân biệt, vòng so vé chưa
  chạy (F1–F4, F13). Mã gốc chạy 204/420 lệnh.
- Công cụ so còn vài chỗ chưa khóa chứng cứ ở bước `compare` (F10–F12).

## Đã đối chiếu, chưa thấy sai

- Byte cho phép là `uchar`, so đúng bằng 1 (dòng 28, 48, 63, 73, 96,
  112); số ô trong thông báo là 0 khi byte bằng 0, còn lại 500 (dòng 86).
- Vé là `long` có dấu (dòng 46, 94, 110). Vé vị thế lưu bằng `(long)`
  (dòng 25). Lọc loại bằng `(ulong)...>=2` (dòng 23). Số chữ số lấy 32
  bit thấp bằng `(uint)` (dòng 55, 60). `Bot1RoundPrice` chặn không dấu
  ở 11 và giữ giá khi `(long)` bằng `LONG_MIN` (PriceLevels dòng 10, 13).
- Thứ tự gọi ngoài đúng hợp đồng: `SymbolInfoInteger` trước khi đọc
  `unit` (truyền tham chiếu, dòng 45); ghi vé đã báo → `PositionsTotal`
  → đọc byte (dòng 84–86); tìm hàng → `TimeCurrent` → ghi giờ (dòng
  115–117); `TimeCurrent` trước khi đọc lại thời gian chờ (dòng 102–103).
- Khớp hàng đầu tiên; vé 0 khớp ô trống (dòng 50, đúng hợp đồng).
  Dọn bảng bỏ qua vé 0, âm, NaN bằng `!(0.0<x)` (dòng 31); xóa giờ →
  mức → vé (dòng 38–40).
- Biên `elapsed == delay` (99 giây) đã khớp mã gốc ở bước 4–5; xác
  nhận phép so là `delay<=elapsed` (dòng 105).
- Bảy đối số `Print` đúng thứ tự trong hợp đồng (dòng 87–88).
- Bộ kiểm ghi bit số thực qua `union` (Smoke dòng 66, 99–107); bản ghi
  40+12.000 byte giống nhau ở hai phía; công cụ so kiểm đúng tổng độ dài
  và đầu tệp (checker dòng 175); bước `mql5` kiểm đích, 0 lỗi/cảnh báo,
  nguồn hiện hành/bản trong MT5/biên nhận và EX5 ba nơi (dòng 151–155).

## Các phát hiện

**F1 — Trung bình — thiếu kiểm.** `Bot1VirtualStopsSmoke.mq5:101`,
`Bot1VirtualStops.mqh:52-62`. Bước 1 dùng lại vé 7 nên trả mức đã lưu
99.0 ở dòng 50. Công thức hướng 2 (dòng 53–57) và hướng khác (mức
`+0.0`, dòng 52) chưa chạy ở cả hai phía. Kiểm tiếp: vé mới với hướng
2 và hướng 0/3/-1; hướng khác phải không gọi `SymbolInfoInteger` và vẫn
lưu mức `+0.0`.

**F2 — Trung bình — thiếu kiểm.** `Smoke.mq5:100`,
`Bot1VirtualStops.mqh:55-56,60-61`, `Bot1PriceLevels.mqh:9-15`.
100 − 10×0.1 cho đúng 99.0. Làm tròn 99.0 với mọi số chữ số vẫn ra 99.0,
và nhân rồi trừ hay phép gộp FMA cũng ra cùng số. Vậy chưa có bằng
chứng số chữ số 3 và phép làm tròn được dùng. Kiểm tiếp: mức lẻ (ví dụ
giá 100.12345, khoảng cách 3.21); số chữ số trả về 0, 3, 11, 12,
`0xFFFFFFFF` và `0x100000003` (32 bit thấp bằng 3); một bộ số mà nhân
rồi cộng khác FMA.

**F3 — Trung bình — thiếu kiểm.** `Smoke.mq5:39-44,106`,
`Bot1VirtualStops.mqh:19-27,33-36`. `PositionsTotal` trả 0 nên chưa chạy:
vòng thu vé, bỏ vé 0, lọc loại, mở rộng `count+64` và vòng so vé. Bước
này không phân biệt biên vòng so là `count` (theo hợp đồng) hay
`ArraySize`. Nội dung mảng không được ghi/so, chỉ có độ dài. Kiểm tiếp:
nhiều vị thế gồm vé 0, loại 0/1/2/-1 và hơn 64 vé được nhận; để vé cũ
còn ở phần sau `count` từ lần gọi trước để phân biệt biên; so mọi phần
tử đến `ArraySize`.

**F4 — Trung bình — thiếu kiểm.** `Bot1VirtualStops.mqh:82-89`,
`Smoke.mq5:45-49`. Nhánh bảng đầy và thông báo chưa chạy. Hàm giả có
kiểu tham số cố định và chỉ băm `slots/positions/ticket`. MQL5 tự đổi
kiểu ngầm, nên nếu nguồn đổi kiểu `slots` hoặc `positions` thì vẫn biên
dịch và cho cùng băm; bốn chuỗi không được kiểm. Kiểm tiếp: bảng 500
hàng đầy vé đang mở → một thông báo; gọi lại cùng vé → không thông báo;
vé khác → có thông báo; byte 0/2/255 → số ô 0/500/500; ghi kiểu và chữ
của đủ 7 đối số, so với `full-table-warning-schema.json`. Trong hàm giả
`PositionsTotal`, ghi lại vé đã báo lúc được gọi để kiểm thứ tự dòng 84–85.

**F5 — Thấp — chưa xác minh.** `Bot1VirtualStops.mqh:48,63,73,86`.
Nguồn đọc lại byte cho phép sau mỗi lời gọi ngoài. Hợp đồng chỉ nói rõ
thời điểm đọc ở bước 6 (sau `PositionsTotal`); chưa rõ bước 4 của mã gốc
đọc lại hay dùng giá trị đã đọc ở bước 1. Hai cách chỉ khác khi dữ liệu
đổi trong lời gọi ngoài, như bộ kiểm có thể làm. Kiểm tiếp: đổi byte,
`unit` và tên mã ngay trong lần trả `SymbolInfoInteger`.

**F6 — Thấp — chưa xác minh.** `Bot1VirtualStops.mqh:50,66,76,99,115`.
So số thực nên `-0.0` được xem là ô trống; NaN là ô đã dùng và không
bao giờ khớp vé. Hợp đồng không nói rõ `-0.0`/NaN ở cột vé. Kiểm tiếp:
cột vé có `-0.0`, NaN, cùng một vé ở hai hàng (phải khớp hàng đầu), vé
0, vé âm, vé `2^53+1` (đổi sang `double` bị làm tròn).

**F7 — Thấp — chưa xác minh.** `Bot1VirtualStops.mqh:100-105,116-117`.
Kết quả `(long)` của NaN/vô hạn/số quá lớn và phép trừ tràn `now-stamp`
phụ thuộc trình biên dịch MQL5, chưa có tài liệu hay phép đo. Dấu giờ
0.9 thành 0 nên trả đúng mà không đọc giờ (đúng chữ hợp đồng, chưa so).
Kiểm tiếp: dấu giờ NaN, ±vô hạn, 0.9, -1.5, 1e19; thời gian chờ 0 và âm;
đổi thời gian chờ trong lần trả `TimeCurrent` để kiểm đọc lại ở dòng 103.

**F8 — Thấp — chưa xác minh.** `Bot1VirtualStops.mqh:16,24-25,35`. Với
mảng đảo chỉ số (`ArraySetAsSeries`), sau khi mở rộng thì chỉ số của
phần tử cũ dịch đi, nên `open_tickets[count]` có thể đè vé đã ghi.
Nguồn chỉ khớp nếu mã gốc dùng cùng cách truy cập của MQL5 (hợp đồng nói
vậy); chưa có phép so. Kiểm tiếp: bật đảo chỉ số, hơn 64 vị thế, so nội
dung mảng và bảng.

**F9 — Trung bình — thiếu kiểm.** `Smoke.mq5:50-64`. Tệp nguồn chỉ được
biên dịch qua macro thay lời gọi; chưa có bản dựng nào biên dịch
`Bot1VirtualStops.mqh` với API MT5 thật. Kiểm tiếp: một tệp nhỏ chỉ
`#include` nguồn, không macro, yêu cầu 0 lỗi/0 cảnh báo.

**F10 — Thấp — chứng cứ công cụ.** `kiem-bang-dung-ao-bot-1.py:173-180`.
`compare` chỉ kiểm danh tính hai bản ghi chạy. Không so `result_sha256`
đã ghi với hai tệp kết quả, không đọc lại `script-status.bin`, không kiểm
`sequence/cases` của baseline. `comparison.json` không có danh tính
công cụ/nguồn và không có độ bao phủ 204/420. Kiểm tiếp: thêm các phép
so này và đưa danh tính, độ bao phủ vào `comparison.json`.

**F11 — Thấp — chứng cứ công cụ.** `kiem-bang-dung-ao-bot-1.py:151,160,165,169-171`.
Có ghi băm `terminal64.exe` trước/sau nhưng không bắt buộc bằng nhau
(lượt này bằng nhau). `errors==warnings==0` nhận cả `False`/`0.0`. Không
kiểm băm MetaEditor. Kiểm tiếp: bắt buộc trước = sau, kiểu `int`, so băm
MetaEditor.

**F12 — Thấp — chứng cứ công cụ.** `kiem-bang-dung-ao-bot-1.py:71,144-147`.
Kết quả gốc ghi không độc quyền (kiểm tồn tại rồi `write_bytes`) và ghi
trước bản ghi JSON. `executed` đếm địa chỉ đã chạy trong khoảng hàm,
chưa giao với danh sách lệnh của `analysis.json` và không liệt kê lệnh
chưa chạy. Kiểm tiếp: tạo tệp độc quyền; báo phần giao, phần thừa (phải
rỗng) và danh sách lệnh còn thiếu.

**F13 — Thông tin.** `kiem-bang-dung-ao-bot-1.py:92-94,126-129`,
`Smoke.mq5:73-81`. Byte cho phép luôn 1 và vé đã báo luôn 9 trong cả
bảy bước. Độ dài mảng phía gốc do câu trả lời giả của `ArrayResize` đặt
(64, đã có trong băm lời gọi). Ba trường này chỉ cho thấy không có lần
ghi ngoài dự kiến, chưa phải bằng chứng nhánh. Bản ghi chỉ gồm các
trường liệt kê, nên lần ghi vào ô dữ liệu khác không được so. Chuỗi
bước được viết cứng ở hai nơi (Smoke dòng 96–108, checker dòng 109–124),
không có tệp đầu vào chung để băm.

## Giới hạn

Rà nguồn này không thay phép so với bot gốc. Không xác nhận phần bảng
dừng ảo, P22 hay toàn bot đạt; không có tỷ lệ hoàn thành.
