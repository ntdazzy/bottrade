# bot3-real-high-low-20261025-r1 — tóm tắt

**Trạng thái: bản đề xuất. Chưa biên dịch, chưa chạy, chưa so với EX5 gốc.**
Codex kiểm, ghép và chạy.

## Tệp đã ghi

| Tệp | Nội dung |
|---|---|
| `Bot3ManagementRealHighLow.mqh` | `Bot3PrintHighLowError`, `Bot3AdvanceHighLowRealBuyStop`, `Bot3AdvanceHighLowRealSellStop`; chữ ký đúng `TASK.md`. |
| `SUMMARY.md` | Tệp này. |

Không sửa nguồn chính, Git hay tệp nào khác. Không chạy lệnh, không gọi tác tử khác.

## Nguồn dùng khi viết

- Đặc tả: yêu cầu lượt này, trùng nguyên văn `TASK.md` trong thư mục.
- Quy tắc: `AGENTS.md`, `dich-nguoc/khoi-phuc/tai-lieu-cu/QUY-TRINH.md`.
- Chỉ lấy giao diện từ nguồn chính `bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/`:
  `Bot3ManagementPrelude.mqh`, `Bot3ManagementMessages.mqh`, `Bot3TradeErrors.mqh`,
  chữ ký `Bot3RoundPrice` (`Bot3PriceLevels.mqh:7`) và `Bot3ModifyPosition`
  (`Bot3PositionModify.mqh:5-6`).
- `Bot3ManagementRealDistance.mqh`: chỉ để theo cách viết (tên biến, chú thích, cách hỏi
  DIGITS/POINT). Logic lấy từ đặc tả.
- Không đọc EX5, mã máy hay bản phân tích lịch sử.

## Giao diện đã dùng

| Tên | Chữ ký trong nguồn chính | Ghi chú |
|---|---|---|
| `Bot3RoundPrice` | `double (const double price,const uint digits)` | `digits` lấy bằng `(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS)` |
| `Bot3ModifyPosition` | `bool (state&,options&,const ulong ticket,const double sl,const double tp)` | sl/tp truyền theo giá trị |
| `Bot3TradeErrorText` | `string (const int code,uint &error_count)` | tự tăng `error_count` 1 lần |
| `Bot3ManagedPosition` | các trường `sl`, `tp`, `open_price` (double) | chỉ ghi `sl` |

Không dùng `Bot3PrintManagementError` (tiền tố khác), `NormalizeDouble`, `SymbolInfoTick`,
`ResetLastError`.

## `Bot3PrintHighLowError(uint &counter)` — dòng 9–14

| Dòng | Việc |
|---|---|
| 11 | `int code=(int)GetLastError();` — đọc đúng một lần, không reset. |
| 12 | `message=Bot3TradeErrorText(code,counter)` — `counter` tăng 1 trong hàm này. |
| 13 | `Print("error: '"+message+"' when modifying stoploss")` — đúng một lần. |

## BUY — `Bot3AdvanceHighLowRealBuyStop`, dòng 18–60

"Đọc mới" = đọc qua tham chiếu tại đúng dòng đó.

| Bước | Dòng | Việc |
|---|---|---|
| 0 | 28 | `enabled<=0 \|\| eligible_flag==0` → thoát. |
| 1 | 30 | `level1=levels[strategy_index]` (trước DIGITS1). |
|  | 31 | API DIGITS → `digits1`. |
|  | 32 | Đọc `gap`, `position.sl`: `gate_base=gap+position.sl` (trước POINT1). |
|  | 33 | API POINT → `point1`. |
|  | 34–35 | `gate=Bot3RoundPrice(gate_base+point1,digits1)`; `!(gate<level1)` → thoát. Không đọc lại `gap`. |
| 2 | 37–40 | Đọc mới `level2=levels[strategy_index]`, `quote=tick.bid`, `count=(double)gap_count`, `captured_unit=unit`. |
|  | 41 | `!(level2<quote-count*captured_unit)` → thoát. |
|  | 42 | `!(level2<position.open_price) && (before_open&1)!=0` → thoát. |
| 3 | 43 | API DIGITS → `digits2`. |
|  | 45–46 | Đọc mới `shift_setting`, `tick.bid`, `unit`, `gap`: `shift=…?10.0:0.0`; `boundary_base=(tick.bid-shift*unit)-gap` (trước POINT2). |
|  | 47 | API POINT → `point2`. |
|  | 48–49 | `boundary=Bot3RoundPrice(boundary_base-point2,digits2)`; `!(level2<boundary)` → thoát (`level2` của bước 2). |
| 4 | 50 | Đọc mới `tick.bid`, `freeze`: `!(tick.bid<position.tp-freeze)` → thoát. |
| 5 | 51 | API DIGITS → `digits3`. |
|  | 52 | Đọc mới `levels[strategy_index]`: `new_sl=Bot3RoundPrice(...,digits3)`. |
|  | 54 | **Ghi** `position.sl=new_sl` ngay. |
|  | 55 | Đọc mới `tick.bid`, `gap`: `!(new_sl<tick.bid-gap)` → thoát, giữ SL mới. |
| 6 | 56 | API `Bot3ModifyPosition(state,options,ticket,position.sl,position.tp)` → `ok`. |
|  | 58 | **Ghi** `changed=true`, trước khi xét `ok`. |
|  | 59 | `!ok` → `Bot3PrintHighLowError(error_count)`. |

Thứ tự API: DIGITS → POINT → DIGITS → POINT → DIGITS → Modify → (nếu lỗi) GetLastError → Print.

## SELL — `Bot3AdvanceHighLowRealSellStop`, dòng 62–101

| Bước | Dòng | Việc |
|---|---|---|
| 0 | 72 | `enabled<=0 \|\| eligible_flag==0` → thoát. |
| 1 | 74–75 | `level1=levels[strategy_index]`; `gate_base=position.sl-gap` (trước POINT1). |
|  | 76 | API POINT → `point1`. |
|  | 77 | `!(level1<gate_base-point1)` → thoát. Không DIGITS, không làm tròn. |
| 2 | 79–81 | Đọc mới và chụp: `captured_unit=unit`, `level2=levels[strategy_index]`, `quote=tick.ask`. |
|  | 82 | Đọc mới `gap_count`: `!(((double)gap_count*captured_unit+quote)<level2)` → thoát. |
|  | 83 | `!(position.open_price<level2) && (before_open&1)!=0` → thoát. |
| 3 | 84–85 | Đọc mới `shift_setting`, `gap`: `shift=…?10.0:0.0`; `boundary_base=(quote+captured_unit*shift)+gap` (trước POINT2, dùng giá trị đã chụp). |
|  | 86 | API POINT → `point2`. |
|  | 87 | `!((boundary_base+point2)<level2)` → thoát. Không DIGITS. |
| 4 | 88 | Đọc mới `freeze`, `tick.ask`: `!((freeze+position.tp)<tick.ask)` → thoát. |
| 5 | 89 | API DIGITS → `digits1`. |
|  | 90 | Đọc mới `levels[strategy_index]`: `candidate=Bot3RoundPrice(...,digits1)`. |
|  | 92 | `!(candidate<position.sl)` (SL cũ, chưa ghi) → thoát. |
| 6 | 93 | API DIGITS → `digits2`. |
|  | 94 | Đọc mới `levels[strategy_index]`: `new_sl=Bot3RoundPrice(...,digits2)`. |
|  | 96 | **Ghi** `position.sl=new_sl` ngay. |
|  | 97 | Đọc mới `tick.ask`, `gap`: `!((tick.ask+gap)<new_sl)` → thoát, giữ SL mới. |
| 7 | 98 | API Modify → `ok`. |
|  | 99 | **Ghi** `changed=true`, trước khi xét `ok`. |
|  | 100 | `!ok` → `Bot3PrintHighLowError(error_count)`. |

Thứ tự API: POINT → POINT → DIGITS → DIGITS → Modify → (nếu lỗi) GetLastError → Print.

## Cờ và các lối ra (cả hai hàm)

| Lối ra | `position.sl` | `changed` | `error_count` | In |
|---|---|---|---|---|
| Cổng trước khi ghi SL sai (BUY 28, 35, 41, 42, 49, 50; SELL 72, 77, 82, 83, 87, 88, 92) | giữ cũ | giữ cũ | không đổi | không |
| Cổng gap cuối sai (BUY 55, SELL 97) | `new_sl` | giữ cũ | không đổi | không |
| Modify `true` | `new_sl` | `true` | không đổi | không |
| Modify `false` | `new_sl` | `true` | +1 (trong `Bot3TradeErrorText`) | 1 dòng |

- `enabled` (int): chỉ xét `<=0`. `eligible_flag` (byte của bên gọi): chỉ xét `==0`,
  không tạo hay giải thích thêm.
- `before_open`: chỉ dùng bit 0. `shift_setting`: `!=0` → `10.0`, ngược lại `0.0`.
- Mọi cổng viết `!(a<b)`: NaN làm cổng sai → thoát. Riêng cổng `before_open` đúng theo
  đặc tả `!(…)`: so sánh có NaN làm vế này đúng → thoát nếu bit 0 bật.
- Không làm: đổi TP, đóng lệnh, khối lượng, ghi bảng/Stamp, `SymbolInfoTick`, kiểm chỉ số
  mảng (0..8 hợp lệ theo đặc tả), xử lý trùng vùng nhớ (đặc tả nói không có), trả lại SL cũ.

## Chỗ thiếu / chưa rõ

Không thấy chỗ đặc tả bỏ trống phải tự điền. Không thêm luật. Hai chỗ đặc tả không nêu
thứ tự, nhưng không đổi kết quả vì giữa chúng không có API và không có tác dụng phụ:

- thứ tự đọc `level2`, `quote`, `count`, `unit` (BUY dòng 37–40): viết đúng thứ tự liệt kê;
- thứ tự hai vế cổng `before_open` (BUY 42, SELL 83): so sánh trước, bit sau.

## Cần Codex kiểm trước khi ghép

1. Đặt tệp cạnh nguồn chính `source/MQL5/Include/bot-cua-toi-3/` rồi biên dịch. Hai
   `#include` dùng đường dẫn cùng thư mục, nên trong thư mục đề xuất chưa biên dịch được.
   Mục tiêu 0 lỗi, 0 cảnh báo.
2. Mã máy đọc lại tham chiếu đúng chỗ như hai bảng trên, không giữ giá trị cũ qua API.
   Chú ý: BUY đọc `unit` hai lần (dòng 40 và 46, có DIGITS2 ở giữa); SELL dùng
   `unit`/`ask`/`level2` đã chụp ở dòng 79–81 cho tới cổng dòng 87.
3. Thứ tự phép tính được giữ: BUY `(gap+sl)+point1`, `quote-count*unit`,
   `(bid-shift*unit)-gap`, `boundary_base-point2`; SELL `(sl-gap)-point1`,
   `gap_count*unit+ask`, `(ask+unit*shift)+gap`, `boundary_base+point2`. Tích với
   `shift=0.0` không bị gộp thành `0.0` (Inf/NaN phải cho NaN).
4. Chuỗi in đúng từng ký tự: `error: '<message>' when modifying stoploss`.
5. Tên mới `Bot3PrintHighLowError`, `Bot3AdvanceHighLowRealBuyStop/SellStop`, guard
   `BOT3_MANAGEMENT_REAL_HIGH_LOW_MQH`: lúc viết, Grep trong `dich-nguoc/**/*.mq*` không thấy
   trùng. Tìm khai báo đầu dòng trong `bot-cua-toi-3/source/MQL5` chỉ thấy biến toàn cục
   `digits1` trong script kiểm `Bot3ManagementVirtualFinishBranchesCheck.mq5` (script đó không
   nạp tệp này); script kiểm mới cho tệp này không nên khai báo toàn cục trùng tên biến cục bộ.
6. So từng lối ra với EX5 gốc trên cùng dữ liệu (chưa làm).

## Cấu hình lượt này

- Mô hình theo môi trường phiên: `claude-opus-5-5`. Mức `max`: không tự kiểm được từ bên trong.
- Ultracode: được yêu cầu, nhưng phiên không có công cụ Workflow và yêu cầu cấm tác tử
  khác, nên làm một mình; đã tự rà từng bước với đặc tả, chưa có đánh giá chéo.
- Không chạy lệnh shell; chỉ dùng công cụ đọc/tìm/ghi tệp.
