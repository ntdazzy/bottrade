# Tóm tắt — `Bot3FinishVirtualManagement` bot 3 (r1)

Trạng thái thật: **chỉ là ứng viên. Chưa biên dịch, chưa chạy, chưa so với
EX5 gốc; không có ca kiểm nào.** Chỉ ghi `Bot3ManagementVirtualFinishFlow.mqh`
và tệp này (`TASK.md` giữ nguyên). Không sửa `bot-cua-toi-3/source/`, không
chạy lệnh, không dùng Git, MT5 hay tác tử lồng. Không đọc EX5/mã máy.

Logic chỉ lấy từ [TASK.md](TASK.md). Chữ ký hàm con lấy từ nguồn chính
`bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/`:
`Bot3ManagementVirtualFinish.mqh:23–28, 51–55, 116–119` và
`Bot3PositionClose.mqh:31–33`.

## Điều đã giữ

Số dòng là dòng trong [Bot3ManagementVirtualFinishFlow.mqh](Bot3ManagementVirtualFinishFlow.mqh).

| Đặc tả | Mã |
|---|---|
| Chỉ include `Bot3ManagementVirtualFinish.mqh`; guard riêng | :3–5 |
| `bool`, 23 tham số đúng thứ tự, kiểu, `const`/`&` như TASK.md:6–13 | :9–18 |
| 1. `Bot3AdvanceVirtualHighLow(...)`, 12 đối số đúng thứ tự | :20–21 |
| 2. `Bot3AdvanceVirtualBreakEvenCounter(...)`, 13 đối số; gọi vô điều kiện ngay sau bước 1, không xét `changed` | :22–24 |
| 3. Sau hai bước mới so: mua `current_level>=tick.bid`, bán `tick.ask>=current_level`; so có thứ tự, viết thẳng trong `if`, không tạo biến cờ | :25 |
| Chạm: `SymbolInfoTick(symbol,tick)` một lần, bỏ bool → `Bot3TryClosePosition(state,options,deviation,tick.bid,tick.ask,gap,freeze,(ulong)ticket)` → `return true` | :27–29 |
| 4. Không chạm: `Bot3StoreVirtualLevels(symbol,initial_stop,initial_take,current_level,current_take,(double)ticket,table)` → `return false` | :31–33 |
| Không đặt lại `changed`/`counter`, không cờ tổng, không vòng vị thế, không `Print`, không hỏi khối lượng, không gọi `Bot3ClosePosition`, không kiểm mảng, không `NormalizeDouble` | toàn hàm |
| Không viết lại ba hàm con có sẵn | toàn tệp |

## Thứ tự đọc/ghi

1. Trước bước 1 hàm không tự đọc gì. `tick`, `unit`, `gap`, `freeze`,
   `settings`, `copied_step`, `levels`, `strategy_index`, `current_level`,
   `changed`, `counter` được chuyển nguyên tham chiếu vào hàm con, nên các
   lần đọc trước/sau API vẫn nằm đúng chỗ bên trong hàm con.
2. Phép so chạm đọc `current_level` và `tick.bid`/`tick.ask` sau khi bước 2
   trả về; không có API xen giữa. Trước phép so không làm mới `tick`.
3. Nhánh chạm: `SymbolInfoTick` ghi `tick` trước. `tick.bid`, `tick.ask`,
   `gap`, `freeze` (`const double &`) và `deviation` (`const ulong &`) truyền
   theo tham chiếu, nên `Bot3TryClosePosition` đọc giá đã làm mới tại chỗ đọc
   của nó. Sau đó trả về ngay, không lưu bảng.
4. Nhánh không chạm: `current_level`, `current_take` truyền theo
   `const double &`; `Bot3StoreVirtualLevels` tự đọc chúng sau các lần gọi
   `SymbolInfoInteger(SYMBOL_DIGITS)`.
5. Hàm này không tự ghi biến nào. Mọi lần ghi nằm trong hàm con hoặc API:
   `current_level`, `changed`, `counter` (bước 1–2), `tick` (`SymbolInfoTick`),
   `state`/`options` (đóng), `table` (lưu).

## Kiểu số

- `ticket` là `long` nhận theo giá trị. `(ulong)ticket` giữ nguyên bit khi
  đưa vào `Bot3TryClosePosition`.
- `(double)ticket` là đổi có dấu từ `long`, không qua `ulong`. Vì `ticket` là
  `const` theo giá trị, đổi ngay tại lời gọi cho cùng giá trị với bản đã đổi
  trước đó.
- Giá, mức dừng/chốt: `double`; `counter`: `int`; `changed`: `bool`;
  `strategy_index`: `uint` (chỉ chuyển tiếp).
- Hàm này không làm tròn. Làm tròn bằng `Bot3RoundPrice(...,(uint)digits)`
  nằm trong `Bot3StoreVirtualLevels`.

## Điểm còn thiếu, cần Codex kiểm

1. Chưa biên dịch. Include tương đối: phải đặt tệp cạnh
   `Bot3ManagementVirtualFinish.mqh` trong `Include/bot-cua-toi-3/`. Cần xem
   bỏ bool `SymbolInfoTick` có cảnh báo không (cùng dạng
   `Bot3ManagementVirtualStart.mqh:32`).
2. Chưa đo cách MQL5 dịch `>=` khi có NaN. Mã giữ đúng chiều trong đặc tả để
   NaN không vào nhánh đóng; nếu trình dịch đảo toán hạng sang dạng so không
   có thứ tự thì kết quả có thể khác.
3. Chưa rõ `tick` ra sao khi `SymbolInfoTick` trả false (hành vi API MT5).
   Đặc tả bảo bỏ bool; mã không xử lý thêm.
4. Đặc tả không ghi địa chỉ native của hàm/tham số, nên tệp không ghi địa chỉ.
   Bên gọi khi ghép phải cấp đúng biến cho từng tham số.
5. Chưa có bộ kiểm. Ca nên có: mua/bán chạm và không chạm; bằng nhau ở biên
   (`current_level==tick.bid`, `tick.ask==current_level` → chạm); NaN ở
   `current_level`, bid, ask → không chạm, đi lưu bảng; bước 1/2 đổi
   `current_level` làm đổi kết quả chạm; `changed` đã true từ trước (bước 2
   vẫn được gọi); giá sau `SymbolInfoTick` khác giá lúc so; vé âm hoặc lớn
   hơn 2^53 cho `(ulong)`/`(double)`; nhánh chạm không gọi
   `Bot3StoreVirtualLevels`; hàm không đặt lại `changed`/`counter`.
6. Ba hàm con tôi không kiểm lại; `Bot3ManagementVirtualFinish.mqh:1` ghi cần
   so lúc chạy trước khi dùng trong EA.
7. Hàm cùng dạng của bot 1 (`Bot1FinishVirtualManagement`,
   `bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/Bot1ManagementVirtualFinish.mqh:125–149`)
   có cùng thứ tự bước 1 → 2 → so → đóng/lưu. Chỉ để tham khảo, không phải
   bằng chứng cho bot 3.

## Phụ thuộc

- `Bot3ManagementVirtualFinish.mqh`: `Bot3VirtualFinishSettings`,
  `Bot3AdvanceVirtualHighLow`, `Bot3AdvanceVirtualBreakEvenCounter`,
  `Bot3StoreVirtualLevels`. Qua include của nó: `Bot3ManagedPosition`
  (Prelude), `Bot3VirtualStopState` (VirtualStops), `Bot3TryClosePosition`
  (PositionClose), `Bot3PendingRequestState`, `Bot3TradeSendOptions`.
- API MT5 gọi trực tiếp trong hàm: chỉ `SymbolInfoTick`.

## Cấu hình phiên

Mô hình theo thông tin hệ thống: `claude-opus-5-5`; phiên ghi "Ultracode is
on". Mức `max` không tự kiểm được. Phiên không có công cụ Workflow; không
dùng tác tử phụ (TASK.md cấm tác tử lồng). Chỉ dùng Read/Grep/Glob/Write và
tự rà từng bước đặc tả với mã.
