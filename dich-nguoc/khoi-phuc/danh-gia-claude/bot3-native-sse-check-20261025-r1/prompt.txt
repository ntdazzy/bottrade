Read AGENTS.md. Bối cảnh: kiểm độc lập phần đầu bot3 trong dự án khôi phục của chủ bot. Chỉ sửa bộ kiểm trong thư mục đề xuất được giao; không sửa mã giao dịch, kỳ vọng, ca kiểm, EX5 hoặc bằng chứng cũ.

Codex đã đo nguyên nhân:
bot-cua-toi-3/bang-chung/kiem-quan-ly-vi-the/cpu-nan-20261025-r1/probe.json
và tests/check-nan-cpu.py (dưới dich-nguoc/khoi-phuc).
Cùng bytes SSE2 standalone,363 tổ hợp, CPU Windows và Unicorn lệch24tổ hợp 2NaN khác mẫu bit. Vì vậy phép so prefix636ca (10lệch) chưa phân biệt được lỗi Unicorn với lỗi mã MQL5. Không được sửa MQL5 dựa trên Unicorn chưa hiệu chỉnh.

Đã chép file check-management-prelude.py hiện hành vào thư mục đề xuất này để bạn Edit (không cần viết lại toàn31KB).
Giao:
- check-management-prelude.py đã sửa
- SUMMARY.md mô tả thay đổi/giới hạn
Chỉ ghi dich-nguoc/khoi-phuc/claude-thuc-hien/bot3-native-sse-check-20261025-r1/.
Không Bash/PowerShell, không chạy máy thật; Codex tự chạy sau kiểm.

Mô tả đã chốt:
1. Giữ nguyên tất cả636ca, cáchpack/hash, nguồn MQL5,8NAMES và bộ so từng bit. Giữ kiểm SHA toàn byte gốc.
2. Thêm helper CPU fixture nội bộ (có thể là class) dùng ctypes trên Windowsx64. Dùng đúng opcode và VirtualAlloc RW -> VirtualProtect RX -> FlushInstructionCache -> WINFUNCTYPE(c_uint64, ptruint64, ptruint64) -> VirtualFree như check-nan-cpu.py. Chỉ dùng 3phép mul/add/sub. Lưu/khôi phục MXCSR theo mẫu; dùng0x1f80, không thay máy/hệ thống/tệp EX5. Không hàm rỗng hoặc điều kiện đoán.
3. Trước lượt original, kiểm lại 363 rows trong probe.json với CPU fixture (giữCPUbits từngrow). Kiểm SHA probe trong identity; lưu opcode/probehash và số lần dùng fixture trong original-run.
4. Chỉ sửa hành vi emulation ở ĐÚNG8lệnh gốc dưới đây khi CẢ HAI toán hạng là NaN. Nhận NaN bằngbits: exponent=0x7ff && mantissa!=0. Không lọc/bỏ ca nào.
RVA -> operation,destination,source:
335a9 mul xmm0, qword[rcx]
335ad sub xmm8, xmm0
3367d mul xmm7, qword[rcx]
33681 add xmm7, xmm6
37be5 mul xmm8, qword[rcx]
37bea add xmm8, xmm6
37cbe mul xmm0, qword[rcx]
37cc2 sub xmm7, xmm0
Đã đối chiếu trực tiếp analysis.json và hàm gốc. Xác thực bytes/mnemonic/operands ở8vịtrí trước khi hook.
Trong UC_HOOK_CODE, trước lệnh: nếu2NaN thì gọi đúng CPU fixture lấy kết quảbits, giữ64bittrêncủaXMMđích, ghi64bitdưới vàRIP=address+size để không bịUnicornghiđè. Không đổi bytes gốc, EFLAGS hoặc thanh ghi khác. Giữ đúngcoveragevàboundariescũ. Không có nhánh gốc đọc MXCSR trong đoạn đã chụp; chỉ đối chiếu giá trị công khai và trace. Nếu chỉ1NaN/khôngNaN thì để nguyên Unicorn.
5. Native6global cases/no-sourcechanges vẫn nhưcũ. Không dùngMQL5 đểtạoexpected. Không hardcodepayload từMQL hoặc thayNaNthành0.
6. CPUfixturelifetime phải đượcgiảiphóng trongfinally cảkhilỗi. Không leaktrangmãthực thi. Chỉkhởitạokhioriginalmode cần; prepare/mql5/comparekhôngthực thi mãmáy nhỏ.
7. Cập nhật docstring,SCOPE/LIMITS/reportnêurõ: lệnhgốckhôngđổibytes; támvịtríarithmetickhi2NaNđượctínhtrực tiếptrênCPUđểkhắcphụcsailệchUnicorn; chưa phảiEA. Ghi sốinstructionsđãdelegate chứkhôngnóitoànbộoriginalchạyvật lý.
8. Snapshotcũprelude-20261025-r1giữnguyên. Codex chạy runmới prelude-cpu-20261025-r1. CóthểvẫncònlệchMQL5saukhioracleđúng; báođúngchứkhôngváđểxanh.

Đọc cácfilechỉđịnhtheođườngdẫnnóitrên, đừngđọcfullcode/inventorykhác. TASKnàygiaoviếtmãsửa bộkiểmđúngspec, khôngphảichỉreview.

