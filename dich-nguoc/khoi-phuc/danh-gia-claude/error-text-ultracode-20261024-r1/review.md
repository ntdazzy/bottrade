## Kết quả đánh giá chuỗi lỗi bot 1/3

**Kết luận:** Không thấy lỗi nào chứng minh được trong `Bot1TradeErrors.mqh` và `Bot3TradeErrors.mqh`. Nhưng cũng chưa có bằng chứng phép so đã chạy và đạt. Trong 9 tệp không có `comparison.json`, `*-run.json`, `baseline.json` hay biên nhận biên dịch. Tài liệu cũng tự ghi "Chưa gọi là kiểm chạy đạt" (`PHAN-TICH-CHUOI-LOI-BOT-1-3.md:16-17`, `:21`).

**Cách làm:** Tôi chỉ đọc 9 tệp và dùng Grep trên chính các tệp đó. Không sửa tệp, không chạy shell, Python hay MT5. Workflow nhiều agent bị chặn với thông báo `Review dynamic workflow before running`, nên chưa có đánh giá của agent khác; chỉ có tôi (Opus 5.5). Tôi không xác minh được mức effort thực tế của lượt này.

Viết tắt: `tool` là `cong-cu/kiem-chuoi-loi-bot-1-3.py`. `.mqh` và `Check.mq5` chỉ cả bản bot 1 lẫn bot 3, vì hai bản giống nhau và cùng số dòng.

### Đã đạt (so với `analysis.json`, chưa so với EX5)
- **92 mã/chuỗi:** Tôi dùng một mẫu Grep gồm 92 cặp mã→chuỗi, mỗi cặp phải khớp nguyên dòng.
  - Khớp đúng 92/92 dòng ở mỗi `.mqh`.
  - Khớp đúng 92/92 dòng `map` ở mỗi `analysis.json`; mỗi `map` có đúng 92 khóa.
  - Cả 91 chuỗi trong `literals` đều thuộc tập này. Bot 1 giống bot 3.
  - Không có ký tự ngoài ASCII, tab hay dấu cách thừa. Giữ nguyên `Exit_limit_` (`.mqh:38`) và `array' string` (`:51`).
- **Bộ đếm:** `error_count++` là lệnh đầu tiên (`.mqh:6`), chạy trước `switch`, không đường trả nào bỏ qua. Kiểu `uint` tự quay từ 0xFFFFFFFF về 0.
- **Nhánh mặc định:** `"unknown error "+(string)code`, với `code` là `const int` (`:4`, `:102`), cho số thập phân có dấu.
- RVA trong tài liệu khớp `CFG` (tool `:23`) và `analysis.json:4-6`. Lệnh chạy MT5 tắt giao dịch và DLL (tool `:141`).

### Điểm yếu và giới hạn (không phải lỗi mã)
1. **Chữ số ở nhánh mặc định không được so độc lập — Trung bình.**
   - Chế độ `original` lấy chữ số từ `cast-values.bin`, mà tệp này do chính script MQL5 ghi (`Check.mq5:42`, tool `:92`, `:151-155`).
   - Phía gốc chỉ kiểm 32 bit thấp của RDX bằng mã, `R8==0x52` và số lần gọi (tool `:91`, `:159`).
   - Vậy tiền tố, thứ tự ghép và số lần gọi được so thật. Còn dạng số (thập phân, có dấu, độ rộng) thực chất là MQL5 so với chính MQL5, nên các mã âm chắc chắn "đạt".
   - Giá trị `"signed int32"` (`analysis.json:835`) là hằng viết tay (tool `:49`), không đọc từ mã gốc.
   - Cách kiểm: xác định nghĩa của `0x52` từ chỗ gọi API 46 khác có kiểu đã biết, hoặc biên dịch mẫu `(string)int/uint/long` để xem giá trị R8.
2. **Tập 92 mã đã đủ chưa, chỉ dựa vào regex — Trung bình.**
   - `cases()` tạo 115 mã × 5 bộ đếm × 3 chuỗi cũ = 1.725 ca (tool `:53-58`): 92 mã có chuỗi cố định và 23 mã đi nhánh mặc định.
   - Các mã chưa từng chạy, ví dụ: 11–62, 67–126, 143, 152–3998, 4024–4048, 4068–4097, 4113–4198, 4208–10003.
   - Với các mã đó, kết luận "không còn case nào khác" chỉ dựa vào regex đọc C của Ghidra (cần đúng tên `pMVar3` và nhãn không âm, tool `:32`) cùng hằng 92 (`:45`).
   - Cách kiểm: chạy bản gốc với mọi mã từ -1 đến 4207 (4.209 ca, dưới giới hạn 20.000 ở `Check.mq5:26`), đòi đúng 92 mã không gọi cast. Hoặc chứng minh biên của bảng nhảy trong mã máy.
3. **Thay chuỗi cũ — Thấp/Trung bình.**
   - Phía MQL5, `old_kind` không có tác dụng: `text` được gán ở `Check.mq5:39-41` rồi bị ghi đè ở `:43`.
   - Chỉ phía gốc thử 3 trạng thái ô: rỗng, `"old text"` và một chuỗi đã cấp phát (tool `:102-107`).
   - Chưa thử: ô đang giữ đúng literal sắp ghi, các dạng ô khác, lỗi cấp phát, và các mã chưa chạy ở mục 2.
   - Dòng mô tả phạm vi ở tool `:165` dễ khiến người đọc tưởng đã kiểm cả phía MQL5.
   - Khi ghép EA: bản gốc ghi vào ô dùng chung `0x6a43c/0x1d6e3c`, còn MQL5 chỉ trả chuỗi. Cần dò mọi chỗ gọi và mọi chỗ đọc lại ô này.
4. **Thứ tự "tăng trước `switch`" không quan sát được — Thấp.**
   - Phép so chỉ so giá trị cuối của bộ đếm (tool `:114`, `:164`). Việc quay về 0 có được thử, với giá trị `0xffffffff` (`:57`).
   - Thứ tự tăng chỉ lộ ra khi có đường lỗi, mà đường lỗi chưa được kiểm.
   - Kiểu không dấu của bộ đếm chỉ có ý nghĩa ở nơi đọc nó; phần này chưa ghép vào EA.
5. **Chuỗi bằng chứng biên dịch/kết quả — Thấp/Trung bình.**
   - Chế độ `compare` (tool `:164-166`) không so băm với `mql5-run.json` và `original-run.json`. Nó cũng không kiểm lại nguồn, EX5 đã biên dịch hay biên nhận.
   - Trong tệp này không có chặn ghi đè `comparison.json`, khác với `:138` và `:150`.
   - Sau khi chạy, băm EX5 chỉ được ghi lại (`:147`), không so lại với biên nhận.
   - Tool chỉ xem mã thoát của terminal (`:143-145`), không đọc mã trả 1–6 của `OnStart`. Lỗi script chỉ lộ gián tiếp qua thư mục mới và bước đọc tệp (`:139`, `:146`, `:148`).
   - `#include <bot-cua-toi-N/…>` lấy tệp trong `MQL5/Include` của terminal, còn băm lại kiểm bản trong `source/MQL5` (`:136-137`). Hai bản có trùng nhau không thì 9 tệp này không cho biết.
   - `read_text()` không chỉ định bảng mã (`:30`, `:82`, `:123`, `:130`). `c_body_sha256` băm chuỗi đã mã hóa lại, không phải byte gốc (`:48`).
   - Cách sửa: cho `compare` so băm với hai tệp `*-run.json` và biên nhận, so lại băm EX5 sau khi chạy, cho script ghi một tệp trạng thái có mã trả, và chặn ghi đè `comparison.json`.

### Giới hạn chung
- Tôi không đọc được C của Ghidra, bản chụp bộ nhớ và `kiem-gui-lenh-bot-1-3.py` (nơi chứa `send.Original`, `supply`, `write_guard`, `Reader`, `pack_text`, `save`). Vì vậy chưa xác minh được bộ giả lập, việc chặn ghi ra ngoài bộ đếm và cách đọc literal.
- Kể cả khi đủ 1.725 ca đều đạt, đó chỉ là một hàm, 115 mã, cấp phát luôn thành công và chưa ghép vào EA. Không được coi là toàn bộ bot đạt 100%.

Nếu muốn có thêm đánh giá độc lập từ nhiều agent, bạn có thể duyệt workflow rồi yêu cầu chạy lại.