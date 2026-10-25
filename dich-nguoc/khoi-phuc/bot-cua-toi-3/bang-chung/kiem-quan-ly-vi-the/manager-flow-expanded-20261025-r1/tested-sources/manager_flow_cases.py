"""Fixed whole-parent fixtures from the functional contract.
The delegated case writer hit its session limit before delivering a file.
Only input configuration is built; no expected manager output is calculated.
"""
import struct
MAGIC=0x4d504d33;CASE=struct.Struct('<20iI')
INTS=['id','buy','profile','position_count','mode','flip_digit','flip_mode','eligible_initial','eligible_after_total','tick_ok','modify_ok','close_ok','delay_pass','digits','index','enabled','magic','error_code','counter','ticket_kind']
def cases():
    out=[]
    def add(group,buy,profile,mode,count=1,**kw):
        c=dict(id=len(out),buy=buy,profile=profile,position_count=count,mode=mode,flip_digit=0,flip_mode=2,eligible_initial=0,eligible_after_total=1,tick_ok=1,modify_ok=1,close_ok=1,delay_pass=0,digits=3,index=2,enabled=1,magic=9001,error_code=4756,counter=1,ticket_kind=0,error_count=0,group=group);c.update(kw);out.append(c)
    for buy in [0,1]:
        for mode in [0,2]:
            for profile in range(23):add('baseline',buy,profile,mode)
            for profile in list(range(9))+[14,20,21]:add('multiple-positions',buy,profile,mode,3)
            add('empty',buy,0,mode,0)
            for profile in [0,14]:
                for digit in range(1,10):add('mode-change',buy,profile,mode,2,flip_digit=digit,flip_mode=2 if mode==0 else 0)
            for eligible in [0,1]:add('eligibility-snapshot',buy,18,mode,3,eligible_after_total=eligible)
            for profile in [6]+list(range(14,22)):add('modify-failure',buy,profile,mode,2,modify_ok=0)
            for profile in [8,9,10,11,12,13,22]:add('close-failure',buy,profile,mode,3,close_ok=0)
            for profile in [0,6,9,10,12,15,16,20]:add('large-tickets',buy,profile,mode,3,ticket_kind=1)
            for profile in [0,9,12,14]:add('tick-failure',buy,profile,mode,2,tick_ok=0)
            for profile in [14,15,17,18,19]:add('error-counter-wrap',buy,profile,mode,modify_ok=0,error_code=-1,error_count=0xffffffff)
            for profile in [14,21]:add('delay-passed',buy,profile,mode,2,delay_pass=1)
    if len(out)>800:raise ValueError('Too many fixed cases: '+str(len(out)))
    return out

def encode(rows):
    encoded=[]
    for ident,c in enumerate(rows):
        if c['id']!=ident or any(type(c[n]) is not int or not -(1<<31)<=c[n]<(1<<31) for n in INTS):raise ValueError('Invalid signed input: '+str(ident))
        if type(c['error_count']) is not int or not 0<=c['error_count']<(1<<32):raise ValueError('Invalid error counter: '+str(ident))
        encoded.append(CASE.pack(*(c[n] for n in INTS),c['error_count']))
    return struct.pack('<3i',MAGIC,1,len(rows))+b''.join(encoded)

def settings(c):
    s=dict(symbol='CHECK',magic=c['magic'],enabled=c['enabled'],unit=1.,stop_distance=10.,take_distance=20.,emergency_offset=.5,gap=.2,freeze=2.5,candle_enabled=[0,0,0],candle_timeframe=[0,0,0],candle_shift=0,anchor_limit=1.,use_anchor=0,high_low_eligible=c['eligible_initial'],timed_activation=0.,timed_distance=0.,timed_delay_seconds=60,virtual_delay_seconds=7,trail=0.,trail_step=0.,trail_start=0.,trail_limit=0.,take_trail_distance=0.,take_trail_start=0.,slippage_enabled=0,slippage_trail=0.,slippage_start=0.,slippage_limit=0.,high_low_gap_count=0,high_low_enabled=0,high_low_before_open=0,high_low_shift=0,high_low_buy_shift=10.,high_low_sell_shift=10.,lock_start=0.,lock_extra=0.,mode=c['mode'],step_enabled=0,step_reference=0.,min_steps=2,step_distance=0.)
    p=c['profile']
    if p==5:s['enabled']=0
    if p in [7,8]:s.update(candle_enabled=[1,0,0],candle_timeframe=[15,0,0],candle_shift=1)
    if p==9:s.update(emergency_offset=0.,stop_distance=.1)
    if p in [14,21]:s.update(timed_activation=1.,timed_distance=2.)
    if p in [15,21,22]:s.update(trail=2.,trail_step=.5,trail_start=1.,trail_limit=4.)
    if p in [16,21]:s.update(take_trail_distance=2.,take_trail_start=-12.)
    if p in [17,21]:s.update(slippage_enabled=1,slippage_trail=2.,slippage_start=-12.,slippage_limit=4.,anchor_limit=-1.)
    if p in [18,21]:s.update(high_low_enabled=1,high_low_gap_count=1)
    if p in [19,21]:s.update(lock_start=2.,lock_extra=1.)
    if p in [20,21]:s.update(step_enabled=1,step_distance=1.)
    return s
def positions(c):
    rows=[];buy=c['buy'];p=c['profile'];big=[9007199254740993,9223372036854775807,18446744073709551615]
    for i in range(c['position_count']):
        r=dict(ticket=7+i if c['ticket_kind']==0 else big[i],type=0 if buy else 1,magic=c['magic'],opened=1000,sl=90. if buy else 110.,tp=130. if buy else 70.,open=100.,volume=.1,comment='note',symbol='CHECK')
        if p==1 and i==0:r['ticket']=0
        if p==2 and i==0:r['type']=1 if buy else 0
        if p==3 and i==0:r['magic']=c['magic']+1
        if p==4 and i==0:r['symbol']='OTHER'
        if p==6:r.update(sl=0.,tp=0.)
        if p==11:r['sl']=106. if buy else 95.
        rows.append(r)
    return rows
def tick_reply(c):
    if c['profile']==9:return (95.,96.) if c['buy'] else (104.,105.)
    return (105.,106.) if c['buy'] else (95.,96.)
def levels_reply(c):
    stop,take=(95.,120.) if c['buy'] else (105.,80.);bid,ask=tick_reply(c)
    if c['profile']==10:stop=106. if c['buy'] else 95.
    if c['profile']==12:stop=bid if c['buy'] else ask
    if c['profile']==13:take=bid if c['buy'] else ask
    return stop,take
def minimum_reply(c):return 0. if c['profile']==22 else .01
