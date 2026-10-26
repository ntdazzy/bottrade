# Bot3PendingSubmissionCheck: đề xuất bộ kiểm khối đặt lệnh chờ

## Trạng thái

- Tôi **không tự biên dịch, không chạy** hai Script; chưa so với bản gốc. Script không tính
  kết quả mong đợi và không tự kết luận đạt.
- Lúc bắt đầu chưa có `Bot3PendingSubmission.mqh` (tìm `Bot3PendingSubmission*` không thấy),
  nên mã viết theo giao diện trong TASK sản phẩm. Trong lúc làm, header xuất hiện ở
  `../bot3-pending-submission-20261026-r2/`; tôi đã đọc: struct và chữ ký khớp TASK, chỉ nạp
  đúng sáu header phụ thuộc, các lời gọi bị chặn dùng đúng dạng hàm giả (`SymbolInfoInteger`
  2 tham số, `Print` một chuỗi, `Sleep(2500)`), không có tên trùng với Script.
- Bằng chứng do Codex lưu, tôi chỉ đọc: `bot-cua-toi-3/bang-chung/bien-dich/b3-submission-check-20261026-r2/bien-nhan.json`
  ghi `errors 0`, `warnings 0` (`exit_code` 1), dòng `Result: 0 errors, 0 warnings` cho
  `Scripts/bot-cua-toi-3/Bot3PendingSubmissionCheck.mq5`; log biên dịch trong
  `.local/mt5-bot3-thread-20261025/MQL5/Scripts/bot-cua-toi-3/` ghi cùng kết quả. Bản trong
  nguồn chính giống hệt tệp đề xuất này (đọc so từng dòng; không tính lại SHA-256). Tôi đã
  sửa thử một dòng `const` rồi hoàn lại, nên tệp cuối trùng bản đã biên dịch.
- Chưa thấy bằng chứng biên dịch `Bot3PendingSubmissionApiCompile.mq5` (chưa có trong nguồn
  chính). Tôi không đọc kết quả chạy trong `bang-chung/kiem-quan-ly-vi-the/b3-pending-submission-20261026-r2/`.
- Chỉ ghi 3 tệp trong thư mục này. Không sửa nguồn chính, Git hay MT5; không chạy lệnh;
  không tạo tác tử; không đọc EX5, mã máy hay phân tích.
- Cấu hình lượt: thông tin hệ thống ghi mô hình Opus 5.5 (`claude-opus-5-5`) và Ultracode
  bật; tôi không tự kiểm được mức `max`. Lượt này không có công cụ workflow và TASK cấm
  tạo tác tử, nên làm một mình.

## Nguồn đã đọc (từ `dich-nguoc/`)

- `AGENTS.md`, `khoi-phuc/tai-lieu-cu/QUY-TRINH.md`.
- `khoi-phuc/claude-thuc-hien/bot3-pending-check-20261026-r2/TASK.md` (việc này);
  `../bot3-pending-submission-20261026-r2/TASK.md` và `Bot3PendingSubmission.mqh` (sau khi có).
- Sáu header phụ thuộc trong `khoi-phuc/bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/`:
  `Bot3PriceLevels`, `Bot3Margin`, `Bot3VolumeValidation`, `Bot3OrderScan`, `Bot3TradeSend`,
  `Bot3TradeErrors`; và các tệp chúng nạp: `Bot3TradeMessages`, `Bot3PendingRequest`,
  `Bot3Filling`. Lấy chữ ký thật và tên guard; các tệp này không có biến toàn cục.
- Hai mẫu: `Scripts/bot-cua-toi-3/Bot3ManagementBarGateCheck.mq5`, `Bot3PreparationApiCompile.mq5`.
- Quy ước của Script đã có (cùng thư mục Scripts): `Bot3PendingQueueCheck.mq5` (giả
  `Bot3OpenPending`, `GetLastError`, `Sleep`, `Print` định nghĩa **sau** header gọi chúng);
  `Bot3ManagementRealBlocksCheck.mq5` dòng 1–135 (union, FNV, giả Digits gọi quá số lần thì
  `Fail` và trả 0, không ghi sự kiện); `Bot3ManagementPreludeCheck.mq5` dòng 130–189 (đọc chuỗi
  bằng `ShortToString`). Tìm dòng `SHORT_VALUE`, `#define …`, `[][2]`, `ArrayInitialize(`.
- Bằng chứng biên dịch nêu ở trên và bản `Bot3PendingSubmissionCheck.mq5` trong nguồn chính (để so).
- `claude-thuc-hien/bot3-newbar-check-20261026-r1/SUMMARY.md` (cách trình bày).

## Script `Bot3PendingSubmissionCheck.mq5` (đích `Scripts/bot-cua-toi-3/`)

Thứ tự nạp:

1. Sáu header phụ thuộc thật, trước mọi macro. Guard của chúng chặn lần nạp lại bên
   trong header sản phẩm, nên các hàm này giữ lời gọi thật. `Bot3RoundPrice` thật.
2. `#define` 9 tên: `SymbolInfoInteger`→`FakeSymbolInfoInteger`, `Bot3MarginGuard`→`FakeMarginGuard`,
   `Bot3ValidateVolume`→`FakeValidateVolume`, `Bot3AllowsPendingOrder`→`FakeAllowsPendingOrder`,
   `Bot3OpenPending`→`FakeOpenPending`, `Sleep`→`FakeSleep`, `GetLastError`→`FakeGetLastError`,
   `Bot3TradeErrorText`→`FakeTradeErrorText`, `Print`→`FakePrint`.
3. `../../Include/bot-cua-toi-3/Bot3PendingSubmission.mqh`, rồi `#undef` cả 9 tên.
4. Sau đó mới khai báo biến kiểm và định nghĩa hàm giả (cần kiểu settings). `Print` cuối
   `OnStart` là `Print` thật.

Mỗi ca, sau khi đã đọc và kiểm xong bản ghi:

- `ZeroMemory` S, T, O; chép 14 trường settings từ ca (3 cờ ép `uchar`, expiration ép
  `datetime`); `Index=strategy_index`, `Errors=(uint)error_count`, `FakeLastError=0`.
- `V[i]=0.125*(i+1)`; `T.magic=0x0123456789abcdef`; `O.async_mode=2`, `log_level=3`, `margin_mode=1`.
- Mọi bộ đếm về 0, `Hash=0xcbf29ce484222325`.
- `Table` (đổi cỡ 100 hàng một lần đầu `OnStart`): cột 0 `1000.0+i`, cột 1 `2000.0+i`; rồi
  cache_mode 0 đưa cả bảng về `0.0`; 1 `[50][0]=+0.0`; 2 `[99][0]=+0.0`; 3 giữ đầy;
  4 `[0][0]` NaN `0x7ff8…`, `[1][0]` `-0.0`; 5 `[0..3][0]` = `+inf`, `-inf`, NaN, `-0.0`.
  Các giá trị đặc biệt lấy từ bit qua union.

`ApplyMutation(trigger)`: chỉ chạy khi `mutation_at==trigger` và `MutationCount==0`. Ghi
sự kiện 9 (word trigger) trước, `MutationCount++`, rồi đổi đúng danh sách TASK (symbol,
comment, unit, stop/take, expiration, magic, cờ omit đảo 0↔255, virtual_expiration 255,
`Index=(Index+1)%9`, `V[i]=0.25*(i+5)`, ask/bid = `base_price∓5.0` của ca, freeze 2.125,
stop 1.25, T.magic, O.*). `check_free_margin` không đổi.

Hàm giả (kind là word đầu sau `BeginEvent`; mọi word lấy từ **đối số**, chuỗi băm FNV riêng
theo từng đơn vị UTF-16):

| kind | Hàm | Word sau kind | Sau sự kiện | Trả |
|---|---|---|---|---|
| 1 | `FakeSymbolInfoInteger(symbol,prop)` | prop, symbol_hash, reply | `DigitsCalls++`, mutation 1/2/3 theo lần | digit0/1/2 ép long |
| 2 | `FakeMarginGuard(symbol,type,volume)` | symbol_hash, type, bit volume, margin_reply | `MarginCalls++`, mutation 4 | margin_reply≠0 |
| 3 | `FakeValidateVolume(symbol,volume)` | symbol_hash, bit volume, volume_reply | `VolumeCalls++`, mutation 5 | volume_reply≠0 |
| 4 | `FakeAllowsPendingOrder()` | limit_reply | `LimitCalls++`, mutation 6 | limit_reply≠0 |
| 5 | `FakeOpenPending` (chữ ký thật) | type, bit volume/price/sl/tp, expiration, magic, virtual_expiration, symbol_hash, comment_hash, state.magic, options.async_mode/log_level/margin_mode, reply | `SendCalls++`; lỗi = initial_error (ordinal 0), final_error (ordinal≥retry_count), còn lại 132; mutation 7 (ordinal 0), 9 (ordinal 1) | initial_accept (ordinal 0), bit ordinal−1 của retry_accept_mask |
| 6 | `FakeSleep(milliseconds)` | milliseconds | `SleepCalls++`, mutation 8 chỉ lần đầu; không ngủ | — |
| 7 | `FakeTradeErrorText(code,counter)` | code, counter cũ, counter mới, text_hash | `ErrorCalls++` | `"error-"+code` |
| 8 | `FakePrint(text)` | text_hash | `PrintCalls++` | — |
| — | `FakeGetLastError()` | không ghi sự kiện | — | `FakeLastError` |

Số có dấu ép qua `long` sang `ulong`; double lấy bit qua union; không chuẩn hóa NaN/−0.

Tệp trong `Files/bot3-pending-submission/<CheckRun>/`:

| Tệp | Bố cục |
|---|---|
| `cases.bin` (vào) | `<3i`: magic `0x50534233`, version 1, count 1..10000. Mỗi ca: 22 int32 theo TASK, 1 int64 expiration, 8 double, rồi symbol và comment (int32 số đơn vị 0..128 + đúng số `ushort`). Không kiểm cỡ cố định; cuối phải `FileTell==FileSize` |
| `mql5-results.bin` (ra) | `<3i` chép đầu vào. Mỗi ca 1936 byte: int32 id, int32 Fault, 241 word (`FileWriteLong`): 14 bộ đếm/trạng thái, 14 settings, 4 trade/options, 9 bit V, 200 bit Table theo hàng rồi cột |
| `script-status.bin` (ra) | `<2i`: Fault đầu tiên, count trong đầu tệp vào |

Mã lỗi:

| Mã | Ý nghĩa | Ghi status |
|---|---|---|
| 3 | `ArrayResize(Table,100)` không ra 100 | không |
| 4 | CheckRun sai (1..50 ký tự `a-z0-9-`) | không |
| 5 | đã có `mql5-results.bin` hoặc `script-status.bin` (không ghi đè) | không |
| 6 | không mở được `cases.bin` | không |
| 7 | đầu tệp thiếu byte hoặc sai magic/version/count | không |
| 8 | không mở được `mql5-results.bin` | không |
| 11 | không mở được `script-status.bin` | không |
| 9 | ca không hợp lệ: id sai thứ tự, cờ/khoảng sai, độ dài chuỗi ngoài 0..128, hoặc chuỗi không giữ được đơn vị đã đọc | có |
| 10 | còn byte chưa đọc sau vòng | có |
| 12 | ca thiếu byte (kiểm bằng `FileTell`/`FileSize` trước phần cố định 160 byte, mỗi độ dài và mỗi chuỗi) | có |
| 20 | `SymbolInfoInteger` gọi lần 4 | có |
| 21 | `Bot3OpenPending` gọi lần 5 | có |

## Script `Bot3PendingSubmissionApiCompile.mq5`

Chỉ nạp header sản phẩm thật; `input bool InvokeFunctions=false`. Khi `false` chỉ `Print`
rồi thoát. Khi `true` tạo settings, `volumes[9]`, `results` 100×2, index 0, error_count,
trade, options (đều về 0) và gọi `Bot3SubmitPendingAfterPrice(true,0.0,…)` một lần.
Chỉ để biên dịch, không chạy.

## Lựa chọn ở chỗ TASK chưa nói

- Lần gọi vượt giới hạn: Digits lần 4 → lỗi 20, trả 0; gửi lần 5 → lỗi 21,
  `FakeLastError=999`, trả false. Cả hai **không** ghi sự kiện, không tăng bộ đếm, không
  đổi dữ liệu (như `BlocksSymbolInteger` trong mẫu đã có). Đây là chặn của bộ kiểm, không
  thêm vào sản phẩm.
- Ca đọc lỗi (9/12): không gọi sản phẩm, không ghi bản ghi, dừng vòng. Lỗi trong lúc chạy
  (20/21): vẫn ghi bản ghi ca đó với Fault rồi dừng. Fault ghi trong mỗi bản ghi là lỗi
  đầu tiên của lượt, nên các ca trước đó luôn có Fault 0.
- Chuỗi được dựng bằng `ShortToString` rồi so lại từng đơn vị: đơn vị 0 (chuỗi MQL5 bị
  cắt) cho lỗi 9 thay vì đưa chuỗi khác dữ liệu vào sản phẩm.
- Bảng đổi cỡ một lần; mỗi ca chỉ nạp lại giá trị (TASK sản phẩm cấm nới mảng).
- Không có chặn treo nào ngoài lần gửi thứ 5. Header hiện tại luôn gọi `Bot3OpenPending`
  sau mỗi `Sleep`, nên chặn này đủ cho header đó.
- Ghi chú cho thiết kế ca: theo công thức lỗi, `retry_count` 0 và 1 cho cùng dãy (ordinal≥1
  luôn ≥ retry_count); chỉ bit 0..2 của `retry_accept_mask` được dùng.

## Codex cần kiểm

1. Check đã có trong nguồn chính, đã biên dịch 0 lỗi/0 cảnh báo theo bằng chứng trên. Ghép
   `Bot3PendingSubmissionApiCompile.mq5` vào `bot-cua-toi-3/source/MQL5/Scripts/bot-cua-toi-3/`
   và chỉ biên dịch, mục tiêu 0 lỗi/0 cảnh báo.
2. Nếu header sản phẩm đổi sau bản tôi đọc, xác nhận lại: chỉ nạp sáu header phụ thuộc,
   không dùng tên trùng với Script (`Case`, `S`, `V`, `Index`, `Errors`, `Table`, `T`, `O`,
   `Fault`, `FakeLastError`, `Events`, `MutationCount`, `Hash`, các `…Calls`, `Fail`, `Bits`,
   `FromBits`, `Signed`, `HashWord`, `TextHash`, `BeginEvent`, `ApplyMutation`, `Available`,
   `Flag`, `Within`, `ReadText`, `ReadCase`, `Initialize`, `PutWord`, `WriteResult`,
   `PendingDoubleBits`, `PendingCheckCase`).
3. Tạo `cases.bin`, chạy Check trong MT5 thử; so `mql5-results.bin` và `script-status.bin`
   theo thứ tự ca với kết quả gốc lấy độc lập.
