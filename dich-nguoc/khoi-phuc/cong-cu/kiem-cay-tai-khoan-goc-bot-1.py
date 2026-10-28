"""Exact bit-vector control-flow proof for the captured login decision tree.
Private outputs only. Never print account values.
"""
import argparse,hashlib,importlib.util,json,random,re,struct,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'.local/auth-symbolic-runtime'))
import z3
from capstone import Cs,CS_ARCH_X86,CS_MODE_64,CS_OP_REG,CS_OP_IMM,CS_OP_MEM
BASE=0x23e5aa10000;LO=0x407d2;HI=0x457cb;RET=0x3d92d;MASK=(1<<64)-1
CAPTURE=ROOT/'khoi-phuc/bot-cua-toi-1/bang-chung/captures/luot-20261023-r1'
OLD=ROOT/'.local/bot1-auth-original-data-20261028-r1/data.private.json'
OUT=None
def need(ok,msg):
    if not ok:raise RuntimeError(msg)
def bv(n,w=64):return z3.BitVecVal(n&((1<<w)-1),w)
def resize(v,w):
    return z3.ZeroExt(w-v.size(),v) if v.size()<w else z3.Extract(w-1,0,v) if v.size()>w else v
def aliases(name):
    small={'al':('rax',8,0),'ah':('rax',8,8),'ax':('rax',16,0),'eax':('rax',32,0),
      'bl':('rbx',8,0),'bh':('rbx',8,8),'bx':('rbx',16,0),'ebx':('rbx',32,0),
      'cl':('rcx',8,0),'ch':('rcx',8,8),'cx':('rcx',16,0),'ecx':('rcx',32,0),
      'dl':('rdx',8,0),'dh':('rdx',8,8),'dx':('rdx',16,0),'edx':('rdx',32,0),
      'sil':('rsi',8,0),'si':('rsi',16,0),'esi':('rsi',32,0),
      'dil':('rdi',8,0),'di':('rdi',16,0),'edi':('rdi',32,0)}
    if name in small:return small[name]
    if name.startswith('r') and name[1:-1].isdigit() and name[-1] in 'dwb':return name[:-1],{'d':32,'w':16,'b':8}[name[-1]],0
    return name,64,0
def getreg(regs,name):
    key,width,offset=aliases(name);need(key in regs,'UNKNOWN_REGISTER '+name)
    return z3.Extract(offset+width-1,offset,regs[key]) if width<64 else regs[key]
def setreg(regs,name,value):
    key,width,offset=aliases(name);value=resize(value,width);regs=dict(regs)
    if width==64:regs[key]=value
    elif width==32:regs[key]=z3.ZeroExt(32,value)
    else:
        mask=((1<<width)-1)<<offset
        regs[key]=(regs[key]&bv(~mask))|(z3.ZeroExt(64-width,value)<<offset)
    regs[key]=z3.simplify(regs[key]);return regs
def address(i,op,regs):
    mem=op.mem;v=bv(mem.disp)
    if mem.base:v+=resize(getreg(regs,i.reg_name(mem.base)),64)
    if mem.index:v+=resize(getreg(regs,i.reg_name(mem.index)),64)*mem.scale
    return z3.simplify(v)
def operand(i,op,regs,width=None):
    w=width or op.size*8
    if op.type==CS_OP_REG:return resize(getreg(regs,i.reg_name(op.reg)),w)
    if op.type==CS_OP_IMM:return bv(op.imm,w)
    raise RuntimeError('UNSUPPORTED_OPERAND '+hex(i.address)+' '+i.mnemonic)
def flags_for(lhs,rhs,operation):
    w=lhs.size();res=lhs-rhs if operation=='sub' else lhs+rhs if operation=='add' else lhs
    sign=lambda a:z3.Extract(w-1,w-1,a)==bv(1,1)
    of=z3.And(sign(lhs)!=sign(rhs),sign(res)!=sign(lhs)) if operation=='sub' else z3.And(sign(lhs)==sign(rhs),sign(res)!=sign(lhs)) if operation=='add' else z3.BoolVal(False)
    cf=z3.ULT(lhs,rhs) if operation=='sub' else z3.ULT(res,lhs) if operation=='add' else z3.BoolVal(False)
    return {'zf':res==bv(0,w),'sf':sign(res),'of':of,'cf':cf}
def condition(cc,f):
    cc=cc.removeprefix('cmov').removeprefix('set').removeprefix('j');z,s,o,c=f['zf'],f['sf'],f['of'],f['cf']
    table={'e':z,'z':z,'ne':z3.Not(z),'nz':z3.Not(z),'a':z3.And(z3.Not(c),z3.Not(z)),
      'nbe':z3.And(z3.Not(c),z3.Not(z)),'ae':z3.Not(c),'nb':z3.Not(c),'nc':z3.Not(c),
      'b':c,'c':c,'nae':c,'be':z3.Or(c,z),'na':z3.Or(c,z),
      'g':z3.And(z3.Not(z),s==o),'nle':z3.And(z3.Not(z),s==o),'ge':s==o,'nl':s==o,
      'l':s!=o,'nge':s!=o,'le':z3.Or(z,s!=o),'ng':z3.Or(z,s!=o),'s':s,'ns':z3.Not(s)}
    need(cc in table,'UNSUPPORTED_CONDITION '+cc);return z3.simplify(table[cc])
def main():
    need(not OUT.exists(),'OUTPUT_EXISTS');cap=json.loads((CAPTURE/'capture.json').read_text());regions=[]
    for row in cap['regions']:
        raw=(CAPTURE/row['file']).read_bytes();need(hashlib.sha256(raw).hexdigest()==row['sha256'],'CAPTURE_HASH_CHANGED');regions.append((row['base'],raw))
    def memory(address,size):
        for base,data in regions:
            if base<=address and address+size<=base+len(data):return data[address-base:address-base+size]
        raise RuntimeError('TABLE_OUTSIDE_CAPTURE')
    function=memory(BASE+0x3d6c0,0x457cb-0x3d6c0)
    need(hashlib.sha256(function).hexdigest()=='7723b57d62ea7b205f2e8086679e8a7d23774416ca98c9369be426fde0365ea5','FUNCTION_CHANGED')
    raw=memory(BASE+LO,HI-LO);decoder=Cs(CS_ARCH_X86,CS_MODE_64);decoder.detail=True;instructions={i.address:i for i in decoder.disasm(raw,LO)}
    x=z3.BitVec('login',64);names=['rax','rbx','rcx','rdx','rsi','rdi','rbp','rsp']+['r'+str(i) for i in range(8,16)]
    regs={n:z3.BitVec('initial_'+n,64) for n in names};regs['rdi']=x;regs['rsi']=(regs['rsi']&bv(~255))|bv(1)
    initialflags={k:z3.Bool('initial_'+k) for k in ['cf','zf','sf','of']}
    solver=z3.Solver();solver.set(timeout=30000);checks=0
    def sat(cond):
        nonlocal checks
        checks+=1;solver.push();solver.add(cond);result=solver.check();solver.pop();need(result!=z3.unknown,'SOLVER_UNKNOWN');return result==z3.sat
    work=[(LO,z3.BoolVal(True),regs,initialflags)];terminals=[];accepted=[];visited=set();branches=set();steps=0;tables=0
    while work:
        pc,path,regs,flags=work.pop()
        while pc!=RET:
            steps+=1;need(steps<2000000,'STEP_LIMIT');need(pc in instructions,'PC_OUTSIDE_TREE '+hex(pc));i=instructions[pc];visited.add(pc);mn=i.mnemonic;ops=i.operands;nextpc=pc+i.size
            if mn in ['nop','int3']:
                need(mn=='nop','REACHABLE_INT3');pc=nextpc;continue
            if mn in ['mov','movabs','movzx','movsx','movsxd']:
                need(ops[0].type==CS_OP_REG,'MOV_TARGET');name=i.reg_name(ops[0].reg);v=operand(i,ops[1],regs)
                if mn in ['movsx','movsxd'] and v.size()<ops[0].size*8:v=z3.SignExt(ops[0].size*8-v.size(),v)
                regs=setreg(regs,name,v)
            elif mn=='lea':regs=setreg(regs,i.reg_name(ops[0].reg),address(i,ops[1],regs))
            elif mn in ['cmp','test','add','sub','xor','or','and']:
                lhs=operand(i,ops[0],regs);rhs=operand(i,ops[1],regs,lhs.size())
                if mn in ['cmp','sub']:flags=flags_for(lhs,rhs,'sub');value=lhs-rhs
                elif mn=='add':flags=flags_for(lhs,rhs,'add');value=lhs+rhs
                else:
                    value=lhs&rhs if mn in ['test','and'] else lhs^rhs if mn=='xor' else lhs|rhs;flags=flags_for(value,bv(0,value.size()),'logic')
                if mn not in ['cmp','test']:regs=setreg(regs,i.reg_name(ops[0].reg),value)
            elif mn=='bt':
                value=operand(i,ops[0],regs);index=operand(i,ops[1],regs,value.size())&bv(value.size()-1,value.size());flags=dict(flags,cf=(z3.LShR(value,index)&bv(1,value.size()))==bv(1,value.size()))
            elif mn.startswith('set'):
                regs=setreg(regs,i.reg_name(ops[0].reg),z3.If(condition(mn,flags),bv(1,8),bv(0,8)))
            elif mn.startswith('cmov'):
                lhs=operand(i,ops[0],regs);rhs=operand(i,ops[1],regs,lhs.size());regs=setreg(regs,i.reg_name(ops[0].reg),z3.If(condition(mn,flags),rhs,lhs))
            elif mn=='jmp':
                if ops[0].type==CS_OP_IMM:pc=ops[0].imm;continue
                need(ops[0].type==CS_OP_MEM,'INDIRECT_JUMP_TYPE');expr=address(i,ops[0],regs);probe=z3.Solver();probe.set(timeout=30000);probe.add(path);count=0
                while probe.check()==z3.sat:
                    count+=1;need(count<=4096,'JUMP_TABLE_TOO_LARGE');addr=probe.model().eval(expr,model_completion=True).as_long();target=struct.unpack('<Q',memory(addr,8))[0]-BASE
                    work.append((target,z3.simplify(z3.And(path,expr==bv(addr))),dict(regs),dict(flags)));probe.add(expr!=bv(addr));tables+=1
                need(probe.check()==z3.unsat,'JUMP_TABLE_UNKNOWN');break
            elif mn.startswith('j'):
                need(ops[0].type==CS_OP_IMM,'JCC_TARGET');cond=condition(mn,flags);branches.add(pc)
                yes=z3.simplify(z3.And(path,cond));no=z3.simplify(z3.And(path,z3.Not(cond)))
                if sat(yes):work.append((ops[0].imm,yes,dict(regs),dict(flags)))
                if sat(no):pc=nextpc;path=no;continue
                break
            else:raise RuntimeError('UNSUPPORTED_OPCODE '+hex(pc)+' '+mn)
            pc=nextpc
        else:
            terminals.append(path);accepted.append(z3.simplify(z3.And(path,z3.Extract(7,0,regs['rsi'])!=bv(0,8))))

    coverage=z3.simplify(z3.Or(*terminals));need(not sat(z3.Not(coverage)),'UNCOVERED_INPUT_DOMAIN')
    accept=z3.simplify(z3.Or(*accepted))
    from z3.z3util import get_vars
    need({str(v) for v in get_vars(accept)}<={'login'},'UNPROVEN_LIVE_IN_REGISTER')
    model=z3.Solver();model.set(timeout=30000);model.add(accept);allowed=[]
    while model.check()==z3.sat:
        value=model.model().eval(x,model_completion=True).as_long();allowed.append(value);need(len(allowed)<=100000,'ALLOW_SET_NOT_SMALL');model.add(x!=bv(value))
    need(model.check()==z3.unsat,'ALLOW_ENUMERATION_UNKNOWN');allowed.sort();old=json.loads(OLD.read_text());expected=set(old['logins']);actual=set(allowed)
    report={'private':True,'verification':'proved_raw_login_set',
      'function_sha256':hashlib.sha256(function).hexdigest(),'tree_sha256':hashlib.sha256(raw).hexdigest(),'range_rva':[hex(LO),hex(HI)],
      'solver_version':z3.get_version_string(),'entire_uint64_domain_covered':True,'only_login_affects_result':True,
      'allow_count':len(allowed),'allow_uint64le_sha256':hashlib.sha256(b''.join(struct.pack('<Q',v) for v in allowed)).hexdigest(),
      'reference_count':len(expected),'missing_count':len(expected-actual),'extra_count':len(actual-expected),
      'instructions_visited':len(visited),'conditional_branches_visited':len(branches),'terminal_paths':len(terminals),'table_dispatches':tables,'steps':steps,'solver_checks':checks}
    tool=ROOT/'khoi-phuc/cong-cu/trich-dieu-kien-tai-khoan-bot-1.py'
    spec=importlib.util.spec_from_file_location('native_login_validation',tool);native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
    need(native.digest(native.EX5)==native.EXPECTED['ex5'],'ORIGINAL_EX5_CHANGED')
    runner=native.load_runner();accepts=native.login_runner(runner);tests=set(allowed);rng=random.Random(20261028)
    for value in allowed:tests.update([(value-1)&MASK,(value+1)&MASK])
    tests.update([0,MASK,(1<<63)-1,1<<63])
    for low,high in zip([0]+allowed,allowed+[MASK]):
        if high-low>1:tests.add((low+high)//2);tests.add(rng.randrange(low+1,high))
    mismatch=sum(accepts(value)!=(value in actual) for value in tests)
    need(mismatch==0,'NATIVE_RESULT_DIFFERS')
    report.update(native_cases=len(tests),native_allowed_cases=len(allowed),native_denied_cases=len(tests)-len(allowed),native_mismatches=mismatch,
      initial_low_byte_rsi=1,upper_initial_rsi_unconstrained=True,original_ex5_sha256=native.digest(native.EX5),
      tool_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),native_helper_sha256=hashlib.sha256(tool.read_bytes()).hexdigest())
    OUT.mkdir();(OUT/'coverage.private.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8');(OUT/'accepted.private.json').write_text(json.dumps(allowed)+'\n',encoding='utf-8')
    print(json.dumps(report),flush=True)
if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('run');args=parser.parse_args()
    need(re.fullmatch('[a-z0-9-]{1,64}',args.run) is not None,'BAD_RUN')
    OUT=ROOT/'.local'/args.run
    main()
