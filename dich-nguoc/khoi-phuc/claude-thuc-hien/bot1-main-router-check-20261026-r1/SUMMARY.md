# Tóm tắt: bộ ca và chương trình kiểm điều phối bot1

## Tệp đã viết (trong thư mục này)

- `router_cases.py`: tạo 1536 ca đầu vào và mã hóa `cases.bin`. Không có
  kết quả mong đợi, không dùng số ngẫu nhiên, không ghi tệp.
- `Bot1ManagementRouterCheck.mq5`: script gọi `Bot1RoutePositionManagement`
  với dịch vụ giả. Không gửi lệnh, không gọi manager thật.
- `SUMMARY.md`: tệp này.

## Trạng thái: chưa kiểm

- Chưa biên dịch, chưa chạy, chưa đối chiếu với EX5 gốc. Tôi không chạy
  lệnh, Git hay MT5 và không tạo tác tử.
- Kích thước dưới đây tính theo công thức, chưa đo:
  `cases.bin` = 12 + 1536×88 = 135180 byte;
  `mql5-results.bin` = 12 + 1536×128 = 196620 byte;
  `script-status.bin` = 8 byte.
- Script cần nằm ở `bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/` để hai
  đường include `../../Include/bot-cua-toi-1/...` đúng. `router_cases.py` chỉ
  dùng thư viện chuẩn (Python 3.6 trở lên).
- `Bot1ManagementRouter.mqh` do phiên khác viết. Lúc tôi bắt đầu, thư mục
  `../bot1-main-router-20261026-r1/` chỉ có TASK.md; gần cuối phiên header mới
  xuất hiện ở đó. Tôi chỉ đọc để so giao diện: chữ ký 13 tham số khớp lời gọi
  trong script. Các dịch vụ header gọi (`PositionsTotal`, `PositionGetTicket`,
  `PositionGetInteger`/`PositionGetString` một đối số, `iTime`, `Print` một
  chuỗi, `Bot1ManagePositions`) đều có bản giả cùng dạng. Tôi không đánh giá
  logic header, không sửa header và không chỉnh mock theo header. Header chưa
  có trong `Include/bot-cua-toi-1/`, nên script chỉ biên dịch được sau khi
  Codex ghép.

## Đã đọc

- Hai TASK.md (`bot1-main-router-check-20261026-r1`,
  `bot1-main-router-20261026-r1`).
- `Bot3ManagementBarGateCheck.mq5` và `bar_gate_cases.py`: định dạng tệp và
  cách chặn dịch vụ.
- `Bot1PositionManagement.mqh` và các struct `Bot1VirtualFinishSettings`,
  `Bot1PendingRequestState`, `Bot1TradeSendOptions`, `Bot1VirtualStopState`:
  kiểu dữ liệu.
- `Bot1PositionManagementFlowCheck.mq5` và `manager_flow_cases.py`: cách viết
  dịch vụ giả và hàm băm chuỗi của bot1.
- `Bot3ManagementBarGate.mqh`: chỉ để xem cách include.
- Không đọc EX5, mã máy hay thư mục phân tích.

## Định dạng

- `cases.bin`: đầu tệp `<3i`: magic `0x4d525431`, version 1, count. Mỗi ca
  88 byte `<14i4q` theo thứ tự INTS rồi LONGS của TASK.
- `mql5-results.bin`: đầu tệp có cùng magic, version và count. Mỗi ca
  128 byte `<12i2Q8q`: id, returned, timeframe, counter, mode, index
  (`shared.strategy_index` cuối ca), events, selected, total_calls,
  buy_calls, sell_calls, live_count, last_ticket, ordered_hash, rồi 8 ô bar.
- `script-status.bin`: `<2i` gồm fault và count.
- Thư mục trong Files: `bot1-management-router\<CheckRun>\`.

## Mã trả về và fault

- `OnStart` trả các mã sau và không ghi status: 4 tên lượt sai; 5 đã có
  `mql5-results.bin` hoặc `script-status.bin`; 6 không mở được `cases.bin`;
  7 magic, version, count hoặc kích thước sai; 8 không mở được
  `mql5-results.bin`; 11 không mở được `script-status.bin`.
- `fault` giữ lỗi đầu tiên và được ghi vào status:
  - 9: ca sai id hoặc sai miền (dừng đọc).
  - 10: chưa đọc hết tệp.
  - 20/21/22: iTime sai symbol, sai shift, hoặc bị gọi lần thứ 3.
  - 23: Print sai chuỗi.
  - 30/31/32/33: manager sai symbol, sai deviation, sai levels, hoặc bị gọi
    lặp cùng chiều.
  - 40/41: PositionGetInteger không có vị thế được chọn hợp lệ, hoặc mã khác
    MAGIC/TYPE.
  - 42/43: PositionGetString không có vị thế được chọn hợp lệ, hoặc mã khác
    SYMBOL.

## Chỗ tôi phải chọn cách hiểu: cần Codex xác nhận

1. `shared.strategy_index=(index+1)%8` trong manager giả: tôi hiểu là
   `(shared.strategy_index+1)%8`, tính trên biến toàn cục hiện tại như mẫu
   bot3. Nếu ý là `case.index` thì kết quả bằng giá trị lúc khởi tạo, nên
   phép đổi không có tác dụng.
2. "Danh sách levels đúng": `ArraySize(levels)` bằng 8 và từng ô trùng bit với
   mảng toàn cục cùng chiều (mua 10.0+i, bán 20.0+i).
3. Mã thuộc tính được so bằng hằng `POSITION_MAGIC`, `POSITION_TYPE`,
   `POSITION_SYMBOL`. TASK ghi số 12, 2, 0, nhưng tôi chưa kiểm số thật vì
   chưa biên dịch. Sự kiện ghi giá trị số của mã.
4. Khi chọn vị thế sai hoặc mã thuộc tính sai, PositionGetInteger trả 0 và
   PositionGetString trả chuỗi rỗng; cả hai vẫn ghi đủ một sự kiện.
5. Manager giả không bắt BUY phải chạy trước SELL; nó chỉ chặn gọi quá 1 lần
   mỗi chiều. Thứ tự gọi được ghi trong ordered_hash.
6. Nếu iTime bị gọi lần 3: báo fault 22, vẫn trả `second` và ghi sự kiện.
7. Mã api của sự kiện cũng được kéo dấu qua long. Các mã đều dương nên giá
   trị không đổi.
8. Script chỉ gọi `Bot1RoutePositionManagement`. `Bot1CountManagementPositions`
   chỉ được kiểm gián tiếp qua nhánh xử lý từng lần nhận giá.

## Cấu hình

- Môi trường báo model `claude-opus-5-5`. Ngữ cảnh hệ thống của phiên ghi
  ultracode đang bật và mức suy luận max. Tôi không tự xác minh được cấu hình
  thực tế; Codex cần kiểm bằng nhật ký phiên. Không có công cụ Workflow và TASK
  cấm tạo tác tử, nên tôi làm một mình.

## Việc còn lại (Codex)

- Ghép header và script vào nguồn, rồi biên dịch trên MT5 kiểm thử riêng.
- Tạo `cases.bin` bằng `encode(cases())`, chạy script với một CheckRun mới.
- So `mql5-results.bin` và `script-status.bin` với kết quả của mã gốc chạy
  độc lập.
