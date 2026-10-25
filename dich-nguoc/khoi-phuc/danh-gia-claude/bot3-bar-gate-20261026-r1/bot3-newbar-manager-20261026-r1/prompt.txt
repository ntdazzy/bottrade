Viết duy nhất Bot3ManagementBarGate.mqh và SUMMARY.md vào CHÍNH thư mục đề xuất này. Chức năng MQL5: chỉ gọi hai chiều quản lý vị thế khi thời gian nến đã đổi. Codex đã chốt trình tự sau; bạn viết mã theo mô tả, không tự tìm thuật toán. Không đọc EX5/mã máy/phân tích; chỉ đọc headerBot3PositionManagement.mqh đểđúnggiaodiện. Không sửa nguồn chính/Git/MT5,chạy lệnh hoặc tạo tác tử. Opus5.5max,Ultracodeđược yêu cầu. Nếu ghi bịtừchối,trảđầymãtrongcâutrảlờiđểCodexlưu,khôngđổinơighi.

Headerguard/include Bot3PositionManagement.mqh. Một hàm:
bool Bot3ManageOnBarChange(const string &symbol,const int &timeframe,const uint strategy_index,long &last_times[],const Bot3PositionManagementSettings &settings,Bot3PositionManagementState &shared,const double &buy_levels[],const double &sell_levels[],Bot3PendingRequestState &requests,Bot3TradeSendOptions &options,const ulong &deviation).

Bên gọi bảođảm strategy_index0..8 và last_timesđủ9ô. strategy_indexlàgiátrịchụp, khôngđọclạishared.strategy_indexđểchọnôthờigian. Cácsettings/shared/levels/vùngthờigian&cóthểbịdịchvụthayđổi;khôngcopycảsettings/sharedhoặcresetgiữa2lầngọiquảnlý.
Đúngthứtự:
1.constENUM_TIMEFRAMESframe=(ENUM_TIMEFRAMES)timeframe;constlongprevious=last_times[strategy_index];rồi gọiiTime(symbol,frame,1),éplongthànhobserved. Nếuprevious==observedreturnfalse,khôngghilạiôthờigian/khônggọiquảnlý. previousphảichụptrước iTime;khôngđọclạilast_timesđểso sauiTime.
2.Nếukhác, gọiiTimelần2vớitimeframeĐỌCMỚIsaulần1,shift1,symbolref;ghilast_times[strategy_index]=(long)kếtquảlần2 SAUlờigọi. Khôngdùngkếtquảlần1đểghi,khôngthêmkiểm0/lỗihoặcvòngchờ.
3.boolbuy_changed=Bot3ManagePositions(true,settings,shared,buy_levels,requests,options,deviation).
4.bool sell_changed=Bot3ManagePositions(false,settings,shared,sell_levels,requests,options,deviation),LUÔNphảigọiSAUmua,kểcảmuađãtrảtrue. Dùngcùngcácvùngthamchiếusaucácbiếnđổicủamua;khôngchụptrước/càiđặtlạicácgiátrị.
5.returnbuy_changed||sell_changed,SAUkhiđãgọixongcảhai. KhôngdùngORngắnmạchđểghéphailờigọitrựctiếp,khiếnmuađạtthìbỏquabán.

Giữcáclối trảvề: bằngthờigian→false; cóđổi→kếtquảORhaihàm. KhôngtựreturntoànEA/gọihàmkhác,khônglấytick/thêmgiờgiao dịch/vàolệnhhoặcđọcmode. Bêngọisẽquyếtđịnhdừngphầnchươngtrìnhcònlạikhitrảtrue. Đâychỉlàphầnđầugọiquảnlý,chưađầyđủchươngtrìnhchính.
Mãgọn,rõ,khôngTODO/hàmrỗng/khunghệthống/tuỳchọnthừa. SUMMARYnóirõchưabiêndịch/chạynếuchưa; Codexsẽkiểm/ghép/sođộclập.
