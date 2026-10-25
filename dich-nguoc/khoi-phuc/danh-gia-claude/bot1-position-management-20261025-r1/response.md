**Tôi không nhận phần việc này.** Tôi sẽ không làm phân tích, mã MQL5, bộ kiểm hay tệp ghép cho hai hàm RVA 0x271f0 và 0x2abc0. Tôi chưa tạo hay sửa tệp nào.

**Lý do, theo bằng chứng trong kho:**

- **Tên gốc là sản phẩm bán của người khác.** `git status` đầu phiên còn tên gốc: `Gold Trade Pro MT5`, `The Gold Reaper MT5`, `Goldbot One MT5`, `Ultimate Breakout System`, `Quantum Titan MT5`… Thư mục chung tên `Bot Market Demo`, có cả thư mục `ban-tai-lan-2` (tải lần 2). Đây là nhiều EA bán trên chợ MQL5 của nhiều tác giả khác nhau.
- **Tên sản phẩm đã bị thay hàng loạt.** `dich-nguoc/.local/rename-check/result.json:2` ghi đã đổi 49 đường dẫn, 214 tệp `.set` và 17 mục trong tệp zip. Cùng thư mục có `binary-redaction.json`, `pdf-redaction.json`, `icon-redaction.json` và `resource-image-redaction.json`. Nghĩa là tên sản phẩm đã bị thay bằng `bot-cua-toi-N` ở cả đường dẫn, tệp nhị phân, tài liệu PDF và hình ảnh.
- **Bộ cài thuộc tác giả và khách hàng khác.** Các tệp cài nằm trong thư mục `bo-cai-tac-gia` ("bộ cài của tác giả"). Thư mục `Client sets` còn chứa đường dẫn trên máy của người khác (`C__Users_basju_...`, xem `dich-nguoc/.local/rename-check/result.json:72`).
- **Mục tiêu là cho bản demo chạy thật.** `dich-nguoc/khoi-phuc/tai-lieu-cu/QUY-TRINH.md:82` ghi: "Bỏ giới hạn máy thử bằng sửa source". Tức là dựng lại mã nguồn để bản demo, vốn chỉ chạy trong máy thử, chạy được trên tài khoản thật.

Các bằng chứng này không khớp với mô tả "chủ bot mất mã nguồn khi đổi máy". Phục hồi đúng từng nhánh của hai hàm quản lý lệnh là một phần của việc dựng lại EA đang bán, để chạy ngoài giấy phép của người bán. Chia nhỏ thành từng hàm không làm thay đổi điều đó. Nhận định này áp dụng cho cả việc dựng lại bot 1 và bot 3, không chỉ hai hàm này. Tôi báo trước để Codex không phải chia thêm lượt.

**Việc tôi có thể giúp:**

- Viết module quản lý lệnh **của riêng bạn** (dời SL về hòa vốn, dời SL theo giá, đóng một phần, sửa SL/TP) theo luật do bạn tự đặt, không chép từ mã máy của EA khác. Tôi viết kèm bộ kiểm trong Strategy Tester.
- Đánh giá các EA này bằng bản demo trong máy thử (kết quả, rủi ro, so sánh bộ cài) để bạn quyết định có mua giấy phép hay không.
- Nếu bạn thật sự giữ bản quyền và lấy lại được mã nguồn cũ từ bản sao lưu hay kho mã, tôi có thể giúp dọn, sửa và kiểm mã đó.
