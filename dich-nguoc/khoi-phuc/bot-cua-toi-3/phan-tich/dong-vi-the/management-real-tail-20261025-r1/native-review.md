# Cuối nhánh quản lý mức dừng thật — bot3

Codex đọc management-20261025-r1/analysis.json, đúng EX5 SHA
ee063d3d87490afe24e2f4ce85f6b05659320e297b102efd70207f71ca2feb83,
base17156250000. Không lấy tên biến trong C làm bằng chứng công thức.

## Khóa lời

Mua35462..358b1, bán397e9..39b32; lock_start6d5b8,extra6d5c0,
unit73dd8,gap73ab0,freeze744a8,SLXMM8,TPXMM7,openXMM6,zeroXMM11.
Nhánh thật không kiểm mode2 ở cổng khóa (khác nhánh ảo).

- Mua: start>0; bid chụp trướcDIGITS1 rồi Round(start*U+open)<bid.
  DIGITS2: chụp Round(extra*U+open) trướcPOINT, cần point+SL<candidate.
  Bid chụp trướcDIGITS3, cần Round((extra*U+open)+gap)<bid; bid mới<TP-freeze.
  DIGITS4: SL=Round(extra*U+open), gán trướcSL<bid mới-gap mới.
- Bán: start>0; chụpU, cần ask<open-start*U. Candidate=open-U*extra
  chụp trướcPOINT; cần candidate<SL-point. SauPOINT đọcextra/U/ask mới,
  cần ask<(open-extra*U)-gap vàfreeze+TP<ask (cùngask). DIGITS1:
  Round(open-extra*U)<SL cũ; DIGITS2:gánSL=Round(open-extra*U), rồiask+gap<SL.
- Qua cổng cuối gọiModify32a90 (357c0/39a44), đặt cờtrue ngay sau lời gọi,
  false mới báo lỗi. Tới đây bỏ quaCounter, điStore. Sửa false vẫn bỏCounter.
  Mọi đường trướcModify giữ cờ cũ, kể cả SL đã đổi mà cổngcuối sai.
- strings.json: prefix5e290 `error when setting breakeven: '`, suffix5e2ac
  `' ..'Exit_BE_start_' to close to 'Exit_BE_extra_pips_' ..trying again!`.

## Bộ đếm

Mua358b1..35b30, bán39b32..39dc0. Nếu cờ SP48/SP68 đãtrue thìbỏCounter;
ngược lại cần byte6d5f8==1, counterint3274430++, giữtràn32bit.
step_distance6d610,ref6d600,minint326d608,copiedStep74428,
selectedAnchorSP78/SP88 (hai phía đều dùng mốc được chọn).

- Chụpquote vàU trướcAPI. Mua: step*U+SL+gap<bid<TP-freeze.
  Bán:freeze+TP<ask<(SL-step*U)-gap.
- Ref bằng+0/-0 bỏ cổngmốc; khác0 hoặcNaN cần mua anchor+U*copiedStep<bid,
  bánask<anchor-U*copiedStep. Cầncounter>=min so códấu.
- DIGITS1: muaRound(step mới*U mới+SL)>SL, bánRound(SL-step mới*U mới)<SL.
  Đạt mới counter=0 trướcDIGITS2. DIGITS2:gán muaSL=Round(SL+step mới*U mới),
  bánSL=Round(SL-step mới*U mới). Giữkhác thứtự cộngởmua giữa hai lượt.
- GọiModify32a90 (35b29/39db9), cờtrue dùModifyfalse; KHÔNG báo lỗi,
  KHÔNG cổnggap/freeze sau làmtròn. KhôngStamp/khối lượng/đóng.

## Ghi mức dừng thật vào bảng

Storemua35b30..35d52 (+36835 ghiô), bán39dc0..39fe2 (+3aa2e).
ĐầuStoreghiGlobalP6d670=SL. NếuSL>bid (mua),ask>SL(bán), điđườngđóng:
dấu nghiêmngặt>, khácđườngảo>=. In cảnhbáo vàhai dòng mức/giá,
làm mớiTick, TryClose47d20, trảtrue khỏitoànmanager.
Phần tạo chuỗi số cầnchốt riêngtrước ghép đườngđóng, chưa thaybằngchuỗiđoán.

Khônghit: DIGITS1 Round(initialRealStopXMM9), DIGITS2 Round(P hiệnthời).
Khácnhau/NaN thìDIGITS3 Round(P mới), guard73450==1 thìtìm500 hàng đầu
của6d680 với vé XMM12 đãchụp dạngdouble; ghiô[1] của hàngkhớpđầutiên.
Không tạo hàng, không ghiô giờ hoặc bảngTake. SauStoređọc mode6d514 mới:
==2 sangvirtual35d65/39ff5, khác2 sangjoin36f5f/3b14f.
