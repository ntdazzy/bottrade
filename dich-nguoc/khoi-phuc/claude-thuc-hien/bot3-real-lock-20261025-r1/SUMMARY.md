# bot3-real-lock-20261025-r1 — tóm tắt

**Trạng thái: bản đề xuất. Chưa biên dịch, chưa chạy, chưa so với EX5 gốc.**
Codex kiểm, ghép và chạy.

## Tệp đã ghi

Thư mục: `dich-nguoc/khoi-phuc/claude-thuc-hien/bot3-real-lock-20261025-r1/` (có `TASK.md`
trùng nguyên văn yêu cầu lượt này).

| Tệp | Nội dung |
|---|---|
| `Bot3ManagementRealLock.mqh` | `Bot3PrintRealLockError`, `Bot3AdvanceRealLockBuyStop`, `Bot3AdvanceRealLockSellStop`; chữ ký đúng `TASK.md`; 86 dòng. |
| `SUMMARY.md` | Tệp này. |

Không sửa nguồn chính, Git, `TASK.md` hay tệp nào khác. Không chạy lệnh, không gọi tác tử khác.

## Nguồn dùng khi viết

- Đặc tả: yêu cầu lượt này (= `TASK.md`).
- Quy tắc: `AGENTS.md`, `dich-nguoc/khoi-phuc/tai-lieu-cu/QUY-TRINH.md`.
- Chỉ lấy giao diện từ nguồn chính `bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/`:
  `Bot3ManagementPrelude.mqh` (struct `Bot3ManagedPosition`), `Bot3ManagementMessages.mqh`,
  `Bot3TradeErrors.mqh:4` (`Bot3TradeErrorText`), `Bot3PriceLevels.mqh:7` (`Bot3RoundPrice`),
  `Bot3PositionModify.mqh:5-6` (`Bot3ModifyPosition`).
- `Bot3ManagementRealHighLow.mqh` (nguồn chính) và `SUMMARY.md` của
  `bot3-real-high-low-20261025-r1`: chỉ để theo cách viết. Logic lấy từ đặc tả.
- Không đọc EX5, mã máy hay bản phân tích lịch sử.

## API và giao diện đã dùng

| Tên | Chữ ký | Dòng dùng |
|---|---|---|
| `SymbolInfoInteger(symbol,SYMBOL_DIGITS)` | trả `long`, ép `(uint)` | BUY 29, 32, 39, 43; SELL 73, 77 |
| `SymbolInfoDouble(symbol,SYMBOL_POINT)` | trả `double` | BUY 35; SELL 66 |
| `Bot3RoundPrice` | `double (const double price,const uint digits)` | BUY 30, 34, 40, 44; SELL 74, 78 |
| `Bot3ModifyPosition` | `bool (state&,options&,const ulong ticket,const double sl,const double tp)` | BUY 48; SELL 82 |
| `GetLastError` | `int` | 11 (một lần) |
| `Bot3TradeErrorText` | `string (const int code,uint &error_count)`, tự tăng `error_count` 1 lần | 12 |
| `Print` | | 13–14 (một lần) |

- `Bot3ManagedPosition`: đọc `open_price`, `tp`; đọc và ghi `sl`. `tick` chỉ đọc (giữ kiểu
  `MqlTick &` theo giao diện).
- Không dùng: `NormalizeDouble`, `SymbolInfoTick`, `ResetLastError`, `Bot3PrintManagementError`
  (tiền tố `TrailStop error: '` khác), mảng, đổi TP, đóng lệnh, khối lượng, bảng/Stamp.

## `Bot3PrintRealLockError(uint &counter)` — dòng 9–15

| Dòng | Việc |
|---|---|
| 11 | `int code=(int)GetLastError();` — đọc đúng 1 lần, không reset. |
| 12 | `msg=Bot3TradeErrorText(code,counter)` — `counter` tăng 1 trong hàm đó; không tăng thêm. |
| 13–14 | `Print("error when setting breakeven: '"+msg+"' ..'Exit_BE_start_' to close to 'Exit_BE_extra_pips_' ..trying again!")` — đúng 1 lần; một biểu thức, chỉ xuống dòng giữa hai toán hạng. |

## BUY — `Bot3AdvanceRealLockBuyStop`, dòng 20–52

"Đọc mới" = đọc qua tham chiếu tại đúng dòng đó, sau API gần nhất.

| Bước | Dòng | Việc |
|---|---|---|
| 0 | 26 | `!(0.0<start)` → thoát. Không kiểm chế độ. |
| 1 | 28 | `quote1=tick.bid` (trước DIGITS1). |
|  | 29 | API DIGITS → `digits1`. |
|  | 30–31 | Đọc mới `start`, `unit`: `gate1=Bot3RoundPrice(start*unit+open_price,digits1)`; `!(gate1<quote1)` → thoát. |
| 2 | 32 | API DIGITS → `digits2`. |
|  | 34 | Đọc mới `extra`, `unit`: `candidate=Bot3RoundPrice(extra*unit+open_price,digits2)` (trước POINT). |
|  | 35 | API POINT → `point`. |
|  | 36 | `!(point+position.sl<candidate)` → thoát. Dùng `candidate` đã chụp, không đọc lại `extra`/`unit`. |
| 3 | 38 | Đọc mới `quote2=tick.bid` (trước DIGITS3). |
|  | 39 | API DIGITS → `digits3`. |
|  | 40–41 | Đọc mới `extra`, `unit`, `gap`: `gate2=Bot3RoundPrice((extra*unit+open_price)+gap,digits3)`; `!(gate2<quote2)` → thoát. |
| 4 | 42 | Đọc mới `tick.bid`, `freeze`: `!(tick.bid<position.tp-freeze)` → thoát. |
| 5 | 43 | API DIGITS → `digits4`. |
|  | 44 | Đọc mới `extra`, `unit`: `new_sl=Bot3RoundPrice(extra*unit+open_price,digits4)`. |
|  | 46 | **Ghi** `position.sl=new_sl` ngay. |
|  | 47 | Đọc mới `tick.bid`, `gap`: `!(new_sl<tick.bid-gap)` → thoát, giữ SL mới. |
| 6 | 48 | API `Bot3ModifyPosition(state,options,ticket,position.sl,position.tp)` → `ok`. |
|  | 50 | **Ghi** `changed=true`, trước khi xét `ok`. |
|  | 51 | `!ok` → `Bot3PrintRealLockError(error_count)`. |

Thứ tự API: DIGITS → DIGITS → POINT → DIGITS → DIGITS → Modify → (nếu lỗi) GetLastError → Print.

## SELL — `Bot3AdvanceRealLockSellStop`, dòng 54–85

| Bước | Dòng | Việc |
|---|---|---|
| 0 | 60 | `!(0.0<start)` → thoát. Không kiểm chế độ. |
| 1 | 62 | Chụp `captured_unit=unit` (`u` trong đặc tả). |
|  | 63–64 | `trigger=open_price-start*captured_unit`; `!(tick.ask<trigger)` → thoát. Không DIGITS, không làm tròn. |
| 2 | 65 | `candidate=open_price-captured_unit*extra` (giữ `u*extra`; trước POINT; không làm tròn). |
|  | 66 | API POINT → `point`. |
|  | 67 | `!(candidate<position.sl-point)` → thoát. |
| 3 | 69–70 | Đọc mới `extra`, `unit`, rồi `tick.ask`: `offset=extra*unit`, `quote=tick.ask`. |
|  | 71 | Đọc mới `gap`: `!(quote<(open_price-offset)-gap)` → thoát. |
|  | 72 | Đọc mới `freeze`: `!(freeze+position.tp<quote)` → thoát (cùng `quote`). |
| 4 | 73 | API DIGITS → `digits1`. |
|  | 74 | Đọc mới `extra`, `unit`: `gate=Bot3RoundPrice(open_price-extra*unit,digits1)`. |
|  | 76 | `!(gate<position.sl)` (SL cũ, chưa ghi) → thoát. |
| 5 | 77 | API DIGITS → `digits2`. |
|  | 78 | Đọc mới `extra`, `unit`: `new_sl=Bot3RoundPrice(open_price-extra*unit,digits2)`. |
|  | 80 | **Ghi** `position.sl=new_sl` ngay. |
|  | 81 | Đọc mới `tick.ask`, `gap`: `!(tick.ask+gap<new_sl)` → thoát, giữ SL mới. |
| 6 | 82 | API Modify → `ok`. |
|  | 83 | **Ghi** `changed=true`, trước khi xét `ok`. |
|  | 84 | `!ok` → `Bot3PrintRealLockError(error_count)`. |

Thứ tự API: POINT → DIGITS → DIGITS → Modify → (nếu lỗi) GetLastError → Print.

## Cờ và các lối ra (cả hai hàm)

| Lối ra | `position.sl` | `changed` | `error_count` | In |
|---|---|---|---|---|
| Cổng trước khi ghi SL sai (BUY 26, 31, 36, 41, 42; SELL 60, 64, 67, 71, 72, 76) | giữ cũ | giữ cũ | không đổi | không |
| Cổng gap cuối sai (BUY 47, SELL 81) | `new_sl` | giữ cũ | không đổi | không |
| Modify `true` | `new_sl` | `true` | không đổi | không |
| Modify `false` | `new_sl` | `true` | +1 (trong `Bot3TradeErrorText`) | 1 dòng |

- Mọi cổng viết `!(a<b)`: so sánh có NaN là sai → thoát, kể cả cổng `0.0<start`.
  Bằng nhau cũng thoát (so sánh chặt).
- Không có tham số chế độ/bật tắt; không thêm cổng; không trả lại SL cũ.

## Chỗ thiếu / chưa rõ

Không thấy chỗ đặc tả bỏ trống phải tự điền. Không thêm luật. Các chỗ đặc tả không nêu
thứ tự, nhưng không đổi kết quả vì giữa chúng không có API và không có ghi:

- SELL 63–64: tính `trigger` rồi mới đọc `tick.ask`;
- SELL 69–70: đọc `extra`/`unit` trước `tick.ask` (theo thứ tự liệt kê trong đặc tả);
- `start` đọc hai lần: BUY 26 và 30 (có DIGITS1 ở giữa, nên dòng 30 là đọc mới đúng đặc tả);
  SELL 60 và 63 (không có API ở giữa).

Tên biến cục bộ do tôi đặt, không phải tên gốc. Ánh xạ với đặc tả: BUY `quote`→`quote1`,
`gate`→`gate1`; SELL `u`→`captured_unit`.

## Cần Codex kiểm trước khi ghép

1. Đặt tệp cạnh nguồn chính `source/MQL5/Include/bot-cua-toi-3/` rồi biên dịch. Hai
   `#include` dùng đường dẫn cùng thư mục, nên trong thư mục đề xuất chưa biên dịch được.
   Mục tiêu 0 lỗi, 0 cảnh báo.
2. Mã máy đọc lại tham chiếu đúng chỗ, không giữ giá trị cũ qua API:
   - BUY: `unit` 4 lần (30, 34, 40, 44), `extra` 3 lần (34, 40, 44), `tick.bid` 4 lần
     (28, 38, 42, 47), `gap` 2 lần (40, 47); giá trị chụp: `quote1`, `candidate`, `quote2`.
   - SELL: `unit` 4 lần (62 chụp, 69, 74, 78), `extra` 4 lần (65, 69, 74, 78), `tick.ask`
     3 lần (64, 70, 81), `gap` 2 lần (71, 81); `captured_unit` dùng ở 63 và 65, `quote` ở 71 và 72.
   - Nếu hàm bị nội tuyến vào nơi gọi có tham số hằng, kiểm lại các lần đọc này.
3. Thứ tự phép tính giữ đúng: BUY `start*unit+open`, `extra*unit+open`, `point+sl`,
   `(extra*unit+open)+gap`, `tp-freeze`, `bid-gap`; SELL `open-start*u`, `open-u*extra`,
   `sl-point`, `(open-offset)-gap`, `freeze+tp`, `open-extra*unit`, `ask+gap`. Không gộp
   nhân-cộng (FMA); không đổi `!(a<b)` thành `a>=b` (NaN phải thoát).
4. Chuỗi in đúng từng ký tự:
   `error when setting breakeven: '<msg>' ..'Exit_BE_start_' to close to 'Exit_BE_extra_pips_' ..trying again!`
5. Tên mới `Bot3PrintRealLockError`, `Bot3AdvanceRealLockBuyStop/SellStop`, guard
   `BOT3_MANAGEMENT_REAL_LOCK_MQH`: lúc viết, Grep trong `dich-nguoc/` chỉ thấy trong `TASK.md`.
   Không thấy biến toàn cục `start`, `extra`, `point`, `quote`, `gate`, `offset`... trong nguồn
   chính, trừ script kiểm `Bot3ManagementVirtualFinishBranchesCheck.mq5` (toàn cục `digits1`,
   `point`, `unit`, `gap`, `freeze`; script đó không nạp tệp này). Script kiểm mới cho tệp này
   không nên khai báo toàn cục trùng tên tham số/biến cục bộ, để tránh cảnh báo che biến.
6. Ca nên có khi kiểm: bằng nhau ở từng cổng; NaN ở `start`/`extra`/`unit`/`gap`/`freeze`/giá;
   đổi giá trị tham chiếu giữa các API (hàm giả) để thấy đọc mới; cổng gap cuối sai; Modify
   `true`/`false` (đếm lỗi +1, in 1 dòng).
7. So từng lối ra với EX5 gốc trên cùng dữ liệu (chưa làm).

## Cấu hình lượt này

- Mô hình theo môi trường phiên: `claude-opus-5-5`. Mức `max`: không tự kiểm được từ bên trong.
- Ultracode: phiên báo đang bật, nhưng danh sách công cụ không có Workflow và yêu cầu cấm
  tác tử khác, nên làm một mình; đã tự rà từng bước với đặc tả, chưa có đánh giá chéo.
- Không chạy lệnh shell; chỉ dùng công cụ đọc/tìm/ghi tệp.
