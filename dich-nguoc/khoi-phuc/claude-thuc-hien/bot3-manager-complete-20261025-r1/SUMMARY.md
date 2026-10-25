# Bot3PositionManagement – bản đề xuất của Claude

**Trạng thái:** mới viết mã theo `TASK.md`. Chưa biên dịch, chưa chạy, chưa so với
EX5 gốc; không phải EA hoàn chỉnh. Codex kiểm, ghép và chạy.

Chỉ tạo 2 tệp trong thư mục này: `Bot3PositionManagement.mqh` và `SUMMARY.md`.
Không sửa nguồn chính, Git, lệnh hay thư mục của phiên khác.

Cấu hình lượt này: mô hình `claude-opus-5-5`, phiên có bật Ultracode. Mức `max`
không tự kiểm được từ bên trong. Phiên không có công cụ Workflow nên làm một mình,
tự đối chiếu từng tham số với chữ ký helper.

## Nguồn đã đọc (chỉ để đúng chữ ký và kiểu dữ liệu)
- Header nguồn chính `bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/`: ManagementPrelude,
  Anchor, RealTimed, RealDistance, RealTake, RealSlippage, RealHighLow, RealLock, RealCounter,
  RealStore, VirtualStart, Virtual, VirtualTake, VirtualFinishFlow, VirtualFinish; thêm
  PositionClose, PositionModify, VirtualStops, ManagementMessages, struct ở PendingRequest/TradeSend.
- `Scripts/bot-cua-toi-3/Bot3ManagementRealApiCompile.mq5`: chỉ xem cách gọi đã có.
- `Bot3ManagementRealStart.mqh` **chưa có** trong nguồn chính lẫn thư mục đề xuất lúc viết.
  Chữ ký `Bot3StartRealManagement` và `Bot3CloseRealStopHit` lấy từ mô tả giao việc
  `../bot3-real-hit-start-20261025-r1/TASK.md`.
- Không đọc EX5, mã máy hay tài liệu phân tích.

## Giao diện trong tệp
| Phần | Dòng | Ghi chú |
|---|---|---|
| `struct Bot3PositionManagementSettings` | 23–57 | Đúng danh sách mô tả, thêm `double gap`, `double freeze` (54–55) |
| `struct Bot3PositionManagementState` | 61–74 | Đúng danh sách mô tả, thêm `MqlTick tick` (73) |
| `bool Bot3ManageOnePosition(...)` | 78–268 | Hàm nội bộ cho một vị thế: trả `true` khi đã tới đường đóng, `bool &changed` |
| `bool Bot3ManagePositions(...)` | 272–295 | Hàm public, chữ ký đúng mô tả |

## Đối chiếu thứ tự với mô tả
| Mô tả | Dòng | Cách làm |
|---|---|---|
| Vòng ngoài | 277–294 | `PositionsTotal` → `total<1` trả false → chép `eligible` một lần → `do{...}while(index<total)`; đọc lại `PositionsTotal` sau mỗi vị thế; vị thế trả `true` thì `return true` ngay |
| 1 Đọc vị thế | 84–87 | dùng `shared.tick`; false thì về vòng ngoài |
| 2 Mức đầu, nến 0/1/2 | 88–95 | nhóm nến không làm return hay đổi `changed` |
| 3 Anchor và bản sao | 96–105 | `ticket`, `anchor`, `raw_reference`, `passed`, `ticket_number` chép một lần |
| 4 Đóng sớm | 107–119 | `SymbolInfoTick` → `PositionGetDouble(POSITION_VOLUME)` (bỏ kết quả) → `Bot3TryClosePosition(..., shared.last_ticket)` → `true`; không Print |
| 5 Chọn đoạn | 121 | `settings.finish.mode!=2` thì chạy THẬT |
| A | 123–128 | true thì return true |
| B–H mua / bán | 131–172 / 174–214 | B gán thẳng `changed`; C, D true thì return true; E–H không trả giá trị |
| I | 216–224 | so `<` nghiêm ngặt; tính `hit`, gán `current_stop`, rồi mới xét `hit` |
| J | 225–228 | lưu rồi đọc lại `mode`; khác 2 trả false; bằng 2 xuống ẢO, giữ `changed` |
| ẢO 1–6 | 231–267 | 1, 3, 4 true thì return true; 6 trả kết quả của `Bot3FinishVirtualManagement`, không đọc lại mode |

## Điều tự chọn (Codex cần đối chiếu)
1. `index` ở D, F và ẢO 3, 4, 6 được hiểu là `shared.strategy_index`: tham số helper là
   `const uint &strategy_index` (chỉ số `volumes[]`/`levels[]`), mô tả ghi "Index vị thế là
   biến cục bộ khác". Chỉ số vị thế `int index` chỉ dùng cho `Bot3ReadManagementPosition`.
2. Mọi helper nhận `const ulong ticket` đều nhận `(ulong)ticket`, kể cả D–H và ẢO 3, 4 (mô tả
   ghi `ticket`). Helper nhận `long` (RealStart, CloseRealStopHit, VirtualStart, Finish) nhận `ticket`.
3. B–H: xét `buy` một lần rồi chạy khối mua hoặc khối bán, cùng thứ tự B→H, thay vì chọn ở
   từng bước. `buy` là tham số giá trị hằng nên kết quả như nhau.
4. Bước I: gọi `Bot3CloseRealStopHit` rồi `return true`, không dùng giá trị trả về (theo mô tả
   RealStart, hàm đó luôn trả true).
5. Bước 4: `u`, `distance`, `trigger` là hằng cục bộ; `emergency_offset` đọc ngay trong công thức.
6. Nhóm nến chạy bằng vòng `for(group=0;group<3;group++)`.
7. Lần đọc `mode` đầu so thẳng `settings.finish.mode`, không chép ra biến.
8. `gap`, `freeze` đặt ngay trước `finish`; `tick` đặt cuối State; mỗi trường một dòng.
9. Giá trị đầu viết `0.0` thay `0` (cùng giá trị).
10. Include dạng `"Tên.mqh"` cùng thư mục: tệp cần đặt cạnh các header trong
    `Include/bot-cua-toi-3/`, cùng với `Bot3ManagementRealStart.mqh`.
11. Tên hàm nội bộ `Bot3ManageOnePosition`; MQL5 không có hàm tự do kiểu private.

## Chưa làm / cần kiểm
| Việc | Trạng thái |
|---|---|
| Biên dịch | Chưa. Thiếu `Bot3ManagementRealStart.mqh` thì chưa biên dịch được |
| Cảnh báo có thể gặp | bỏ kết quả `SymbolInfoTick`, `PositionGetDouble`, `Bot3CloseRealStopHit`; truyền phần tử `settings.candle_enabled[group]` vào `const uchar &` — cần trình biên dịch xác nhận |
| Giá trị đầu của `shared.tick` | Tệp này không đặt; do bên gọi quyết định |
| Chạy, bộ kiểm | Chưa có |
| So với EX5 gốc | Chưa; cần Codex so thứ tự gọi API/lệnh và kết quả |
