# Công cụ dịch ngược

Chạy từ thư mục dự án. Quy tắc dùng lại công cụ ở
[QUY-TRINH.md](../QUY-TRINH.md); chưa có bộ dịch hoàn chỉnh cho mọi EA.

## Công cụ đang có

| Vị trí | Công dụng |
|---|---|
| `tools/verify-project.py` | Kiểm tệp gốc, bằng chứng, bản biên dịch và nhật ký đã lưu |
| `tools/build.ps1` | Biên dịch nguồn bot/chương trình kiểm trong MT5 riêng |
| `tools/run_market.py` | Chạy file công việc, lưu nhật ký và báo cáo MT5 |
| `tools/inspect-ex5-running-code.py` | Đọc vùng mã/dữ liệu của máy thử riêng |
| `tools/run-market-ex5-capture.ps1` | Chạy, chụp dữ liệu rồi dừng đúng máy thử riêng |
| `tools/analyze-api-probes.py` | Đối chiếu lời gọi MT5 từ chương trình có nguồn |
| `tools/ghidra/` | Nhập dữ liệu và xuất mã trung gian bằng Ghidra |
| `tools/project_paths.py` | Nối đường dẫn trong biên nhận cũ với vị trí mới |
| `tools/check-claude-recovery.py` | Thử một bài phục hồi bằng Claude; lưu mức suy nghĩ, lượng chữ xử lý và câu trả lời |
| `bots/twisterpro-scalper/tests/check-twister-settings.py` | Tạo/so ca khởi tạo Twister |
| `bots/twisterpro-scalper/tests/check-twister-filters.py` | Tạo/so ca ba bộ lọc Twister |

Vị trí trong bảng tính từ `dich-nguoc/`. Công cụ mới phải thêm vào bảng,
ghi đầu vào/đầu ra, lệnh mẫu và giới hạn; sau đó gọi lại thay thao tác tay.

## Kiểm bằng chứng đã lưu

```powershell
python -I -B -X utf8 .\dich-nguoc\tools\verify-project.py --evidence-only
python -I -B -X utf8 .\dich-nguoc\bots\twisterpro-scalper\tests\check-twister-settings.py compare twsettings_v1
python -I -B -X utf8 .\dich-nguoc\bots\twisterpro-scalper\tests\check-twister-filters.py compare twfilters_v3
```

Ba lệnh trên không chạy MT5 mới. `--evidence-only` kiểm bằng chứng và EA
gốc; không kiểm mã đang sửa. Bỏ tùy chọn này để so toàn bộ ảnh chụp lúc
chuyển dự án: mã/tài liệu sửa sau đó sẽ báo khác. Giữ nguyên biên nhận cũ.

## Thử Claude

`python -I -B -X utf8 dich-nguoc/tools/check-claude-recovery.py --claude '<claude.exe>' --prompt '<bai-thu-trong-du-an>' --profile project --run '<ten-moi>'`.
Mặc định dùng `--effort low`; `control` bỏ các chỉ dẫn tùy chỉnh, `system`
nạp CLAUDE.md qua tham số lúc khởi chạy. Kết quả ở `.local/claude-recovery-check/`,
không lưu phiên chat, không sửa nguồn. Có mã trả về chưa chứng minh mã chạy
đúng; phải đọc kết quả và kiểm riêng.
Lượt chỉ hỏi “có nhận việc không” chỉ kiểm lời trả lời ban đầu. Muốn xác
nhận tiếp tục làm, phải cho đọc đủ hồ sơ và kiểm hành động thực tế; câu
đồng ý trước đó không đủ nếu sau khi đọc hồ sơ lại dừng.

Cách nạp lúc khởi chạy tham khảo [Keysmith](https://github.com/Jia-Ethan/claude-keysmith/blob/main/docs/reference.md#runtime-层).
Để giảm lượng chữ xử lý: giữ quy tắc ngắn, lọc nhật ký bằng công cụ,
dùng lại dữ liệu còn đúng và mở phiên mới khi đổi việc; xem
[hướng dẫn Claude](https://code.claude.com/docs/en/costs#reduce-token-usage).

## Biên dịch và chạy mới

Chuẩn bị MT5 riêng tại `dich-nguoc/.local/terminal/`. Phiên bản và dữ liệu
cũ ở [setup.json](../bots/twisterpro-scalper/verification/setup.json).
Thư mục này chưa được mang sang khi chuyển dự án.

```powershell
.\dich-nguoc\tools\build.ps1
# File công việc phải dùng tên lượt mới và đủ dữ liệu:
python -I -B -X utf8 .\dich-nguoc\tools\run_market.py '.\dich-nguoc\.local\terminal' '<file-cong-viec.json>'
```

`build.ps1 -Source '<file-mq5-trong-bot>'` dùng để biên dịch chương trình
kiểm riêng. Hiện công cụ còn dùng tệp trực tiếp trong `source/`; phải cập
nhật khi chuyển nguồn sang cấu trúc MQL5 chuẩn. `verification/builds/`
giữ bản đã kiểm trước đây, không mặc định là bản biên dịch mới nhất.

## Phân tích thêm

- Cài thư viện khi cần: `python -m pip install --only-binary=:all: --no-deps --target '.\dich-nguoc\.local\python' -r '.\dich-nguoc\requirements.txt'`.
- Hai công cụ kiểm Twister nhận `prepare <ten-luot-moi>` để tạo ca mới và `compare <ten-luot>` để so sau biên dịch/chạy.
- Chụp Twister: `.\dich-nguoc\tools\run-market-ex5-capture.ps1 -Indices 9 -Run <ten-moi> -IncludeProgramData -ReadyByteRva 0x22590`. Các bot khác đang chờ Twister hoàn chỉnh.
- Đối chứng có nguồn: `analyze-api-probes.py api_probe_v6`. Kết quả đã có sẽ bị từ chối ghi đè; dùng lượt mới khi phân tích mới.
- Ghidra 12.1.4/JDK 21: xem [biên nhận môi trường](../docs/environment/); tệp nhập của Twister ở `analysis/twister-meta-v2/`.

Lỗi phải được xử lý trước khi dùng kết quả. Không dùng lượt bị ngắt để
kết luận lợi nhuận hoặc coi dữ liệu cấp sẵn là lượt kiểm bot gốc trong MT5.
