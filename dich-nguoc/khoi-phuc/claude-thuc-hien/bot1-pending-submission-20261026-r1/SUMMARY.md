# SUMMARY: bot1-pending-submission-20261026-r1

## Đã viết

- `Bot1PendingSubmission.mqh` trong thư mục này: 126 dòng, chỉ ký tự ASCII,
  xuống dòng LF. Grep không thấy ký tự ngoài ASCII hay `\r`.
  - Guard `BOT1_PENDING_SUBMISSION_MQH`. Include cùng thư mục đúng 5 tệp:
    `Bot1PriceLevels.mqh`, `Bot1Margin.mqh`, `Bot1VolumeValidation.mqh`,
    `Bot1TradeSend.mqh`, `Bot1TradeErrors.mqh`. Không include `Bot1OrderScan.mqh`.
  - `struct Bot1PendingSubmissionSettings` và chữ ký
    `Bot1SubmitPendingAfterPrice(...)` chép đúng theo TASK.md.
  - `Bot1SubmissionDifference(left,right)` có thân đúng 3 dòng như TASK.
  - Một hàm nội bộ `Bot1SendPendingEntry(first_attempt,...)` làm quy trình C.
    Lần đặt đầu gọi với `true`, mỗi lần thử lại gọi với `false`.
- Muốn biên dịch thì phải chép tệp vào
  `bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/`, vì include dùng đường
  cùng thư mục. Tôi không chép, không sửa nguồn chính, Git hay MT5.

## Đối chiếu mô tả với mã

Số dòng tính trong `Bot1PendingSubmission.mqh`. Bảng bỏ tiền tố `settings.`
cho gọn.

| Mục | Dòng | Cách viết |
|---|---|---|
| Struct | 9-18 | Tên, kiểu và thứ tự trường đúng TASK |
| Hàm trừ | 19-25 | `if(left!=left) return left+0.0; if(right!=right) return right+0.0; return left-right;` |
| 1 | 61-70 | Chỉ chạy khi cờ `!=0`. Đọc `volumes[strategy_index]` trước, rồi chép `symbol`. Gọi `Bot1MarginGuard(symbol, BUY/SELL, volume)`. False: Print đúng chuỗi rồi return |
| 2 | 71-74 | Digits lần 1 (uint), sau đó mới đọc `unit`. `unit*(buy ? 0.0 : -0.0)+base_price` rồi `Bot1RoundPrice` |
| 3 | 75-78 | Digits lần 2. Mua: `Bot1SubmissionDifference(base_price,(stop_distance+0.0)*unit)`. Bán: `((stop_distance+0.0)*unit)+base_price` |
| 4 | 79-82 | Digits lần 3. Mua: `take_distance*unit+base_price`. Bán: `Bot1SubmissionDifference(base_price,take_distance*unit)`. Luôn chạy, kể cả khi `omit_real_sl_tp!=0` |
| 5 | 83-84 | Đọc lại volume, `Bot1ValidateVolume(settings.symbol,volume)`. False thì return |
| 6 | 85-87 | `int limit=(int)AccountInfoInteger(ACCOUNT_LIMIT_ORDERS);` rồi `if(limit!=0 && OrdersTotal()>=limit) return;` |
| 7 | 88-99 | Chụp ask/bid một lần. Kiểm freeze trước, stop sau, đúng thứ tự toán hạng. Dạng `if(!(a<b)) return;` nên NaN dẫn tới return |
| 8 | 100 | `bool accepted=Bot1SendPendingEntry(true,...)` |
| 9 | 101-112 | Chỉ khi lần đầu true. Hàng đầu có cột 0 `==0.0` nhận `(double)(uint)accepted` và `base_price` chưa làm tròn, rồi return. Bảng đầy thì return, không đổi bảng |
| 10 | 113-118 | `while(GetLastError()==132) { Sleep(2500); Bot1SendPendingEntry(false,...); }`. Bỏ qua bool trả về. Không giới hạn vòng, không IsStopped, không ResetLastError |
| 11 | 119-124 | Luôn chạy khi ra khỏi vòng, kể cả khi lần thử lại trả true. Ghép chuỗi đúng thứ tự rồi Print. Không ghi bảng, không reset lỗi hay `error_count` |
| C | 26-54 | Lần đầu: đọc `omit_real_sl_tp` rồi `expiration`. Thử lại: đọc `expiration` rồi `omit_real_sl_tp`. Dùng `omit` đã chụp để chọn sl/tp (0: sl/tp cục bộ; khác 0: 0.0/0.0). Sau đó chép `comment`, đọc lại volume, chép `symbol`, gọi `Bot1OpenPending` với magic và `virtual_expiration` đọc ngay lúc gọi, kiểu `ORDER_TYPE_BUY_STOP`/`ORDER_TYPE_SELL_STOP` (4/5) |

Giữ nguyên qua mọi lần thử, truyền theo giá trị: `buy`, `base_price`, `price`,
`sl`, `tp`. Không tính lại giá, không gọi Digits khi thử lại. `settings`,
`volumes`, `strategy_index`, `trade`, `options`, `results`, `error_count`
vẫn là tham chiếu, không chụp sớm.

## Khác biệt bot1 so với bot3

So với `bot-cua-toi-3/source/.../Bot3PendingSubmission.mqh` hiện hành:

| Chỗ | bot3 | bot1 (tệp này) |
|---|---|---|
| Include | 6 tệp, có `Bot3OrderScan.mqh` | 5 tệp, không có OrderScan |
| Bước 6 | Gọi `Bot3AllowsPendingOrder()` | Đọc thẳng `(int)AccountInfoInteger(ACCOUNT_LIMIT_ORDERS)`. Chỉ khi `limit!=0` mới gọi `OrdersTotal()`; `>=limit` thì return |
| Quy trình C | Mọi lần đều đọc `expiration` trước `omit_real_sl_tp` | Lần đầu đọc `omit_real_sl_tp` trước; thử lại đọc `expiration` trước. Thêm tham số `first_attempt` |
| Tên | Tiền tố `Bot3` | Tiền tố `Bot1` |

Bước 1-5 và 7-11 viết giống bot3, chỉ đổi tiền tố tên.

## Khác chữ trong mô tả nhưng cùng giá trị

- Bước 1 đặt tên `margin_volume`, `margin_symbol` như bot3, thay cho `volume`,
  `symbol`. Thứ tự đọc giữ nguyên.
- Ba lần Digits dùng lại một biến `digits` như bot3, thay cho
  `digits1/2/3`. Mỗi lần vẫn là một lời gọi `SymbolInfoInteger` mới.
- Bước 2 tách thành `raw_price` rồi `Bot1RoundPrice(raw_price,digits)`.
  Biểu thức không đổi.
- Bước 6 dùng `&&`. Theo tài liệu MQL5, `&&` dừng khi vế trái false, nên
  `limit==0` thì không gọi `OrdersTotal()`. Tôi chưa chạy để kiểm điều này.
- Tên `Bot1SendPendingEntry` là tên tôi đặt. Grep trong
  `bot-cua-toi-1/source` và `claude-thuc-hien` không thấy trùng tên này,
  tên struct, tên hàm công khai hay tên guard.

## Chưa làm / cần kiểm

- Chưa biên dịch, chưa chạy, chưa viết bộ kiểm. Chưa có bằng chứng chạy nào.
- Điểm Codex nên kiểm:
  1. Dòng 34-45: `omit` và `expiration` khai báo không có giá trị đầu và được
     gán ở cả hai nhánh if/else. Tôi không thêm giá trị mặc định. Cần xem
     trình biên dịch có cảnh báo "possible use of uninitialized variable" không.
  2. Bước 6: `limit==0` thì không gọi `OrdersTotal()`. Giá trị 64 bit bị cắt
     về int32 có dấu, ví dụ `0x100000000` thành 0 (không giới hạn), còn
     `0xFFFFFFFF` thành -1 (luôn return vì `OrdersTotal()>=-1`).
  3. Thứ tự đọc `omit_real_sl_tp`/`expiration` ở lần đầu và lần thử lại.
     Thứ tự này chỉ thấy được khi có cách theo dõi lần đọc; cần cách kiểm
     riêng của Codex.
  4. Các ca như bot3: `-0.0`, NaN/inf ở `unit`, `stop_distance`,
     `take_distance`, `base_price`. NaN ở bước 7 phải dẫn tới return. Cột 0
     là NaN thì không phải hàng trống; `-0.0` là hàng trống vì `-0.0==0.0`.
  5. Vòng thử lại: lần thử lại trả true mà mã lỗi vẫn 132 thì vẫn lặp. Ra
     khỏi vòng luôn báo lỗi, `error_count` tăng đúng 1, không ghi `results`.

## Đã đọc để làm

- TASK.md của lượt này, `AGENTS.md` (trong lời nhắc), `tai-lieu-cu/QUY-TRINH.md`.
- Header bot1 cần dùng: `Bot1PriceLevels.mqh`, `Bot1Margin.mqh`,
  `Bot1VolumeValidation.mqh`, `Bot1TradeSend.mqh`, `Bot1TradeErrors.mqh`.
  Thêm ba tệp include gián tiếp: `Bot1PendingRequest.mqh`,
  `Bot1TradeMessages.mqh`, `Bot1Filling.mqh`. Tôi đọc để xem có biến toàn cục
  trùng tên biến cục bộ không: không có biến toàn cục nào.
- Mẫu: `Bot3PendingSubmission.mqh` hiện hành; SUMMARY r2 và r3 của bot3 để
  theo cách trình bày.
- Không đọc EX5, mã máy hay thư mục phân tích.

## Cấu hình lượt này

- Môi trường báo mô hình là `claude-opus-5-5` (Opus 5.5) và ultracode đang
  bật. Từ bên trong tôi không tự kiểm được mức effort `max`; Codex kiểm riêng.
- Phiên này không có công cụ Workflow. TASK cấm tạo tác tử và dùng shell, nên
  tôi làm một mình và không chạy lệnh nào.
