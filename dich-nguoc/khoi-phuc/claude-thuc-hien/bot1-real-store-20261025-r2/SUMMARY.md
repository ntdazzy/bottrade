# Bot1ManagementRealStore.mqh — tóm tắt đề xuất

- Thư mục: `dich-nguoc/khoi-phuc/claude-thuc-hien/bot1-real-store-20261025-r2/`
- Tệp đã viết: `Bot1ManagementRealStore.mqh`, `SUMMARY.md`. Không sửa tệp nào khác.
- Lý do chọn r2: `TASK.md` của r1 và r2 giống hệt nhau; `TASK.md` của r2 mới hơn
  theo thời gian sửa. Không ghi gì vào r1.

## Trạng thái

- Chưa biên dịch, chưa chạy, chưa có ca kiểm nào, chưa so với EX5 gốc.
  Phiên này không được chạy lệnh.
- Không tuyên bố hoàn thành 100%. Codex kiểm, ghép và so với bằng chứng.

## Cấu hình phiên

- Mô hình theo thông tin môi trường của phiên: `claude-opus-5-5` (Opus 5.5).
- Ultracode: lời nhắc hệ thống của phiên ghi là đang bật.
- Mức `max`: không tự kiểm được từ bên trong phiên.
- Không tạo tác tử hay Workflow (theo yêu cầu; phiên này cũng không có công cụ Workflow).

## Đã đọc

- `TASK.md` của r1 và r2 (để chọn thư mục).
- Chỉ các header trong `dich-nguoc/khoi-phuc/bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/`:
  - `Bot1PriceLevels.mqh`: `double Bot1RoundPrice(const double price,const uint digits)`.
  - `Bot1VirtualStops.mqh`: `#define BOT1_VIRTUAL_STOP_ROWS 500`; `Bot1VirtualStopState`
    gồm `double rows[BOT1_VIRTUAL_STOP_ROWS][3]`, `uchar guard`, `long reported_ticket`.
  - `Bot1ManagementPrelude.mqh`, `Bot1ManagementRealTimed.mqh`,
    `Bot1ManagementVirtualFinish.mqh`: chỉ để theo cách viết (guard, include, đặt tên).
- Không đọc EX5, mã máy, tài liệu phân tích, bằng chứng hay đề xuất khác.

## Giao diện

```mql5
void Bot1StoreRealStop(const string &symbol,const double initial_stop,const double &current_stop,
                       const double cached_ticket_number,Bot1VirtualStopState &table)
```

Guard `BOT1_MANAGEMENT_REAL_STORE_MQH`; include `Bot1ManagementPrelude.mqh` và
`Bot1VirtualStops.mqh`.

## Đặc tả → mã

| Bước | Đặc tả | Dòng |
|---|---|---|
| 1 | Gọi DIGITS lần 1 → `uint digits`; `previous=Bot1RoundPrice(initial_stop,digits)` | 10–11 |
| 2 | Gọi DIGITS lần 2, sau đó mới đọc `current_stop`; `current=Bot1RoundPrice(current_stop,digits)` | 12–13 |
| 3 | `previous==current` → `return` (so sánh thường, không epsilon) | 14 |
| 4 | Gọi DIGITS lần 3, sau đó đọc lại `current_stop`; gán lại `current` | 16–17 |
| 5 | Sau cả 3 lần đọc/làm tròn mới đọc `table.guard`; khác 1 → `return` | 18 |
| 6 | Duyệt `row` từ 0 đến `BOT1_VIRTUAL_STOP_ROWS-1`; dòng khớp đầu tiên `rows[row][0]==cached_ticket_number` → ghi `current` vào `rows[row][1]`, rồi `break` | 19–24 |

Mỗi lần đọc `current_stop` nằm trong câu lệnh riêng, sau câu lệnh gọi DIGITS; không
chép `current_stop` vào biến tạm từ trước. Cả 3 lần gọi đều dùng thẳng `symbol` qua
tham chiếu.

## Những việc hàm không làm

Không kiểm chế độ, không đóng lệnh, không ghi `current_stop` (tham số `const`), không tạo
dòng, không ghi cột 0 hoặc cột 2, không đổi `guard`, không ghi `reported_ticket`, không gọi
hàm nào ngoài `SymbolInfoInteger` và `Bot1RoundPrice`.

## Ghi chú cho Codex

- Include dùng đường dẫn tương đối. Muốn biên dịch, phải đặt tệp vào
  `source/MQL5/Include/bot-cua-toi-1/`, vì thư mục đề xuất không có các header kia.
- `Bot1ManagementPrelude.mqh` đã include sẵn `Bot1VirtualStops.mqh`. Include thứ hai được
  giữ theo đặc tả; guard `BOT1_VIRTUAL_STOPS_MQH` chặn nạp lặp.
- Thân hàm có cùng trình tự với `Bot1StoreVirtualStop` (`Bot1ManagementVirtualFinish.mqh:105-123`).
  Chỉ khác tên tham số và dùng `break` thay cho `return` sau khi ghi; tác dụng như nhau vì sau
  vòng lặp không còn lệnh nào. Đề xuất này không gọi lại hàm đó vì đặc tả chỉ cho phép hai
  include trên. Codex quyết định có gộp hay không.

## Gợi ý ca kiểm (chưa chạy)

Có thể dùng `#define` trước khi include để thay `SymbolInfoInteger` bằng một hàm thử. Hàm
thử đếm số lần gọi và đổi `current_stop`/`guard` ngay trong lúc được gọi. Cách này chưa thử
biên dịch.

1. `previous==current`: gọi DIGITS đúng 2 lần, không đọc `guard`, bảng không đổi.
2. Khác nhau và `guard!=1`: gọi DIGITS 3 lần, bảng không đổi.
3. `guard==1`, ticket khớp ở dòng k và ở cả một dòng sau: chỉ `rows[k][1]` đổi, nhận giá trị
   làm tròn ở lần 3.
4. Không có dòng nào khớp: bảng không đổi.
5. Hàm thử đổi `current_stop` hoặc `guard` ngay trong lần gọi DIGITS thứ 2 hoặc thứ 3: hàm
   phải dùng giá trị đã đổi.
6. `cached_ticket_number` hoặc `rows[row][0]` là NaN: không khớp (vì dùng `==` thường).
