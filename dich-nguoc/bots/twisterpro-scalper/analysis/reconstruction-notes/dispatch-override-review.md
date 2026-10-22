# Kiểm tra bảng override lời gọi MT5 của TwisterPro

## Kết luận

Con số `MQL_DISPATCH_CALL_OVERRIDES 79` chỉ là số dòng trong `twister-symbols-v3/dispatch-calls.tsv`. `OverrideMqlDispatchCalls.java` không tự tìm lời gọi còn thiếu và cũng không kiểm tra rằng mọi lời gọi tới bộ xử lý chung đã có một dòng. Vì vậy số 79 không chứng minh đã phục hồi đủ lời gọi.

Khi một callsite không có dòng override, Ghidra dùng chữ ký bốn tham số đã gán cho `MT5_Dispatch` (`context, operation, argument_count, type_0`). Các thẻ kiểu và giá trị biến nằm ở thanh ghi/ngăn xếp phía sau không được đưa vào dạng C. Đây là nguyên nhân các dòng trong `FUN_...18c0` hiện thành:

```c
MT5_Dispatch(context, 0xd, 5, 0x590008);
MT5_Dispatch(context, 0xd, 9, 0x590008);
```

Trong khi các lời gọi iMA hiện đủ tham số vì callsite của chúng có trong bảng.

## Bằng chứng trong hàm khởi tạo

Địa chỉ nền mã là `0x25a0b0c0000`. Đọc mã máy `captures/twisterdata1_09/0000025a0b0c0000.bin` cho thấy ba callsite bị thiếu trong `FUN_...18c0`:

- `RVA 0x2cc3`: `edx=0xd`, `r8d=5`, năm thẻ đều được ghi là `0x590008` ở các ô ngăn xếp; đây là lời gọi 5 tham số chuỗi.
- `RVA 0x2de3`: `edx=0xd`, `r8d=9`; các thẻ theo thứ tự là `0x590008, 0x520004, 0x590008, 0x520004, 0x590008, 0x520004, 0x520004, 0x520004, 0x590008`.
- `RVA 0x2ed8`: `edx=0xd`, `r8d=6`; các thẻ theo thứ tự là `0x590008, 0x590008, 0x520004, 0x520004, 0x590008, 0x520004`.

Ba địa chỉ trên không xuất hiện trong `twister-symbols-v3/dispatch-calls.tsv` và cũng không xuất hiện trong `twister-dispatch-callsite-types.json`. Ngược lại, `RVA 0x2b8e` (PrintFormat 4 tham số) và `RVA 0x2bf8` (StringFormat 2 tham số) có dòng bảng nên C hiển thị đầy đủ.

## Bằng chứng trong hàm định dạng lệnh

`FUN_...d37f0` (RVA `0x137f0`) có 25 câu lệnh `MT5_Dispatch` trong C xuất. Bảng chỉ có 23 dòng, đều là operation `0xd8`. Mã máy có thêm callsite `RVA 0x13f84`: trước lệnh gọi, `edx=0xd8`, `r8d=2`, thẻ `0x590008`, giá trị chuỗi ở `[rsp+0x20]`; địa chỉ này không có trong bảng.

Hai câu lệnh C operation `0xd8` cùng dạng có thể được trình biên dịch gộp vào một callsite chung, nên chênh lệch số dòng C không tự nó chứng minh có hai callsite máy khác nhau. Callsite `0x13f84` thì có mã máy riêng và chắc chắn bị thiếu override.

## Sửa tối thiểu đề xuất

Không sửa chữ ký chung để thêm tham số cố định. Chỉ bổ sung các dòng đã đo từ mã máy vào bảng nguồn tạo override:

```text
25a0b0c2cc3	5	0x590008,0x590008,0x590008,0x590008,0x590008
25a0b0c2de3	9	0x590008,0x520004,0x590008,0x520004,0x590008,0x520004,0x520004,0x520004,0x590008
25a0b0c2ed8	6	0x590008,0x590008,0x520004,0x520004,0x590008,0x520004
25a0b0d3f84	2	0x590008,0x590008
```

Bốn dòng trên là đề xuất kiểm thử bảng, chưa được chèn vào bảng hiện tại theo yêu cầu chỉ phân tích. Sau khi thêm, cần xuất lại C và kiểm tra chính bốn callsite; chỉ khi tham số phía sau xuất hiện đúng mới coi override đã có tác dụng.

## Giới hạn

- Các thẻ trên được đọc từ mã máy đã chụp; chúng xác định kiểu giá trị, chưa khôi phục tên biến hay chuỗi gốc.
- Không được dùng số 79 để kết luận mọi lời gọi đã phục hồi. Ít nhất bốn callsite máy cần bổ sung/đối chiếu như trên.

## Bổ sung đã kiểm lại ngày 21/10/2026

Hai danh sách thẻ ban đầu tại 0x2de3 và 0x2ed8 đã được sửa theo từng lệnh ghi thật; xem dispatch-additional-four.json. Bốn lời gọi đã thêm vào twister-symbols-v4/dispatch-calls.tsv, tổng 83. Không coi 83 là mọi lời gọi của bot.
