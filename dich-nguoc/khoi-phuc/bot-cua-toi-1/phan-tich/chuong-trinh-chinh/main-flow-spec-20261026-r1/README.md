# Đặc tả luồng chính bot 1 (EX5 gốc)

## Bằng chứng

- EX5 gốc SHA-256: `a3b0de423a06e10ebedc279307b93d7cb9188ba2bb5de77131a913c865b0e922`.
- Mã trung gian: `phan-tich/luot-20261023-data-v2/ma-trung-gian.c`, vùng gốc base `0x23e5aa10000`.
- Dispatcher RVA `0x10f60` (`FUN_23e5aa20f60`, dòng 8225), thân kết thúc trước `0x173e4`.
- Evaluator RVA `0x18aa0` (`FUN_23e5aa28aa0`, dòng 11210), kết thúc trước `0x1ef9c`; tham số duy nhất là `uint param_1`.
- Vùng evaluator đã chụp SHA-256 `45d53270186b7019a8721e0cf3734a61aac8e8660c70f7e602849b1c298d7cbd` (native-bindings).

## Thứ tự đã xác nhận

1. Dispatcher đọc `TimeCurrent`; nếu chế độ chỉ nến mới thì so thời gian nến `iTime(...,1)` và trả về khi chưa có nến mới. Cờ `0x721c9` cho phép bỏ qua bộ lọc nến; cờ `0x77470` phải bằng 1 mới đi tiếp. Bằng chứng: `FUN_23e5aa20f60`, đầu hàm.
2. Dispatcher kiểm tra tài khoản (`AccountInfoInteger`, `AccountInfoDouble`), cập nhật vốn đỉnh và giới hạn lỗ; khi vượt ngưỡng gọi hàm dừng `FUN_23e5aa40010`, đặt cờ dừng và trả về. Việc tính dùng số thực `double`; có quét lịch sử giao dịch để cộng lời/phí/hoa hồng trong cùng nến.
3. Dispatcher tạo và so thời gian phiên giao dịch; cập nhật trạng thái tin tức/phiên, đặt cờ chặn và thông báo qua `MT5_Dispatch`. Sau đó làm mới bộ đếm nến (`Bars`, `iTime`).
4. Khi không bị chặn, dispatcher gọi evaluator `FUN_23e5aa28aa0(param_1)`. `param_1` là chỉ số nến/khung được lấy từ bảng trạng thái (kiểu `uint`, lưu tại `local_1ac` trong evaluator).
5. Sau đường xử lý chính, dispatcher tăng bộ đếm lỗi/hiển thị và trả về. Các nhánh lỗi dùng `MT5_Dispatch` và mã lỗi runtime; chưa có bằng chứng cho việc ném ngoại lệ ra ngoài. Việc gọi trực tiếp `0x18aa0` từ mọi điểm trong `0x10f60` chưa được chứng minh đầy đủ bằng bảng gọi.

## Evaluator: đầu vào và sở hữu trạng thái

- Khởi tạo toàn bộ biến cục bộ về 0; lấy `TimeTradeServer` và `TimeToStruct` trước khi đọc dữ liệu.
- Chuỗi mã sản phẩm lấy từ vùng `DAT_23e5aa7791c`; nếu rỗng hoặc khác chuỗi chuẩn thì dùng `DAT_23e5aa7a428`. Chuỗi được sao chép qua `FUN_23e5aa105c0` (bộ nhớ động, `wchar_t`).
- `DAT_23e5aa7a3b4` là cờ đã kiểm môi trường MQL. Khi chưa kiểm, gọi `MQLInfoInteger(7)`; nếu bằng 0 thì báo lỗi một lần và không chạy phần giao dịch.
- Đọc lịch phiên bằng `SymbolInfoSessionTrade`; nếu lỗi thì báo `MT5_Dispatch` và thoát nhánh.
- Đọc giá tick (`SymbolInfoTick`) và thời gian hiện tại. Nếu lỗi tick thì báo và không tiếp tục.

## Quét vị thế/lệnh và quản lý

- Quét `PositionsTotal` theo chỉ số; lấy vé, loại (integer thuộc tính 2), mã chiến lược (thuộc tính 12), tên mã, khối lượng/giá/dừng/chốt (double thuộc tính 4,6,7), thời gian mở (integer thuộc tính 2). Chỉ giữ vị thế có mã chiến lược bằng `DAT_23e5aa7246c` và tên mã trùng chuỗi hiện tại.
- Khi có vị thế, gọi `FUN_23e5aa36d20` với vé và hai giá thực; đây là đường quản lý vị thế. Nếu không có vị thế, kiểm tra nến tại `iTime` và gọi các hàm điều kiện `FUN_23e5aa371f0`, `FUN_23e5aa3abc0`.
- Quét `OrdersTotal` tương tự; lọc magic và mã, đọc loại lệnh, thời gian hết hạn, giá/dừng/chốt. Lệnh hết hạn gọi `FUN_23e5aa44150(ticket)`.
- Các nhánh xoá/sửa lệnh và quản lý vị thế đều có điều kiện cờ; thứ tự đọc là vé → magic → mã → loại → giá/thời gian.

## Vòng chiến lược 8 và giá/khối lượng

- Native-bindings ghi `volumes_count=8` tại RVA `0x66a80`; trong mã, evaluator đặt `iVar11=0` và lặp tới khi `iVar11 < DAT_23e5aa72458`. Vì vậy có bảng 8 phần tử đã xác nhận, còn điều kiện cắt sớm theo `DAT_72458` phải giữ nguyên; không mặc định luôn chạy đủ 8 vòng.
- Mỗi vòng: gọi `FUN_23e5aa44780(magic, offset)` (`offset=100` khi cờ `0x72554`), cập nhật giá nhỏ nhất; nếu bật thời gian hết hạn, lưu `TimeCurrent()+DAT_23e5aa76da0`.
- Nếu cờ xoá lệnh hết hạn bật, quét lệnh ngược từ `OrdersTotal()-1` tới 0; loại 4 hoặc 5 và `expiration + DAT_23e5aa76da0 <= TimeCurrent()` thì xoá.
- Sau đó quét vị thế/lệnh cùng mã để quyết định đã có lệnh hay chưa; nếu chưa, gọi `FUN_23e5aa365a0`, `FUN_23e5aa4c670`, rồi so số lượng lệnh chờ với `DAT_23e5aa72458` trước khi tạo yêu cầu.
- Các giá đầu vào/ra là `double`; khối lượng là `double` trong mảng tại `0x76a80`, `0x76db0`, `0x770d0`. Công thức đầy đủ của `FUN_23e5aa42890/42ac0` và làm tròn giá nằm ở hàm con, chưa được chốt trong phạm vi này.

## Nhánh tin tức/phiên/tài khoản

- Ba cờ chặn độc lập (`DAT_23e5aa77488`, `77489`, `7748a`) được cập nhật từ lịch thời gian; trong cửa sổ chặn, gọi các hàm đóng/huỷ `3f5c0`, `3f7e0`, `3fa00`, `3fce0` tùy cờ cấu hình và không chạy vòng chiến lược.
- Thời gian phiên dùng `TimeTradeServer`, `TimeCurrent`, `TimeToStruct`; cửa sổ so sánh theo phút (`*60`).
- Nếu tài khoản không đủ điều kiện MQL (`MQLInfoInteger(6/4)==0`) thì đặt cờ lỗi, thông báo và bỏ qua giao dịch.

## Chưa đủ bằng chứng (không được tự điền)

- Chưa xác định chính xác quan hệ gọi trực tiếp giữa dispatcher `0x10f60` và evaluator `0x18aa0` ở mọi nhánh; chỉ xác nhận evaluator có tham số `uint` và đường gọi nằm trong vùng dispatcher.
- Chưa chốt tên/ý nghĩa kinh doanh của từng cờ `DAT_*`; chỉ ghi điều kiện và tác dụng quan sát được.
- Chưa chốt công thức `base_price`, tám giá/khối lượng chiến lược, làm tròn theo `unit`, và kết quả trả về của từng hàm chiến lược con.
- Chưa chốt thứ tự tạo yêu cầu mua/bán ở cuối evaluator, mã lỗi từng API và xử lý khi cấp phát chuỗi thất bại.
- Chưa có kiểm chạy song song hai EA MT5; tài liệu này chỉ là đặc tả từ mã trung gian/native.

## Nguồn dựng lại và cách kiểm

Đặc tả này nối tới các header hiện có trong `source/MQL5/Include/bot-cua-toi-1` theo tên hàm `Bot1Management*`, `Bot1Strategy*`, `Bot1Pending*`, `Bot1Position*`, `Bot1NewsBlock*`, `Bot1Account*`. Chưa ghép hoặc sửa header. Mỗi mục chỉ được giao viết mã sau khi các mục “chưa đủ bằng chứng” được phân tích bổ sung.
