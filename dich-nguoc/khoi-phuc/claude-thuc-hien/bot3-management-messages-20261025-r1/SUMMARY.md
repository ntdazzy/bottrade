# Tóm tắt — `Bot3PrintManagementError` bot 3 (r1)

Trạng thái thật: **chỉ là ứng viên. Chưa biên dịch, chưa chạy, chưa so với
EX5 gốc; không có ca kiểm nào.** Chỉ ghi `Bot3ManagementMessages.mqh` và tệp
này (`TASK.md` giữ nguyên). Không sửa `bot-cua-toi-3/source/`. Không đọc EX5,
mã máy hay bản phân tích lịch sử; không chạy lệnh, Git hay MT5.

Logic chỉ lấy từ đặc tả `TASK.md` dòng 5. Chữ ký thư viện lấy từ
[Bot3TradeErrors.mqh:4](../../bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/Bot3TradeErrors.mqh):
`string Bot3TradeErrorText(const int code,uint &error_count)`. Ngoài ra chỉ
đọc `QUY-TRINH.md`, nguồn chính `Bot3PendingQueue.mqh`, `Bot3TradeMessages.mqh`,
`Bot3ManagementPrelude.mqh` và hai tệp đề xuất bên cạnh (virtual-start,
slippage) để viết cùng kiểu.

## Điều đã giữ

Số dòng là dòng trong [Bot3ManagementMessages.mqh](Bot3ManagementMessages.mqh).

| Đặc tả | Mã |
|---|---|
| Chặn include `BOT3_MANAGEMENT_MESSAGES_MQH`; include `Bot3TradeErrors.mqh` có sẵn | :3–5, :15 |
| `void Bot3PrintManagementError(const string &suffix,uint &error_count)` | :8 |
| Đọc `GetLastError()` đúng 1 lần vào `int code` | :10 |
| Gọi `Bot3TradeErrorText(code,error_count)` đúng 1 lần, lưu vào `string result` | :11 |
| `message="TrailStop error: '"+result+suffix`, nối trái sang phải | :12 |
| `Print(message)` đúng 1 lần | :13 |
| Không `ResetLastError`, không gọi API/truy vấn khác, không thêm tiền tố, thời gian hay xuống dòng | :10–13 |
| Bộ đếm chỉ đổi trong thư viện (`error_count++`, `Bot3TradeErrors.mqh:6`); hàm mới không tự đọc/ghi bộ đếm | :11 |
| Không viết lại `Bot3TradeErrorText`; không có hàm rỗng/TODO | toàn tệp |

## Thứ tự đọc/ghi

1. `GetLastError()` → `code`. `_LastError` không bị đặt lại.
2. `Bot3TradeErrorText`: tăng `error_count` trước, rồi chọn chuỗi theo `code`
   (thứ tự này nằm sẵn trong thư viện).
3. Nối `"TrailStop error: '"` → `result` → `suffix`.
4. `Print(message)`.

Mỗi bước là một câu lệnh riêng, nên thứ tự không phụ thuộc thứ tự tính đối số.

## Kiểu số và chuỗi

- `GetLastError()` trả `int`; `code` là `int`, truyền vào `const int code` — không ép kiểu.
- `error_count` (`uint &`) truyền thẳng vào `uint &error_count` của thư viện —
  không sao chép, không ép kiểu.
- Không có số thực, không làm tròn; không có giá nên không dùng
  `Bot3RoundPrice`/`NormalizeDouble`.
- Chuỗi cố định kết thúc bằng một dấu `'`; không thêm dấu đóng — phần sau
  `result` chỉ là `suffix`. Dấu `'` trong chuỗi nháy kép không cần thoát
  (cùng dạng `Bot3TradeErrors.mqh:51`).

## Điểm còn thiếu, cần Codex kiểm

1. Chưa biên dịch. Include tương đối: phải đặt tệp trong `Include/bot-cua-toi-3/`
   cạnh `Bot3TradeErrors.mqh`; thư mục đề xuất này không có tệp include đó.
2. Đặc tả không ghi địa chỉ native, nơi gọi hay giá trị `suffix` (có dấu `'`
   đóng không, mua/bán khác nhau không). Mã không tự điền; chú thích đầu tệp
   không ghi địa chỉ.
3. Đặc tả không ghi biến bộ đếm nào được truyền vào `error_count`. Hàng đợi
   lệnh chờ dùng `queue.error_count` (`Bot3PendingQueue.mqh:11,86`); chưa biết
   phần quản lý dùng chung hay riêng.
4. `suffix` do bên gọi tính trước khi vào hàm, tức trước lần đọc
   `GetLastError()`. Nếu bản gốc dựng phần đuôi sau khi đọc mã lỗi, hoặc dựng
   bằng API có thể đổi `_LastError`, cần kiểm thứ tự ở nơi gọi.
5. `suffix` là `const string &` theo đặc tả; nếu bên gọi truyền hằng hoặc biểu
   thức chuỗi, cần xem trình biên dịch có nhận không.
6. Tên cục bộ `code`, `result`, `message`: tìm trong `bot-cua-toi-3/source`
   không thấy biến toàn cục cùng tên (chỉ có biến cục bộ trong script kiểm).
   Chưa có EA chính nên chưa kiểm cảnh báo "hides global declaration".
7. Chưa có bộ kiểm. Ca nên có: mã 0, 1; mã trong bảng (130, 4108); mã ngoài
   bảng (−1, 10016 → `unknown error ...`); bộ đếm tăng đúng 1 mỗi lần gọi, cả
   khi đang là `4294967295`; `suffix` rỗng hoặc có `'`; `_LastError` sau lời
   gọi vẫn như trước; dòng in khớp từng ký tự với bản gốc.

## Cấu hình phiên

Mô hình theo thông tin hệ thống: `claude-opus-5-5`; thông tin phiên ghi
"Ultracode is on". Mức `max` không tự kiểm được. Không dùng Workflow hay tác
tử phụ (đặc tả cấm tác tử lồng); chỉ dùng Read/Grep/Glob/Write và tự đối
chiếu từng câu đặc tả với mã.
