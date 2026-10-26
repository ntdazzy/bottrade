# Viết bộ ca và chương trình kiểm điều phối bot1

Viết `router_cases.py`, `Bot1ManagementRouterCheck.mq5`, `SUMMARY.md` vào CHÍNH thư mục đề xuất này. Không sửa nơi khác, không chạy lệnh/Git/MT5, không tạo tác tử. Không đọc EX5/mã máy/thư mục phân tích. Codex chốt mô tả; bạn chỉ triển khai. Opus5.5 max, ultracode được yêu cầu. Nếu không ghi được thì trả đủ nội dung, không đổi chỗ ghi.

Đọc mô tả `../bot1-main-router-20261026-r1/TASK.md` để biết giao diện/chức năng. Header được giao phiên khác, không tạo bản thay thế. Chỉ kiểm MQL5, không viết Python tính kết quả mong đợi. Codex chạy mã gốc độc lập. Tham khảo Script `bot-cua-toi-3/source/MQL5/Scripts/bot-cua-toi-3/Bot3ManagementBarGateCheck.mq5` và `bar_gate_cases.py` về định dạng và chặn dịch vụ; không suy logic bot1 từ bot3.

## Tệp đầu vào chung

`MAGIC=0x4d525431`, version1. Đầu tệp `<3i>`: magic/version/count. Mỗi ca88byte `<14i4q>` gồm:

INTS = id,index,timeframe,after_first_frame,buy_reply,sell_reply,change_first_bar,change_buy,license_valid,tick_management,bar_override,profile,shrink_after_buy,magic

LONGS = previous,observed,second,after_first_bar

Python `cases()` trả dict mới mỗi lần, `encode(rows)` giữ đúng thứ tự, kiểm kiểu int/độ rộng/id liên tục và miền được mô tả. Không số ngẫu nhiên/ghi tệp/kết quả mong đợi. Tạo ca bằng tích có thứ tự:

- license_valid=(0,1)
- route_flags=((0,0),(1,0),(1,1)) -> tick_management,bar_override
- profile=range(8)
- times=((1000,1000,1100),(1000,1100,1200)) -> previous,observed,second
- buy_reply=(0,1)
- sell_reply=(0,1)
- change_buy=(0,1)
- shrink_after_buy=(0,1)

Tổng1536ca. id liên tục từ0, index=(id%3)*3 (0,3,6), timeframe=15,after_first_frame=16385,change_first_bar=id%2,after_first_bar=5000,magic=-123 nếu id%3==0 ngược lại123. group có thể thêm nhưng không ghi nhị phân. Bộ ca chỉ tạo đầu vào.

## Chương trình MQL5

Đọc input string CheckRun giống chương trình tham khảo. Thư mục Files `bot1-management-router\\<CheckRun>\\`. Không ghi đè đầu ra cũ. Kiểm tên lượt chỉ a-z/0-9/- dài1..50, count1..10000, tổng kích thước12+count*88, id liên tục/miền cờ0..1,profile0..7,index0..7. Đọc/ghi từng trường FileReadInteger/FileReadLong, không FileReadStruct vì đệm căn lề. Tạo mql5-results.bin vàscript-status.bin chứa2int32 fault,count. Kết quả chung cùngmagic/version/count. Không giao dịch thật.

Include Bot1PositionManagement.mqh TRƯỚC macro để loại ảnh hưởng mock lên thân manager. Sau khi định nghĩa mock, macro đổi iTime/PositionsTotal/PositionGetTicket/PositionGetInteger/PositionGetString/Print/Bot1ManagePositions, include `../../Include/bot-cua-toi-1/Bot1ManagementRouter.mqh`, rồi undef đủ. Tên/giao diện dịch vụ giả như SDK thật và manager chuẩn. Chỉ dùng Printmột tham số string ở router; Print báo cuối chạy SAU undef.

Trạng thái mỗi ca: ZeroMemory settings/shared/requests/options. symbol="CHECK",settings.magic=case.magic,finish.mode=1,shared.counter=7,shared.strategy_index=(case.index+1)%8,shared.last_ticket=999. bars[i]=100+i, riêngbars[index]=previous; levelsBuy[i]=10.0+i,sell=20.0+i. timeframe=case.timeframe. valid/tick/override là uchar giữ nguyên ca. deviation0x0123456789abcdef. selected=-1,total_calls=0,buy_calls=sell_calls=0. Hash FNV1a64 khởi đầu0xcbf29ce484222325; mỗi byte XOR rồi nhân0x100000001b3, tràn64bit.

Danh sách vị thế giả: mỗi hàng ticket ulong,magic long,type long,symbol string. K=case.magic kéo dấu long. Theo profile:

0. rỗng
1. (101,K,0,"CHECK")
2. (102,K,1,"CHECK")
3. (0,K,0,"CHECK"),(202,K+1,0,"CHECK"),(203,K,2,"CHECK"),(204,K,0,"OTHER"),(205,K,0,"CHECK"),(206,K,1,"CHECK")
4. (301,K+4294967296,0,"CHECK"),(302,K+4294967296,1,"CHECK")
5. (401,K,4294967296,"CHECK"),(402,K,4294967297,"CHECK")
6. (501,K,0,"OTHER"),(502,K,1,"OTHER")
7. (601,K,0,"CHECK"),(602,K,1,"CHECK")

Mỗi lời gọi giả ghi MỘT sự kiện gồm5ulong, băm từng từ theo8byte thứ tự ít quan trọng trước, tăng events. Không dùng chuỗi dạng số để băm. Các mã và4đối số:

- PositionsTotal: tăng total_calls trước; value=live_count, riêngprofile7 với total_calls==2 trả0. Ghi `(5,total_calls,value,live_count,0)`; trảintvalue.
- PositionGetTicket(index): index trong danh sách sống vàticket!=0 thì selected=index, trảticket; vé0/ngoài danh sách trả0 và giữ selected trước đó. Ghi `(6,index,ticket,selected,0)` sau chọn. Không tự loại hàng vé0 trong Total.
- PositionGetInteger(prop): yêu cầu selected hợp lệ; propMAGIC12 trả full longmagic, TYPE2 trả full longtype, mã khácfault. Ghi `(7,prop,value,selected,0)`; giữ dấu bằng ép qua long rồiulong.
- PositionGetString(prop): yêu cầu selected hợp lệ/propSYMBOL0, trảchuỗi hàng. Ghi `(8,prop,FNV1a64(UTF16LE không NUL của chuỗi),selected,0)`.
- iTime: yêu cầu symbolCHECK,shift1,khôngquá2lần. value=observed lần0,second lần1. Ghi `(1,(uint)frame,1,bars[case.index],value)` trước biến đổi. Sau lần0 ghi frame=after_first_frame và nếuchange_first_bar đặt bars[case.index]=after_first_bar. Trảdatetimevalue.
- Print(string): yêu cầu chính xác `Licence not valid!`. Ghi `(4,FNV1a64(UTF16LE không NUL của chuỗi),0,0,0)`. Không in thật trong dịch vụ giả.
- Bot1ManagePositions: giao diện giống header. Ghi `(buy?2:3,shared.counter,settings.finish.mode,shared.strategy_index,bits(levels[0]))` trước biến đổi. Kiểm symbolCHECK/deviationđúng/danh sáchlevelsđúng. Tăngbuy_calls hoặcsell_calls và không gọi quá1lần mỗi chiều, không yêu cầu buyphải được gọi trước nếu buykhông có vị thế. NếuBUY vàchange_buy: counter++,mode++,shared.strategy_index=(index+1)%8,bars[case.index]+=10. Độc lập, nếuBUY vàshrink_after_buy: live_count=0,selected=-1. Trảbuy_reply/sell_reply. Không gửi lệnh thật, không gọi manager thật.

Mỗi ca gọi router đúng giao diện với strategy_index=case.index đã chụp, cácbiến&/mảng/shared chuẩn. Không đưa shared.strategy_index làm indexôbar. Không tự viết lại thuật toánroutertrongchươngtrìnhkiểm.

Đầu ra mỗi ca128byte `<12i2Q8q>`: id,returned,timeframe,counter,mode,index,events,selected,total_calls,buy_calls,sell_calls,live_count, rồi last_ticket ulong,ordered_hash ulong, rồi8barlong. returned là bool router; index là shared.strategy_index cuối ca. Kết quả lấy trực tiếp các biến sau gọi. Đừng tự tính bool mongđợi/hợp thức hóa sai khác.

Hashchuỗi: mỗi ushortký tựtrả2byte thấp/trước; dùngStringGetCharacter; khôngASCII. Hashlevelsbitsdùnguniondouble/ulong. Nguyênâm trongeventphải kéo dấulongtrướculong, riêngframe theo(uint)theomô tả. Lỗi đầu tiên giữ trongfault, cuối lượtghi trạng thái. SUMMARYnêuđúng chưa biên dịch/đối chiếu. Codex làm bước đó và so với gốc.
