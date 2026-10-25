# Điều chỉnh dừng thật sau kiểm trượt giá

Codex đọc trực tiếp quản lý B3 đúng base17156250000 và EX5
ee063d3d87490afe24e2f4ce85f6b05659320e297b102efd70207f71ca2feb83.
Mua34b22..34ff2, ra34fc6/34fda/34fad; bán39064..39404, ra393fa.
Đầu đoạn chỉ chạy khi int6d4e8==1 và bit0 byteSP5c/SP54==1,
và trail6d4f8>0. Không so toàn byte với1.
start6d4f0,limit6d500,U73dd8,gap73ab0,freeze744a8;
SLXMM8,TPXMM7,openXMM6,raw referenceXMM15,zeroXMM11.

- Mua chụp bid trước DIGITS1→POINT. GateRound(trail*U+(point+SL),d1)<bid.
  Chụp bid2 trước DIGITS2; Round(start*U+reference,d2)<bid2.
  Đọc bid mới: bid<TP-freeze. DIGITS3: SL<Round(limit*U+open,d3).
  DIGITS4: chụp bid3, SL=Round(bid3-trail*U,d4), gán ngay;
  yêu cầu SL<bid3-gap mới. Tới đây gọi Modify32a90.
- Bán chụp ask trước POINT; sau API chụp U một lần cho cả ba cổng
  không làm tròn: ask<(SL-point)-trail*U; ask mới<reference-start*U;
  freeze+TP<ask mới; open-U*limit<SL. Sau đó DIGITS1,
  Round(trail mới*U mới+ask mới,d1)<SL cũ. DIGITS2, chụp ask2,
  SL=Round(trail mới*U mới+ask2,d2), gán trước ask2+gap mới<SL.
- Mọi đường trước Modify giữ cờ cũ, kể cả SL đã đổi nhưng cổng cuối sai.
  Modify mua34ea7/bán392eb. True in chuỗi gốc active; false báo lỗi.
  Sau in/báo đặt cờtrue (SP48/SP68), không đóng/khối lượng/Stamp/ghi bảng.
  Buy lỗi34ebb; sell392ff, cùng prefix5df98, suffixraw5e15c.
- strings.json đọc trực tiếp ba vùng: lỗi
  `' when setting Slip TL.  Trying again!`, thành công mua
  `Slippage control active`, bán `Slippage controle active` (giữ lỗi chữ).

Đây là mô tả phân tích trước khi giao, chưa là kết quả chạy hoặc toàn EA.
