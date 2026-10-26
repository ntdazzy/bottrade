# SUMMARY: bot3-pending-submission-20261026-r2

## Đã viết

- `Bot3PendingSubmission.mqh` trong thư mục này (105 dòng, chỉ ký tự ASCII).
  - Guard `BOT3_PENDING_SUBMISSION_MQH`; include cùng thư mục đúng 6 tệp:
    `Bot3PriceLevels.mqh`, `Bot3Margin.mqh`, `Bot3VolumeValidation.mqh`,
    `Bot3OrderScan.mqh`, `Bot3TradeSend.mqh`, `Bot3TradeErrors.mqh`.
  - `struct Bot3PendingSubmissionSettings` và chữ ký
    `Bot3SubmitPendingAfterPrice(...)` chép đúng theo TASK.md.
  - Một hàm phụ `Bot3SendPendingEntry(...)` làm quy trình C. Lần đặt đầu và
    mọi lần thử lại đều gọi hàm này. Không tạo lớp hoặc callback.
- Tệp nằm trong thư mục đề xuất. Muốn biên dịch thì phải chép vào
  `bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/`, vì các include dùng
  đường cùng thư mục. Tôi không chép tệp và không sửa nguồn chính, Git hay MT5.

## Đối chiếu mô tả với mã

Số dòng tính trong `Bot3PendingSubmission.mqh`. Trong bảng bỏ tiền tố
`settings.` cho gọn.

| Mục | Dòng | Cách viết |
|---|---|---|
| Struct | 10–19 | Tên, kiểu và thứ tự trường đúng như TASK.md |
| 1 | 42–51 | Chỉ chạy khi cờ `!=0`. Đọc `volumes[strategy_index]` trước, sau đó mới chép `symbol`. Gọi `Bot3MarginGuard(symbol, BUY/SELL, volume)`. Nếu false: `Print` đúng chuỗi rồi return |
| 2 | 53–55 | Digits lần 1 (uint), sau đó mới đọc `unit`. Tính `unit*(buy ? 0.0 : -0.0)+base_price`, nhân trước cộng sau, rồi `Bot3RoundPrice` |
| 3 | 56–59 | Digits lần 2. Mua: `base_price-((stop_distance+0.0)*unit)`. Bán: `((stop_distance+0.0)*unit)+base_price` |
| 4 | 60–63 | Digits lần 3. Mua: `take_distance*unit+base_price`. Bán: `base_price-take_distance*unit`. Luôn chạy, kể cả khi `omit_real_sl_tp!=0` |
| 5 | 64–65 | Đọc lại volume, gọi `Bot3ValidateVolume(settings.symbol,volume)`. Nếu false thì return |
| 6 | 66 | Gọi `Bot3AllowsPendingOrder()`. Nếu false thì return |
| 7 | 67–78 | Đọc ask/bid một lần vào biến cục bộ. Kiểm mức freeze trước, mức stop sau. Thứ tự toán hạng giữ như mô tả. Viết dạng `if(!(a<b)) return;`, nên NaN dẫn tới return |
| 8 | 79 | Lưu `bool accepted` của lần đặt đầu |
| 9 | 80–91 | Chỉ chạy khi lần đặt đầu trả true. Hàng đầu tiên có cột 0 `==0.0` nhận `(double)(uint)accepted` và `base_price` chưa làm tròn, rồi return. Bảng đầy thì return và không đổi bảng |
| 10 | 92–97 | `while(GetLastError()==132) { Sleep(2500); đặt lại; }`. Bỏ qua bool trả về của lần đặt lại. Không giới hạn vòng, không có IsStopped |
| 11 | 98–103 | Luôn chạy khi ra khỏi vòng. Gọi `Bot3TradeErrorText(GetLastError(),error_count)`, ghép chuỗi đúng thứ tự rồi Print. Không ghi bảng, không reset mã lỗi hay `error_count` |
| C | 20–35 | Đọc `expiration`, rồi `omit_real_sl_tp` (0: dùng sl/tp đã tính; khác 0: 0.0/0.0). Sau đó chép `comment`, đọc lại volume, chép `symbol`. Cuối cùng gọi `Bot3OpenPending`, trong đó magic và `virtual_expiration` được đọc ngay lúc gọi, kiểu lệnh là `ORDER_TYPE_BUY_STOP`/`ORDER_TYPE_SELL_STOP` (4/5) |

Các giá trị cục bộ giữ nguyên qua mọi lần thử là `buy`, `base_price`,
`price`, `sl` và `tp`; chúng được truyền theo giá trị vào hàm phụ.
`settings`, `volumes`, `strategy_index`, `trade`, `options`, `results` và
`error_count` vẫn là tham chiếu, không được chụp sớm.

## Khác chữ trong mô tả nhưng cùng giá trị

- Bước 2, phía mua: viết `0.0` thay cho `+0.0`. Hai cách cùng giá trị. Tôi
  chưa kiểm được MQL5 có nhận dấu `+` một ngôi hay không, nên dùng `0.0`.
- Ba lần Digits dùng lại một biến `digits`. Mỗi lần vẫn là một lời gọi
  `SymbolInfoInteger` mới.
- Tên hàm phụ `Bot3SendPendingEntry` là tên tôi đặt. Đã tìm trong
  `dich-nguoc/khoi-phuc` và không thấy trùng tên này hoặc tên guard.

## Chưa làm / cần kiểm

- Chưa biên dịch, chưa chạy, chưa viết bộ kiểm. Tệp này chưa có bằng chứng
  chạy nào.
- Tôi chỉ đọc TASK.md và 6 header nêu trên. Chưa đọc `Bot3PendingRequest.mqh`
  và `Bot3TradeMessages.mqh` (được include gián tiếp qua `Bot3TradeSend.mqh`),
  nên chưa biết có cảnh báo tên cục bộ trùng biến toàn cục hay không.
- Những điểm Codex nên kiểm sau khi biên dịch:
  1. Hằng `-0.0` ở bước 2 vẫn là số không mang dấu âm. Phép nhân với `0.0`
     và phép `+0.0` ở bước 3 không bị trình biên dịch gộp hay bỏ. Nên thử
     với `base_price=-0.0` và `unit` là inf hoặc NaN.
  2. Ca NaN: ở bước 7, NaN phải dẫn tới return. Ở bước 9, cột 0 là NaN thì
     không được coi là hàng trống.
  3. Vòng ở bước 10 không có giới hạn, nên bộ kiểm phải cấp một dãy mã lỗi
     hữu hạn. Mã gọi thẳng `GetLastError()` và `Sleep()`, không bọc lại.
     Cần có ca lần đặt lại trả true mà mã lỗi vẫn là 132.
  4. Mỗi lần báo lỗi, `error_count` tăng đúng 1. Không ghi `results` sau
     bất kỳ lần thử lại nào.

## Cấu hình lượt này

- Môi trường báo mô hình là `claude-opus-5-5` (Opus 5.5) và ultracode đang
  bật. Từ bên trong tôi không tự kiểm được mức effort `max`; Codex kiểm riêng.
- Phiên này không có công cụ Workflow, và TASK.md cấm tạo tác tử, nên tôi
  không tạo tác tử con. Không chạy lệnh nào.
