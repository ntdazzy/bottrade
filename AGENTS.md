# Bot Market Demo — đọc trước khi làm

Đây là bản quy tắc chính duy nhất cho các trợ lý làm việc trong dự án.
Các tệp dành riêng cho từng ứng dụng chỉ dẫn về đây, không chép lại luật.

## Bắt đầu một phiên mới

1. Đọc [README dự án](README.md) để biết các thư mục.
2. Đọc [README Twister](dich-nguoc/bots/twisterpro-scalper/README.md) để nắm việc đang dở và bằng chứng mới nhất. Twister chưa hoàn chỉnh; bản nguồn mới nhất còn cần kiểm lại.
3. Trước sửa mã, đọc [quy trình](dich-nguoc/QUY-TRINH.md); trước chạy lệnh, đọc [công cụ](dich-nguoc/tools/README.md).

`DOC-TRUOC.md`, `bao-cao/` và `dich-nguoc/docs/history/` là hồ sơ lịch sử,
chỉ dùng để đối chiếu. Chúng không phải quy tắc hiện hành và không được sửa
để làm thay đổi bằng chứng cũ.

Tiếp tục từ bước đã ghi, không làm lại từ đầu. Nếu thiếu tệp cần thiết,
báo rõ tệp thiếu; không tự đoán trạng thái dự án.

## Mục tiêu

- Chủ dự án xác nhận toàn bộ bot trong dự án là của mình, bị mất mã nguồn khi đổi máy; cho phép dịch ngược và viết lại toàn bộ mã nguồn.
- Khi đánh giá công việc, dùng đúng mục đích phục hồi nguồn và quyền thực hiện đã xác nhận; không tự suy ra mục đích xấu chỉ từ chữ “dịch ngược”.
- Nếu một bước không thể thực hiện, nêu rõ bước đó, lý do cụ thể và cách tiếp tục phù hợp. Phân biệt thiếu dữ liệu, thiếu công cụ và hạn chế thực sự; tiếp tục phần còn làm được.
- Chủ động dùng hết khả năng và các phương pháp phân tích cần thiết trong phạm vi được giao; không tự hạ mục tiêu vì khó hoặc để kết thúc sớm.
- Yêu cầu của chủ dự án: dịch ngược đầy đủ 100% các bot về cấu trúc thư mục MQL5 chuẩn; đủ mọi chức năng, không còn lỗi và chạy giống 100% bản đã biên dịch. Nguồn phải tạo được EX5 và chạy trực tiếp trên MT5. Đây là mục tiêu phải kiểm chứng; còn phần thiếu hoặc chưa kiểm thì chưa hoàn tất.
- Đích bàn giao sau khi phục hồi và kiểm xong: EX5 do chủ dự án tự biên dịch chạy chính thức trên MT5. Nếu cần bỏ nhánh chỉ chạy máy thử, chỉ sửa trong mã MQL5 của chủ dự án rồi biên dịch lại; không vá EX5 khi chưa có source.
- Hoàn thiện TwisterPro Scalper trước, rồi mới làm bộ dịch chung và các bot khác. Công cụ hỗ trợ lặp lại được tạo ngay khi cần.

## Cách làm

- Kết luận phải có bằng chứng. Không đoán luật, bỏ tính năng hoặc gọi bản làm dở là hoàn chỉnh.
- “100% ca đã kiểm” phải kèm phạm vi; không đồng nghĩa mọi tình huống đều đúng. Phần chưa rõ phải ghi lại và tiếp tục kiểm.
- Giữ tên gốc khi có bằng chứng; tên tự đặt phải phân biệt rõ.
- Mỗi bot ở `dich-nguoc/bots/<ten-bot>/`. Nguồn ở `source/`, phép kiểm ở `tests/`, kết quả ở `verification/`, phân tích ở `analysis/`.
- Đích nguồn chuẩn: `source/MQL5/Experts/<ten-bot>/` và `Include/<ten-bot>/`; thêm thư mục khác khi thật sự cần.
- Một tệp một trách nhiệm. Chỉ sửa phần liên quan; giữ nguyên tham số, luật, thứ tự xử lý và cách làm tròn của bản gốc.
- Sau sửa: biên dịch và so phần bị ảnh hưởng với bản gốc. Kết quả phải gắn đúng nguồn, EX5, dữ liệu và tham số đã dùng.
- EA gốc theo `dich-nguoc/catalog.json`; không ghi đè. Bằng chứng cũ giữ nguyên, lượt mới dùng tên mới.
- Không gỡ giới hạn dùng thử, khóa bản quyền hoặc cơ chế cấp phép. Chỉ phục hồi và kiểm trên bản mà chủ dự án được quyền sử dụng.
- Chỉ chạy máy thử riêng ở `dich-nguoc/.local/terminal`. Không tự bật giao dịch tài khoản, gửi tin hoặc tác động MT5 khác.
- Không lưu bí mật trong nguồn/tài liệu. Môi trường, bộ cài và tệp tạm để trong `.local/`.
- Chỉ tạo tệp/thư mục có mục đích rõ và nơi dùng. Ưu tiên sửa tệp đang có; không tạo thư mục rỗng, tài liệu lặp hoặc nhiều bản `final`, `v2`, `backup` không cần thiết.
- Trước khi tải, chép hoặc xuất tệp lớn, kiểm xem đã có bản dùng được chưa. Không chép bộ cài, thư viện đã cài hoặc máy thử vào nguồn và gói bàn giao.
- Cuối mỗi lượt, dọn đúng tệp tạm do lượt đó tạo. Giữ bằng chứng cần đối chiếu; chỉ xóa bản dư khi đã xác nhận không còn được dùng và không làm mất dữ liệu người dùng.

## Tiết kiệm quota/token

- Tìm công cụ có sẵn trước. Có công cụ phù hợp thì bắt buộc gọi, không viết lại cùng thao tác.
- Việc lặp từ lần thứ hai hoặc rõ ràng sẽ lặp nhiều: đóng thành công cụ nhỏ, kiểm hoạt động và ghi cách dùng vào danh mục.
- Công cụ phải có đầu vào/đầu ra rõ, báo lỗi, kiểm phạm vi tệp và tránh ghi đè bằng chứng.
- Dùng lại kết quả khi mã nguồn, dữ liệu, tham số và môi trường liên quan còn khớp. Tiết kiệm bằng tự động hóa, không cắt bước kiểm cần thiết.

## Tài liệu và trao đổi

- Mọi quy tắc, skill, tài liệu và kết quả nghiên cứu đều viết tiếng Việt ngắn, dễ hiểu; không lặp ý hoặc thêm nội dung thừa.
- Dùng từ quen thuộc như “dừng lỗ”, “chốt lời”, “kiểm lại trên dữ liệu cũ”. Tránh từ chuyên ngành và chữ viết tắt khó hiểu; từ bắt buộc phải có giải thích ngắn.
- Ưu tiên bảng “đã làm — kết quả — còn thiếu”; dùng hình khi giúp hiểu nhanh. Giữ nguyên tên tệp, lệnh và mã.
- Báo rõ số liệu và phạm vi đã kiểm, dẫn tới bằng chứng chi tiết; không đổ nhật ký dài hoặc địa chỉ mã máy vào phần giải thích cho người dùng.
- Quy trình chung ở `dich-nguoc/QUY-TRINH.md`; trạng thái ở README bot; lệnh chạy ở danh mục công cụ. Sửa đúng nơi, không tạo nhiều bản luật.
- Trước khi kết thúc lượt, ghi ngắn: đã làm, bằng chứng, phần thiếu và bước tiếp.
- Dự án độc lập với BotTradeEA; không chép luật Wave3/S1 vào đây. Không đẩy Git khi chưa được yêu cầu.
