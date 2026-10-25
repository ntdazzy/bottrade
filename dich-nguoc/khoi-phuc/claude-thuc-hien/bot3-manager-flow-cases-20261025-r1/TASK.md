Viết duy nhất manager_flow_cases.py và SUMMARY.md trong thư mục này. ChỉtạoinputcốđịnhvàfixturekhởitạotheoCONTRACT.md ởthưmụcchunganh em bot3-manager-flow-check-20261025-r1. Khôngđọcsourcebot/phântíchlịchsử,khôngviết thuậttoánmanager/expected. Khôngsửafilekhác/Git/chạylệnh/táctử. Opus5.5maxUltracodeyêucầu.Codexchạykiểm.
MAGIC0x4d504d33,CASEstruct '<20iI',INTSlist20đúngCONTRACT,cases()->listdict,encode(rows)->header3int32+records84byte.
Thêmsettings(c)->dictfieldvaluesđúngprofileđểCodexcấpdữliệuchobộchạy. Khôngtínhbấtkỳkếtquảgiaodịch/nhánhnàosẽđạt.
settingsdictphẳnggồmsymbol,magic,enabled,unit,stop_distance,take_distance,emergency_offset,gap,freeze,candle_enabled3,candle_timeframe3,candle_shift,anchor_limit,use_anchor,high_low_eligible,timed_activation,timed_distance,timed_delay_seconds,virtual_delay_seconds,trail,trail_step,trail_start,trail_limit,take_trail_distance,take_trail_start,slippage_enabled,slippage_trail,slippage_start,slippage_limit,high_low_gap_count,high_low_enabled,high_low_before_open,high_low_shift,high_low_buy_shift,high_low_sell_shift,lock_start,lock_extra,mode,step_enabled,step_reference,min_steps,step_distance.
Thêmpositions(c)->listdict đúnginputrowvàprofile; tick_reply(c)->(bid,ask),levels_reply(c)->(stop,take),minimum_reply(c)->double. Đây chỉlàkhởitạođầuvào,khôngđọckếtquả. Ticketulongcókhoảng0..2^64-1. Khôngdùngrandom/expected,thưviệnchuẩnstruct,itertools.
Cađềnghịdưới500,từngnhómđộclập(khôngtíchkhổnglồ):
baselineprofile0..22×buy0/1×mode0/2,count1(92ca);
multipo sprofile0..8,14,20,21×buy0/1×mode0/2,count3;
emptybuy0/1×mode0/2,count0;
modeflipprofile0và14,buy0/1,initialmode0/2,count2,flip_digit1..9,flip_modengượclại0↔2;
eligibilityprofile18,buy0/1,mode0/2,count3,eligible_after_total0/1;
modifyfalseprofile6,14..21,buy0/1,mode0/2,count2,modify_ok0;
close_replyfalseprofile8,9,10,11,12,13,22,buy0/1,mode0/2,count3,close_ok0;
ticket64profile0,6,9,10,12,15,16,20,buy0/1,mode0/2,count3,ticket_kind1;
tickfalseprofile0,9,12,14,buy0/1,mode0/2,count2,tick_ok0;
error_countwrapprofile14,15,17,18,19,buy0/1,mode0/2,count1,modify_ok0,error_code-1,error_count2^32-1.
Mặcdịnhmode0,count1,flip_digit0,flip_mode2,eligible_initial0,eligible_after_total1,tick_ok1,modify_ok1,close_ok1,delay_pass0,digits3,index2,enabled1,magic9001,error_code4756,counter1,ticket_kind0,error_count0.
Đềnhómtổngcóthểtrên500,phảigiữđủnhómvàbáosốđếmthực,KHÔNGcắtâmthầmchođủ500. Nếu>800raiseValueErrorvớisốđếm.
Casesidliêntụcgroupmôtả,listskhôngalias,encodekiểmrange/size.Cácloạigiátrịnull/chữUnicodechưathuộctậpnày,nêurõ,khôngthêmbấtngờ.
