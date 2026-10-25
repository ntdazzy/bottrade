# SUMMARY – bot3-real-take-cases-20261025-r1

## Trạng thái
- Chỉ viết `real_take_cases.py` và `SUMMARY.md` trong thư mục này; không sửa tệp khác.
- **Chưa chạy** Python hoặc MT5 vì yêu cầu không chạy lệnh. Số ca, dải id và kích thước dưới đây là số đếm từ vòng lặp trong mã, chưa có bằng chứng chạy.
- Không có kết quả mong đợi, không gọi mã bot, không mô phỏng thuật toán, không random. Chỉ import `math`, `struct`; không dùng dataclass hay chú giải kiểu.
- Chỉ đọc hai TASK (`bot3-real-take-cases-…`, `bot3-real-take-check-…`). Theo giới hạn của yêu cầu, không đọc `QUY-TRINH.md` hay phân tích lịch sử.
- Cấu hình: hệ thống ghi model `claude-opus-5-5` và báo Ultracode bật. Tôi không tự xác minh được mức `max` từ trong phiên, nên Codex cần đối chiếu cấu hình chạy thật. Không dùng tác tử phụ.

## Giao diện
- `MAGIC = 0x4D525033`, `VERSION = 1`, `HEADER = struct.Struct('<3i')`, `CASE = struct.Struct('<8iqQIII23d')`, tức 32+8+8+12+184 = 244 byte, không đệm.
- `INTS`, `DOUBLES` đúng thứ tự TASK. Có thêm `VOLUME_COUNT = 9`, `NAN_POS`/`NAN_POS_BITS`, `NAN_NEG`/`NAN_NEG_BITS`, `NEG_ZERO`, `INT32_MIN`, `INT32_MAX`.
- `cases()` tạo list dict mới ở mỗi lần gọi. Mỗi dict có các khóa:
  - 8 INTS;
  - `ticket` (int64), `deviation` (uint64);
  - `index`, `error_count`, `prior_changed` (uint32);
  - 14 DOUBLES, `volumes` (list 9 float);
  - `group` dạng `buy.|sell.<nhóm>:<thay đổi>`.

  `id` liên tục 0..993. Trước khi trả về, `cases()` tự kiểm đủ khóa, kiểu int/float, id, buy 0/1, scenario 0..8, modify_ok 0/1, index 0..8, prior_changed 0/1 và tổng ≤ 1499.
- `encode(rows)` gồm `HEADER.pack(MAGIC, 1, len(rows))`, rồi mỗi ca một `CASE.pack(8 INTS, ticket, deviation, index, error_count, prior_changed, 14 DOUBLES, volumes[0..8])`.
  - Hàm không chặn giá trị ngoài luật của Script, để Codex vẫn tạo được tệp sai khi kiểm phần xử lý lỗi.
  - Hàm chỉ báo lỗi khi thiếu khóa, khi `volumes` không đúng 9 phần tử, hoặc khi `struct` không đóng gói được.
- Với 994 ca: `len(encode(cases()))` phải bằng 12 + 994×244 = 242548.
- NaN và -0 được tạo trực tiếp từ bit qua `struct`; không có phép tính nào trên NaN. Các ô `volumes` được ghi sau cùng, nên giá trị tính `.1+i*.01` không đè lên NaN. `struct` của CPython chép nguyên 8 byte với `<d`, nhưng khi chạy nên so lại bit trong tệp với `NAN_*_BITS`.

## Nhóm ca (mỗi phía 497 ca; buy=1 trước, sell=0 sau)
| Nhóm | Số ca | id buy | id sell | Nội dung |
|---|---|---|---|---|
| base | 1 | 0 | 497 | Giá trị bình thường của TASK |
| sweep | 165 | 1–165 | 498–662 | 14 DOUBLES và `volumes[2]`, mỗi trường × 11 giá trị: -inf, -1e19, -100.125, -0, +0, 0.01, 100.125, 1e19, +inf, NaN+, NaN-. Mỗi ca chỉ đổi 1 trường |
| state | 72 | 166–237 | 663–734 | scenario 0..8 × modify_ok 1/0 × prior_changed 0/1 × minimum 0.01/+0 |
| gate | 102 | 238–339 | 735–836 | 90 ca: minimum {-0.01, -0, +0, 0.01, NaN+} × volume {-0.1, -0, +0, 0.1, +inf, NaN-} × volumes[2] {0.1, +inf, NaN+}. Thêm 12 ca: scenario 6/8 × minimum 0.01/+0 × 3 giá trị volumes[2] |
| index | 36 | 340–375 | 837–872 | index 0/8 × scenario 0..8 × minimum 0.01/+0, giữ volumes gốc |
| cell | 54 | 376–429 | 873–926 | index k = 0..8 với volumes[k] ∈ {1, +inf, NaN+} × minimum 0.01/+0 |
| digits | 7 | 430–436 | 927–933 | (-1,0,1), (0,1,2), (2,8,3), (11,10,9), (12,3,0), (INT32_MIN,INT32_MAX,-1) và ca đối chứng (3,3,3). tp = tp gốc + 0.123456789 |
| ticket | 12 | 437–448 | 934–945 | 0, 1, 2^53+1, 2^63-1, -2^63, -1 × minimum 0.01/+0 |
| deviation | 14 | 449–462 | 946–959 | 6 ca: 0, 11, 2^64-1 × minimum 0.01/+0. Thêm 8 ca: 2^64-1, minimum +0, scenario 1..8 |
| error | 16 | 463–478 | 960–975 | error_count 0/2^32-1 × error_code 0/4001/4756/-1 × modify_ok 1/0 |
| threshold | 12 | 479–490 | 976–987 | Mỗi ngưỡng có 3 ca: `nextafter` xuống, đúng giá trị, `nextafter` lên |
| nanpair | 6 | 491–496 | 988–993 | (unit,distance), (start,anchor), (tp,point), mỗi cặp theo 2 thứ tự (NaN+,NaN-) và (NaN-,NaN+) |
| **Cộng** | **497 × 2 = 994** | | | Dưới 1500 |

Các ngưỡng, `group` có dạng `threshold.<cổng>:<trường>=<giá trị>[-1ulp|+1ulp]`:
- buy: gate1 tp 108.01, gate2 anchor 108.0, freeze tp 107.5, final gap 1.0.
- sell: gate1 tp 92.99, gate2 anchor 93.0, freeze tp 92.5, final gap 2.0.

## Quy ước giá trị đặc biệt
- NaN+ = `0x7ff8000000000123`, NaN- = `0xfff8000000000456`, -0 = `0x8000000000000000`.
- Nhóm gate: minimum dùng NaN+, volume dùng NaN-, volumes[2] dùng NaN+. Như vậy cặp volume/minimum và cặp volume/volumes[2] khác bit, còn minimum/volumes[2] cùng bit. Nhóm cell dùng NaN+.

## Lựa chọn của tôi, cần Codex duyệt
1. "volume1" ở mục index được hiểu là `volumes[index] = 1.0`.
2. Đã thêm `volumes[2]` vào nhóm sweep và thêm ca đối chứng digits (3,3,3).
3. Các tích hẹp do tôi chọn:
   - minimum 0.01/+0 cho index, cell, ticket, deviation;
   - scenario 0..8 cho index 0/8;
   - scenario 6/8 cho gate;
   - scenario 1..8 cho deviation 2^64-1;
   - modify_ok 1/0 cho error.
4. Nhóm gate đặt ở index gốc 2. Khi `volumes[2] = 0.1`, giá trị này trùng `volumes[0] = 0.1+0*0.01`, nên ở 34 ca/phía 9 ô không còn khác nhau. Điều này chỉ ảnh hưởng nếu Mutate tăng index 7 lần trong một lần gọi. Nhóm index và cell luôn giữ 9 ô khác nhau.
5. Có 14 ca/phía trùng dữ liệu với một ca trước đó. Tôi giữ lại để mỗi nhóm có đủ danh sách giá trị:
   - sweep: point=0.01, minimum=0.01;
   - state (scenario,modify_ok,prior_changed,minimum): (0,1,0,0.01), (0,1,0,+0);
   - gate (minimum,volume,volumes[2]): (0.01,0.1,+inf), (0.01,0.1,NaN+);
   - cell index 2: +inf/NaN+ × minimum 0.01/+0 (4 ca);
   - deviation 11 × minimum 0.01/+0;
   - error (error_count,error_code,modify_ok): (0,4756,1), (0,4756,0).

## Ví dụ tạo tệp (chưa chạy)
Chạy trong thư mục này:

`python -c "import real_take_cases as m; open('cases.bin', 'xb').write(m.encode(m.cases()))"`

Chế độ `xb` không ghi đè tệp đã có.
