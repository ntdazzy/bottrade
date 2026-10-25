Viết duy nhất real_blocks_cases.py và SUMMARY.md trong thư mục này. Tạo inputcốđịnh theo CONTRACT.md ở thư mục anh em bot3-real-blocks-check-20261025-r1. Chỉđọc TASK/CONTRACTđó,khôngsourcebot/phan-tichlịchsử. Khôngsửafilekhác/Git/lệnh/tác tử. Codexchạykiểm. Opus5.5maxUltracodeyêucầu. Khôngtínhkếtquảmongđợi/khôngrandom.
ModuleMAGIC0x4d524233,CASEstruct '<22iqQII43d',INTSlist22đúngcontract,DOUBLESlist25,cases()->listdict,encode(rows)->header3int32+records456B. Keys ticket signed64,deviationuint64,index/error_countuint32,volumes/levels9double,groupstring,idliêntục0. Sốdưới4000. Chỉthưviệnchuẩnmath,itertools,struct.
Mỗibuy0/1vàstage0..5 cóbaseline: digits3; modify_ok1,errorcode4756,enabled1,gap_count1,minimum_steps2,counter1,passed_flag1,eligible_flag1,before_open0,shift0,step_enabled1,guard1,prior_changed0,pattern0,ticket7,deviation11,index2,error_count0. slbuy90/sell110,tpbuy130/sell70,open100,volume.1,bidbuy105/sell95,askbuy106/sell96,unit1,trail2,step.5,start1,limit4,reference100,anchor100,gap.2,freeze2.5,point.01,minimum.01,lock_start2,lock_extra1,step_reference0,step_distance1,copied_step.5,initial_stop90,ticket_number7,current_stop95. volumes[i]=.1+i*.01;levelsbuy95+i*.01/sell105+i*.01.
Tạoca cóýnghĩamỗistage thaytừngtrườngliênquan với[-Inf,-1e19,-100.125,-0,+0,.01,100.125,1e19,Inf,NaNpayload7ff8000000000123,fff8000000000456]:
stage0:sl,tp,unit,trail,step,start,limit,anchor,gap,freeze,point,volume,minimum;
stage1:sl,tp,unit,trail,start,limit,reference,gap,freeze,point;
stage2:sl,tp,open_price,unit,gap,freeze,point vàlevels[index];
stage3:sl,tp,unit,lock_start,lock_extra,gap,freeze,point;
stage4:sl,tp,unit,step_distance,step_reference,copied_step,anchor,gap,freeze;
stage5:initial_stop,current_stop,ticket_number.
Thêmtừngnhómnhỏkhôngtíchkhổnglồ:scenario0..11×modify_ok0/1×prior_changed0/1,minimum0đểClosechạy; riêngstage5scenariochỉ0/1/3/4vì3DIGITS;stagesđộc lậpkhôngcầngộpcaquyểntấtcảtrường.
stage0:volumes[index]Inf/NaN,.1;minimum-.01,-0,0,.01,NaN;volume0,.1,Inf. <=60ca/phía nhómnày. thêmdeviation0,2^64-1,ticket0,2^53+1,-1,-2^63mỗitrườngđộclập.
stage1:enabled[-1,0,1,2],passed_flag0,1,2,3,255;tích20ca.
stage2:enabled[-1,0,1,2],eligible_flag0,1,2,255;before_open0,1,2,255;shift0,1,2,255;gap_countintmin,-1,0,intmax;thaytừngtrườngđộclập,khôngtích.
stage4:enabledbyte0,1,2,255;counterintmin,-1,0,1,intmax;minimum_stepsintmin,-1,0,2,intmax;step_reference+0,-0,1,NaN; thaytừngtrườngđộclập,thêmcounterintmax×scenarioDIGITS2=3.
stage5:pattern0..5×guard0,1,2,255×scenario0,1,3,4 (96ca/phía),ticket_number âm0,+0,2^53+2,NaN,Inf,ticket64độclập. GuardbanđầucóthểđổiquaDIGITS3.
Tấtcảstage0..4cóindex0,8vàdigits(-1,0,1,2),(0,1,2,3),(2,8,3,1),(11,10,9,8),(intmin,intmax,-1,12) táchbiệtsaulàmtăngSL.123456789 cho digitsca. errorcount0,2^32-1,errorcode[-1,0,4001,4756]×modify_ok0cho0..3,khôngsaikỳvọng.
ThêmcaseNaN2toánhạng phùhợpstage nhưngkhôngtínhexpected:unit+trail(stage0/1),sl+point(stage1/2/3),unit+lock_extra(stage3),sl+step_distance(stage4). Cảnhbáobộkiểm4000capnếuvượtđừngbỏâmthầmmục,báosốđếmđểCodexchốt.
CaquétgiáchoStage3khóangưỡng:lock_start5±1ulpbuy/4±1ulpsell;extra0±1ulp. stage4gap14±1ulpbuy/13±1ulpsell. Chỉinputkhôngtínhexpected. LưuNaN/âm0từbitskhôngchuẩnhoá,clonearraysmỗica. SUMMARY sốca/chưachạy/mọiđiểmtựchọn.
