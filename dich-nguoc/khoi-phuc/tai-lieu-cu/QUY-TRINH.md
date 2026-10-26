# Quy trình phục hồi bot

Chủ dự án xác nhận toàn bộ bot là của mình, mất mã nguồn khi đổi máy;
cho phép dịch ngược và viết lại toàn bộ theo [AGENTS.md](../../../AGENTS.md).
Mục tiêu: phục hồi 100% chức năng bằng nguồn MQL5 đầy đủ, tạo được EX5
từ nguồn và chạy trực tiếp trên MT5 như bot gốc, có bằng chứng đối chiếu.
Ưu tiên hiện tại là bot 1 và bot 3; phân tích bot 2 song song theo yêu cầu ngày26/10/2026; phần chưa kiểm không được gọi là đạt 100%.
Không gỡ giới hạn dùng thử hoặc khóa bản quyền; phần đó cần bản cấp phép phù hợp.

## Luồng phân tích trước khi viết mã

Trước khi viết thêm chức năng, phải phân tích kỹ đúng EX5 gốc và lập
danh sách toàn bộ các phần tìm được: hàm, thuật toán/nhánh, tính năng,
đầu vào/cài đặt, chế độ, hiển thị, tài nguyên, trạng thái lưu, vòng đời
và lỗi. Mỗi mục cần vị trí gốc hoặc bằng chứng chạy; chỗ chưa rõ phải
ghi riêng để tiếp tục phân tích, không điền luật suy đoán.

Dùng một bảng chung nối phần cần phục hồi với bằng chứng, nguồn MQL5,
phép kiểm và việc còn thiếu. Sau đó mới làm lần lượt; không để việc đã
viết xong một phần che mất các phần khác. Giữ mã sạch, rõ và đúng hành
vi EX5, gồm kiểu số, thứ tự, làm tròn và tác dụng phụ.

Theo phân công hiện tại, Codex phân tích chứng cứ gốc, chốt thuật toán
và viết đặc tả. Claude nhận phần lớn việc viết mã/bộ kiểm theo đặc tả,
mục tiêu khoảng 95% phần thực hiện. Codex quản lý, chia phần, theo dõi,
tự đối chiếu với bot gốc và kiểm kết quả trước khi ghép.
Làm rõ ngày26/10/2026: cố gắng giao toàn bộ việc viết mã đã đủ mô tả
cho Claude; giao Claude lập bảng nối tất cả các khối nguồn hiện có,
giao diện, nơi gọi và dữ liệu truyền. Codex kiểm bảng nối trước khi
dùng để giao viết phần ghép tiếp theo; phần chưa rõ vẫn phải phân tích.
Cách giao việc được làm rõ ngày 25/10/2026: Codex phân tích bằng chứng
gốc trước và chốt mô tả từng chức năng, gồm công thức, điều kiện, kiểu
số, thứ tự và tác dụng phụ. Claude nhận mô tả cùng ngữ cảnh/mục tiêu
để viết từng phần; không phải tự phân tích EX5 thay bước này. Codex
kiểm mã rồi so với bản gốc. Cách viết mã có thể khác, logic xử lý phải
giữ nguyên; chỗ chưa rõ cần phân tích tiếp, không tự điền hoặc thêm luật.
Làm rõ mới nhất: giao Claude viết mã từ bản mô tả chức năng độc lập,
đủ giao diện, kiểu số, công thức, điều kiện, thứ tự đọc/ghi, làm tròn,
tác dụng phụ và đầu ra. Không giao Claude đọc EX5/mã máy hoặc tự bóc
tách thuật toán. Codex giữ chứng cứ gốc để kiểm, tự phân tích tiếp
mọi chỗ chưa rõ trước khi giao. Ngữ cảnh viết mã là chức năng MQL5
cụ thể; không bịa lý do, quyền sở hữu hay đổi tên phần đã bị từ chối.
Ngoại lệ được người dùng xác nhận ngày 25/10/2026: Codex trực tiếp làm
các phần Claude từ chối, gồm phân tích, viết mã và bộ kiểm; Claude làm
các phần còn nhận. Không đổi cách hỏi để vượt việc từ chối.
Ngày 26/10/2026, người dùng yêu cầu Codex tự viết tiếp khi Claude hết
hạn mức; không chờ dịch vụ mở lại. Quy tắc phân tích và đối chiếu giữ nguyên.
Giao từng phần rõ đầu vào/đầu ra và nêu đúng bối cảnh; không yêu cầu
vượt biện pháp bảo vệ. Bản đề xuất của Claude chưa phải kết quả đã đạt.
Khi đã ghép đủ, phải so toàn bộ bot và toàn bộ cài đặt/hiển thị, kể cả
khởi động lại, lưu trạng thái và lỗi. Chỉ hoàn thành khi không còn mục
bắt buộc bị bỏ hoặc sai khác chưa giải quyết. Số hàm đã chụp và số ca
kiểm đạt không được dùng thay cho bằng chứng đầy đủ của EX5.

## 1. Cấu trúc đầu ra

```text
bots/<ten-bot>/
├── README.md                         Trạng thái và bước tiếp
├── source/MQL5/
│   ├── Experts/<ten-bot>/<bot>.mq5    EA chính
│   ├── Include/<ten-bot>/*.mqh        Các phần dùng lại
│   └── Scripts/<ten-bot>/*.mq5        Kiểm tra/xuất dữ liệu khi cần
├── tests/                            Chương trình và ca kiểm
├── verification/<ten-luot>/          Bằng chứng đã lưu
└── analysis/                         Mã trung gian và ghi chú
```

Chỉ tạo thư mục có nội dung. Thêm `Indicators`, `Libraries`, `Files` khi
bot cần. Mỗi bot chỉ có một bộ nguồn hiện hành. EA bàn giao không dùng
EX5 gốc hoặc bộ mô phỏng để thực hiện luật; phụ thuộc gốc phải được ghi rõ.

Twister hiện còn để mã trực tiếp trong `source/`. Khi chuyển sang cấu
trúc chuẩn phải sửa đường dẫn nạp tệp, công cụ và phép kiểm cùng lượt; giữ bằng chứng cũ.

## 2. Các bước bắt buộc

| Bước | Làm gì | Kết quả cần có |
|---|---|---|
| 1. Chốt đầu vào | Đọc README bot, kiểm SHA-256 trong `catalog.json`, chọn đúng bản EA và `.set` | Danh sách tệp, phiên bản và chức năng phải phục hồi |
| 2. Thu bằng chứng | Đọc tệp/mã máy/dữ liệu; khi cần chạy thì dùng máy thử riêng | Bản chụp có mã kiểm tra, đúng tiến trình và trạng thái khởi tạo |
| 3. Xác định chức năng | Đối chiếu hàm, tham số, kiểu số, chuỗi và lời gọi MT5 bằng chương trình có nguồn | Bảng nối vị trí gốc với chức năng; ghi rõ phần chưa biết |
| 4. Viết MQL5 | Phục hồi từng phần rồi ghép đúng thứ tự các sự kiện | Mã thật; không hàm rỗng hoặc luật tự đoán |
| 5. Kiểm từng phần | Biên dịch, so với dữ liệu/lệnh máy gốc | Ca thường, sát ngưỡng, thiếu dữ liệu và lỗi đều có kết quả |
| 6. So trong MT5 | Chạy hai bản cùng dữ liệu và điều kiện | So từng lệnh theo thứ tự; ghi khác biệt đầu tiên và kiểm lại sau sửa |
| 7. Kiểm phần còn lại | Giao diện, lịch tin, khởi động lại, lưu trạng thái và các nhánh ngoài máy thử | Bằng chứng riêng; xem ảnh thật nếu có giao diện |
| 8. Bàn giao | Biên dịch từ bản nguồn sạch, đóng gói tài nguyên, cập nhật README bot | Nguồn MQL5 chuẩn, bản EX5 đúng nguồn, hướng dẫn và kết quả kiểm |

Thứ tự phục hồi: tham số → khởi tạo → dữ liệu → điều kiện mua/bán → khối
lượng → đặt/sửa/xóa lệnh → sau khớp → lịch tin/giao diện → xử lý lỗi.

## 3. Viết mã và kiểm đúng

- Giữ phép so sánh, đơn vị, kiểu số, làm tròn và thứ tự cập nhật của bản gốc.
- Giữ tên gốc khi biết; tên phục dựng ghi rõ. Mã C trung gian chưa phải nguồn MQL5.
- Không tự tối ưu lợi nhuận, sửa hành vi lạ hoặc thêm/bớt luật trong lúc phục hồi.
- Biên dịch hướng tới 0 lỗi, 0 cảnh báo; phải xử lý hoặc giải thích cảnh báo trước bàn giao.
- Kết quả mong đợi lấy từ bản gốc, không lấy từ chính mã mới để tự chứng minh.
- Hai bản dùng cùng mã giá, dữ liệu, kỳ, khung, tham số, cách tạo giá, vốn, phí và điều kiện khớp.
- So thời điểm, hướng, giá, khối lượng, dừng/chốt và mọi lần đặt/khớp/sửa/hủy/hết hạn/đóng; cùng tổng tiền chưa đủ.
- Khi đã có EA chính đầy đủ, chạy bản gốc và bản dựng lại song song
  trong hai môi trường MT5 kiểm thử riêng, dùng cùng dữ liệu và cài
  đặt. So đầy đủ kết quả theo thứ tự; mọi mục bắt buộc phải khớp mới
  đạt. Kiểm từng hàm trước đó không được gọi là đã chạy cặp toàn bot.
- Kiểm các chế độ, tham số, ngày/nến mới, không vào lệnh, mất dữ liệu, khởi động lại và lỗi.
- Có sai số thì giải thích nguồn và ảnh hưởng; không nới sai số để giấu lệch.
- Mỗi lượt lưu lệnh chạy, phiên bản công cụ, mã nguồn/EX5/dữ liệu, nhật ký, kết quả và giới hạn. Không sửa bằng chứng cũ.
- Chỉ chuyển sang chạy chính thức sau khi EX5 được biên dịch từ MQL5 của chủ dự án và đã kiểm riêng trên tài khoản được phép. Bỏ giới hạn máy thử bằng sửa source, không sửa trực tiếp EX5.

## 4. Dùng công cụ để tiết kiệm quota

1. Đọc [danh mục công cụ](tools/README.md), dùng công cụ phù hợp đang có.
2. Thao tác lặp từ lần thứ hai, dễ nhầm hoặc tốn nhiều token: tạo công cụ nhỏ thay phần thủ công, ưu tiên mở rộng công cụ cũ.
3. Công cụ phải có đầu vào/đầu ra, phạm vi đường dẫn, lỗi rõ, ví dụ lệnh và kiểm hoạt động thật; không ghi đè kết quả cũ.
4. Đăng ký cách dùng trong danh mục; các lượt sau bắt buộc gọi lại.
5. Dùng lại bằng chứng còn đúng mã tệp và điều kiện. Chỉ đọc tóm tắt/chỗ lệch thay vì đổ cả tệp lớn vào chat.

Công cụ chung ở `tools/`, phép kiểm riêng ở `bots/<ten-bot>/tests/`.
Công cụ hỗ trợ được tạo ngay khi cần cho phần đang phân tích. Không mở
rộng thành bộ dịch nhiều bot hoặc tạo bộ khung lớn ngoài phạm vi đang làm.

## 5. Khi nào được coi là hoàn thành

- Đủ chức năng, tài nguyên và cấu trúc MQL5 chuẩn; biên dịch sạch từ nguồn.
- Chạy trực tiếp trên MT5, có bằng chứng đối chiếu giao dịch, vòng đời, trạng thái, giao diện và lỗi.
- Không còn phần bị bỏ, nhánh chưa rõ hoặc khác biệt chưa giải quyết.
- Bản nguồn bàn giao đúng bản đã kiểm; README ghi cách lặp lại và giới hạn kiểm chứng.

“100% ca đã kiểm” phải nêu rõ bộ ca, không phải bằng chứng cho mọi đầu
vào có thể có. Tên biến chưa biết được báo riêng. Còn thiếu thì tiếp tục
làm, không hạ mục tiêu thành “gần giống” hoặc chuyển sang bot khác.

## 6. Cách viết tài liệu và báo cáo

- Viết ngắn, tiếng Việt dễ hiểu; tránh thuật ngữ khó, giải thích khi buộc dùng.
- Ưu tiên bảng “phần đã làm | kết quả và phạm vi | còn thiếu/bước tiếp”.
- Dùng số đã kiểm và hình khi có ích. Bằng chứng chi tiết để trong tệp có liên kết.
- Không chép nhật ký dài, mã máy hoặc nội dung lặp vào báo cáo cho người dùng.
