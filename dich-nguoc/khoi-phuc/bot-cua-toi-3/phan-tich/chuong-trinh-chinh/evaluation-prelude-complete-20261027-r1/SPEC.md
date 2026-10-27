# Bot 3 — đầu đánh giá, thông báo giờ giao dịch và cập nhật giá

Đặc tả được Codex chốt từ mã gốc trước khi viết nguồn. Phạm vi: entry
`20ef0` đến ngay trước `212ff`, đi cả các nhánh `21578..216e5`,
`216e5..22397` và `22aa6..22aad`. Không nối tiếp phần quét lệnh/vị thế.
SHA toàn hàm `20ef0..2a1bc`:
`6bead161fa97b6568b546e8c86a4ff03fdda55d6fb226a52b58dd14ec050d920`.

## Giao diện và thứ tự

Nguồn mới `Bot3EvaluationPrelude.mqh` dùng lại `Bot3EvaluationHead.mqh`.
`Bot3EvaluationPreludeState` chứa `Bot3EvaluationHeadState head`,
`uchar session_flag`, `MqlTick tick`, `double spread`,
`MqlDateTime current_calendar`. Hàm
`Bot3PrepareEvaluation(uint index, uchar caller_flag,
Bot3EvaluationHeadInputs &inputs, Bot3EvaluationPreludeState &state)`.
Đầu vào `inputs` có thể bị ghi byte `native_1d6d08`; `state.tick` và
`current_calendar` ban đầu là dữ liệu đã có, không tự xóa trước gọi dịch vụ.

1. Gọi `Bot3BeginEvaluation` đã so 432 ca; giữ thứ tự lấy giờ máy chủ,
   đổi lịch, chọn tên mã, rồi đọc thông tin MQL số 7 khi cờ bằng 0.
2. Nếu mã nhánh là `BOT3_HEAD_NEXT_216E5`, ghi cờ thành 1 trước khi
   gọi Print; in ba đối số chuỗi đúng thứ tự:
   `"[SESSIONS] trade sessions reported for "`, tên mã đã chọn, `":"`.
   Không đổi thành một đối số nối sẵn.
3. Với mỗi ngày 0 đến 6: gọi `IntegerToString(day,0,32)`, tạo dòng
   `"   day "+kết_quả+":"`. Gọi `SymbolInfoSessionTrade` với tên mã
   đã chọn, ngày, chỉ số 0. Trả false thì nối `" none"`.
   Trả true thì với mỗi phiên: gọi `TimeToString(from,2)`, sau đó
   `TimeToString(to,2)`, nối `" ["+from_text+"-"+to_text+"]"`.
   Sau khi nối chỉ số 9 thì dừng; nếu chưa đủ, tăng chỉ số và gọi lại
   dịch vụ; false thì dừng. Tối đa 10 phiên, không gọi chỉ số 10.
   In một đối số là dòng đầy đủ cho mỗi ngày, rồi sang ngày sau.
   Điểm gốc: `217f8`, `21b0c`, `21b3b`, `21e13`, `22253`, `217ab`.
4. Xét lịch đã lấy ở phần đầu, không lấy giờ máy chủ lần nữa.
   Ngày 0 hoặc 6: `session_flag=1`, không gọi dịch vụ cho bước này.
   Ngày khác: gọi phiên 0, false thì `session_flag=0`.
   Nếu true, tính và so như mục dưới; mỗi phiên không bao phủ thời
   điểm thì gọi phiên tiếp. Hết chỉ số 9 hoặc các lần gọi sau trả
   false thì `session_flag=1`. Tìm thấy điều kiện thời gian thì bằng 0.
5. Sau bước trên hủy tên mã tạm (`state.head.selected_symbol=NULL`),
   rồi `SymbolInfoTick(inputs.symbol,state.tick)` — dùng tên mã gốc,
   không dùng tên thay thế ở bước 1. False thì `Print("Tick not ok")`,
   vẫn tiếp tục. `state.spread=state.tick.ask-state.tick.bid`.
   Cuối cùng gọi `TimeCurrent(state.current_calendar)` và bỏ giá trị trả.
   Dừng phạm vi ở `212ff`; chưa chạy nhánh cờ người gọi/quét lệnh.

## Phép so thời gian, giữ nguyên trường hợp lạ

Theo địa chỉ đối số tại call `215cc`/`216d3`: `from` là `[rsp+208]`,
`to` là `[rsp+200]`. Bản nháp cũ đã gọi ngược hai biến này.
Tại callee, con trỏ from ở `[rsp+28]`, to ở `[rsp+30]`.

- `now=(long)head.server_time % 86400`, `begin=(long)from % 86400`.
  Đây là chia dư có dấu, phần dư của số âm giữ dấu âm.
- Nếu `(long)to < 86401`: đặt `end=(long)to`. Nếu
  `((ulong)to-86340) < (ulong)0xfffffffffffeaebd`, đổi `end=86400`.
  Đây là phép trừ/so không dấu 64 bit, không thay bằng `to%86400`.
  Trong nhánh này, điều chỉnh áp dụng cho `to<=0` hoặc `to>=86340`.
  Nếu `end>=begin`, phiên bao phủ khi `begin<=now && now<=end`.
  Nếu `end<begin`, phiên bao phủ khi `now>=begin || now<=(long)to`.
- Nếu `(long)to >= 86401`: dùng `end=(long)((ulong)to%86400)` và
  điều kiện `now>=begin || now<=end`, kể cả khi `end>=begin`.
- Chỉ số 0 false ra `22aa6` khác với chỉ số sau false ra `211fe`.
  Mọi cạnh đều hội tụ `21200`; không có cạnh return/dừng bot ở đây.
  `211fe` chỉ ghi AL=1; `22aa6`/`2169e` xóa EAX.
  `21212` lưu dword đè nửa thấp thời gian ở `rsp+f8`. Phần sau chỉ
  dùng byte thấp tại điều kiện tương ứng `local_1d0` trong C; nguồn
  giữ byte đó ở `session_flag`, không bịa ý nghĩa cho các bit thanh
  ghi còn lại. Không coi giá trị dword thô là bool được khởi tạo đầy đủ.

## Bằng chứng chuỗi và giới hạn

Các descriptor gốc đã đọc: `677d0` là đầu thông báo, `66f98` là `:`,
`67800` là `   day `, `67828` là ` [`, `5cd78` là `Tick not ok`.
Các bộ đệm literal: `66fb0` là `-`, `67840` là `]`, `6785c` là ` none`.
Nội dung tên mã động không suy ra từ con trỏ heap.

Phải so cả thứ tự/đối số dịch vụ, ba đối số thông báo đầu và toàn bộ
chuỗi mỗi ngày, byte cờ trước Print, giá/lịch khi dịch vụ không ghi,
phép chia dư/biên thời gian và NULL/chuỗi rỗng. Bộ so chạy nguyên các
lệnh gốc từ `20ef0`, không thay helper ghép/hủy chuỗi hoặc đặt nhánh
giữa chừng. Dịch vụ MT5 và cấp bộ nhớ thành công được cung cấp riêng.
Lỗi cấp bộ nhớ, các phần sau `212ff` và cả EA vẫn chưa được chứng minh
chỉ bằng phép kiểm này. Không sửa EX5 gốc hoặc cờ bản quyền.
