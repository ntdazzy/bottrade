# Bot 1 — đầu đánh giá đến sau cập nhật giá/lịch

Codex đã đọc mã gốc và chốt trước khi viết nguồn. Hàm `18aa0..1ef9c`
có SHA `45d53270186b7019a8721e0cf3734a61aac8e8660c70f7e602849b1c298d7cbd`.
Phần cần viết chạy từ entry `18aa0` đến ngay trước `18eb1`, gồm các
nhánh kiểm phiên `18f3b..190a4`, báo phiên `190a4..19d17` và nhánh
đặt cờ `1a2eb..1a2f2`. Không chạy quét vị thế/lệnh ở phần sau.

## Giao diện

Một tệp `Bot1EvaluationPrelude.mqh`, không phụ thuộc nguồn bot 3.
`Bot1EvaluationPreludeInputs`: `string symbol`, `string native_6a428`,
`uchar native_6a3b4`. Cờ cuối được sửa thành 1 khi cần in các phiên.
`Bot1EvaluationPreludeState`: `uint strategy_index`, `datetime server_time`,
`MqlDateTime calendar`, `string selected_symbol`, `uchar session_flag`,
`MqlTick tick`, `double spread`, `MqlDateTime current_calendar`.
Hàm `Bot1PrepareEvaluation(uint index, Bot1EvaluationPreludeInputs &inputs,
Bot1EvaluationPreludeState &state)`; không có cờ người gọi DL như bot 3.

1. Lưu index32bit (`18b01`, `[rsp+bc]`). Lấy `TimeTradeServer()` đúng
   một lần (`18c81`), giữ giá trị 64bit (`[rsp+f8]`); gọi TimeToStruct
   (`18ca0`) ghi 8 int32 vào lịch (`[rsp+50]`, thứ tuần ở `+68`). Bỏ bool
   trả về; khi dịch vụ không ghi thì giữ lịch ban đầu.
2. So tên mã `symbol` (descriptor `67918`, con trỏ `6791c`) với chuỗi
   rỗng literal `517d8`. Nếu bằng chuỗi rỗng thì chọn `native_6a428`;
   NULL giữ nguyên tên gốc. Sao vào `state.selected_symbol` (`sp+110`).
3. Nếu cờ `native_6a3b4==0`, gọi `MQLInfoInteger((ENUM_MQL_INFO_INTEGER)7)`
   (`18d8f`). Kết quả int32=0 đi `190a4`; ghi cờ thành1 TRƯỚC Print.
   Cờ khác0 hoặc thông tin khác0 thì không in. Không đọc thông tin6 ở
   phần này; thông tin6 nằm sau đoạn quét vị thế ngoài phạm vi.
4. Thông báo và kiểm phiên dùng đúng công thức đã chốt dưới đây.
5. Hủy tên mã tạm `state.selected_symbol=NULL`; `SymbolInfoTick(inputs.symbol,
   state.tick)` dùng tên gốc, không dùng tên thay thế (`18e2b`). False
   thì `Print("Tick not ok")`, vẫn tiếp tục. Tính `ask-bid` ghi spread
   (`62560`), rồi `TimeCurrent(state.current_calendar)` (`18eaf`, lịch
   global `67790`). Dừng trước `18eb1`, không sửa cờ `62418` hoặc quét vị thế.

## Thông báo 7 ngày

Raw các descriptor đã đọc trực tiếp: `5d500` =
`[SESSIONS] trade sessions reported for `; `5d520` = `:`;
`5d550` = `   day `; `5d578` = ` [`; `545c8` = `Tick not ok`.
Các bộ đệm sau số độ dài: `5d590` = `-`, `5d5a0` = `]`, `5d5bc` = ` none`.

Print đầu có BA đối số: đầu thông báo, selected_symbol, dấu `:`;
không gộp thành1đối số (`1910a`). Mỗi ngày0..6 gọi
`IntegerToString(day,0,32)` rồi tạo `"   day "+số+":"`.
Gọi SymbolInfoSessionTrade(selected_symbol,day,0,from,to); false thì
nối ` none`. True thì gọi TimeToString(from,2), rồi TimeToString(to,2),
nối `" ["+from_text+"-"+to_text+"]"`. Dừng sau chỉ số9; nếu chưa đủ,
tăng chỉ số và gọi lại, false thì dừng mà KHÔNG thêm ` none`.
In một đối số là dòng đầy đủ, rồi ngày tiếp. Con trỏ báo phiên:
from=`sp+198`, to=`sp+190` (call `194cc`/`19bd2`).
Thứ tự dịch vụ tương ứng bot 3 đã so, nhưng mã gốc của bot 1 vẫn phải
chạy riêng làm đối chứng, không lấy đầu ra bot 3 làm kết quả mong đợi.

## Kiểm giờ giao dịch

Ngày0/6 => cờ1, không gọi kiểm phiên. Ngày khác gọi phiên0 (`18f8f`):
false => cờ0. Mọi cạnh hội tụ `18daf`, vẫn đi lấy giá, không return/dừng.
from là `sp+1a8`, to là `sp+1a0`; tại callee from ở `sp+28`, to ở `sp+30`.

`now=(long)server_time%86400`, `begin=(long)from%86400` (chia dư có dấu).
Nếu `(long)to<86401`, đặt end=(long)to; nếu
`((ulong)to-86340)<(ulong)0xfffffffffffeaebd`, end=86400.
Nếu end>=begin: cờ0 khi begin<=now && now<=end.
Nếu end<begin: cờ0 khi now>=begin || now<=(long)to.
Nếu `(long)to>=86401`: cờ0 khi now>=begin ||
now<=(long)((ulong)to%86400), kể cả khi hai đầu sau chia dư không đảo nhau.
Còn lại thử phiên tiếp, tối đa0..9. Hết10 hoặc các lần sau false =>cờ1.
`18dad` chỉ sửa AL=1; `1a2eb`/`1905e` xóa EAX; `18dc1` ghi dword vào
`sp+c0`. Bộ nguồn so byte thấp này, không gọi các bit thanh ghi còn lại
là một bool được khởi tạo đầy đủ.

## Phép kiểm và việc chưa chứng minh

So 30 giá trị ngôn ngữ và toàn bộ dịch vụ/đối số/UTF16/NULL, gồm dữ liệu
cũ khi dịch vụ không ghi, lịch lỗi, 10 phiên và biên số64bit. Dùng nguyên
thân/lệnh/helper chuỗi của bot1, chỉ cấp trả lời SDK/cấp bộ nhớ thành công.
Không sửa EX5, cờ bản quyền hoặc đặt lại thanh ghi ở giữa.
Không dùng kết quả thành phần này để chốt EA hay ngữ cảnh R12 tại
nơi gọi quản lý vị thế: phần nối qua các nhánh sau còn phải kiểm liên tục.
Lỗi cấp bộ nhớ, các nhánh từ `18eb1`, cài đặt/hiển thị, vòng đời và
toàn bộ EA vẫn chưa được chứng minh.
