# SUMMARY: bot3-pending-math-20261026-r3

## Đã viết (3 tệp trong thư mục này)

### 1. `Bot3PendingSubmission.mqh`

Tệp có 112 dòng, xuống dòng kiểu LF, chỉ dùng ký tự ASCII. Bản gốc để so là
`source/MQL5/Include/bot-cua-toi-3/Bot3PendingSubmission.mqh` lúc bắt đầu
lượt này (105 dòng, giống hệt bản r2). So với bản đó có các thay đổi sau:

- Thêm dòng 20–26: một dòng chú thích và hàm
  `double Bot3SubmissionDifference(const double left,const double right)`.
  Thân hàm đúng như TASK: `if(left!=left) return left+0.0;`,
  `if(right!=right) return right+0.0;`, `return left-right;`.
  Thân này giống `Bot3QueueDifference` (`Bot3PendingQueue.mqh:36-41`).
  Không include PendingQueue, không dùng union, không thêm giới hạn.
- Dòng 64 (`raw_sl` phía BUY) đổi thành
  `Bot3SubmissionDifference(base_price,(settings.stop_distance+0.0)*settings.unit)`.
- Dòng 69 (`raw_tp` phía SELL) đổi thành
  `Bot3SubmissionDifference(base_price,settings.take_distance*settings.unit)`.
- Các dòng còn lại giống nguyên văn bản gốc, chỉ dời số dòng:
  - chữ ký public;
  - thứ tự đọc và gọi;
  - 3 lần gọi Digits;
  - `-0.0`, `+0.0`;
  - phép so ở bước 7 (vẫn là `price-...`);
  - vòng thử lại, ghi bảng, chuỗi lỗi.
- Tìm bằng grep: trong tệp không còn `base_price-`. Hàm mới xuất hiện ở
  dòng 21 (định nghĩa), 64 và 69.

### 2. `pending_submission_cases.py`

Tệp có 71 dòng.

- Dòng 1–49 và 56–71 là nguyên văn 65 dòng của
  `bot-cua-toi-3/tests/pending_submission_cases.py`, bản tôi đọc lúc bắt đầu
  lượt (khi đó 65 dòng, chưa có ca mới). Tôi kiểm bằng grep theo từng nhóm
  dòng trên cả hai tệp:
  - đủ 65/65 dòng, nội dung giống nhau, chỉ dời 6 dòng sau dòng 49;
  - cùng xuống dòng LF, không có tab, không có khoảng trắng cuối dòng;
  - dòng 48 dùng đúng các mã ký tự U+00E0, U+1EDD và U+1F4B0.
- Thêm dòng 50–55, nằm sau vòng sinh 308 ca cũ và trước `return out`:

```python
    for buy in [0,1]:
        for field in ['stop_distance','take_distance']:
            for bits in [0x7ff8000000000123,0xfff8000000000456,0x7ff0000000000789,0xfff0000000000abc]:
                c=base(buy);c[field]=struct.unpack('<d',struct.pack('<Q',bits))[0];add(c,'nan-payload-and-subtraction')
            for value in [float('inf'),-float('inf')]:
                c=base(buy);c[field]=value;c['unit']=0.;add(c,'invalid-product-and-subtraction')
```

- Không sửa `encode`, `RESULT`, `RESULT_NAMES`, `table`. Không thêm kết quả
  mong đợi, cũng không chuẩn hóa NaN.

### Các ca mới

Hàm `add` cấp id theo thứ tự thêm. Các id 0–307 không đổi vì vòng cũ giữ
nguyên. Tổng số ca: 308 + 24 = 332.

Bốn mẫu NaN, theo thứ tự: `0x7ff8000000000123`, `0xfff8000000000456`,
`0x7ff0000000000789`, `0xfff0000000000abc`.

| id | buy | Trường đổi | Giá trị | unit | Nhóm | Biểu thức có dùng `Bot3SubmissionDifference` (theo mã) |
|---|---|---|---|---|---|---|
| 308–311 | 0 | stop_distance | 4 mẫu NaN | .125 | nan-payload-and-subtraction | Không (sl phía SELL là phép cộng) |
| 312–313 | 0 | stop_distance | +inf, -inf | 0.0 | invalid-product-and-subtraction | Không |
| 314–317 | 0 | take_distance | 4 mẫu NaN | .125 | nan-payload-and-subtraction | Có (`raw_tp` SELL) |
| 318–319 | 0 | take_distance | +inf, -inf | 0.0 | invalid-product-and-subtraction | Có (`raw_tp` SELL) |
| 320–323 | 1 | stop_distance | 4 mẫu NaN | .125 | nan-payload-and-subtraction | Có (`raw_sl` BUY) |
| 324–325 | 1 | stop_distance | +inf, -inf | 0.0 | invalid-product-and-subtraction | Có (`raw_sl` BUY) |
| 326–329 | 1 | take_distance | 4 mẫu NaN | .125 | nan-payload-and-subtraction | Không (tp phía BUY là phép cộng) |
| 330–331 | 1 | take_distance | +inf, -inf | 0.0 | invalid-product-and-subtraction | Không |

Cột cuối chỉ dựa vào việc đọc mã, không phải kết quả chạy. `0x7ff0…0789` và
`0xfff0…0abc` là NaN báo lỗi (signaling NaN). Theo
`tests/check-pending-submission.py:133`, kết quả có cả bit của các trường đầu
vào, nên những ca này cũng kiểm việc script MQL5 có giữ nguyên bit của các
giá trị này khi đọc và lưu hay không.

## Đã đọc để làm

- TASK.md của r3.
- `source/.../Bot3PendingSubmission.mqh`.
- `tests/pending_submission_cases.py`.
- `tests/check-pending-submission.py`: chỉ để xem số ca có bị ghi cứng không.
  Tệp này dùng `len(rows)` ở mọi chỗ.
- Grep `Bot3QueueDifference` trong `Bot3PendingQueue.mqh`.
- Grep `308|154|332` trong `Bot3PendingSubmissionCheck.mq5`: không thấy hằng
  nào. Tôi chưa đọc hết script này nên chưa chắc nó không có giới hạn khác.
- Không đọc EX5 hay mã máy. Tôi không tìm hiểu hay dùng phần địa chỉ native
  trong tệp chạy kiểm.

## Chưa làm / giới hạn

- Chưa biên dịch, chưa chạy kiểm. Chưa có bằng chứng 332 ca khớp, và tôi
  không kết luận đã đạt chỉ từ việc đọc mã.
- Không sửa nguồn chính, tests, Git hay MT5. Không dùng shell, không tạo tác
  tử con.
- Ghi nhận trong lúc kiểm: sau khi tôi ghi hai tệp vào r3, hai tệp
  `source/.../Bot3PendingSubmission.mqh` và `tests/pending_submission_cases.py`
  đã có nội dung mới. Cũng đã có thêm thư mục
  `bang-chung/kiem-quan-ly-vi-the/b3-pending-submission-20261026-r3/`.
  Tôi không ghi vào những chỗ đó: các lệnh Write của tôi chỉ ghi vào thư mục
  r3, và bản r2 vẫn còn 105 dòng. Phép so nguyên văn ở trên dùng bản source
  và tests lúc trước khi chúng bị thay.

## Cấu hình lượt này

- Môi trường báo mô hình là `claude-opus-5-5` (Opus 5.5) và ultracode đang
  bật. Từ bên trong tôi không tự kiểm được mức effort `max`; Codex kiểm riêng.
- Phiên này không có công cụ Workflow, nên tôi làm một mình, không tạo tác tử.
