Viết Bot1ManagementRealLock.mqh và SUMMARY.md duy nhất trong thư mục đề xuất này. Chức năng MQL5: đặt dừng lỗ để khóa lời sau khi giá đã vượt một khoảng. Codex đã chốt trình tự/công thức dưới đây; chỉ viết theo mô tả. Không đọc EX5/mã máy/thư mục phân tích hoặc tự tìm thuật toán. Chỉ đọc header Bot1 để đúng kiểu/phong cách. Không sửa nguồn chính/Git/MT5, không chạy lệnh hoặc tạo tác tử. Opus5.5max, Ultracode được yêu cầu.

Headerguard/include Bot1ManagementPrelude.mqh và Bot1ManagementMessages.mqh. Hai hàmvoid Bot1AdvanceRealLockBuyStop/SellStop cùng13tham số:
(const string &symbol,const double &start,const double &extra,const double &unit,const double &gap,const double &freeze,Bot1ManagedPosition &position,MqlTick &tick,bool &changed,Bot1PendingRequestState &state,Bot1TradeSendOptions &options,uint &error_count,const ulong ticket).
ticket làgiátrịchụp; các& cóthểbịdịchvụgiảthayđổigiữacáclầnđọc. Giữmọithứtựtoánhạng, cổngstrict<; mỗiif(!(a<b))return đểNaNkhôngđiqua. Dùng Bot1RoundPrice, Bot1ModifyPosition, Bot1TradeErrorText sẵn có; khôngviếtlạithuậttoánhelper, khôngNormalizeDouble/epsilon/lọcgiátrị/thêm luật. Khôngkiểmmode, khôngđổiTP, đóng,khốilượng,tickmới,bảnghoặcthôngbáothànhcông.

Helpervoid Bot1PrintRealLockError(uint &counter): code=(int)GetLastError1lần; stringmsg=Bot1TradeErrorText(code,counter); Print("error when setting breakeven: '"+msg+"' ..'Exit_BE_start_' to close to 'Exit_BE_extra_pips_' ..trying again!"). Giữnguyênchữto close/khoảngtrắng/dấuchấm, khôngResetLastError, khôngtựtăngcountervìhelperđãtăng.

MUA:
1.Nếu !(0.0<start),return, giữsl/changed.
2.quote1=tick.bid TRƯỚC DIGITS1; uintdigits1=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS). Sau đó đọcstart/unit/open đểgate1=Bot1RoundPrice(start*unit+position.open_price,digits1). Nếu !(gate1<quote1),return.
3.Gọi DIGITS2; candidate=Bot1RoundPrice(extra*unit+position.open_price,digits2) đọcextra/unitMỚIsaudịchvụ. SAU khi làmtròn gọi POINT1=SymbolInfoDouble(symbol,SYMBOL_POINT). Nếu !((point+position.sl)<candidate),return; khôngtínhlạicandidate/extra/unit sauPOINT1.
4.quote2=tick.bid MỚI TRƯỚC DIGITS3; gọidigits3. SAUđó gate2=Bot1RoundPrice((extra*unit+position.open_price)+gap,digits3). Nếu !(gate2<quote2),return.
5.Nếu !(tick.bid<position.tp-freeze),return, khôngthêmDIGITSởđây.
6.Gọi DIGITS4; new_sl=Bot1RoundPrice(extra*unit+position.open_price,digits4), dùngcácrefMỚI. Ghi position.sl=new_sl TRƯỚC cổnggap. Nếu !(new_sl<tick.bid-gap),returnvàGIỮslmới/changedcũ.
7.boolok=Bot1ModifyPosition(state,options,ticket,position.sl,position.tp); ngaySAUlờigọiđặtchanged=trueTRƯỚCkiểmok. Nếu!okBot1PrintRealLockError(error_count).

BÁN:
1.Nếu !(0.0<start),return. captured_unit=unit; trigger=position.open_price-start*captured_unit. Nếu !(tick.ask<trigger),return. KhôngDIGITS/làmtrònởđây.
2.candidate=position.open_price-captured_unit*extra TRƯỚC POINT1; gọipoint. Nếu !(candidate<position.sl-point),return. Khôngđọclạicaptured_unit/extrađểtínhlạicandidate.
3.SAU POINT1 đọcMỚI offset=extra*unit; quote=tick.ask. Nếu !(quote<(position.open_price-offset)-gap),return.
4.Nếu !((freeze+position.tp)<quote),return, dùngcùngquoteđãchụpbước3.
5.Gọi DIGITS1; gate=Bot1RoundPrice(position.open_price-extra*unit,digits1). Nếu !(gate<position.sl),return, CHƯAghisl.
6.Gọi DIGITS2; new_sl=Bot1RoundPrice(position.open_price-extra*unit,digits2),đọcrefMỚIlầnnữa. Ghi position.sl=new_sl TRƯỚC cổnggap. Nếu !((tick.ask+gap)<new_sl),returnvàGIỮslmới/changedcũ.
7.Sửa,changedtrue trướckiểmok,báolỗi khi!ok giốngMUA.

Mọiđườngravớigatesai trướcModify giữchangedcũ (kểcảslmớiđãghi). Khôngthêm tínhnăng/hàmrỗng/TODO/khunghệthống. SUMMARYnóiđúngchưabiêndịch/chạy nếu chưa; Codexkiểm/ghép/biêndịchvàsođộclập.
