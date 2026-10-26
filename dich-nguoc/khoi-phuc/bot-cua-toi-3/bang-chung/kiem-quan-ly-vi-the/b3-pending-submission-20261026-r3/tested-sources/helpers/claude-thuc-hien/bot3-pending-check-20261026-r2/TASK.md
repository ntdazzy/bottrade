# Viết bộ kiểm MQL5 cho khối đặt lệnh chờ

Chỉ viết `Bot3PendingSubmissionCheck.mq5`, `Bot3PendingSubmissionApiCompile.mq5`, `SUMMARY.md` trong thư mục đề xuất này. Đọc TASK chức năng ở `../bot3-pending-submission-20261026-r2/TASK.md` và header khi xuất hiện cùng thư mục đó; nếu chưa có header, dùng giao diện trong TASK, không chờ. Đọc các header cần thiết và hai mẫu Script `Bot3ManagementBarGateCheck.mq5`, `Bot3PreparationApiCompile.mq5` ở nguồn bot3. Không đọc mã gốc/EX5/phân tích. Không sửa nguồn chính/Git/MT5, không dùng shell hoặc tạo tác tử. Yêu cầu Opus5.5max, ultracode.

Codex sẽ cung cấp tệp ca kiểm và kết quả mong đợi bằng chạy mã gốc độc lập. Script chỉ đọc ca, gọi mã sản phẩm THẬT và xuất quan sát; không tính kết quả mong đợi hoặc tự khẳng định đạt. Các dịch vụ/hàm con được thay bằng trả lời hữu hạn sau đây, không gửi lệnh tài khoản.

## Chặn hàm con đúng phạm vi

Include sáu header phụ thuộc thật TRƯỚC các macro (các guard ngăn include lại). Sau đó define các tên `SymbolInfoInteger`, `Bot3MarginGuard`, `Bot3ValidateVolume`, `Bot3AllowsPendingOrder`, `Bot3OpenPending`, `Sleep`, `GetLastError`, `Bot3TradeErrorText`, `Print` thành tên Fake riêng, include `../../Include/bot-cua-toi-3/Bot3PendingSubmission.mqh`, rồi undef. Giữ `Bot3RoundPrice` thật. Định nghĩa hàm Fake sau include để có kiểu settings. Dữ liệu fixture toàn cục: settings S, double V[9], uint Index, double Table[][2] ArrayResize100, uint Errors, trade T/options O. Hàm FakeOpenPending phải đọc các ĐỐI SỐ được truyền, không lấy globals thay args. Các Fake khác cũng vậy. Không thay/viết lại thân sản phẩm trong Script.

## Tệp ca kiểm

`input string CheckRun="";` chỉ chấp nhận1..50ký tự chữ thường/số/`-`. Thư mục `bot3-pending-submission\\<CheckRun>\\`. Cấm ghi đè `mql5-results.bin` hoặc `script-status.bin`. Header cases.bin ba int32: magic0x50534233, version1, count1..10000.

Mỗi ca đọc liên tục theo thứ tự:
- 22 int32: id,buy,check_free_margin,omit_real_sl_tp,virtual_expiration,strategy_magic,strategy_index,digit0,digit1,digit2,margin_reply,volume_reply,limit_reply,initial_accept,retry_count,retry_accept_mask,initial_error,final_error,cache_mode,mutation_at,error_count,case_tag.
- Một int64: expiration.
- Tám double: base_price,unit,stop_distance,take_distance,minimum_stop_price,minimum_freeze_price,ask,bid.
- Hai chuỗi symbol/comment, mỗi chuỗi int32 số đơn vịUTF16 rồi đúng số ushort; không có byte null cuối. Kiểm độ dài0..128. FileReadInteger(...,SHORT_VALUE) castushort để giữ Unicode.

Kiểm id tăng từ0, buy/ba reply/initial_accept 0hoặc1, flags0..255,index0..8,retry_count0..3,cache_mode0..5,mutation_at0..9. error_count đọcint32 rồi castuint, cho phép toàn32bit. Không diễn giải case_tag. Không yêu cầu độ dài tệp cố định vì có chuỗi; cuối cùng FileTell phải bằngFileSize.

## Khởi tạo và đổi dữ liệu

Mỗi ca ZeroMemory S/T/O rồi chép các trường từ ca, Index từstrategy_index, Errors từerror_count, FakeLastError=0. V[i]=0.125*(i+1). T.magic=0x0123456789abcdef; O.async_mode=2; O.log_level=3; O.margin_mode=1. Các bộ đếm0, hash=0xcbf29ce484222325.

Table100x2: với mọi hàngi, cột0=1000.0+i,cột1=2000.0+i; sau đó:
cache_mode0: tất cả hai cột0.0;
1: chỉTable[50][0]=+0.0;
2: chỉTable[99][0]=+0.0;
3: giữ đầy;
4: Table[0][0]=quietNaN bits0x7ff8000000000000, Table[1][0]=-0.0;
5: Table[0][0]=+inf bits0x7ff0000000000000, [1][0]=-inf bits0xfff0000000000000, [2][0]=quietNaN, [3][0]=-0.0.

`ApplyMutation(trigger)` chỉ làm khi case.mutation_at==trigger và chưa từng đổi. Trước khi đổi ghi event9 với trigger. Sau đó đổi: symbol="NEXT",comment="changed",unit=0.25,stop_distance=7.25,take_distance=9.5,expiration=9876543210,strategy_magic=-77, omit_real_sl_tp=(cờ hiện tại==0 ?255:0),virtual_expiration=255, Index=(Index+1)%9,V[i]=0.25*(i+5), ask=base_price-5.0,bid=base_price+5.0,minimum_freeze_price=2.125,minimum_stop_price=1.25; T.magic=0xfedcba9876543210,O.async_mode=5,O.log_level=-2,O.margin_mode=2. check_free_margin giữ nguyên. Không đổi giá cục bộ trong sản phẩm.

## Ghi dấu và các Fake

Mỗi event gọi BeginEvent(kind) tăng Events và băm wordkind; rồi băm từng word theo thứ tự dưới đây. Mỗi word là ulong8byte, băm từngbyte từ thấp lên cao: hash^=byte;hash*=0x100000001b3 (trànulong). Số có dấu castqua long sangulong. Double dùng union để giữ đúng64bit. Chuỗi băm FNV cùng cách, nhưng duyệt từngushort UTF16, bămbyte thấp rồi cao; hash riêng ban đầu như trên. Không chuẩn hóa NaN/dấu0.

1. FakeSymbolInfoInteger(string symbol,ENUM_SYMBOL_INFO_INTEGER prop): dùng digit0/1/2 theo số lần gọi, quá3thì Fault. Event1: prop,symbol_hash,reply(castlong). Tăng DigitsCalls; ApplyMutation(1/2/3 theo lần gọi). Trả longreply.
2. FakeMarginGuard(symbol,type,volume): Event2: symbol_hash,type,volume_bits,margin_reply. Tăng MarginCalls, ApplyMutation(4), trảboolreply.
3. FakeValidateVolume(symbol,volume): Event3: symbol_hash,volume_bits,volume_reply. Tăng VolumeCalls, ApplyMutation(5), trảreply.
4. FakeAllowsPendingOrder(): Event4: limit_reply. Tăng LimitCalls, ApplyMutation(6), trảreply.
5. FakeOpenPending có nguyên giao diện sản phẩm. ordinal=SendCalls trước tăng. reply=initial_accept nếuordinal0, ngược lại bit(ordinal-1) của retry_accept_mask. Event5: type,volume_bits,price_bits,sl_bits,tp_bits,expiration,magic,virtual_expiration,symbol_hash,comment_hash,state.magic,options.async_mode,options.log_level,options.margin_mode,reply. TăngSendCalls. FakeLastError=initial_error nếuordinal0, ngược lại final_error nếuordinal>=retry_count, còn lại132. ApplyMutation(7) nếuordinal0; ApplyMutation(9) chỉ nếuordinal1. Trảreply. Quá4lần thìFault, trảfalse vàFakeLastError=999 để tránh treo bộ kiểm. Đây là chặn trong bộ kiểm, KHÔNG thêm giới hạn vào sản phẩm.
6. FakeSleep(int milliseconds): Event6:milliseconds. TăngSleepCalls; chỉ lần đầu ApplyMutation(8). Không ngủthật.
7. FakeGetLastError(): trảFakeLastError, khôngghi event.
8. FakeTradeErrorText(int code,uint &counter): old=counter;counter++; text="error-"+IntegerToString(code). Event7: code,old,counter,text_hash. TăngErrorCalls, trảtext. Đọc counterđối số.
9. FakePrint(string text): Event8:text_hash; tăngPrintCalls.

Event ghi TRƯỚC ApplyMutation và giá trị trả về. Không gọi các API giao dịch thật. Tất cả lỗi bộ kiểm giữ mãFault đầu tiên; bộ kiểm dừng sau xuấtca đanglỗi.

## Kết quả

Gọi `Bot3SubmitPendingAfterPrice(case.buy!=0,case.base_price,S,V,Index,Table,Errors,T,O)` đúngmộtlần. Xuất header baint32 giốngcases. Mỗi ca: int32id,int32Fault rồi **241ulong** bằngFileWriteLong castlong, theođúngthứtự:

- 14word: Events,Hash,DigitsCalls,MarginCalls,VolumeCalls,LimitCalls,SendCalls,SleepCalls,PrintCalls,ErrorCalls,MutationCount,Errors,FakeLastError(signextend),Index.
- 14word settings: check_free_margin,omit_real_sl_tp,virtual_expiration,strategy_magic(signextend),expiration,unit_bits,stop_distance_bits,take_distance_bits,minimum_stop_price_bits,minimum_freeze_price_bits,ask_bits,bid_bits,symbol_hash,comment_hash.
- 4word: T.magic,O.async_mode,O.log_level(signextend),O.margin_mode(signextend).
- 9word bitcủaV[0..8].
- 200word bitcủaTable theo hàng rồi cột.

Mỗi ca1936byte. Đóngtệp, ghi script-status.bin haiint32 Fault/count. Print trạng thái Script khi ngoài macrosđãundef. Không tựassert giá trị mong đợi. Ghiđúng lỗi đọc thiếu/dữ liệu khônghợp lệ. SUMMARY ghi chưa tự biên dịch/chạy.

ApiCompile chỉ include header sản phẩm thật, `input bool InvokeFunctions=false`; OnStart chỉ gọi khi InvokeFunctions==true. Tạo đủstruct/9vols/100x2table, gọi nguyên giao diện vớiIndex hợp lệ. Codex CHỈ BIÊN DỊCH, không chạy Script này.
