# Bot3ManagementRealTakeCheck.mq5 — bản đề xuất

Trạng thái: **mã đã viết xong; chưa biên dịch, chưa chạy, chưa so kết quả** (yêu cầu
không cho chạy lệnh). Codex kiểm, ghép và chạy.

| Mục | Nội dung |
|---|---|
| Tệp đã viết | `Bot3ManagementRealTakeCheck.mq5`, `SUMMARY.md` (chỉ trong thư mục này; không sửa nguồn chính) |
| Vị trí khi ghép | `MQL5/Scripts/bot-cua-toi-3/`; đường include `../../Include/bot-cua-toi-3/...` |
| Hàm được gọi | `buy=1` → `Bot3AdvanceRealTakeBuy`, `buy=0` → `Bot3AdvanceRealTakeSell` |
| Cấu hình phiên | Mô hình `claude-opus-5-5` (theo thông tin hệ thống của phiên). Hệ thống báo Ultracode đang bật. Mức `max`: không tự kiểm được từ trong phiên. Không dùng tác tử khác hoặc Workflow |

## Nguồn đã đọc (chỉ để lấy giao diện và mẫu)

- Mẫu `bot-cua-toi-3/source/MQL5/Scripts/bot-cua-toi-3/Bot3ManagementRealTimedCheck.mq5`:
  cách đọc/ghi tệp, kiểm `CheckRun`, union lấy bit double, FNV-1a.
- `Bot3ManagementPrelude.mqh` (`Bot3ManagedPosition`), `Bot3ManagementMessages.mqh`
  (`Bot3PrintManagementError(const string &,uint &)`), `Bot3PositionClose.mqh`
  (`Bot3TryClosePosition`), `Bot3PositionModify.mqh`, các struct trong
  `Bot3PendingRequest.mqh` và `Bot3TradeSend.mqh`.
- Đã dò các header mà Prelude/Messages include: không có biến toàn cục, không có tên
  bắt đầu bằng `Take`, nên tiền tố `Take` của script không bị trùng.
- Không đọc: `Bot3ManagementRealTake.mqh` (chưa có trong `source/MQL5/Include/bot-cua-toi-3`),
  các bản đề xuất buy/sell khác, tài liệu phân tích lịch sử, EX5.

## Thứ tự include

Prelude, Messages → định nghĩa 5 macro → include `Bot3ManagementRealTake.mqh` → `#undef` cả 5.

## Tệp vào/ra

Thư mục `MQL5/Files/bot3-management-real-take/<CheckRun>/`; `CheckRun` dài 1..50, chỉ gồm `a-z`, `0-9`, `-`.

| Tệp | Phần đầu | Mỗi bản ghi (little endian, không đệm) |
|---|---|---|
| `cases.bin` (đọc) | `int32` `0x4d525033`, `1`, `count` (1..100000); kích thước phải đúng `12+count*244` | `<8i q Q 3I 23d` = 244 byte |
| `mql5-results.bin` (ghi) | cùng magic/version/count | `<3i 2I Q 23d i Q` = 224 byte |
| `script-status.bin` (ghi) | — | `int32 fault`, `int32 count` |

Vị trí byte trong một ca: 0 id · 4 buy · 8 scenario · 12 modify_ok · 16 error_code ·
20/24/28 digits0..2 · 32 ticket · 40 deviation · 48 strategy_index · 52 error_count ·
56 prior_changed · 60 sl · 68 tp · 76 open_price · 84 volume · 92 bid · 100 ask ·
108 unit · 116 distance · 124 start · 132 anchor · 140 gap · 148 freeze · 156 point ·
164 minimum · 172..236 volumes[0..8].

Vị trí byte trong một kết quả: 0 id · 4 returned · 8 changed · 12 final_index ·
16 error_count · 20 final_deviation · 28 sl · 36 tp · 44 open_price · 52 volume ·
60 bid · 68 ask · 76 unit · 84 distance · 92 start · 100 anchor · 108 gap · 116 freeze ·
124 point · 132 minimum · 140..204 volumes[0..8] · 212 event_count · 216 ordered_hash.
Mọi giá trị là giá trị cuối sau lời gọi hàm.

## Xử lý một ca

1. Đọc đủ 244 byte, rồi kiểm `id` đúng thứ tự, `buy` là 0/1, `scenario` 0..8,
   `strategy_index` 0..8, `prior_changed` 0/1. Sai thì đặt lỗi 9 và dừng; không gọi hàm,
   ca đó không có kết quả (các ca trước vẫn còn trong tệp).
2. Đặt lại: số sự kiện = 0, băm = `0xcbf29ce484222325`, digitindex = 0,
   `TakeState`/`TakeOptions` = 0 bằng `ZeroMemory`.
3. `position`: `ZeroMemory`, rồi lấy `sl, tp, open_price, volume` từ ca; các trường khác
   là 0/rỗng (kể cả `ticket_number`). `tick`: `ZeroMemory`, rồi lấy `bid, ask` từ ca.
4. Biến toàn cục truyền tham chiếu: `TakeUnit, TakeDistance, TakeStart, TakeGap, TakeFreeze,
   TakeTick, TakeVolumes[9], TakeIndex, TakeDeviation`. `anchor` là biến cục bộ truyền
   giá trị; `point`, `minimum` giữ giá trị của ca. `error_count` là biến cục bộ truyền
   tham chiếu; `changed=(prior_changed!=0)`.

## API giả (chỉ 5 macro quanh include)

| Macro thay | Hợp lệ khi | Sự kiện (5 `uint64`) | Mutate | Trả về |
|---|---|---|---|---|
| `SymbolInfoInteger` → `TakeSymbolInteger` | `"CHECK"`, `SYMBOL_DIGITS`, lần k = 0..2 | `(3,17,(ulong)(long)digits[k],k,0)`, rồi digitindex++ | lần 1→1, lần 2→3, lần 3→4 | `(long)digits[k]` |
| `SymbolInfoDouble` → `TakeSymbolDouble` | `"CHECK"`, `SYMBOL_POINT` | `(4,16,bits(point),0,0)` | 2 | `point` |
| | `"CHECK"`, `SYMBOL_VOLUME_MIN` | `(4,34,bits(minimum),0,0)` | 6 | `minimum` |
| `Bot3ModifyPosition` → `TakeModify` | luôn | `(5,ticket,bits(sl),bits(tp),(ulong)(long)modify_ok)` | 5 | `modify_ok!=0` |
| `Bot3PrintManagementError` → `TakeReport` | suffix là `"' when setting trailing Exit_TP.  Trying again!"` | `(10,(ulong)(long)error_code,error_count trước khi tăng,textHash(suffix),0)`, rồi `error_count++` (uint quay vòng) | 7 | — |
| `Bot3TryClosePosition` → `TakeTryClose` | state/options là tham chiếu đã cấp | `(6,ticket,deviation,bits(bid),bits(ask))` rồi `(7,bits(gap),bits(freeze),0,0)` | 8 (một lần, sau cả 2 sự kiện) | `true` |

Không hàm giả nào gửi lệnh, làm mới giá hoặc đọc thời gian/tài khoản.

`Mutate(target)` chỉ chạy khi `scenario==target`: `unit*=2; distance+=.5; start+=.25;
gap+=.125; freeze+=.25; tick.bid+=.25; tick.ask+=.5; index=(index+1)%9; deviation++`.
Không đổi volumes, point, minimum, anchor, position, error_count. `scenario=0` không làm
thay đổi gì.

Băm: mỗi sự kiện là 5 `uint64`, FNV-1a 64 từng byte little endian, nối tiếp trong cả ca
(nhân `0x100000001b3`). `event_count` = số sự kiện (TryClose tính 2). `textHash` = FNV-1a 64
trên UTF-16LE, bắt đầu riêng từ `0xcbf29ce484222325`.

## Mã lỗi

| Mã | Khi nào | Có `script-status.bin` |
|---|---|---|
| 0 | Không lỗi | có |
| 1 | `SymbolInfoInteger` sai symbol/property hoặc gọi quá 3 lần (trả 0, không ghi sự kiện) | có |
| 2 | `SymbolInfoDouble` sai symbol hoặc property khác `SYMBOL_POINT`/`SYMBOL_VOLUME_MIN` (trả 0.0, không ghi sự kiện) | có |
| 3 | `Bot3PrintManagementError` nhận suffix khác (vẫn ghi sự kiện, tăng đếm, Mutate 7) | có |
| 4 | `CheckRun` sai | không, chỉ mã trả về |
| 5 | Đã có `mql5-results.bin` hoặc `script-status.bin` | không |
| 6 | Không mở được `cases.bin` | không |
| 7 | Sai magic/version/count hoặc kích thước tệp | có (không tạo `mql5-results.bin`) |
| 8 | Không tạo được `mql5-results.bin` | có |
| 9 | Ca sai id/buy/scenario/strategy_index/prior_changed | có |
| 10 | Chưa đọc hết `cases.bin` | có |
| 11 | Không tạo được `script-status.bin` | không |
| 12 | `Bot3TryClosePosition` nhận state/options không phải tham chiếu đã cấp (vẫn ghi sự kiện) | có |

Lỗi 1, 2, 3, 12 không dừng vòng lặp. Lỗi 9 ghi đè mã lỗi trước đó. Lỗi 10 chỉ đặt khi chưa có lỗi.

## Chỗ mô tả chưa nói rõ — tôi đã chọn, cần Codex xác nhận

1. TryClose ghi **đối số nhận được** (`ticket`, `deviation`, giá thứ nhất/thứ hai, ngưỡng
   thứ nhất/thứ hai), đọc qua tham chiếu ngay lúc gọi, trước `Mutate(8)`. Nếu header truyền
   sai đối số thì băm sẽ lệch.
2. Cách kiểm tham chiếu state/options (chỉ ở TryClose, Modify không kiểm vì mô tả không yêu
   cầu): so `magic`/`log_level`, đảo bit 0 của `TakeState.magic` và `TakeOptions.log_level`,
   so lại qua tham chiếu, rồi trả giá trị cũ ngay. Kết quả cuối không đổi.
3. Lỗi 7 và 8 vẫn ghi `script-status.bin` (mẫu RealTimed chỉ trả mã 7/8), theo câu
   "Lỗi ghi trạng thái khác 0".
4. Không ghi đè: dừng nếu đã có một trong hai tệp kết quả. Vì vậy sau lượt lỗi 7 phải chạy
   lại với `CheckRun` mới.
5. Tên tệp kết quả `mql5-results.bin` lấy theo mẫu; mô tả không nêu tên.
6. Sự kiện dùng đúng hằng `17`, `16`, `34` như mô tả, không dùng `(ulong)property`.
7. Double đọc/ghi bằng `FileReadDouble/FileWriteDouble` như mẫu (không làm tròn, không
   `FileWriteString`).

## Codex cần kiểm khi ghép

- Biên dịch cùng `Bot3ManagementRealTake.mqh` thật, hướng tới 0 lỗi/0 cảnh báo. Header phải
  gọi `SymbolInfoInteger/Double` dạng 2 đối số. Header nào được include lần đầu bên trong
  `Bot3ManagementRealTake.mqh` cũng bị 5 macro thay.
- Các lời gọi khác của header (nếu có, ví dụ `TimeCurrent`, `PositionSelect…`, `GetLastError`)
  không bị thay; cần xác nhận header không dùng chúng.
- Bộ ca nên có NaN và −0 để xác nhận bit được giữ nguyên khi đọc/ghi.
- Mô hình đối chiếu của Codex phải theo đúng thứ tự sự kiện và Mutate trong bảng trên.
