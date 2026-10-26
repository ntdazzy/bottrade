# Kiểm độc lập khối chuẩn bị bot 1

Ngày 26/10/2026. Đã đọc `AGENTS.md` và `dich-nguoc/khoi-phuc/tai-lieu-cu/QUY-TRINH.md` trước khi kiểm. Đối chiếu `preparation-complete-20261026-r1/README.md`, `bindings.json`, `raw-instructions.txt` với vùng `FUN_23e5aa17500` trong mã trung gian hiện hành.

## Kết quả đã khớp

- Vị trí và mã kiểm thân hàm: `0x7500..0x831d`, mã kiểm raw `3392856140a1634057edf8cdfc091e5a5dc7fa6d1a8f8413f2d8409b50b484db`.
- Thứ tự gọi tạo chỉ báo, sao chép 100 giá trị, đánh dấu chuỗi, kiểm mảng ngắn, tính hệ số/lô, đọc tick/thời gian/điểm/chữ số, tính chênh lệch giá, chép trường, chuẩn hoá dừng/chốt, giới hạn sàn và thời hạn đều khớp lệnh máy.
- Nhánh handle âm, kết quả sao chép bằng 0, mảng ngắn, hệ số bằng 0 và chia cho 0 đều được giữ ở đúng vị trí; chưa có bằng chứng để đổi thành lỗi MQL5 khác.

## Sửa tài liệu bắt buộc

`bindings.json` cũ ghi `0x7753/0x7775` cho đọc điểm. Lệnh máy cho thấy:

- `0x7753` là lời gọi thời gian hiện tại, ghi vùng `0x67790`.
- `0x7775` mới là `SymbolInfoDouble` thuộc tính `0x10`, ghi điểm vào `0x67928` và đơn vị vào `0x66d98`.

Đã sửa hai tài liệu trong cùng lượt. Không sửa mã máy hay EX5.

## Giới hạn còn lại

- Điều kiện hệ số có NaN phải theo `ucomisd/jbe` tại `0x7637`; diễn giải C của công cụ dịch có thể trình bày nhánh NaN khác, nên không dùng C để chốt hành vi này.
- Một số trường `native_RVA_*`, tham số dịch vụ và lỗi máy chủ chưa có tên chắc chắn.
- Chưa có caller, EA đầy đủ hoặc phép chạy cặp hai bot; đây chưa phải xác nhận toàn bot.

## Nguồn kiểm

- `bot-cua-toi-1/phan-tich/chuong-trinh-chinh/preparation-complete-20261026-r1/raw-instructions.txt`
- `bot-cua-toi-1/phan-tich/chuong-trinh-chinh/preparation-complete-20261026-r1/bindings.json`
- `bot-cua-toi-1/phan-tich/luot-20261023-data-v2/ma-trung-gian.c` (mã kiểm hiện tại `9048c2c1c84b4607dfad326687968df8231495f6447e4202e83b653ebbf8a19a`; bản capture gốc được ghi riêng trong README)
