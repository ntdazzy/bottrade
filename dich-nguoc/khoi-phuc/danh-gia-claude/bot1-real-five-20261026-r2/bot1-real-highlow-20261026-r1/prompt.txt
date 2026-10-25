Viết duy nhất Bot1ManagementRealHighLow.mqh và SUMMARY.md trong thư mục đề xuất này. Chức năng: dời dừng lỗ thật theo một bảng mức cao/thấp do bên gọi cung cấp. Codex đã chốt các công thức/trình tự dưới đây; bạn viết mã theo mô tả, không tìm thuật toán. Không đọc EX5/mã máy/thư mục phân tích; chỉ đọc header bot1 hiện hành để đúng kiểu/phong cách. Không sửa nguồn chính/Git/MT5, không chạy lệnh, không tạo tác tử. Opus5.5max, Ultracode được yêu cầu.

Header guard, include Bot1ManagementPrelude.mqh và Bot1ManagementMessages.mqh. Hai hàmvoid Bot1AdvanceHighLowRealBuyStop/SellStop cùng18tham số:
(const string &symbol,const int &enabled,const uchar eligible_flag,const int &gap_count,const double &unit,const uchar &before_open,const uchar &shift_setting,const double &gap,const double &freeze,const double &levels[],const uint &strategy_index,Bot1ManagedPosition &position,MqlTick &tick,bool &changed,Bot1PendingRequestState &state,Bot1TradeSendOptions &options,uint &error_count,const ulong ticket).
eligible_flag/ticket là giá trị chụp; mọi tham chiếu khác có thể bị dịch vụ giả kiểm thử thay đổi. Bên gọi bảo đảm index hợp lệ. Không thêm kiểm/lọc giá trị, epsilon hoặc luật dự phòng. Mọi cổng so sánh < phải viết dạng if(!(a<b))return để NaN không đi qua. before_open chỉ xét bitthấp; shift_setting xét khác0. Dùng Bot1RoundPrice và Bot1ModifyPosition sẵn có, không NormalizeDouble/viết lại helper. Không đổiTP, đóng vị thế, hỏi khối lượng, lấy tick mới hoặc ghi bảng.

Hàm phụ Bot1PrintHighLowError(uint &counter): đọc GetLastError1lần; string message=Bot1TradeErrorText(code,counter); Print("error: '"+message+"' when modifying stoploss"). Không tự tăngcountervìhelperđãtăng, khôngResetLastError, khôngđổi khoảng trắng/chữhoa.

Đầu cảhai: nếu enabled<=0 hoặc eligible_flag==0 thìreturn, giữsl/changed.

MUA đúngthứtự:
1.level1=levels[strategy_index] TRƯỚC DIGITS1; lấy digits1=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS). gate_base=gap+position.sl TRƯỚC POINT1; point1=SymbolInfoDouble(symbol,SYMBOL_POINT); gate=Bot1RoundPrice(gate_base+point1,digits1). Nếu !(gate<level1),return.
2.quote=tick.bid rồi level2=levels[strategy_index] mới SAU POINT1. count=(double)gap_count, captured_unit=unit; nếu !(level2<quote-count*captured_unit),return.
3.Nếu !(level2<position.open_price) và(before_open&1)!=0 thìreturn. Trường hợp NaN ởmộtvế vẫn cóthể đi tiếp nếu bitbefore_open=0; đừng thêm kiểmNaN.
4.Lấy DIGITS2. SAU dịchvụ mới đọcshift=(shift_setting!=0?10.0:0.0),bid/unit/gap: boundary_base=(tick.bid-shift*unit)-gap. SAU ĐÓ gọi POINT2; boundary=Bot1RoundPrice(boundary_base-point2,digits2). level2 vẫn làbảnchụp bước2; nếu !(level2<boundary),return.
5.Nếu !(tick.bid<position.tp-freeze),return; không thêmDIGITSởđây.
6.Lấy DIGITS3, SAU ĐÓ mớiđọc levels[strategy_index] và làmtròn thànhnew_sl. Ghi position.sl=new_sl TRƯỚC kiểmgap. Nếu !(new_sl<tick.bid-gap),return, GIỮslmới vàchangedcũ.
7.boolok=Bot1ModifyPosition(state,options,ticket,position.sl,position.tp); NGAY SAU lời gọisửa đặtchanged=true TRƯỚC kiểmok. Nếu !ok gọiBot1PrintHighLowError(error_count), khônginởnhánhthànhcông.

BÁN đúngthứtự:
1.level1=levels[strategy_index],gate_base=position.sl-gap TRƯỚC POINT1; gọipoint1. Nếu !(level1<gate_base-point1),return. KhôngDIGITS/làmtrònởcổngnày.
2.captured_unit=unit rồi level2=levels[strategy_index],quote=tick.ask SAU POINT1. Nếu !(((double)gap_count*captured_unit+quote)<level2),return.
3.Nếu !(position.open_price<level2) và(before_open&1)!=0 thìreturn, giữ tínhchấtNaNnhưMUA.
4.shift=(shift_setting!=0?10.0:0.0);boundary_base=(quote+captured_unit*shift)+gap. Gọi POINT2 rồi nếu !((boundary_base+point2)<level2),return. KhôngDIGITS/làmtròn, khôngđọclạiunit/quote/level2ởcổngnày.
5.Nếu !((freeze+position.tp)<tick.ask),return, dùngaskMỚI sauPOINT2.
6.Lấy DIGITS1; candidate=Bot1RoundPrice(levels[strategy_index],digits1),đọcindex/levelMỚI. Nếu !(candidate<position.sl),return; CHƯAghisl.
7.Lấy DIGITS2; new_sl=Bot1RoundPrice(levels[strategy_index],digits2),đọcindex/levelMỚIlầnnữa. Ghi position.sl=new_sl TRƯỚC kiểmgap. Nếu !((tick.ask+gap)<new_sl),return, giữslmới/changedcũ.
8.Sửa, đặtchanged=true trước kiểmok và báolỗi nếu !ok giốngMUA. Không thayđổi cờbefore_open/shift_setting/eligible_flaghoặclevels.

Mãđầyđủ,gọn,rõ; khôngTODO/hàmrỗng, khôngluậttựthêm. SUMMARYghiđúngchưa biên dịch/chạy nếu chưa; Codex sẽkiểm/ghép/biêndịch/so bản gốc độc lập.
