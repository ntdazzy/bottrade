# Dời mức ảo theo kiểm trượt giá

Mô tả trước nguồn. Mua `0x29c64..0x29de9`, các cạnh bỏ qua tại
`0x29eb8/0x29eae/0x2a3b4`. Bán `0x2d3d1..0x2d55a`, các cạnh bỏ
qua tại `0x2d629/0x2d61f/0x2db33`. Đo đến trước nhánh mức cao/thấp.

- Int `0x623f0` phải đúng 1; cờ khoảng cách lấy từ đoạn bảng giá mở
  phải đúng. Double khoảng `0x62400` phải >0; NaN không thỏa.
- Chụp mức và giá hiện tại, hỏi điểm giá rồi mới đọc tham số phía sau.
- Mua cần: mức đã chụp + điểm + khoảng×đơn vị < giá đã chụp;
  mức tham chiếu bảng + `0x623f8`×đơn vị < giá bán hiện tại;
  giá bán hiện tại < chốt − `0x67468`;
  mức hiện tại < đơn vị×`0x62408` + giá mở.
- Bán cần: giá đã chụp < (mức đã chụp − điểm) − khoảng×đơn vị;
  giá mua hiện tại < mức tham chiếu bảng − `0x623f8`×đơn vị;
  `0x67468` + chốt < giá mua hiện tại;
  giá mở − đơn vị×`0x62408` < mức hiện tại.
- Sau các điều kiện: in trước khi tính mức mới. Chuỗi mua ở `0x55b60`
  đúng `Slippage control active`; chuỗi bán ở `0x55d30` đúng
  `Slippage controle active` (giữ nguyên lỗi chính tả của bản gốc).
- Sau lời gọi in, đọc lại giá, khoảng, đơn vị; bật cờ và ghi mức mới:
  mua giá bán − khoảng×đơn vị; bán khoảng×đơn vị + giá mua.
- Không sửa/đóng, hỏi số chữ số hoặc ghi giờ ở chính đoạn này.

Đây là một đoạn trong nhánh ảo; không phải hàm quản lý đầy đủ.
