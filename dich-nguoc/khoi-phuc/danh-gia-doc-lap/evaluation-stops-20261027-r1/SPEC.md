# Bổ sung mức dừng/chốt trước quản lý — bot 1 và bot 3

Codex chốt từ hai thân evaluator gốc trước khi viết mã. Đây là một
vòng khác với `BotNFillManagementInitialLevels`: chỉ gọi sửa MỘT lần
sau khi tính đủ hai mức, không đổi vé qua double, không làm tròn mức
đã có và không tạo chốt khi khoảng chốt <=0/NaN. Không dùng nhầm hàm cũ.

| Dữ liệu/điểm | Bot1 | Bot3 |
|---|---|---|
| Entry sau phần đầu |18eb1|214ee (sau bước dọn lệnh chờ) |
| Cờ byte |62418|6d510|
| Mã chiến lược int32 |6246c|6d564|
| Tên mã descriptor |67918|74958|
| Khoảng dừng/chốt double |62498 /624a0|6d588 /6d590|
| Đơn vị double |66d98|73dd8|
| Lời gọi tổng vị thế |18ee9|21526|
| Lấy vé lần đầu |19da2|22422|
| Đọc dừng/chốt/mở/loại/số chữ số |19e87/19ea0/19edd/19ef6/19f19|224f7/2250f/2254b/22564/22587|
| Gọi sửa |19d88, thân26d20|22408, thân32a90|
| Hủy chuỗi rồi hết phạm vi |1a141..1a152|227af..227c0|

SHA evaluator bot1 `18aa0..1ef9c`:
`45d53270186b7019a8721e0cf3734a61aac8e8660c70f7e602849b1c298d7cbd`.
Bot3 `20ef0..2a1bc`:
`6bead161fa97b6568b546e8c86a4ff03fdda55d6fb226a52b58dd14ec050d920`.
Thân sửa26d20/32a90 và gửi950 đã có nguồn/đối chứng riêng; lượt mới
cần chạy nguyên các thân này, không thay bằng câu trả lời của hàm con.

## Nguồn và giao diện

Tạo `BotNEvaluationStops.mqh` trong Include mỗi bot, include đúng
`BotNPriceLevels.mqh` và `BotNPositionModify.mqh` đang có.
`BotNEvaluationStopInputs` chứa `uchar enabled`, `int magic`,
`double stop_distance`, `double target_distance`, `double unit`.
Hàm `void BotNFillEvaluationStops(const string &symbol,
const BotNEvaluationStopInputs &inputs, BotNPendingRequestState &trade,
BotNTradeSendOptions &options)`. Các đầu vào là tham chiếu: không sao
sẵn các cài đặt trước khi các lời gọi dịch vụ có thể đổi dữ liệu.
Tên mã là cùng biến `EvaluationPreludeInputs.symbol` khi nối với phần đầu.

1. `inputs.enabled==0` thì trả về. Không đọc PositionsTotal ở nhánh này.
2. Lấy PositionsTotal đúng1lần. Chỉ số từ total-1 giảm tới0; không đọc
   lại tổng ở cuối vòng. Lấy vé64bit; vé0 bỏ qua.
3. PositionGetInteger(POSITION_MAGIC=12) so long64 với `(long)inputs.magic`
   (mã32bit có dấu, không cắt kết quả dịch vụ về32bit). Sai thì bỏ.
4. PositionGetString(POSITION_SYMBOL=0), giữ phân biệt NULL/chuỗi rỗng,
   so với symbol đầy đủ. Sai thì bỏ.
5. Đọc PositionGetDouble(POSITION_SL=6), rồi POSITION_TP=7. Nếu cả hai
   đều khác0 thì bỏ, gồm NaN theo phép so số thực gốc. ±0 đều bằng0.
6. Đọc lần lượt POSITION_PRICE_OPEN=4, POSITION_TYPE=2 (long64), rồi
   SymbolInfoInteger(symbol,SYMBOL_DIGITS=17), ép kết quả về uint32.
   Phải đọc số chữ số TRƯỚC khi bỏ loại không phải0/1.
7. Với loại0 (mua), nếu dừng==0:
   `sl=BotNRoundPrice(open-(inputs.stop_distance+0.0)*inputs.unit,digits)`.
   Loại1 (bán):
   `sl=BotNRoundPrice((inputs.stop_distance+0.0)*inputs.unit+open,digits)`.
   Không bỏ phép cộng0.0; không buộc khoảng dừng phải dương.
8. Nếu chốt==0 và `inputs.target_distance>0.0`: mua dùng
   `tp=BotNRoundPrice(open+inputs.target_distance*inputs.unit,digits)`;
   bán dùng `tp=BotNRoundPrice(open-inputs.target_distance*inputs.unit,digits)`.
   Phép nhân phải làm trước cộng/trừ như gốc. Nếu không đủ điều kiện,
   giữ chốt đã đọc, kể cả NaN/-0. Không đọc lại các mức từ vị thế.
9. Loại0/1 luôn gọi `BotNModifyPosition(trade,options,ticket,sl,tp)`
   sau bước6 nếu ít nhất1mức bằng0, kể cả khi khoảng chốt không dương
   và không tạo mức mới. Chỉ một lần, bỏ bool trả về và tiếp tục vòng.
   Không truyền mức qua biến giá mở bị sửa giữa hai công thức.

`BotNRoundPrice` đã giữ ép long có LONG_MIN thì trả giá chưa làm tròn;
digits giới hạn11 sau épuint32. Không thay bằng NormalizeDouble.
Các mức thay đổi chỉ là đối số gửi; phần gọi ngoài không tự cập nhật
giá trị vị thế trên máy chủ hoặc tự sửa cài đặt.

## Nối kiểm nguyên thân

Chạy phần đầu evaluator đã so, rồi tiếp từ RIP hiện tại qua vòng này,
hủy chuỗi cuối và dừng trước1a152/227c0. Không đặt lại thanh ghi/ngăn
xếp ở giữa. Các cài đặt/vị thế/trạng thái yêu cầu ban đầu được nạp
trước khi chạy từ entry. Thân26d20/32a90 và950 chạy thật; chỉ SDK được
cấp lời trả lời. So cả mọi đối số sửa, thứ tự dịch vụ, đầy đủ35trường
yêu cầu/kết quả/kiểm cùng4chuỗi tại ranh giới cần thiết và khi ra.
Có nhánh bị dừng/chọn vé lỗi, gửi đồng bộ/bất đồng bộ thành công/thất
bại, thiếu1/2mức, loại/số chữ số ngoài thông thường, NaN/vô cực/±0,
vé64bit và nhiều vị thế. Cài đặt có thể đổi tại điểm dịch vụ được ghi rõ.

Lượt kiểm nối bot3 dùng cờ DL=0 để bỏ bước dọn lệnh chờ đứng trước;
không dùng lượt này để chứng minh bước đó. Phần thông báo950 dùng
log_level=0 trong lượt nối, nhánh thông báo đã có phép so riêng.
Đây chưa phải luồng quản lý đầy đủ hay EA, lỗi cấp bộ nhớ hoặc môi
trường giao dịch thật. Ngữ cảnh R12 đi tiếp tới quản lý vẫn phải so
liên tục trước ghép EA; không suy từ lượt có cấp dữ liệu này ra100%.
