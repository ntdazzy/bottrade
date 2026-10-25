# Bot3 prefix quản lý: tính 2NaN trên CPU (bản đề xuất, CHƯA CHẠY)

Tệp giao: `check-management-prelude.py` (sửa từ bản hiện hành
`bot-cua-toi-3/tests/check-management-prelude.py`) và tệp này.
Không chạy Python/Bash/PowerShell, không đụng EX5, MQL5, ca kiểm hay bằng chứng cũ.

## Thay đổi theo mô tả đã chốt

| Mục | Đã làm |
|---|---|
| 1. Giữ nguyên | `cases()` (đếm tay: 318 ca mỗi bên, tổng 636), `encode`/`CASE`/`RESULT`, băm FNV sự kiện, `NAMES`, phép so từng bit trong `compare`, kiểm SHA EX5/hàm/đoạn gốc: không sửa. |
| 2. CPU fixture | Lớp `CpuFixture`, chỉ chạy trên Windows x64. Dùng đúng 5 đoạn opcode của `check-nan-cpu.py` (`CPU_CODES`). Thứ tự: VirtualAlloc RW (0x04) → chép mã → VirtualProtect RX (0x20) → FlushInstructionCache → WINFUNCTYPE(c_uint64, POINTER(c_uint64), POINTER(c_uint64)) → VirtualFree (0x8000). Chỉ có mul/add/sub. Mỗi lần tính: đọc MXCSR → đặt 0x1f80 → tính → khôi phục trong `finally`. |
| 3. Kiểm probe | `verify_probe` chạy trước `Original()`: SHA của bytes probe phải bằng `probe_sha256` trong identity; `opcodes` và `mxcsr_used` khớp; đủ 363 dòng; chạy lại cả 363 dòng trên CPU, mỗi dòng phải ra đúng bit `cpu` đã ghi. `identity()` có thêm `probe_sha256`. `original-run.json` có thêm `cpu_fixture`: opcodes, mxcsr_used, probe (sha256, số dòng), `calls`, `delegated_instructions`, `delegated_by_site`, `delegated_cases`. |
| 4. Tám vị trí | Bảng `CPU_SITES` ghi bytes, phép, thanh ghi đích, toán hạng nguồn. Trước khi hook, mỗi vị trí phải khớp dòng trong listing r2 (bytes, mnemonic `mulsd/addsd/subsd`, operands) và bytes trong bộ nhớ native. Hook `both_nan` được thêm sau `visit`: NaN = exponent 0x7ff và mantissa ≠ 0. Chỉ khi cả hai toán hạng là NaN mới gọi đúng phép trên CPU; giữ 64 bit trên của XMM đích, ghi 64 bit dưới, đặt RIP = address+size. Một NaN hoặc không NaN: hàm trả về ngay, Unicorn tự chạy lệnh đó. Không ghi bộ nhớ, EFLAGS hay thanh ghi khác. |
| 5. Native/ca/nguồn | Không đổi thiết lập globals/thanh ghi đầu vào, ca kiểm hay nguồn MQL5. Không lấy kỳ vọng từ MQL5, không đổi NaN thành 0. |
| 6. Vòng đời | Chỉ nhánh `original` mới tạo fixture, có `try/finally: cpu.close()`. Constructor tự giải phóng trang nhớ nếu lỗi giữa chừng. Gọi sau `close()` sẽ báo lỗi. `prepare/mql5/compare` không chạy mã máy. |
| 7. Báo cáo | Cập nhật docstring. `SCOPE` thêm `full_ea=False`, `original_bytes_changed=False`, `both_nan_sites_on_cpu=8`, `whole_original_on_cpu=False`. `LIMITS` thêm 2 dòng: bytes gốc không đổi, chỉ 8 vị trí 2NaN tính trên CPU, đây không phải lần chạy vật lý; cờ trạng thái MXCSR không mô phỏng. Báo cáo `compare` có thêm `cpu_fixture`. |
| 8. Snapshot cũ | Không đụng `prelude-20261025-r1`. Các mode vẫn không ghi đè thư mục hay tệp đã có. |

## Phần thêm ngoài mô tả (Codex quyết giữ hay bỏ)

- `GUEST_MXCSR_DIFFERS`: lúc thay kết quả, phần điều khiển MXCSR của Unicorn
  (bỏ 6 bit cờ) phải bằng 0x1f80. Phần này không đổi kết quả, chỉ dừng nếu môi trường khác 0x1f80.
- Kiểm probe tự khớp: `matched` phải bằng (cpu == unicorn); `failed` phải bằng số dòng lệch;
  mọi dòng lệch phải là 2NaN, đúng điều kiện được thay ở bước 4.

## Bằng chứng đã xem

- `probe.json`: 363 ca, 24 lệch, cả 24 đều là 2NaN. CPU trả toán hạng đầu
  (SNaN được đổi thành QNaN), Unicorn trả toán hạng khác.
- `native-boundaries.json` r2: 8 dòng có bytes/mnemonic/operands đúng như `CPU_SITES`.
  Chỉ đọc đúng các dòng 1455–1464, 1695–1704, 4602–4611, 4848–4857.
- Đã đọc `QUY-TRINH.md` theo AGENTS.md. Không đọc mã hay danh mục khác.

## Giới hạn, chưa kiểm

- Chưa chạy, chưa kiểm cú pháp bằng máy. Codex cần chạy và kiểm.
- Phải đặt tệp vào `bot-cua-toi-3/tests/` trước `prepare`, vì đường dẫn tính từ vị trí tệp.
  `tool_sha256` đổi, nên công cụ mới không kiểm lại được run cũ. Điều này là dự kiến.
- Bộ kiểm dựa vào hai hành vi của Unicorn 2: ghi RIP trong UC_HOOK_CODE thì bỏ qua lệnh hiện tại
  (`child()` đang dùng cách này), và đọc được `UC_X86_REG_MXCSR`. Nếu không đọc được,
  lỗi sẽ hiện ở lần thay kết quả đầu tiên.
- Không so `unicorn_version` trong probe (2.1.4) với Unicorn đang chạy.
- Chưa biết ca nào sẽ được thay kết quả; xem `delegated_cases` sau khi chạy.
- Sau khi sửa phần mô phỏng, MQL5 vẫn có thể còn lệch. Phần lệch còn lại cần phân tích
  tiếp, không sửa bộ kiểm để ra kết quả đạt. Đây chưa phải EA, chưa chạy hai bot song song.

## Cách chạy (Codex)

```
python -I -B -X utf8 bot-cua-toi-3/tests/check-management-prelude.py prepare prelude-cpu-20261025-r1
(bien-dich.ps1 Bot3ManagementPreludeCheck.mq5 như cũ)
... mql5 prelude-cpu-20261025-r1 --build <BUILD>
... original prelude-cpu-20261025-r1
... compare prelude-cpu-20261025-r1
```

Khi `original` chạy hết: `cpu_fixture.calls` = 363 + `delegated_instructions`.

## Cấu hình lượt này

Môi trường ghi mô hình `claude-opus-5-5`, Ultracode bật. Mức `max` không tự kiểm được
từ bên trong. Phiên này không có công cụ Workflow nên làm một mình, không chạy song song.
