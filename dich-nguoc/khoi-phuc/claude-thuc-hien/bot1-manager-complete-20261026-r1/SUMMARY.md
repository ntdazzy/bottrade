# Bot1PositionManagement — bản đề xuất

## Kết quả

- Đã viết `Bot1PositionManagement.mqh` (279 dòng) và `SUMMARY.md` trong
  `dich-nguoc/khoi-phuc/claude-thuc-hien/bot1-manager-complete-20261026-r1/`.
- **Chưa biên dịch, chưa chạy, chưa so với EX5 gốc.** Phiên này không chạy lệnh nào.
- Hiện chưa thể biên dịch vì `Bot1ManagementRealStart.mqh` (phiên khác) chưa có
  trong nguồn. `Bot1StartRealManagement` và `Bot1CloseRealStopHit` được gọi đúng tên và
  thứ tự đối số trong đặc tả. Tôi không tạo hàm giả để thay hai hàm này.
- Không viết lại thân helper nào. Không thêm bảng take, `current_take`, TP trailing hoặc
  trường `mode` ngoài `finish.mode`.

## Nguồn đã đọc

- Đặc tả: `TASK.md` trong thư mục này.
- Header Bot1 hiện hành, chỉ để lấy giao diện, trong
  `bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/`: `Bot1ManagementPrelude.mqh`,
  `Bot1ManagementVirtualFinish.mqh`, `Bot1ManagementRealTimed.mqh`,
  `Bot1ManagementRealDistance.mqh`, `Bot1ManagementRealSlippage.mqh`,
  `Bot1ManagementRealHighLow.mqh`, `Bot1ManagementRealLock.mqh`,
  `Bot1ManagementRealCounter.mqh`, `Bot1ManagementRealStore.mqh`,
  `Bot1ManagementMessages.mqh`, `Bot1VirtualStops.mqh`, `Bot1PositionClose.mqh`. Tìm thêm
  định nghĩa `Bot1PendingRequestState` (`Bot1PendingRequest.mqh`) và
  `Bot1TradeSendOptions` (`Bot1TradeSend.mqh`).
- `Bot3PositionManagement.mqh` chỉ dùng để tham khảo cách chia hàm. Logic Bot1 lấy từ đặc
  tả; các chỗ Bot1 khác Bot3 (bước 5, bước B, bước H) viết theo đặc tả Bot1.
- Không đọc EX5, mã máy hay thư mục phân tích. Tìm tên `Bot1CloseRealStopHit` /
  `Bot1StartRealManagement` trong `dich-nguoc/khoi-phuc` (chỉ lấy tên tệp): chỉ có trong
  `TASK.md` của thư mục này và của `bot1-real-start-20261026-r1`. Tôi không mở `TASK.md`
  của phiên RealStart.
- Đã kiểm `Bot1ManagePositions`, `Bot1ManageOnePosition`, hai tên struct và
  `BOT1_POSITION_MANAGEMENT_MQH` chưa có trong nguồn Bot1 (không trùng tên).

## Đặc tả → mã (số dòng trong `Bot1PositionManagement.mqh`)

| Phần đặc tả | Dòng | Ghi chú |
|---|---|---|
| Header guard, 10 include | 3–14 | RealStart là `Bot1ManagementRealStart.mqh`, theo cách đặt tên các header còn lại |
| `Bot1PositionManagementSettings` | 16–48 | Đúng thứ tự trường; `mode` chỉ ở `finish` |
| `Bot1PositionManagementState` | 50–66 | Đúng thứ tự trường; không có trường take |
| `Bot1ManagePositions` | 254–278 | `PositionsTotal`, `<1`→false, chụp `eligible` một lần, `do/while` tiến, đọc lại tổng sau mỗi vị thế |
| `Bot1ManageOnePosition` | 68–250 | true chỉ ở đường đóng |
| 1. Đọc/lọc vị thế | 76–79 | false → bỏ qua, không đổi `changed` |
| 2. SL/TP ban đầu | 80–82 | Không đặt `changed` |
| 3. Hai nhóm nến | 83–90 | group 0 `alternate=false`, group 1 `true`; không thoát, không đặt `changed` |
| 4. Tham chiếu cache, `ticket`, `ticket_number` | 91–102 | Chụp `ticket` sau helper |
| 5. Đóng sớm | 104–117 | Không in; `SymbolInfoTick`, `SymbolInfoDouble` bỏ kết quả; dùng `shared.last_ticket`; luôn trả true |
| 6. `finish.mode!=2` | 119 | |
| Thật A | 121–126 | |
| Thật B–G, mua | 130–166 | |
| Thật B–G, bán | 167–203 | |
| Thật H | 204–211 | Ghi `current_stop` trước, kiểm chạm `<` chặt |
| Thật I, đọc lại mode | 212–216 | Luôn ghi bảng; `!=2` → xong vị thế; `==2` → sang chuỗi ảo, giữ `changed` |
| Ảo A–D | 219–242 | |
| Ảo E | 243–249 | Trả thẳng kết quả helper; không đọc lại mode |

## Chỗ Codex cần kiểm hoặc quyết

1. **`SymbolInfoDouble(settings.symbol,SYMBOL_VOLUME)` (dòng 113)** viết đúng đặc tả. Theo
   tài liệu MQL5, `SYMBOL_VOLUME` thuộc `ENUM_SYMBOL_INFO_INTEGER`, không thuộc
   `ENUM_SYMBOL_INFO_DOUBLE`. Trình biên dịch có thể báo lỗi hoặc cảnh báo kiểu enum. Tôi
   không tự ép kiểu, cũng không đổi sang `SYMBOL_VOLUME_REAL`, vì làm vậy là đoán mã thuộc
   tính. Cần đối chiếu với bằng chứng gốc.
2. **Giao diện RealStart chưa kiểm được.** `ticket` là `const long`. Nếu RealStart nhận
   `long &` không const thì lời gọi ở dòng 122 và 208 sẽ lỗi biên dịch. Tôi coi
   `Bot1CloseRealStopHit` nằm trong `Bot1ManagementRealStart.mqh`, vì không header hiện hành
   nào có hàm này. Nếu hàm có giá trị trả về thì giá trị đó bị bỏ qua; sau lời gọi, manager
   luôn trả true.
3. **Biến không khởi tạo, theo đặc tả:** `passed`, `anchor` (91–92), `initial_stop` (121),
   `initial_level` (219). Helper hiện hành luôn ghi `passed`/`anchor` trước khi trả
   (`Bot1ManagementPrelude.mqh:125-127`) và luôn ghi `initial_level`
   (`Bot1ManagementPrelude.mqh:141-142`). Việc ghi `initial_stop` phụ thuộc RealStart.
   Trình biên dịch có thể cảnh báo.
4. **Cách viết khác đặc tả nhưng giữ nguyên logic:** chuỗi thật chia thành hai khối
   `if(buy)`/`else`, cùng thứ tự B→G. Bước B viết `if(Bot1AdvanceTimed...(...)) changed=true;`,
   tương đương `bool timed=...; if(timed) changed=true;` và chỉ gọi một lần.
   `raw_reference`, `anchor`, `passed`, `ticket`, `ticket_number` không bị gán lại. Mọi
   helper nhận các giá trị này theo giá trị, không theo tham chiếu ghi được.
5. Hai lời gọi `Bot1CloseManagementCandle` truyền phần tử mảng `settings.candle_enabled[i]`
   và `settings.candle_timeframe[i]` vào tham số `const uchar &`. Vì chưa biên dịch, chưa
   xác nhận được mọi lời gọi tham chiếu đều hợp lệ.

## Giới hạn

- Chưa biên dịch, chưa chạy ca kiểm, chưa so hai bot. Codex kiểm ghép, biên dịch và so độc lập.
- Không sửa nguồn chính, Git hay MT5; không chạy lệnh; không tạo tác tử.
- Cấu hình phiên: hệ thống ghi mô hình `claude-opus-5-5` và Ultracode đang bật. Từ trong phiên
  không kiểm được mức `max`. Phiên không có công cụ Workflow, và đặc tả cấm tạo tác tử, nên
  tôi làm một mình. Chưa có bên nào đánh giá độc lập.
