# Mức cao/thấp dùng dừng thật

Codex đọc trực tiếp management-20261025-r1/analysis.json đúng EX5 B3
ee063d3d87490afe24e2f4ce85f6b05659320e297b102efd70207f71ca2feb83,
base17156250000. Mua34ff2..35462; bán39404..397e9.
Đầu đoạn bắt buộc int6d5d4>0 và byteSP3f/SP37 khác0. Ý nghĩa nghiệp vụ
của byte này chưa chốt; giao diện giữ nguyên một byte từ bên gọi, không tự tạo.
H mua74110/H bán73df0 với index74934, countint6d3c0, U73dd8,
gap73ab0,freeze744a8,beforeOpenbit0 6d5c8,shiftbyte6d5dc.

- Mua: H1 chụp trước DIGITS1. Sau digits chụp x=gap+SL trước POINT1;
  gateRound(x+point,d1)<H1. SauPOINT đọc H2 mới, bid mới, count/U mới,
  cần H2<bid-double(count)*U. Nếu !(H2<open) và beforeOpenbit0 thì dừng.
  DIGITS2, sauAPI shift=(byte!=0?10:0); chụp
  v=(bid-shift*U)-gap trước POINT2; cần H2<Round(v-point,d2).
  SauPOINT đọcbid/freeze mới, cần bid<TP-freeze. DIGITS3 rồi
  SL=Round(H hiện thời,d3), gán trước SL<bid mới-gap mới.
- Bán: chụp H1 và x=SL-gap trước POINT1, cần H1<x-point.
  SauPOINT chụp U, H2 và ask2; cần double(count)*U+ask2<H2.
  Nếu !(open<H2) và beforeOpenbit0 thì dừng. Chụp shift byte,
  v=(ask2+U*shift)+gap trước POINT2; cần v+point<H2. Không có DIGITS
  ở hai cổng đầu. SauPOINT cần freeze+TP<ask mới. DIGITS1 rồi
  Round(H hiện thời,d1)<SL cũ. DIGITS2 rồi SL=Round(H hiện thời,d2),
  gán trước ask mới+gap mới<SL.
- Qua cổng cuối gọi Modify32a90 (3535c/396e6), đặt changed=true ngay
  sau lời gọi và trước nhánh xử lý trả về. Sửa false mới báo lỗi.
  Không đóng/khối lượng/Stamp/ghi bảng; mọi đường trướcModify giữ cờ cũ.
- Lỗi tại3536d/396f7. strings.json đọc prefix5d8a0 `error: '`,
  suffixraw5e20c `' when modifying stoploss`, hai hằng shift đều10.0.
  Hàm in khác prefix của nhóm TrailStop, không dùng sai helper đó.

Chưa biên dịch/chạy so phần mới; chưa biết đủ đầu vào từ vòng quản lý.
