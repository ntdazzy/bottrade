# Kiểm tra tệp EX5 và Markdown — 22/10/2026

## Mục tiêu và phạm vi đã kiểm

- Repository `ntdazzy/bottrade`: **17 EX5 bot gốc**, 7 EX5 công cụ/kiểm thử, và **36 tài liệu Markdown** trên nhánh PR trước khi chỉnh sửa báo cáo này.
- Đã đối chiếu danh sách, đường dẫn, kích thước EX5; kiểm tra metadata có thể đọc trong phần đầu 15/17 tệp gốc. Hai tệp lớn `MoonDog EA.ex5` và `My AI Gold.ex5` không trả dữ liệu qua API tải nội dung hiện tại; không tuyên bố đã quét lại hai bản này.
- Đã đọc và tìm các cụm tên tác giả, bản quyền, Market, Demo, Trial, nguồn và liên kết trong **36 Markdown**. Các bản ghi phân tích lịch sử được giữ lại để không đánh mất thông tin kiểm chứng.
- **Không chỉnh byte EX5, không sửa source MQL5, không gỡ Demo/Trial và không thử MT5 ở lượt này.**

## Metadata có thể quan sát trong EX5

| Bot | Giá trị hiển thị trong metadata/chuỗi đầu tệp | Trạng thái kiểm tra |
|---|---|---|
| AI Golden Life MT5 | `MQL BLUE` / `mqlblue.com` | Đọc trực tiếp |
| CryonX EA MT5 | `Copyright 2023, MetaQuotes Ltd.` / `mql5.com` | Đọc trực tiếp |
| Dynamic Liquidity Intelligence | `Sathit Sukhirun` / tài khoản `nicedata` | Đọc trực tiếp |
| EA Super Trend XAUUSD | `Trading Systems EA Quantum Lab` / `t.me/EAQuantumLab` | Đọc trực tiếp |
| Gold Beaver | `2026, Arnold Bobrinskii` | Đọc trực tiếp |
| Gold Trade Pro MT5 | `Copyright 2023 - Wim Schrynemakers` | Đọc trực tiếp |
| Goldbot One MT5 | `Copyright 2024 - Wim Schrynemakers` | Đọc trực tiếp |
| MoonDog EA | Không xác minh được lại qua API; báo cáo cũ ghi không tìm thấy chuỗi Latin đáng kể | Chưa xác minh trực tiếp |
| My AI Gold | Báo cáo lịch sử ghi `Vitalii Kosov` | Chưa xác minh trực tiếp |
| Quantum Queen X MT5 | `Click here to contact the author.` / tài khoản `weredeu` | Đọc trực tiếp |
| Quantum Titan MT5 (2 bản) | `Click here to contact the author.` / tài khoản `weredeu` | Đọc trực tiếp |
| Scalping Robot Pro MT5 | `MQL BLUE` / `mqlblue.com` | Đọc trực tiếp |
| The Gold Reaper MT5 | `Copyright 2024 - Wim Schrynemakers` | Đọc trực tiếp |
| TwisterPro Scalper | `Copyright 2026, Twister Pro Systems` / `mql5.com` | Đọc trực tiếp |
| Ultimate Breakout System (2 bản) | `Copyright 2026 - Profalgo LTD` / `forexeasolutions.com` | Đọc trực tiếp |

Những chuỗi trên là dữ liệu *trong EX5*, không phải bằng chứng độc lập về quyền sở hữu trí tuệ hay cơ chế cấp phép. Kết quả quét chuỗi không xác định được có hay không giới hạn chạy thử bên trong chương trình đã biên dịch.

## Kiểm tra toàn bộ Markdown

| Nhóm | Kết quả |
|---|---|
| README gốc và tài liệu hướng dẫn agent | Tên dự án `Bot Market Demo` xuất hiện trong tiêu đề; đổi **nhãn dự án** thành `NTdazzy — BotTrade EX5` ở các tài liệu giới thiệu, không sửa dữ liệu lịch sử |
| `dich-nguoc/docs/history/KIEM-TRA-DICH-NGUOC.md` | Có danh sách metadata, tên tác giả và trang web trước đây (mục `Thông tin đọc được ở đầu tệp`). **Giữ lại vì đây là bản ghi bằng chứng** |
| `bao-cao/KET-QUA-2025-2026.md`, `bao-cao/KET-QUA-3-TUAN.md` | Có nhắc `của tác giả`, liên hệ tài khoản tín hiệu và số liệu kiểm thử; là kết quả đối chiếu, không phải đoạn mô tả phát hành |
| `dich-nguoc/docs/history/MUC-TIEU-TRUOC-KHI-CHUYEN.md` và `docs/history/DOI-CHIEU.md` | Có các đường dẫn máy thử `Experts/Market`, phiên Demo và ghi chép nguồn phân tích; xóa mù có thể phá chứng cứ và quy trình tái lập |
| `README` của từng bot (15 file) | **Đã sửa** các liên kết tới EX5 chứa dấu cách bằng `%20` để đường dẫn Markdown ổn định; nội dung khác và checksum EX5 giữ nguyên |
| `DOC-TRUOC.md` | Hiện là file rỗng, nhưng trước đây từng được README dẫn tới; cần cân nhắc xóa liên kết hoặc thêm nội dung thật |
| Tài liệu phục dựng Twister / tools | Mô tả mã nguồn thử nghiệm, lời gọi MT5 và hạn chế chạy thực tế. Nếu xóa source, tài liệu sẽ cần đồng bộ để tránh liên kết hỏng |

Đã rà soát **36/36 Markdown** về các từ khóa liên quan và sửa liên kết có dấu cách trong **15 README của bot**. Đây là kiểm tra nội dung tĩnh, chưa thử render tất cả liên kết trong giao diện GitHub.

## Những gì đã chỉnh để phát hành rõ ràng

- README giới thiệu repository như nơi lưu trữ EX5 do NTdazzy phát hành; tài liệu [PHAT-HANH-MIEN-PHI.md](PHAT-HANH-MIEN-PHI.md) dẫn tới 17 `.NOTICE.txt` đi kèm.
- Tệp [LICENSE](LICENSE) chỉ cho phép sử dụng, chia sẻ, nghiên cứu, dịch ngược, sửa đổi **đối với nội dung mà NTdazzy có quyền cấp phép**.
- Loại toàn bộ khác biệt với `main` trong file MQL5 đã sửa ở PR trước; không đụng tới EX5 gốc hoặc các bản kiểm thử.

## Giới hạn, những điều không nên khẳng định

1. Thông tin Author/Copyright/Description **trong EX5 chưa được thay đổi**. Tệp `.NOTICE.txt` không làm thay đổi màn hình Properties trong MetaTrader 5.
2. Không thể hứa rằng file EX5 cũ chạy miễn phí, không có Demo/Trial hoặc không cần kích hoạt chỉ vì viết giấy phép kèm theo.
3. Việc xóa dòng tên tác giả khỏi README không xóa dữ liệu nhúng EX5 hay lịch sử Git; cũng không tự chuyển quyền tác giả. Giữ các ghi nhận nguồn gốc và bản quyền bên thứ ba.
4. Nếu định xóa thư mục source/analysis/verification, trước tiên lưu bản sao và cập nhật các liên kết Markdown, công cụ và biên nhận kiểm thử tương ứng. Không có thao tác xóa nào được thực hiện trong PR này.

## Bước kiểm thử để hoàn tất việc thay metadata

Chỉ thay Author/Description nhúng một cách có kiểm soát khi có source có quyền sử dụng hợp lệ; biên dịch lại bằng MetaEditor, kiểm tra thuộc tính hiển thị, kiểm tra SHA-256 file mới và chạy Strategy Tester trên tài khoản thử. Mọi khác biệt phải được ghi nhận thay vì tuyên bố là bản gốc đã đổi tác giả.
