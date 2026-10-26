# Bot 1 — khối nạp tham số tại RVA `0x10f60`

Ngày kiểm: 2026-10-26.

## Bản gốc và bằng chứng

- EX5 có SHA-256 theo yêu cầu: `a3b0de423a06e10ebedc279307b93d7cb9188ba2bb5de77131a913c865b0e922`.
- Ảnh mã máy đã phân tích: `C:\Users\NTD\Desktop\Bot Market Demo\dich-nguoc\khoi-phuc\bot-cua-toi-1\bang-chung\captures\luot-20261023-r1\0000023e5aa10000.bin`.
- Ảnh mã máy: `code_sha256=e099f124084093c3fdc8651d5f5326709b165248982e5d4eb7394afcbb8177a4`.
- Ảnh vùng dữ liệu: `data_sha256=2ad9ad0ea90a8f8df88170348a71a070d475174122c9eae7df8deb1fb32c61f4`.
- Địa chỉ nền mã: `0x23e5aa10000`; mọi RVA bên dưới tính từ nền này.
- Hàm chứa khối: native RVA `0x10f60`–`0x173e4`; dòng `8225` trong `ma-trung-gian.c`.
- Bằng chứng cũ được dùng lại: `bang-chung/kiem-dieu-chinh/settings-20261023-r2/native-profiles.json`.

## Kết quả đã đủ bằng chứng

`kiem-tham-so-goc-bot-1-3.py` đã chứng minh 8 mẫu, mỗi mẫu 6 trường đầu vào. `kiem-bang-khoang-cach-bot-1-3.py` đã chạy mỗi mẫu với `HL=0` và `HL=1`, tổng cộng 16 đoạn. Tất cả trường được ghi; `live_in_definitions={}`. Các địa chỉ gọi đầu tiên lần lượt là `0x12f2e`, `0x1383f`, `0x14060`, `0x14764`, `0x14e85`, `0x15791`, `0x15e71`, `0x166b3`.

| mẫu | confirmation_frame | hour1_flag | older_width | recent_width | last_shift | gap_points | khác nhau do HL |
|---:|---:|---:|---:|---:|---:|---:|---|
| 0 | 16408 | 1 | 4 | 2 | 160 | 150 | `stop_distance`: 1300 → 1500; `trail_distance`: 800 → 600; `trail_start`: 500 → 550 |
| 1 | 16388 | 1 | 8 | 10 | 150 | 600 | `stop_distance`: 1000 → 1600 |
| 2 | 16408 | 1 | 18 | 3 | 180 | 900 | `stop_distance`: 1200 → 1800 |
| 3 | 16408 | 1 | 4 | 2 | 240 | 900 | `stop_distance`: 1300 → 1600 |
| 4 | 16408 | 1 | 15 | 3 | 230 | 550 | `stop_distance`: 600 → 1100 |
| 5 | 16408 | 1 | 12 | 2 | 50 | 700 | `stop_distance`: 1000 → 1600 |
| 6 | 16408 | 1 | 17 | 2 | 110 | 150 | không khác |
| 7 | 16408 | 1 | 7 | 2 | 20 | 250 | `stop_distance`: 600 → 700 |

Các trường bổ sung đã được công cụ chứng minh ghi trong mỗi đoạn: `buy_offset`, `sell_offset`, `nearby_radius`, `expiration_hours`, `target_distance`, `trail_limit`, `trail_step`, `aux_hour1`, `aux_scan50`, `aux_older`, `aux_recent`, `aux_offset`; giá trị đầy đủ của 16 dòng nằm trong `native-profiles.json` cũ và không bị ghi đè.

## Điều chỉnh, HL và số ngẫu nhiên

- Điều chỉnh được nạp từ các ô double RVA `0x6a708`, `0x6a710`, `0x6a718`, `0x6a720`; bằng chứng cũ đặt cả bốn bằng `0.0`.
- Cờ HL là byte RVA `0x6a5d0`; phép kiểm chạy cả `0` và `1`.
- `Randomization` là double RVA `0x6a5f0`; bằng chứng cũ đặt `0.0`. C nhánh trực tiếp kiểm `0.0 < DAT_23e5aa7a5f0`, nên bằng `0` không sinh số và không cập nhật hạt giống.
- Hạt giống không phải giả định: tại RVA `0x12516` (và lặp lại ở đầu từng nhánh) có lệnh `movabs rax, 0x23e5aa7a478`, sau đó `imul ..., 0x343fd` và `add ..., 0x269ec3`; đây là ô hạt giống RVA `0x6a478` được đọc/cập nhật.
- Khi randomization dương, biểu thức C ghi rõ mẫu sinh: `state = state * 0x343fd + 0x269ec3` trên số 32 bit; giá trị dùng là `(state >> 0x10) & 0x7fff`; độ lệch là `value * (randomization + randomization) * DAT_23e5aa5fe30 - randomization`. Số lần cập nhật phụ thuộc nhánh HL và trường đang gán, nên chưa rút thành một chuỗi chung duy nhất.

## Lệnh máy gốc tiêu biểu

Lệnh đầy đủ, kèm byte, được ghi trong `native-instructions.txt`. Ví dụ đoạn mẫu 0:

```text
12469: 48 ba 80 22 a7 5a 3e 02 00 00 movabs rdx, 0x23e5aa72280
12473: 48 b9 84 22 a7 5a 3e 02 00 00 movabs rcx, 0x23e5aa72284
1247d: 66 0f 57 e4 xorpd xmm4, xmm4
1249c: c6 02 01 mov byte ptr [rdx], 1
1249f: c7 01 04 00 00 00 mov dword ptr [rcx], 4
124b9: c7 00 18 40 00 00 mov dword ptr [rax], 0x4018
124bf: c7 02 02 00 00 00 mov dword ptr [rdx], 2
124c5: c7 01 a0 00 00 00 mov dword ptr [rcx], 0xa0
124d5: 48 b9 00 00 00 00 00 c0 62 40 movabs rcx, 0x4062c00000000000
124df: 48 89 0a mov qword ptr [rdx], rcx
12510: 66 0f 2e c4 ucomisd xmm0, xmm4
12514: 76 7f jbe 0x23e5aa22595
12516: 48 b8 78 a4 a7 5a 3e 02 00 00 movabs rax, 0x23e5aa7a478
12532: 69 08 fd 43 03 00 imul ecx, dword ptr [rax], 0x343fd
12545: 81 c1 c3 9e 26 00 add ecx, 0x269ec3
```

## Kết quả dựng lại và phần còn thiếu

- Native đã chạy số dương/âm/NaN/vô cực và seed 0/1/MAX. Số dương dùng 7 mẫu theo thứ tự buy, sell, stop, target, trail, trail-start, trail-limit; profile 5 cần tiền nạp `R8=base+0x4ff00` trước block.
- Hệ số native là đúng `1/32768`; các ô điều chỉnh `0x6a708`, `0x6a710`, `0x6a718`, `0x6a720` lần lượt tác động vào giá mua/bán, dừng, mục tiêu và khoảng dời dừng.
- MQL5 đã so **320/320 ca** hữu hạn (hai HL, bốn mức randomization hữu hạn, bốn ô điều chỉnh ±1), kết quả gốc/MQL5 cùng mã kiểm `87bf7d128b10b6a5c05c0994f0067a07b71f38ea07d22e880ec183ff17a7ca7c`.
- Ca NaN/vô cực đã có bằng chứng native nhưng chưa nằm trong bộ MQL5 320 ca; khởi tạo seed từ chương trình gọi, toàn EA và nơi gọi vẫn chưa chốt.
- Đây là kiểm từng khối nạp tham số, chưa phải kiểm toàn bộ EA và chưa phải chạy song song hai bot trên MT5.
