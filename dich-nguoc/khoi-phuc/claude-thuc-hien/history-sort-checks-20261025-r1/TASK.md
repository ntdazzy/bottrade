# Viết bộ kiểm hàm sắp xếp hai mảng bot 1 và 3

Đây là dự án khôi phục nguồn bot giao dịch của người dùng. Codex đã
phân tích hàm phụ sắp xếp và chạy ca gốc, hai Claude khác đang viết
hai header theo mô tả. Bạn viết bộ kiểm theo mô tả đã chốt, không
tự phân tích EX5, không sửa khóa/giới hạn, không giao dịch. Codex sẽ
tự chạy biên dịch, kiểm lệnh gốc và nguồn mới. Không đọc EX5/C/capture.

Đọc AGENTS.md và `dich-nguoc/khoi-phuc/PHAN-TICH-SAP-XEP-BOT-1-3.md`.
Chỉ ghi trong thư mục TASK này; chỉ Read/Grep/Glob/Edit/Write,
không lệnh/MT5/kỹ năng lồng nhau. Viết mã thật, không chỉ hướng dẫn:

- `Bot1HistorySortCheck.mq5`, `Bot3HistorySortCheck.mq5` để chép vào
  Scripts/bot-cua-toi-N. Include chuẩn `<bot-cua-toi-N/BotNHistorySort.mqh>`.
- `kiem-sap-xep-bot-1-3.py` để chép vào cong-cu.
- `SUMMARY.md`: cách dùng, giới hạn, tên tệp. Chưa chạy thì nói chưa chạy.

## Đầu vào/đầu ra chung

Python nhận `prepare|mql5|original|compare BOT NEW_RUN [--build BUILD]`,
BOT chỉ 1/3, tên lượt `[a-z0-9-]{1,40}`, không ghi đè. Thư mục kết quả
`bot-cua-toi-N/bang-chung/kiem-sap-xep/NEW_RUN`; giữ cases.json/bin,
tested-sources (header, Script, công cụ hiện hành và phụ thuộc),
baseline/mql5-run/original-run/comparison.json và hai tệp kết quả.
Ràng buộc SHA nguồn, công cụ, ca kiểm, biên nhận, EX5 biên dịch và
program MT5. Kiểm errors/warnings đúng kiểu int=0, không nhận bool.
Mỗi ca so chính xác hai mảng vật lý, kích thước, cờ thường/đảo; đọc
hết tệp, không nhận dữ liệu thừa/cắt cụt. Đáp án là mã gốc chạy, không
phải tự tính bằng thuật toán Python hay ArraySort.

Để trước hết hoàn thành phần ca trả bình thường, sinh khoảng 300–600
ca cố định hạt giống, gồm unsigned >2^63, LONG_MIN/MAX đi kèm, trùng,
đã tăng/giảm, các chiều dài 1/2/3/8/31/64/100/128, khoảng con và bốn
tổ hợp cờ đảo. Cho cả left==right và left>right mà middle hợp lệ;
không đưa ca cố ý lỗi vào lượt thường. Danh sách ca lỗi và cách chạy
riêng có thể ghi SUMMARY, chưa có bằng chứng thì không báo đã kiểm.
Không thêm quá nhiều lớp trừu tượng hoặc bộ khung chung.

Script có `input string CheckRun`, đọc `botN-history-sort/CheckRun/cases.bin`,
ghi `mql5-results.bin` và `script-status.bin`, in nhãn kết quả. Chuỗi
CheckRun chỉ tên lượt. Không kiểm từng ca bằng kỳ vọng tự nghĩ.
Để ghi mảng vật lý: nạp với cờ thường, bật cờ theo ca trước gọi; sau
gọi ghi cờ hiện tại, lưu và tạm tắt cờ rồi ghi phần tử theo bộ nhớ.
Giữ hai mảng độc lập. Không macro thay hàm sắp xếp.

## Tái dùng nền có sẵn

Đọc mô tả/biên nhận của `cong-cu/bien-dich.ps1` và phần prepare/mql5
trong `cong-cu/kiem-sua-vi-the-bot-1-3.py` hoặc
`kiem-bang-dung-ao-day-du-bot-1.py` để giữ kiểu chạy MT5 riêng.
Máy thử cho bộ kiểm này là `.local/claude-recovery-20261023/mt5`
(ROOT.parent/'.local/claude-recovery-20261023/mt5'). Codex điều phối
dùng riêng, không dùng máy thử hai chat bot1/bot3. Chỉ script kiểm,
giao dịch/DLL tắt, ShutdownTerminal=1, gọi tiến trình ẩn trên Windows.
Không chạy lệnh trong lúc viết.

Chạy gốc dùng mô-đun đã có `cong-cu/kiem-gia-vao-bot-1-3.py` bằng
importlib. `entry.Original(bot)` có m,memory, x (hằng thanh ghi), uc,
base, regions; code gốc đã nạp đúng hash. Dùng
`kiem-khoi-luong-hop-le-bot-1-3.py` với `original_hash(bot)` để kiểm gốc.
Không sửa hai công cụ này. Chỉ chạy đúng RVA được giao:

| bot | hàm | mô tả khóa | mô tả long |
|---|---|---|---|
| 1 | 0x47950 | 0x6a2a0 | 0x6a2e0 |
| 3 | 0x557f0 | 0x772e0 | 0x77320 |

Các mô tả mảng gồm 52 byte: uint64 loại ban đầu lần lượt
0x800010056 / 0x800010055; cờ đảo là bit20 của uint64 đó; length int32
tại+8, con trỏ uint64 tại+28. Dữ liệu khóa là ulong64 và dữ liệu
đi kèm long64, mỗi phần tử 8 byte. Cấp hai vùng riêng trong bộ mô
phỏng, ví dụ 0x71000000 và0x71010000 sau mem_map(0x71000000,0x20000).
Chép lại regions có kind mutable_program_data trước mỗi ca;
khởi tạo các thanh ghi nguyên và XMM về0. RSP=0x50020000-0x108,
ghi địa chỉ trả 0x60000000 vào ô RSP; ECX=left,EDX=right (32 bit).
Chạy `emu_start(base+rva,0x60000000,timeout=5000000,count=2000000)`,
bắt buộc RIP==0x60000000 mới nhận ca thường. Ghi hai vùng dữ liệu
vật lý, độ dài và cờ hiện tại. Không chặn/sửa thân hàm hoặc tự thay
kết quả. Không lệnh SDK nào trong đường thường ngoài tự gọi đệ quy.

Phạm vi chỉ hàm sắp xếp; chưa chốt mọi dữ liệu lịch sử/caller hay
toàn EA. `whole_bot_complete` phải false trong các báo cáo. Nếu cần
mở tệp/hiểu mẫu hãy đọc source mới và biên nhận, không EX5/C/capture.
