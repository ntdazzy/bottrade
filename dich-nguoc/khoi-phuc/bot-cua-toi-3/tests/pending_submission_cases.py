"""Finite input fixtures for the pending-submission caller; no expected outputs."""
import copy,itertools,struct
MAGIC=0x50534233
INTS=['id','buy','check_free_margin','omit_real_sl_tp','virtual_expiration','strategy_magic','strategy_index',
      'digit0','digit1','digit2','margin_reply','volume_reply','limit_reply','initial_accept',
      'retry_count','retry_accept_mask','initial_error','final_error','cache_mode','mutation_at','error_count','case_tag']
DOUBLES=['base_price','unit','stop_distance','take_distance','minimum_stop_price','minimum_freeze_price','ask','bid']
RESULT_NAMES=['events','ordered_hash','digits_calls','margin_calls','volume_calls','limit_calls','send_calls',
 'sleep_calls','print_calls','error_text_calls','mutation_count','error_count','last_error','index',
 'check_free_margin','omit_real_sl_tp','virtual_expiration','strategy_magic','expiration','unit','stop_distance',
 'take_distance','minimum_stop_price','minimum_freeze_price','ask','bid','symbol_hash','comment_hash',
 'trade_magic','async_mode','log_level','margin_mode']+['volume'+str(i) for i in range(9)]+['table%d_%d'%(i,j) for i in range(100) for j in range(2)]
RESULT=struct.Struct('<2i241Q')
assert len(INTS)==22 and len(RESULT_NAMES)==241 and RESULT.size==1936
def base(buy):
    c={k:0 for k in INTS};c.update(buy=buy,check_free_margin=1,strategy_magic=9001,strategy_index=4,
      digit0=3,digit1=3,digit2=3,margin_reply=1,volume_reply=1,limit_reply=1,initial_accept=1,
      expiration=123456789,base_price=100.005,unit=.125,stop_distance=10.,take_distance=20.,
      minimum_stop_price=.5,minimum_freeze_price=.25,ask=90.,bid=110.,symbol='CHECK',comment='note')
    return c
def cases():
    out=[]
    def add(c,group):c=copy.deepcopy(c);c.update(id=len(out),group=group);out.append(c)
    for buy in [0,1]:
        for margin,volume,limit in itertools.product([0,1],repeat=3):
            c=base(buy);c.update(margin_reply=margin,volume_reply=volume,limit_reply=limit);add(c,'early-return-order')
        for flags in itertools.product([0,1,2,255],repeat=2):
            c=base(buy);c.update(check_free_margin=flags[0],omit_real_sl_tp=flags[1]);add(c,'raw-byte-flags')
        for cache,index in itertools.product(range(6),[0,4,8]):
            c=base(buy);c.update(cache_mode=cache,strategy_index=index);add(c,'cache-first-empty')
        for initial,error,retries,mask,final in [(1,132,0,0,0),(0,0,0,0,0),(0,134,0,0,0),
            (0,132,1,0,134),(0,132,1,1,0),(0,132,2,1,134),(0,132,3,7,0)]:
            for omit in [0,255]:
                c=base(buy);c.update(initial_accept=initial,initial_error=error,retry_count=retries,
                  retry_accept_mask=mask,final_error=final,omit_real_sl_tp=omit,error_count=-1);add(c,'retry-bool-and-error')
        for trigger in range(10):
            for omit in [0,255]:
                c=base(buy);c.update(mutation_at=trigger,omit_real_sl_tp=omit,initial_accept=0,initial_error=132,
                  retry_count=2,retry_accept_mask=1,final_error=134);add(c,'live-reads-and-retry')
        for digits in [(-1,0,12),(0,2,8),(11,11,11),(12,2,3),(3,1,0)]:
            c=base(buy);c.update(zip(['digit0','digit1','digit2'],digits));add(c,'digits-reread')
        for bound,delta in itertools.product(['minimum_stop_price','minimum_freeze_price'],[-1e-8,0.,1e-8]):
            c=base(buy);c.update(base_price=100.,digit0=3)
            c['ask' if buy else 'bid']=99. if buy else 101.;c[bound]=1.+delta;add(c,'strict-quote-boundary')
        for field in ['base_price','unit','stop_distance','take_distance','ask','bid','minimum_stop_price','minimum_freeze_price']:
            for value in [-0.,0.,-1.,float('inf'),-float('inf'),float('nan'),1e19,-1e19]:
                c=base(buy);c[field]=value;add(c,'numeric-'+field)
        for symbol,comment in [('', ''),('Vàng.💰','chờ 💰'),('CHECK.long','x'*128)]:
            c=base(buy);c.update(symbol=symbol,comment=comment,initial_accept=0,initial_error=134);add(c,'utf16-and-error-message')
    for buy in [0,1]:
        for field in ['stop_distance','take_distance']:
            for bits in [0x7ff8000000000123,0xfff8000000000456,0x7ff0000000000789,0xfff0000000000abc]:
                c=base(buy);c[field]=struct.unpack('<d',struct.pack('<Q',bits))[0];add(c,'nan-payload-and-subtraction')
            for value in [float('inf'),-float('inf')]:
                c=base(buy);c[field]=value;c['unit']=0.;add(c,'invalid-product-and-subtraction')
    return out
def encode(rows):
    raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
    for c in rows:
        raw+=struct.pack('<22iq8d',*[c[k] for k in INTS],c['expiration'],*[c[k] for k in DOUBLES])
        for k in ['symbol','comment']:
            text=c[k].encode('utf-16-le');raw+=struct.pack('<i',len(text)//2)+text
    return bytes(raw)
def table(mode):
    rows=[[1000.+i,2000.+i] for i in range(100)]
    if mode==0:return [[0.,0.] for _ in rows]
    if mode in [1,2]:rows[50 if mode==1 else 99][0]=0.
    if mode==4:rows[0][0]=float('nan');rows[1][0]=-0.
    if mode==5:
        for i,v in enumerate([float('inf'),-float('inf'),float('nan'),-0.]):rows[i][0]=v
    return rows
