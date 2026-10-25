Viết DUY NHẤT Bot1ManagementRealBlocksCheck.mq5, real_blocks_cases.py và SUMMARY.md vào CHÍNH thư mục dich-nguoc/khoi-phuc/claude-thuc-hien/bot1-real-six-check-20261026-r1/. Đây là nơi ghi duy nhất, không ghi sang thư mục có trong tài liệu tham khảo. Nếu công cụ ghi bị từ chối, trả đủ mã qua các khối mã trong câu trả lời; Codex lưu lại. Không sửa nguồn chính/Git/MT5, không chạy lệnh hay tạo tác tử, không đọc EX5/mã máy/phân tích. Opus5.5max,Ultracodeđược yêu cầu. Chỉ viết bộ cấp đầu vào/ghi kết quả, không tự tính đáp án.

Nguồn tham khảo được đọc (bắt đầu dich-nguoc/khoi-phuc/):
- bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/Bot1ManagementRealBlocksCheck.mq5 và bot-cua-toi-1/tests/real_blocks_cases.py: phiên bản3khối đã chạy và so.
- claude-thuc-hien/bot1-real-three-check-20261026-r1/TASK.md: giao diện dữ liệu/dịch vụ. Chỉ tham khảo giao diện, KHÔNG thay thư mục ghi theo tài liệu này.
- bot-cua-toi-3/source/MQL5/Scripts/bot-cua-toi-3/Bot3ManagementRealBlocksCheck.mq5: mẫu gọi6khối và biến toàn cục. Chỉ dùng mẫu cấu trúc, giữ các khác biệt Bot1 dưới đây.
- Các header Bot1 hiện hành để đúng tên/kiểu/giao diện. Chức năng3headermới đã có; không viết lại hoặc giả thay chúng.

Thay đổi cần làm, giới hạn rõ:
1.Giữ đầy đủ giao diện Bot1 hiện hành: magic0x4d524231,version1,input440byte `<22iqQII41d`,output384byte `<5iIIQ41diQQ`,mảngvolumes/levels8,index0..7,Mutate%8,bảngrows500x3,băm1500ô,khôngtake_rows. Giữhàmdịchvụgiả/FNV/khôngghiđè/tênrun/mãlỗi/thứtựinclude. Chỉ mở stage từ0/1/5 thành0..5.
2.Khôi phục biến toàn cục cho gap_count,minimum_steps,before_openuchar,shift_settinguchar,step_enableduchar; đọc từ đúng các ô có sẵn trong22int, không thêmtrường. Chúngphảiđượctruyềnthamchiếuđúngkiểu choheader. Mutate khôngđổi các biến này, giữnguyên danhsách/thứtựmutator hiện có. Counter là cùng biến toàn cục đangđượcMutateghi.
3.Include Bot1ManagementRealHighLow.mqh,Bot1ManagementRealLock.mqh,Bot1ManagementRealCounter.mqh SAU cácmacrogiả và Messages như3headercũ. Không nạp chúng trướcmacro. Header mớiđượcRootghépvàbiêndịch0/0; các thân lỗi thậtphảichạy trênGetLastError/Printgiả,khôngtạohàmlỗi thaythế.
4.Giữ stage0,1,5 cách gọi hiện có. Thêm stage2highlow: gọivoid Bot1AdvanceHighLowRealBuyStop/SellStop("CHECK",enabled,(uchar)eligible_flag,gap_count,unit,before_open,shift_setting,gap,freeze,levels,index,position,tick,changed,state,options,error_count,ticket) theo18đối số.
5.stage3lock: voidBot1AdvanceRealLockBuyStop/SellStop("CHECK",lock_start,lock_extra,unit,gap,freeze,position,tick,changed,state,options,error_count,ticket) theo13đốisố.
6.stage4counter: voidBot1AdvanceRealCounterBuyStop/SellStop("CHECK",step_enabled,step_reference,minimum_steps,step_distance,unit,copied_step,anchor,gap,freeze,counter,position,tick,changed,state,options,ticket) theo17đốisố. stage2/3/4returned=false,khôngsuytừchanged. Khôngtựbỏquastagekhichangedtrue (headercountertựxửlýđúngtrình tự).
7.FactoryPython chỉđổiSTAGESthành(0,1,2,3,4,5),cácchúthíchliênquan; dùngmọicaB3theothứtựcũ,deepcopy,source_case_id,idliêntục,arrayscắt8,index%8,encodegiữnguyênđịnhdạng/kiểmgiátrị. Khôngthêmngẫunhiên,kếtquảmongđợihoặcsửacaseB3. TệpCanonBot1hiệnhànhđủmãđểđọcvàdùnglại; khôngcầntìmtoànrepo.
8.Mọiinput/output chưađượcstageđọcvẫntrảđầyđủnhưtrước. Khôngdọn/reformatphầnkhôngcầnsửa. KhôngTODO/hàmrỗng/khunghệthống/logicbotmới. SUMMARYnóirõchưabiêndịch/chạy nếu chưa; Codexsẽkiểm/ghépvàsođộclập.
