# Công cụ hiện hành cho bot 1 và 3

Chạy từ gốc dự án. Mỗi lượt dùng tên mới, giữ nguyên bằng chứng cũ.

| Công cụ | Đầu vào và kết quả | Giới hạn |
|---|---|---|
| `xem-quan-ly-goc.py` | Bot, cặp vị trí đầu/cuối viết hệ16; in lệnh đã chụp và vị trí đúng của dữ liệu trong chương trình | Chỉ đọc hai thân quản lý đã có trong analysis.json; cuối khoảng không được tính; không đọc/sửa EX5 hoặc chạy MT5 |
| `thu-ket-qua-claude.py` | Tên đợt và `--runs` các tên việc; lưu biên nhận, câu giao/đáp và mã kiểm tra | Kiểm model/mức suy nghĩ từ yêu cầu thật trong nhật ký; đã giao tệp chưa đồng nghĩa mã đạt; Ultracode vẫn cần bằng chứng riêng |
| `giao-claude-phan-viec.ps1` | `-Prompt`, `-Run`, `-OutputDirectory`; khởi chạy Claude ghi đề xuất trong thư mục riêng | Chỉ giao phần đã đủ mô tả; không tự ghép nguồn, không giao lại phần bị từ chối dưới tên khác |
| `kiem-ban-git-quan-ly.py` | `--manifest FILE --case-run BOT:RUN --compile-only BOT:BUILD`, thêm `--ref HEAD` sau commit; so nguồn/phụ thuộc đúng byte Git, kết quả, bản dựng và EX5 gốc | Chỉ đọc; sáu khối vẫn là kiểm từng phần, bản ghép toàn luồng chỉ biên dịch chưa thành phép chạy |
| `bien-dich.ps1` | `-Bot`, `-Terminal` riêng, `-Run`, `-Source` đường dẫn đầy đủ của nguồn; tạo biên nhận và giữ bản dựng | Biên dịch thành công chỉ chứng minh mã được chấp nhận, chưa chứng minh hành vi |

Ví dụ đọc hai đoạn, không sửa tệp:

```powershell
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/xem-quan-ly-goc.py 1 27ee4 28220 2b8ed 2bc82
```

Khoảng sai báo lỗi trước khi đọc; chỉ chấp nhận bot1/3. Các phép kiểm
riêng của từng phần ở `bot-cua-toi-1/tests/` và `bot-cua-toi-3/tests/`.
