# Bot1ManagementRealBlocksCheck — bản đề xuất của Claude

**Trạng thái: đã viết mã; chưa biên dịch, chưa chạy, chưa so với EX5 gốc.**
Chưa có kết quả kiểm nào, không gọi là đạt.

| Phần đã làm | Kết quả và phạm vi | Còn thiếu / bước tiếp |
|---|---|---|
| `Bot1ManagementRealBlocksCheck.mq5` | Chương trình cấp đầu vào/ghi kết quả cho 3 khối Bot1: dời dừng theo khoảng giá (stage 0), điều chỉnh sau kiểm trượt giá (stage 1), ghi dừng vào bảng (stage 5). Chỉ có dịch vụ giả, không gửi lệnh. | Codex đặt vào `bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/` (đường `#include` chỉ đúng ở đó), biên dịch, tạo `cases.bin`, lấy kết quả gốc độc lập để so. |
| `SUMMARY.md` | Tệp này. | — |

Không sửa nguồn chính, Git, MT5 hay ba header; không tạo header thay thế; không chạy lệnh; không tạo tác tử.

## Đã đọc

- Mẫu được phép: `bot-cua-toi-3/.../Bot3ManagementRealBlocksCheck.mq5`,
  `claude-thuc-hien/bot3-real-blocks-check-20261025-r1/CONTRACT.md`; `TASK.md`; `AGENTS.md`; `tai-lieu-cu/QUY-TRINH.md`.
- Header Bot1 hiện hành, chỉ để lấy kiểu và thứ tự nạp: `Bot1ManagementRealDistance`, `Bot1ManagementRealSlippage`,
  `Bot1ManagementRealStore`, `Bot1ManagementPrelude`, `Bot1VirtualStops`, `Bot1ManagementMessages`, `Bot1TradeErrors`,
  `Bot1PositionModify`, `Bot1PositionClose`, `Bot1TradeSend`, `Bot1PendingRequest` (đoạn đầu), `Bot1PriceLevels`,
  `Bot1ManagementVirtualFinish`.
- Grep: các dòng `#include`, `struct`, `#define` và biến toàn cục trong `Include/bot-cua-toi-1`; các dòng
  `#include`/`#property`/`#define` của `Bot1ManagementRealTimedCheck.mq5` (chỉ để khớp dạng đường dẫn).
- Không đọc: EX5, mã máy, thư mục phân tích, nguyên nhân lịch sử, header Bot3.

## Yêu cầu → mã (số dòng trong `.mq5`)

| Yêu cầu | Dòng |
|---|---|
| `input CheckRun`; tên 1..50 ký tự `a-z0-9-`; thư mục `Files/bot1-management-real-blocks/<CheckRun>/`; không ghi đè | 7, 274–283 |
| Đầu vào: magic `0x4d524231`, version 1, count 1..100000, kích thước `12+440*count` | 284–287 |
| Đọc hết ca 440 byte `<22iqQII41d` rồi mới kiểm | 200–228 |
| Kiểm ca: id đúng thứ tự, buy 0/1, chỉ stage 0/1/5, scenario 0..11, index 0..7, 6 cờ 0..255, prior_changed 0/1, table_pattern 0..5, modify_ok 0/1 | 229–233, 267 |
| state/options ZeroMemory, bảng theo pattern, `changed` lấy từ `prior_changed` | 234–236 |
| Stage 0: `Bot1AdvanceDistanceBuyStop/SellStop`, 19 đối số đúng thứ tự, `returned` là bool thật | 170–180 |
| Stage 1: `Bot1AdvanceSlippageRealBuyStop/SellStop`, 17 đối số; `returned=false` | 181–191, 194 |
| Stage 5: `Bot1StoreRealStop(symbol,initial_stop,current_stop,ticket_number,table)`; `returned=false` | 192–194 |
| Sự kiện 5 uint64, FNV-1a 64 LE, chữ UTF-16LE | 27–50 |
| Mutate đúng danh sách của TASK; `index=(index+1)%8` rồi `levels[index]+=1.25` | 51–63 |
| DIGITS (tối đa 4 lần, đích 1/3/4/5), POINT (tối đa 2 lần, đích 2/6), VOLUME_MIN (10), GetLastError giả, Print (8/9), Modify (7), TryClose (11) | 64–112 |
| Prelude/VirtualStops trước macro; Messages và 3 header sau macro; bỏ macro ngay sau đó | 4–6, 113–130 |
| Bảng `rows[500][3]` = `{10000+i,20000+i,-30000-i}`, guard từ ca, pattern 0..5 (5: NaN bits `0x7ff8000000000011` ở hàng 0, vé ở hàng 499); băm 1500 ô theo hàng/ô | 133–165 |
| Kết quả 384 byte `<5iIIQ41diQQ` (so bit: `<5iIIQ41QiQQ`); double ghi nguyên bit | 238–257 |
| `script-status.bin` = fault, count (2 int32); giữ lỗi đầu; `Print` cuối là Print thật | 25, 289–293 |

Mã lỗi giống mẫu: 1 gọi DIGITS sai, 2 gọi POINT/VOLUME_MIN sai, 7 đầu/kích thước sai, 8 không mở được tệp
kết quả, 9 ca sai (dừng trước khi gọi khối), 10 chưa đọc hết tệp. OnStart trả 4 (tên sai), 5 (đã có kết quả),
6 (không mở được `cases.bin`), 11 (không mở được tệp trạng thái); các trường hợp này không ghi tệp trạng thái.

## Khác mẫu Bot3

Chỉ các chỗ TASK nêu hoặc giao diện Bot1 buộc:

1. Tên/kiểu Bot1: magic, thư mục, `Bot1PendingRequestState`, `Bot1TradeSendOptions`, `Bot1VirtualStopState`,
   `Bot1ManagedPosition`, `BOT1_VIRTUAL_STOP_ROWS`, macro `Bot1ModifyPosition`/`Bot1TryClosePosition`.
2. Ca 440 byte, kết quả 384 byte; `volumes`/`levels` 8 phần tử; index 0..7; Mutate `%8`.
3. Chỉ nhận stage 0, 1, 5 (giữ số 5).
4. Bảng không có `take_rows`; băm chỉ 1500 ô.
5. Không nạp `Bot1ManagementVirtualFinish.mqh`: ba header không cần nó (nó chỉ nạp Prelude).
6. `gap_count`, `minimum_steps`, `eligible_flag`, `before_open`, `shift_setting`, `step_enabled` vẫn đọc đúng vị trí,
   các cờ vẫn kiểm 0..255. Ba khối không nhận các giá trị này nên chúng là biến cục bộ, không phải biến toàn cục như mẫu.

Giữ như CONTRACT: TryClose giả trả `true`. `Bot1TryClosePosition` thật là `void` (`Bot1PositionClose.mqh:31`), và
hai hàm dời dừng gọi nó như một câu lệnh (`Bot1ManagementRealDistance.mqh:53,104`), nên giá trị này không được đọc.

## Bằng chứng thứ tự nạp

- Trước macro: Prelude → PriceLevels, PositionModify → TradeSend → (TradeMessages, PendingRequest → Filling),
  PositionClose → TradeSend, VirtualStops → PriceLevels. Không tệp nào nạp `Bot1ManagementMessages.mqh` hay
  `Bot1TradeErrors.mqh` (grep `#include` cả thư mục). Vì vậy `Bot1PrintManagementError` (`Messages:8–14`) chạy với
  `GetLastError`/`Print` giả, còn `Bot1TradeErrorText` (`TradeErrors:4–6`) tự tăng bộ đếm lỗi thật.
- Các header Bot1 không khai báo biến toàn cục (grep), nên tên `Blocks*` không bị trùng.

## Codex cần kiểm khi ghép

- Biên dịch tại đích, hướng tới 0 lỗi/0 cảnh báo. Chỗ nên xem: chuỗi hằng `"CHECK"` truyền vào `const string &symbol`
  (mẫu Bot3 cũng làm vậy; header slippage Bot1 truyền chuỗi hằng vào `const string &suffix` ở dòng 41 và 79);
  hai biến cục bộ `gap_count`, `minimum_steps` chỉ đọc, không dùng.
- Kết quả mong đợi phải lấy từ bản gốc; tôi không tính.
- `reported_ticket` chỉ được ZeroMemory đặt 0. Theo TASK, ô này không nằm trong đầu ra hay băm, nên nếu có lệch
  ở ô này thì kết quả sẽ không cho thấy.
- `position.ticket_number/comment/opened/type/magic/symbol` để 0/rỗng; ba khối không đọc các trường này.

## Cấu hình lượt

- Mô hình: `claude-opus-5-5` (Opus 5.5), theo thông tin môi trường của lượt.
- Ultracode: thông báo hệ thống của lượt ghi là đang bật. Không dùng Workflow/tác tử con vì TASK cấm tạo tác tử.
- Mức `max`: được yêu cầu, nhưng trong lượt không có dữ liệu để tự xác nhận mức thực tế.
