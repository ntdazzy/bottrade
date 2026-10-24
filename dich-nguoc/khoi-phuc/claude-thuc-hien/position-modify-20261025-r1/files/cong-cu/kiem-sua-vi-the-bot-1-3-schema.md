# Sơ đồ tệp của `kiem-sua-vi-the-bot-1-3.py`

Mọi số nguyên là little-endian. `MAGIC = 0x4d4f4431`, phiên bản 1.
Chuỗi (`text`) = `int32 số ký tự UTF-16` + các mã UTF-16; tối đa 4096.
Thư mục lượt: `bot-cua-toi-N/bang-chung/kiem-sua-vi-the/RUN/`, tên lượt
`[a-z0-9-]{1,40}`. Mọi tệp đầu ra được tạo mới; có sẵn thì dừng.

## 1. `cases.bin` (tạo ở `prepare`)

Đầu tệp: `int32 MAGIC, int32 1, int32 n`. Mỗi ca:

| Phần | Kiểu | Ghi chú |
|---|---|---|
| Môi trường gửi | đúng `kiem-gui-lenh-bot-1-3.py encode()` bỏ 12 byte đầu | `id, async_mode, log_level, margin_mode, accepted, write_result` (6×int32); `digits[2], executions[2]` (int64); `digits_ok[2], execution_ok[2]` (int32); yêu cầu ban đầu (cờ NULL mã giá + 17 trường); kết quả ban đầu; kết quả cấp sau gửi |
| `scenario` | int32 | 0..7, bảng mục 6 |
| `ticket`, `magic`, `deviation` | uint64 ×3 | vé truyền vào; mã nhận diện đã lưu; độ lệch đã lưu (hàm không dùng) |
| `stopped` | int32 | giá trị dword cờ dừng (khác 0 là dừng) |
| `preferred` | int32 | ưu tiên cách khớp đã lưu (hàm không dùng) |
| `select_ok` | int32 | 0/1, kết quả chọn vé |
| `symbol_null` | int32 | 0/1; 1 thì `symbol` phải rỗng |
| `symbol` | text | kết quả `PositionGetString` |
| `sl`, `tp` | double ×2 | giữ nguyên bit, gồm NaN báo hiệu |

`cases.json` lưu cùng dữ liệu, số thực ở dạng hex 8 byte, thêm `group`.
`baseline.json`: `cases`, `cases_sha256`, `original_ex5_sha256`,
`engine_sha256`, `tool_sha256`, `dependencies_sha256`, `sources_sha256`.

## 2. Đầu ra MQL5 (`mql5`)

Thư mục MT5: `MQL5/Files/botN-position-modify/RUN/`. Mã trả của script:
0 xong; 2 thiếu `CheckRun`; 3 không mở được đầu vào; 4 đầu tệp sai;
5 không tạo được đầu ra; 6 ca sai dạng; 7 lời gọi ngoài dự kiến; 8 còn
byte đầu vào; 9 không ghi được trạng thái.

`script-status.bin`: `int32 0, int32 n`.

`mql5-results.bin` = `int32 MAGIC, 1, n` + mỗi ca:
`int32 id`, `uint32 giá trị trả`, **khối trạng thái**, 8×int32 bộ đếm
(`entries, selects, strings, sends, format_failures, early_prints,
events, print_count`), `uint64 print_hash`.

**Khối trạng thái** (cũng là bản ghi 18):

| Byte | Nội dung |
|---|---|
| 0..259 | mã nhận diện (8), ưu tiên (4), 17 trường yêu cầu (120), 10 trường kết quả (68), 8 trường kiểm (60); chuỗi thay bằng FNV-1a 64 của UTF-16 |
| tiếp | 4 chuỗi đầy đủ: `request.symbol`, `request.comment`, `result.comment`, `check.comment` |
| tiếp | 4×int32 cờ NULL cùng thứ tự |
| tiếp | uint64 độ lệch; int32 chế độ gửi; int32 chế độ ký quỹ; int32 mức ghi |

`api-fixtures.bin` = `int32 MAGIC, 1, n`, `text _Symbol`, `int32 _Digits`,
rồi các bản ghi `int32 case_id, int32 api, dữ liệu`:

| api | Khi nào | Dữ liệu |
|---|---|---|
| 17 | đầu mỗi ca | 4 text: `(string)(int)TRADE_ACTION_SLTP`, `"0"`, `"0"`, mã kết quả cấp |
| 18 | trước chọn vé, trước đọc mã giá, trước in dừng, sau gửi | khối trạng thái |
| 20 | chọn vé | int32 lần, uint64 vé, int32 kết quả |
| 23 | đọc mã giá | int32 thuộc tính, int32 lần, int32 NULL, text |
| 8 | in dừng | text mẫu, text tên hàm, text kết quả in |
| 1 | gửi | int32 async, int32 accepted, 120 byte yêu cầu, 68 byte kết quả cũ, 68 byte kết quả mới |
| 2 | đọc chữ số/cách thực hiện khi in | int32 thuộc tính, text mã giá, int64 giá trị, int32 thành công |
| 3 | DoubleToString | uint64 bit, int32 chữ số, text |
| 5 | StringFormat | int32 số đối số, đối số có thẻ `0x590008` (text) / `0x560015` (uint64), text kết quả |
| 6 | PrintFormat 3 đối số | 4 text |

Bản ghi khác (7, 9, …) là lỗi `UNEXPECTED_MODIFY_FIXTURE/RECORD`.

`mql5-run.json`: số ca, mã thoát, thời gian, `script_sha256`,
`terminal_sha256_before/after`, biên nhận biên dịch và mã băm, mã
MetaEditor, năm mã định danh của lượt, mã băm 3 đầu ra, mã băm bản sao
`tested-sources/` (7 nguồn + `check-tool.py`).

## 3. Đầu ra mã gốc (`original`)

`original-results.bin`: cùng dạng `mql5-results.bin`; giá trị trả là
EAX. `original-run.json`: mã băm kết quả/dữ liệu cấp, năm mã định danh,
`paths` (`stopped`, `select_failed`, `sent`), `coverage`
(`instructions`=196, `executed`), `observed_literals` (chuỗi đọc qua mô
tả gốc), số ca đã kiểm hợp đồng đầu vào.

## 4. `comparison.json` (`compare`)

`cases, matched, failed, first_failures[≤12]` (mỗi mục: `id, group,
first_different_byte, field, original, mql5`), `paths`, `coverage`,
`observed_literals`, mã băm 5 tệp, `whole_bot_complete=false`. Mã thoát
1 nếu có ca lệch.

## 5. Kiểm bắt buộc ở từng bước

| Bước | Kiểm |
|---|---|
| mọi bước | EX5 gốc theo `catalog.json`; mã máy đo `5033d9d4…`; mã công cụ; mã các phụ thuộc (khung close/cancel/send, đối chứng có nguồn, bản chụp, Unicorn, phân tích + biên nhận, `semantics.json`, `strings.tsv`); 7 nguồn MQL5 không đổi từ `prepare` |
| `mql5` | biên nhận: đúng đích; `errors`/`warnings` phải là số nguyên 0 (null = lỗi); mã EX5 = bản trong biên nhận = bản trong MT5; 7 nguồn trong biên nhận = nguồn hiện hành = bản trong MT5; mã `terminal64.exe` trước = sau |
| `original` | mã các tệp MQL5; hợp đồng đầu vào từng ca; đủ 196 lệnh đã chạy; xem mục 7 |
| `compare` | lại toàn bộ; tạo lại ca phải giống từng byte; tập nguồn đúng 7 tên; mã `terminal64.exe` hiện tại = đã ghi |

## 6. Kịch bản thay đổi tại ranh giới

Cùng một thay đổi được làm ở MQL5 (`ModifyChange`) và trên bộ nhớ mã gốc.

| Số | Lúc | Ghi | Điều phải thấy |
|---|---|---|---|
| 1 | trong lần chọn vé thứ 1 | mã nhận diện `0x1111222233334444`, độ lệch 77, `request.price=11.5`, `result.retcode=4242`, `check.balance=-3.5`, mức ghi 2 | chọn được: bị xóa trừ mã nhận diện/độ lệch/mức ghi; `request.magic` lấy giá trị mới. Chọn lỗi: giữ cả |
| 2 | trong lần đọc mã giá | mã nhận diện `0xfedcba9876543210` | `request.magic` lấy giá trị mới (đọc sau mã giá) |
| 3 | trong lần đọc mã giá | `price=33.25, action=7, position=0x55, type_filling=3, expiration=1234567`, `result.deal=99`, `check.margin=8.5` | còn nguyên tới khi gửi (đã xóa trước đó); thông báo theo hành động 7 |
| 4 | trong lần đọc mã giá | `sl=1, tp=2, magic=3, symbol="changed"` | bị ghi đè sau lời đọc |
| 5 | sau khi gửi trả | mã nhận diện `0x0123456789abcdef`, `request.tp=-7.5` | thông báo in `tp` mới; trạng thái cuối có mã mới |
| 6 | trong lần in dừng | `result.retcode=777`, `request.price=55.5`, mã nhận diện 42 | retcode thành 10027 sau in; hai giá trị kia giữ |
| 7 | trong lần chọn vé | đảo cờ dừng | không đọc lại cờ dừng |

## 7. Bất biến chỉ kiểm ở mã gốc

- Chạy từ RVA hàm tới lệnh trả, `RIP` về địa chỉ canh, dùng hết bản ghi cấp.
- Chỉ được ghi 628 byte vùng lưu, ngăn xếp, vùng cấp phát kiểm, ô chuỗi tạm.
- Thanh ghi khác đối số mang giá trị canh; RBX/RBP/RDI/RSI/R12–R15/XMM6–15
  và RSP phải được khôi phục; 32 bit cao của RAX bằng 0.
- Nhánh thoát sớm: 628 byte giữ nguyên, trừ retcode 10027 khi dừng và
  các byte kịch bản tự ghi. Nhánh chọn được: ba vùng đệm riêng
  `(128,112)`, `(312,124)`, `(500,128)` bằng 0.
- Chụp kết quả trước khi dọn 4 chuỗi bằng hàm gốc RVA 0; sau đó số lần
  cấp phải bằng số lần giải phóng.
