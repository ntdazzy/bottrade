Viết duy nhất Bot1ManagementRealStart.mqh và SUMMARY.md trong CHÍNH thư mục đề xuất này. Chức năng MQL5: đọc mức dừng từ bảng, ghi mức dùng chung và kiểm đóng khi giá chạm. Codex đã chốt logic sau; chỉ viết theo mô tả. Không đọc EX5/mã máy/phân tích hoặc tự tìm thuật toán. Chỉ đọc headerBot1 hiện hành để đúngkiểu/giaodiện. Không sửa nguồn chính/Git/MT5, không chạy lệnh/tạo tác tử. Opus5.5max; Ultracodeđược yêu cầu. Nếughi bịtừchối,trảđầymãtrongcâutrảlờiđểCodexlưu; khôngđổi nơi ghi.

Headerguard/include Bot1ManagementPrelude.mqh,Bot1VirtualStops.mqh.

Hàm1 boolBot1CloseRealStopHit(const bool buy,const string &symbol,const double &current_stop,MqlTick &tick,Bot1PendingRequestState &state,Bot1TradeSendOptions &options,const ulong &deviation,const double &gap,const double &freeze,const long ticket).
Luôn theođúngthứtự:
Print("Closing with virtual SL");
Print("Virtual_SL: "+(string)current_stop);
Print((buy ? "Last Bid: " : "Last Ask: ")+(string)(buy ? tick.bid : tick.ask));
SymbolInfoTick(symbol,tick),bỏquakếtquả,khi lấygiáthấtbạigiữtickcũ;
Bot1TryClosePosition(state,options,deviation,tick.bid,tick.ask,gap,freeze,(ulong)ticket);
return true.
Mỗigiátrị đọc tạiđúngdòngin,khôngchụpcả3dòngtrướcPrintđầutiên. Dùngépchuỗi(string),khôngDoubleToString/StringFormat hoặcđặtsốchữsố. Khôngđọclạivé/khốilượng/TP,khôngkiểmđiềukiệnthêm,khôngbáolỗithêm.

Hàm2 boolBot1StartRealManagement(const bool buy,const string &symbol,const double &unit,const double &stop_distance,const long ticket,Bot1ManagedPosition &position,MqlTick &tick,Bot1VirtualStopState &table,long &open_tickets[],double &initial_stop,double &current_stop,Bot1PendingRequestState &state,Bot1TradeSendOptions &options,const ulong &deviation,const double &gap,const double &freeze).
doublelevel=Bot1VirtualStopLevel(table,open_tickets,symbol,unit,buy?1:2,position.open_price,stop_distance,ticket);
Ghi current_stop=level SAU helper,trướcnhánhgiá. BÁNghiinitial_stop=levelngaytrướckiểmgiá; MUAchỉghiinitial_stop=level ởnhánhkhôngchạm.
Nếubuy?tick.bid<level:level<tick.ask thìreturnBot1CloseRealStopHit(...ticket) vớiđúngrefsđãnhận. DấusoSTRICT<;NaNkhôngchạm,bằngnhaukhôngchạm. Cònkhông,MUAghiinitial_stop=levelrồireturnfalse.
Khônggọichờ/ghi giờ/sửavịthế/đổicờchanged; khôngghicurrent_stoplạisauPrint/đóng. Khônglàmmớigiátrướckiểmchạm. KhôngthêmkiểmTP/trạngtháilệnh/mode/cấpquyền.

Mãđầyđủ,gọn,khôngTODO/hàmrỗng; SUMMARYnóirõchưabiêndịch/chạynếuchưa. Codexkiểm/ghép/biêndịchvàsođộclập.
