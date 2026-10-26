# Viết chương trình kiểm khối chuẩn bị bot3 bằng bộ dữ liệu sẵn có

Viết `Bot3PreparationCheck.mq5` và `SUMMARY.md` trong CHÍNH thư mục này. Không sửa nguồn chính, chạy lệnh/Git/MT5 hoặc tạo tác tử; không đọc EX5/mã máy/phân tích. Opus5.5max, ultracode được yêu cầu. Codex tự đối chiếu độc lập.

Đọc `../bot3-preparation-complete-20261026-r1/TASK.md` và header đề xuất ở cùng thư mục đó để biết giao diện Bot3PreparationInputs/State và hàm void Bot3PrepareStrategy. Đây là mã được giao phiên khác; không sửa. Đọc Script `Bot3DistanceSettingsCheck.mq5` hiện hành và header Bot3DistanceSettings.mqh để tái dùng đúng định dạng dữ liệu. CHỈ dùng việc đọc/ghi cũ; chương trình mới PHẢI gọi Bot3PrepareStrategy, không gọi Bot3PrepareDistances hoặc tính kết quả mong đợi. Bộ dữ liệu đầu vào được Codex chọn từ các ca gốc chạy thành công, các lỗi runtime sẽ kiểm riêng, không bắt/né lỗi để cho kết quả đạt.

## Đọc dữ liệu

CheckRun string, chỉ a-z/0-9/- dài1..50. Files `bot3-preparation\\<run>\\`, không ghi đè đầu ra. cases.bin dùng NGUYÊN dạng chương trình cũ: đầu16byte int32magic0x44535431/version1/bot3/count, mỗi ca268byte. Count1..10000, tổng kích thước16+count*268, id liên tục từ0. Đọc đúng thứ tự các trường trong chương trình cũ, các số cờ giữuchar khi gán vào Inputs mới. Context giữ Bot3DistanceContext với sample/point/digits/stops_level/freeze_level/bid/ask/now. Không đọc/ghi struct có đệm.

Có thể đọc r kiểu Bot3DistanceInputs rồi chuyển tường minh vào Inputs mới. Các cờ của bộ ca cũ chỉ0/1. Bot3PreparationInputs mới: symbol="XAUUSD",comment="case"+IntegerToString(id),indicator_timeframe=15,indicator_period=30; reference=r.reference,variable_distances=(uchar)r.use_variable,adjust_lots=(uchar)r.adjust_lots,entry=r.entry và đủ mọi trường đã đọc tương ứng. KHÔNG tự tính tỷ lệ/đơn vị/khoảng cách để điền state.

ZeroMemory state và inputs mới ở mỗi ca, ArrayResize(state.indicator_values,0) tường minh. Không dùng state từ ca trước. Tạo các đầu vào bổ sung theo đúng bảng j/kiểu dưới đây; chỉ là dữ liệu đầu vào, không phải đáp án:

- double: `0.5+(double)id*0.125+(double)j*0.25`.
- int: `(id%2==0 ? 1 : -1)*(id+j+1)`.
- uchar: `(uchar)((id+j)%256)`.

| j | kiểu | input bổ sung | output đọc trực tiếp sau gọi |
|---:|---|---|---|
|0|double|native_6d250|native_6d4e0|
|1|uchar|native_6d258|native_6d4e8|
|2|double|native_6d260|native_6d4f0|
|3|double|native_6d268|native_6d4f8|
|4|double|native_6d270|native_6d500|
|5|uchar|native_6d278|native_6d508|
|6|int|native_1d6fa8|native_6d50c|
|7|uchar|native_1d6fc0|native_6d510|
|8|uchar|virtual_stops|mode|
|9|int|native_1d6fe8|native_6d518|
|10|uchar|native_1d7178|native_6d51c|
|11|uchar|native_6d2a3|native_6d520|
|12|int|native_6d2e0|native_6d550|
|13|int|management_timeframe|management_timeframe|
|14|uchar|native_6d3f8|native_6d608|
|15|double|native_6d3f0|native_6d600|
|16|double|native_6d408|native_6d618|
|17|double|native_1d7138|native_6d620|
|18|double|native_6d410|native_6d628|
|19|int|native_1d7130|native_6d630|
|20|double|native_6d418|native_6d638|
|21|uchar|native_6d420|native_6d640|

## Dịch vụ giả: đúng tham số, không thị trường thật

Include Bot3DistanceSettings.mqh đầu tiên (lấy kiểu Context; không SDK). Khai báo context toàn cục và7bộ đếm ở dưới. Định nghĩa các dịch vụ giả TRƯỚC macro/include Bot3Preparation.mqh. Header production chỉ có trong đề xuất phiên kia; viết include chuẩn `../../Include/bot-cua-toi-3/Bot3Preparation.mqh`, Codex ghép sau. Macro đổi iATR/CopyBuffer/iOpen/SymbolInfoTick/TimeCurrent/SymbolInfoDouble/SymbolInfoInteger thành các fake, rồi include, rồi undef đủ7macro. ArrayResize/ArraySetAsSeries vẫn là thật.

Mỗi dịch vụ tăng đúng bộ đếm của nó. Sai symbol/thuộc tính/tham số giữ fault đầu tiên; trả dữ liệu đã chỉ định để ghi được hồ sơ. Không đọc state/điều chỉnh đáp án.

- iATR(symbol,frame,period): yêu cầu symbolXAUUSD,frame15,period30, trả17.
- CopyBuffer(handle,buffer,start,count,double &target[]): yêu cầu17/0/0/100; ArrayResize(target,2); target[0]=context.sample,target[1]=context.sample; trả2. Không tự đặt series, header thực hiện.
- iOpen(symbol,frame,shift): yêu cầuXAUUSD/PERIOD_D1/1; trảcontext.sample.
- SymbolInfoTick(symbol,MqlTick&): yêu cầuXAUUSD; ghi tick.time=context.now,tick.bid=context.bid,tick.ask=context.ask; các trường khác giữ từ state đãZeroMemory; trảtrue.
- TimeCurrent(MqlDateTime&): tăng đếmTimeCurrent, ZeroMemory(calendar), trả(datetime)context.now. Quá tải TimeCurrent() khôngtham số cũng tăng CÙNG bộ đếm và trảthờigian này.
- SymbolInfoDouble(symbol,ENUM_SYMBOL_INFO_DOUBLE): chỉSYMBOL_POINT, trảcontext.point.
- SymbolInfoInteger(symbol,ENUM_SYMBOL_INFO_INTEGER): SYMBOL_DIGITS trả(long)context.digits, SYMBOL_TRADE_STOPS_LEVEL trảcontext.stops_level, SYMBOL_TRADE_FREEZE_LEVEL trảcontext.freeze_level; trường khácfault. Không ép long vềint.

Không cần giả Print/GetLastError, vì bộ ca này luôn trảhandle17/Ticktrue. Không gọi SDK thật ngoài các phép tệp/chuỗi/mảng ở Script. Không gửi lệnh. Reset7bộ đếm vàfault ca trước khi gọi; faultchung giữ đầu tiên cho toàn lượt.

Mỗi ca gọi `Bot3PrepareStrategy((uint)(id%9),inputs,state)` đúng một lần. Không thay hàm bằng mã khác, không đọc giá thật, không sửa giá trị state sau gọi để khớp.

## Đầu ra: 76 từ dữ liệu mỗi ca

mql5-results.bin đầu4int32: magic0x50525033/version1/count/fields76. Mỗi ca: idint32,successint32 luôn1 nếu hàm trảvề, sau đó76từ64bit. Các double ghi nguyên bitquaunion; int kéo dấuqua(long), uint/uchar giữ giátrị trướcFileWriteLong. KHÔNG làm tròn hayđổi sangchuỗi số. Nếu hàm thực sự phát lỗi runtime thìkhôngnuốt lỗi vàkhôngtựghi success.

35từ đầu giữ NGUYÊN thứ tự output của Script cũ nhưng lấy từ Bot3PreparationState mới: scale,lot_scale,unit,spread,max_spread,feature_flag,freeze_buffer,entry_frame,older_width,recent_width,last_shift,gap_points,buy_offset,sell_offset,nearby_radius,stop_distance,target_distance,trail_distance,trail_start,trail_limit,trail_step,trigger_distance,locked_distance,native_6d378,native_6d380,aux_frame,aux_scan,aux_older,aux_recent,aux_offset,min_change,stop_min_price,freeze_min_price,expiration_seconds,expiration.

Tiếp22từ theo thứ tự output của bảng j ở trên, đọc chính trường state (không dùng lại inputs, không tự tínhmode/600).

Tiếp12từ theo thứ tự: state.native_6d5c8,state.native_6d5f0(bits double),state.native_6d5dc,state.native_6d5e8(bits),state.native_6d5f8,state.expiration_hours,state.point(bits),state.strategy_index,state.indicator_handle,ArraySize(state.indicator_values),(int)ArrayGetAsSeries(state.indicator_values),FNV1a64 của state.comment UTF16LE khôngNUL.

Cuối7từ: số lần iATR,CopyBuffer,iOpen,SymbolInfoTick,TimeCurrent,SymbolInfoDouble,SymbolInfoInteger (thứtựnày). 35+22+12+7=76. FNVkhởiđầu0xcbf29ce484222325, mỗi byte XORrồinhân0x100000001b3 tràn64; StringGetCharactercấpushort, bămbyte thấp trước rồi bytecao.

Kết thúc tệp: kiểm đãđọcđúngFileSize, đóngtệp. Ghi script-status.bin gồm2int32 fault,count. Print cuối lượt sauundef. Không tạo profiles.bin, không kiểm BaseDistances hoặc thêm nhánh unrelated.

SUMMARY nêu đúng chưabiên dịch/chạy/đốichiếu; các lỗi runtime/chỉbáothấtbại/thiếu dữ liệu và toànEA nằmngoàilượt này. Codex sẽ chạy gốc thật độc lập, không dùng nguồn MQL5 mới làm đáp án.
