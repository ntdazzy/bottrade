"""Fixed numeric/API inputs only; expected trading behavior is not calculated here."""
import itertools,math,struct
MAGIC=0x4d525433;CASE=struct.Struct('<8i3qI10d');MASK=(1<<64)-1
INTS=['id','buy','scenario','modify_ok','error_code','digits0','digits1','delay_seconds']
LONGS=['ticket','now','opened']
DOUBLES=['sl','tp','bid','ask','unit','activation','distance','gap','freeze','point']
def signed(value):return ((value+(1<<63))&MASK)-(1<<63)
def number(bits):return struct.unpack('<d',struct.pack('<Q',bits))[0]
def cases():
    rows=[];values=[-math.inf,-1e19,-100.125,-0.,0.,.01,100.125,1e19,math.inf,number(0x7ff8000000000123),number(0xfff8000000000456)]
    def add(c,g):c.update(id=len(rows),group=g);rows.append(c)
    for buy in [0,1]:
        b=dict(id=0,buy=buy,scenario=0,modify_ok=1,error_code=4756,digits0=3,digits1=3,delay_seconds=60,
          ticket=7,now=1061,opened=1000,error_count=0,sl=95. if buy else 105.,tp=130. if buy else 70.,
          bid=105. if buy else 94.,ask=106. if buy else 95.,unit=1.,activation=1.,distance=2.,gap=.2,freeze=2.5,point=.01)
        add(dict(b),'normal')
        for field in DOUBLES:
            for value in values:c=dict(b);c[field]=value;add(c,'numeric-'+field)
        for opened,delay in itertools.product([-(1<<63),-1,0,1000,(1<<63)-1],[-(1<<31),-1,0,1,(1<<31)-1]):
            due=signed(opened+delay)
            for difference in [-1,0,1]:
                c=dict(b);c.update(opened=opened,delay_seconds=delay,now=signed(due+difference));add(c,'time-signed-wrap')
        for scenario,ok in itertools.product(range(6),[0,1]):
            c=dict(b);c.update(scenario=scenario,modify_ok=ok);add(c,'api-mutation')
        for d0,d1 in [(-2147483648,2147483647),(-1,0),(0,1),(2,8),(3,2),(11,10),(12,3),(2147483647,-1)]:
            c=dict(b);c.update(digits0=d0,digits1=d1,sl=b['sl']+.123456789);add(c,'digits-separate')
        for ticket,ok in itertools.product([0,1,(1<<53)+1,(1<<63)-1,-(1<<63),-1],[0,1]):
            c=dict(b);c.update(ticket=ticket,modify_ok=ok);add(c,'ticket64')
        for count,code in itertools.product([0,1,(1<<32)-1],[0,1,4001,4756,-1]):
            c=dict(b);c.update(error_count=count,error_code=code,modify_ok=0);add(c,'error-callback-counter')
        quote=b['bid'] if buy else b['ask'];sl=quote-(2.+.01) if buy else quote+2.+.01
        for value in [math.nextafter(sl,-math.inf),sl,math.nextafter(sl,math.inf)]:c=dict(b);c['sl']=value;add(c,'first-price-gate')
        tp=quote+2.5 if buy else quote-2.5
        for value in [math.nextafter(tp,-math.inf),tp,math.nextafter(tp,math.inf)]:c=dict(b);c['tp']=value;add(c,'freeze-equality')
        for gap in [math.nextafter(2.,-math.inf),2.,math.nextafter(2.,math.inf)]:c=dict(b);c['gap']=gap;add(c,'last-gap-equality')
        for fields in [('sl','distance'),('sl','point'),('unit','distance'),('distance','point')]:
            c=dict(b);c.update(zip(fields,[number(0x7ff8000000000123),number(0xfff8000000000456)]));add(c,'nan-operand-order')
    return rows
def encode(rows):
    return struct.pack('<3i',MAGIC,1,len(rows))+b''.join(CASE.pack(*(c[k] for k in INTS),*(c[k] for k in LONGS),c['error_count'],*(c[k] for k in DOUBLES)) for c in rows)
