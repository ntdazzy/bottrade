Đối chứng native phần scale và lot

Phạm vi: chỉ FUN_253f2627550, RVA 0x7550..0x83c4, fullbase 0x253f2620000.
SHA bytes đúng dải: dcd19e9d1581d0d4e68a1f8c1e293a83c1a4cb1f17de08a506e1e74f4d762141.

Địa chỉ tính lại:
- 0x253f2685834 - 0x253f2620000 = RVA 0x65834. README cũ ghi DAT_253f267e5834 là tên/địa chỉ sai; native dùng 0x253f2685834.
- 0x253f267e1a8 = RVA 0x5e1a8; 0x253f2686228 = RVA 0x66228.
- 0x253f2684cd8 = RVA 0x64cd8; 0x253f26849b0 = RVA 0x649b0; 0x253f26853a8 = RVA 0x653a8.

Kết quả native đã đối chứng:

1. Chọn scale
- RVA 0x7690: ucomisd reference,0 rồi jbe. Giá trị tham chiếu <= 0 hoặc unordered (NaN) vào nhánh MT5_iOpen.
- RVA 0x76c6: kết quả iOpen được ucomisd với 0; jne rồi jnp đi lỗi 0x430854000001f7 (đích RVA 0x83a3). Vì vậy 0 hữu hạn đi lỗi; khác 0 đi chia; NaN đi tiếp qua phép chia.
- RVA 0x76d6: candidate = giá symbol / reference.
- RVA 0x76ef: nếu byte RVA 0x5e1fd bằng 0 thì candidate = giá tham chiếu.
- RVA 0x770b..0x7723: scale = (candidate == 0 ? giá tham chiếu : candidate), rồi ghi vào full address 0x253f2686228 (RVA 0x66228).
- RVA 0x772e: nếu byte full address 0x253f2688788 (RVA 0x68788) khác 0 thì mới ghi giá tham chiếu / scale.

2. Điều chỉnh lot scale
- RVA 0x7826: giá SymbolInfoDouble thuộc tính 0x10 được ghi vào 0x65868 và 0x64cd8.
- RVA 0x7830: đọc SymbolInfoInteger thuộc tính 0x11. Nếu kết quả 3, đọc lại; nếu lần đọc lại là 5, hoặc lần đọc đầu là 5, RVA 0x7866..0x786f nhân lot_scale = scale * giá tại RVA 0x4cd98.
- RVA 0x7891..0x78a0: nếu đọc thuộc tính 0x11 bằng 1, chia lot_scale = scale / giá tại RVA 0x4cd98.
- Giá trị khác 3,5,1 giữ lot_scale bằng scale. Scale được ghi trước khi chỉnh lot_scale.

3. Chia 0 và NaN
- RVA 0x80d7: ucomisd lot_scale,0; jne; jnp lỗi. Lot_scale bằng 0 hữu hạn đi lỗi 0x430854000001f7 ở RVA 0x83a3. Khác 0 đi chia. NaN đi tiếp qua phép chia vì jnp không được lấy.
- RVA 0x80e3: dVar2 = giá giới hạn / lot_scale.
- RVA 0x8214..0x8222: twice = (giá giới hạn + giá giới hạn) / lot_scale.

4. Literal và điều kiện chính
- RVA 0x810d..0x8117: nâng ô số nguyên lên (int)dVar2 khi dVar2 lớn hơn.
- RVA 0x8137..0x8164: nâng lot giới hạn theo dVar2 và giới hạn dừng/lot_scale.
- RVA 0x817c..0x81b6: nếu cờ nguồn > 0, nâng ô phụ theo cùng hai giới hạn.
- RVA 0x8226..0x82da: twice được so lần lượt với ba ô; chỉ giá lớn hơn mới ghi.
- RVA 0x8249..0x82f7: hai ô số nguyên bị ép tối thiểu 1 bằng cmp và jg.
- RVA 0x8265..0x826f: literal 0x3fb999999999999a = 0.1 được ghi khi ô hiện tại không lớn hơn ngưỡng tại RVA 0x4cdb0.
- RVA 0x8288: literal 0xe10 = 3600 dùng đổi tham số thời gian sang giây.

Giới hạn: đối chứng này chỉ xác nhận hướng so sánh, literal, thứ tự ghi và điểm chia 0 của native. Chưa xác định tên input MQL5, đơn vị từng ô hoặc toàn bộ ý nghĩa chiến lược. Không suy nghĩa từ tên C và không coi toàn block đã chốt.
