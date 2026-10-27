# Bot3 — tạo lại lệnh chờ khi khối lượng thay đổi

Đặc tả Codex chốt từ evaluator20ef0..2a1bc, SHA
`6bead161fa97b6568b546e8c86a4ff03fdda55d6fb226a52b58dd14ec050d920`.
Phạm vi sau lời gọi tính khối lượng: `22a59` đến điểm dọn chuỗi
`235f7` (các nhánh ghép thông báo có khối ngoài khoảng liên tục).
Không thay lời gọi tính khối lượng3f900 bằng một công thức đoán; việc
ghép lời gọi đó và cổng phía trước là phần còn lại riêng.

## Hàm con có gửi lệnh

Native `3e580..3ee78`, SHA
`41038bbbec9179a3edada39d012b593d8c235fbd8276374929ec7714d4169418`,
gọi950 tại3eded rồi trả bool. Nó CÓ GỬI. Comment của MQL5
`Bot3PreparePendingRequest` chỉ nói về phần đã tách trước ranh giới
gửi; không được dùng comment này để gọi cả thân native là không gửi.
Nguồn tương ứng đủ hành vi là `Bot3OpenPending` trong TradeSend.mqh.
Không giao riêng phần prepare thay cho open. Xóa32450 cũng dùng nguyên
`Bot3DeletePending`, không tự ghi trả lời của hàm con trong mã bàn giao.

## Nguồn và đầu vào

Tạo `Bot3EvaluationPendingResize.mqh`, include `Bot3OrderCancel.mqh`.
Hàm `Bot3ResizeEvaluationPending(const int &strategy_magic,
const uchar &virtual_expiration,const string &symbol,
const double &change_percent,const double &volumes[],
const uint &strategy_index,ulong &last_ticket,double &results[][2],
Bot3PendingRequestState &trade,Bot3TradeSendOptions &options)`.
Các biến tham chiếu đều là dữ liệu sống, không chép trước vòng.
Bảng100x2 là cùng bảng72e10 đã có; volumes là mảng9ô73ac0,
strategy_index là global74934; last_ticket là global74838.

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
6. `Bot3DeletePending(trade,options,saved_ticket)`; bỏ bool kết quả.
   Đọc lại volume từ volumes[strategy_index], sao symbol hiện tại,
   dùng comment/sl/tp/price/expiration đã giữ để gọi Bot3OpenPending
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

Địa chỉ: tổng22a6d; vé22b42; mã22b56; tên22b79; loại22c37/2315c;
khối lượng22c55/2317a; mua đọc12/13/9/2/16 ở22c9a/22cbd/22ccd/
22cdd/22d18, xóa22d65, open22de3; bán xóa2328a, open23308;
bảng22e00/23320, thông báo23116/22af1, chờ2312a/22b05.
Literals: descriptor60268/60328; suffix có độ dài40tại60288, buffer6028c.

## Cổng gọi phía trước còn riêng

Hiện tại còn phải nối đầu đánh giá/quản lý/hàm14fa0, cờ người gọi,
cờ phiên và điều kiện vốn. Nguyên factor là6d618/100+1; so cả tăng
và giảm vốn trước3f900, có nhánh dừng vì chia0. Không dùng phép so
của vòng này để chứng minh phần trước hoặc mọi SDK của tính khối lượng.

Phép kiểm vòng phải chạy nguyên các nhánh caller và thân xóa/open/gửi,
đọc đủ200ô bảng,35trường/4chuỗi, last_ticket và thứ tự/đối số dịch vụ.
Chỉ SDK/cấp chuỗi thành công được cấp; chuyển số thành chuỗi đo trong
MT5 rồi đối chiếu lời gọi/value gốc. Không gửi lệnh lên tài khoản thật,
không sửa EX5/cờ bản quyền. Chưa toànEA hoặc lỗi cấp bộ nhớ.
