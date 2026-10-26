# Công cụ hiện hành cho bot 1 và 3

Chạy từ gốc dự án. Mỗi lượt dùng tên mới, giữ nguyên bằng chứng cũ.

| Công cụ | Đầu vào và kết quả | Giới hạn |
|---|---|---|
| `xem-quan-ly-goc.py` | Bot, cặp vị trí đầu/cuối viết hệ16; thêm `--full-snapshot` để đọc hàm khác trong bản chụp; in lệnh và vị trí dữ liệu, mã kiểm của hàm | Mặc định đọc hai thân quản lý trong analysis.json; cuối khoảng không được tính; không sửa EX5 hoặc chạy MT5 |
| `thu-ket-qua-claude.py` | Tên đợt và `--runs` các tên việc; lưu biên nhận, câu giao/đáp và mã kiểm tra | Kiểm model/mức suy nghĩ từ yêu cầu thật trong nhật ký; đã giao tệp chưa đồng nghĩa mã đạt; Ultracode vẫn cần bằng chứng riêng |
| `giao-claude-phan-viec.ps1` | `-Prompt`, `-Run`, `-OutputDirectory`; khởi chạy Claude ghi đề xuất trong thư mục riêng | Chỉ giao phần đã đủ mô tả; không tự ghép nguồn, không giao lại phần bị từ chối dưới tên khác |
| `kiem-ban-git-quan-ly.py` | `--manifest FILE --case-run BOT:RUN --compile-only BOT:BUILD`, thêm `--ref HEAD` sau commit; so nguồn/phụ thuộc đúng byte Git, kết quả, bản dựng và EX5 gốc | Chỉ đọc; kiểm đúng phạm vi các lượt được chọn, không xác nhận EA đầy đủ |
| `bien-dich.ps1` | `-Bot`, `-Terminal` riêng, `-Run`, `-Source` đường dẫn đầy đủ của nguồn; tạo biên nhận và giữ bản dựng | Biên dịch thành công chỉ chứng minh mã được chấp nhận, chưa chứng minh hành vi |

Ví dụ đọc hai đoạn, không sửa tệp:

```powershell
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/xem-quan-ly-goc.py 1 27ee4 28220 2b8ed 2bc82
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/xem-quan-ly-goc.py 3 e0c0 e150 --full-snapshot
```

Khoảng sai báo lỗi trước khi đọc; chỉ chấp nhận bot1/3. Các phép kiểm
riêng của từng phần ở `bot-cua-toi-1/tests/` và `bot-cua-toi-3/tests/`.

Phép kiểm ghép mới:

- `bot-cua-toi-{1,3}/tests/check-profile-preparation.py`: prepare/original/mql5/compare,
  chạy thân nạp cấu hình rồi chuẩn bị trong cùng bộ nhớ native. Bot 1 so 432 ca/
  119 giá trị; bot 3 so 2.106 ca/124 giá trị. Dữ liệu tên mã, comment, vốn và
  dịch vụ được cấp; chưa phải dispatcher hay EA đầy đủ.

- `bot-cua-toi-3/tests/check-pending-submission.py`: prepare/original/mql5/compare,
  so332ca từ giá cơ sở đến đặt/thử lại/ghi bảng; các hàm con được cấp trả lời,
  giữ làm tròn thật; dùng `--build` ở mql5. Chưa là toàn chương trình chính.
- `bot-cua-toi-1/tests/check-management-router.py`: prepare/original/mql5/compare;
  --first-zero-ticket-changed chọn ngữ cảnh của bộ kiểm; hai manager được cấp trả lời.
- `bot-cua-toi-1/tests/check-position-management-flow.py`: --trade-children chạy thân
  hàm con; --first-zero-ticket-changed chọn ngữ cảnh riêng, --router-caller chạy
  nơi gọi theo lần nhận giá qua các thân quản lý thật. Chưa là EA.
- `bot-cua-toi-3/tests/check-preparation-full.py`: prepare/original/mql5/compare,
  dùng1.016ca thường và76giá trị, không nuốt18ca lỗi vào kết quả thường.
- `bot-cua-toi-3/tests/check-preparation-errors.py RUN --build BUILD`:18ca chia0,
  kiểm lớp lỗi và không có kết quả thường, chưa so mọi trạng thái trước lỗi.
- `bot-cua-toi-3/tests/check-runtime-profile.py`: prepare/original/mql5/compare,
  2.106 ca nạp 9 cấu hình, hạt giống và điều chỉnh; so toàn bộ 33 giá trị
  theo từng bit và kiểm trường ngoài phạm vi. Chỉ là khối trước EA, chưa là toàn bot.
- `bot-cua-toi-1/tests/check-runtime-profile.py`: prepare/original/mql5/compare,
  432 ca nạp 8 cấu hình, hai HL, hạt giống, NaN/vô cực và bốn ô điều chỉnh; so từng bit.
- `bot-cua-toi-1/tests/check-preparation-full.py`: prepare/original/mql5/compare,
  1.060 ca/87 giá trị từ thân chuẩn bị đầy đủ; gồm lỗi dịch vụ, mảng mẫu khác nhau,
  NaN/vô cực và thứ tự gọi. `--build` chọn bản Script đã biên dịch.
- `bot-cua-toi-1/tests/check-preparation-errors.py RUN --build BUILD`: 10 ca chia 0,
  hai ca mảng ngắn; so loại lỗi và không ghi kết quả bình thường, chưa so đủ
  trạng thái trước lỗi. Dùng MT5 riêng và dự án bật kiểm chia 0.
- `bot-cua-toi-3/tests/probe-division-behavior.py RUN --build BUILD`: đo6ca chia
  trong MT5riêng. `bien-dich.ps1 -CheckFloatingPointDividers` tạo dự án bật
  fpzerocheck1 và giữSHA; chỉ dùng khi bằng chứng gốc yêu cầu cách dừng này.
- `chay-chup-bot-1-3.py`/`chup-bot-1-3.py`/`tao-ho-so-ma-chup.py` nhận thêmbot2;
  giữ kiểmPID/đườngdẫn/mãbăm, bản gốc đãcàiSHA390d8..., không sửaEX5/khóa.
- `xuat-ma-co-du-lieu.ps1 -Bot N -Metadata ... -Ghidra ... -Java ... -Run ...`
  xuất C từ bản chụp/metadata đã kiểm; giữ lỗi từng hàm, không xem C làMQL5.
  Thư mục dự án Ghidra không được chứa thành phần bắt đầu dấu chấm.
