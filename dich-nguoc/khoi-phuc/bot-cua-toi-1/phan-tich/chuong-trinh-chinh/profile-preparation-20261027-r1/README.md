# Bot 1 — nạp cấu hình nối với chuẩn bị dữ liệu

Đã thêm dạng gọi `Bot1LoadRuntimeProfile` nhận `Bot1PreparationInputs` để
truyền trực tiếp sang `Bot1PrepareStrategy`. Hàm cũ nhận `Bot1DistanceInputs`
giữ nguyên. Chỉ chép các trường cấu hình đã chứng minh, giữ các cờ/chủ thể
chung do nơi gọi cấp.

## Sáu trường bổ sung từ native

Hai lượt `b1-full-inputs-20261027-r1/r2` chạy nguyên lệnh máy cho tám cấu
hình, HL 0/1 và randomization dương/0. Mỗi cấu hình ghi đủ **28 trường,
142 byte**, không đọc thanh ghi chưa ghi. Các bảng:

| Trường | RVA | Giá trị theo chỉ số 0..7 |
|---|---|---|
| indicator_period | 0x621c4 | 53, 97, 58, 47, 100, 99, 95, 145 |
| indicator_day | 0x621c8 | 1, 1, 1, 1, 1, 1, 1, 1 |
| native_622a8 | 0x622a8 | 1, 1, 1, 1, 1, 1, 1, 1 |
| native_622ec | 0x622ec | 1, 5, 1, 1, 1, 1, 1, 1 |
| native_622f0 | 0x622f0 | 1, 0, 1, 1, 1, 1, 1, 1 |
| native_62360 | 0x62360 | 800, 400, 700, 100, 600, 300, 100, 100 |

Ô cuối được giữ trong `Bot1ProfileRuntimeState`; chưa đổi sang tên chức
năng vì chưa chốt nơi dùng. Không lấy chu kỳ chỉ báo từ khung nến vào lệnh.

## Phép so nối hai bước

`b1-profile-preparation-20261027-r3`: **432/432 ca khớp** 119 giá trị, gồm
hạt giống, đủ trường nạp, trạng thái sau chuẩn bị, thứ tự dịch vụ và đối số
ATR. Hai thân native chạy nối tiếp trong cùng bộ nhớ; không chép kết quả
MQL5 hay kết quả mong đợi vào bộ nhớ native. Kết quả hai phía cùng SHA-256:
`80c2d91578aa7c454210396b228c1269ad31c397308f175b795aa015daceac81`.

Script API và Script kiểm biên dịch **0 lỗi, 0 cảnh báo**. Thêm lượt kiểm
giao diện cũ `b1-runtime-profile-20261027-r2`: **432/432** vẫn khớp.

## Phần chưa nằm trong phép so

Đoạn cấp tên mã, comment và đổi tiền/vốn ở giữa hai bước được cấp cùng dữ
liệu, chưa chạy thân gốc đoạn đó. Chưa có nơi gọi từ EA chính, chưa chứng
minh vòng đời, menu/hiển thị hoặc chạy hai EA hoàn chỉnh. Không dùng kết quả
hai bước này làm kết luận toàn dispatcher hoặc toàn bot đã khôi phục xong.
