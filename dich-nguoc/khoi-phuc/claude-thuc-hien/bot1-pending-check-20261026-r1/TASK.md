# Viết bộ kiểm MQL5 và ca kiểm cho khối đặt lệnh bot1

Chỉ viết `Bot1PendingSubmissionCheck.mq5`, `Bot1PendingSubmissionApiCompile.mq5`, `pending_submission_cases.py`, `SUMMARY.md` trong thư mục đề xuất này. Đọc TASK ở ../bot1-pending-submission-20261026-r1 và header khi có; không chờ header. Dùng bộ kiểm/cases bot3 hiện hành làm mẫu, không tự tạo kết quả mong đợi. Chỉ đọc nguồn sản phẩm/Script/tests này; không đọc thư mục phân tích hoặc tự tìm thuật toán. Không sửa mã chính/Git/MT5, không shell/tạo tác tử. Opus5.5max và ultracode.

Codex tự chạy phần đối chiếu gốc độc lập. Script gọi THÂN SẢN PHẨM thật bằng các dịch vụ trả lời hữu hạn; không gửi lệnh tài khoản.

## Khác với bộ bot3

1. Đổi mọi tên Bot3/đườngbot3 thành Bot1/bot1, hàm public `Bot1SubmitPendingAfterPrice`. Include trước macro chỉ5header: PriceLevels,Margin,VolumeValidation,TradeSend,TradeErrors. Không include OrderScan.
2. Chặn `SymbolInfoInteger,Bot1MarginGuard,Bot1ValidateVolume,Bot1OpenPending,Sleep,GetLastError,Bot1TradeErrorText,Print`; THÊM `AccountInfoInteger` và `OrdersTotal`, KHÔNG chặn/không tự tạo Bot1AllowsPendingOrder. Giữ Bot1RoundPrice và Bot1SubmissionDifference thật. Define trước includeheader, undef ngay sau. Fakes đọc đối số thật.
3. V[8], Index0..7, đổiIndex=(Index+1)%8 và vòngV8. Giá trị V[i]=.125*(i+1); sau đổi=.25*(i+5). Mọi phần Table100x2/hàm băm/string/flags/đổi dữ liệu/error giống mẫu bot3.
4. Inputthưmục `bot1-pending-submission\\<CheckRun>\\`, magic0x50534231,version1,count1..10000, tên tệpkếtquả/statusgiốngmẫu. CheckRun1..50chữthường/số/`-`, không ghiđè. Kiểm đọc đủ/tệp dư nhưmẫu.

## Định dạng ca

22int32 theođúngthứtự: id,buy,check_free_margin,omit_real_sl_tp,virtual_expiration,strategy_magic,strategy_index,digit0,digit1,digit2,margin_reply,volume_reply,orders_total,initial_accept,retry_count,retry_accept_mask,initial_error,final_error,cache_mode,mutation_at,error_count,case_tag.

Tiếp2int64: expiration,order_limit. Tiếp8double: base_price,unit,stop_distance,take_distance,minimum_stop_price,minimum_freeze_price,ask,bid. Phần cố định168byte. Sauđó2chuỗisymbol/comment nhưmẫu: int32đếmUTF16 +từngushort, khôngnullcuối,độdài0..128.

Kiểm margin_reply,volume_reply,initial_accept,buy là0/1; flags0..255,index0..7,retry_count0..3,cache_mode0..5,mutation_at0..10. orders_total làbấtkỳint32códấu, order_limit bấtkỳint64códấu; KHÔNG ép chúng thànhbool. error_count đọcint32castuint toàn32bit.

Khởi tạo cùng mẫu: S từca,T/OZeroMemory rồiT.magic0x0123456789abcdef,options2/3/1,FakeLastError0,Errorsuintca,Indexuintca,V8,Table100x2,theo6cache_mode nhưmẫu. Dùngbitunion tạo±inf/NaN/-0. Bộđếm0,HashFNVbasis. ApplyMutation(trigger) giống bot3, mộtlần; ngoại trừ Index%8,V8. Không đổi order_limit/orders_total khi đổi dữ liệu.

## Sự kiện/Fake

Giữ event/cáchbămword/chuỗi từmẫu, với sự kiện giới hạn thay đổi:

- event1Digits: property,symbol_hash,replysignextend. DigitsCalls++,ApplyMutation1/2/3.
- event2Margin: symbol_hash,type,volumebits,reply. MarginCalls++,Mutation4.
- event3Validate: symbol_hash,volumebits,reply. VolumeCalls++,Mutation5.
- **FakeAccountInfoInteger(ENUM_ACCOUNT_INFO_INTEGER prop)**: trảlongCase.order_limit. Event4: prop (ACCOUNT_LIMIT_ORDERS=47),replyraw64bits. AccountLimitCalls++,ApplyMutation6. Phảighi47vàthựcsố64bit,khôngghi bool.
- **FakeOrdersTotal()**: trảintCase.orders_total. Event10: replysignextend64. OrdersTotalCalls++,ApplyMutation10.
- event5OpenPending: type,volumebits,pricebits,slbits,tpbits,expiration,magic,virtual_expiration,symbol_hash,comment_hash,state.magic,options.async_mode,options.log_level,options.margin_mode,reply. ordinal/giớihạnbộkiểm4lần vàcáchtínhreply/error nhưmẫu. Mutation7lầnđầu/9lầnthử1.
- event6Sleep: milliseconds;Mutation8lầnđầu,khôngngủthật.
- FakeGetLastError trảFakeLastError,khôngevent.
- event7ErrorText: code,oldcounter,newcounter,text_hash; text="error-"+IntegerToString(code),tăngquađốisố.
- event8Print:text_hash.
- event9Mutation:trigger trướcđổidữliệu.

GiữFaultđầutiên; chặnthửvượt4lần chỉởFake đểkhôngtreo, khôngsửa sảnphẩm. APIthật khôngđượcchạy. Fakes phải cógiao diện đúngMQL5, địnhnghĩasauincludeđểcósettings type.

## Kết quả: vẫn241ulong, mỗi ca1936byte

Header3int32nhưinput. Mỗi caint32id,int32Fault rồi241ulong theođúngthứtự:

- **15word**: Events,Hash,DigitsCalls,MarginCalls,VolumeCalls,AccountLimitCalls,OrdersTotalCalls,SendCalls,SleepCalls,PrintCalls,ErrorCalls,MutationCount,Errors,FakeLastError(signextend),Index.
- 14wordsettingsnhưbot3: check_free_margin,omit_real_sl_tp,virtual_expiration,strategy_magic(signextend),expiration,unitbits,stop_distancebits,take_distancebits,minimum_stop_pricebits,minimum_freeze_pricebits,askbits,bidbits,symbol_hash,comment_hash.
- 4word:T.magic,O.async_mode,O.log_level(signextend),O.margin_mode(signextend).
- **8word**:V0..7bits.
- 200word:Tabletheohàngrồicột.

Gọi sảnphẩm đúng1lần/mỗica, khôngtínhtựexpected. Đóng/ghi status2int32Fault/countnhưmẫu. ApiCompile:includeheaderthật,inputboolInvokeFunctions=false,OnStartchỉgọikhitrue;tạoV8/Index0/Table100x2vàđủstruct. CodexchỉbiêndịchScriptAPI.

## Python ca kiểm, không tính expected

Saochép `bot-cua-toi-3/tests/pending_submission_cases.py` hiện hành332ca làmcơsở;đổiMAGIC/tênhằng/RESULT_NAMESchoformattrên.

- INTScùng22trườngnhưng `limit_reply` đổi `orders_total`; thêmorder_limit vàoencode sauexpiration bằng `<22i2q8d`.
- Base:strategy_index=3,orders_total=0,order_limit=100. Cácgiátrịkhác giữnhưmẫu.
- Vòngearly-return-order: vẫn lặp3boolmargin/volume/limit;vớilimit1đặtorders_total0,vớilimit0đặtorders_total100. order_limit100.
- Cácchỉsốcachetườngminhđổi[0,4,8]thành[0,3,7]. Các332ca cònlạigiữcấutrúc/nhóm/thứtựnhưmẫu,bao24caNaNpayload/tíchvôcựcvới0. Khôngthêmlimit_replycũvàkhôngđổiFNV/table/encodingchuỗi.
- SAU332ca,thêm80ca:buy0/1 ×order_limit[0,1,-1,1<<32,(1<<32)+1,(1<<32)-1,(1<<63)-1,-(1<<63)] ×orders_total[-1,0,1,99,2147483647],c=base(buy),chỉđổi2trường;group `account-limit-int32-and-short-circuit`.
- Thêm4ca:buy0/1 ×omit0/255,c=base(buy);mutation_at10,initial_accept0,initial_error132,retry_count2,retry_accept_mask1,final_error134,omitflagtheovòng;group `orders-total-mutation`.
- Tổng416ca,idtăngliêntục0..415. RESULT `<2i241Q`;RESULT_NAMES241phầntửtheođầu raởtrên. vol8+meta15bùnhau,nênkíchthước1936khôngđổi.

SUMMARY ghiđủtệpvàgiớihạnchưachạy. Chỉgiao mãthật,khôngplaceholderhoặcghiđèđườngkhác.
