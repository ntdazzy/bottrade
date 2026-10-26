# SUMMARY: bên gọi và bộ kiểm cho cờ vé 0 đầu (bot1)

Thư mục: `dich-nguoc/khoi-phuc/claude-thuc-hien/bot1-zero-ticket-check-20261026-r1/`
Trạng thái: bản đề xuất theo `TASK.md`. **Chưa ghép, chưa biên dịch, chưa chạy, chưa so với EX5 gốc.**

## Nguồn đã đọc

- `TASK.md` của thư mục này; `AGENTS.md` (có sẵn trong ngữ cảnh phiên); `dich-nguoc/khoi-phuc/tai-lieu-cu/QUY-TRINH.md`.
- 3 tệp hiện hành trong `dich-nguoc/khoi-phuc/bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/`:
  `Bot1PositionManagementFlowCheck.mq5` (479 dòng), `Bot1ManagementRouterCheck.mq5` (285),
  `Bot1PositionManagementApiCompile.mq5` (15). Tệp thứ tư `Bot1ManagementRouterApiCompile.mq5`
  chưa có trong nguồn nên viết mới theo mẫu ApiCompile.
- Ở `../bot1-first-zero-ticket-20261026-r1/`: hai header đề xuất `Bot1PositionManagement.mqh`
  (287 dòng), `Bot1ManagementRouter.mqh` (109 dòng); thêm `TASK.md`, `SUMMARY.md` của thư mục đó
  để biết chữ ký mới.
- Grep chỉ đọc trong `bot-cua-toi-1/source/`:
  - Lời gọi `Bot1ManagePositions(` / `Bot1RoutePositionManagement(`: chỉ có router header và 3 script
    trên. Chưa có EA nào trong `Experts` gọi hai hàm này.
  - Include hai header này: chỉ 3 script trên và router header.
  - Ký tự `\r` và ký tự ngoài ASCII: không có trong 3 script nguồn lẫn 4 tệp mới (LF, ASCII).
- Không đọc EX5, mã máy, tài liệu phân tích. Không chạy lệnh, không sửa nguồn chính/Git/MT5,
  không tạo tác tử.

## Tệp đã ghi

| Tệp | Số dòng | Ghi chú |
|---|---|---|
| `Bot1PositionManagementFlowCheck.mq5` | 495 | sửa từ bản 479 dòng |
| `Bot1ManagementRouterCheck.mq5` | 293 | sửa từ bản 285 dòng |
| `Bot1PositionManagementApiCompile.mq5` | 15 | sửa 2 dòng |
| `Bot1ManagementRouterApiCompile.mq5` | 17 | tệp mới |
| `SUMMARY.md` | | tệp này |

Số dòng và vị trí trong các bảng dưới đã kiểm bằng Grep trên tệp mới. Phần giữ nguyên chữ đã được
đọc lại và so từng đoạn với bản nguồn bằng mắt, chưa dùng công cụ diff.

## 1. `Bot1PositionManagementFlowCheck.mq5`

| Cũ | Mới | Thay đổi |
|---|---|---|
| — | 7–8 | `input bool FirstZeroTicketChanged=false;`, `input bool ExecuteManagementRouter=false;` |
| — | 293 | Chú thích: router header include manager, nên các macro tác động cả hai. |
| 291 | 294 | include `Bot1PositionManagement.mqh` → `Bot1ManagementRouter.mqh` |
| — | 451–462 | Chú thích và hàm `FRouteManagement()` gọi router thật. |
| 471 | 486–487 | Router bật thì gọi `FRouteManagement()`, tắt thì gọi manager như cũ, chỉ thêm tham số cuối `FirstZeroTicketChanged`. Toán tử `?:` chỉ chạy một bên. |

Giữ nguyên chữ: cũ 1–6 = mới 1–6; 7–290 = 9–292; 292–447 = 295–450; 448–470 = 463–485;
472–479 = 488–495. Vì vậy giữ nguyên: dữ liệu và mã ca, mọi mock SDK và hàm con, công thức hash,
toàn bộ macro và 23 dòng `#undef`, `FWriteResult` (112/140/176 byte), phiên bản 1/2/3, các mã
lỗi, dòng chú thích đầu tệp. Mảng `times` không được ghi ra, theo TASK.

`FRouteManagement()` tạo biến mới ở mỗi ca:

- `uchar license_valid=1,tick_management=1,bar_override=0`; `int timeframe=15`; `long times[8]` khởi 0.
- `strategy_index=(uint)FCase[14]`. TASK ghi `FCase[15]` nếu trường chỉ số là 15. Trong script này
  `FCase[15]` là `FCfg.enabled` (dòng mới 353); chỉ số chiến lược là `FCase[14]`:
  `FShared.strategy_index=(uint)FCase[14]` (dòng mới 358), `FReadCase` kiểm 0..7 (dòng mới 397).
  Giữa `FInitialize` và lời gọi không có dịch vụ nào chạy, nên giá trị này bằng
  `FShared.strategy_index` lúc gọi.
- `buy_levels[8]` = 95., `sell_levels[8]` = 105. (hai mảng riêng); dùng FCfg/FShared/FRequests/
  FOptions/FDeviation thật; tham số cuối là `FirstZeroTicketChanged`.
- Không thêm mock thay manager, không tính kết quả mong đợi.

## 2. `Bot1ManagementRouterCheck.mq5`

| Cũ | Mới | Thay đổi |
|---|---|---|
| — | 9 | `input bool FirstZeroTicketChanged=false;` |
| — | 136–138 | Chú thích: cờ chỉ được kiểm, không vào hash hay giá trị trả. |
| 138 | 142 | Fake manager thêm tham số cuối `const bool first_zero_ticket_changed`, giống header. |
| — | 149–152 | `per_tick = tick_management!=0 && bar_override==0 && profile!=0` (lấy từ ca); cờ mong đợi là `true` khi `per_tick`, ngược lại là `FirstZeroTicketChanged`; lệch thì `RouterFail(34)`. |
| 277 | 285 | Lời gọi `Bot1RoutePositionManagement` thêm tham số cuối `FirstZeroTicketChanged`. |

Giữ nguyên chữ: cũ 1–8 = mới 1–8; 9–134 = 10–135; 135–137 = 139–141; 139–144 = 143–148;
145–276 = 153–284; 278–285 = 286–293.

Cờ không vào event/hash, không đổi reply, không đổi 128 byte ghi ra, không thêm truy vấn SDK.
Mã lỗi 34 là mã mới (mã cũ: 9, 10, 20–23, 30–33, 40–43). Profile 7 (PositionsTotal lần 2 trả 0)
vẫn là nhánh từng lần nhận giá vì lần gọi đầu thấy 2 vị thế.

## 3. Hai tệp biên dịch API

- `Bot1PositionManagementApiCompile.mq5`: chỉ dòng 13–14 thêm `,false`. Giữ guard
  `InvokeFunctions=false` và chú thích không chạy.
- `Bot1ManagementRouterApiCompile.mq5` (mới, cùng kiểu mẫu): include router;
  `input bool InvokeFunctions=false`; khi tắt thì in "compile only" và return như mẫu. Khi bật:
  các struct `ZeroMemory`, `buy_levels`/`sell_levels`/`last_times` 8 ô khởi 0,
  `uchar license_valid=0,tick_management=0,bar_override=0`, `int timeframe=0`, `ulong deviation=1`,
  gọi router một lần với index `0` và cờ bar `false` tường minh.
  TASK không nêu giá trị các cờ; tôi chọn 0 theo kiểu khởi 0 của mẫu. Nếu lỡ chạy với
  `InvokeFunctions=true`, router chỉ in "Licence not valid!" rồi trả về; script không gọi lệnh
  giao dịch nào.

## Hành vi suy từ mã (chưa chạy)

- FlowCheck, router bật: hai cờ cố định nên router chỉ vào nhánh nến mới khi `FCase[3]==0`; khi đó
  cả hai manager gặp `PositionsTotal()==0` và trả `false`. Vì vậy `FirstZeroTicketChanged` không
  đổi kết quả khi router bật; ca có vị thế luôn đi nhánh từng lần nhận giá, router truyền `true`.
- FlowCheck, router bật so với gọi manager trực tiếp: `FCalls`/`FHash` có thêm lời gọi của router
  và hàm đếm; `FAfterFirstTotal` chạy ở lần `PositionsTotal` đầu của router; `FShared.last_ticket`
  còn bị hàm đếm ghi (kể cả hàm đếm SELL chạy sau manager BUY); manager hướng ngược có thể chạy
  (profile 2) với bảng mức riêng của hướng đó.
- FlowCheck, router tắt: theo header đề xuất, cờ `false` giữ hành vi hiện hành nên kết quả cần
  trùng bản cũ. Cờ `true` chỉ tác động khi vé ở index 0 bằng 0; trong `FInitialize` đó là
  profile 1 với `FCase[3]>=1`, và chỉ trường `returned` có thể đổi.
- Profile 1, router bật: `FCase[3]==1` thì hàm đếm ra 0, manager không được gọi; `FCase[3]>=2` thì
  manager nhận `true`.
- RouterCheck: `mql5-results.bin` cần giống nhau giữa cờ `false` và `true`, status 0 ở cả hai;
  lỗi 34 nghĩa là router truyền sai cờ.

## Việc Codex cần kiểm và so

1. Ghép hai header đề xuất và 4 script cùng lượt. Script dùng đường dẫn `../../Include/bot-cua-toi-1/`,
   nên chỉ biên dịch được khi nằm trong `source/MQL5/Scripts/bot-cua-toi-1/` cùng header mới;
   với header hiện hành sẽ lỗi chữ ký.
2. Biên dịch cả 4 script, mục tiêu 0 lỗi, 0 cảnh báo.
3. FlowCheck theo các ngữ cảnh:

| `ExecuteManagementRouter` | `FirstZeroTicketChanged` | Cần so |
|---|---|---|
| false | false | Trùng byte với kết quả cũ (hồi quy) và với EX5 gốc |
| false | true | Với EX5 gốc ở ngữ cảnh cờ `true`; khác biệt dự kiến chỉ ở ca vé 0 đầu |
| true | false | Với EX5 gốc khi đi qua router |
| true | true | Như dòng trên (suy từ mã) |

4. RouterCheck 1.536 ca với cờ `false` và `true`: hash và kết quả như bản cũ, status 0.
5. Chuỗi router → thân manager → hàm con sửa/đóng/bảng: FlowCheck với
   `ExecuteManagementRouter=true`, `ExecuteTableChildren=true`, `ExecuteTradeChildren=true`
   (bản ghi 176 byte, phiên bản 3), so với gốc.

## Chưa kiểm

- Chưa biên dịch bằng MetaEditor, chưa chạy MT5, chưa so với EX5.
- Chưa diff bằng công cụ; phần giữ nguyên được kiểm bằng đếm dòng, Grep vị trí và đọc lại.
- Nội dung 4 tệp `.mq5` chỉ có ASCII; chưa kiểm BOM của bản nguồn ở mức byte.
- Cấu hình phiên: mô hình `claude-opus-5-5` theo thông tin môi trường; ultracode bật theo thông
  báo hệ thống; mức `max` không tự kiểm được. Không dùng tác tử con hay Workflow, theo yêu cầu
  không tạo tác tử; công cụ Workflow cũng không có trong phiên này.
