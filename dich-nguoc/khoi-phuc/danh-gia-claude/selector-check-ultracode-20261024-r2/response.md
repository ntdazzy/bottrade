# Rà soát hạ tầng kiểm chọn lệnh hủy (bot 1 và bot 3)

## Cách rà soát
- **Ba agent rà soát nền chưa có đánh giá.** Chúng dừng khi phiên trước kết thúc mà không gửi báo cáo, nên tôi không dùng chúng làm bằng chứng. Workflow nhiều agent bị chặn chờ duyệt nên không chạy.
- Tôi tự kiểm lại toàn bộ bằng cách chỉ đọc, không chạy lệnh và không sửa tệp. Vì không chạy lệnh, tôi **không tự tính lại băm**. Các kết luận về băm dựa trên nội dung JSON và mã kiểm.

## Kết luận
Không tìm thấy lỗi nào khiến bản gốc và MQL5 khớp nhau một cách sai trên 2474 ca/bot hiện có. Có 2 thiếu sót đã chứng minh được trong mã, cả hai thuộc khâu nguồn gốc và không làm sai bằng chứng hiện tại.

## Thiếu sót đã chứng minh

**L1. Biên nhận biên dịch có `errors`/`warnings` = `null` vẫn được chấp nhận** (mức thấp)
- Vị trí: `kiem-chon-lenh-huy-bot-1-3.py:299` (chế độ mql5) và `:322` (chế độ compare). Biểu thức `receipt['errors'] or receipt['warnings']` cho `None or None` là sai, nên không báo `BUILD_NOT_VERIFIED`. Lỗi giống hệt có ở `kiem-hang-doi-trong-may-thu.py:56`.
- `bien-dich.ps1` thực sự có thể tạo biên nhận như vậy:
  - Dòng 63–64 ghi `null` khi nhật ký thiếu dòng `Result:`.
  - Dòng 70–71 vẫn chép EX5 và ghi biên nhận.
  - Sau đó dòng 74 mới báo `COMPILE_FAILED`.
- Ví dụ tự kiểm được: biên nhận có `"errors": null, "warnings": null`, đúng `target` và `binary_sha256`. Dòng 299 không chặn, dù chính công cụ biên dịch đã báo thất bại.
- Phần đã chặn sẵn: `kiem-chung-chon-lenh-huy-bot-1-3.py:92` và `:103` yêu cầu `== 0`. Hai biên nhận `b1/b3-pending-selection-01` đều là 0 lỗi, 0 cảnh báo, nên bằng chứng hiện tại không bị ảnh hưởng.

**L2. Bước mql5 không ghi và không kiểm băm của chính công cụ** (mức thấp)
- Vị trí: `kiem-chon-lenh-huy-bot-1-3.py:294–311`. Bước này không so `sha(__file__)` với `baseline['tool_sha256']`. Tệp `mql5-run.json` (dòng 311, bản của cả hai bot) không có `tool_sha256`.
- Các bước sau không bù được chỗ này:
  - compare (`:327`) và công cụ kiểm tổng hợp (`:88`) chỉ so công cụ ở bước prepare, original, bản hiện tại và bản trong `tested-sources`.
  - Danh sách nguồn được kiểm ở `:323–324` và `kiem-chung…:94–95` lấy từ chính `mql5-run.json`.
- Ví dụ: chạy prepare bằng công cụ T0, sửa công cụ (bỏ một tên ở dòng 300 hoặc đổi `Symbol=` ở dòng 305), chạy mql5, rồi trả lại T0. Các bước original, compare và kiểm tổng hợp vẫn đạt, không tệp nào cho thấy đã dùng bản sửa.
- Hiện trạng: `mql5-run.json` liệt kê đúng 8 tệp, khớp đồ thị `#include` thật mà tôi đã kiểm. Bước máy thử thì có ghi `tool_sha256` và đã được kiểm (`kiem-chung…:104`). Vậy đây là thiếu hồ sơ nguồn gốc, không phải kết quả sai.

## Giới hạn giả định (chưa có ví dụ làm sai kết quả)
- **G1. `fixtures()` không kiểm đã đọc hết đúng độ dài tệp** (`:104–140`, khác `read_cases:101` và `read_results:188`). `Reader.text/block` cũng không báo khi tệp bị cắt cụt. Đã có chặn: bản ghi cuối luôn là thông điệp api 25 của ca cuối, nên `validate_inputs` sẽ bắt. Ngoài ra compare và kiểm tổng hợp đều so băm `api-fixtures.bin`.
- **G2. Không phân biệt `NULL` với `""`** ở 4 chuỗi trạng thái và ở đối số chuỗi của api 2/3/5/6/8 (`Text`/`TextHash` trong PipelineApi, `text()` của bộ giả lập). Cờ null chỉ có ở api 11–14, 23 và `symbol_null`. Trong luồng hủy, hàm định dạng đổi `NULL` thành `_Symbol` (`Bot1TradeMessages.mqh:29,68`). Vì vậy khác biệt vẫn lộ ra ở các ca có ghi nhật ký, chỉ bị che ở ca không định dạng.
- **G3. Máy thử dùng đường dẫn tác tử cố định và không kiểm thư mục kết quả có sạch không.** Đường dẫn là `Agent-127.0.0.1-3000/.../<CheckRun>` (`kiem-hang-doi-trong-may-thu.py:105,110–113`). Đã có chặn: nhật ký được cắt theo từng lượt (`chay-may-thu.py:111,126–136`) và phải có `EXIT:0`; EA ghi lại cả ba tệp kết quả. Hai lượt hiện có đều chạy trên Agent-3000 (dòng 1 của cả hai log). Nếu tác tử khác chạy, công cụ có thể chép nhầm tệp cũ. Byte vẫn phải trùng với script và bản gốc, nên rủi ro chỉ là ghi sai nguồn gốc, không phải khớp sai.
- **G4. Công cụ kiểm tổng hợp không tự dựng lại wrapper máy thử** mà chỉ so băm với `build.json` (`kiem-chung…:107`). Tôi đã đọc và so tay: wrapper của b1 và b3 chỉ khác ở 3 chỗ thay thế cộng phần `OnInit`/`OnTick`. Tệp `include` đã chỉnh chỉ đổi dòng 213.
- **G5. Phép tự kiểm đột biến** (`kiem-chung…:23–59`) thử 24 loại, mỗi loại một lần trên một trường. Nó không thử xóa hay đảo thứ tự bản ghi; phần đó do bước phát lại bản gốc bắt.

## Giá trị được cấp và đầu ra thuật toán
- **Đầu ra thuật toán thật:**
  - Bảng 1600 byte.
  - `last_ticket`.
  - request/result/check sau hàm (trừ `new_result`, vốn do harness cấp).
  - Các bộ đếm: lần gửi, lỗi định dạng, lần in sớm, `OrderSelect`, lần in.
  - Băm chuỗi in mà phía bản gốc đọc từ bộ nhớ.
  - Thứ tự và đối số mọi lời gọi (được so lúc phát lại, không nằm trong byte kết quả).
- **Trạng thái do harness mô hình hóa, khớp không chứng minh thêm:**
  - `selected`: phía bản gốc lấy thẳng từ fixture (`:227`) hoặc từ dữ liệu ca (`:241–242`).
  - `magic` và `symbol`: biến đầu vào, phía bản gốc bị `write_guard` cấm ghi.
  - `event_count`: bằng nhau theo cấu trúc.
  - `print_hash`: tính từ chuỗi do MT5 định dạng, phía bản gốc dùng lại bản ghi.
- **Giá trị được cấp:**
  - Các truy vấn lệnh/symbol, kết quả `OrderSelect` và kết quả gửi đều được ràng vào `cases.bin`.
  - Kết quả định dạng chuỗi và `_Symbol`/`_Digits` được đo trong MT5, không ràng vào ca; đúng với phạm vi đã công bố.
  - Ở pha hủy, giá trị guard không gắn với lệnh vừa chọn. Ví dụ ca kind=1 chọn lệnh type 5 giá 100, nhưng sau `OrderSelect` lại nhận `ORDER_TYPE=4`, giá 104. Terminal thật không trả như vậy, nhưng hai bên nhận y hệt nhau nên không gây khớp sai.

## Đã kiểm, không thấy lỗi
- **Mã hóa:** thứ tự và độ rộng trường của `cases.bin`, fixture và kết quả khớp giữa Python và MQL5 (260 byte + 4 chuỗi + `Q3i` + chuỗi + `5iQ2iQ` + 1600 byte). Dấu `Q`/`q` đúng. NaN/sNaN và -0 đi bằng bit thô. Làm tròn int64→double ở 2^53+1 và ≥2^63 giống nhau ở cả ba nơi. UTF-16 tính theo đơn vị mã, cặp surrogate giữ nguyên.
- **Offset và slot:** khớp `native.txt` của cả hai bot.
- **Kịch bản đổi trạng thái 1–4:** điều kiện kích hoạt, thời điểm và tác dụng giống nhau ở hai bên.
- **Danh sách nguồn ở dòng 300:** bằng đồ thị `#include` thật.
- **Phát hiện chạy dở:** `script-status.bin` chỉ được ghi khi chạy xong, thư mục Files luôn mới, và compare bắt buộc có `mql5-run.json`.

## Giới hạn phạm vi
2474 ca mỗi bot là bộ hữu hạn. Nó chỉ chứng minh 4 hàm chọn lệnh, cùng nhánh hủy/gửi/thông điệp, với các giá trị được cấp. Nó không chứng minh toàn bộ bot, cài đặt, hiển thị, khởi động lại, tài khoản thật hay lỗi cấp phát. `whole_bot_complete=false` là đúng.
