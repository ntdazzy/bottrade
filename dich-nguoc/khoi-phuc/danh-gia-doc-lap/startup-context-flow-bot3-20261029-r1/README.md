# Nối ngữ cảnh, chuẩn bị và đuôi — bot 3

`Bot3StartupContextFlow.mqh` gọi tạo trạng thái ban đầu rồi chuẩn bị
và phần khởi động còn lại, cùng các đối tượng dữ liệu. Mã gốc chạy
liên tục từ `0x3ce6` tới trả về tại `0x5f34`, nền `0x17156250000`.

| Phần | Bằng chứng/nguồn | Kiểm trong phần nối | Kết quả/còn thiếu |
|---|---|---|---|
| Mã nhận diện | `0x1d6ff0 → 0x6d564` | Dùng trực tiếp `ContextInputs.base_magic` và `Context.magic` | Khớp, không giữ thêm bản rời |
| Bình luận | `0x1d6ff8 → 0x6d568`; chuẩn bị `0x6d308 → 0x6d578` | Giữ riêng bốn vùng gốc/đầu ra, kể cả NULL/rỗng/UTF-16 | Khớp |
| Mã giá và đuôi | `0x1d6e28 → 0x74958`, đuôi `0x6d230` | Đổi mã dùng chung trước chuẩn bị; tìm đuôi theo đúng nhánh | Khớp |
| Ngày/lịch sử/bảng | `Bot3StartupContext` và các trường trong công cụ | So số thường, cờ, NaN/vô cực; bốn phép nhân CPU | Khớp |
| Chuẩn bị và đuôi | `0x4580..0x5f34`, thân chuẩn bị `0xe0c0` | Không đặt lại dữ liệu tại các điểm nối | Khớp; hai thân tìm mức và ba thân bảng được thay bằng bộ ghi |

Lượt `b3-startup-context-flow-20261029-r1`: **531/531 ca khớp từng
byte**, 248 trường, dãy chỉ báo và 2.800 ô. Có 28.885 lần gọi,
29.936 phép tính CPU; mỗi ca qua điểm nối đuôi đúng một lần.
Nguồn kiểm và bộ ghép `b3-all-headers-api-20261029-r6` biên dịch
0 lỗi, 0 cảnh báo; bộ ghép chứa đủ 113 tệp `.mqh`.

## Giới hạn

Vùng trả chuỗi từ phần trước được nạp trước; cấp phát chuỗi thành
công và phản hồi dịch vụ được cấp. Không yêu cầu giá trị có sẵn
của thanh ghi XMM6; đoạn gốc tự tạo giá trị cần dùng. Không chạy
quyền dùng; bộ chặn các điểm bảo vệ vẫn được giữ.

Chưa nối đoạn đổi giờ/chọn tần suất `0x3840..0x3ce6`, phần tài khoản/
lịch tin phía trước, các thân tìm mức/bảng, toàn trạng thái tại lỗi
hoặc EA đầy đủ. Không dùng số ca này làm tỷ lệ hoàn thành toàn bot.

Chạy lại `cong-cu/kiem-noi-ngu-canh-khoi-dong-bot-3.py`: `generate`,
`prepare RUN`, `mql5 RUN --build BUILD`, `original RUN`, `compare RUN`.
Dùng tên lượt mới, MT5 bot 3 riêng; MQL5 chạy trước mã máy gốc.

[Số liệu/địa chỉ](verification.json), [danh sách tệp](../startup-context-flow-bot3-20261029-r1-manifest.txt).
