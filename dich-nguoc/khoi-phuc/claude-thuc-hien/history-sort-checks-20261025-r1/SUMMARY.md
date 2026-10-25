# Bộ kiểm hàm sắp xếp hai mảng bot 1 và 3

## Trạng thái

- Đã viết mã thật cho ba tệp dưới đây. **Chưa biên dịch, chưa chạy**
  Python, MT5 hay mã gốc (lượt này không có công cụ chạy lệnh). Chưa
  có kết quả so; chưa biết mã có lỗi cú pháp/biên dịch hay không.
- Phạm vi chỉ hàm sắp xếp `0x47950` (bot 1) / `0x557f0` (bot 3), ca trả
  bình thường. Mọi báo cáo ghi `whole_bot_complete=false`.
- Đã đọc: `AGENTS.md`, `QUY-TRINH.md`, `PHAN-TICH-SAP-XEP-BOT-1-3.md`,
  TASK, `bien-dich.ps1` và một biên nhận thật, `kiem-sua-vi-the-bot-1-3.py`,
  `kiem-bang-dung-ao-day-du-bot-1.py`, `kiem-gia-vao-bot-1-3.py`,
  `kiem-muc-gia-bot-1-3.py`, `kiem-khoi-luong-hop-le-bot-1-3.py`, hai
  Script kiểm cũ, phần hook của thư viện unicorn 2.1.4 trong `.local`.
  Không mở EX5, mã C, `native.txt`, `analysis.json` hoặc bản chụp.

## Tệp

| Tệp trong thư mục này | Chép vào |
|---|---|
| `Bot1HistorySortCheck.mq5` | `bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/` |
| `Bot3HistorySortCheck.mq5` | `bot-cua-toi-3/source/MQL5/Scripts/bot-cua-toi-3/` |
| `kiem-sap-xep-bot-1-3.py` | `cong-cu/` |

Trước `prepare` phải có header `Include/bot-cua-toi-N/BotNHistorySort.mqh`
(phần Claude khác viết) trong `source/MQL5`, vì SHA header và Script được
ghi ngay từ `prepare`.

## Cách chạy (bot 1; bot 3 đổi số và tên tệp)

```powershell
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-sap-xep-bot-1-3.py prepare 1 history-sort-20261025-r1
& dich-nguoc/khoi-phuc/cong-cu/bien-dich.ps1 -Bot 1 -Terminal 'dich-nguoc/.local/claude-recovery-20261023/mt5' -Run b1-history-sort-01 -Source 'dich-nguoc/khoi-phuc/bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/Bot1HistorySortCheck.mq5'
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-sap-xep-bot-1-3.py mql5 1 history-sort-20261025-r1 --build b1-history-sort-01
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-sap-xep-bot-1-3.py original 1 history-sort-20261025-r1
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-sap-xep-bot-1-3.py compare 1 history-sort-20261025-r1
```

- `original` chỉ cần `prepare`, có thể chạy trước `mql5`.
- Chạy `mql5` ngay sau khi biên dịch: `bien-dich.ps1` xóa rồi chép lại
  thư mục `Scripts/bot-cua-toi-N` của MT5 riêng nên EX5 cũ trong đó mất.
  Hai bot chạy lần lượt vì dùng chung MT5 riêng.
- Tên lượt `[a-z0-9-]{1,40}`, tên bản dựng `[a-z0-9-]{1,48}`. Không ghi
  đè: thư mục lượt, mọi tệp kết quả, thư mục `MQL5/Files`, `.set`, `.ini`
  đều tạo mới. Lượt `mql5` lỗi để lại `mql5-failure.json`; dùng tên lượt mới.

Kết quả ở `bot-cua-toi-N/bang-chung/kiem-sap-xep/NEW_RUN/`: `cases.bin`,
`cases.json`, `baseline.json`, `mql5-results.bin`, `script-status.bin`,
`tested-sources/` (Script, header, `check-tool.py`, bốn công cụ phụ thuộc,
`bien-dich.ps1`), `mql5-run.json`, `original-results.bin`,
`original-run.json`, `comparison.json`.

## Ca thường: 512 mỗi bot (đếm theo mã, chưa chạy `prepare` để xác nhận)

Hạt giống `20261025`. Mỗi bộ dữ liệu chạy đủ bốn tổ hợp cờ đảo
(khóa, đi kèm) = (0,0), (0,1), (1,0), (1,1) với cùng dữ liệu vật lý.

| Nhóm | Ca | Nội dung |
|---|---|---|
| `full-<kiểu>` | 224 | Chiều dài 1/2/3/8/31/64/100/128 × 7 kiểu khóa: ngẫu nhiên 64 bit, quanh 2^63, trùng (có 2^63, 2^64−1), đã tăng, đã giảm, tất cả bằng nhau, xen kẽ 0/2^64−1; left=0, right=n−1 |
| `subrange` | 68 | n=3: (0,1),(1,2); n=8/31/64/100/128: khoảng giữa, khoảng đầu, khoảng cuối |
| `left-equals-right` | 60 | n=1/2/3/8/64/128, vị trí 0, n/2, n−1 |
| `left-above-right` | 132 | n=1/2/8/128: (1,0), (0,−1), (1,−2) (middle=0 do chia cắt về 0), (INT_MAX,INT_MIN), (INT_MAX,INT_MIN+1), các cặp cho middle=n−1 |
| `documented-pilot` | 8 | Hai ca gốc Codex đã đo, × 4 cờ |
| `unequal-lengths` | 20 | Hai mảng khác độ dài, right nhỏ hơn cả hai độ dài |

Mảng đi kèm: các số long khác nhau, có LONG_MIN và LONG_MAX (khi n≥2),
−1, 0, để mọi lần đổi chỗ đều thấy được.

Điều kiện "ca thường" (hàm `in_bounds`, sai thì `prepare` dừng
`CASE_NOT_NORMAL`): left+right và hai biên trong int32; middle (chia cắt
về 0) nằm trong mảng khóa; nếu left≤right thì 0≤left và right nhỏ hơn
độ dài cả hai mảng. Lý do theo mô tả thuật toán (không phải phân tích
EX5): pivot nằm trong [left,right] làm điểm chặn cho hai vòng con, nên
mọi chỉ số đọc/ghi đều trong [left,right]. Không có ca cố ý lỗi.

## Cách so

- Script: nạp mảng với cờ thường (`ArrayFree`, tắt cờ, `ArrayResize`,
  đọc từng phần tử), bật cờ riêng của từng mảng theo ca, gọi
  `BotNHistorySort`. Sau gọi ghi cờ hiện tại và độ dài, lưu cờ, tạm tắt
  cờ, ghi phần tử theo bộ nhớ, rồi trả lại cờ. Không có đáp án trong
  Script. In `BOTN_HISTORY_SORT_CASE:id` trước mỗi ca và
  `BotNHistorySortCheck:mã,số_ca` khi kết thúc. Kiểm `CheckRun` chỉ gồm
  `a-z0-9-` (1–40 ký tự), từ chối ghi đè, kiểm đủ byte trước mỗi lần đọc
  và đọc hết tệp. Mã thoát: 0 đạt; 2 tên lượt sai; 3 kết quả đã có;
  4 không mở được ca; 5 đầu tệp sai; 6 không tạo được kết quả; 7 ca
  sai/cắt cụt; 8 nạp mảng/bật cờ lỗi; 9 ghi/trả cờ lỗi; 10 thừa byte;
  11 không tạo được tệp trạng thái.
- Mã gốc: `entry.Original(bot)` từ `kiem-gia-vao-bot-1-3.py` (tự kiểm hash
  bản chụp và engine). Lớp con chỉ chạy đúng RVA trong bảng; điểm kết
  thúc hàm lấy từ `metadata/import.json` (coi `end_rva` là điểm ngay sau
  hàm, như `kiem-sua-vi-the`). Mỗi ca: chép lại vùng
  `mutable_program_data`, xóa ngăn xếp và vùng dữ liệu
  `0x71000000/0x20000`; khóa ở `0x71000000`, đi kèm ở `0x71010000`;
  mô tả 52 byte = loại `0x800010056`/`0x800010055` OR bit20 khi đảo,
  độ dài +8, con trỏ +28; thanh ghi nguyên và XMM về 0;
  RSP=`0x50020000-0x108` chứa địa chỉ trả `0x60000000`; ECX=left,
  EDX=right; `emu_start(..., timeout=5000000, count=2000000)`. Nhận ca khi
  RIP=`0x60000000` và RSP về đúng +8. Kết quả đọc lại từ mô tả: cờ, độ
  dài, dữ liệu tại con trỏ.
- Chặn chặt, không sửa thân hàm: gọi SDK bất kỳ, chạy ra ngoài
  [RVA, end_rva) trừ địa chỉ trả cuối, hoặc ghi ngoài ngăn xếp/hai mảng
  đều làm lượt `original` dừng với lỗi rõ.
- Hai ca gốc trong `PHAN-TICH-SAP-XEP-BOT-1-3.md` (cờ thường) phải ra
  đúng số đã ghi, nếu không lượt `original` dừng `DOCUMENTED_PILOT_DIFFERS`.
- `compare` so từng ca theo byte: hai mảng vật lý, độ dài, cờ; báo
  trường lệch đầu tiên (`keys[physical i]`, `values.series`, …) và số
  khớp theo nhóm. Mã thoát 1 khi có lệch.
- Ràng buộc SHA ở mọi bước: EX5 gốc (`original_hash`), công cụ, bốn công
  cụ phụ thuộc + `bien-dich.ps1`, bốn tệp phân tích `sort-20261025-r1`,
  `import.json`, `capture.json`, `engine-observed.json` (công cụ chỉ băm),
  Script/header, `cases.bin`/`cases.json` (tạo lại phải giống từng byte).
  Bước `mql5`: biên nhận đúng đích, `errors`/`warnings` phải là `int` 0
  (không nhận bool/null), EX5 trùng ở biên nhận và trong MT5 trước/sau
  chạy, nguồn trong MT5 trùng nguồn đã biên dịch, `metaeditor64.exe`
  trùng biên nhận, `terminal64.exe` trước=sau. `compare` kiểm lại định
  danh, ca, tệp kết quả, `tested-sources`, biên nhận (cả EX5 lưu kèm
  biên nhận) và `terminal64.exe` hiện tại; không kiểm lại bản EX5 đang
  nằm trong MT5.
- MT5 chạy giống các công cụ cũ: `/portable /config`, `Enabled=0`,
  `AllowLiveTrading=0`, `AllowDllImport=0`, chỉ Script kiểm,
  `ShutdownTerminal=1`, `CREATE_NO_WINDOW`, chờ tối đa 120 giây. Cờ này
  chỉ ẩn cửa sổ dòng lệnh; cửa sổ MT5 có thể vẫn hiện. Chưa thêm
  `SW_HIDE` vì chưa có bằng chứng `terminal64.exe` chạy đúng với cờ đó.

## Giới hạn

- Chỉ ca trả bình thường. Lượt thường **không phân biệt được** các luật
  sau vì kết quả cuối giống nhau: đọc pivot trước khi thoát khi
  left>right, không thêm biên vào hai vòng con, đệ quy trái trước vòng
  phải, tự đổi khi i==j và thứ tự ghi keys[i]/keys[j]. Cần ca lỗi hoặc
  rà nguồn để kiểm.
- Ba lớp chặn chặt có thể dừng lượt nếu mã gốc có tác dụng phụ ngoài mô
  tả; khi đó cần Codex phân tích, không được nới chặn để cho qua.
- Độ phủ chỉ ghi danh sách offset đã chạy; chưa đối chiếu với 214 lệnh.
  `captured_descriptors` (52 byte mô tả trong bản chụp) chỉ được ghi lại,
  không bắt buộc bằng `0x800010056`/`0x800010055`.
- Chưa chạy máy đo quá khứ, nơi gọi, dữ liệu lịch sử thật hoặc toàn EA.

## Cần Codex kiểm khi ghép

- Script dùng hai hàm `template<typename T>` (tính năng có trong tài liệu
  MQL5) để nạp/ghi cả `ulong[]` và `long[]`; dự án chưa có tệp nào dùng
  `template`. Nếu MetaEditor báo lỗi/cảnh báo, thay bằng hai bản riêng
  cho `ulong` và `long`, giữ nguyên thứ tự ghi.
- Ba lớp chặn dựa vào unicorn 2.1.4 bản py3: lỗi ném trong hook được giữ
  lại và `emu_start` ném lại sau khi dừng (đã đọc mã thư viện, chưa chạy).
- `end_rva` trong `import.json` được coi là điểm ngay sau hàm.

## Ca lỗi (chưa viết, chưa chạy, chưa có bằng chứng)

| Ca đề xuất | Đầu vào ví dụ |
|---|---|
| Mảng rỗng | n=0, (0,−1) |
| left>right, middle ngoài mảng | n=8, (20,10); n=8, (0,−3) |
| Tràn int32 | (INT_MAX, INT_MAX) |
| left âm | n=8, (−1,3) |
| right ≥ độ dài khóa | n=8, (0,8) |
| Mảng đi kèm ngắn hơn | khóa 8, đi kèm 4, (0,7) — lỗi sau khi đã đổi một phần |
| Mảng khóa ngắn hơn right | khóa 5, đi kèm 8, (0,7) |
| Các ca trên với bốn tổ hợp cờ | |

Cách chạy riêng (đề xuất): mỗi ca một lần mở MT5 như chế độ `faults` của
`kiem-khoi-luong-hop-le-bot-1-3.py`; phía gốc dừng ở lời gọi xử lý lỗi
để đọc hai mảng đã đổi trước lỗi. Câu hỏi mở: phía MQL5 lấy trạng thái
mảng sau lỗi `array out of range` bằng cách nào (ví dụ `OnDeinit` có
chạy sau lỗi nghiêm trọng không) — phải thử trên MT5 riêng. Dòng/cột lỗi
của nguồn mới khác bản gốc, không được gọi là giống.

## Đề xuất thêm vào `cong-cu/BOT-1-3.md` (sau khi chạy thật)

```text
## Sắp xếp hai mảng lịch sử

- `kiem-sap-xep-bot-1-3.py MODE BOT NEW_RUN [--build BUILD]`: `prepare`
  → biên dịch `BotNHistorySortCheck.mq5` → `mql5 --build` → `original`
  → `compare`. 512 ca thường mỗi bot. Mã gốc `0x47950`/`0x557f0` chạy
  nguyên trên hai vùng dữ liệu riêng; so hai mảng vật lý, độ dài, cờ
  đảo. Chưa có ca lỗi, nơi gọi, dữ liệu lịch sử, toàn EA.
```
