Viết duy nhất Bot3ManagementRealSlippage.mqh và SUMMARY.md trong thư mục này. Chỉ viết theo mô tả chức năng đủ dưới đây, không tự tìm thuật toán/đọc phân tích lịch sử. Không sửa nguồn chính/Git, không chạy lệnh/tác tử khác. Codex kiểm/ghép. Opus5.5 max, Ultracode được yêu cầu; không khẳng định đã chạy.
Include Bot3ManagementPrelude.mqh và Bot3ManagementMessages.mqh. Dùng Bot3RoundPrice (uint digits), không NormalizeDouble. Các tham chiếu cài đặt/tick có thể được API đổi; position.sl được hàm cập nhật, tp/open_price cục bộ không bị API đổi, reference giá trị cố định. Không trùng vùng nhớ.
Hai hàm void Bot3AdvanceSlippageRealBuyStop/SellStop, cùng giao diện:
(const string &symbol,const double &unit,const int &enabled,const uchar passed_flag,const double reference,const double &trail,const double &start,const double &limit,const double &gap,const double &freeze,Bot3ManagedPosition &position,MqlTick &tick,bool &changed,Bot3PendingRequestState &state,Bot3TradeSendOptions &options,uint &error_count,const ulong ticket).
Chung: thoát nếu enabled!=1 hoặc (passed_flag&1)!=1 hoặc !(0.0<trail). NaN làm mọi cổng dương sai; dùng if(!(a<b))return. Mọi đường trướcModify giữchangedcũ; vẫn giữ SL mới nếu đã gán mà cổng cuối sai.
BUY:
1 quote=tick.bid TRƯỚC DIGITS1; digits1=SymbolInfoInteger(symbol,SYMBOL_DIGITS) rồi point=SymbolInfoDouble(symbol,SYMBOL_POINT).
2 sauPOINT đọc trail/unitmới: gate=Bot3RoundPrice(trail*unit+(point+position.sl),digits1); yêu cầu gate<quote. Giữ đúng ngoặc point+SL.
3 quote2=tick.bid TRƯỚCDIGITS2; sauAPI boundary=Bot3RoundPrice(start*unit+reference,digits2); yêu cầu boundary<quote2.
4 đọc mới: tick.bid<position.tp-freeze.
5 DIGITS3, sauAPI limitprice=Bot3RoundPrice(limit*unit+position.open_price,digits3); yêu cầu position.sl<limitprice.
6 DIGITS4, sauAPI quote3=tick.bid; new_sl=Bot3RoundPrice(quote3-trail*unit,digits4); gánposition.sl=new_sl ngay. Sau đó đọcgapmới; yêu cầu new_sl<quote3-gap. Sai vẫn giữnewSL.
7 gọiModify(state,options,ticket,position.sl,position.tp). True: Print("Slippage control active"); false: Bot3PrintManagementError("' when setting Slip TL.  Trying again!",error_count). SauPrint/Report mớichanged=true. Không đóng hoặc tínhvolume.
SELL:
1 quote=tick.ask TRƯỚC POINT; point=SymbolInfoDouble(symbol,SYMBOL_POINT), KHÔNGDIGITS trướcPOINT,KHÔNGlàm tròn cổngđầu.
2 sauPOINT chụp u=unit. gate=(position.sl-point)-trail*u; yêu cầu quote<gate.
3 đọcask2 mới, yêu cầu ask2<reference-start*u. Tiếp freeze+position.tp<ask2 (dùng cùngask2). Tiếp position.open_price-u*limit<position.sl. Cảba cổng dùnguđãchụp, thứtựnhâncuối u*limit.
4 DIGITS1; sauAPI gate2=Bot3RoundPrice(trail*unit+tick.ask,digits1); yêu cầu gate2<position.sl cũ. Dùng trail/unitmới.
5 DIGITS2; sauAPI quote3=tick.ask; new_sl=Bot3RoundPrice(trail*unit+quote3,digits2); gánposition.sl ngay. Sauđóđọcgapmới; yêu cầu quote3+gap<new_sl; sai giữSLmới.
6 Modify nhưbuy; True: Print("Slippage controle active") (giữchữcontrole); falsebáocùngsuffixnhưbuy. Sauin/báolỗichanged=true.
KhôngSymbolInfoTick,khôngđổiTP,khôngghi bảng/Stamp,khôngthêmcổngvolume hoặcđiều kiệnkhác. Mãrõràngtối giản,đúngthứtựđọcghi,giữphépnhâncộngđãmô tả. SUMMARY ghiAPI/thứtự/đầu ra vàchưađượcbiêndịch/chạy.
