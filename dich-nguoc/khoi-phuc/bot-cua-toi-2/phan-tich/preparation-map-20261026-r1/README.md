# Bản đồ khối chuẩn bị tham số chiến lược — bot 2

**Bản nháp chưa được chấp nhận để viết mã.** Root đã phát hiện nhánh
và tên giá trị bị ghi sai trong nội dung dưới đây; đọc [ROOT-REVIEW.md](ROOT-REVIEW.md).
Các kết luận “đã chốt” trong bản nháp này không có hiệu lực.

## Phạm vi và bằng chứng

Khối được chốt là `FUN_253f2627550(undefined4 param_1)` trong mã C trung gian mới.
Đây là khối chuẩn bị dữ liệu chỉ báo, thông tin mã và các tham số đã đọc trước đó
để dùng ở các bước xử lý sau. Chưa coi đây là toàn bộ phần khởi động hay toàn EA.

| Mục | Giá trị |
|---|---|
| Bản gốc cài đặt | `OriginalB2`, SHA-256 `390d8ab14fc213ff4b8cbe5084bec545526e62c6028516fe21219a59398ce795` |
| Mã native đối chiếu | `metadata/codefile` `00000253f2620000.bin` |
| SHA-256 codefile | `ae4e9020f7f5f08d49774728bed14c17eb2bd26b6271c20da51bd3aaa446014f` |
| SHA-256 C trung gian | `445a0e71fb7aac36d64a2e9724270468e0b61c24edcf5246471497cde1ca28f3` |
| Địa chỉ bắt đầu/kết thúc | `0x253f2627550` / `0x253f26283c4` |
| RVA tính từ fullbase `0x253f2620000` | `0x7550..0x83c4` |
| Độ dài dùng để băm | `0x83c4 - 0x7550 = 0xE74` byte |
| SHA-256 bytes native của dải | `dcd19e9d1581d0d4e68a1f8c1e293a83c1a4cb1f17de08a506e1e74f4d762141` |

Độ dài và SHA bytes trên được kiểm trực tiếp từ `00000253f2620000.bin`, lấy lát
`[0x7550, 0x83c4)`; không cắt địa chỉ thành 5 chữ số. Metadata inventory-v3
ghi cùng `native_body_sha256`, khai báo C ở dòng 3650, và các lời gọi native
`MT5_CopyBuffer`, `MT5_Dispatch`, `MT5_SymbolInfoDouble`,
`MT5_SymbolInfoInteger`, `MT5_SymbolInfoTick`, `MT5_TimeCurrent`, `MT5_iOpen`.

## Giao diện và kiểu dữ liệu đã thấy

- Đầu vào: `param_1` là `undefined4`, được ghi nguyên dạng vào ô trạng thái
  `DAT_253f267e5834` (RVA `0x65834`). Chưa có bằng chứng trực tiếp để đặt tên
  hoặc đổi nó thành kiểu MQL5 khác.
- Kết quả trả về: `void`.
- Bộ nhớ trạng thái: các ô toàn cục tại RVA `0x5e16c..0x5e548`, `0x64cd8`,
  `0x64ce0`, `0x65390`, `0x653a8`, `0x65690..0x656d0`, `0x65834..0x65868`,
  `0x66228..0x66230`, `0x68448`, `0x685c0..0x685f8`, `0x68738..0x68788`.
  Kiểu được ghi dưới đây chỉ là kiểu thấy trong phép toán native (`double`,
  số nguyên 32 bit, byte hoặc kết quả `longlong`); tên tham số gốc chưa biết.

## Thứ tự xử lý và điều kiện

1. Gọi `MT5_Dispatch(..., 0x53, 3)`; ép kết quả thành số nguyên và ghi vào
   `DAT_253f267e16c` (RVA `0x5e16c`). Nếu kết quả < 0, gọi
   `MT5_Dispatch(..., 2, 2, 0x590008)` rồi trả về.
2. Gọi `MT5_CopyBuffer(..., handle, 0, 0, 100, &DAT_253f267e170)`.
   Nếu trả 0, trả về ngay. Nếu cờ 4 bit thấp của trường tại `0x5e174` khác
   0, đặt thêm bit `0x10`.
3. Nếu trường đếm tại `0x5e178 < 2`, gọi lỗi bộ nhớ với mã
   `0xd078f000001f6`, sau đó đi tới lỗi mã `0x230862000001f7`.
4. Ngược lại, lấy `dVar8 = DAT_253f266cd90` (RVA `0x4cd90`, `double`).
   Nếu `DAT_253f267e1a8` (RVA `0x5e1a8`) <= 0, dùng giá mở cửa
   `MT5_iOpen(symbol, 0x4018, 1)`; nếu giá này khác 0 thì tính
   `dVar8 = DAT_253f2688448 / DAT_253f267e1a8`. Nếu không đi được nhánh này,
   dùng `DAT_253f266cd90` khi byte `DAT_253f267e1fd` bằng 0.
5. Ghi `DAT_253f2686228 = dVar8 == 0 ? DAT_253f266cd90 : dVar8` và nếu byte
   `DAT_253f2688788` khác 0 thì ghi `DAT_253f266cd90 / DAT_253f2686228` vào
   `DAT_253f2686230`. Ghi `param_1` vào `DAT_253f2685834`.
6. Gọi `MT5_SymbolInfoTick`; nếu thất bại, gọi `MT5_Dispatch(...,2,1,0x590008)`.
   Gọi `MT5_TimeCurrent`, rồi `MT5_SymbolInfoDouble(symbol, 0x10)`; sao chép
   giá trị trả qua vùng `DAT_253f2688448` vào `0x65868` và `0x64cd8`.
7. Đọc `MT5_SymbolInfoInteger(symbol, 0x11)` nhiều lần. Nếu kết quả 3 hoặc
   5, đặt `0x64cd8 = 0x65868 * DAT_253f266cd98` (RVA `0x4cd98`, `double`).
   Nếu kết quả 1, đặt `0x64cd8 = 0x65868 / DAT_253f266cd98`.
8. Tính `DAT_253f267e558 = DAT_253f26856a0 - DAT_253f2685698`.
   Sau đó sao chép tuần tự các tham số đã có vào vùng chuẩn bị `0x5e3dc..0x5e548`.
   Các phép nhân thấy trực tiếp gồm:
   - `0x5e448 = 0x5e278 * 0x66228`;
   - `0x5e450 = 0x5e280 * 0x66228`, rồi làm tròn về số nguyên theo hằng số tại
     `0x4cda0` chọn theo dấu;
   - `0x5e458 = 0x5e288 * 0x66228`, làm tròn cùng cách;
   - `0x5e468 = 0x5e298 * 0x66228`;
   - `0x5e4a0 = 0x5e2d8 * 0x66228`;
   - `0x5e4a8 = 0x5e2e0 * 0x66228`;
   - `0x5e4b0`, `0x5e4b8`, `0x5e4c0`, `0x5e4c8`, `0x5e328`, `0x5e330`,
     `0x5e4d0`, `0x5e4d8` lần lượt nhân tham số nguồn tương ứng với `0x66228`.
   - Các ô byte/số nguyên `0x5e4e0..0x5e4e8`, `0x5e500`, `0x5e510` được đặt
     về 0 hoặc chép từ nguồn; đây là thao tác trạng thái, chưa biết ý nghĩa.
9. Sao chép chuỗi/đối tượng `0x5e488` từ `0x5e2b8` bằng
   `FUN_253f26205c0(..., 0, ...)`; đây là tác dụng phụ cấp phát/giảm tham chiếu
   của bộ nhớ chuỗi, không phải phép tính tham số.
10. Tính `dVar3 = 0x5e518 * 0x64cd8`. Nếu nhỏ hơn giá trị symbol ở `0x68448`,
    đặt `0x5e518 = 0x68448 / 0x64cd8`, với nhánh chặn chia 0/NaN.
11. Đọc giới hạn symbol `0x1f` và `0x20`, rồi ghi
    `0x649b0 = integer(0x1f) * 0x68448` và
    `0x653a8 = integer(0x20) * 0x68448`.
12. Chuẩn hóa tham số: nếu `0x5e4a0 <= 0` hoặc `0x5e4a8 <= 0`, đặt ô đó bằng
    `1.0` và giữ giá trị cũ trong biến tạm; nếu `0x5e4d0 < 0x5e4d8`, đặt
    `0x5e4d8 = 0x5e4d0 + 0x4cdb0`.
13. Khi `0x64cd8 != 0` (hoặc NaN), tính `dVar2 = 0x653a8 / 0x64cd8`; nâng
    `0x5e3e8` lên `(int)dVar2` nếu thấp hơn; nâng `0x5e4b0` lên `dVar2` và
    `0x649b0 / 0x64cd8` nếu các điều kiện hiện hữu cho phép.
14. Nếu `0x5e4f0 > 0`, nâng `0x5e4f8` theo cùng hai giới hạn. Tính
    `dVar2 = (0x649b0 + 0x649b0) / 0x64cd8`; mỗi ô `0x5e4a0`, `0x5e4a8`,
    `0x5e448` được thay bằng giá trị lớn hơn giữa nó và `dVar2`.
15. Ép `0x5e438` và `0x5e43c` tối thiểu bằng 1. Nếu `0x5e448 < 0x4cdb0`,
    đặt `0x5e448 = 0.1`.
16. Ghi `0x64ce0 = 0x5e470 * 0xe10`. Nếu `0x5e470 < 1`, thời điểm tạm là 0;
    nếu không, gọi `MT5_TimeCurrent` rồi cộng `0x64ce0`. Cuối cùng đặt
    `0x65390 = 0`; nếu byte `0x5e421` bằng 0 thì đặt `0x65390` bằng thời điểm
    vừa tính; sau đó trả về.

## Chưa chứng minh và không được tự đặt tên

- Chưa có bằng chứng đủ để ánh xạ các ô `0x5e1fc..0x5e398` sang tên input MQL5,
  đơn vị (điểm, giá, giây hay tiền) hoặc ý nghĩa chiến lược.
- Chưa chứng minh kiểu chính xác của các ô bị đọc gián tiếp, đặc biệt vùng chuỗi
  `0x5e488` và các byte xen kẽ; chỉ ghi kiểu theo phép dùng trong C.
- Chưa có phép chạy cặp EA gốc/dựng lại; bản này chỉ là đặc tả một khối từ bytes
  native và mã C. Không giao phần thiếu cho Claude và không gọi khối này là đã
  phục hồi chức năng.
- Các địa chỉ `OriginalB2` và codefile là hai bằng chứng khác nhau; không đồng
  nhất SHA codefile với SHA EX5 cài đặt vì metadata ghi rõ chúng khác tệp.
