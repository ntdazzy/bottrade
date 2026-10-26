# SUMMARY: bot1-pending-check-20261026-r1

## Trạng thái

- **Chưa biên dịch, chưa chạy** hai Script. Chưa chạy Python, chưa tạo `cases.bin`,
  chưa so với bản gốc. Bộ kiểm không tính kết quả mong đợi và không tự kết luận đạt.
- Header sản phẩm: lúc bắt đầu, tìm `Bot1PendingSubmission*` không thấy, nên mã viết
  theo giao diện trong TASK sản phẩm. Trong lúc làm, header xuất hiện ở
  `../bot1-pending-submission-20261026-r1/Bot1PendingSubmission.mqh` (126 dòng), và
  tôi đã đọc nó:
  - struct và chữ ký public khớp TASK; chỉ include đúng 5 header;
  - các lời gọi bị chặn có đúng dạng hàm giả: `SymbolInfoInteger` 2 tham số, `Print`
    một chuỗi, `Sleep(2500)`, `AccountInfoInteger(ACCOUNT_LIMIT_ORDERS)`, `OrdersTotal()`;
  - các tên `Bot1PendingSubmissionSettings`, `Bot1SubmissionDifference`,
    `Bot1SendPendingEntry`, `Bot1SubmitPendingAfterPrice` không trùng tên nào trong Script.
- Header chưa có trong nguồn chính. Script include theo đường của nguồn chính
  (`../../Include/bot-cua-toi-1/`), nên phải ghép header trước khi biên dịch.
- Chỉ ghi 4 tệp trong thư mục này. Không sửa nguồn chính, Git hay MT5; không chạy lệnh;
  không tạo tác tử. Không đọc EX5, mã máy, thư mục phân tích hay bằng chứng.

## Tệp đã viết

| Tệp | Đích khi ghép | Nội dung |
|---|---|---|
| `Bot1PendingSubmissionCheck.mq5` | `bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/` | Gọi thân sản phẩm thật với các dịch vụ giả trả lời hữu hạn; 324 dòng, chỉ ASCII |
| `Bot1PendingSubmissionApiCompile.mq5` | cùng thư mục | Chỉ để biên dịch với khai báo API thật |
| `pending_submission_cases.py` | `bot-cua-toi-1/tests/` | 416 ca đầu vào, không có kết quả mong đợi |
| `SUMMARY.md` | — | Tệp này |

## Check: khác với mẫu bot3 hiện hành

Mẫu là `bot-cua-toi-3/source/MQL5/Scripts/bot-cua-toi-3/Bot3PendingSubmissionCheck.mq5`.
Phần không nêu dưới đây giữ nguyên như mẫu: union bit, FNV từng word và từng chuỗi,
`Fail` giữ lỗi đầu, đọc chuỗi UTF-16, bảng 100×2 theo 6 `cache_mode`, cách đổi dữ liệu,
lỗi khi gửi, `Sleep`, `ErrorText`, `Print`.

| Chỗ | bot3 | bot1 (tệp này) |
|---|---|---|
| Include trước macro | 6 header, có OrderScan | 5 header: PriceLevels, Margin, VolumeValidation, TradeSend, TradeErrors |
| Macro (define trước header sản phẩm, undef ngay sau) | 9 tên, có `Bot3AllowsPendingOrder` | 10 tên: `SymbolInfoInteger`, `Bot1MarginGuard`, `Bot1ValidateVolume`, `AccountInfoInteger`, `OrdersTotal`, `Bot1OpenPending`, `Sleep`, `GetLastError`, `Bot1TradeErrorText`, `Print`. Không chặn, không tạo `Bot1AllowsPendingOrder` |
| Hàm thật giữ lại | `Bot3RoundPrice` | `Bot1RoundPrice`, `Bot1SubmissionDifference` |
| Khối lượng | `V[9]`, Index 0..8, `%9` | `V[8]`, Index 0..7, `(Index+1)%8`; `V[i]=0.125*(i+1)`, sau đổi `0.25*(i+5)` |
| Phần cố định của ca | 160 byte, 1 int64 | 168 byte: 22 int32, 2 int64 (`expiration`, `order_limit`), 8 double |
| Trường int32 thứ 13 | `limit_reply` (0/1) | `orders_total` (int32 có dấu bất kỳ, không kiểm) |
| Kiểm ca | index ≤8, mutation ≤9 | index ≤7, mutation ≤10; `order_limit` không kiểm |
| 15 word đầu | 14 word, có `LimitCalls` | Events, Hash, Digits, Margin, Volume, `AccountLimitCalls`, `OrdersTotalCalls`, Send, Sleep, Print, Error, Mutation, Errors, FakeLastError (dấu mở rộng), Index |
| Thư mục, magic | `bot3-pending-submission\`, `0x50534233` | `bot1-pending-submission\<CheckRun>\`, `0x50534231` |

Mỗi ca vẫn 1936 byte: 8 V + 15 word đầu = 9 V + 14 word đầu của bot3.

## Hàm giả

Mọi word lấy từ **đối số thật**. Sự kiện ghi trước khi đổi dữ liệu và trước khi trả về.

| kind | Hàm | Word sau kind | Sau sự kiện | Trả |
|---|---|---|---|---|
| 1 | `FakeSymbolInfoInteger(symbol,prop)` | prop, symbol_hash, reply | `DigitsCalls++`, mutation 1/2/3 | digit0/1/2 |
| 2 | `FakeMarginGuard(symbol,type,volume)` | symbol_hash, type, bit volume, reply | `MarginCalls++`, mutation 4 | margin_reply≠0 |
| 3 | `FakeValidateVolume(symbol,volume)` | symbol_hash, bit volume, reply | `VolumeCalls++`, mutation 5 | volume_reply≠0 |
| 4 | `FakeAccountInfoInteger(prop)` | prop (`ACCOUNT_LIMIT_ORDERS`=47), đủ 64 bit của reply | `AccountLimitCalls++`, mutation 6 | `long` order_limit |
| 10 | `FakeOrdersTotal()` | reply int32 mở rộng dấu lên 64 bit | `OrdersTotalCalls++`, mutation 10 | `int` orders_total |
| 5 | `FakeOpenPending` (đúng chữ ký thật) | như mẫu: type, bit volume/price/sl/tp, expiration, magic, virtual_expiration, symbol_hash, comment_hash, state.magic, 3 option, reply | như mẫu; mutation 7 (lần đầu), 9 (lần thử 1) | như mẫu |
| 6 | `FakeSleep` | milliseconds | mutation 8 ở lần đầu; không ngủ thật | — |
| 7 | `FakeTradeErrorText(code,counter)` | code, counter cũ, counter mới, text_hash | tăng qua đối số | `"error-"+code` |
| 8 | `FakePrint(text)` | text_hash | `PrintCalls++` | — |
| 9 | (đổi dữ liệu) | trigger | ghi trước khi đổi | — |
| — | `FakeGetLastError()` | không ghi sự kiện | — | `FakeLastError` |

Khi đổi dữ liệu, Script không đổi `order_limit` và `orders_total`: hai giá trị này nằm
trong `Case`, không nằm trong settings.

Mã lỗi giống mẫu: 3, 4, 5, 6, 7, 8, 11 (không ghi status); 9, 10, 12, 20 (Digits lần 4),
21 (gửi lần 5) (có ghi status). Mã 12 kiểm đủ 168 byte trước phần cố định.

## ApiCompile

Chỉ include header sản phẩm thật; có `input bool InvokeFunctions=false`. Khi `false`,
chỉ `Print` rồi thoát. Khi `true`, tạo settings, `volumes[8]`, index 0, error_count,
`results` 100×2, trade, options (đều bằng 0), rồi gọi
`Bot1SubmitPendingAfterPrice(true,0.0,…)` một lần.

## Tệp ca: khác với `bot-cua-toi-3/tests/pending_submission_cases.py`

- `MAGIC=0x50534231`. Trong INTS, `limit_reply` đổi thành `orders_total`.
  `encode` dùng `<22i2q8d`, đặt `order_limit` ngay sau `expiration`.
- `base`: `strategy_index=3`, `orders_total=0`, `order_limit=100`; các giá trị khác như mẫu.
- `early-return-order`: vẫn lặp 3 bool. Bool limit 1 cho `orders_total=0`, bool 0 cho
  `orders_total=100`.
- `cache-first-empty`: chỉ số `[0,3,7]`.
- `RESULT_NAMES` có 241 tên. Hai tên mới tôi đặt là `account_limit_calls` và
  `orders_total_calls`; khối lượng là `volume0..7`.
- Thêm 2 assert: `struct.calcsize('<22i2q8d')==168` và `len(out)==416`.
- Không đổi phần còn lại: docstring, `table`, cách mã hóa chuỗi, các nhóm cũ (kể cả
  `live-reads-and-retry` vẫn `range(10)`). Grep xác nhận dòng 49 có đúng U+00E0,
  U+1EDD, U+1F4B0 như mẫu.

Thứ tự id, tính bằng cách đọc mã (chưa chạy Python):

| id | Nhóm |
|---|---|
| 0–153 / 154–307 | 9 nhóm cũ, buy=0 rồi buy=1 (mỗi bên 154 ca) |
| 308–331 | 24 ca NaN payload và tích vô cực nhân 0 |
| 332–371 / 372–411 | `account-limit-int32-and-short-circuit`, buy=0 rồi buy=1. Id = đầu khối + 5×(vị trí order_limit) + (vị trí orders_total) |
| 412–415 | `orders-total-mutation`: (buy, omit) = (0,0), (0,255), (1,0), (1,255) |

Ở nhóm limit, 8 giá trị `order_limit` có 32 bit thấp là `0`, `1` hoặc `0xFFFFFFFF`.
Đây chỉ là tính chất của đầu vào, không phải kết quả mong đợi.

## Giới hạn của bộ kiểm

- Hàm giả chỉ thấy giá trị lúc có lời gọi dịch vụ. Vì vậy Script không thấy được
  thứ tự đọc giữa hai lời gọi, gồm:
  - `omit_real_sl_tp` trước hay sau `expiration` (lần đầu và lần thử lại);
  - comment, volume, symbol trong hàm gửi;
  - volume trước symbol ở bước 1.

  Nếu cần chứng minh các thứ tự này, Codex phải dùng cách kiểm riêng.
- Chỉ chặn treo ở lần gửi thứ 5 (và Digits lần 4) như mẫu. `AccountInfoInteger` và
  `OrdersTotal` không có giới hạn số lần, giống `FakeAllowsPendingOrder` của bot3.
- `FakeAccountInfoInteger` trả `order_limit` với mọi giá trị prop; prop chỉ được
  ghi vào chuỗi băm.

## Codex cần kiểm

1. Ghép header sản phẩm vào `bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/`, rồi
   biên dịch hai Script, mục tiêu 0 lỗi/0 cảnh báo. SUMMARY sản phẩm có nêu một cảnh
   báo có thể xảy ra: `omit`/`expiration` khai báo không có giá trị đầu.
2. Runner bot1 dùng cùng các tên như runner bot3: `cases`, `encode`, `table`, `RESULT`,
   `RESULT_NAMES`, `MAGIC`. Tôi chỉ grep `data.` trong
   `bot-cua-toi-3/tests/check-pending-submission.py` để xem tên.
3. Tạo `cases.bin` (416 ca), chạy Check trong MT5 thử, so `mql5-results.bin` và
   `script-status.bin` theo thứ tự ca với kết quả gốc lấy độc lập.

## Đã đọc

- `AGENTS.md` (trong lời nhắc), `tai-lieu-cu/QUY-TRINH.md`, TASK của lượt này và
  `../bot1-pending-submission-20261026-r1/` (TASK, header, SUMMARY).
- Header bot1 trong `source/MQL5/Include/bot-cua-toi-1/`: đọc PriceLevels, Margin,
  VolumeValidation, TradeSend, TradeErrors, PendingRequest; grep tên cấp ngoài trong
  TradeMessages, Filling, và grep guard của cả 8 tệp.
- Mẫu bot3 hiện hành: `Bot3PendingSubmissionCheck.mq5`, `Bot3PendingSubmissionApiCompile.mq5`,
  `Bot3PendingSubmission.mqh`, `tests/pending_submission_cases.py`.
- `Bot1ManagementRouterApiCompile.mq5`, để xem cách viết đường include.
- SUMMARY của `bot3-pending-check-20261026-r2` và `bot3-pending-math-20261026-r3`, để
  theo cách trình bày.

## Cấu hình lượt này

- Môi trường báo mô hình `claude-opus-5-5` (Opus 5.5) và ultracode đang bật. Từ bên
  trong, tôi không tự kiểm được mức `max`; Codex kiểm riêng.
- Phiên này không có công cụ Workflow. TASK cấm tạo tác tử và dùng shell, nên tôi làm
  một mình và không chạy lệnh nào.
