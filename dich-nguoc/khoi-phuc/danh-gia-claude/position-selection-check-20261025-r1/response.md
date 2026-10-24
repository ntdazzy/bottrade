# Review bộ so sánh và mã MQL5 chọn vị thế (position-selection r1, bot1 và bot3)

**Kết luận**
- **Mã MQL5:** `Bot1/3PositionSelection.mqh` khớp ngữ nghĩa mã máy ở mọi điểm tôi kiểm. Không thấy lỗi.
- **Bộ so sánh r1:** chặt. Nó so thứ tự và đối số của mọi lời gọi API, so toàn bộ trạng thái ở mỗi ranh giới API và lúc vào/ra guard. Nó chạy trọn chuỗi guard → close → filling → send của bản gốc và kiểm cân bằng bộ nhớ.
- **Lỗi:** có 2 lỗi chứng minh được, đều nằm ở bộ kiểm, không nằm ở mã MQL5.
- **Biên nhận:** `comparison.json` của cả hai bot xuất hiện trong lúc tôi review (lần Glob đầu chưa có). Cả hai ghi `matched 4598, failed 0`. Tôi không tự tính lại hash. Kết quả này chỉ chứng minh bộ ca r1, không chứng minh toàn EA.

**Viết tắt** (bot3 có cấu trúc trùng dòng):
- NC = `bot-cua-toi-1/bang-chung/kiem-chon-vi-the-dong/position-selection-20261025-r1/tested-sources/native-check-tool.py`
- MQ = `Bot1PositionSelectionCheck.mq5` cùng thư mục; SEL = `Bot1PositionSelection.mqh`
- CLOSE = `cong-cu/kiem-dong-vi-the-bot-1-3.py`; SEND = `cong-cu/kiem-gui-lenh-bot-1-3.py`; CANON = `cong-cu/kiem-chon-vi-the-dong-bot-1-3.py`

## 1. Lỗi chứng minh được

**L1 – Kịch bản 5 (đổi seed và symbol sau khi guard trả về) không kiểm được gì**
- NC:56-57 đặt `11/'XAUUSD'` ở chỉ số 0 và `12/'Renamed'` ở chỉ số 1, với `total=2`. Vòng quét đi 2 → 1 → 0, nên guard chỉ được gọi ở chỉ số 0, tức vòng cuối.
- Vì vậy thay đổi ở NC:234 và MQ:149 xảy ra sau lần so cuối, không ảnh hưởng lần so nào.
- **Ví dụ kiểm được:** sửa thử SEL theo một trong hai cách:
  - (a) tính lại `accepted[]` từ `magic_base` sau mỗi lần gọi guard;
  - (b) chép `symbol` vào biến cục bộ ở lần so đầu rồi dùng mãi.

  Theo phân tích của tôi, cả hai bản sai vẫn qua đủ 4598 ca. Lý do: kịch bản 1/2/3/6 đổi giá trị trước lần so đầu, còn kịch bản 5 đổi sau lần so cuối. Cả hai bản đều trái mục `read_timing` trong scan semantics.json.
- **Cách sửa:** thêm ca mới (giữ nguyên ca r1) với thứ tự `[[12,'Renamed'],[11,'XAUUSD']]`. Theo phân tích mã máy, bản gốc sẽ gọi guard 2 lần (11 rồi 12); cả hai bản sai chỉ gọi 1 lần. Cần chạy để xác nhận.
- CANON:57 hiện vẫn giữ thứ tự cũ.

**L2 – `fixtures()` của r1 không kiểm đã đọc hết byte**
- NC:113-145 dừng vòng đọc khi `pos ≥ len` rồi trả về. Không có `FIXTURE_BYTES_NOT_EXACT` như tool cha (CLOSE:151).
- `Reader.text/block` cắt lát mà không kiểm biên (SEND:118-122).
- **Ví dụ:** một fixture có bản ghi cuối là api 23 với chuỗi `'XAUUSD'`, bỏ 2 byte cuối → r1 vẫn nhận, kết thúc với `pos = len+2`.
- Ảnh hưởng thực tế thấp, vì hash của fixture và phép so trạng thái ở bước native vẫn chặn. Nhưng đây là bước lùi so với tool cha.
- CANON:145 đã thêm kiểm này (tôi thấy trong lúc review). Chưa có biên nhận nào chạy với kiểm mới.

## 2. Đã đối chiếu, không thấy lỗi

| Mục | Bằng chứng |
|---|---|
| Bố cục byte vào/ra | Đầu vào: NC:68-75 ↔ MQ:225-253 ↔ NC:77-104. Kết quả: MQ:264-265 ↔ NC:187-196. Trạng thái quét `Q4i+text`: NC:107, 227 ↔ MQ:47-48. Tập include đóng gồm đúng 8 tệp trong `names()` (NC:274-275). |
| Chuỗi có thể NULL | NULL, `""` và văn bản được thử cho cả target và vị thế (NC:49-51). Native biểu diễn NULL bằng 12 byte 0 (NC:240, CLOSE:275). Cờ NULL được ghi tách khỏi văn bản. |
| Cộng định danh / dừng sớm | SEL:14-20 cộng kiểu `uint` rồi ép `(int)` → `(long)`. SEL:26-29 gọi lại `PositionGetInteger(12)` mỗi phép so, dừng ở lần khớp đầu. Ca kiểm: NC:42-48. |
| Vé / volume / guard | SEL:23-24 ghi vé mỗi vòng, kể cả khi bằng 0. SEL:34-35 đọc volume rồi bỏ, truyền `last_ticket` đọc ngay lúc gọi. Kịch bản 4 kiểm vé đổi giữa chừng (NC:182, 249). |
| Snapshot | Mọi mock gọi snapshot trước API (MQ:153/157/166/176/183). Native so ở NC:253-266 và CLOSE:256. Trạng thái lúc vào/ra guard so ở NC:243, 249. |
| Guard/close gốc chạy trọn | Native chỉ được chạy trong các vùng hàm đã kiểm (SEND:194-195). Mọi lệnh ghi ngoài vé (seed, symbol…) đều bị `write_guard` chặn (NC:222-224, SEND:196-202). |
| 80/81 và reset bộ đếm | MQ:192-194 chỉ reset chỉ số trả lời của bộ kiểm; NC:247 reset tương ứng. Hai phía đều không reset bộ đếm send/print/stop. |
| Trả lời cấp sẵn và định dạng đo thật | Trả lời SDK bị ràng buộc với đầu vào ca (NC:147-185, CLOSE:154-196). `StringFormat` và `DoubleToString` chạy thật trong MT5 (`Bot1PipelineApi.mqh`:115-119, 142-146). |
| Kiểm trả về / bộ nhớ | CLOSE:314-331 kiểm: RIP về điểm dừng, dùng hết bản ghi, vùng nhớ lưu, dọn 4 chuỗi, `allocs==frees`. NC:271 kiểm guard có trả về. |
| Nguồn gốc bản dựng | `bien-nhan.json` ghi 0 lỗi / 0 cảnh báo; hash 8 nguồn và hash `.ex5` khớp `mql5-run.json`. Terminal được kiểm trước/sau khi chạy (NC:299-302). Bước compare sinh lại ca và so (NC:322). |

**Hệ quả có ích** (nếu biên nhận đúng, và chỉ cho các nhánh đã chạy): mã gốc guard/close/filling/0x950 không ghi seed hay symbol, và không đổi vé. Nếu có, `write_guard` hoặc snapshot 81 đã dừng lượt chạy. Điều này đóng một mục "chưa loại trừ" trong response.md trước.

## 3. Giới hạn (không phải lỗi)

- Mọi trả lời SDK đều lấy từ trace MQL5. Không có tài khoản thật, không có lệnh thật, không mô phỏng lỗi cấp phát, không phủ toàn EA (NC:1-7).
- **Mô hình chọn vị thế** chỉ có ở phía mock (MQ:159, NC:166-167). Native chép `selected` từ trace (NC:258), nên trường này luôn trùng và không phải bằng chứng. Hành vi thật của `PositionGetTicket(total)` và `_LastError` vẫn chưa đo.
- Trả lời trong guard không phụ thuộc vị thế đang quét (MQ:89-95), và được phát lại y hệt ở mỗi lần gọi guard. Vì vậy ca có nhiều lần gọi guard luôn đi cùng một nhánh.
- Hai bot dùng cùng một `cases.bin` (`f27c4c…`). Chưa có lượt chạy trong máy thử MT5; `tester-check-tool.py` có trong tested-sources nhưng không được dùng cho r1.
- **CANON đã khác bản đóng băng:** thêm `FIXTURE_BYTES_NOT_EXACT` (dòng 145) và `HELPER_STACK_NOT_RESTORED` (dòng 244, 250). Hệ quả:
  - Chạy lại `compare` cho r1 bằng CANON sẽ báo `INPUT_OR_ORIGINAL_OR_TOOL_CHANGED`.
  - Hai kiểm mới cần một lượt r2 có biên nhận.
- Bản đóng băng không tự chạy lại được: nó cần tool cha cùng thư mục, mà tested-sources không có, và `ROOT=parents[1]` trỏ sai chỗ. Các module cha chỉ được ghim bằng hash trong `original-run.json`.

## 4. Tăng cường tùy chọn

- NC:175: giới hạn số lần gọi magic theo từng bot (8 hoặc 15) thay vì 15 chung.
- Thêm ca chuỗi cùng độ dài, chỉ khác ký tự cuối (`XAUUSD`/`XAUUSE`).
- Thêm ca nhiều lần gọi guard, mỗi lần một bộ trả lời khác nhau.
- Lúc guard trả về, kiểm cả các thanh ghi callee-saved, không chỉ RSP.
- Thêm danh sách hash của tool cha vào tested-sources.

**Cấu hình lượt này:** model `claude-opus-5-5` (theo thông tin hệ thống). Tôi không tự xác minh được mức effort thực tế và không suy ra nó từ cờ yêu cầu. Tôi không dùng agent hay workflow, không chạy lệnh, không sửa tệp.