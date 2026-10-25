# Bot3ManagementRealTimedCheck — tóm tắt

**Trạng thái:** mới viết mã. Chưa biên dịch, chưa chạy trong MT5, chưa so với EX5 gốc. Codex kiểm và ghép.

**Cấu hình lượt này:** mô hình theo thông tin phiên là `claude-opus-5-5`. Không tự kiểm được mức `max` từ bên trong phiên. Thông báo hệ thống ghi Ultracode bật; không dùng Workflow hay tác tử lồng (đề bài cấm, phiên cũng không có công cụ Workflow). Không chạy lệnh nào.

## Tệp đã ghi

- `Bot3ManagementRealTimedCheck.mq5`: script kiểm `Bot3AdvanceTimedBuyStop` / `Bot3AdvanceTimedSellStop` (`Bot3ManagementRealTimed.mqh:7-35`, `:37-69`) bằng API giả lập. Không giao dịch thật.
- Đường include `../../Include/bot-cua-toi-3/` chỉ đúng khi đặt script vào `MQL5/Scripts/bot-cua-toi-3/`.

## Include và macro (`.mq5:4-5`, `:62-72`)

1. Include `Bot3ManagementPrelude.mqh` và `Bot3ManagementMessages.mqh` trước macro, nên hàm thật trong hai tệp này không bị thay.
2. `#define`: `TimeCurrent`→`TTime`, `SymbolInfoInteger`→`TSymbolInteger`, `SymbolInfoDouble`→`TSymbolDouble`, `Bot3ModifyPosition`→`TModify`, `Bot3PrintManagementError`→`TReport`.
3. Include `Bot3ManagementRealTimed.mqh`; hai include bên trong nó bị guard bỏ qua. Sau đó `#undef` cả 5.
4. `Bot3RoundPrice` vẫn là hàm thật.

## Đầu vào

Thư mục: `MQL5/Files/bot3-management-real-timed/<CheckRun>/`. `CheckRun` dài 1..50 ký tự, chỉ `a-z`, `0-9`, `-`.

`cases.bin` (little-endian):

- Đầu tệp `<3i`: magic `0x4d525433`, version `1`, count `1..100000`.
- Kích thước tệp phải đúng `12 + 140*count` (`.mq5:87-88`).
- Mỗi case `<8i3qI10d`, 140 byte, đọc theo thứ tự (`.mq5:94-103`):
  `id, buy, scenario, modify_ok, error_code, digits0, digits1, delay_seconds` (int32);
  `ticket, now, opened` (int64);
  `error_count` (uint32);
  `sl, tp, bid, ask, unit, activation, distance, gap, freeze, point` (double).

Cách nạp mỗi case:

- Global, truyền tham chiếu để callback sửa: `TUnit`, `TDistance`, `TGap`, `TFreeze`, `TDelay`, `TTick` (ZeroMemory rồi gán bid/ask).
- Global chỉ để hàm giả đọc: scenario, modify_ok, error_code, digits[2], now, point.
- Local: `position` (ZeroMemory; `open_price=100.0`; `sl`, `tp`, `opened` theo case; không callback nào sửa), `activation`, `error_count`, `state`/`options` (ZeroMemory).
- Lời gọi (`.mq5:107-110`): buy=1 → `Bot3AdvanceTimedBuyStop`, buy=0 → `Bot3AdvanceTimedSellStop`, đối số `("CHECK", unit, activation, distance, delay, gap, freeze, position, tick, state, options, error_count, (ulong)ticket)`. Giá trị trả ghi vào `requested`.

## Đầu ra

`mql5-results.bin`:

- Đầu tệp `<3i`: magic, version, count chép từ input.
- Mỗi hàng `<3iI10QiQ` (108 byte; double đọc dạng bit), lấy giá trị sau lời gọi (`.mq5:111-117`):
  `id, requested, delay` (int32);
  `error_count` (uint32, ghi bằng `FileWriteInteger((int)...)`);
  `position.sl, position.tp, tick.bid, tick.ask, unit, activation, distance, gap, freeze, point` (double);
  `calls` (int32, số sự kiện trong case);
  `trace_hash` (uint64, ghi bằng `FileWriteLong`).
- Ghi từng trường theo thứ tự, không dùng `FileWriteStruct`.

`script-status.bin` `<2i`: `fault, count`. `count` là count ở đầu tệp input, giống các script kiểm cùng loại.

## Trace và hàm giả

FNV-1a 64: bắt đầu `0xcbf29ce484222325`; với mỗi byte: XOR rồi nhân `0x100000001b3`. Mỗi sự kiện gồm 5 ulong `[api,a,b,v,w]`, mỗi ulong 8 byte little-endian. `hash`, `calls`, chỉ số digits đặt lại đầu mỗi case. Hash chuỗi: cùng FNV-1a, trên byte UTF-16LE (byte thấp trước).

| api | Hàm giả | a | b | v | w | Trả về | scenario gây đổi |
|---|---|---|---|---|---|---|---|
| 9 | TimeCurrent | `(ulong)now` | 0 | 0 | 0 | `(datetime)now` | 1 |
| 3 | SymbolInfoInteger lần 1 | 17 | `(ulong)(long)digits0` | 0 | 0 | `(long)digits0` | 2 |
| 3 | SymbolInfoInteger lần 2 | 17 | `(ulong)(long)digits1` | 1 | 0 | `(long)digits1` | 4 |
| 4 | SymbolInfoDouble | 16 | `bits(point)` | 0 | 0 | `point` | 3 |
| 5 | Bot3ModifyPosition | `ticket` | `bits(sl)` | `bits(tp)` | `(ulong)(long)modify_ok` | `modify_ok!=0` | 5 |
| 10 | Bot3PrintManagementError | `(ulong)(long)error_code` | `(ulong)counter` trước khi tăng | hash UTF-16LE của suffix | 0 | không; `counter++` (uint32 cuộn) | không có |

- Thay đổi chỉ chạy khi `scenario` bằng số ở cột cuối, sau khi ghi sự kiện: `unit*=2`, `distance+=0.5`, `gap+=0.125`, `freeze+=0.25`, `tick.bid+=0.25`, `tick.ask+=0.5`, `delay=(int)((uint)delay+1)`. Không đổi activation, point, position, now. Scenario 0: không đổi gì.
- Report không gọi `Print`/`GetLastError` thật. Thân hàm báo lỗi thật được kiểm riêng.

## Thứ tự API theo header hiện tại

Đọc từ `Bot3ManagementRealTimed.mqh`, không phải kết quả chạy. Mỗi bước chỉ tới được khi các điều kiện trước đó qua.

- Buy: TimeCurrent `:14` → SymbolInfoInteger lần 1 `:18` → SymbolInfoDouble `:19` → SymbolInfoInteger lần 2 `:24` → Bot3ModifyPosition `:29` → Bot3PrintManagementError `:32` (chỉ khi Modify trả false).
- Sell: TimeCurrent `:44` → SymbolInfoDouble `:50` → SymbolInfoInteger lần 1 `:56` → SymbolInfoInteger lần 2 `:59` → Bot3ModifyPosition `:65` → Bot3PrintManagementError `:66` (chỉ khi Modify trả false).

## Mã lỗi

Mã trả của `OnStart` khi dừng sớm, không ghi `script-status.bin`:

- 4: `CheckRun` sai.
- 5: `mql5-results.bin` đã có; không ghi đè.
- 6: không mở được `cases.bin`.
- 7: magic/version/count sai hoặc kích thước tệp sai; đã đóng handle input.
- 8: không mở được `mql5-results.bin`; đã đóng handle input.
- 11: không mở được `script-status.bin`.

`fault` trong `script-status.bin` (không đặt lại giữa các case; mã sau đè mã trước; `OnStart` trả về `fault`):

- 1: SymbolInfoInteger gọi với symbol khác `"CHECK"`, property khác `SYMBOL_DIGITS`, hoặc lần gọi thứ 3 trong một case. Trả 0, không ghi sự kiện, không gây đổi.
- 2: SymbolInfoDouble gọi với symbol khác `"CHECK"` hoặc property khác `SYMBOL_POINT`. Vẫn ghi sự kiện và trả `point`.
- 3: suffix của Report khác đúng chuỗi `' when setting trailing Exit_TrailSL_after_X_Minutes_size_ loss.  Trying again!` (hai dấu cách trước `Trying`). Vẫn ghi sự kiện và tăng counter.
- 9: `id≠i`, `buy` không phải 0/1, hoặc `scenario` ngoài 0..5. Dừng vòng lặp, không ghi hàng đó.
- 10: sau vòng lặp, vị trí đọc khác kích thước tệp.

## Giới hạn

- Chưa biên dịch, chưa chạy, chưa có kết quả so với EX5.
- Script không tự tính kết quả mong đợi; bên kiểm phải tự dựng mô hình để so từng hàng.
- Không kiểm thân thật của `Bot3ModifyPosition` và `Bot3PrintManagementError`; chỉ ghi lại lời gọi.
- Không kiểm phạm vi của `modify_ok`, `error_code`, `digits0/1`, `delay_seconds`.
- Khi `fault=9`, số hàng trong `mql5-results.bin` ít hơn `count` trong status.
- Không có tệp Python kiểm; việc này không được giao.

Các lựa chọn cần Codex xác nhận:

1. Kiểm kích thước tệp ngay sau đầu tệp (trả 7), và vẫn giữ kiểm `FileTell` cuối (`fault=10`) như các script cùng loại.
2. Viết `(ulong)(long)modify_ok`: mở rộng dấu rõ ràng; với int thì bằng `(ulong)modify_ok`.
3. Ghi hằng 17/16 vào trace đúng như đặc tả, thay vì `(ulong)property`. Hai cách chỉ khác nhau nếu `SYMBOL_DIGITS≠17` hoặc `SYMBOL_POINT≠16`.
4. Khi vi phạm, SymbolInfoInteger giả trả 0 và không ghi sự kiện, giống `Bot3ManagementVirtualLevelsCheck.mq5`.
5. Chỉ kiểm sự tồn tại của `mql5-results.bin` trước khi ghi, giống các script cùng loại. Trong script này, status chỉ được ghi sau khi đã tạo tệp kết quả.
