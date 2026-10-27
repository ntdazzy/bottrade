> Ghi chú phân tích chưa được quản lý xác nhận đầy đủ; không dùng thay bản đồ native/bộ kiểm.

# Khác biệt có chứng cứ: vòng vào lệnh Bot 3 so với Bot 1

Phạm vi B3: `0x26f9e..0x29c88`. So sánh với C đầy đủ B1 trong evaluator
`0x1ca24..0x1e94f`. Chỉ nêu khác biệt đã thấy trong mã máy/source hiện có.

## 1. Nhóm mã lệnh dùng trong cổng vị thế

- B3 tại `0x275a8..0x27725` (mua) và `0x286a8..0x28825` (bán) tạo và so
  **15** mã liên tiếp từ `INT32[0x1d6ff0] + 1` đến `+15`. Giá trị so là số
  nguyên 64-bit đã mở rộng dấu từ phép cộng 32-bit. Quét đi từ
  `OrdersTotal()` đến 0, bỏ vé 0, rồi mới xét nhóm mã.
- Đây không phải phép so bằng `strategy_magic` đơn lẻ của các hàm đếm lệnh
  chờ. Khi ghép cổng vị thế B3, phải giữ phép cộng/tràn 32-bit rồi mở rộng
  dấu; không thay bằng `ulong` hoặc so chuỗi.
- B1 C ở cổng vị thế tương ứng so trực tiếp với
  `INT32[0x6246c]` (ví dụ `0x1cc99..0x1cde3`, `0x1d1a6..0x1d287`). Vì vậy
  không tái dùng cổng nhóm 15 mã của B3 cho B1.

## 2. Cờ mua/bán và thứ tự quét

- B3 nạp hai cờ tại `0x1d6f80` và `0x1d6f88` vào biến stack **một lần** ở
  đầu lượt trước các đoạn cổng. Các nhánh mua/bán sau đó dùng bản đã nạp,
  không đọc lại địa chỉ cờ giữa vòng.
- Các quét lệnh/vị thế không có một tổng dùng chung: B3 gọi lại
  `OrdersTotal()`/`PositionsTotal()` trong từng khối đếm/chọn. Vòng lệnh
  chờ đi giảm từ `total` đến `0`; vòng vị thế ở những cổng chặn đi tăng và
  đọc `PositionsTotal()` lại sau từng phần tử (đã thấy chuỗi này ở
  `0x27263..0x273d2`, `0x27442..0x2753d`, rồi lặp lại cho nhánh bán).
- Do đó các cờ đã chụp là cố định trong lượt, nhưng tổng, vé, mã, tên mã,
  loại và giá là dữ liệu sống tại từng lần gọi dịch vụ.

## 3. Đếm đúng bằng mức tối đa và thay lệnh

- B3 chỉ đi vào thay lệnh khi `count == maximum`, không phải `>=`:
  - mua: `0x27be6..0x280b5`;
  - bán: `0x28cc6..0x291a4`.
- Trong hai đoạn này B3 quét lại lệnh loại 4/5, lấy giá mở lại khi cần và
  giữ cực trị để so với mức mới. Cực trị mua/bán là đối xứng; phải giữ so
  sánh chặt, bao gồm nhánh giá bằng nhau không thay lệnh.
- Nếu mức mới không tốt hơn cực trị giữ được, nhánh dừng trước gửi. Nếu tốt
  hơn, execution đi tiếp tới mức vào và gửi. Không được thay bằng xóa cực
  trị vô điều kiện chỉ vì `count == maximum`.

## 4. Helper tìm mức và lệnh gần

- B3 dùng `0x31cd0` (mua) và `0x32090` (bán), sau đó dùng `0x47380` và
  `0x475e0` để chặn lệnh gần: `0x27a48..0x27a6e` và
  `0x28b28..0x28b4e`.
- Các phần này dùng lại trực tiếp `Bot3EntryLevel` và `Bot3NearbyPending`
  trong `Bot3EntryLevels.mqh:7-84`. Hợp đồng giữ nguyên: `symbol`,
  `strategy_magic`, `buy_offset`, `sell_offset`, `unit`, `radius`,
  `last_shift`, quote và `last_ticket` phải là tham chiếu sống.
- Địa chỉ nguồn mức B3 dùng chỉ số động `0x74934`; không chụp chỉ số trước
  helper rồi dùng lại cho giá/kết quả sau helper.

## 5. Khối lượng, hạn lệnh và hết hạn

- Cập nhật khối lượng B3 gọi helper chuẩn `0x3f900` tại `0x2718c..0x27196`;
  đây đã khớp `Bot3VolumeRuntime.mqh`, không cần dựng lại.
- Hạn lệnh chờ B3 không dùng trực tiếp mẫu B1
  `AccountInfoInteger(ACCOUNT_LIMIT_ORDERS)`. `Bot3PendingSubmission.mqh:73`
  gọi `Bot3AllowsPendingOrder()`; giữ đúng helper B3 này khi ghép.
- Hết hạn/chế độ gửi dùng `Bot3OpenPending`/`Bot3PreparePendingRequest`
  (`0x3e580`; source `Bot3PendingRequest.mqh:13-92`) và đã có nguồn thật.
  Không thay bằng yêu cầu hết hạn của B1.

## 6. Khác biệt thực chất khi gửi lại

- B1 đọc `omit_real_sl_tp` trước `expiration` ở lần đầu, đảo thứ tự ở retry.
- B3 luôn đọc `expiration` rồi `omit_real_sl_tp` ở cả lần đầu và retry:
  `Bot3PendingSubmission.mqh:27-41,99-104`. Đây là khác biệt phải giữ, vì
  hai trường có thể thay đổi trong lúc dịch vụ gửi/sleep.
- Cả B3 và B1 giữ giá đã tính cho retry; retry vẫn đọc lại cấu hình gửi,
  khối lượng, tên mã, magic và cờ gửi bất đồng bộ qua `Bot3SendPendingEntry`.

## 7. Giá 0/NaN, SL/TP và ký quỹ

- B3 dùng cùng các cổng số học đã có source: signed zero cho giá, `base +
  stop*unit` và `base - take*unit` cho SELL_STOP; hai cổng chặt
  `price + freeze < bid` và `price + stop < bid`:
  `Bot3PendingSubmission.mqh:59-85`.
- Không thấy khác biệt B3/B1 có chứng cứ ở quy tắc NaN, làm tròn, SL/TP hay
  `Bot3MarginGuard`; dùng source B3 hiện có, không thêm điều kiện mới.

## 8. Trường dùng chung phải nối bằng tham chiếu sống

| Nhóm | Nguồn chuẩn B3 |
|---|---|
| thực thi | `Bot3NfpExecution`: `strategy_magic`, `magic_base`, `symbol`, `reference_a`, `reference_b`, `threshold_a`, `gap`, `last_ticket`, `trade`, `options` (`Bot3NfpFilter.mqh:19-27`) |
| hàng đợi/phục hồi | `Bot3PendingQueue`, `Bot3PendingRestoreSettings`: hàng đợi, cờ, `sl_distance`, `tp_distance`, `expiration_base`, `comment`, `virtual_expiration` |
| gửi lệnh | `Bot3PendingSubmissionSettings`: tên mã, comment, cờ ký quỹ/SLTP/hết hạn, magic, expiration, unit, stop/take, hai khoảng cách tối thiểu, ask/bid (`Bot3PendingSubmission.mqh:10-18`) |
| khối lượng | `Bot3VolumeState`, mảng `volumes[]`, chỉ số chiến lược, giới hạn và dữ liệu rút tiền (`Bot3VolumeRuntime.mqh:10-102`) |

Các giá trị kể trên không được sao chép một lần ở đầu evaluator nếu helper có
thể làm thay đổi chúng. Riêng hai cờ `0x1d6f80/0x1d6f88` là ngoại lệ đã thấy:
chúng được chụp một lần cho lượt hiện tại.

## Giới hạn

Tài liệu này chỉ chốt khác biệt B3/B1 trong đoạn được yêu cầu. Nó không xác
nhận evaluator/EA hoàn chỉnh và không thay cho phép đối chiếu chạy với EX5.
