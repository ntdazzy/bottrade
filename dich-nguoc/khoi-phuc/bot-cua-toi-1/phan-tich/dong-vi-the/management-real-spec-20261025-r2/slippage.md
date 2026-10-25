> BẢN NHÁP CHƯA ĐƯỢC CHẤP NHẬN. Xem REVIEW.md trước khi dùng.

# Đặc tả Bot 1: dừng lỗ chống trượt thật

## Phạm vi và bằng chứng

- Bản gốc: `Gold Trade Pro MT5.ex5`, SHA-256 `a3b0de423a06e10ebedc279307b93d7cb9188ba2bb5de77131a913c865b0e922`; cơ sở `0x23e5aa10000`.
- Thân mua: RVA `0x2865c..0x28aed`; thân bán: RVA `0x2bfdf..0x2c36e` (đầu cuối không tính).
- Lời gọi sửa là RVA `0x26d20`; helper báo lỗi là RVA `0x336d0`. Caller giữ giá tham chiếu đã chọn: lưu vào `xmm12` tại `0x2c390` và khôi phục vào `xmm15` tại `0x2c4bb`; hàm nhận đúng giá này, không tự chọn lại.

## Giao diện

Hàm mua và bán trả về `void`, nhận `symbol`, `unit`, cờ bật, cờ `distance_passed`, `reference`, `trail`, `start`, `limit`, `gap`, `freeze`, vị thế (`sl`, `tp`, `open_price`), `MqlTick`, cờ `changed`, trạng thái gửi lệnh, bộ đếm lỗi và `ticket`. `reference` là giá caller đã chọn; không mặc định là `open_price`.

## Mua — RVA `0x2865c..0x28aed`

1. Chỉ chạy khi global bật bằng 1 và bit thấp của `distance_passed` bằng 1 (`0x2865c..0x28672`). Nếu `trail <= 0` trả ngay (`0x28678..0x2868b`).
2. Đọc Bid, digits, point. `gate = Round(trail * unit + (point + position.sl), digits)`; yêu cầu `gate < bid` (`0x28691..0x2875e`).
3. Đọc lại Bid và digits. `boundary = Round(start * unit + reference, digits)`; yêu cầu `boundary < bid` (`0x2877d..0x28828`).
4. Kiểm tra `bid < position.tp - freeze` (`0x28833..0x2884a`).
5. Đọc digits. `limit_price = Round(limit * unit + position.open_price, digits)`; yêu cầu `position.sl < limit_price` (`0x28850..0x288f5`).
6. Đọc digits, đọc lại Bid, tính `new_sl = Round(bid - trail * unit, digits)`, ghi `position.sl=new_sl`; chỉ tiếp tục khi `new_sl < bid - gap` (`0x28900..0x289c9`).
7. Gọi sửa `ticket, position.sl, position.tp` (`0x289cf..0x289e7`). Nếu thành công in đúng `"Slippage control active"`; nếu thất bại gọi helper lỗi với hậu tố `"' when setting Slip TL.  Trying again!"` (`0x289e9..0x28ac6`). Dù thành công hay thất bại, đặt `changed=true` tại cuối thân (`0x28ac1..0x28ae8`). Không đóng vị thế, không đổi TP.

## Bán — RVA `0x2bfdf..0x2c36e`

1. Điều kiện bật và bit distance giống mua (`0x2bfdf..0x2c00e`); `trail <= 0` trả ngay.
2. Đọc Ask và point; trước các kiểm đầu không đọc digits, không làm tròn. Dùng `captured_unit=unit`. `gate = position.sl - point - trail * captured_unit`; yêu cầu `ask < gate` (`0x2c014..0x2c065`).
3. Đọc lại Ask. `boundary = reference - start * captured_unit`; yêu cầu `ask < boundary` (`0x2c06b..0x2c08f`).
4. Yêu cầu `freeze + position.tp < ask` (`0x2c095..0x2c0ab`).
5. `limit_price = position.open_price - captured_unit * limit`; yêu cầu `limit_price < position.sl` (`0x2c0b1..0x2c0cc`).
6. Đọc digits; tính lần đầu `gate2=Round(trail * unit + ask, digits)`; yêu cầu `gate2 < position.sl` (`0x2c0d2..0x2c178`). Đọc digits lần hai, đọc lại Ask, tính `new_sl=Round(trail * unit + ask, digits)`, ghi trước; yêu cầu `ask + gap < new_sl` (`0x2c183..0x2c249`).
7. Gọi sửa. Thành công in đúng chuỗi gốc `"Slippage controle active"` (chính tả này có chữ `controle`); thất bại gọi helper với hậu tố như mua. Sau cả hai nhánh đặt `changed=true` (`0x2c24f..0x2c369`). Không đóng vị thế, không làm mới tick.

## Quy tắc chung và phần còn thiếu

- Giữ từng lần đọc digits/point/tick theo thứ tự trên. Dùng so sánh chặt `<`; `ucomisd` xử lý NaN như bản gốc, không thêm luật.
- Ghi SL trước kiểm gap và giữ giá đã ghi khi gap không đạt. Cờ `changed` chỉ được đặt sau lời gọi sửa và báo lỗi.
- Không tự thay `reference` bằng cache hoặc giá mở. Chưa có bằng chứng độc lập về tên tham số cài đặt trong EA cha, kiểu chính xác của cờ trên stack và nội dung đầy đủ của các helper gửi lệnh; cần đối chiếu khi ghép mã.
