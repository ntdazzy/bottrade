# Phần đầu đánh giá đã so với nguồn MQL5

Phạm vi duy nhất: từ `20ef0` đến hai cạnh ra `211ea` hoặc `216e5`;
chưa chạy xử lý ngày/phiên, tick, lệnh hoặc vị thế ở các nhánh sau.
SHA-256 phần mã đầu:
`5c7b757b6a0965ee4044679c7fa3138a99550e7dce7dfb08c0de47df027638f8`.
SHA-256 toàn hàm gốc `20ef0..2a1bc`:
`6bead161fa97b6568b546e8c86a4ff03fdda55d6fb226a52b58dd14ec050d920`.

Thứ tự giữ nguyên:

1. Lưu chỉ số 32 bit và cờ byte tại `[rsp+b0]`/`[rsp+88]`.
2. `210d2` gọi `TimeTradeServer()`; kết quả được lưu ở `[rsp+f8]` tại
   `210e9`. Tên `local_1d0` trong C trung gian không phải vị trí `rsp+1d0`.
3. `210f1` gọi `TimeToStruct`, đầu ra ở `[rsp+58]`; không kiểm bool trả về.
   Đây là 8 số int32, gồm thứ trong tuần tại `+70`, ngày trong năm tại `+74`.
   [Tài liệu MQL5](https://www.mql5.com/en/docs/constants/structures/mqldatetime)
   xác định Chủ nhật=0, thứ Bảy=6, ngày đầu năm=0.
4. So chuỗi ở descriptor `74958` với chuỗi rỗng bất biến `59d18`.
   Chuỗi rỗng có bộ đệm chọn nguồn `1d6e28`; con trỏ NULL giữ nguồn `74958`.
   Helper `5c0` sao nguồn được chọn vào descriptor tạm `[rsp+110]`.
   Nội dung thực của `1d6e28` do môi trường cấp; chưa đặt tên nghiệp vụ
   hoặc thay bằng chuỗi rỗng/tên mã tự nghĩ.
5. Byte `1d6d08 != 0` bỏ đọc thông tin MQL, đi `211ea`. Nếu byte=0,
   gọi `MQLInfoInteger(7)` đúng một lần; kết quả int32=0 đi `216e5`,
   khác0 đi `211ea`. Hàm MQL5 chỉ trả mã nhánh, không gọi/chế ra nhánh sau.

Kết quả: **432/432 ca khớp**, gồm 17 giá trị, chuỗi UTF-16 đầy đủ và
phân biệt NULL/chuỗi rỗng. Có bộ đệm rỗng ở heap và literal của mã gốc,
tên mã tiếng Việt/ký tự ghép/300 ký tự, byte 0/1/255, int thông tin MQL
-1/0/1, chỉ số uint32 và ba mốc thời gian. Calendar ban đầu được cấp
giống nhau ở khung gốc và trạng thái MQL5; khi dịch vụ báo false và
không ghi, cả hai giữ nguyên dữ liệu. Khi báo thành công, phía MQL5
dùng `TimeToStruct` thật để đổi thời gian đã cấp.

Hai bản biên dịch đều 0 lỗi/0 cảnh báo: `b3-head-api-20261027-r1`
(chỉ biên dịch, mặc định không gọi), `b3-head-check-20261027-r1`.
Lượt so: `b3-evaluation-head-20261027-r1`. Cấp chuỗi thành công và
câu trả lời dịch vụ được cấp; chưa so lỗi cấp bộ nhớ, mọi đường của
toàn hàm, EA hoặc cặp hai bot hoàn chỉnh.

[Nguồn](../../../source/MQL5/Include/bot-cua-toi-3/Bot3EvaluationHead.mqh),
[bộ kiểm](../../../tests/check-evaluation-head.py),
[kết quả](../../../bang-chung/kiem-quan-ly-vi-the/b3-evaluation-head-20261027-r1/comparison.json).
