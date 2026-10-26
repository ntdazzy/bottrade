# Cho phép kiểm riêng ca phát lỗi của khối chuẩn bị bot3

Viết bản đầy đủ `Bot3PreparationCheck.mq5` và SUMMARY.md vào CHÍNH thư mục này.
Đọc Script hiện hành source/MQL5/Scripts/bot-cua-toi-3/Bot3PreparationCheck.mq5.
Không đọc EX5/mã máy/phân tích; không sửa nguồn chính, Git/MT5, chạy lệnh
hoặc tạo tác tử. Opus5.5max, ultracode được yêu cầu. Codex kiểm riêng.

Hiện Script chạy nhiều ca chuẩn bị thành công. Cần giữ cả cách chạy đó
và thêm khả năng chọn đúng một ca để quan sát lỗi chia0/chỉ mục thật.
Không bắt lỗi runtime, không đổi hàm chuẩn bị, dữ liệu, công thức hoặc
các dịch vụ giả; không tự tính kết quả mong đợi.

Sửa tối thiểu:

1. Thêm `input int OnlyCase=-1;` sau CheckRun. -1 nghĩa chạy đủ như hiện
   hành. Sau kiểm đầu tệp/count/size, nếu OnlyCase<-1 hoặc OnlyCase>=count
   thì đóngsource vàreturn12, không tạooutput.
2. Tính selected_count=OnlyCase<0 ? count : 1. Đầu ra trườngcount dùng
   selected_count; các trườngmagic/version/fields76 giữ nguyên.
3. Mỗi vòng vẫn đọc đầy đủ một ca và kiểmid==i TRƯỚC khi chọn/bỏqua. Nếu
   OnlyCase>=0 và i!=OnlyCase thì continue. Khôngbreaksaucađượcchọn để
   đọcđếncuốitệp khi hàm trảvề bìnhthường.
4. Với ca đượcchọn, trước PrepRunCase: `Print("PREPARATION_CASE:",i);`
   và FileFlush(output). Print này ở vùng sauundef nhưScript hiện tại.
   Không gọi thêmdịchvụthịtrường hoặc sửa counters.
5. PrepRunCase, success,76outputwords, bools và dịchvụgiả giữ nguyên.
   Nếu lỗi runtime xảyra trong Bot3PrepareStrategy, khôngbắt lỗi,
   khôngghi record/success/status giảđểhoàntất. Outputđầu16byte phảiđược
   flushtrướccallđểCodexkiểmkhôngcóbảnghi khi lỗi.
6. script-status.bin cuối chỉ xuất khi đãđiđếncuối bìnhthường, countdùng
   selected_count. CheckFileTell vẫn sau đọc tất cảca. Không ghiđèđầura.
7. Khôngđổidạngbản ghi:id vẫn i tronginput, khôngđánhlạitheoOnlyCase.
   Lượtchọncase7 sẽghiid7nếuthànhcông, khôngid0. BộchạygốccủaCodex
   hiểuviệcđó.

Đây chỉ sửa khả năng chọnca; không thay đổi bất kỳlogic mã cầnphục hồi.
SUMMARY ghi rõ chưabiêndịch/chạy/đối chiếu; lỗiđượckiểmtheoloại lỗi và
khôngtrảvềbìnhthường, chưađủso mọi trạngtháitrướclỗi hoặc toànEA.
