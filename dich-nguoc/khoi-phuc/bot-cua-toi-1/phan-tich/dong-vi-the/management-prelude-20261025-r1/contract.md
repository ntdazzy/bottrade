# Phần đầu quản lý vị thế bot 1

Mô tả được viết trước nguồn. Chưa phải toàn bộ hai hàm quản lý.
Bản gốc SHA-256 `a3b0de423a06e10ebedc279307b93d7cb9188ba2bb5de77131a913c865b0e922`.
Nguồn bằng chứng: `../management-20261025-r1/analysis.json`, `functions.c`,
`native-guards.txt`; đầu mã `0x23e5aa10000`.

## Đọc và lọc

- Vị trí: mua `0x2737e..0x277c5`, bán `0x2ad4c..0x2b1c5`.
- Đọc vé theo chỉ số, ghi vé 64 bit vào `0x677f8`; vé 0 thì bỏ qua.
- Với vé khác 0: đọc số chữ số của mã giá đang quản lý; đọc dừng lỗ (6)
  và làm tròn. Lặp lại riêng cho chốt lời (7). Sau đó đổi vé từ số nguyên
  có dấu 64 bit sang số thực; đọc lại số chữ số, đọc giá mở (4), làm tròn.
- Đọc ghi chú (11), khối lượng (3), thời gian mở (1), loại (2), mã nhận
  diện (12), mã giá (0), theo đúng thứ tự. Các mã thuộc tính đã có nguồn
  đối chứng trong `doi-chung-mt5/chon-vi-the-dong-20261025/` và
  `doi-chung-mt5/dong-vi-the-20261024/`; không coi thuộc tính 3 là giá.
- Cập nhật giá gần nhất vào `0x67750`. Khi lỗi vẫn tiếp tục lọc, sau khi
  in đúng chuỗi `Tick not ok` (mô tả chuỗi tại `0x545c8`).
- Chỉ nhận khi 32 bit thấp của loại bằng 0 (mua) hoặc 1 (bán), 32 bit
  thấp của mã nhận diện bằng số int tại `0x6246c`, số int tại `0x62428`
  đúng bằng 1 và mã giá bằng chuỗi đang quản lý. Không tự kiểm số dương.
- Lệnh máy phân biệt con trỏ chuỗi trống và không có chuỗi; phép so MQL5
  phải được kiểm trước khi xác nhận phần này.

## Bổ sung dừng/chốt ban đầu

- Mua `0x277c5..0x27982`, bán `0x2b1c5..0x2b383` (lệnh gọi sửa
  cuối tại `0x2b381`, lệnh tiếp theo tại `0x2b383`).
- Dừng/chốt chỉ bổ sung khi giá trị đã làm tròn đúng bằng 0. NaN không
  thỏa. Số chữ số đọc trước mỗi lần tính. Dùng `Bot1RoundPrice` hiện có.
- Mua: dừng = giá mở − `0x62498` × `0x66d98`; chốt = giá mở +
  `0x624a0` × `0x66d98`. Bán đổi hai dấu. Không kiểm khoảng cách >0.
- Sau mỗi phép tính gọi hàm sửa `0x26d20` với cả dừng/chốt hiện tại;
  bỏ qua giá trị trả. Hai lần gọi độc lập; không đọc lại vị thế.
- Vé truyền là số thực đã đổi trở lại số nguyên có dấu 64 bit, rồi
  giữ nguyên bit khi truyền vé ulong; không dùng thẳng vé ban đầu.
- Hai cặp hằng làm tròn `0x50228/0x50230`, `0x50250/0x50258` đều được
  đọc trực tiếp: `-0.5000001/+0.5000001`. Không dùng làm tròn mặc định.

## Đóng theo nến

- Mua `0x27982..0x27c51`, bán phần trước `0x2b667`.
- Hai nhóm độc lập, mỗi nhóm chỉ bật khi byte tương ứng đúng bằng 1:
  `0x62265` dùng khung byte `0x62264`; `0x62267` dùng khung 0 nếu byte
  `0x62266` bằng 0, còn lại dùng 30. Không hiểu byte là khung int đầy đủ.
- Mỗi nhóm kiểm `iTime(khung,1) <= thời gian mở < iTime(khung,0)`;
  chỉ gọi bước sau khi điều kiện trước đạt. Đọc lại khung tại từng lời gọi.
- Đọc giá đóng nến 1, rồi giá mở nến 1. Mua cần đóng < mở; bán cần
  mở < đóng. Sau đó đọc lại giá đóng nến 1: mua cần đóng < giá mở vị
  thế; bán cần giá mở vị thế < đóng. Đây là hai lần đọc riêng.
- Nếu đủ điều kiện, gọi hàm đóng `0x3d010` với vé qua số thực như trên,
  rồi in `closing candle confirmation` (`0x55858`). Không thoát sớm;
  nhóm nến thứ hai vẫn chạy và các bước dời dừng sau đó vẫn chạy.
- `iTime`, `iOpen`, `iClose` lần lượt là địa chỉ máy MT5 +`0x7d3b50`,
  +`0x7d3bc0`, +`0x7d3d40`, khớp bảng chữ ký trong bản chụp. Khi cần
  chứng minh thêm bằng chương trình có nguồn, ghi riêng giới hạn này.

## Ranh giới còn thiếu

Chưa xác nhận đầy đủ hai hàm: vòng quét ngoài, bảng 100 vé/giá mở,
các nhánh dời dừng thật/ảo, các thông báo lỗi, đọc lại dữ liệu giữa
lời gọi, bit giá trị trả và lỗi bộ nhớ. Không viết hàm rỗng cho các phần
này; không gọi phần đầu đã dựng là hai hàm quản lý hoàn chỉnh.
