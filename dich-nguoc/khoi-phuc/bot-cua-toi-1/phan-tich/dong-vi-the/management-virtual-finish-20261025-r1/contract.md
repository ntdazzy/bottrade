# Kết thúc nhánh ảo bot 1 — mô tả trước khi viết

EX5 SHA-256 a3b0de423a06e10ebedc279307b93d7cb9188ba2bb5de77131a913c865b0e922.
Đầu mã 0x23e5aa10000. Nguồn: management-20261025-r1/analysis.json,
functions.c và native-guards.txt, đã đọc lại các lệnh dưới đây.
Đây chưa phải toàn hai hàm quản lý hoặc EA.

P=double62580, U=double66d98, gap=double66a70, freeze=double67468.
Tick bid/ask=67758/67760; open=xmm6, tp=xmm7 trước khối khóa lời.
Ticket so bảng=xmm11; initial_virtual_stop=xmm9 (từ helper3d200).
Bảng500x3 tại62590, guardbyte66410. Dữ liệu mốc: selected_anchor stack+88,
cached_reference xmm15; hai giá trị này không được mặc định là bằng nhau.
Bộ đếm signedint32 tại673f0, copied_step double673e8.

## Mức cao/thấp

Mua bắt đầu29ecb, bán2d63c. Chỉ gọi khi int624e4>0.
Bảng mua670d0/bán66db0; uint index678f4.
1. Chụp P và levels[index] trước POINT. Limit=P+gap mua/P-gap bán,
   gap đọc trước POINT. Sau POINT so limit+point<level mua,
   level<limit-point bán. NaN làm phép so dương sai.
2. Đọc lại index và level sau POINT. Yêu cầu level<open mua/open<level bán,
   hoặc bit thấp byte624d8==0.
3. K=byte624ec!=0 ? double50248(mua)/50270(bán) : +0.0.
   Hai ô đó là10.0 tại bản chụp; trường nội bộ giữ đúng giá trị này.
   Vẫn thực hiện K*U khi K==0.
4. Trước POINT thứ hai chụp: mua limit=(bid-K*U)-gap;
   bán limit=(K*U+ask)+gap. Sau POINT so level<limit-point mua,
   limit+point<level bán. level là lần đọc thứ hai đã giữ qua API.
5. Kiểm LẠI tick sau API: bid<tp-freeze mua, freeze+tp<ask bán.
   Đặt changed=true; P=levels[index] đọc lại index/bảng tại thời điểm ghi.

## Khóa lời và bộ đếm

Mua29f59..2a157, bán2d6d5..2d8d9; có các thân ngoài dòng tại2a4d6/2dc53.
- lock_start double624c8>0 và mode int6241c==2 mới xét khóa.
- Chụp U trước POINT. Mua activation*U+open<bid;
  bán ask<open-activation*U.
- Candidate trước POINT: U*lock_extra+open mua/open-U*lock_extra bán.
  Chụp P trước POINT. Sau POINT yêu cầu P+point<candidate mua,
  candidate<P-point bán.
- Đọc lại lock_extra, U, tick sau POINT. Candidate mới=open+extra*U mua,
  open-extra*U bán. Yêu cầu gap+candidate<bid mua, ask<candidate-gap bán;
  rồi bid<tp-freeze mua, freeze+tp<ask bán.
  Khi đủ ghi P=candidate và changed=true.
- Nếu changed đã true (từ trước hoặc khóa) thì bỏ bộ đếm.
- Khi changed false, chỉ tăng counter khi byte62508==1. Đọc quote/P trước
  cờ; U/step_distance62520 sau cờ. counter++ giữ tràn int32 như gốc.
  next=step_distance*U+P mua, P-step_distance*U bán.
- Yêu cầu gap+next<quote mua/quote<next-gap bán;
  quote<tp-freeze mua/tp+freeze<quote bán.
- Nếu step_reference double62510==0 (cả+0 và-0), bỏ kiểm mốc.
  NaN không là zero. Khác zero: selected_anchor+U*copied_step<quote mua;
  quote<cached_reference-U*copied_step bán.
- counter>=min_steps int62518 thì counter=0,P=next,changed=true.
  Nếu không đạt giữ counter đã tăng và changed=false.

## Lưu mức ảo

Mua2a157..2a389; bán2d8d9..2db08.
Hỏi digits lần1 rồi Round(initial_virtual_stop);
hỏi digits lần2 rồi đọc P và Round(P).
Bằng có thứ tự thì không ghi. NaN coi là khác.
Khác: hỏi digits lần3, đọc lại P rồi Round(P); sau đó guard==1 mới quét
500hàng. Gặp ticket double bằng có thứ tự đầu tiên thì chỉ ghi row+8.
Không tạo ô, không sửa timestamp, không gán giá đã làm tròn lại vào P.

## Điểm nối đã sửa

Sau khối khóa/bộ đếm, bên gọi kiểm P>=bid mua/ask>=P bán có thứ tự.
Nếu chạm: refresh tick rồi helper3d010; bỏ qua lưu.
Khi lưu nhánh ảo xong, mua2a389 JMP2a3f8, bán2db08 JMP2db77.
Các cạnh này BỎ QUA cmp mode. Cạnh real khác mới qua2a3e5/2db64 rồi
mode==2 mới đi StartVirtual. Không tạo vòng lặp mode2->Start sau lưu ảo.
Cờ tổng chỉ nâng1 khi changed!=0 rồi về vòng vị thế27333/2ad03.

Chưa ghép real/virtual, hàm con thật, vòng ngoài, lỗi bộ nhớ, bảng/UI
và EA. Cần bộ so native và MQL5 cho các hàm mới trước khi gọi đạt.
