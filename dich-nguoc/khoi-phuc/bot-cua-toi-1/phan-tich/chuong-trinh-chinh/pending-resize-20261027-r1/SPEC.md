# Bot1 — tạo lại lệnh chờ khi khối lượng thay đổi

Đặc tả Codex chốt từ evaluator18aa0..1ef9c, SHA
`45d53270186b7019a8721e0cf3734a61aac8e8660c70f7e602849b1c298d7cbd`.
Phạm vi sau lời gọi tính khối lượng: `1a817` đến điểm dọn chuỗi
`1b317` (các nhánh ghép thông báo có khối ngoài khoảng liên tục).
Không thay lời gọi tính khối lượng34780 bằng một công thức đoán; việc
ghép lời gọi đó và cổng phía trước là phần còn lại riêng.

## Hàm con có gửi lệnh

Native `32dd0..336c8`, SHA
`8d666c1808a0c8d2090eb04e957a383f26fd51f6a8bcee6edeb9d3875b0a7217`,
gọi950 tại3363d rồi trả bool. Nó CÓ GỬI. Comment của MQL5
`Bot1PreparePendingRequest` chỉ nói về phần đã tách trước ranh giới
gửi; không được dùng comment này để gọi cả thân native là không gửi.
Nguồn tương ứng đủ hành vi là `Bot1OpenPending` trong TradeSend.mqh.
Không giao riêng phần prepare thay cho open. Xóa34150 cũng dùng nguyên
`Bot1DeletePending`, không tự ghi trả lời của hàm con trong mã bàn giao.

## Nguồn và đầu vào

Tạo `Bot1EvaluationPendingResize.mqh`, include `Bot1OrderCancel.mqh`.
Hàm `Bot1ResizeEvaluationPending(const int &strategy_magic,
const uchar &virtual_expiration,const string &symbol,
const double &change_percent,const double &volumes[],
const uint &strategy_index,ulong &last_ticket,double &results[][2],
Bot1PendingRequestState &trade,Bot1TradeSendOptions &options)`.
Các biến tham chiếu đều là dữ liệu sống, không chép trước vòng.
Bảng100x2 là cùng bảng65dd0 đã có; volumes là mảng8ô66a80,
strategy_index là global678f4; last_ticket là global677f8.

1. Lấy OrdersTotal đúng1lần, duyệt từ **total đến0**, gồm cả hai đầu.
   Total<0 thì bỏ cả vòng; total=0 vẫn đọc vé index0. Không sửa thành
   total-1 dù cách đó trông hợp lý hơn.
2. Mỗi lần OrderGetTicket(index) ghi thẳng last_ticket, kể cả0.
   Vé0 bỏ. Đọc OrderGetInteger15, so64bit với strategy_magic32bit có dấu.
   Đọc OrderGetString0, so đủ nội dung/NULL với symbol.
3. Đọc OrderGetInteger4: nếu bằng4 đúng64bit, chạy bước mua dưới đây.
   Sau nhánh này LUÔN đọc lại OrderGetInteger4, nếu bằng5 chạy bước bán.
   Không dùng else-if hoặc giữ loại từ lần đầu; dữ liệu có thể đã đổi
   sau hàm xóa/gửi. Vé/mã/tên lọc ngoài không đọc lại sau nhánh mua.
4. Mỗi nhánh trước hết đọc OrderGetDouble7. Nếu bằng
   volumes[strategy_index] thì bỏ nhánh; NaN làm so bằng thất bại.
5. Khi khác: đọc OrderGetDouble12 giữ sl; NGAY SAU lần đọc này lấy
   bản chụp vé từ last_ticket. Đọc OrderGetDouble13 giữ tp, rồi9 giữ
   price; OrderGetInteger2 giữ expiration; OrderGetString16 giữ comment.
   Giữ các dữ liệu này qua lời gọi xóa; không đọc lại từ lệnh sau xóa.
6. `Bot1DeletePending(trade,options,saved_ticket)`; bỏ bool kết quả.
   Đọc lại volume từ volumes[strategy_index], sao symbol hiện tại,
   dùng comment/sl/tp/price/expiration đã giữ để gọi Bot1OpenPending
   với loại4 hoặc5, strategy_magic và virtual_expiration hiện tại.
   Gọi tạo lại cả khi xóa trảfalse; không thêm luật chặn mới.
7. Dùng `(double)(int)saved_ticket` (int32có dấu, KHÁC kiểu của bước
   dọn lệnh chờ trước đó), quét100dòng. Dòng đầu có ô0 bằng giá trị đó
   thì ô0=(double)(uint)accepted; GIỮ ô1 và mọi dòng trùng sau.
8. In một đối số chuỗi:
   mua: `"lotsize changed more than "+(string)change_percent+
         "%... adjusting lotsize of pending orders"`;
   bán dùng chữ L hoa: `"Lotsize changed more than "...`.
   Sau đó Sleep1000, kể cả khi open trảfalse. Không điều kiện hóa in/chờ
   theo accepted. Rồi trở về bước3 để đọc lại loại nếu vừa xử lý mua.

Địa chỉ: tổng1a82b; vé1a902 (được đối chiếu trong bản raw cùng lượt); hai
nhánh xóa1ab1e/1afee, mở1ab9c/1b06c, bảng1abb0 và nhánh tương ứng bán;
thông báo1ae81/1a8a3, chờ1ae95/1a8b7. Thân xóa bot1 trảvoid, còn
bot3 trảbool; cả hai nơi gọi này đều bỏ giá trị trả về. Lượt kiểm phải
chạy đúng34150 thay vì dùng thân32450 của bot3.

## Cổng gọi phía trước còn riêng

Hiện tại còn phải nối đầu đánh giá/quản lý/hàme1b0, cờ phiên và điều
kiện vốn. Bot1 không có cờ người gọi DL của bot3. Nguyên factor là62528/100+1; so cả tăng
và giảm vốn trước34780, có nhánh dừng vì chia0. Không dùng phép so
của vòng này để chứng minh phần trước hoặc mọi SDK của tính khối lượng.

Phép kiểm vòng phải chạy nguyên các nhánh caller và thân xóa/open/gửi,
đọc đủ200ô bảng,35trường/4chuỗi, last_ticket và thứ tự/đối số dịch vụ.
Chỉ SDK/cấp chuỗi thành công được cấp; chuyển số thành chuỗi đo trong
MT5 rồi đối chiếu lời gọi/value gốc. Không gửi lệnh lên tài khoản thật,
không sửa EX5/cờ bản quyền. Chưa toànEA hoặc lỗi cấp bộ nhớ.
