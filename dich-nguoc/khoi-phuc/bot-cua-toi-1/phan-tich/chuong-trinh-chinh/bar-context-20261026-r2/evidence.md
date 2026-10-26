# Bằng chứng tái lập

## 1. Chụp vùng mã gốc

Lệnh:

```powershell
python -I -B dich-nguoc/khoi-phuc/cong-cu/xem-quan-ly-goc.py 1 18aa0 1a245 1a245 1a2b0 1a300 1a414 1a460 1a5c0 1a640 --full-snapshot
```

Kết quả đầu ra xác nhận:

```text
FUNCTION 0x18aa0..0x1ef9c snapshot_sha256=45d53270186b7019a8721e0cf3734a61aac8e8660c70f7e602849b1c298d7cbd
```

Các dòng quyết định:

```text
0x1a152 movabs rax, 0x23e5aa77470[RVA=0x67470]
0x1a15c cmp byte ptr [rax], 0
0x1a15f je ...[RVA=0x1a20a]
0x1a165 movabs rax, 0x23e5aa72490[RVA=0x62490]
0x1a16f cmp byte ptr [rax], 0
0x1a172 je ...[RVA=0x1a245]
0x1a178 movabs rax, 0x23e5aa72000[RVA=0x62000]
0x1a182 cmp byte ptr [rax], 0
0x1a185 jne ...[RVA=0x1a245]
0x1a19f call rbx
0x1a1a3 jle ...[RVA=0x1a245]
0x1a1c4 call rbx
0x1a1c6 test eax, eax
0x1a1d2 jle ...[RVA=0x1a43a]
0x1a1ef movabs r12, 0x7ff6846f7fc0
0x1a245 mov esi, dword ptr [rsp + 0xbc]
0x1a326 call r12
0x1a2cd call ...[RVA=0x271f0]
0x1a2db call ...[RVA=0x2abc0]
```

## 2. Lần dấu R12

Kết quả đã lưu trong `newbar-r12-definitions.json` của lượt r1, với base `0x23e5aa10000`, ghi rõ:

- `0x18f13`: `movabs r12, 0x23e5aa7246c`
- `0x18f55`: `lea r12, [rsp + 0x1a8]`
- `0x19237`, `0x1936e`: đọc độ dài vào `r12d`
- `0x1924e`, `0x19385`, `0x194d6`: xoá R12 về 0
- `0x19b9d`: tăng R12
- điểm vào chưa giải: `0x18aa0`, `0x19034`, `0x1994d`, `0x19be1`

Kết quả này không cho một giá trị R12 duy nhất trên đường nến mới. Quy tắc thanh ghi không đổi: R12 được giữ qua lời gọi; không có phép gán tại `0x1a245` trước khi dùng ở `0x1a326`.

## 3. Giới hạn

Đây là phân tích mã gốc và lần dấu tĩnh. Chưa có EA đầy đủ, chưa có lần chạy cặp hai bot, và chưa có ghi thanh ghi R12 trực tiếp trong lần chạy nến mới. Vì vậy chỉ chốt được điều kiện vào nhánh; chưa chốt được cờ vé đầu bằng 0.
