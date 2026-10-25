Viết duy nhất real_take_cases.py và SUMMARY.md trong thư mục này; không sửa tệp khác, không chạy lệnh/tác tử khác. Viết Python tạo dữ liệu cố định cho chương trình MQL5 tính dời chốt lời. Không tính kết quả mong đợi, không mô phỏng thuật toán. Codex sẽ chạy kiểm. Opus5.5 max, Ultracode được yêu cầu. Chỉ đọc TASK này và TASK của bot3-real-take-check-20261025-r1 kế bên để biết giao diện nhị phân; không đọc phân tích lịch sử.

Module xuất MAGIC=0x4d525033,CASE=struct.Struct('<8iqQIII23d'), INTS=[id,buy,scenario,modify_ok,error_code,digits0,digits1,digits2], DOUBLES=[sl,tp,open_price,volume,bid,ask,unit,distance,start,anchor,gap,freeze,point,minimum], cases()->list dict, encode(rows)->bytes. Các ca có deviation unsigned64,index,error_count,prior_changed uint32,volumes list9double,ticket signed64,group chuỗi; id liên tục từ0. Encode chính xác layout trong TASK Script, byteheader3int32.
Tạo tập ca hẹp có ý nghĩa cả buy0/1:
- bình thường: buy có SL90,TP130,open100,volume.1,bid105,ask106,unit1,distance2,start2,anchor115; sell SL110,TP70,open100,volume.1,bid95,ask96,unit1,distance2,start2,anchor85;gap.2,freeze2.5,point.01,minimum.01,volumes=.1+i*.01,digits3,scenario0,modify_ok1,index2,ticket7,deviation11,errorcode4756,error_count0,prior_changed0.
- Mỗi trường double lần lượt có -Inf,-1e19,-100.125,-0,+0,.01,100.125,1e19,+Inf,2quietNaN mang payload khác dấu. Chỉ1trường thay mỗi ca.
- prior_changed0/1,scenario0..8,modify_ok0/1; thêm minimum0 để Close có thể được gọi. Không tạo tích khổng lồ các trường.
- Cổng volume: minimum[-.01,-0,+0,.01,NaN],volume[-.1,-0,+0,.1,Inf,NaN], volumes tạiindex[.1,Inf,NaN]; vài tổ hợp có ý nghĩa, <=120ca mỗi phía. Không làm đè NaN bằng giá trị tính được.
- index0,8; mỗi index0..8 cóvolume1,Inf,NaN tronglầnriêng; mutation đổiindex nên để các9ô khác nhau.
- digits từnglần khác nhau gồm (-1,0,1),(0,1,2),(2,8,3),(11,10,9),(12,3,0),(intmin,intmax,-1); +.123456789 vàoTP.
- ticket[0,1,2^53+1,2^63-1,-2^63,-1],deviation[0,11,2^64-1],errorcount[0,2^32-1],errorcode[0,4001,4756,-1]; lấy từngnhómđộc lập hoặc tích hẹp.
- Các giá trị sátngưỡng bằng math.nextafter chứkhông tựtính expected: buy TP108.01±1ulp (cổng1ask106),anchor108±1ulp(cổng2ask106+start2),TP107.5±1ulp(freeze105+2.5),gap1±1ulp(cổngcuốiask106gap<newTP107); sell TP92.99±1ulp(cổng1bid95),anchor93±1ulp(cổng2bid95-start2),TP92.5±1ulp(freeze95-2.5),gap2±1ulp(cổngcuốinewTP93<95-gap).
- NaN2toán hạng cho(unit,distance),(start,anchor),(tp,point). Dùng quietNaN bits7ff8000000000123,fff8000000000456.
Không ghi expected, không gọi mã bot, không random; mỗi ca group mô tả. Tổng dưới1500. Không dùng chú giải dataclass/import package ngoài thư viện chuẩn.
