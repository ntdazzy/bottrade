> BẢN NHÁP CHƯA ĐƯỢC CHẤP NHẬN. Xem REVIEW.md trước khi dùng.

# Đặc tả Bot 1: dừng lỗ theo khoảng cách thật

## Phạm vi và bằng chứng

- Bản gốc: `Gold Trade Pro MT5.ex5`, SHA-256 `a3b0de423a06e10ebedc279307b93d7cb9188ba2bb5de77131a913c865b0e922`.
- Cơ sở nạp: `0x23e5aa10000`. Thân mua là RVA `0x28220..0x28652`; thân bán là RVA `0x2bc82..0x2bfdf` (đầu cuối không tính).
- Lời gọi sửa dừng lỗ là `0x26d20`. Các chuỗi báo lỗi được dựng trong cùng thân; hàm dịch mã lỗi là `0x336d0`.
- Tài liệu này chỉ mô tả hai thân thật. Không dùng nó để kết luận EA hoàn chỉnh.

## Giao diện cần giao cho mã MQL5

Hai hàm trả về `bool`, nhận cùng dữ liệu vị thế, giá, cài đặt và trạng thái gửi lệnh như các hàm `Bot1AdvanceTimed...`. Tham số cần có: `symbol`, `unit`, `trail`, `step`, `start`, `limit`, `anchor`, `gap`, `freeze`, vị thế có `sl/tp/open_price/volume`, `MqlTick`, mảng khối lượng và chỉ số chiến lược, cờ `changed`, trạng thái gửi lệnh, độ lệch, bộ đếm lỗi và `ticket`.

`anchor` là giá tham chiếu đã được caller chọn từ bộ nhớ đệm; bằng chứng caller tại RVA `0x2c390` lưu giá tham chiếu cũ vào `xmm12`, rồi khôi phục tại `0x2c4bb`. Không tự đổi nó thành giá mở lệnh hoặc tự đọc bộ nhớ đệm trong hàm.

## Mua — thứ tự và công thức (RVA `0x28220..0x28652`)

1. Nếu `trail <= 0` thì trả `false` ngay (`0x28220..0x2822f`). Đọc giá Bid từ tick đã truyền (`xmm15`).
2. Đọc `SYMBOL_DIGITS`, rồi `SYMBOL_POINT` (`0x28231..0x28267`). Đặt `gate = Round((trail + step) * unit + (point + position.sl), digits)`. Chỉ đi tiếp khi `gate < bid` (`0x28269..0x28318`).
3. Đọc lại digits. Đặt `boundary = Round(start * unit + anchor, digits)`. Chỉ đi tiếp khi `boundary < bid` (`0x2831e..0x283d2`).
4. Đọc `SYMBOL_DIGITS` lần nữa; kiểm tra dừng đóng băng: `bid < position.tp - freeze` (`0x283d8..0x283ef`).
5. Đọc digits; đặt `cap = Round(limit * unit + position.open_price, digits)`. Chỉ đi tiếp khi `position.sl < cap` (`0x283f5..0x2849f`).
6. Đọc digits; đặt `candidate = Round(bid - trail * unit, digits)`. Ghi `position.sl = candidate` trước khi kiểm tra khoảng trống. Chỉ sửa lệnh khi `candidate < bid - gap` (`0x284a5..0x28570`). Vì đã ghi trước, nếu kiểm tra khoảng trống hỏng thì giá SL trong biến vẫn là candidate.
7. Gọi sửa lệnh tại `0x28576..0x28590`, truyền đúng `ticket`, `position.sl`, `position.tp`. Nếu thất bại, vẫn tiếp tục phần sau; dựng chuỗi kết thúc `"' when setting trailing Exit_stop_ loss.  Trying again!"`, gọi lấy lỗi một lần và tăng `error_count` qua helper (`0x28598..0x2861f`).
8. Sau lời gọi sửa, lấy `volumes[strategy_index]`, nhân với số 0 dạng số thực rồi làm tròn 2 chữ số (`0x28598..0x2861f`). Không thay phép nhân bằng hằng 0 để giữ NaN/Inf như bản gốc. Đánh dấu `changed=true` sau nhánh sửa. Nếu giá trị này không nhỏ hơn khối lượng vị thế, trả `false`. Đọc `SYMBOL_VOLUME_MIN`; nếu giá trị bằng 0 không đạt `minimum <= value`, trả `false`. Khi đạt, gọi hàm đóng vị thế với tick hiện có và trả `true` (`0x2861f..0x28652`). Việc gọi đóng và mã trả về của nó không được thay đổi thành kết quả sửa SL.

## Bán — thứ tự và công thức (RVA `0x2bc82..0x2bfdf`)

1. Nếu `trail <= 0` trả `false` (`0x2bc82..0x2bcff`). Đọc Ask. Đọc `SYMBOL_POINT` trước; chưa đọc digits. Dùng cùng `unit` đã chụp sau lần đọc point cho các kiểm đầu.
2. `gate = position.sl - point - (trail + step) * unit`; chỉ đi tiếp khi `ask < gate` (`0x2bd05..0x2bcff`).
3. `boundary = anchor - start * unit`; chỉ đi tiếp khi `ask < boundary` (`0x2bd05..0x2bd2d`).
4. Kiểm tra đóng băng `freeze + position.tp < ask` (`0x2bd33..0x2bd53`).
5. `cap = position.open_price - unit * limit`; chỉ đi tiếp khi `cap < position.sl` (`0x2bd59..0x2bd74`).
6. Đọc digits; tính lần đầu `candidate = Round(trail * unit + ask, digits)` và chỉ tiếp tục khi `candidate < position.sl` (`0x2bd7a..0x2be25`). Đọc digits lần hai, đọc lại Ask, tính lại cùng công thức, ghi `position.sl=candidate` trước kiểm gap; chỉ sửa khi `ask + gap < candidate` (`0x2be2b..0x2bef1`). Nếu gap hỏng, giữ candidate trong biến.
7. Gọi sửa tại `0x2bef7..0x2bf0f`. Nếu thất bại, dựng đúng hậu tố lỗi như nhánh mua và gọi helper lỗi (`0x2bf17..0x2bf96`). Sau đó đặt `changed=true`; dùng cùng kiểm khối lượng bằng `volumes[strategy_index] * 0`, `SYMBOL_VOLUME_MIN`, và gọi đóng nếu đạt (`0x2bf17..0x2bfdf`). Không làm mới tick trước lời gọi đóng.

## Làm tròn, so sánh và tác dụng phụ

- Mỗi lần native gọi digits/point đều phải giữ đúng vị trí; không gom các lần đọc thành một lần. `Round` là phép làm tròn giá của Bot 1 (thân dùng các lệnh chuyển số nguyên và bảng hệ số; hàm nguồn tương ứng là `Bot1RoundPrice`).
- Các điều kiện trên đều là so sánh chặt (`<`). `ucomisd` khiến NaN không qua điều kiện; không thay bằng `<=` hoặc kiểm tra NaN riêng.
- Giá SL được ghi vào bản sao vị thế trước kiểm gap ở cả hai phía. Cờ `changed` được đặt sau lời gọi sửa, kể cả sửa thất bại; nhánh trả `true` chỉ là nhánh đã qua kiểm khối lượng và đã gọi đóng.
- Không tự làm mới Bid/Ask. Không sửa TP. Không tăng bộ đếm lỗi nếu sửa thành công; khi sửa thất bại phải lấy lỗi và tăng đúng một lần.

## Chưa đủ bằng chứng

Địa chỉ và kiểu đầy đủ của caller cung cấp `unit`, `trail`, `step`, `start`, `limit`, `anchor`, `gap`, `freeze`, các trường vị thế và cờ `changed` cần ghép với hàm quản lý cha. Tài liệu này không tự xác nhận tên cài đặt giao diện hoặc hành vi toàn EA.
