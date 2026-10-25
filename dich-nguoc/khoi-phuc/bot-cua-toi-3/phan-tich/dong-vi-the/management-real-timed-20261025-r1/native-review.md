# Dời dừng thật theo thời gian — phân tích trước khi giao viết

Codex đọc quy tắc và trực tiếp đọc instructions của management-20261025-r1.
Đúng EX5 ee063d3d87490afe24e2f4ce85f6b05659320e297b102efd70207f71ca2feb83,
base0x17156250000; hàm mua32f60/bán37590.
Chỉ đọc bản gốc, không sửa EX5/khóa hoặc MT5 chính.

## Ranh giới và ánh xạ

Mua33dfc..34138; nhánh không đạt34131 đặt cờ false. Bán3842c..38776,
không đạt38774. Không gồm gọi lấy mức ảo ngay trước hoặc nhánh khoảng giá sau.
XMM8 là SL cục bộ, XMM7 là TP, opened stack+60/+70. Quote=bid mua/ask bán.
activation6d5e8,delayint32 7449c,distance6d5f0,unit73dd8,gap73ab0,freeze744a8.

Mua: activation>0→TimeCurrent→now>=opened+signextend(delay), cộng cuộn64bit;
chụp bid33e4d→digits33e68→POINT33e83→offset=distance*unit;
gate=Round(offset+(point+SL),digits1), yêu cầu gate<quote đã chụp.
Sau POINT đọc bid/freeze mới, bid<TP-freeze. Hỏi digits2 tại33f64;
đọc bid/distance/unit mới; SL=Round(bid-distance*unit,digits2).
Giữ SL tính mới dù gate cuối SL<bid_captured-gap sai. Đạt gọi32a90,
cờ yêu cầu=true cả khi sửa trảfalse. Sửa thấtbại gọi báo lỗi.

Bán có thứ tự riêng: chụp ask38473→POINT3848e, không digits;
gate=(SL-point)-distance*unit, yêu cầu ask_captured<gate (KHÔNG Round).
Đọc ask/freeze mới, freeze+TP<ask. Hỏi digits1 tại384fc;
Round(distance*unit+ask,digits1)<SL. Hỏi digits2 tại385aa;
SL=Round(distance*unit+ask,digits2), nhân trước cộng ask theo thứ tự này.
Giữ SL dù gate cuối ask_captured+gap<SL sai. Đạt gọi32a90, cờ yêu cầu=true
cả khi false, báo lỗi chỉ khi false.

Các giá trị position là cục bộ, API không đổi open/TP/opened. Settings/tick
chung phải đọc lại tại đúng điểm. NaN làm cổng dương sai. Không có Stamp,
đóng vị thế hoặc ghi bảng trong hai đoạn này.

## Báo lỗi

Native đọc int32 lỗi hiện tại từ engine+1d6e10 rồi gọi3ee80 đã có nguồn
Bot3TradeErrorText (tự tăng bộ đếm). Ghép trái→phải và Print đúng một lần:
`TrailStop error: '` + error_text +
`' when setting trailing Exit_TrailSL_after_X_Minutes_size_ loss.  Trying again!`.
Prefix đọc trực tiếp từ descriptor5df98 (raw5df6c); suffix rawUTF165dfbc.
Không tự sửa câu lạ hoặc hai khoảng trắng sau dấu chấm.
Cấp phát chuỗi thất bại đi nhánh lỗi ngôn ngữ; chưa có phép so lỗi hết RAM.

## Phân công

Ba đặc tả viết mã độc lập gửi Claude: mua, bán, báo lỗi. TASK chỉ chứa
giao diện, kiểu số, công thức, thứ tự/tác dụng phụ và đầu ra; không yêu cầu
Claude đọc EX5/mã máy hay tự tìm thuật toán. Chứng cứ gốc được giữ ở đây,
Codex chịu trách nhiệm so mã và kiểm chạy. Đề xuất chưa phải kết quả đạt.
Một việc độc lập nữa là ghép các hàm cuối nhánh ảo đã có; công thức đã
chốt trong management-virtual-finish-20261025-r1/contract.md.
