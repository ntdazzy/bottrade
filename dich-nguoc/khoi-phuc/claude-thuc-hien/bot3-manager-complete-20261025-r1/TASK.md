Viết duy nhất Bot3PositionManagement.mqh và SUMMARY.md trong thư mục này. Viết phần ghép quản lý vị thế MQL5 theo mô tả đầyđủ, dùngcáchàmcósẵn. Khôngtựtìmthuậttoán/đọctàiliệuphântíchlịchsử. Khôngsửanguồnchính/Git/lệnh/táctửkhác. Codexkiểm/ghép/chạy. Opus5.5max,Ultracodeyêucầu. Khôngclaimđãbiêndịch/chạy/hoànEA. KhôngTODO,hàmrỗnghoặctựtạoAPI/luậtmới.

Include cácheaders Bot3ManagementPrelude,Anchor,RealStart,RealTimed,RealDistance,
RealTake,RealSlippage,RealHighLow,RealLock,RealCounter,RealStore,VirtualStart,
Virtual,VirtualTake,VirtualFinishFlow. Một số sẽđượcCodexđặtcạnhnguồnchínhtrướckhibiêndịch.
Đọcsourceheaderchính/đềxuấtchỉđểđúngchữký/kiểudữliệu,khôngthayalgorithmđãmôtả.

Khai báo struct Bot3PositionManagementSettings:
string symbol;int magic,enabled;double unit,stop_distance,take_distance,emergency_offset;
uchar candle_enabled[3],candle_timeframe[3],candle_shift;
double anchor_limit;uchar use_anchor;uchar high_low_eligible;
double timed_activation,timed_distance;int timed_delay_seconds,virtual_delay_seconds;
double trail,trail_step,trail_start,trail_limit,take_trail_distance,take_trail_start;
int slippage_enabled;double slippage_trail,slippage_start,slippage_limit;int high_low_gap_count;
Bot3VirtualFinishSettings finish;
modechỉởsettings.finish.mode,khôngthêmbảnsaomodekhác. finishchứahighlow_enabled/beforeopen/shift,
lock_start/extra,step_enabled/reference/min_steps/distance; hai trườnghigh_low_buy_shift/sell_shift
làhằngnộibộđượcbêngọiđặt10.0,tệpghépkhôngtựthaychúng/thêminput.
Khôngtựđặtgiátrịmặcđịnhhoặcloadtừfile/tàikhoảnđểđiềnsettings.

Struct Bot3PositionManagementState:
Bot3ManagementAnchorState anchor;Bot3VirtualStopState table;long open_tickets[];
double current_stop,current_take,volumes[9];uint strategy_index,error_count;int counter;ulong last_ticket;
strategy_indexđượcbêngọiđảmbảo0..8;khôngclamp/index++này.Indexvịthếlàbiếncục bộkhác.
settings/statecóthểbịAPIđổisaukhigọi(cácthamchiếu). Khôngcóp2vùngdữliệukháctrùngnhớ;
mảnglevels[]thamchiếu9mứcchophíađanggọi,bêngọiđảm bảohợplệ,khôngtựtínhmứcmới.

Hàmpublic:
bool Bot3ManagePositions(const bool buy,const Bot3PositionManagementSettings &settings,
Bot3PositionManagementState &shared,const double &levels[],Bot3PendingRequestState &requests,
Bot3TradeSendOptions &options,const ulong &deviation).
Đượcphéptáchmộthàmprivatexửlýmộtvịthếvớibool&changedvàboolreturnclose_reachednếucầnđểtránhđúp
luồngcontinue. Khôngtạothêmtầngfactory/service/strategy. Mộtboolbuyđãđủhaihướng,khôngcần2wrapperrỗng.

## Vòng ngoài
int total=PositionsTotal() đúngmộtlầnđầu. Nếutotal<1returnfalse.
SAUAPIđầu,cacheuchar eligible=settings.high_low_eligible DUYNHẤT1LẦNchotấtcảvịthếtronglượt.
bool any_changed=false;int index=0. Mỗivịthếchanged=false; nếuclosedcủaluồngdướilàtrue,
RETURNTRUEKHỎITOÀNHÀMNGAY(khôngđọctotal/tăngindex/sangvịthếtiếp).
Xửlýxong/skipthìany_changed=any_changed||changed,index++,total=PositionsTotal() LẠI;
lặpnếuindex<total,sairareturnany_changed. Khôngchỉcachetotalđầuhoặclặpngược.

## Mỗi vịthế
1 Bot3ManagedPositionposition; gọiBot3ReadManagementPosition(index,buy,settings.magic,
settings.enabled,settings.symbol,shared.last_ticket,tick,position). CầnMqlTicktickchungtronglượt
haycục bộ? CỤCBỘmỗivịthếnhưnggiữgiácũkhimộtlầnSymbolInfoTickthấtbại: dùngMqlTicktick
đượcbêngọiduytrìlàchưađủ; đểtránhđoán, THÊMtrườngMqlTicktickvàostructshared, gọihelperbằngshared.tick.
KhôngZeroMemorytickmỗivịthế. Falsebỏquaphầncònlạivàđihậuvòng. Helperđọc/lọcđãloTicket0.
2 Bot3FillManagementInitialLevels(buy,symbol,unit,stop_distance,take_distance,position,requests,options),
bỏquakếtquảnhưhelper. Khôngtựreadpositionlại. Sauđógọinhómnến0,1,2đúngthứtựqua
Bot3CloseManagementCandle(buy,symbol,group,settings.candle_enabled[group],settings.candle_timeframe[group],
settings.candle_shift,position,shared.tick,requests,options,deviation,settings.gap,settings.freeze).
THÊMdoublegap,freezevàosettings(haigiátrịnàylàthànhphầnđộc lập,nộidungkhácfinish).
Cácnhómđóngtheonếnkhôngkhiếnreturn/changed=true,tấtcảvẫnchạytiếpcùngvịthế.
3 Bot3PrepareManagementAnchor(shared.anchor,symbol,settings.unit,settings.finish.step_reference,
settings.anchor_limit,settings.use_anchor,buy,position.ticket_number,position.open_price).
Cacheconstlongticket=shared.anchor.ticket;constdoubleanchor=shared.anchor.reference;
constdoubleraw_reference=shared.anchor.level;constboolpassed=shared.anchor.gap_passed;
constdoubleticket_number=(double)ticket. CáclocalnàyKHÔNGđổitheoAPIvềsau.
shared.anchor.step_referencelàbảnstepđãchéptrướcdigitsvẫnđượctruyềnthamchiếuởcácbướcsaunhưcótronghelper.
4 Cổngđóngsớm: chụpu=settings.unit;distance=settings.stop_distance;
BUYtrigger=(position.open_price-u*(distance+0.0))-settings.emergency_offset;
SELLtrigger=u*(distance+0.0)+position.open_price+settings.emergency_offset.
Nếubuy?shared.tick.bid<trigger:trigger<shared.tick.ask(cóthứtựNaNfalse),thì
SymbolInfoTick(symbol,shared.tick) bỏquakếtquả;rồiPositionGetDouble(POSITION_VOLUME) bỏquakếtquả;
SAUhaicallmớiđọcshared.last_ticketvàBot3TryClosePosition(requests,options,deviation,
shared.tick.bid,shared.tick.ask,settings.gap,settings.freeze,shared.last_ticket);bỏquakếtquảcon;
returntruekhỏitoànmanager. Khôngin cảnhbáoởđườngđóngsớmnày.
5 Đọcmode=settings.finish.mode. Nếukhác2chạytoànbộđoạnTHẬTởdưới.
Nếubằng2bỏquađoạnTHẬTvàchạyđoạnẢO.

## ĐoạnTHẬT theođúngthứtự
A doubleinitial_real_stop=0;gọiBot3StartRealManagement(buy,symbol,settings.unit,settings.stop_distance,
ticket,position,shared.tick,shared.table,shared.open_tickets,initial_real_stop,shared.current_stop,
requests,options,deviation,settings.gap,settings.freeze). True→returntruekhỏitoànhàm.
B changed=buy?Bot3AdvanceTimedBuyStop(...):Bot3AdvanceTimedSellStop(...),
tham sốsymbol,unit,timed_activation,timed_distance,timed_delay_seconds,gap,freeze,position,tick,
requests,options,shared.error_count,(ulong)ticket. Khôngchỉgánchangedkhihàmsửatrảtrue;
chínhboolhelperđãmangýnghĩađúng.
C Bot3AdvanceDistanceBuyStop/SellStop(symbol,unit,trail,trail_step,trail_start,trail_limit,
anchor,gap,freeze,position,tick,shared.volumes,shared.strategy_index,changed,requests,options,
deviation,shared.error_count,(ulong)ticket). Nếuhelpertrue→returntruekhỏitoànhàm.
D Bot3AdvanceRealTakeBuy/Sell(symbol,unit,take_trail_distance,take_trail_start,anchor,gap,
freeze,position,tick,volumes,index,changed,requests,options,deviation,error_count,ticket).
True→returntruekhỏitoànhàm.
E Bot3AdvanceSlippageRealBuyStop/SellStop(symbol,unit,slippage_enabled,(uchar)passed,
raw_reference,slippage_trail,slippage_start,slippage_limit,gap,freeze,position,tick,changed,
requests,options,error_count,ticket).
F Bot3AdvanceHighLowRealBuyStop/SellStop(symbol,finish.high_low_enabled,eligible,
high_low_gap_count,unit,finish.high_low_before_open,finish.high_low_shift,gap,freeze,levels,
index,position,tick,changed,requests,options,error_count,ticket). DùngeligibleđãcacheđầuVÒNGNGOÀI.
G Bot3AdvanceRealLockBuyStop/SellStop(symbol,finish.lock_start,finish.lock_extra,unit,gap,
freeze,position,tick,changed,requests,options,error_count,ticket).
H Bot3AdvanceRealCounterBuyStop/SellStop(symbol,finish.step_enabled,finish.step_reference,
finish.min_steps,finish.step_distance,unit,shared.anchor.step_reference,anchor,gap,freeze,
shared.counter,position,tick,changed,requests,options,ticket). Helpertựbỏquakhichangedtrue;
khôngbỏcounterchỉvìSLđãđổinhưngchưaModify.
I chụpboolhit=buy?tick.bid<position.sl:position.sl<tick.ask;shared.current_stop=position.sl;
nếuhitBot3CloseRealStopHit(buy,symbol,current_stop,tick,requests,options,deviation,gap,freeze,ticket),
returntrue. Dấu<nghiêmngặt,bằngnhaukhônghit.
J Bot3StoreRealStop(symbol,initial_real_stop,shared.current_stop,ticket_number,shared.table).
SAUhelperlưu,đọclạisettings.finish.mode MỚI; nếukhác2kếtthúcvịthế,falseclose_reached.
Nếuvẫnbằng2rơixuốngẢO,kếthừachangedtừthật,khôngclear.

## ĐoạnẢO
doubleinitial_stop=0,initial_take=0;
1 Bot3StartVirtualManagement(buy,symbol,unit,stop_distance,virtual_delay_seconds,ticket,
position,tick,table,open_tickets,initial_stop,initial_take,current_stop,current_take,requests,
options,deviation,gap,freeze). True→returntruekhỏitoànhàm.
2 Bot3AdvanceTimedVirtualStop(buy,symbol,unit,timed_activation,timed_distance,timed_delay_seconds,
freeze,position,tick,current_stop,changed).
3 Bot3AdvanceDistanceVirtualStop(buy,symbol,unit,trail,trail_step,trail_start,trail_limit,
anchor,position,tick,volumes,index,current_stop,changed,requests,options,deviation,gap,freeze,ticket).
True→returntrue.
4 Bot3AdvanceVirtualTake(buy,symbol,unit,take_trail_distance,take_trail_start,anchor,position,
tick,volumes,index,current_take,changed,requests,options,deviation,gap,freeze,ticket). True→returntrue.
5 Bot3AdvanceSlippageVirtualStop(buy,symbol,unit,slippage_enabled,passed,raw_reference,
slippage_trail,slippage_start,slippage_limit,freeze,position,tick,current_stop,changed).
6 boolclosed=Bot3FinishVirtualManagement(buy,symbol,finish,unit,gap,freeze,anchor,
shared.anchor.step_reference,position,tick,levels,index,current_stop,current_take,changed,
shared.counter,initial_stop,initial_take,ticket,table,requests,options,deviation).
True→returntruekhỏitoànhàm;falseđikếtthúcvịthế. KHÔNGđọclạimodehoặclặplạiảoởđuôinày.

Tấtcảcàiđặt/lưuđộngđềutruyềntừsettings/shared;khôngsnapshotstruct/mảngđểrútgọntêntừđó
làmmấtcáclầnđọcsauAPI. Cóthểdùngtham sốhelperprivatechoquảnlýmộtvịthếđểgiữmãgọn,
nhưngkhôngtựaliasMQLlocalreferencekhônghợplệ. Chỗchưađúnggiaodiệnhãyđọcsourceđượcchỉđịnh
vànêurõmọiđiềutựchọntrongSUMMARY,khôngđổiLogic/điềukiện/thứtự.
