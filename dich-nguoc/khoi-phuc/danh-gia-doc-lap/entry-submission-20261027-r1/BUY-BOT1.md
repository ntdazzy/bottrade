> Ghi chú đề xuất ban đầu, chưa được quản lý xác nhận. Có tên/địa chỉ/thuộc tính chưa đúng; không dùng làm đặc tả viết mã.

# Bot1 — đặc tả nhánh mua từ RVA `0x1ca24`

Phạm vi: nhánh sau giới hạn lệnh, từ `0x1ca24` đến các nhánh gửi lệnh được gọi trong cùng evaluator. Đây là đặc tả phân tích, chưa phải xác nhận toàn EA.

## 1. Cổng và vòng chiến lược

- `0x1ca24`: đọc `DAT_23e5aa72458` (`maximum_pending`). Nếu `<=0`, nhảy `0x1e94f`.
- `0x1ca37`: nạp cờ `DAT_23e5aa7a570`, cờ `DAT_23e5aa7a578`, hệ số `DAT_23e5aa5ffe8`.
- Vòng `0x1cb55`: chỉ số vòng ở `[rsp+0xc0]`, bắt đầu `0`; tăng tại `0x1cb4b`; dừng khi chỉ số mới `>= DAT_23e5aa72458` tại `0x1cb4d`.
- `0x1cb9b` gọi native `0x34780` với `0x62498` và cờ `0x6a570 ? 100 : 0`.
- `0x1cba7` đọc chỉ số toàn cục `0x678f4`. Kết quả `0x34780` so với `(&DAT_23e5aa76a80)[global_index]` tại `0x1cbd0`; nếu nhỏ hơn thì ghi đè tại `0x1cbe0`.
- `0x1cbef` kiểm `DAT_23e5aa72468 > 0`; nếu đúng, gọi SDK thời gian tại `0x1cbf9`, cộng với `DAT_23e5aa76da0`, ghi vào `DAT_23e5aa77450`.

## 2. Quét/hủy lệnh quá hạn

- Cờ `DAT_23e5aa72419` khác `0` tại `0x1cc21` mở nhánh quét.
- Đặt `DAT_23e5aa77450 = 0`, gọi `OrdersTotal()` tại `0x1cc48`.
- Duyệt từ `total` về `0`, lấy ticket rồi lọc ticket khác `0`, magic `DAT_23e5aa7246c`, và `ORDER_SYMBOL` so sánh đầy đủ với `DAT_23e5aa7791c`.
- `ORDER_TYPE` đọc độc lập: loại `4` hoặc đọc lại loại `5` tại `0x1cd6c–0x1cd8c`.
- Đọc `TimeCurrent()` và `ORDER_TIME_EXPIRATION` bằng `OrderGetInteger(...,1)`. Nếu `DAT_23e5aa76da0 + expiration <= current_time`, gọi xóa `0x34150` tại `0x1cdd7`.
- Source gần nhất: `Bot1OrderCancel.mqh`; chưa có hàm riêng giữ nguyên toàn bộ nhánh magic/symbol/type/expiration này.

## 3. Tiền xử lý vị thế và lệnh chờ

- Sau phần quá hạn, vùng `0x1ce35` trở đi tạo nhiều chuỗi tạm và bảng kết quả.
- Nếu `DAT_23e5aa76a68 == 0`, gọi `PositionsTotal()` và duyệt vị thế buy (`POSITION_TYPE==0`) theo magic/mã sản phẩm.
- Nếu không có vị thế phù hợp, gọi các hàm native kiểm tra/chuẩn bị tại `0x365a0`, `0x4c670`.
- Sau đó đếm lệnh loại `4` bằng `OrdersTotal()`, magic và mã sản phẩm; biến đếm so với `DAT_23e5aa72458`.
- Nếu số lệnh đạt giới hạn, quét lại loại `4` để tìm giá cực trị; dùng trường giá `9`.
- Các cổng này có nhánh `MT5_Dispatch(...,2,1,0x590008)` khi chuỗi/điều kiện không đạt. Chưa đủ chứng cứ để đặt tên chính xác từng cờ `0x76a68`, `0x77440`, `0x77910`.

## 4. Kiểm giá và chuẩn bị gửi buy

- `MT5_SymbolInfoInteger(symbol,0x11)` được gọi nhiều lần để lấy chữ số.
- Giá được làm tròn theo bảng hệ số native; Source gần nhất: `Bot1RoundPrice` trong `Bot1PriceLevels.mqh`.
- Giá buy được cộng khoảng cách dạng `offset * scale + current_price`.
- Có cổng kiểm giá tối thiểu/tối đa so với các lệnh đang có; nếu giá không còn hợp lệ thì quay về nhánh dọn tạm.
- Cổng tài khoản dùng `MT5_AccountInfoInteger(...,0x2f)`; nếu khác `0`, `OrdersTotal()` phải nhỏ hơn giới hạn. Đồng thời hai điều kiện khoảng cách giá phải đúng.
- Chuỗi comment được dựng từ comment và mã sản phẩm; hai nhánh khác nhau theo cờ `DAT_23e5aa72418`.

## 5. Gửi lệnh và retry

- Hàm gửi native được gọi qua `FUN_23e5aa42dd0` với loại lệnh `5` ở nhánh buy đã thấy trong C.
- Khi kết quả `0`, kiểm mã lỗi `DAT_23e5aa7a410 == 0x84`, gọi sleep native `0x7ff6846d17c0(...,0x9c4)`, dựng lại request và gọi lại.
- Sau retry, gọi hàm gửi thực tế `FUN_23e5aa436d0`.
- Nếu gửi thành công, ticket và giá được ghi vào bảng kết quả 100 ô tại vùng `0x76410/0x76418`; nếu thất bại, gọi `MT5_Dispatch` và dọn chuỗi.
- Source tương ứng:
  - `Bot1PendingRequest.mqh`: tạo request, loại, giá, SL/TP, khối lượng, hạn lệnh;
  - `Bot1TradeSend.mqh`: gửi request;
  - `Bot1TradeErrors.mqh`: đổi mã lỗi;
  - `Bot1Margin.mqh`: cổng tiền ký quỹ;
  - `Bot1PendingSubmission.mqh`: logic gửi pending gần nhất.
- Chưa đủ bằng chứng để khẳng định `FUN_23e5aa42dd0` đã tương ứng 100% với `Bot1OpenPending`; cần đối chiếu toàn bộ tham số ở các nhánh còn lại.

## 6. Điều chưa chốt

- Ý nghĩa đầy đủ của `0x34780`, `0x6a570`, `0x6a578`, `0x76a68`, `0x77440`, `0x77910`.
- Công thức cuối của SL/TP và khối lượng tại các nhánh sau `0x1ce80`.
- Chính xác điều kiện “nearby” và điều kiện giá cực trị trước `FUN_23e5aa42dd0`.
- Trường `ORDER_TIME_EXPIRATION` đã xác định là property `1`; các trường giá/khối lượng đã thấy là `9`, `7`, `8`, nhưng cần nối từng trường với tên MQL5 trong request cuối.
- Bảng kết quả 100 ô đã xác định địa chỉ `0x76410/0x76418`, nhưng chưa chốt toàn bộ thời điểm ghi/xóa ở mọi nhánh lỗi.

Không gọi nhánh này là đã phục hồi đầy đủ; phần trên mới chốt được cổng, vòng, lọc lệnh, quá hạn, một phần chuẩn bị giá và cơ chế retry.
