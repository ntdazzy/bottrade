# bot3-real-take-sell-20261025-r1 — tóm tắt

**Trạng thái: bản đề xuất. Chưa biên dịch, chưa chạy, chưa so với EX5 gốc.**
Codex kiểm và ghép.

## Tệp đã ghi

| Tệp | Nội dung |
|---|---|
| `Bot3RealTakeSell.mqh` | Hàm `Bot3AdvanceRealTakeSell`, đúng chữ ký trong `TASK.md`. |
| `SUMMARY.md` | Tệp này. |

Không sửa nguồn chính, Git hay tệp nào khác.

## Nguồn dùng khi viết

- Đặc tả: yêu cầu của lượt này, trùng nguyên văn `TASK.md` trong thư mục.
- Quy tắc: `AGENTS.md`, `dich-nguoc/khoi-phuc/tai-lieu-cu/QUY-TRINH.md`.
- Chỉ lấy giao diện (kiểu, chữ ký) từ nguồn chính
  `bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/`: `Bot3ManagementPrelude.mqh`,
  `Bot3ManagementMessages.mqh`, `Bot3PositionModify.mqh`, `Bot3PositionClose.mqh`,
  `Bot3PriceLevels.mqh`, dòng `#include` của `Bot3TradeSend.mqh`.
- `Bot3ManagementRealDistance.mqh`, `Bot3ManagementRealTimed.mqh`: chỉ để theo cách
  viết (kiểu tham số, chú thích, biến `suffix`). Logic lấy từ đặc tả.
- Không đọc EX5, mã máy hay bản phân tích lịch sử.

## Giao diện đã dùng

| Tên | Chữ ký trong nguồn chính | Ghi chú |
|---|---|---|
| `Bot3RoundPrice` | `double (const double price,const uint digits)` | gọi với `digits1/2/3` và `2` |
| `Bot3ModifyPosition` | `bool (state&,options&,const ulong ticket,const double sl,const double tp)` | |
| `Bot3PrintManagementError` | `void (const string &suffix,uint &error_count)` | truyền qua biến `suffix` |
| `Bot3TryClosePosition` | `void (state&,options&,const ulong &deviation,const double &,const double &,const double &,const double &,const ulong ticket)` | trả `void`; hàm mới trả `true` sau lời gọi |

## Thứ tự API / đọc / ghi / đầu ra

Số dòng theo `Bot3RealTakeSell.mqh`. "Đọc mới" = đọc qua tham chiếu sau API gần nhất.

| Bước | Dòng | Việc |
|---|---|---|
| 1 | 15 | Đọc `distance`. `!(0.0<distance)` → trả `false`. Không kiểm `TP>0`. |
| 2 | 17 | `quote=tick.bid` (trước DIGITS1). |
| 3 | 18 | API `SymbolInfoInteger(symbol,SYMBOL_DIGITS)` → `digits1`. |
| 4 | 19 | API `SymbolInfoDouble(symbol,SYMBOL_POINT)` → `point`. |
| 5 | 20 | Đọc mới `distance`, `unit`. `gate=Bot3RoundPrice(distance*unit+(point+position.tp),digits1)` (TP cũ). |
| 6 | 21 | `!(gate<quote)` → `false`. |
| 7 | 22 | `quote2=tick.bid` (trước DIGITS2). |
| 8 | 23 | API DIGITS → `digits2`. |
| 9 | 24 | Đọc mới `start`, `unit`. `boundary=Bot3RoundPrice(start*unit+anchor,digits2)`; `anchor` là giá trị truyền vào. |
| 10 | 25 | `!(boundary<quote2)` → `false`. |
| 11 | 26 | Đọc mới `freeze`, `tick.bid`. `!((freeze+position.tp)<tick.bid)` → `false`. Phía bán vẫn dùng bid. |
| 12 | 27 | API DIGITS → `digits3`. |
| 13 | 28 | `quote3=tick.bid` (sau DIGITS3). |
| 14 | 29 | Đọc mới `distance`, `unit`. `new_tp=Bot3RoundPrice(quote3-distance*unit,digits3)`. |
| 15 | 31 | **Ghi** `position.tp=new_tp` ngay. |
| 16 | 32 | Đọc mới `gap`; dùng `quote3` của bước 13. `!(new_tp<quote3-gap)` → `false` (giữ TP mới). |
| 17 | 34 | API `Bot3ModifyPosition(state,options,ticket,position.sl,position.tp)`. |
| 18 | 36–39 | Nếu Modify `false`: `Bot3PrintManagementError("' when setting trailing Exit_TP.  Trying again!",error_count)` → **ghi** `changed=true` → trả `false`. Không tính khối lượng. |
| 19 | 42 | Nếu Modify `true`: đọc mới `strategy_index`, `volumes[strategy_index]`. `zero_volume=Bot3RoundPrice(volumes[strategy_index]*0.0,2)`. |
| 20 | 43 | **Ghi** `changed=true`. |
| 21 | 44 | `!(zero_volume<position.volume)` → `false`. |
| 22 | 45 | API `SymbolInfoDouble(symbol,SYMBOL_VOLUME_MIN)` → `minimum`. |
| 23 | 46 | `!(minimum<=zero_volume)` → `false`. |
| 24 | 48 | API `Bot3TryClosePosition(state,options,deviation,tick.bid,tick.ask,gap,freeze,ticket)`; không `SymbolInfoTick` trước đó. |
| 25 | 49 | Trả `true`. |

## Các lối ra

| Lối ra | Trả về | `position.tp` | `changed` | `error_count` |
|---|---|---|---|---|
| Bước 1, 6, 10, 11 sai | `false` | giữ cũ | giữ cũ | không đổi |
| Cổng gap (bước 16) sai | `false` | `new_tp` | giữ cũ | không đổi |
| Modify `false` | `false` | `new_tp` | `true` (sau báo lỗi) | chỉ đổi trong `Bot3PrintManagementError` |
| Bước 21 hoặc 23 sai | `false` | `new_tp` | `true` | không đổi |
| Tới `Bot3TryClosePosition` | `true` | `new_tp` | `true` | không đổi |

- `true` chỉ nghĩa là đã tới lời gọi đóng; không có nghĩa Modify hay đóng lệnh thành công.
- Mọi cổng viết dạng `!(a<b)` / `!(a<=b)`: NaN làm cổng sai → trả `false`.
- Giữ `volumes[...]*0.0`, không thay bằng `0.0`: Inf/NaN cho NaN nên bước 21 sai.
- Không làm: đổi `position.sl`, ghi bảng, Stamp, kiểm `0<TP`, kiểm chỉ số mảng
  (0..8 hợp lệ theo đặc tả), `ResetLastError`, trả lại TP cũ khi Modify lỗi.

## Chỗ thiếu / chưa rõ

Không thấy chỗ đặc tả bỏ trống phải tự điền. Không thêm luật ngoài đặc tả.

## Cần Codex kiểm trước khi ghép

1. Đặt tệp cạnh nguồn chính `source/MQL5/Include/bot-cua-toi-3/` rồi biên dịch. Hai
   `#include` dùng đường dẫn cùng thư mục, nên trong thư mục đề xuất này chưa biên
   dịch được. Mục tiêu 0 lỗi, 0 cảnh báo.
2. Mã máy đọc lại giá trị qua tham chiếu đúng chỗ như bảng trên, không giữ giá trị cũ
   qua lời gọi API.
3. `volumes[strategy_index]*0.0` không bị gộp thành hằng; thứ tự phép tính
   `distance*unit+(point+position.tp)` được giữ.
4. Chuỗi suffix đúng từng ký tự (hai dấu cách trước `Trying`).
5. So từng lối ra với EX5 gốc trên cùng dữ liệu (chưa làm).
6. Guard là `BOT3_REAL_TAKE_SELL_MQH`; nếu ghép chung tệp với bản mua
   (`bot3-real-take-buy-20261025-r1`) thì đổi guard khi ghép.

## Cấu hình lượt này

- Mô hình theo môi trường phiên: `claude-opus-5-5`. Mức `max`: không tự kiểm được từ bên trong.
- Ultracode: được yêu cầu, nhưng phiên không có công cụ Workflow và yêu cầu cấm tác tử
  lồng, nên làm một mình, không có đánh giá chéo.
- Không chạy lệnh shell; chỉ dùng công cụ đọc/tìm/ghi tệp.
