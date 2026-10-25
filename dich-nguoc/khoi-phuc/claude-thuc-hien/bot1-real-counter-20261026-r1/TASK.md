Viết duy nhất Bot1ManagementRealCounter.mqh và SUMMARY.md trong thư mục đề xuất này. Chức năng: đếm số bước trước khi dời dừng lỗ thật. Codex đã chốt công thức/trình tự; chỉ viết mã theo mô tả này. Không đọc EX5/mã máy/phân tích hoặc tự tìm thuật toán. Chỉ đọc header Bot1 hiện hành để đúng kiểu/phong cách. Không sửa nguồn chính/Git/MT5, không chạy lệnh hoặc tạo tác tử. Opus5.5max,Ultracodeđược yêu cầu.

Headerguard và include Bot1ManagementPrelude.mqh. Hai hàmvoid Bot1AdvanceRealCounterBuyStop/SellStop cùng17tham số:
(const string &symbol,const uchar &enabled,const double &reference_setting,const int &minimum_steps,const double &step_distance,const double &unit,const double &copied_step,const double selected_anchor,const double &gap,const double &freeze,int &counter,Bot1ManagedPosition &position,MqlTick &tick,bool &changed,Bot1PendingRequestState &state,Bot1TradeSendOptions &options,const ulong ticket).
selected_anchor/ticket làgiátrịchụp; các&kháccóthểbịdịchvụgiảthayđổigiữacáclầnđọc. Giữdấustrict<,thứtựtoánhạngvàtrình tự đọc. DùngBot1RoundPrice/Bot1ModifyPosition; khôngNormalizeDouble/epsilon/kiểmgiátrịmới/luật dựphòng. KhôngPrint/GetLastError/resetlỗi/đóng/khốilượng/tickmới/TP/bảng/mode.

Đầu cảhai theođúngthứtự: if(changed)return; if(enabled!=1)return; counter=(int)((uint)counter+1),giữtràn32bit có dấu. Counterđãtăngphảigiữlạinếucác cổngsaukhôngqua. reference_setting==+0hoặc-0 bỏcổngneo; mọi giátrịkhác,kểcảNaN,phảiápdụngcổngneo, khônglọcNaN.

MUA:
1.quote=tick.bid,u=unit,product=step_distance*u. Nếu !(((product+position.sl)+gap)<quote),return. Nếu !(quote<position.tp-freeze),return. KhôngDIGITS/POINTtạicáccổngnày.
2.Nếu reference_setting!=0.0: offset=u*copied_step; nếu !(selected_anchor+offset<quote),return. u/quotelàbảnchụpbước1,khôngđọclạirefunit.
3.Nếu counter<minimum_steps,return, sosánhint32códấu.
4.Lấy digits1=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS); SAUđó đọcrefMỚI tínhcandidate=Bot1RoundPrice(step_distance*unit+position.sl,digits1). Nếu !(position.sl<candidate),return. Chưaghisl/chưaresetcounter.
5.counter=0 TRƯỚC DIGITS2; lấydigits2. GiátrịcounterbịdịchvụDIGITS2thayđổiphảigiữ, khôngresetlạisauđó.
6.new_sl=Bot1RoundPrice(position.sl+step_distance*unit,digits2),giữthứtựSL+productkhácbước4. Ghi position.sl=new_sl.
7.Gọi Bot1ModifyPosition(state,options,ticket,position.sl,position.tp),BỎQUAkếtquảboolkhôngbáolỗi. SAUlờigọisửa đặtchanged=true,dùsửathấtbại. Khôngthêmcổnggapnữasaughisl.

BÁN:
1.quote=tick.ask,u=unit,product=step_distance*u. Nếu !(quote<(position.sl-product)-gap),return. Nếu !((freeze+position.tp)<quote),return.
2.Nếu reference_setting!=0.0: offset=u*copied_step; nếu !(quote<selected_anchor-offset),return.
3.Nếu counter<minimum_steps,return.
4.Lấy DIGITS1; candidate=Bot1RoundPrice(position.sl-step_distance*unit,digits1),đọcrefMỚIsaudịchvụ. Nếu !(candidate<position.sl),return,chưaghisl/chưareset.
5.counter=0 trướcDIGITS2,rồilấydigits2.
6.new_sl=Bot1RoundPrice(position.sl-step_distance*unit,digits2),đọcrefMỚIlầnnữa;position.sl=new_sl.
7.GọiModifybỏquakếtquả,rồichanged=truegiốngMUA.

Mỗicổngdùngif(!(a<b))returnđểNaNkhôngđiqua, riêngreference_setting!=0.0phảigiữnghĩatrên. Khônghàmrỗng/TODO/tínhnăngkhác/khunghệthống. SUMMARYnóirõchưabiêndịch/chạy nếu chưa; Codexsẽkiểm/ghép/biêndịchvàđốichiếuđộclập.
