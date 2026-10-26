# Bot1PositionManagementFlowCheck: mở cờ chạy thân thật hàm con

**Trạng thái: chưa biên dịch, chưa chạy.** Đề bài không cho Claude chạy lệnh hay MT5. Đây là bản
đề xuất. Codex rà, đặt tệp vào `bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/` (đường include
tương đối tính từ thư mục đó), biên dịch, chạy cả 3 chế độ rồi so độc lập. Claude không tính đáp án.

## Đã đọc (chỉ đọc)

- Bản Bot1 hiện hành `Scripts/bot-cua-toi-1/Bot1PositionManagementFlowCheck.mq5`: dùng làm gốc,
  phần nào không bắt buộc đổi thì giữ nguyên.
- Mẫu `Scripts/bot-cua-toi-3/Bot3PositionManagementFlowCheck.mq5`: cờ, dịch vụ gửi giả, hash 35
  trường, metadata.
- Header Bot1: PositionModify, PositionClose, VirtualStops, TradeSend, PendingRequest, Filling,
  TradeMessages, PriceLevels, PositionManagement, ManagementPrelude, ManagementRealStart. Có tìm
  chuỗi trong các `Bot1Management*.mqh` và `Bot1TradeErrors.mqh`.
- Không đọc EX5, mã máy hay tài liệu phân tích. Không sửa header, nguồn chính, Git hay MT5.

## Thay đổi so với bản hiện hành

| Phần | Dòng | Nội dung |
|---|---|---|
| Đầu vào | 4–6, 450, 465 | Thêm `ExecuteTableChildren`, `ExecuteTradeChildren` (mặc định false). Bật Trade mà tắt Table thì `return 12` ngay đầu `OnStart`. Header tệp kết quả ghi version 1/2/3; header tệp cast luôn ghi 1. Định dạng ca 84 byte và magic `0x4d504d31` giữ nguyên. |
| Thứ tự nạp | 226–314 | 17 macro SDK → Modify, Close → `#define Print FPrint` → VirtualStops → 5 wrapper → 5 macro helper → PositionManagement → undef đủ 23 macro. Wrapper được viết trước macro helper nên gọi đúng hàm thật, không thành đệ quy. |
| Bảng (Table=true) | 249–267 | FStopLevel trace 20 như cũ rồi trả `Bot1VirtualStopLevel`. FDelay trace (26, ticket, seconds, 0, 0) rồi trả `Bot1VirtualStopDelayPassed`. FStamp trace 23 rồi gọi `Bot1VirtualStopStamp`. Khi Table=false: vẫn trả FStopReply, trace 22 kèm `FCase[12]`, trace 23 như cũ. Không có FTakeLevel. |
| Sửa/đóng (Trade=true) | 268–284 | FModify trace (30, ticket, bits sl, bits tp, 0) rồi trả `Bot1ModifyPosition`. FTryClose kiểm tham chiếu (sai thì lỗi 29), trace (31, ticket), gọi `Bot1TryClosePosition` (hàm void) rồi trả true. Khi Trade=false: trace 8/9, xóa vị thế khi được chấp nhận và profile≠7. Phần xóa gom vào `FRemovePosition`, logic giống vòng lặp cũ. |
| Dịch vụ giả thêm | 98–104, 138–162, 187–224 | SelectByTicket: trace 27; vé không khớp thì giữ vị thế đang chọn. SymbolInteger: EXEMODE→2, FILLING→1 (trace mã thuộc tính); DIGITS như cũ (trace 17, đổi mode ở lần gọi thứ n). Dạng 3 đối số ghi lỗi 23 và trả false. SymbolDouble thêm BID/ASK. IsStopped=false. OrderSend/Async đi vào FTradeService: event 28/29; SLTP theo `FCase[10]`, DEAL theo `FCase[11]`, hành động khác ghi lỗi 32. |
| Hash | 39–77, 408–415 | Request 17 + result 10 + check 8 = 35 trường. Chuỗi băm theo UTF-16 kèm cờ NULL; không băm thẳng vùng nhớ. Metadata gồm 6 từ: magic, preferred, deviation, async_mode, log_level, margin_mode (tên trường đúng header Bot1). |
| Khởi tạo | 347–348 | Sau ZeroMemory: thêm `FTradeSends=0`, `magic=0`, `preferred=ORDER_FILLING_FOK` (0), async/log/margin=0. |
| Đầu ra | 416–447 | Phần gốc 112 byte, 19 trường, giữ nguyên. Table thêm 28 byte `<qiiQi`: reported_ticket, cỡ open_tickets, series, hash mảng vật lý, FSelected. Hash mảng đọc `[series?size-1-i:i]`, chỉ trong ArraySize. Tổng 140 byte. Trade thêm 36 byte `<4Qi`, tổng 176 byte. |

## Giữ nguyên

- Dữ liệu ca và `FReadCase` (từ chối profile 16, strategy 0..7).
- `FSetProfile`; profile 13 chạy như profile 0.
- `FLevels[8]`; bảng chỉ gieo hàng dừng; nhóm nến.
- Cache 100×2 (200 ô), bảng 500×3 (1500 ô).
- `FWriteCasts` 32 giá trị và các dịch vụ cũ.
- Không có take/current_take/take_rows/reported_take_ticket/candle_shift/take_trail. Chữ "take"
  còn lại chỉ là trường `take_distance` và 2 chú thích có sẵn trong bản hiện hành.

## Codex cần kiểm

1. Biên dịch. Mong 0 lỗi/0 cảnh báo, nhưng chưa kiểm. Điểm dễ vướng: FDelay truyền tham số
   `seconds` (truyền theo trị) vào `const int &delay_seconds` của hàm thật.
2. Khi cả hai cờ false: hai tệp kết quả phải trùng từng byte với bản hiện hành trên bộ 352 ca. Lý do
   mong trùng: tìm chuỗi cho thấy các header quản lý không gọi trực tiếp `PositionSelectByTicket`,
   `IsStopped`, `OrderSend*`, BID/ASK hay EXEMODE/FILLING. Vì vậy các dịch vụ mới chỉ được gọi qua
   hàm con.
3. `open_tickets` chỉ được đặt lại bằng `ZeroMemory(FShared)`, giống bản hiện hành và mẫu Bot3.
   Cần xác nhận ZeroMemory đưa mảng động về cỡ 0. Nếu không, sau khi
   `Bot1DropClosedVirtualStops` đã chạy một lần, cỡ mảng có thể bị mang sang ca sau.
4. `Print`/`PrintFormat` trong 2 header trade gọi hàm thật nên không vào trace. Theo mã, ma trận
   này không đi tới các lệnh in đó, vì: IsStopped=false, log_level=0, EXEMODE=2 kèm FILLING=1 trả
   true trước nhánh in, và không có lệnh chờ. Nếu thực tế vẫn đi tới thì cần báo lại.
5. Chạy 3 chế độ: false/false, chỉ Table, Table+Trade. Riêng chế độ chỉ bật Trade phải trả 12.

## Cấu hình lượt

- Mô hình: claude-opus-5-5 (theo thông tin phiên). Phiên báo Ultracode đang bật.
- Không có công cụ Workflow, và đề bài cấm tạo tác tử, nên làm trong một phiên và tự rà lại.
- Mức "max" không tự kiểm được từ bên trong phiên. Codex cần đối chiếu với cấu hình thực tế.
