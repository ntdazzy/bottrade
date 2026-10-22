# Bot Market Demo

Chủ dự án xác nhận toàn bộ bot ở đây là của mình, bị mất mã nguồn khi
đổi máy và cho phép dịch ngược, viết lại toàn bộ mã nguồn.
Mục tiêu: phục hồi 100% chức năng, ưu tiên giữ tên gốc; bàn giao thư mục
MQL5 chuẩn, tạo được EX5 từ nguồn và chạy trực tiếp trên MT5 như bot gốc.
Kết quả phải được đối chiếu và kiểm chứng trước khi xác nhận hoàn tất.
Sau khi phục hồi và kiểm xong, bản EX5 tự biên dịch sẽ chạy chính thức trên
MT5. Nếu source có nhánh chỉ dành cho máy thử, sửa nhánh đó trong MQL5 rồi
biên dịch lại; không sửa trực tiếp EX5.

**Đang tập trung: [TwisterPro Scalper](dich-nguoc/bots/twisterpro-scalper/README.md).**
Chưa xác nhận giống hoàn toàn; chưa làm công cụ dịch các bot khác.

| Cần xem gì | Mở ở đâu |
|---|---|
| Quy tắc bắt buộc cho người và trợ lý làm việc | [AGENTS.md](AGENTS.md) |
| Quy trình dịch ngược, cấu trúc MQL5 và tiêu chí hoàn thành | [QUY-TRINH.md](dich-nguoc/QUY-TRINH.md) |
| Hồ sơ cũ và cách phân nhóm (chỉ tham khảo) | [DOC-TRUOC.md](DOC-TRUOC.md) |
| Danh sách các bot đang nghiên cứu | [dich-nguoc/README.md](dich-nguoc/README.md) |
| Mã MQL5 của Twister | [source](dich-nguoc/bots/twisterpro-scalper/source) |
| Kết quả so với bot gốc | [verification](dich-nguoc/bots/twisterpro-scalper/verification) |
| Cách chạy công cụ | [tools/README.md](dich-nguoc/tools/README.md) |

```text
Bot Market Demo/
├── README.md                  Bắt đầu tại đây
├── AGENTS.md                  Quy tắc làm việc của dự án này
├── DOC-TRUOC.md               Hướng dẫn EA đã có
├── 1-dang-tin-nhat/           EA gốc, giữ cách chia nhóm hiện tại
├── 2-co-loi/
├── 3-so-ao-luot-nhanh/
├── 4-loai/
├── bao-cao/                  Báo cáo đã có
└── dich-nguoc/
    ├── README.md             Danh sách và trạng thái các bot
    ├── QUY-TRINH.md          Quy trình phục hồi và kiểm chứng
    ├── catalog.json          Đường dẫn và mã kiểm tra 17 tệp EA gốc
    ├── bots/
    │   └── <ten-bot>/
    │       ├── README.md     Trạng thái, việc đã kiểm, phần còn thiếu
    │       ├── source/       MQL5 đang làm, khi đã có mã
    │       ├── tests/        Chương trình kiểm tra riêng của bot
    │       ├── verification/ Dữ liệu và bằng chứng các lượt kiểm
    │       └── analysis/     Mã trung gian và ghi chú phân tích
    ├── tools/                Công cụ dùng chung
    ├── requirements.txt      Thư viện Python cần cài khi phân tích
    └── docs/                 Biên nhận chuyển, môi trường, lịch sử
```

Mỗi bot có một thư mục cố định. Chỉ tạo `source`, `tests`, `verification`
khi có nội dung; không tạo cây thư mục rỗng cho các bot chưa làm tới.
EA gốc nằm một nơi; các hồ sơ dịch ngược dẫn tới EA đó qua `catalog.json`.

Đầu ra chuẩn là `source/MQL5/Experts/<ten-bot>/`,
`source/MQL5/Include/<ten-bot>/` và các thư mục hỗ trợ cần thiết.
Twister hiện vẫn dùng các tệp trực tiếp trong `source/`; công cụ đang
theo cách đó. Khi chuyển sang cấu trúc chuẩn phải sửa công cụ và kiểm lại
cùng lượt; xem quy trình để phân biệt trạng thái hiện tại với đích bàn giao.

Các bước lặp lại phải được đóng thành công cụ và gọi lại để tiết kiệm
quota/token. Tiết kiệm bằng dùng lại kết quả còn hợp lệ và tự động hóa,
không cắt bớt việc phục hồi hoặc kiểm tra.

MT5, Ghidra, JDK, bộ cài, dữ liệu tài khoản và tệp tạm không nằm trong hồ
sơ được chuyển. Khi cần chạy lại, chuẩn bị môi trường cục bộ theo hướng
dẫn công cụ. Không bật giao dịch trên biểu đồ hoặc tài khoản.

## Mở bằng trợ lý khác

Mở đúng thư mục `Bot Market Demo`. Chỉ sửa luật tại [AGENTS.md](AGENTS.md).

| Ứng dụng | Cách đọc bản quy tắc chung |
|---|---|
| [Codex](https://learn.chatgpt.com/docs/agent-configuration/agents-md), [Cursor](https://cursor.com/docs/rules) | Đọc `AGENTS.md` |
| [Claude Code](https://code.claude.com/docs/en/memory) | `CLAUDE.md` nạp `AGENTS.md` |
| [Gemini CLI](https://geminicli.com/docs/cli/gemini-md/) | `GEMINI.md` nạp `AGENTS.md` |
| [GitHub Copilot](https://docs.github.com/en/copilot/how-tos/configure-custom-instructions/add-repository-instructions) | `.github/copilot-instructions.md` yêu cầu đọc `AGENTS.md` |

Việc tự đọc còn phụ thuộc phiên bản và cài đặt ứng dụng. Với trợ lý chưa
hỗ trợ, yêu cầu “Đọc AGENTS.md trước khi làm”. Chưa thử mở từng ứng dụng.
