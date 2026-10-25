Read AGENTS.md. Bối cảnh: khôi phục nguồn độc lập bot 3 của chủ dự án. Viết bộ so đoạn mã MQL5 với lệnh gốc đã chụp; không gửi lệnh thật. Codex đã đọc và chốt công thức tại:
bot-cua-toi-3/phan-tich/dong-vi-the/management-virtual-20261025-r1/contract.md (dưới dich-nguoc/khoi-phuc).
Ba Claude khác đang viết phần A/B/C; không viết lại phần nguồn giao dịch, không đổi công thức. Codex sẽ ghép ba hàm vào Include/bot-cua-toi-3/Bot3ManagementVirtual.mqh, include Bot3ManagementPrelude.mqh.

Chỉ ghi trong dich-nguoc/khoi-phuc/claude-thuc-hien/bot3-management-virtual-check-20261025-r1/:
1. Bot3ManagementVirtualCheck.mq5
2. check-management-virtual.py
3. SUMMARY.md
Không chạy shell/MT5, không sửa thư mục nguồn chính hoặc bằng chứng cũ.

Mục tiêu cụ thể: tái dùng cách làm/tests check-management-virtual-start.py và Bot1ManagementVirtualStartCheck.mq5 của bot 1; chỉ stage1/2/3, không stage0. Theo đúng 3 hàm/signature trong contract mới bot3. Mỗi phần gồm cả mua/bán, dữ liệu đổi sau API, sát ngưỡng, NaN/vô cực; so tất cả bit đầu ra, cờ và thứ tự/đối số lời gọi, không tự dùng nguồn mới tạo kết quả mong đợi. Bộ ghi protocol có thể giữ bố cục B1 (<14i3q20d; output <iii6QiQ), chỉ đổi MAGIC sang 0x4d565333, đầu vào initial bằng VLevel. Có thể import case-generator của bộ B1 và lọc stage>0, ghi hash dependency; hoặc chép và mở rộng rõ ràng. Phải đủ stage1/2/3, cả2chiều. Tránh ghi cases.json NaN không hợp lệ với parser nghiêm nếu không cần; công cụ cũ hiện dùng Pythonjson.

Mode prepare|original|mql5|compare RUN [--build BUILD].
HOME là bot-cua-toi-3; ROOT recovery. MT5 chỉ ../.local/mt5-bot3-thread-20261025.
Lưu lần mới tại bot3/bang-chung/kiem-quan-ly-vi-the/RUN. Chuẩn bị đóng băng nguồn/test; kiểm SHA trước mỗi bước; không ghi đè tệp cũ.
Native helper engine dùng entry.Original(3) từ cong-cu/kiem-gia-vao-bot-1-3.py. Khởi tạo sys.path tới ROOT.parent/.local/claude-recovery-20261023/python như bộ cũ.
Bản gốc phải kiểm SHA trong contract và toàn bytes hai thân hàm với management-20261025-r1/analysis.json.
Địa chỉ dưới đây là RVA (đã trừ 0x17156250000):
- Stage1 mua start35f8f, stop35fd3 hoặc367f4; đường thân3667f do nhánh dẫn đến. Bán start3a21a, stop3a2f7.
- Stage2 mua start35fd3 stop36189; bán start3a2f7 stop3a4af; thoát đóng qua helper47d20 (chặn tại helper, đánh dấu closed rồi dừng; không chạy helper trong bộ này).
- Stage3 mua start364e2, stop36667/3672c/36736/36813; bán start3a803 stop3a97d. Stop36667 trước nhánh sang chức năng tiếp theo, giá đã ghi tại36663.
Native setup: rsp là sp sau prologue, có thể chọn 0x50020000-0x108; xmm11=+0.0, xmm6=open,xmm7=tp,xmm13=volume,xmm15=anchor/reference,r12b=changed.
rsi=engine context từ class hoặc dùng 0 vì API được cấp giả lập; rdi=base+74958 symbol descriptor.
r13=base+1d6e48 mua; r14=base+1d6e48 bán; B3 scratch double ở1d6e48.
opened stack mua+60/bán+70; anchor mua+78/bán+88; flagdistance DWORD mua+5c/bán+54; ticket ulong mua+40/bán+48.
Setting/global/P/B/A đúng trong contract. Unit73dd8; P6d670; symbol74958.
Volume table73ac0+8*index; strategy_index74934.
SDK TimeCurrent offset engine+7d1c40 => event9; SymbolInfoDouble engine+7c2890 => event4; Print dispatcher engine+7b49f0 => event10. Các số event/wordhash giữ như bộ B1.
Close guard47d20 => event8, ticket từ RCX, supplied boundary; không thay bằng direct close2e370.
Print text đọc descriptor theo SDK args (stack+20 có descriptor12bytes, +4 pointer, pointer-4 uintlengthUTF16), hoặc xác thực đúng2descriptor5e1f0/5e3c0 bằng bytes bản chụp. Không in bản ghi có data nhạy cảm.
Reset mutable regions/registers/counters mỗi case; không để cờ từ case trước.
Scenario biến động dùng các quy tắc VChanged của Script B1 (Time/POINT/Print có thể +1.25 vào P/B/A); giữ cặp native và MQL5 cùng dữ liệu. Trước và sau API đọc đúng theo contract. Báo first_failures để Codex sửa nếu cần; không nới sai số.

MQL5 mode kiểm build receipt bot3 sạch0/0, đúng target, đúng toàn sourcehash và binaryhash, chạy terminal private hidden (CREATE_NO_WINDOW) với AllowLiveTrading=0, DLL0, Script, ShutdownTerminal=1; đóng băng output và script-status. Mỗi bước không được ghi đè bằng chứng. Báo whole_bot_complete=false/slice_only=true/helper_children_intercepted=true. Chưa có EA; không gọi bộ này là chạy hai bot đầy đủ.

Bạn có thể đọc mã lệnh trong analysis.json để xác nhận ranh giới/setup bộ kiểm, không diễn giải thuật toán khác hay thay contract. Nếu thiếu chi tiết, ghi rõ trong SUMMARY; giao tệp thật hoàn chỉnh, không chỉ mã trong trả lời.

