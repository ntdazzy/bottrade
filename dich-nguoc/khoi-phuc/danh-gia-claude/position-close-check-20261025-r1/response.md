Tôi tìm thấy **1 lỗi đã chứng minh**. Lỗi này làm dừng toàn bộ bước `original` và `compare` của cả hai bot, nhưng không tạo kết quả "đạt" giả. Các phần còn lại khớp; vài chỗ chỉ là giới hạn bằng chứng.

## 1. Lỗi đã chứng minh: sai mã thuộc tính khớp lệnh

`cong-cu/kiem-dong-vi-the-bot-1-3.py:173-175`: `validate_inputs` coi hai thuộc tính khớp lệnh là 17/18. Giá trị thật là 33 (`SYMBOL_TRADE_EXEMODE`) và 50 (`SYMBOL_FILLING_MODE`).

- Phía MQL5 ghi đúng `(int)property` (`Bot1PipelineApi.mqh:91`, Bot3 cùng dòng) cho hai lời gọi ở `Bot1Filling.mqh:23,25`.
- Các công cụ khác đều dùng 33/50: `kiem-kieu-khop-lenh-bot-1-3.py:114`, `kiem-tao-yeu-cau-cho-bot-1-3.py:112-117`, `kiem-chuoi-dat-lenh-bot-1-3.py:177-178`.
- Phía chạy mã gốc của chính công cụ này (dòng 270) so thanh ghi với cùng số trong fixture, nên chỉ bộ kiểm đầu vào sai.

**Ví dụ kiểm độc lập:** ca 20 (mode 0, stopped=0, select_ok=[1,1,1], ticket=0). Bản ghi api 9 đầu tiên là `(33,'XAUUSD',0)`. Dòng 174 chọn nhầm khóa `filling`, rồi dòng 175 báo `FILLING_INPUT_DIFFERS`.
- Bản tối giản: `validate_inputs(rows[20], [(9,(33,'XAUUSD',0))])` báo lỗi, còn `(9,(17,'XAUUSD',0))` lại qua.

**Đã xảy ra thật:** `close-20261025-r1/failure.json` của bot 1 và bot 3 ghi đúng ca 20 và đúng nguyên nhân này. Tệp hiện tại vẫn còn dòng 175 cũ.

**Hệ quả:**
- Mọi ca đi tới hàm khớp lệnh đều bị chặn ở dòng 341 và 355.
- Bot 1 (r1, r2) và bot 3 (r2) đều ghi `api-fixtures.bin = 5e6c2f9e…`. Vì vậy chạy r2 bằng mã này sẽ dừng lại ở ca 20, hoặc dừng sớm hơn ở dòng 321 nếu băm tệp khác `28b5f732…`.
- Cách sửa: ánh xạ 33 → `executions`, 50 → `fillings`. Sau khi sửa phải `prepare` một lượt mới, vì băm công cụ bị ghim ở dòng 319/321.

## 2. Cần kiểm thêm (chưa chứng minh)

Nội dung tệp hiện tại trùng từng dòng với `close-20261025-r1/tested-sources/native-check-tool.py`. Nhưng r1 ghi `tool_sha256=17de41bd…`, còn r2 ghi `28b5f732…`. Tôi không chạy lệnh nên không băm được tệp hiện tại. Ít nhất một bản ghi không ứng với tệp đang có; cần băm SHA-256 để làm rõ.

## 3. Giới hạn (không phải lỗi đã chứng minh)

- **Chưa tách rõ giá trị cấp, giá trị đo và mã gốc.** Docstring dòng 4-6 chỉ nói "SDK replies are input-bound", và câu này được chép vào `original-run.json`/`comparison.json` (dòng 346, 360).
  - Thực tế, bản ghi fixture 3/5/6/8 là kết quả định dạng đo trong MT5, rồi phát lại cho mã gốc.
  - Event(17) có 3 chuỗi hằng `"1","0","1"` (`Bot1PositionCloseCheck.mq5:157`, Bot3 cùng dòng). Chỉ chuỗi thứ 4 là ép kiểu đo thật, và dòng 147-148 chỉ so với `str()` của Python.
  - Không gây đạt giả, vì bản MQL5 tự ép kiểu (`Bot1TradeMessages.mqh:4-5`) và tham số in vẫn được so.
- **Thiếu nguồn gốc terminal.** `mql5-run.json` (dòng 337) không ghi băm hay bản build của `terminal64.exe` đã chạy phép đo định dạng; biên nhận chỉ có `metaeditor_sha256`.
- **Kiểm `api-contract.json` chỉ một phần.** Dòng 210 chỉ kiểm `POSITION_SL==6`; các hằng khác và địa chỉ SDK (dòng 214) viết cứng. Hiện tại đều khớp, và sai lệch sẽ bị bắt khi chạy.
- **`compare` không kiểm lại đích biên dịch.** Dòng 347-353 không xem lại `receipt['target']` hay danh sách nguồn, mà tin `mql5-run.json` (tệp này không có băm neo bên ngoài).
- **Vùng mã được phép chạy rộng hơn cần.** `self.ranges` thừa kế cả hàm hủy lệnh 0x34150/0x32450 (`kiem-huy-lenh-cho-bot-1-3.py:174`).
- **Độ phủ ca kiểm còn thiếu.**
  - Mode 1 không có ca stopped≠0, symbol NULL, execution≥2, hay hai lần đọc khớp lệnh khác giá trị; `position_magic` luôn là -123.
  - `Print` trong `Bot1Filling.mqh` là `Print` thật, vì tệp này được include trước PipelineApi (dòng 4-6 của script kiểm). Nhánh đó không thể tới vì action=0 sau ZeroMemory.

## 4. Đã đối chiếu, không thấy lỗi

- **Bố cục vào/ra:**
  - Đầu vào: `encode` 73-76 ↔ MQL5 135-152 ↔ `read_cases` 84-96.
  - Trạng thái 260 byte (8+4+120+68+60), 4 chuỗi, 4 cờ null, deviation và 4 biến: `WriteCloseState` 22-34 ↔ `state_block` 102-105 ↔ `state_record` 222-224.
  - Kết quả: MQL5 160-161 ↔ `read_results` 187-196 ↔ dòng 308. Mọi loại fixture khớp, có kiểm byte thừa (dòng 140).
- **Ràng buộc SDK, so với `native-guards.txt`:**
  - select: RDX=ticket (0x22d09).
  - double: đọc kết quả từ ô 0x6a448 (0x23131, 0x3d0cd).
  - string: `xor edx,edx`, rồi đọc ô 0x6a43c (0x22d2a, 0x22d58).
  - SymbolInfoDouble: R8=1/4 (0x230c6).
  - Địa chỉ cấu hình của cả hai bot khớp `semantics.json`.
- **Chụp trạng thái tại biên dịch vụ:** các điểm chụp MQL5 (51, 56, 61, 66, 74, 83, 92, 99, 106) ↔ Python (242, 273, 274) cùng vị trí và thứ tự. Thay đổi có kiểm soát `CloseChange` 36-48 ↔ `change` 227-239 cùng thời điểm.
- **Reset bộ đếm định dạng qua hai lần đóng:** MQL5 dòng 51 và 154-156 ↔ Python 144 và 180. Bộ đếm đọc khớp lệnh không reset theo lần gửi ở cả hai phía, nên nhất quán.
- **Trả về, hoàn tất, bộ nhớ:**
  - Hàm gốc trả về void (0x2318f, 0x3d1e6), nên không so RAX là đúng.
  - Có kiểm RIP, đủ bản ghi, `allocs==frees` và vùng nhớ (300-307); MQL5 có kiểm đọc hết tệp và tệp status (164-166 ↔ 336).
- **Hai lỗi cũ vẫn đã sửa:**
  - `errors/warnings != 0` (325, 348) nên giá trị null bị từ chối.
  - Băm công cụ được ghi và so ở 319, 321, 337, 346, 348, 353.
  - 7 nguồn ở dòng 326 đủ theo các tệp include của cả hai bot.

**Cấu hình lượt này:** tôi tự review trong lượt, không chạy lệnh, không sửa tệp, không dùng agent hay workflow nền (theo yêu cầu, dù ultracode đang bật). Model là `claude-opus-5-5`; tôi không đọc được mức effort thực tế nên không xác nhận là "max".