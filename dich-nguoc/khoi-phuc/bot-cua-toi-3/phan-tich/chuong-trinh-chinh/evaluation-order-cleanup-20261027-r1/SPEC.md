# Bot3 — dọn lệnh chờ ở đầu đánh giá

Codex chốt từ raw `212ff..214ee`, trong evaluator `20ef0..2a1bc`
SHA `6bead161fa97b6568b546e8c86a4ff03fdda55d6fb226a52b58dd14ec050d920`.
Hàm xóa được gọi là `32450..32a84`, SHA
`9c734e0a55e2cbbe1b567281e7d9a93329834ecd8b29d5054e63ab2b7122eede`.
Đã có nguồn `Bot3DeletePending` trong `Bot3OrderCancel.mqh`, phải dùng
đúng nguồn này; không đổi sang hàm chọn lệnh cao/thấp vì điều kiện khác.

## Giao diện và logic

Tệp `Bot3EvaluationPendingCleanup.mqh`, include `Bot3OrderCancel.mqh`.
Hàm `void Bot3CleanEvaluationPending(const uchar caller_flag,
const int &strategy_magic,const string &symbol,double &results[][2],
Bot3PendingRequestState &trade,Bot3TradeSendOptions &options)`.
Không thêm trạng thái trả về; không sửa `last_ticket` global ở `74838`.
`results` là cùng bảng kết quả100dòng của hàng đợi, không tạo bảng riêng.

1. Cờ người gọi lấy từ byte DL đã lưu (`sp+88`) ở đầu evaluator. Bằng0
   thì không gọi OrdersTotal hoặc xóa lệnh, đi thẳng phần quét vị thế.
2. Khác0: lấy OrdersTotal đúng1lần, duyệt giảm `total-1` đến0. Không
   đọc lại tổng ở cuối vòng, kể cả khi dịch vụ xóa làm thay đổi danh sách.
3. OrderGetTicket(index), giữ vé64bit. Vé0 bỏ qua. Đọc OrderGetInteger
   (ORDER_MAGIC=15), so long64 với int32có dấu `strategy_magic`.
4. Đọc OrderGetString(ORDER_SYMBOL=0), so đầy đủ với `symbol`, giữ
   phân biệt NULL/chuỗi rỗng. Không đọc giá hoặc tìm lệnh cực trị.
5. Đọc OrderGetInteger(ORDER_TYPE=4); chỉ phần thấp32bit tham gia
   `((uint)type & (uint)0xfffffffe)!=0`. Các giá trị có phần thấp0/1 bỏ;
   không thay bằng `type>=2` hoặc giới hạn cứng4/5.
6. Gọi `Bot3DeletePending(trade,options,ticket)`. Trả false thì không
   sửa bảng. Trả true thì tính `recorded=(double)(long)ticket` (có dấu),
   quét đúng100dòng từ0..99. Khi `results[row][0]==recorded` theo so
   có thứ tự (NaN không bằng) thì ghi hai ô `[0]`/`[1]` bằng+0 và dừng
   quét bảng ngay. Giữ các dòng trùng phía sau và các dòng không trùng.
7. Tiếp lệnh chỉ số kế tiếp; không dùng giá trị trả hàm con thay cho
   việc quan sát send thật trong phép kiểm. Không in thông báo thêm.

Raw: gọi tổng2133c, vé213b2, mã213c4, chuỗi213dd, kiểu21487,
xóa214a1, kiểm EAX214a3, quét214c0..214d6, zero21386/2138e,
hủy chuỗi214ec rồi214ee. Cả bảng bắt đầu tại
`0x171562c3450-0x640 = 0x171562c2e10`, RVA **72e10** với base17156250000.
Đừng tính sai base hoặc viết nhầm c2e10/73450 thành RVA đầu bảng.

## Kiểm nối

Chạy nguyên evaluator từ entry20ef0, qua phần đầu đã so, rồi từ RIP
212ff qua vòng xóa, nguyên thân32450/950 và phần quét vị thế đã so.
Có cả cờ0/1/255; không đặt lại thanh ghi/ngăn xếp hoặc đầu vào giữa
hai bước. Nạp bảng, trạng thái yêu cầu, vị thế/lệnh và cài đặt trước
entry. So đầy đủ trạng thái35trường/4chuỗi, đối số dịch vụ, thứ tự,
bool xóa và tất cả200ô bảng, gồmNaN/vé64bit/trùngdòng/vịtrí0/99.
Các bộ trả dịch vụ được cấp, không gửi lệnh lên tài khoản thật.
Phải phân biệt false vì khoảng khóa xóa, chương trình dừng và false
từ dịch vụ gửi; chỉ bool cuối hàm con quyết định xóa dòng bảng.

Thân xóa và gửi đều chạy thật; câu trả lời chọn/truy vấn/giá/gửi được
cấp. Thông báo gửi log0 trong lượt này; lỗi cấp bộ nhớ, phần quản lý
tiếp sau227c0 và toànEA chưa được chứng minh. Không thay EX5 gốc hoặc
cờ bản quyền. Bản so từng phần không được gọi là đã chạy hai EA.
