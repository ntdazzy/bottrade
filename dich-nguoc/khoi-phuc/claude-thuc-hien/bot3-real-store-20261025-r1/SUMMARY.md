# Bot3ManagementRealStore.mqh — tóm tắt

## Kết quả
- Viết `Bot3ManagementRealStore.mqh` và tệp này trong
  `dich-nguoc/khoi-phuc/claude-thuc-hien/bot3-real-store-20261025-r1/`. Ghi vào thư mục gốc
  của kho bị từ chối quyền, nên dùng thư mục việc đã có sẵn `TASK.md` này.
- Include tương đối `Bot3ManagementPrelude.mqh`, `Bot3VirtualStops.mqh` (dòng 4-5). Hai tệp này nằm ở
  `dich-nguoc/khoi-phuc/bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/`; include chỉ tìm thấy khi
  Codex đặt tệp vào thư mục đó.
- Hàm duy nhất:
  `void Bot3StoreRealStop(const string &symbol,const double initial_stop,const double &current_stop,const double cached_ticket_number,Bot3VirtualStopState &table)`
- Đầu ra: không trả giá trị. Tác dụng phụ duy nhất có thể có: ghi `table.rows[r][1]` ở hàng khớp đầu tiên.

## Ba lần hỏi DIGITS và thứ tự đọc/ghi
Biến `digits` (uint) được dùng lại cho d1, d2, d3.
1. Dòng 11-12: DIGITS lần 1 `(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS)`;
   `previous=Bot3RoundPrice(initial_stop,d1)`.
2. Dòng 13-14: DIGITS lần 2; câu lệnh sau mới đọc `current_stop`; `current=Bot3RoundPrice(current_stop,d2)`.
3. Dòng 15: `if(previous==current) return;`
4. Dòng 16-17: DIGITS lần 3; đọc lại `current_stop`; `current=Bot3RoundPrice(current_stop,d3)`.
   Giá trị theo d2 chỉ dùng để so, không được lưu.
5. Dòng 18: sau DIGITS lần 3 mới đọc `table.guard`; `guard!=1` thì thoát.
6. Dòng 19-26: duyệt `row=0..BOT3_VIRTUAL_STOP_ROWS-1` (500), so `table.rows[row][0]==cached_ticket_number`;
   hàng khớp đầu tiên: `table.rows[row][1]=current; break;`.

Mỗi lần hỏi DIGITS là một câu lệnh riêng, đứng trước câu lệnh đọc `current_stop`, nên thứ tự không phụ
thuộc thứ tự tính đối số.

## Nhánh
| Nhánh | Số lần DIGITS | Đọc bảng | Ghi |
|---|---|---|---|
| `previous==current` | 2 | không | không |
| khác hoặc NaN, `guard!=1` | 3 | `guard` | không |
| khác hoặc NaN, `guard==1`, không hàng nào khớp | 3 | `guard`, ô vé cả 500 hàng | không |
| khác hoặc NaN, `guard==1`, có hàng khớp | 3 | `guard`, ô vé đến hàng khớp đầu tiên | `rows[r][1]=current`, chỉ hàng đầu tiên |

## NaN và giá trị đặc biệt
- Hai phép so đều là `==` có thứ tự: NaN ở bất kỳ bên nào cho false.
  - Dòng 15: `previous` hoặc `current` là NaN → coi là khác → hỏi DIGITS lần 3 và đi tiếp.
  - Dòng 21: ô vé hoặc `cached_ticket_number` là NaN → không khớp; `cached_ticket_number` là NaN thì không
    ghi hàng nào.
- Không lọc giá trị lưu: `current` là NaN hay 0 vẫn được ghi nếu có hàng khớp (mô tả không có luật lọc).
- Theo `==`, +0.0 bằng -0.0. Nếu `cached_ticket_number` là 0.0 thì hàng đầu tiên có ô vé 0.0 (hàng trống)
  sẽ khớp và bị ghi ô 1. Không thêm luật chặn vì mô tả không có; Codex nên đối chiếu với bản gốc.
- Vé so trực tiếp bằng double, không ép qua ulong/long.
- Phần NaN dựa vào việc `==` của MQL5 với double là so IEEE có thứ tự; chưa kiểm bằng biên dịch/chạy.

## Không làm
Không ghi `current_stop`, mức SL/TP, ô vé (cột 0), ô giờ (cột 2), `take_rows`, `guard`, `reported_*`,
bảng khác, mode/counter, cờ; không tạo hàng; không Tick/Modify/Close/Stamp; không NormalizeDouble;
không gộp kiểm chạm giá hay đóng lệnh vào hàm này.

## Phạm vi đọc
- Chỉ mở `dich-nguoc/khoi-phuc/bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/Bot3VirtualStops.mqh`:
  `BOT3_VIRTUAL_STOP_ROWS 500`, `Bot3VirtualStopState { double rows[500][3]; double take_rows[500][2];
  uchar guard; long reported_ticket; long reported_take_ticket; }`.
- Glob chỉ dùng để tìm vị trí tệp. Theo giới hạn của yêu cầu, không mở `TASK.md`,
  `Bot3ManagementPrelude.mqh`, `Bot3PriceLevels.mqh`, `QUY-TRINH.md`, EX5 hay phân tích lịch sử.
  Kiểu `Bot3RoundPrice(double,uint)` lấy từ mô tả và cách gọi trong `Bot3VirtualStops.mqh`.

## Trạng thái
- Chưa biên dịch, chưa chạy, chưa so với EX5. Codex kiểm, ghép và chạy.
- Không sửa nguồn chính, không dùng Git, không gửi lệnh, không động tới tác tử khác.

## Cấu hình phiên
- Mô hình theo thông tin môi trường: `claude-opus-5-5` (Opus 5.5). Ultracode: bật theo thông báo hệ thống
  của phiên. Mức `max`: không tự xác minh được từ bên trong phiên. Công cụ Workflow không có trong phiên
  này nên viết một mình.

## Ca nên kiểm
- Nhánh bằng nhau: đúng 2 lần DIGITS, không đọc/ghi bảng.
- `current_stop` hoặc digits đổi giữa các lần gọi: giá trị lưu phải theo lần đọc thứ 3 với d3.
- `guard` khác 1 tại lúc đọc (sau DIGITS lần 3): không ghi.
- Hai hàng cùng vé: chỉ hàng đầu được ghi.
- NaN ở `previous`, `current`, ô vé, `cached_ticket_number`; `cached_ticket_number=0.0` khi có hàng trống.
- Mọi ô khác ngoài `rows[r][1]` không đổi.
