> Ghi chú đề xuất ban đầu, chưa được quản lý xác nhận. Có tên/địa chỉ/thuộc tính chưa đúng; không dùng làm đặc tả viết mã.

# Đặc tả nhánh đặt lệnh chờ bán — Bot 1

Phạm vi: đường đi máy gốc `0x1ca24..0x1e94f`, gồm các khối chung đã dời
`0x1cab6..0x1cb55`. Đây chưa phải đặc tả cả EA. Các bước dưới đây chỉ nêu
điều đã thấy trong mã máy; tên biến dạng `RVA` là tên tạm.

## Kết luận luồng

```text
đánh giá trước đó
  -> nếu MaximumPending <= 0: tới 0x1e94f
  -> nạp cờ/góc giá dùng chung
  -> khối chung: kiểm trạng thái, quét vị thế/lệnh, giới hạn số lệnh
  -> nhánh giá bán: tìm đáy đủ điều kiện, chặn lệnh gần, dựng giá/SL/TP
  -> kiểm khối lượng, tiền ký quỹ, giới hạn tài khoản, khoảng cách giá
  -> gửi SELL_STOP; nếu lỗi 132 thì ngủ 2500 ms và gửi lại
  -> quay về 0x1cb01 hoặc 0x1e94f
```

## 1. Cổng đầu và khối chung

| RVA | Bằng chứng | Hành vi |
|---|---|---|
| `0x1ca24..0x1ca31` | so `DWORD[0x62458]` với 0; `jle 0x1e94f` | Không tiếp tục khi giới hạn lệnh chờ hiện hành không dương. |
| `0x1ca37..0x1caa7` | đọc byte `0x6a570`, `0x6a578`, hằng `0x4ffe8` | Nạp cờ và một giá trị dùng cho cả nhánh; chưa đủ bằng chứng đặt tên nghiệp vụ cho hai byte này. |
| `0x1cab6..0x1caf9` | gọi `0x26960`, sau đó `0x3c8d0`; kết quả false đi `0x1ce6e` | Khối đặt điều kiện giá bán dùng helper mức vào và helper lệnh gần. Các source tương ứng đã có: `Bot1EntryLevel` và `Bot1NearbyPending` trong `Bot1EntryLevels.mqh`. |
| `0x1cb01..0x1cb4f` | hủy các đối tượng tạm trên stack, tăng bộ đếm ở stack, so lại `0x62458` | Kết thúc một lượt; nếu bộ đếm đã chạm giới hạn thì đi `0x1e94f`. Không được thay thành một phép kiểm giới hạn cố định trước vòng. |
| `0x1cb55..0x1d0fe` | gọi `OrdersTotal`, `OrderGetTicket`, `OrderGetInteger(15)`, `OrderGetString`, `OrderGetInteger(4)`; có so loại `4` rồi `5` | Khối chung quét lệnh hiện tại. Mỗi lần quét dùng tổng lệnh và đi từ tổng đến 0; vé 0 bị bỏ; mã lệnh so với mã chiến lược dạng số nguyên có dấu; tên mã so toàn bộ; loại lệnh đọc sau điều kiện trước. |
| `0x1d110..0x1d5f5` | gọi `0x265a0` và các quét loại `4`/`5` | Khối đối xứng cho hướng còn lại nằm chung trong evaluator. Không coi việc xuất hiện cả hai loại là bằng chứng thứ tự mua/bán; nhánh này cần ghép với caller hoàn chỉnh. |

### Pseudocode phần quét có bằng chứng trực tiếp

```text
if maximum_pending <= 0:
    goto SAME_BAR

load live flags / live quote inputs

for each required scan:
    total = OrdersTotal()                 # từng helper tự đọc lại khi mã máy gọi lại
    for index = total down to 0:
        last_ticket = OrderGetTicket(index)
        if last_ticket == 0: continue
        if OrderGetInteger(ORDER_MAGIC) != (long)strategy_magic: continue
        if OrderGetString(ORDER_SYMBOL) != live_symbol: continue
        type = OrderGetInteger(ORDER_TYPE)
        # chỉ xử lý loại 4 hoặc 5 ở nhánh tương ứng
```

Nguồn có thể dùng lại cho quét/so lệnh: `Bot1OrderScan.mqh`,
`Bot1PendingSelection.mqh`, `Bot1EntryLevels.mqh`. Khi ghép phải giữ tham
chiếu sống cho `strategy_magic`, `symbol`, `last_ticket`, số lệnh tối đa và
giá trị mảng theo chỉ số chiến lược; không chụp chúng thành bản sao đầu hàm.

## 2. Tìm mức bán và chặn lệnh gần

Mã máy vào phần bán rõ tại `0x1db92..0x1e10f`.

```text
if candidate/base-price is above the current sell-side quote: stop current path
if bit 0 of 0x67910 is clear: stop current path

# lấy, làm tròn và lưu mức bán; mỗi lần đọc tên mã dùng con trỏ sống 0x67918
base = rounded live level
if base is NaN: stop

target = base - sell_offset * unit

if near_pending_sell(base, live_symbol, strategy_magic,
                     buy_offset, sell_offset, unit, radius, last_ticket):
    stop current path
```

Chứng cứ công thức:

- `0x1dc9c..0x1dd46` lấy `0x62578 - 0x62450 * 0x66d98`, là nhánh trừ
  khoảng cách bán theo đơn vị.
- `0x1dd5a..0x1ddac` gọi `0x3cb30` với cờ hướng bằng 1; đây là chặn lệnh
  gần của nhánh bán.
- `Bot1EntryLevels.mqh:20-23` có đúng công thức `level-sell_offset*unit`
  và ngưỡng `abs(price-target) < unit*radius`.

`Bot1EntryLevel` có thể dùng lại (`Bot1EntryLevels.mqh:31-84`) cho phần tìm
đáy/đỉnh xác nhận. Nó phải nhận tham chiếu sống tới `symbol`, `quote`,
`gap_points`, `unit`, `last_shift`, các độ rộng và `last_ticket`: mã máy gọi
dịch vụ giá nhiều lần, nên thay đổi trong các lần gọi có thể ảnh hưởng lần đọc
sau.

## 3. Dựng giá gửi và các cổng trước gửi

Phần bán đã thấy trực tiếp ở `0x1ddc9..0x1e075`:

```text
price = round(base - sell_offset*unit)
sl    = round(base + stop_distance*unit)
tp    = round(base - take_distance*unit)

if !ValidateVolume(live_symbol, volumes[live_strategy_index]): stop

limit = AccountInfoInteger(ACCOUNT_LIMIT_ORDERS)
if limit != 0 and OrdersTotal() >= limit: stop

bid = live_bid
if !(price + freeze_distance < bid): stop
if !(price + minimum_stop_distance < bid): stop
```

Chứng cứ: `0x1ddc9..0x1dff1` dựng ba giá; `0x1dffb..0x1e029` gọi kiểm khối
lượng và kiểm giới hạn tài khoản; `0x1e02f..0x1e06f` là hai so sánh chặt
`price + distance < bid` của lệnh bán.

Phần source tái sử dụng nguyên thân:

- `Bot1PendingSubmission.mqh:72-99`: làm tròn, kiểm khối lượng, giới hạn
  tài khoản, hai cổng khoảng cách của SELL_STOP.
- `Bot1VolumeValidation.mqh:5-35`: min/max/bước khối lượng.
- `Bot1Margin.mqh:18-30`: cổng ký quỹ (chỉ khi cờ `check_free_margin` bật).

Các trường phải là tham chiếu sống lúc dùng: `symbol`, `volumes[index]`,
`strategy_index`, `unit`, `stop_distance`, `take_distance`, `ask`, `bid`,
`minimum_stop_price`, `minimum_freeze_price`, và giới hạn tài khoản. Không
đưa các giá này vào cấu trúc sao chép từ đầu evaluator.

## 4. Gửi, hết hạn và gửi lại

Từ `0x1e075` mã máy chuẩn bị hai nhánh đọc cấu hình rồi đi các khối gửi
`0x1e383..0x1e8ee` (nhánh đầu và gửi lại). Các call tới `0x4a0` là gửi lệnh.

```text
first attempt:
    read omit_real_sl_tp
    read expiration
    if omit == 0: send calculated SL and TP; otherwise send 0,0
    send SELL_STOP with live symbol/comment/volume/magic/expiration

if first attempt accepted:
    ghi kết quả vào ô trống đầu tiên của results
else:
    while GetLastError() == 132:
        Sleep(2500)
        # retry đọc expiration trước omit_real_sl_tp
        gửi lại cùng price/sl/tp đã tính, nhưng các trường cấu hình đọc lại
    in lỗi cuối cùng, kể cả khi lần thử lại trả true
```

Nguồn tái sử dụng:

- `Bot1PendingSubmission.mqh:28-53,100-124` giữ đúng thứ tự đọc cấu hình
  của lần đầu/lần thử lại, vòng lỗi 132 và ghi `results`.
- `Bot1TradeSend.mqh:12-30` chọn gửi thường/bất đồng bộ và dựng yêu cầu.
- `Bot1PendingRequest.mqh` xử lý loại hết hạn và kiểm loại lệnh được phép.

Trường sống bắt buộc ở bước gửi: `omit_real_sl_tp`, `expiration`,
`virtual_expiration`, `comment`, `symbol`, `strategy_magic`,
`volumes[strategy_index]`, `async_mode`, `log_level`, `margin_mode`,
`error_count` và request/result của giao dịch. Giá `price/sl/tp` là giá đã
tính của lượt đó, không tính lại trong retry.

## 5. Quét vị thế và cờ

Các đoạn `0x1cb55..0x1d5f5` có thêm quét vị thế/lệnh và nhiều cờ trong stack;
đã thấy chắc chắn các cổng/điểm vào sau:

- `0x1cb8c` kiểm byte `0x62554`, sau đó gọi `0x34780`.
- `0x1ce35` kiểm byte `0x66a68`; `0x1ce50..0x1ce69` gọi helper khác khi cờ
  bật.
- `0x1d623` kiểm bit 0 của `0x67910`; cùng cổng này xuất hiện ở `0x1dba8`.
- `0x1d7c3` và `0x1dd4b` kiểm byte `0x62424` trước khi gọi `0x4cb30`.

Chưa có bằng chứng đủ để gán ý nghĩa nghiệp vụ độc lập cho `0x62554`,
`0x66a68`, `0x62424`, `0x6a570`, `0x6a578` hoặc mọi biến stack. Chúng phải
được đưa vào harness theo địa chỉ/chứng cứ trước khi ghép source; không thay
bằng điều kiện tự đoán.

## 6. Điểm nối cùng nến

Mọi nhánh dừng quay lại `0x1cb01` hoặc `0x1e94f`. Ở `0x1e94f`:

```text
call 0xffb0
if cached_hour(0x6779c) != last_hour(0x67448):
    last_hour = cached_hour
    call CleanPendingResults (0x32ce0)
```

`Bot1CleanPendingResults` đã có tại `Bot1OrderScan.mqh:29-41`, nhưng caller
hoàn chỉnh của đoạn trên chưa nằm trong nguồn MQL5 hiện hành.

## Chưa rõ / không được suy đoán

1. Ý nghĩa nghiệp vụ và đầu vào đầy đủ của các helper `0x34780`, `0x4c8d0`,
   `0x4cb30`, cũng như chuỗi kiểm ở `0x1cb55..0x1d5f5`.
2. Cách ghép chính xác nhánh mua và bán tại các điểm chung `0x1cb01`,
   `0x1e156`, `0x1e94f`.
3. Toàn bộ vòng đời UI và các helper ngoài evaluator.

Không được gọi nhánh bán là hoàn chỉnh trước khi các mục này có harness đối
chiếu với EX5 và caller MQL5 thật được ghép.
