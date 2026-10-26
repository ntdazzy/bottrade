# Bot3PreparationCheck — chọn riêng một ca để quan sát lỗi runtime

## Trạng thái

- Đã viết bản đầy đủ `Bot3PreparationCheck.mq5` (376 dòng) trong thư mục này theo `TASK.md`, sửa từ
  Script hiện hành `bot-cua-toi-3/source/MQL5/Scripts/bot-cua-toi-3/Bot3PreparationCheck.mq5` (366 dòng).
- **Chưa biên dịch, chưa chạy, chưa đối chiếu** với EX5 gốc hay với lượt chạy trước.
- Không sửa nguồn chính, Git, MT5; không chạy lệnh; không tạo tác tử; không đọc EX5, mã máy hay tài
  liệu phân tích. Không đổi hàm chuẩn bị, dữ liệu, công thức, dịch vụ giả; không tự tính kết quả mong đợi.
- Cấu hình lượt: môi trường ghi mô hình `claude-opus-5-5`, Ultracode bật. Tôi không tự kiểm được mức
  `max` từ trong lượt. Không có công cụ workflow và TASK cấm tạo tác tử, nên làm một mình.

## Nguồn đã đọc (từ `dich-nguoc/khoi-phuc/`)

- `claude-thuc-hien/bot3-preparation-fault-check-20261026-r1/TASK.md`.
- Script hiện hành nêu trên.
- `claude-thuc-hien/bot3-preparation-check-20261026-r1/SUMMARY.md` (bảng mã trả cũ).
- Chỉ tìm, không đọc thân tệp: `OnlyCase|selected_count|#define|FileFlush|PREPARATION_CASE` trong
  `bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/`. Không có tên trùng; `#define` ngoài guard chỉ có
  `BOT3_VIRTUAL_STOP_ROWS` (`Bot3VirtualStops.mqh:5`). Không macro nào đổi `Print` hay `FileFlush`.

## Phần sửa (dòng tệp mới ← dòng Script hiện hành)

| TASK | Dòng mới | Sửa |
|---|---|---|
| 1 | `:9-10` (sau `:8`) | chú thích + `input int OnlyCase=-1;` ngay sau `CheckRun` |
| 1 | `:349-350` (sau `:345-346`) | sau kiểm magic/version/bot/count/cỡ (mã 7): `OnlyCase<-1 \|\| OnlyCase>=count` → `FileClose(source)`, trả 12; chưa mở `mql5-results.bin` |
| 2 | `:351`, `:355` (← `:350`) | `selected_count=OnlyCase<0 ? count : 1`; chỉ trường count của đầu `mql5-results.bin` đổi; `0x50525033`, 1, 76 giữ |
| 3 | `:358-362` | đọc đủ 268 byte, kiểm id==i (sai → lỗi 9, `break`), rồi mới `continue` cho ca khác `OnlyCase`; không `break` sau ca được chọn |
| 4, 5 | `:363-366` | `Print("PREPARATION_CASE:",i);` → `FileFlush(output);` → `PrepRunCase(output,i,r);` |
| 6 | `:368`, `:372` (← `:358`, `:362`) | kiểm `FileTell` vẫn sau vòng; `script-status.bin` = (lỗi đầu tiên, `selected_count`), chỉ ghi khi tới cuối |
| 7 | `:366` | id truyền vào vẫn là `i` của `cases.bin`, không đánh lại |
| — | `:374` (← `:364`) | `Print` cuối in `selected_count` (xem mục "Lựa chọn của tôi") |

Thêm 10 dòng, sửa 3 dòng; phần còn lại chép nguyên. Kiểm bằng đếm dòng khớp mẫu trên hai tệp (không
phải diff): dòng không rỗng 364 → 374; `FileWriteLong\(output,` 76 = 76;
`FileRead|PrepFail\(|inputs\.|ValueBits|^#` 168 = 168;
`0x|\\\\|PrepExtra|PrepContext\.|Prep[A-Za-z]+Calls|state\.|return |if\(` 172 → 174 (đúng hai dòng mới
`:350`, `:362`).

Giữ nguyên: dịch vụ giả `:23-90`, 7 `#define`/`#include`/7 `#undef` `:91-106`, `PrepReadCase` `:124-170`,
`PrepFillInputs` `:171-228`, `PrepWriteResult` (success=1, 76 từ) `:229-315`, `PrepRunCase` `:316-331`,
cách đọc cờ `!=0`, mã trả 4–11, chặn ghi đè (mã 5).

## Hành vi theo mã (chưa chạy)

- `OnlyCase=-1` (mặc định): gọi mọi ca như Script hiện hành; byte của hai tệp đầu ra như cũ vì
  `selected_count=count`. Khác duy nhất: trước mỗi lệnh gọi có thêm một dòng log `PREPARATION_CASE:<i>`
  và một `FileFlush`.
- `OnlyCase=k` (`0≤k<count`): mọi ca vẫn được đọc và kiểm id theo thứ tự; chỉ ca k được gọi
  (`Bot3PrepareStrategy((uint)(k%9),…)` như cũ). `PrepContext` lúc gọi là của ca k vì ca k là ca đọc
  sau cùng trước lệnh gọi. Trả bình thường: `mql5-results.bin` = 16 byte đầu (count 1) + một bản ghi
  616 byte có id k; `script-status.bin` = (lỗi, 1); log cuối `Bot3PreparationCheck:<lỗi>,1`.
- Lỗi runtime trong `Bot3PrepareStrategy`: không bắt. Script dừng trong lệnh gọi, trước
  `PrepWriteResult`. Log có `PREPARATION_CASE:k` rồi dòng lỗi của MT5. `mql5-results.bin` chỉ có phần đã
  flush: 16 byte đầu (chế độ -1: 16 byte + bản ghi các ca trước). Không có bản ghi/success của ca k,
  không `script-status.bin`, `OnStart` không trả mã.
- id sai ở ca j: lỗi 9, dừng vòng. Nếu j<k thì ca k không chạy: đầu ghi count 1 nhưng 0 bản ghi,
  status (9, 1). Lỗi 10 sau đó không đè lỗi đầu tiên.
- `Print`/`FileFlush` không gọi dịch vụ thị trường, không đụng bộ đếm; bộ đếm vẫn chỉ đặt lại trong
  `PrepRunCase`.

## Mã trả

| Mã | Khi | Đầu ra |
|---|---|---|
| 4 | CheckRun sai | không |
| 5 | đã có `mql5-results.bin` hoặc `script-status.bin` | không ghi đè |
| 6 | không mở được `cases.bin` | không |
| 7 | magic, version, bot, count hoặc cỡ tệp sai | không |
| 12 (mới) | `OnlyCase<-1` hoặc `OnlyCase>=count` | không; đã đóng `cases.bin` |
| 8 | không mở được `mql5-results.bin` | không |
| 11 | không mở được `script-status.bin` | chỉ `mql5-results.bin` |
| 9, 10, 21–82 | như Script hiện hành | cả hai tệp, count = `selected_count` |
| không có | lỗi runtime | chỉ phần đã flush của `mql5-results.bin` |

## Lựa chọn của tôi ngoài chữ TASK

1. `Print` cuối (`:374`) in `selected_count` thay `count`, để log khớp hai từ của `script-status.bin`.
   Chế độ -1 không đổi. Muốn giữ `count` thì đổi một từ ở dòng này.
2. Ở chế độ -1 mọi ca đều là ca được chọn (`selected_count=count`), nên `Print` và `FileFlush` chạy trước
   mọi ca. Nhờ vậy lượt đủ bị lỗi cũng cho biết ca lỗi qua log.
3. Bốn dòng chú thích mới (`:9`, `:349`, `:361`, `:363`). Chú thích của `OnlyCase` nằm dòng riêng nên
   không thành tên hiển thị của đầu vào.

## Giới hạn

- Chưa biên dịch/chạy/đối chiếu; hành vi trên chỉ đọc từ mã.
- Ca lỗi chỉ kiểm được theo loại lỗi MT5 ghi trong log và việc không trả về bình thường (không status,
  không bản ghi). Script không ghi state, bộ đếm hay dịch vụ đã gọi trước lỗi, nên chưa đủ so mọi trạng
  thái trước lỗi. Vị trí dòng trong log là của nguồn mới, không so được với EX5. Chưa so toàn EA, chưa
  chạy hai bot song song.
- Sau lượt lỗi, `mql5-results.bin` vẫn còn; chạy lại cùng `CheckRun` sẽ trả 5. Mỗi lượt cần `CheckRun` mới.
- Chế độ -1 thêm tối đa `count` dòng log (tối đa 10000).
- Header vẫn dùng hàm thật (mảng, `Print`, `GetLastError` theo chú thích `:91`). Tôi không đọc header
  trong lượt này, nên không biết có trạng thái nào giữ giữa các lần gọi không. Nếu bản ghi k của chế độ
  `OnlyCase=k` khác bản ghi k của chế độ -1, cần xem chỗ đó trước.

## Codex cần kiểm

1. Đặt tệp vào `bot-cua-toi-3/source/MQL5/Scripts/bot-cua-toi-3/`, biên dịch với header hiện hành; mục
   tiêu 0 lỗi, 0 cảnh báo.
2. Chế độ -1 với bộ ca cũ: so từng byte hai tệp đầu ra với lượt trước của Script hiện hành.
3. `OnlyCase=k` với ca chạy được: so bản ghi id k với bản ghi k của lượt đủ; status (0, 1).
4. `OnlyCase=k` với ca lỗi: log có `PREPARATION_CASE:k` rồi lỗi; so loại lỗi với lượt EX5 gốc trên cùng
   dữ liệu; `mql5-results.bin` đúng 16 byte; không có `script-status.bin`.
5. `OnlyCase=-2` và `OnlyCase=count`: trả 12, không có tệp đầu ra.
