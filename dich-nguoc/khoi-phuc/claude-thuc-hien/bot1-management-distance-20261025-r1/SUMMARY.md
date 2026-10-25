# Bot1ManagementDistance — tóm tắt

## Trạng thái

| Mục | Kết quả |
|---|---|
| Nguồn | Đã viết `Bot1ManagementDistance.mqh` trong thư mục TASK này |
| Biên dịch | **Chưa** biên dịch (lượt này không được chạy lệnh/MT5) |
| So với mã gốc | **Chưa** chạy ca nào với tệp này; chưa có bằng chứng đạt |
| Phạm vi | Chỉ đoạn dời mức ảo theo khoảng cách: mua `0x29aab..0x29c64`, bán `0x2d1fd..0x2d3d1`. Không phải toàn bộ nhánh ảo, hàm quản lý hay EA (`whole_bot_complete=false`) |

Đã đọc: AGENTS.md, `tai-lieu-cu/QUY-TRINH.md`, TASK.md,
`virtual-distance-contract.md` và các hợp đồng cùng thư mục (chỉ để biết
ranh giới), các header bot 1 hiện có (`Bot1ManagementPrelude.mqh`,
`Bot1PriceLevels.mqh`, `Bot1PositionClose.mqh`, `Bot1Volume.mqh`), tệp kiểm
`Bot1ManagementVirtualStartCheck.mq5`, `comparison.json`/`mql5-run.json`
của lượt `virtual-start-20261025-r6` và vài dòng của
`check-management-virtual-start.py` (danh sách ca stage 2, điểm dừng khi
gọi đóng). Không đọc EX5, mã C hay bản chụp; không ghi ngoài thư mục này.

## Khi ghép

1. Chép vào `bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/Bot1ManagementDistance.mqh`.
2. Tệp nạp `Bot1ManagementPrelude.mqh` để lấy `Bot1ManagedPosition`.
   Prelude hiện còn bản nháp cùng tên, cùng chữ ký (dòng 190–230).
   **Phải bỏ bản nháp đó khi ghép**, nếu không biên dịch sẽ báo trùng hàm.
   Chữ ký giữ y hệt (kể cả `MqlTick &tick`, hàm không ghi vào `tick`) để
   lỗi trùng hiện rõ, không thành hàm nạp chồng chạy nhầm bản nháp.
3. Thứ tự tham số khớp lời gọi stage 2 ở
   `Bot1ManagementVirtualStartCheck.mq5:139`. Khi kiểm, nạp tệp này sau các
   `#define` giả lập (như dòng 84) để `SymbolInfoDouble` và
   `Bot1ClosePosition` đi vào hàm giả.
4. Khác bản nháp: phần lượng/đóng viết bằng `return` sớm; thứ tự lời gọi,
   phép so và lần đọc giữ nguyên. Bản nháp đã khớp r6 924/924 ca (có ca
   stage 2; hàm này trong `tested-sources` của r6 giống chữ với nguồn hiện
   tại). Đó là bằng chứng của bản nháp, không phải của tệp này.

## Đối chiếu hợp đồng → mã

| Hợp đồng | Dòng | Cách giữ |
|---|---|---|
| Chỉ chạy khi `0x624a8 > 0`; NaN không chạy | 21 | `!(0.0<trail_distance)` → trả `false`, không đổi gì |
| Chụp mức `0x62580` và giá (mua Bid, bán Ask), rồi mới hỏi điểm | 22–24 | `level`, `quote` đọc trước `SymbolInfoDouble(symbol,SYMBOL_POINT)` |
| Tham số phía sau đọc sau lời gọi; khoảng = (`0x624c0`+`0x624a8`)×đơn vị | 25 | `(trail_step+trail_distance)*unit` |
| Mua: mức chụp + điểm + khoảng < giá chụp | 28 | `level+point+distance<quote`, cộng từ trái |
| Mua: `0x624b0`×đơn vị + mốc < Bid hiện tại | 29 | đọc lại `tick.bid` |
| Mua: mức hiện tại < `0x624b8`×đơn vị + giá mở | 30 | đọc lại `current_level` |
| Mua: ghi Bid hiện tại − `0x624a8`×đơn vị | 31 | |
| Bán: giá chụp < (mức chụp − điểm) − khoảng | 35 | |
| Bán: Ask hiện tại < mốc − `0x624b0`×đơn vị | 36 | đọc lại `tick.ask` |
| Bán: giá mở − `0x624b8`×đơn vị < mức hiện tại | 37 | đọc lại `current_level` |
| Bán: ghi `0x624a8`×đơn vị + Ask hiện tại | 38 | |
| Sau ghi: đọc `0x66a80 + uint(0x678f4)*8`, nhân +0, làm tròn 2 chữ số theo công thức gốc | 41 | `Bot1RoundPrice(volumes[strategy_index]*0.0,2)` (hằng ±0.5000001); không thay bằng 0 vì NaN/vô hạn phải ra NaN |
| Bật cờ thay đổi | 42 | chỉ bật, không tắt |
| Lượng < khối lượng vị thế đã chụp mới hỏi `SYMBOL_VOLUME_MIN` | 43–44 | NaN thì không hỏi |
| Đóng khi lượng >= nhỏ nhất, kể cả bằng; NaN không đóng | 45 | `minimum<=volume` |
| Đóng bằng vé địa phương, không lấy giá lại | 46 | `(ulong)(long)position.ticket_number`; không gọi `SymbolInfoTick` |
| Không hỏi số chữ số, không sửa dừng, không ghi giờ, không điều kiện chốt lời | — | không có các lời gọi/phép so này |
| Phép so có thứ tự, NaN làm sai | 21–45 | mọi điều kiện viết dạng `!(a<b)` / `!(a<=b)` |

## Dò tay ca mặc định (không phải phép chạy)

Lấy giá trị `base()` của bộ ca r6: unit 0.1, điểm 0.01, trail 3, step 0.1,
start −2, limit 0, mốc 100, giá mở 100, Bid=Ask=100, khối lượng 1, bảng
lượng 1, nhỏ nhất 0.01.

| Ca | Dò theo nguồn mới |
|---|---|
| Mua, mức 95 | 95.32<100, 99.8<100, 95<100 → ghi ≈99.7, changed; lượng 0<1 → hỏi nhỏ nhất; 0.01<=0 sai → trả false |
| Bán, mức 105 | 100<104.68, 100<100.2, 100<105 → ghi ≈100.3; tương tự không đóng |
| Nhỏ nhất 0 hoặc −0.01 | 0<=0 hoặc −0.01<=0 → gọi đóng, trả true |
| Bảng lượng NaN/±vô hạn | nhân +0 ra NaN; `Bot1RoundPrice` trả lại NaN nếu `(long)NaN` là `LONG_MIN` như hàm này giả định → không hỏi nhỏ nhất, không đóng |

Chưa so với kết quả gốc; chỉ để soát nhanh.

## Giới hạn và phần còn thiếu

1. **Chỉ số chiến lược**: phép so chỉ kiểm chỉ số 0..7 (bảng 8 ô
   `0x66a80`). Ngoài vùng, MQL5 sẽ báo lỗi mảng và dừng chương trình, còn
   mã gốc đọc tiếp bộ nhớ sau bảng. Chưa có bằng chứng nên không thêm kiểm
   biên (sẽ là luật tự thêm). Nơi gọi phải truyền bảng 8 ô dùng chung và
   chỉ số đã chụp.
2. **Giá trị trả**: `true` chỉ nghĩa là đã gọi đóng. Hợp đồng chưa nói sau
   khi đóng thì thoát khỏi vị thế hay chạy tiếp; bộ ca gốc r6 dừng ngay
   tại lời gọi đóng. Nơi gọi chưa được tự suy luồng sau đó.
3. **Nhánh chưa viết**: ngưỡng phụ, mức cao/thấp, khóa lời, bộ đếm và ghi
   bảng sau đoạn này; vòng quét ngoài và phần ghép hai hàm quản lý.
4. **Đọc lại tham số**: nguồn tính khoảng sau lời gọi điểm, nhưng tệp kiểm
   hiện tại chỉ đổi được `current_level` và `tick` trong hàm giả, không đổi
   được trail_*/unit; thứ tự này chưa đo trực tiếp được. Trong MT5 thật,
   `SymbolInfoDouble` không đổi các biến này.
5. **Cần kiểm khi biên dịch**: `SYMBOL_VOLUME_MIN` phải bằng 34 như hợp
   đồng; phép `*0.0` không được bị rút gọn thành 0 (ca bảng lượng
   NaN/vô hạn sẽ lộ); 0 lỗi, 0 cảnh báo.
6. Tên `trail_distance/step/start/limit`, `anchor`, `volumes`,
   `strategy_index` là tên phục dựng theo TASK, chưa phải tên cài đặt gốc.

## Ca nên thêm (đề xuất, Codex quyết)

Stage 2 của r6 có: numeric từng trường, đóng khi lượng 0 (nhỏ nhất
−0.01/0/0.01, chỉ số 0/1/7) và đọc lại kịch bản 0/5. Ở kịch bản 5, mức và
giá cùng tăng 1.25 nên phép so đầu không tách được mức chụp với mức đọc
lại. Kết quả dưới đây là **theo hợp đồng**, cần chạy gốc để chốt:

| Ca (giá trị khác `base()`) | Theo hợp đồng | Tách được |
|---|---|---|
| Mua, kịch bản 2, mức 99.6, limit 20 | 99.92<100 → ghi | phép so đầu dùng mức chụp |
| Mua, kịch bản 2, limit −45 | 96.25<95.5 sai → không ghi | phép so 3 dùng mức đọc lại |
| Bán, kịch bản 2, limit −55 | 105.5<106.25 → ghi | phép so 3 dùng mức đọc lại |
| Mua, kịch bản 5, start 10 | 101<101.25 → ghi | phép so 2 dùng Bid đọc lại |

## Câu hỏi về hợp đồng

Không thấy mâu thuẫn giữa hợp đồng và TASK. Điểm chưa rõ duy nhất là luồng
sau khi đóng (mục 2 phần giới hạn); không tự điền.

## Cấu hình lượt

Phiên báo mô hình `claude-opus-5-5`; mức suy nghĩ thực tế không tự kiểm
được từ trong phiên. Phiên báo bật Ultracode nhưng không có công cụ
Workflow, và TASK chỉ cho Read/Grep/Glob/Edit/Write, nên làm trực tiếp,
không chia phiên con.
