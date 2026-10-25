# Bộ kiểm phần đầu quản lý bot 3 — bản đề xuất

**Trạng thái: chưa biên dịch, chưa chạy native, chưa chạy MQL5, chưa có kết quả so.**
Không có số "đạt" nào. `prefix_only=true`, `whole_manager_complete=false`,
`whole_bot_complete=false`. Tôi chỉ dùng Read/Glob/Grep/Write, chỉ ghi trong thư
mục này, không chạy lệnh, không mở EX5/C/capture.

## Tệp

| Tệp | Codex chép tới | Ghi chú |
|---|---|---|
| `Bot3ManagementPreludeCheck.mq5` | `bot-cua-toi-3/source/MQL5/Scripts/bot-cua-toi-3/` | Macro thay API chỉ nằm ở đây |
| `check-management-prelude.py` | `bot-cua-toi-3/tests/` | `HOME=parents[1]`, `ROOT=HOME.parent` |
| header của Claude khác | `.../Include/bot-cua-toi-3/Bot3ManagementPrelude.mqh` | Phải có trước `prepare` |

## Chỗ nối với header

Viết theo header ứng viên đang có ở
`claude-thuc-hien/bot3-management-prelude-20261025-r2/Bot3ManagementPrelude.mqh`
(đọc lúc viết). Trong `OnStart` chỉ có ba lời gọi:

- `Bot3ReadManagementPosition(0,buy,ExpectedMagic,Enabled,TestSymbol,LastTicket,TestTick,position)`
- `Bot3FillManagementInitialLevels(buy,TestSymbol,Unit,Stop,Take,position,state,options)` khi đọc được nhận
- `Bot3CloseManagementCandle(buy,TestSymbol,group,CandleOn[group],Timeframes[group],Shift,position,TestTick,state,options,Deviation,ThresholdA,ThresholdB)` với group 0,1,2

Header đổi chữ ký thì chỉ sửa ba dòng này. Header đổi nội dung thì SHA nguồn
đổi và công cụ dừng `..._IDENTITY_CHANGED`; cần lượt mới.

## Giao thức

- `cases.bin`: magic `0x4d505233`, version 1, count `<3i`. Mỗi ca
  `<3iQ2q2i5i7d3i2dq6q7i9d` rồi 3 chuỗi `<2i`(cờ NULL, số đơn vị UTF-16) +
  UTF-16LE: symbol, position_symbol, comment. Chuỗi NULL phải rỗng.
- Kết quả mỗi ca `<iiQi5Q3q2Q2i2QiQ`, 20 trường như bot1. sl/tp ghi sau bổ sung
  mức. Vé 0: mọi trường position bằng 0, hai cờ NULL bằng 1.
- Sự kiện 5×uint64, băm FNV-1a theo thứ tự: 1 digits, 2 ticket, 3 PositionDouble,
  4 Integer, 5 String, 6 Tick, 7 Print, 8 Modify(vé,sl,tp), 9 TryClose(vé),
  10 iTime, 11 iClose, 12 iOpen. Modify giả trả `false`; TryClose giả chỉ ghi vé.
- Giờ/giá nến được dùng tuần tự theo thứ tự gọi (6 giờ, 6 close, 3 open) như bot1.

## Ánh xạ native trong công cụ (lấy từ TASK và contract r2, chưa chạy)

| Mục | Mua | Bán |
|---|---|---|
| Bắt đầu hàm | `0x32f60` | `0x37590` |
| Dừng nhận | `0x33b73` | `0x38194` |
| Dừng loại | `0x330a0/0x330a3/0x330ca` | `0x376d0/0x376d3/0x376f7` |
| Mô tả symbol vị thế | `RSP+0x80` | `RSP+0x58` |

Chung: comment `RSP+0x90`; sl XMM8, tp XMM7, vé XMM9, open XMM6, volume XMM13;
opened/type/magic lấy từ ca (theo TASK). Biến: magic `0x6d564`, enabled
`0x6d520` (int32), stop `0x6d588`, take `0x6d590`, unit `0x73dd8`, cờ
`0x6d29e/0x6d2a0/0x6d2a2`, khung `0x6d29d/0x6d29f/0x6d2a1`, shift `0x6d29c`,
symbol `0x74958`, last_ticket `0x74838` (đọc lại từ bộ nhớ sau chạy), tick
`0x74790` (+8/+16), scratch double `0x1d6e48`, string `0x1d6e3c`. API dùng RVA
engine như mẫu bot1; PositionsTotal trả 1, không ghi sự kiện. Con `0x32a90`=8
(RCX, XMM1, XMM2) và `0x47d20`=9 (RCX) được chặn, trả 0, không chạy.

Trước khi chạy, công cụ kiểm: đầu mã `0x17156250000`; SHA EX5 gốc trong
`analysis.json` và `native-boundaries.json`; `analysis_sha256`, `contract_sha256`
trong `native-boundaries.json`; byte các hàm trong `analysis.json`; từng đoạn:
lệnh liền nhau, đúng số lệnh, đúng byte và SHA; hai chuỗi Print; hai hằng làm tròn.

## Nhóm ca (tính tay: 318 mỗi chiều, 636 tổng; số thật do `prepare` in ra)

| Nhóm | Mỗi chiều | Phân biệt |
|---|---|---|
| `initial-levels-ticket64` | 24 | sl/tp 0 hoặc có, vé 0/1/2^53+1/2^63−1/2^63/2^64−1 qua Modify và TryClose |
| `filter-type-low32`, `filter-magic-low32`, `filter-enabled` | 7, 11, 6 | type/magic so thấp 32 bit, enabled đúng 1 |
| `symbol-null-and-unicode`, `comment-null-and-unicode` | 13, 4 | NULL/rỗng, hoa thường, dấu cách, chữ Việt, emoji, chuỗi dài |
| `numeric-*`, `numeric-volume` | 54, 3 | ±inf, ±1e19, ±0, NaN, sát làm tròn trong công thức |
| `nan-payload-operand-order` | 6 | Hai/ba NaN khác payload: thứ tự toán hạng |
| `digits-low32-clamp`, `digits-five-reads` | 6, 12 | Chặn 11 theo uint32, năm lần đọc digits khác nhau |
| `candle-flag-byte`, `candle-frame-shift` | 9, 21 | Từng nhóm: cờ 0/2/255, khung 0/1/2/255, shift 0/1/2/255 |
| `candle-time-boundaries`, `candle-time-signed` | 18, 9 | `previous>opened`, `opened>=current`, so có dấu |
| `candle-body-boundaries`, `candle-level-boundaries`, `close-reread` | 27, 18, 15 | `<` có thứ tự, NaN, ±0, close đọc lại khác |
| `three-groups-all-close` | 12 | Cả ba nhóm đóng; shift dùng chung, khung từng nhóm |
| `group-exit-independent`, `group-flag-independent`, `group-random-outcomes` | 15, 6, 12 | Nhóm này thoát, nhóm sau vẫn chạy |
| `tick-failure-continues` | 10 | Tick lỗi vẫn Print rồi lọc tiếp, tick giữ giá trị cũ |

Các phép biên nến lặp cho cả ba nhóm vì theo contract mỗi nhóm dùng byte cờ,
byte khung và ánh xạ khung riêng.

## Kiểm thêm so với mẫu bot1 (nhỏ, không đổi giao thức so)

- MQL5: Fault 9 nếu TryClose nhận deviation/bid/ask/threshold khác giá trị
  script truyền và tick hiện tại; Fault 19 nếu gọi thẳng `Bot3ClosePosition`;
  Fault 26/29/20/27 cho tiêu đề ca, byte ngoài 0–255, chuỗi sai, chưa đọc hết tệp.
- Python: hook cũ của `entry.Original` bị đặt thành `UNEXPECTED_API`; dừng loại
  trước khi đọc vé → `BOUNDARY_BEFORE_TICKET`; chỉ số vé khác 0 hoặc đọc vé lần
  hai → `BAD_TICKET_CALL`; Print phải là một trong hai chuỗi; con phải được gọi
  từ trong đoạn; mỗi ca xóa ngăn xếp, đặt lại EFLAGS/MXCSR; giới hạn số lần đọc.
- Báo phủ lệnh từng đoạn (đã chạy/tổng, danh sách thiếu); không bắt buộc 100%.

## Giới hạn, chưa kiểm

- Chưa chạy bước nào; mọi kết quả còn trống.
- TryClose: native chỉ so vé. Deviation/bid/ask/threshold chỉ kiểm phía MQL5
  (Fault 9), vì `0x47d20` đọc biến toàn cục.
- "Lấy last_ticket sau tp" chưa phân biệt được: theo TASK `scenario=0`, không
  API nào đổi last_ticket giữa chừng.
- opened/type/magic phía native lấy từ ca nên chỉ chứng minh MQL5 lưu đúng.
- iTime/iClose/iOpen/tick chỉ băm tên symbol, không có cờ NULL (như bot1).
- Nếu chỉ nhóm `nan-payload-operand-order` lệch: đối chiếu thứ tự toán hạng
  trong nguồn trước; có thể do trình biên dịch đổi thứ tự phép nhân. Không nới
  phép so; cần phân tích tiếp.
- Nếu phần trước `0x330f1/0x3771e` gọi API ngoài TASK, công cụ dừng
  `UNEXPECTED_API` hoặc lỗi bộ nhớ; Codex bổ sung ánh xạ khi đó.
- Chưa kiểm vòng ngoài, PositionsTotal, nhiều vị thế, ghép helper thật, dời
  dừng, bảng, chế độ, UI, lưu trạng thái, lỗi cấp phát, khởi động lại, EA chính.

Tôi đã mở `native-boundaries.json` để biết khóa JSON; trang đầu có danh sách
lệnh máy. Tôi không dùng nó để suy luật; công cụ dùng tệp này để ràng buộc
byte và đo phủ.

## Lệnh cho Codex (sau khi chép header, script và công cụ)

```powershell
$test='dich-nguoc/khoi-phuc/bot-cua-toi-3/tests'
python -I -B -X utf8 "$test/check-management-prelude.py" prepare NEW_RUN
& 'dich-nguoc/khoi-phuc/cong-cu/bien-dich.ps1' -Bot 3 -Terminal 'dich-nguoc/.local/mt5-bot3-thread-20261025' -Run NEW_BUILD -Source 'dich-nguoc/khoi-phuc/bot-cua-toi-3/source/MQL5/Scripts/bot-cua-toi-3/Bot3ManagementPreludeCheck.mq5'
python -I -B -X utf8 "$test/check-management-prelude.py" mql5 NEW_RUN --build NEW_BUILD
python -I -B -X utf8 "$test/check-management-prelude.py" original NEW_RUN
python -I -B -X utf8 "$test/check-management-prelude.py" compare NEW_RUN
```

Đầu ra: `bot-cua-toi-3/bang-chung/kiem-quan-ly-vi-the/NEW_RUN/` (không ghi đè).
`mql5` kiểm biên nhận: đúng target, errors/warnings là số nguyên 0, SHA EX5 khớp
bản trong máy thử và bản riêng trong `bang-chung/bien-dich/NEW_BUILD/`, nguồn
khớp; chạy với giao dịch và DLL tắt; `script-status.bin` phải là `(0,count)`.
