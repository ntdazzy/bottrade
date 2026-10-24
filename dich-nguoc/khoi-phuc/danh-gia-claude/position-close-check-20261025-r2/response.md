Trong bản r4 đóng băng, cả 7 phần sửa đều đúng. **Tôi không tìm thấy lỗi nào còn lại đã chứng minh được.** Bằng chứng r4 của cả hai bot ghi khớp 2589/2589 ca (tôi chỉ đọc JSON, không tự tính lại băm). Phần còn lại dưới đây là giới hạn, không phải lỗi.

**Đính chính lượt trước:** câu "tệp hiện tại vẫn còn dòng 175 cũ" là do tôi đọc đường dẫn chuẩn đúng lúc tệp đang được sửa. Bản r4 đã sửa xong. Giải thích trong `parent-review.md` khớp với những gì tôi thấy lúc đó, nhưng tôi chưa tự băm để xác nhận.

## Kết quả từng mục (dòng của `native-check-tool.py` r4)

- **33/50:** đã đúng ở dòng 184-187: 33 ứng với `executions`, 50 ứng với `fillings`, giá trị khác thì báo lỗi.
  - Phần định dạng vẫn dùng 17/33 (dòng 155, 191-196), đúng với lời gọi đọc kiểu tham chiếu.
  - Ví dụ kiểm: với ca 20, bản ghi `(9,(33,'XAUUSD',0))` giờ qua; `(9,(17,'XAUUSD',0))` giờ báo `FILLING_INPUT_DIFFERS`.
- **Chụp kết quả trước khi dọn chuỗi:** thứ tự đúng.
  - Kiểm vùng nhớ (315-321), rồi chụp kết quả (322), rồi gọi hàm hủy chuỗi gốc RVA 0 cho 4 chuỗi tại offset 20/100/292/488 (326-330), cuối cùng mới kiểm cân bằng bộ nhớ (331).
  - Đây đúng là 4 chuỗi mà mã gốc tự giải phóng trong bước ZeroMemory (`native-guards.txt`: 0x22db2, 0x22e04, 0x22eb1, 0x22f5e).
  - Bước dọn không đổi được kết quả đã chụp. Chuỗi rò ở chỗ khác vẫn bị phát hiện.
- **Bản ghi 17:** `Bot1/Bot3PositionCloseCheck.mq5:157` giờ dùng phép đổi kiểu MQL thật: `(int)TRADE_ACTION_DEAL`, `(uint)ORDER_TYPE_BUY/SELL` và `supplied_result.retcode`.
  - Ánh xạ ở dòng 289-295 (0x52 có dấu, 0x53 không dấu) khớp với các hàm đổi kiểu của bản phục hồi (`Bot1TradeMessages.mqh:4-5`).
- **Đích biên dịch và 7 tệp nguồn:** bước `mql5` kiểm ở dòng 348-352; bước `compare` kiểm đúng đích và đúng tập 7 tệp ở dòng 372-374.
  - Các tệp nguồn sản phẩm (6 tệp ngoài script kiểm) có băm trùng r1/r2; chỉ script kiểm thay đổi.
- **Băm terminal:** ghi ở dòng 361, so lại ở dòng 374. r4 của cả hai bot đều ghi `d92c969e…`.
- **12 hằng / 8 địa chỉ lời gọi SDK:** dòng 221-224 khớp đúng `api-contract.json`; địa chỉ móc ở dòng 228 cũng khớp.
- **220 ca mới:** ở dòng 71-78, gồm 12 + 16 + 192 = 220 ca. Tổng 2369 + 220 = 2589, khớp `baseline.json` và `comparison.json` của r4.
  - Mọi chỉ số đọc nằm trong giới hạn: tối đa 3 lần chọn vị thế, 4 lần đọc kiểu, 4 lần đọc SL, 2 lần cho mỗi loại còn lại.

## Giới hạn còn lại (không phải lỗi)

1. **Ba chuỗi đầu của bản ghi 17 là đổi kiểu trên hằng số.** Trình biên dịch có thể tính sẵn, nên chưa chắc đi qua hàm đổi kiểu lúc chạy như mã gốc (api 46).
   - Trong đường đóng vị thế, bản MQL5 chỉ đổi kiểu ở nhánh "unknown" (`Bot1TradeMessages.mqh:15,64,121`). Thực tế chỉ dùng chuỗi "0" và chuỗi retcode, nên rủi ro thấp.
2. **Băm terminal chỉ tính sau khi chạy** (dòng 361) và chỉ cho `terminal64.exe`. Nếu terminal tự cập nhật trong lúc chạy thì sẽ không bị phát hiện. Nếu terminal đổi sau này, `compare` sẽ dừng.
3. **`compare` không đối chiếu từng băm nguồn** trong `mql5-run.json` với `receipt['sources_sha256']` (dòng 374-377). Hai tệp `mql5-run.json` và `original-run.json` cũng không có băm neo bên ngoài. Đây chỉ là giới hạn nếu bằng chứng bị sửa tay.
4. **Kiểm bộ nhớ chỉ đếm số lần cấp/giải phóng**, không theo địa chỉ, và vùng đã giải phóng không bị xóa (`kiem-gia-vao-bot-1-3.py:135-141` — tệp chuẩn, không có bản đóng băng). "Cân bằng" là điều kiện cần, chưa chứng minh không có giải phóng sai hay đọc sau khi giải phóng.
5. **Vùng mã được phép chạy vẫn gồm hàm hủy lệnh thừa kế** từ lớp kiểm cũ (parent-review đã ghi nhận).
6. **Ca mới vẫn còn chỗ chưa phủ:** `fillings=[flags,flags]` nên hai lần đọc cờ khớp lệnh luôn cùng giá trị, và `preferred` không có giá trị 1 (IOC). Số lần đọc vẫn được so, nên lỗi bỏ sót một lần đọc vẫn bị bắt.
7. **Phạm vi:** 2589 ca chạy với phản hồi giao dịch/truy vấn được cấp và định dạng đo trong MT5. Kết quả này không chứng minh toàn bộ EA, phía nhà môi giới hay lỗi cấp phát bộ nhớ; `whole_bot_complete=false` là đúng.

**Cấu hình lượt này:** chỉ đọc tệp, không chạy lệnh, không sửa, không dùng agent hay workflow. Tôi không quan sát được mức effort thực tế, nên không xác nhận "max" — kể cả mức mà parent-review ghi.