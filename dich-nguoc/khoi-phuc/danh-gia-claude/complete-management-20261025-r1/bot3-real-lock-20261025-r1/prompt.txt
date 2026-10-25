Viết duy nhất Bot3ManagementRealLock.mqh và SUMMARY.md trong thư mục này. Chỉ viết theo mô tả chức năng dưới đây; không đọc phân tích lịch sử/tự tìm thuật toán. Không sửa nguồn chính/Git, không lệnh/tác tử khác. Codex kiểm/ghép/chạy. Opus5.5 max, Ultracode yêu cầu. Không claimđãbiêndịch/chạy.
Include Bot3ManagementPrelude.mqh và Bot3ManagementMessages.mqh. Dùng Bot3RoundPrice (uintdigits), khôngNormalizeDouble. Tấtcả thamchiếu càiđặt/tick cóthểđổi sauAPI; position.sl đượchàmghi, tp/open_price cục bộ khôngbịAPIđổi, khôngtrùngvùngnhớ.
Hai hàm void Bot3AdvanceRealLockBuyStop/SellStop, cùnggiao diện:
(const string &symbol,const double &start,const double &extra,const double &unit,const double &gap,const double &freeze,Bot3ManagedPosition &position,MqlTick &tick,bool &changed,Bot3PendingRequestState &state,Bot3TradeSendOptions &options,uint &error_count,const ulong ticket).
Chung: nếu !(0.0<start) thoát. KHÔNG kiểm chếđộ. Mọi cổngdươnglàcóthứtự, NaNlàmfalse. Mọi lốitrướcModifygiữchangedcũ; SLmớigiữkhiđãgánmàcổngcuối sai.
BUY:
1 quote=tick.bid TRƯỚC DIGITS1; hỏiDIGITS1 rồi gate=Round(start*unit+position.open_price,d1) đọcstart/unitmới; cần gate<quote.
2 DIGITS2; sauAPI candidate=Round(extra*unit+open_price,d2) đọcextra/unitmới; rồi POINT. Cần point+position.sl<candidate. CandidateđãchụptrướcPOINT,khôngđọcextra/unitlạichocổngnày.
3 quote2=tick.bid TRƯỚCDIGITS3; hỏiDIGITS3 rồi gate2=Round((extra*unit+open_price)+gap,d3); cần gate2<quote2.
4 đọc mới tick.bid<position.tp-freeze.
5 DIGITS4; sauAPI new_sl=Round(extra*unit+open_price,d4);gánSLngay. Sauđóđọc bid/gapmới, cầnnew_sl<tick.bid-gap; saisẽgiữSLmới.
6 ok=Bot3ModifyPosition(state,options,ticket,position.sl,position.tp); changed=true NGAYsauModify,trướcif(!ok); falsemớiBot3PrintRealLockError(error_count). Khôngvolume/đóng/Stamp.
SELL:
1 chụpu=unit; trigger=position.open_price-start*u, cần tick.ask<trigger. KHÔNGDIGITSởcổngnày.
2 candidate=position.open_price-u*extra (giữu*extra) TRƯỚCPOINT. POINT; cần candidate<position.sl-point.
3 sauPOINTđọc extra/unitmới,quote=tick.ask mới; offset=extra*unit; cầnquote<(open_price-offset)-gap; tiếpcầnfreeze+position.tp<quote(dùngcùngquote).
4 DIGITS1; sauAPI gate=Round(open_price-extra*unit,d1); cầngate<SLcũ.
5 DIGITS2; sauAPI new_sl=Round(open_price-extra*unit,d2);gánSLngay. Sauđóđọctick.ask/gapmới;cần tick.ask+gap<new_sl;sai giữSLmới.
6 Modify→changed=true→falsemớibáolỗinhưbuy.
Định nghĩa helpervoid Bot3PrintRealLockError(uint &counter): đọcintcode=(int)GetLastError() đúng1lần; stringmsg=Bot3TradeErrorText(code,counter) đãtăngđếmbêntrong; Print("error when setting breakeven: '"+msg+"' ..'Exit_BE_start_' to close to 'Exit_BE_extra_pips_' ..trying again!") đúng1lần. Không dùngPrintManagementError(vìprefixkhác),khôngresetlỗi,tăngđếmthêm.
KhôngSymbolInfoTick/đổiTP/mảng/bảng/đóng/khốilượng. Khôngtựthêmcổng,giữthứtựnhâncộng/đọcghi. SUMMARY nóiAPI/flag/chưachạy.
