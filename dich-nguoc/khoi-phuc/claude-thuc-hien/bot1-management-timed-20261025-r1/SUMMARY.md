# Bot1ManagementTimed — tóm tắt

## Trạng thái

| Mục | Kết quả |
|---|---|
| Nguồn | Đã viết `Bot1ManagementTimed.mqh` trong thư mục TASK này |
| Biên dịch | **Chưa** biên dịch (lượt này không được chạy lệnh/MT5) |
| So với mã gốc | **Chưa** chạy ca nào; chưa có bằng chứng đạt |
| Phạm vi | Chỉ đoạn dời mức ảo theo thời gian: mua `0x29a67` + `0x29e01..0x29ea9`, bán `0x2d1b6` + `0x2d572..0x2d61a`. Không phải toàn bộ nhánh ảo, hai hàm quản lý hay EA |

Đã đọc AGENTS.md, `tai-lieu-cu/QUY-TRINH.md`, TASK.md,
`virtual-timed-contract.md` (và các hợp đồng cùng thư mục để biết ranh
giới), nguồn hiện có `Bot1ManagementPrelude.mqh`, `Bot1VirtualStops.mqh`,
`Bot1PriceLevels.mqh`, `Bot1ManagementVirtualStartCheck.mq5`. Không đọc
EX5, mã C hay bản chụp; không chạy lệnh/MT5/git; chỉ ghi hai tệp ở đây.

## Hàm và tham số

`void Bot1AdvanceTimedVirtualStop(const bool buy,const string &symbol,
const Bot1TimedVirtualStopParams &params,MqlTick &tick,double &current_level,bool &changed)`

| Tham số | Lấy từ | Ghi chú |
|---|---|---|
| `params.activation` | double `0x624f8` | |
| `params.delay_seconds` | int có dấu 32 bit `0x6745c` | |
| `params.opened` | thời gian mở đã chụp (`position.opened`) | `long` |
| `params.distance` | double `0x62500` | |
| `params.unit` | double `0x66d98` | |
| `params.tp` | chốt lời đã chụp (`position.tp`) | |
| `params.freeze_distance` | double `0x67468` | |
| `tick` | biến giá dùng chung của bước quản lý | biến thật, không bản sao; hàm không ghi |
| `current_level` | mức ảo dùng chung `0x62580` | biến thật, không bản sao |
| `changed` | cờ thay đổi của người gọi | chỉ được bật |

Tên cấu trúc và tên trường là tên phục dựng; hợp đồng không có tên gốc.

## Đối chiếu hợp đồng → mã

| Điểm hợp đồng | Dòng | Cách giữ |
|---|---|---|
| Chỉ chạy khi `0x624f8 > 0`, NaN không thỏa | 21 | `!(0.0<activation)` → thoát trước mọi lời gọi; NaN, ±0, số âm đều thoát |
| Gọi `TimeCurrent()` rồi mới đọc delay | 22–23 | Lời gọi ở câu riêng; delay chỉ đọc ở câu sau |
| Mở rộng int có dấu lên 64 bit, cộng thời gian mở; tiếp tục khi giờ >= tổng | 23 | `params.opened+(long)delay_seconds`; `now<tổng` → thoát |
| Chụp mức và giá (mua Bid, bán Ask) trước `SymbolInfoDouble(SYMBOL_POINT)` | 24–26 | `level`, `quote` gán trước lời gọi |
| Sau lời gọi mới đọc khoảng, đơn vị; tính khoảng×đơn vị | 27 | `offset=distance*unit`; từ đây tới lần ghi không còn lời gọi nào |
| Mua: mức + điểm + khoảng×đơn vị < giá đã chụp | 30 | `(level+point)+offset<quote` |
| Mua: Bid hiện tại < TP − freeze | 31 | Đọc lại `tick.bid` sau lời gọi |
| Mua: bật cờ, ghi Bid − khoảng×đơn vị | 32 | |
| Bán: giá đã chụp < (mức − điểm) − khoảng×đơn vị | 36 | |
| Bán: freeze + TP < Ask hiện tại | 37 | Đọc lại `tick.ask` sau lời gọi |
| Bán: bật cờ, ghi khoảng×đơn vị + Ask | 38 | |
| So có thứ tự, NaN làm sai | 21, 30–31, 36–37 | Chỉ dùng `!(a<b)` → thoát; không đổi sang `>=` |
| Cờ đã bật giữ nguyên | — | Không có `changed=false` |
| Không làm tròn, sửa, đóng, ghi giờ | — | Chỉ gọi `TimeCurrent` và `SymbolInfoDouble` |

Chuỗi lời gọi mong đợi: activation không đạt → 0 lời gọi; chưa đủ giờ →
chỉ `TimeCurrent`; còn lại → `TimeCurrent`, rồi `SymbolInfoDouble(symbol,SYMBOL_POINT)`.

## Khi ghép

1. Chép vào `bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/Bot1ManagementTimed.mqh`.
   Tệp không nạp tệp khác.
2. **Trùng tên**: `Bot1ManagementPrelude.mqh:163-188` đã có
   `Bot1AdvanceTimedVirtualStop` 11 tham số. Đọc tay thấy cùng thứ tự lời
   gọi, phép so và lần ghi; chỉ khác cách truyền tham số (chưa chạy để so).
   Nạp cả hai thì MQL5 có hai bản cùng tên. Cần giữ một bản và sửa lời gọi
   ở `Bot1ManagementVirtualStartCheck.mq5:138`; tôi không sửa vì ngoài thư mục.
3. `params` truyền tham chiếu, trường chỉ được đọc tại đúng điểm hợp đồng.
   Trong MT5, `TimeCurrent`/`SymbolInfoDouble` không đổi biến của EA, nên
   điền `params` ngay trước khi gọi cho cùng kết quả. Bộ kiểm muốn đổi delay,
   khoảng, đơn vị hoặc freeze bên trong hàm giả thì phải đổi chính cấu trúc
   được truyền vào.
4. `tick` và `current_level` phải là biến dùng chung thật (như `VTickData`,
   `VCurrent` trong bộ kiểm hiện có), vì hợp đồng phân biệt giá/mức đã chụp
   với giá hiện tại.

## Giới hạn, chưa có bằng chứng

1. **Đường ra sau đoạn chưa rõ.** Hợp đồng ghi mua kết thúc trước `0x29aab`
   hoặc `0x2a38b`, bán trước `0x2d1fd` hoặc `0x2db0a`, nhưng không nói đường
   nào tới điểm nào. `0x29aab`/`0x2d1fd` là đầu nhánh khoảng cách; đường tới
   `0x2a38b`/`0x2db0a` có thể bỏ qua nhánh khoảng cách và trượt giá. Hàm
   `void` theo TASK không báo đường đã đi, còn gọi lại `TimeCurrent` ở
   người gọi sẽ thêm lời gọi so với gốc. Cần Codex chốt; tôi không tự thêm
   giá trị trả.
2. **Dấu của phép so giờ**: hợp đồng chỉ ghi `>=`. Tôi dùng `long` có dấu
   như `Bot1VirtualStopDelayPassed`. Chỉ khác so không dấu khi giờ hoặc
   tổng âm (delay âm lớn, thời gian mở nhỏ, hoặc tổng tràn 64 bit).
3. Giả định trình biên dịch, chưa kiểm: `(long)TimeCurrent()` giữ 64 bit;
   cộng `long` tràn thì quay vòng; `<` của double là so có thứ tự; không
   gộp nhân-cộng (FMA) hay đổi thứ tự cộng; không đọc sớm trường của tham
   chiếu `const` qua lời gọi ngoài.
4. Phần không thuộc đoạn này, chưa viết: nhánh khoảng cách, ngưỡng phụ, mức
   cao/thấp, khóa lời, bộ đếm, ghi lại bảng, và cách ghép vào hai hàm quản lý.

## Ca nên có khi so (đề xuất, chưa chạy)

- activation: NaN, −0.0, +0.0, số dương nhỏ nhất, +inf, số âm.
- Giờ: đúng bằng tổng; kém 1 giây; delay `INT_MIN`, `INT_MAX`, âm;
  thời gian mở 0; tổng tràn 64 bit.
- Biên dấu `<`: mua `mức+điểm+offset == Bid`, `Bid == TP−freeze`; bán
  `Ask == (mức−điểm)−offset`, `freeze+TP == Ask` → không đổi.
- NaN/±inf ở mức, Bid/Ask, điểm, khoảng, đơn vị, TP, freeze.
- `changed` vào là true mà điều kiện sai → vẫn true.
- Thứ tự đọc: hàm giả đổi mức/Bid/Ask trong `TimeCurrent` (phải thấy) và
  trong `SymbolInfoDouble` (mức/giá đã chụp không thấy, điều kiện 2 và lần
  ghi phải thấy); đổi delay trong `TimeCurrent`, đổi khoảng/đơn vị/freeze
  trong `SymbolInfoDouble` (phải thấy).
- Bộ số mà nhân rồi cộng khác FMA; so bit giá trị ghi.

## Cấu hình lượt

Phiên báo mô hình `claude-opus-5-5`; mức suy nghĩ thực tế không tự kiểm
được từ trong phiên. Phiên báo bật Ultracode nhưng không có công cụ
Workflow, và TASK chỉ cho Read/Grep/Glob/Edit/Write, nên làm trực tiếp.

Codex đã biên dịch thử bản ứng viên trong máy thử riêng:
`b1-management-timed-compile-02`, 0 lỗi/0 cảnh báo. Đây chỉ là kiểm
cú pháp; chưa chạy và chưa so với mã gốc. Biên nhận đã lưu tại
`danh-gia-claude/bot1-management-timed-20261025-r1/compile-receipt.json`.
