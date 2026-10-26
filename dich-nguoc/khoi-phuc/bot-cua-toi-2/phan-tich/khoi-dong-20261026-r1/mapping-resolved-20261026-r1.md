# Metadata bot2 đã nối đúng bản chụp — 2026-10-26

- Capture mới: `luot-20261026-r1`, PID `27580`.
- EX5 nguồn: `Goldbot One MT5.ex5`, SHA-256
  `390d8ab14fc213ff4b8cbe5084bec545526e62c6028516fe21219a59398ce795`.
- Engine SHA-256 `5033d9d45d669cebd735e8a6be20b54d74b75274f885c9a0e48e52d872104efb`, base `0x7ff79ff60000`.
- Vùng mã snapshot base `0x253f2620000`, SHA
  `ae4e9020f7f5f08d49774728bed14c17eb2bd26b6271c20da51bd3aaa446014f`.
- Vùng dữ liệu chương trình SHA
  `081d4e4274f0fdc0c22f3b463137d73177fc2093abb18f0875c009f265e5db77`.
- Metadata mới có **86** dải hàm, 680 chuỗi, 141 nhãn SDK và 81 chữ ký.

`compare-metadata-v2.py` đối chiếu các RVA của 86 dải mới với bản đồ 83 cũ;
file `metadata-v2.json` là kết quả tự động. Kết quả thô có 6 RVA xuất hiện
thêm (`0x8e0`, `0x900`, `0xc30`, `0x11060`, `0x1f900`, `0x20c70`) và 3 RVA
không còn là điểm bắt đầu cũ (`0x430`, `0x8b0`, `0x24150`); đây là thay đổi
bảng dải hàm, chưa kết luận tất cả là thuật toán mới. Ba hàm ròng tăng được
ghi theo RVA
thực tế; bản 83 cũ vẫn giữ riêng và không bị coi là sai. Metadata mới chỉ
chứng minh phạm vi snapshot và nhãn/thunk tương ứng, chưa chứng minh toàn bộ
EA, thuật toán hay hành vi giao dịch.
