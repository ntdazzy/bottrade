# Cầu nối EvaluationResizeFlow → NFP / thoát

**Ghi chú đề xuất chưa được root xác nhận. Không dùng làm đặc tả viết mã.**
Các vùng sau `1b44f`/`2372b` đã thuộc nhánh NFP có nguồn riêng. Các mô tả
timestamp/cờ và câu kết luận "quay về NFP" dưới đây chưa chính xác ở mọi
nhánh: `1a63a`/`22875` là thoát sớm khỏi đánh giá. Chưa nối chắc chắn kiểu
chuỗi thông báo; cần root kiểm từng địa chỉ trước khi phục hồi cầu nối.

## Bot1

Bằng chứng raw: evaluator snapshot SHA-256 `45d53270186b7019a8721e0cf3734a61aac8e8660c70f7e602849b1c298d7cbd`.

- `0x1b317–0x1b341`: gọi bộ dọn chuỗi/tạm tại RVA `0x0` cho bốn vùng stack `[rsp+0x70]`, `[rsp+0x80]`, `[rsp+0xa0]`, `[rsp+0x50]`.
- `0x1b343–0x1b377`: gọi `MQLInfoInteger` với mã `6`, sau đó mã `4` khi nhánh đầu trả `0`.
  - Nếu mã `6 != 0`, đi tiếp tại `0x1b37d`.
  - Nếu mã `6 == 0` và mã `4 == 0`, nhảy `0x1b8a7`.
- `0x1b37d–0x1b3b0`:
  - cờ byte `0x62568` phải khác `0`;
  - biến ngày/giờ `0x6779c` phải bằng `0`;
  - biến `0x677a0` phải `<=4`;
  - nếu không đạt, nhảy `0x1b44f`.
- `0x1b3b6`: cờ `0x67434`:
  - khác `0` → nhảy `0x1ec5d`;
  - bằng `0` → gọi SDK tại `0x7ff6846ef6c0` với `edx=5`, `r8d=0x52`, output `[rsp+0xd8]`.
- `0x1b3f2–0x1b411`: tạo hai chuỗi tạm bằng các descriptor `0x54710`, `0x5e6e0`, rồi gọi hàm nối/so chuỗi `0x4a0`. Nếu không đạt, nhảy `0x1ee7b`; nếu đạt, `MT5_Dispatch(...,2,1,0x590008)` tại `0x1b5c0`.
- `0x1b5ec–0x1b64f`: đọc `TimeCurrent()` hai lần; so với timestamp `0x6a640` ± hai cửa sổ phút tại `0x6a678` và `0x6a680`. Đây là cổng thời gian trước khi đi tiếp; nhánh trong/ngoài cửa sổ rẽ về `0x1b72b`, `0x1b5ec` hoặc khối tiếp theo.
- `0x1b44f–0x1b5ec`: xử lý nhánh lịch/khởi tạo khác; đọc cờ `0x6a640`, `0x6a648`, `0x67488`, gọi `MQLInfoInteger(6)`, `TimeTradeServer`, hàm lịch `0x61b0`, rồi có thể gọi `MT5_Dispatch`. Không có bằng chứng đây là một phần gửi lệnh.
- `0x1b8a7–0x1b8ec`: nếu cờ `0x67434==0`, dựng chuỗi và `MT5_Dispatch`; sau đó đặt `0x67434=1` và nhảy luồng chính `0x1a63a`.
- `0x1ec5d`: đặt byte tại `0x67434=1`, rồi nhảy `0x1a63a`.
- `0x1eb08`: chỉ là tiếp tục nối/dọn chuỗi tạm sau vùng `0x1ea3e`; không phải lệnh giao dịch. `0x1ec31` gọi `MT5_Dispatch`, `0x1ec5d` đặt cờ rồi thoát về luồng chính.

## Bot3

Bằng chứng raw: evaluator snapshot SHA-256 `6bead161fa97b6568b546e8c86a4ff03fdda55d6fb226a52b58dd14ec050d920`.

- `0x235f7–0x2361e`: dọn bốn vùng tạm stack.
- `0x23620–0x23652`: gọi `MQLInfoInteger(6)`, rồi mã `4` khi cần; nếu cả hai không cho phép thì nhảy `0x238b0`.
- `0x23658–0x23695`:
  - byte `0x6d658` phải khác `0`;
  - ngày/giờ `0x747dc` phải bằng `0`;
  - `0x747e0 <= 4`;
  - nếu không, nhảy `0x2372b`.
- `0x2369b`: cờ `0x74474`:
  - khác `0` → nhảy `0x23bb9`;
  - bằng `0` → gọi SDK `0x7ff6846ef6c0` với `edx=5`, `r8d=0x52`, output `[rsp+0xd8]`.
- `0x236cd–0x236ec`: nối/so chuỗi bằng descriptor `0x5ce70`, `0x68a50`; nếu chuỗi hợp lệ thì dispatch ở nhánh sau, nếu không thì đi `0x23a5d`.
- `0x23c34` gọi `TimeCurrent()`; so timestamp tại `0x1d7028` với cửa sổ phút ở `0x1d7058` và biến lân cận. Đây là cổng thời gian tương ứng Bot1.
- `0x2372b–0x238f8`: nhánh lịch/khởi tạo; đọc cờ `0x1d7020`, `0x1d7028`, `0x744c8`, gọi `MQLInfoInteger(6)`, `TimeTradeServer`, hàm lịch `0x6ad0`, rồi có thể dispatch; cuối nhánh đặt `0x74474=1` và nhảy `0x22875`.
- `0x23bb9`: đặt `0x74474=1`, nhảy `0x22875`.
- `0x238fd–0x23b50`: nối chuỗi tạm; `0x23c08` dispatch rồi nhảy tiếp. Đây là dọn/hiển thị, chưa thấy lời gọi gửi lệnh trong đoạn này.

## Kết luận

- Hai cầu nối này chủ yếu là cổng môi trường, lịch, cờ đã xử lý và cửa sổ thời gian; các đích `0x1b8a7`, `0x1ec5d`, `0x23bb9`, `0x238f8` đều đặt cờ rồi quay về luồng chính/NFP.
- Không thấy trong các đoạn đã chụp một lời gọi `OrderSend`/`BotOpenPending` trực tiếp.
- Các descriptor chuỗi và ý nghĩa đầy đủ của cờ `0x62568/0x67434`, `0x6d658/0x74474` chưa được nối chắc chắn với tên tham số Source.
