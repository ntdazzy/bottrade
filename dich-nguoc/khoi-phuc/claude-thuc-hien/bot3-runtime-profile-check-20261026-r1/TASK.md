# Viết bộ kiểm thuần số cho nạp tham số bot3

Chỉ ghi `Bot3RuntimeProfileCheck.mq5`, `Bot3RuntimeProfileApiCompile.mq5`, `runtime_profile_cases.py`, `SUMMARY.md` trong thư mục đề xuất này. Đọc TASK/functional-constants.json ở ../bot3-runtime-profile-20261026-r1, Bot3Preparation.mqh và các kiểu liên quan hiện hành; header sản phẩm ở thư mục đề xuất khi có. Không đọc thư mục phân tích hoặc tự tìm thuật toán. Không sửa nguồn chính/Git/MT5; không shell/tạo tác tử. Opus5.5max, ultracode.

Bộ kiểm chỉ gọi `Bot3LoadRuntimeProfile` thật và xuất trạng thái. Không có dịch vụ cần thay thế và không có lệnh giao dịch. Không tự tính kết quả mong đợi từ các công thức/bảng; bên quản lý chạy đối chiếu độc lập.

## Tệp và đầu vào

- inputstring CheckRun=""; chỉ1..50chữthường/số/`-`.
- Thư mục `bot3-runtime-profile\\<CheckRun>\\`; cases.bin, mql5-results.bin, script-status.bin. Không ghi đè kết quả/status đã có.
- Header3int32: magic0x52504633,version1,count1..10000.
- Mỗi ca **68byte** theo `<2iI7d`: idint32,indexint32,seeduint32, randomization,price_delta,stop_delta,target_delta,trail_delta,aux_delta,lock_delta (7double). seed đọcFileReadIntegercastuint, cho phép toàn32bit. Index0..8,idtăngliêntục. Cho phép±inf/NaN/dấu0 ởdouble; không lọc giá trị.
- Kiểm đúng độ dài12+count*68 trước chạy, kiểm EOF cuối nhưmẫu Script khác.

## Khởi tạo và kiểm giữ trường ngoài phạm vi

Include header `../../Include/bot-cua-toi-3/Bot3RuntimeProfile.mqh` thật. Không chép thân hàm vào Script và không define thay hàm sản phẩm.

Mỗi ca tạo Bot3PreparationInputs inputs, Bot3ProfileRuntimeState state, Bot3ProfileAdjustments adjustments. ZeroMemory để khởi tạo rồi điền seed/7tham số từca. Đặt hai intopaque của state bằng sentinel khác0 và khác giá trị bảng, để biết đã được ghi đè.

Các trường inputs NGOÀI31trường sản phẩm phải ghi: điền giá trị sentinel khác0 theo kiểu thật rồi chụp một bản trước khi gọi. Hai string dùng "KEEP.symbol.💰" và "KEEP.comment". Cácdouble dùng giá trị hữu hạn khác0, có thể thêm theoid; cácint/uchar dùng giá trị khác0 trong miền. Không dựa vào giá trị0 ban đầu để tuyên bố giữ nguyên.

Tập trường mà sản phẩm được ghi gồm:
`entry`(đủ6trường),buy_offset,sell_offset,nearby_radius,expiration_hours,stop_distance,target_distance,trail_distance,trail_start,trail_limit,trail_step,native_6d368,native_6d370,trigger_distance,locked_distance,aux_hour1,aux_scan50,aux_older,aux_recent,aux_offset,indicator_period,indicator_timeframe,native_6d2e0,management_timeframe. Haiintstate cũngđượcghi;seedđượcđổitheotham số.

Sau gọi đúng1lần `Bot3LoadRuntimeProfile((uint)index,adjustments,inputs,state)`, so tất cả trường inputs NGOÀI tập nêu trên với bản trước; double so từngbit bằngunion, số nguyên/string so trực tiếp. `untouched_changed=0` khi giữ nguyên hết,1khi cóbấtkỳtrường ngoài phạm vi bị đổi. Không tựso kết quả31trường với bảng/côngthức trongScript. Có thể viết helper so các trường không được đổi; phải bao đủ trường trong struct Bot3PreparationInputs hiện hành, không chỉ symbol/comment.

## Kết quả

Header3int32nhưinput. Mỗi ca **268byte** `<3i32Q`: id,Fault,untouched_changed rồi32ulong. Double ghi rawbits quaunion; int32códấu castlong→ulong;uchar/uint castulong. Thứ tự32word:

0state.random_seed
1state.native_6d324
2state.native_6d3c0
3entry.confirmation_frame
4entry.entry_frame
5entry.older_width
6entry.recent_width
7entry.last_shift
8entry.gap_points bits
9buy_offset bits
10sell_offset bits
11nearby_radius bits
12expiration_hours
13stop_distance bits
14target_distance bits
15trail_distance bits
16trail_start bits
17trail_limit bits
18trail_step bits
19native_6d368 bits
20native_6d370 bits
21trigger_distance bits
22locked_distance bits
23aux_hour1
24aux_scan50
25aux_older
26aux_recent
27aux_offset bits
28indicator_period
29indicator_timeframe
30native_6d2e0
31management_timeframe.

Đóngtệp vàghi status2int32Fault/count, giữ mãFault đầu tiên. Fault không được gộp với untouched_changed vì một cái là lỗi bộ đọc/chạy, một cái là quan sát trạng thái. ApiCompile chỉ includeheaderthật và inputboolInvokeFunctions=false; khi true tạo đủstruct/index0 rồi gọi; bên quản lý chỉbiêndịch.

## Python ca kiểm

MAGIC=0x52504633; INTfieldsid/index/seed; DOUBLES theo7trường ởtrên. `RESULT=struct.Struct('<3i32Q')` size268; RESULT_NAMES đúng3+32trườngđầura. cases() trảdict vớiidliêntục và group, encode() tạoheader3int32 vàtừngrow `<2iI7d`. Không tạoexpected hoặc dùngbảngkếtquảtrongcodePython.

Tổng **2106ca** theo thứ tự:
1.486ca: index0..8 ×seed[0,1,2,2147483647,2147483648,4294967295] ×randomization[-1.0,-0.0,0.0,1e-300,1.0,17.25,1000.0,NaN,+inf]. Sáu delta0.0;group `randomization-and-seed`.
2.1620ca: index0..8 ×từng6delta ×10giátrị[-1e16,-0.1,0.0,0.1,1e16,qNaNbits0x7ff8000000000123,qNaNbits0xfff8000000000456,sNaNbits0x7ff0000000000789,+inf,-inf] ×randomization[0.0,17.25,+inf]. Seed1, chỉdelta đang xét bị đổi, còn lại0.0;group `delta-and-floating-order-<field>`.

TạoNaNpayload bằngstructpack/unpackQ/d nhưmẫu, không qua phép toán làm mấtbits. Đừng bỏca khó hoặc soNaN theo tính bằng nhau; xuất ra để bên quản lý đối chiếu đúngbits.

SUMMARY ghi các tệp, kiểu/dung lượng và chưa tự biên dịch/chạy. Không gọi cảbot/chiến lược đã hoàn thành.
