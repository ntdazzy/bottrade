# Quy trình phục hồi bot

Chủ dự án xác nhận toàn bộ bot là của mình, mất mã nguồn khi đổi máy;
cho phép dịch ngược và viết lại toàn bộ theo [AGENTS.md](../AGENTS.md).
Mục tiêu: phục hồi 100% chức năng bằng nguồn MQL5 đầy đủ, tạo được EX5
từ nguồn và chạy trực tiếp trên MT5 như bot gốc, có bằng chứng đối chiếu.
Tập trung hoàn thiện Twister trước; phần chưa kiểm không được gọi là đạt 100%.
Không gỡ giới hạn dùng thử hoặc khóa bản quyền; phần đó cần bản cấp phép phù hợp.

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
Công cụ hỗ trợ được tạo ngay; bộ dịch nhiều bot chỉ làm sau khi Twister
hoàn chỉnh. Không tạo bộ khung lớn cho việc chỉ cần một lệnh ngắn.

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
