# Hàng đợi 100 lệnh chờ — bot 1 và 3

Đã dựng `BotNPendingQueue.mqh`: **374/374 ca mỗi bot khớp** toàn bộ
500 số của hai bảng, cờ/bộ đếm/lỗi, dữ liệu dùng chung và thứ tự/
đối số tạo lệnh, in thông báo, chờ. Chạy bằng script và bằng bộ máy
đo lại quá khứ đều cho cùng từng byte. Bản `bN-pending-queue-03` và
chương trình kiểm trong máy thử biên dịch 0 lỗi, 0 cảnh báo.
[Biên nhận và giới hạn](KIEM-CHUNG-HANG-DOI-BOT-1-3-R2.json).

Phân tích trước khi dựng: bot 1 `0x2e6d0..0x2f5b8`, C 19415–19768;
bot 3 `0x3bb10..0x3c9f8`, C 25736–26089. Đã đọc cả hai thân hàm,
đối số máy thật của bốn lời gọi tạo lệnh và các chuỗi; có agent chỉ
đọc kiểm lại. Những nhầm địa chỉ/chuỗi của lượt đọc ban đầu đã được
đối chiếu và sửa trước khi dựng nguồn.

| Dữ liệu | Bot 1, RVA | Bot 3, RVA |
|---|---|---|
| Cờ chạy, 1 byte | `0x66420` | `0x73468` |
| 100 hàng, mỗi hàng 3 số double: giá, loại, khối lượng | `0x65470` | `0x724b0` |
| 100 kết quả, mỗi hàng 2 số double: kết quả gửi, giá sau gửi | `0x65dd0` | `0x72e10` |
| Giá mua/bán, khoảng cách | `0x67760/0x67758/0x66a70` | `0x747a0/0x74798/0x73ab0` |
| Khoảng dừng/chốt, đơn vị | `0x62498/0x624a0/0x66d98` | `0x6d588/0x6d590/0x73dd8` |
| Mốc thời hạn | `0x67450` | `0x74490` |
| Mã giá/ghi chú động | `0x67918/0x62470` | `0x74958/0x6d568` |
| Lỗi cuối/bộ đếm lỗi | `0x6a410/0x6744c` | `0x1d6e10/0x7448c` |

1. Chỉ vào hàm khi cờ bằng đúng 1. Quét hàng 0..99 theo thứ tự.
   Giá phải >0; loại phải bằng đúng double 4 hoặc 5. `NaN` bị bỏ;
   riêng giá dương vô hạn vẫn qua phép so >0.
2. Loại 4 cần `giá - khoảng cách > giá mua`; loại 5 cần
   `giá + khoảng cách < giá bán`. Bằng ngưỡng hoặc `NaN` thì bỏ.
3. In `Restoring pending buy-order` hoặc `Restoring pending sell-order`
   trước lần gọi đầu. Sau đó chép ghi chú, cộng mốc thời hạn với
   172800 bằng số nguyên 64 bit, tính dừng/chốt rồi chép mã giá.
   Loại 4: dừng = giá − khoảng dừng × đơn vị; chốt = giá + khoảng chốt
   × đơn vị. Loại 5 đảo hai dấu. Khối lượng là double, không phải int.
4. Sau mỗi lần gọi tạo/gửi, tìm kết quả đầu tiên có ô thứ nhất ==0;
   `NaN` không phải ô rỗng. Ghi `double(uint32(EAX))` và giá được đọc
   lại sau lời gọi. Đây là kết quả 0/1 của hàm tạo/gửi, không phải vé lệnh.
5. Nếu lần đầu trả 0: khi lỗi cuối ==132, chờ 2500 ms rồi đọc lại ghi
   chú, mốc thời hạn, giá, khối lượng, hai khoảng và đơn vị để thử lại.
   Không in lại dòng đầu, không kiểm lại loại/giá mua/bán/khoảng cách.
   **Sau thử lại chỉ kiểm mã lỗi, không kiểm kết quả gửi**; giữ nguyên
   hành vi có thể tiếp tục lặp dù lần gửi lại đã trả thành công.
6. Khi lỗi khác 132, gọi hàm đổi mã lỗi rồi in
   `error: '` + nội dung lỗi + `' when setting entry order`.
   Sau nhánh loại 4, đọc lại loại để xét loại 5; lời gọi trước đó có
   thể thay dữ liệu. Sau mỗi hàng, chỉ tiếp tục khi bit thấp cờ là 1.
7. Cuối hàm chỉ xóa đủ 2400 byte hàng đợi khi bit thấp cờ còn là 1.
   Giữ bảng kết quả. Không tự thêm giới hạn thử lại hoặc sửa hành vi lạ.

Chuỗi đầu mua có descriptor `0x55108/0x5d868`; đầu bán
`0x551e8/0x5d948`; tiền tố lỗi `0x55140/0x5d8a0`, hậu tố tại
`0x5515c/0x5d8bc`. Các địa chỉ tính từ đầu vùng mã, không lấy đuôi
địa chỉ tuyệt đối làm RVA.

## Kết quả và phần còn thiếu

- Script: [bot 1](bot-cua-toi-1/bang-chung/kiem-hang-doi/queue-20261024-r3/comparison.json),
  [bot 3](bot-cua-toi-3/bang-chung/kiem-hang-doi/queue-20261024-r3/comparison.json).
- Bộ máy đo lại quá khứ: [bot 1](doi-chung-mt5/hang-doi-20261024/engine-b1-r3/comparison.json),
  [bot 3](doi-chung-mt5/hang-doi-20261024/engine-b3-r3/comparison.json).
- Có các ca cờ 0/1/2/3/255, hàng đầu/cuối, bảng kết quả đầy, giá sát
  ngưỡng, hai chiều, 100 hàng, thử lại nhiều lần và thay dữ liệu ngay
  sau lời gọi. Cả hai chương trình chỉ cấp kết quả tạo lệnh và giả lập
  chờ; không gửi lệnh hoặc chờ 2500 ms thật trong hàng đợi.
- Đã đọc hai lần `GetLastError()` trên MT5 thật: giá trị 65668 được
  giữ nguyên ở cả hai lần. Phần kiểm hàng đợi cấp lỗi rõ ràng theo từng
  lần tạo lệnh; không tự xóa lỗi giữa các lần đọc.

Lượt `r1/r2` khớp 232/236 ca; bốn ca lệch ở dấu của số không xác định.
Đã đọc mã máy của nguồn mới: trình biên dịch gộp các nhánh thành đổi
dấu rồi cộng, làm khác phép trừ của gốc. Nguồn hiện hành dùng ba hàm
số học nhỏ giữ đúng thứ tự toán hạng và phần số không xác định; không
thay đổi điều kiện giao dịch. `r3` thêm 138 ca gồm dấu/phần dữ liệu
khác nhau của `NaN`, số báo lỗi và số 0 có dấu. Các bản lúc lệch giữ
nguyên trong `tested-sources/`; không tính lượt lỗi là đạt.

Đã đo trực tiếp 25 cặp số trong MT5, gồm các dạng `NaN`, bằng hàm
phép trừ có nguồn và đã đọc mã máy; [kết quả](doi-chung-mt5/hang-doi-20261024/arithmetic-runtime-r2/results.json).
Phát hiện bộ mô phỏng CPU chọn phần dữ liệu `NaN` khác CPU thật khi
cả hai toán hạng là `NaN`. Bộ kiểm hàng đợi chỉ sửa quy tắc chọn đó
theo phép đo độc lập; phép tính thường vẫn chạy mã máy gốc. Không lấy
hàm số học của nguồn hàng đợi làm kết quả mong đợi.
[Quá trình xác định nguyên nhân](danh-gia-doc-lap/hang-doi-20261024/nan-checkpoint.md).

Dịch vụ xóa vùng nhớ gốc được cấp riêng sau khi kiểm đủ địa chỉ hàng
đợi, giá trị 0 và độ dài 2400; đã đối chứng `ZeroMemory` có nguồn tới
đúng địa chỉ MT5 `0xacad20`. Chưa mô phỏng mọi lỗi của bộ nhớ/CPU.

Phép kiểm riêng trên vẫn cấp kết quả tạo lệnh. Lượt mới đã
[so chung hàng đợi → tạo yêu cầu → gửi → thông báo](PHAN-TICH-CHUOI-DAT-LENH-BOT-1-3.md),
khớp 818 ca mỗi bot, cả chương trình MQL5 và máy đo quá khứ. Thân
hàm tạo lệnh gốc chạy thật; kết quả ở ranh giới gửi/thuộc tính vẫn
được cấp. Chưa có EA đầy đủ, kết quả nơi giao dịch, toàn bộ cài đặt,
hiển thị hoặc kiểm khởi động lại. Không đánh dấu toàn bộ P16/P31 hoàn tất.
