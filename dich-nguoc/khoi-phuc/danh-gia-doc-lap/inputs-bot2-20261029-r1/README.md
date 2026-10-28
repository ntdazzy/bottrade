# Danh sách cài đặt bot 2 — 2026-10-29 r1

`inputs.json` được tạo trực tiếp từ báo cáo HTML của lượt chụp
`luot-20261026-r1`, cùng `capture-run.json` và `capture-finalization.json`.

Kết quả kiểm tra:

- EX5 đúng SHA-256: `390d8ab14fc213ff4b8cbe5084bec545526e62c6028516fe21219a59398ce795`.
- Base mã: `0x253f2620000`.
- 70 dòng theo đúng thứ tự: 8 tiêu đề menu và 62 cài đặt.
- Ba mục bị truyền đè trong lượt chạy: `AutoGMT=false`,
  `Broker_GMT_OFFSET_Winter=0`, `Broker_GMT_OFFSET_Summer=0`.
- Ba giá trị trên được đọc từ `capture-run.json` và đối chiếu giống hệt
  `capture-finalization.json`; công cụ không gán cố định.
- SHA-256 báo cáo HTML được đối chiếu với `report_sha256` trong
  `capture-finalization.json`.
- Base được đọc từ `inventory-v3.json` và đối chiếu với vùng mã thực thi
  trong `capture.json`.
- `type`, `default`, `rva` giữ `null` vì chưa có bằng chứng trực tiếp.
- 59 mục còn lại không bị truyền trong lượt chạy, không được gọi là mặc định chắc chắn.

Mã kiểm tra tệp bằng chứng được ghi trong `inputs.json`. `inventory-v3` chỉ
được dùng để ghi nhận nguồn snapshot và base; nó không có bảng ánh xạ đầu vào
sang RVA.

Chạy lại từ thư mục gốc:

```text
python dich-nguoc/khoi-phuc/cong-cu/kiem-danh-sach-cai-dat-bot-2.py
```

Lệnh phải in `status: already_verified` (nếu JSON đã có và giống dữ liệu mới),
`report_rows: 70`, `menu_titles: 8`, `inputs: 62`. Công cụ từ chối ghi đè nếu
JSON cũ khác dữ liệu vừa tạo.
