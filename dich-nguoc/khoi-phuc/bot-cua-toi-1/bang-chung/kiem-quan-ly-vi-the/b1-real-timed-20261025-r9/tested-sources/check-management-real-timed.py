"""Compare Bot1 timed real-stop slices with the captured native image.

Usage: check-management-real-timed.py prepare|original|mql5|compare RUN [--build BUILD]
The error-report callback is intercepted; this is not a full manager/EA run.
"""
import argparse, importlib.util, json, re, shutil, struct, subprocess
from pathlib import Path

HOME = Path(__file__).resolve().parents[1]
ROOT = HOME.parent

def module(name, path):
    spec = importlib.util.spec_from_file_location(name, path)
    obj = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(obj)
    return obj

PRE_PATH = HOME/'tests/check-management-prelude.py'
CASE_PATH = ROOT/'bot-cua-toi-3/tests/real_timed_cases.py'
CPU_PATH = ROOT/'cong-cu/doi-chieu-nan-quan-ly.py'
pre = module('bot1_timed_prelude', PRE_PATH)
vstart = module('bot1_timed_virtual_start', HOME/'tests/check-management-virtual-start.py')
inputs = module('bot1_timed_cases', CASE_PATH)
cpu = module('bot1_timed_cpu', CPU_PATH)
sha, require, save = pre.sha, pre.require, pre.save
MT = (ROOT.parent/'.local/mt5-bot1-thread-20261025').resolve()
MASK = (1<<64)-1
MAGIC = 0x4d525431
RESULT = struct.Struct('<3iI10QiQ')
ANALYSIS = HOME/'phan-tich/dong-vi-the/management-20261025-r1'
CONTRACT = HOME/'phan-tich/dong-vi-the/management-real-timed-20261025-r1/port-receipt.json'
NAMES = ['Include/bot-cua-toi-1/'+n for n in [
    'Bot1ManagementPrelude.mqh', 'Bot1PriceLevels.mqh', 'Bot1PositionModify.mqh',
    'Bot1PositionClose.mqh', 'Bot1VirtualStops.mqh', 'Bot1TradeErrors.mqh',
    'Bot1ManagementRealTimed.mqh', 'Bot1ManagementMessages.mqh']]
NAMES += ['Scripts/bot-cua-toi-1/Bot1ManagementRealTimedCheck.mq5']
SUFFIX = "' when setting trailing Exit_TrailSL_after_X_Minutes_size_ loss.  Trying again!"
FIELDS = ['id','requested','delay','error_count','sl','tp','bid','ask','unit','activation','distance','gap','freeze','point','calls','ordered_hash']
SCOPE = dict(calculation_slice_only=True, whole_manager_complete=False, whole_bot_complete=False,
             original_bytes_changed=False, modify_child_intercepted=True,
             error_reporting_block_intercepted=True)
LIMITS = ['Chỉ kiểm lát cắt dừng lỗ thật theo thời gian; chưa phải toàn bộ bộ quản lý hoặc EA.',
          'Nút sửa vị thế và khối báo lỗi được trả lời tại điểm gọi; actualReporter không chạy.',
          'Phép tính NaN dùng bộ đo SSE2 BothNaN và bộ dữ liệu vật lý; các lệnh khác chạy trong Unicorn.']

def identity():
    return dict(original_ex5_sha256=pre.validation.original_hash(1), tool_sha256=sha(Path(__file__)),
        analysis_sha256=sha(ANALYSIS/'analysis.json'), contract_sha256=sha(CONTRACT), probe_sha256=sha(cpu.PROBE),
        helpers_sha256={str(p.relative_to(ROOT)): sha(p) for p in [PRE_PATH, CASE_PATH, CPU_PATH,
            HOME/'tests/check-management-virtual-start.py']},
        sources_sha256={n: sha(HOME/'source/MQL5'/n) for n in NAMES})

def encode(rows):
    return struct.pack('<3i', MAGIC, 1, len(rows)) + inputs.encode(rows)[12:]

class Original(vstart.Original):
    def __init__(self, fixture):
        super().__init__()
        require(self.base == 0x23e5aa10000, 'B1_BASE_DIFFERS')
        self.m.hook_add(self.uc.UC_HOOK_CODE, self.visit, begin=self.base+0x27ee4, end=self.base+0x2bc82)
        for rva in [0x2812e, 0x2bb75]:
            self.apis[self.base+rva] = 10
            self.m.hook_add(self.uc.UC_HOOK_CODE, self.report, begin=self.base+rva, end=self.base+rva)
        self.apis[self.base+0x26d20] = 5
        # vstart.Original already installs this child hook. Installing it twice pops two returns.
        self.nan = cpu.BothNaN(self, json.loads((ANALYSIS/'analysis.json').read_text()), fixture)

    def visit(self, m, address, size, user):
        off = address-self.base
        self.covered.add(off)
        if off in [0x28220, 0x2b938, 0x2bc82]:
            self.stopped = True
            m.emu_stop()

    def changed(self, api):
        target = {9: 1, 4: 3, 5: 5}.get(api)
        if api == 3:
            target = 2 if self.digit_count == 1 else 4
        if target != self.case['scenario']:
            return
        for rva, delta in [(0x62500,.5), (0x66a70,.125), (0x67758,.25), (0x67760,.5), (0x67468,.25)]:
            p = self.base+rva
            value = struct.unpack('<d', self.m.mem_read(p, 8))[0]
            self.m.mem_write(p, struct.pack('<d', value+delta))
        p = self.base+0x66d98
        value = struct.unpack('<d', self.m.mem_read(p, 8))[0]
        self.m.mem_write(p, struct.pack('<d', value*2.))
        p = self.base+0x6745c
        value = struct.unpack('<I', self.m.mem_read(p, 4))[0]
        self.m.mem_write(p, struct.pack('<I', (value+1)&0xffffffff))

    def child(self, m, address, size, user):
        x = self.x; api = self.apis[address]; sp = m.reg_read(x.UC_X86_REG_RSP)
        ticket = m.reg_read(x.UC_X86_REG_RCX)
        if api != 5:
            raise ValueError('UNEXPECTED_CHILD')
        self.event(api, ticket, m.reg_read(x.UC_X86_REG_XMM1)&MASK, m.reg_read(x.UC_X86_REG_XMM2)&MASK, self.case['modify_ok'])
        self.changed(api)
        ret = struct.unpack('<Q', m.mem_read(sp, 8))[0]
        m.reg_write(x.UC_X86_REG_RSP, sp+8); m.reg_write(x.UC_X86_REG_RIP, ret)
        m.reg_write(x.UC_X86_REG_RAX, self.case['modify_ok'])

    def report(self, m, address, size, user):
        self.event(10, self.case['error_code'], self.error_count, pre.entry.text_hash(SUFFIX))
        self.error_count = (self.error_count+1)&0xffffffff
        x = self.x
        m.reg_write(x.UC_X86_REG_R15, self.base+(0x67758 if self.case['buy'] else 0x67760))
        m.reg_write(x.UC_X86_REG_RIP, self.base+(0x28220 if self.case['buy'] else 0x2bc82))

    def call(self, m, address, size, user):
        x = self.x; api = self.apis[address]; c = self.case
        if api == 3:
            require(m.reg_read(x.UC_X86_REG_R8) == 17 and self.digit_count < 2, 'BAD_DIGITS')
            value = c['digits'+str(self.digit_count)]; self.digit_count += 1
            self.event(api, 17, value, self.digit_count-1); m.reg_write(x.UC_X86_REG_RAX, value&MASK)
        elif api == 4:
            require(m.reg_read(x.UC_X86_REG_R8) == 16, 'BAD_POINT_PROPERTY')
            value = c['point']; self.event(api, 16, pre.bits(value))
            m.mem_write(self.base+0x6a448, struct.pack('<d', value)); m.reg_write(x.UC_X86_REG_XMM0, pre.bits(value))
        elif api == 9:
            require(m.reg_read(x.UC_X86_REG_RDX) == 0, 'BAD_TIME_OVERLOAD')
            self.event(api, c['now']); m.reg_write(x.UC_X86_REG_RAX, c['now']&MASK)
        elif api == 10:
            self.event(api, c['error_code'], self.error_count, pre.entry.text_hash(SUFFIX))
        else:
            return super().call(m, address, size, user)
        self.changed(api)

    def run(self, c):
        m, x = self.m, self.x; self.case = c; self.events = []; self.stopped = False; self.cursor = 0x70001000
        self.digit_count = 0; self.error_count = c['error_count']
        for region, raw in self.regions:
            if region.get('kind') == 'mutable_program_data': m.mem_write(region['base'], raw)
        for n in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:
            m.reg_write(getattr(x, 'UC_X86_REG_'+n), 0)
        for n in range(16): m.reg_write(getattr(x, 'UC_X86_REG_XMM'+str(n)), 0)
        m.reg_write(x.UC_X86_REG_EFLAGS, 0x202); m.reg_write(x.UC_X86_REG_MXCSR, 0x1f80); m.mem_write(0x50000000, b'\0'*0x20000)
        for rva, key in [(0x66d98,'unit'),(0x624f8,'activation'),(0x62500,'distance'),(0x66a70,'gap'),(0x67468,'freeze')]:
            m.mem_write(self.base+rva, struct.pack('<d', c[key]))
        m.mem_write(self.base+0x6745c, struct.pack('<i', c['delay_seconds']))
        m.mem_write(self.base+0x67758, struct.pack('<2d', c['bid'], c['ask']))
        m.mem_write(self.base+0x67918, struct.pack('<IQ', 0, self.string('CHECK')))
        m.reg_write(x.UC_X86_REG_RDI, self.base+0x67918); m.reg_write(x.UC_X86_REG_R13, self.base+0x6a448)
        m.reg_write(x.UC_X86_REG_R15, self.base+(0x67758 if c['buy'] else 0x67760)); m.reg_write(x.UC_X86_REG_RBP, c['ticket']&MASK)
        for reg, key in [(7,'tp'), (8,'sl')]: m.reg_write(getattr(x, 'UC_X86_REG_XMM'+str(reg)), pre.bits(c[key]))
        sp = 0x50020000-0x208; m.reg_write(x.UC_X86_REG_RSP, sp); m.mem_write(sp, struct.pack('<Q', 0x60000000))
        m.mem_write(sp+(0x70 if c['buy'] else 0x80), struct.pack('<q', c['opened']))
        if c['buy']: m.mem_write(sp+0x30, struct.pack('<q', c['ticket']))
        start = 0x27ee4 if c['buy'] else 0x2b8ed
        try:
            m.emu_start(self.base+start, 0x60000000, timeout=5000000, count=100000)
        except Exception as exc:
            raise RuntimeError('case=%d buy=%d rva=%#x %s' % (c['id'], c['buy'], m.reg_read(x.UC_X86_REG_RIP)-self.base, exc)) from exc
        require(self.stopped, 'BOUNDARY_MISSING case=%d buy=%d rva=%#x' % (c['id'], c['buy'], m.reg_read(x.UC_X86_REG_RIP)-self.base))
        requested = (struct.unpack('<Q', m.mem_read(sp+0x50, 8))[0] if c['buy'] else struct.unpack('<Q', m.mem_read(sp+0x58, 8))[0])&255
        h = 0xcbf29ce484222325
        for event in self.events:
            for b in struct.pack('<5Q', *event): h = ((h^b)*0x100000001b3)&MASK
        read = lambda rva: struct.unpack('<Q', m.mem_read(self.base+rva, 8))[0]
        return RESULT.pack(c['id'], int(requested != 0), struct.unpack('<i', m.mem_read(self.base+0x6745c, 4))[0], self.error_count,
            m.reg_read(x.UC_X86_REG_XMM8)&MASK, pre.bits(c['tp']), read(0x67758), read(0x67760), read(0x66d98), read(0x624f8),
            read(0x62500), read(0x66a70), read(0x67468), pre.bits(c['point']), len(self.events), h)

def main():
    p = argparse.ArgumentParser(); p.add_argument('mode', choices=['prepare','original','mql5','compare']); p.add_argument('run'); p.add_argument('--build'); a = p.parse_args()
    require(re.fullmatch('[a-z0-9-]{1,50}', a.run), 'BAD_RUN')
    folder = HOME/'bang-chung/kiem-quan-ly-vi-the'/a.run; rows = inputs.cases(); current = identity()
    if a.mode == 'prepare':
        folder.mkdir(parents=True, exist_ok=False); (folder/'cases.bin').write_bytes(encode(rows)); tested = folder/'tested-sources'; tested.mkdir()
        for n in NAMES: shutil.copyfile(HOME/'source/MQL5'/n, tested/Path(n).name)
        for path in [Path(__file__), CASE_PATH]: shutil.copyfile(path, tested/path.name)
        save(folder/'baseline.json', dict(**current, cases=len(rows), inputs_sha256=sha(folder/'cases.bin'), **SCOPE)); print(json.dumps({'cases':len(rows)})); return
    b = json.loads((folder/'baseline.json').read_text()); require(all(b[k] == v for k,v in current.items()), 'IDENTITY_DIFFERS'); require((folder/'cases.bin').read_bytes() == encode(rows), 'INPUTS_DIFFERS')
    if a.mode == 'original':
        require(not (folder/'original-results.bin').exists(), 'RESULT_EXISTS'); f = cpu.CpuFixture()
        try:
            cpu.verify_probe(f, current['probe_sha256']); r = Original(f); raw = bytearray(struct.pack('<3i', MAGIC, 1, len(rows)))
            traces = []
            for c in rows:
                raw += r.run(c); traces.append(dict(id=c['id'], events=r.events))
            (folder/'original-results.bin').write_bytes(raw); save(folder/'original-traces.json', traces)
            save(folder/'original-run.json', dict(**current, cases=len(rows), result_sha256=sha(folder/'original-results.bin'), executed_instructions=sorted(hex(n) for n in r.covered), nan_fixture=r.nan.report(), **SCOPE)); print(json.dumps({'cases':len(rows), 'instructions':len(r.covered)}))
        finally: f.close()
        return
    if a.mode == 'mql5':
        require(a.build and re.fullmatch('[a-z0-9-]{1,50}', a.build), 'BUILD_REQUIRED'); receipt = HOME/'bang-chung/bien-dich'/a.build/'bien-nhan.json'; build = json.loads(receipt.read_text(encoding='utf-8-sig'))
        require(build['target'] == NAMES[-1] and build['errors'] == build['warnings'] == 0, 'BUILD_NOT_CLEAN')
        for n,v in current['sources_sha256'].items(): require(build['sources_sha256'][n] == v == sha(MT/'MQL5'/n), 'SOURCE_DIFFERS')
        binary = MT/'MQL5'/Path(NAMES[-1]).with_suffix('.ex5'); require(sha(binary) == build['binary_sha256'], 'BINARY_DIFFERS')
        files = MT/'MQL5/Files/bot1-management-real-timed'/a.run; files.mkdir(parents=True, exist_ok=False); shutil.copyfile(folder/'cases.bin', files/'cases.bin')
        preset = MT/'MQL5/Presets'/f'b1-real-time-{a.run}.set'; ini = MT/f'b1-real-time-{a.run}.ini'
        with preset.open('x', encoding='utf-16') as f: f.write(f'CheckRun={a.run}\n')
        with ini.open('x', encoding='utf-16') as f: f.write(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-1\\Bot1ManagementRealTimedCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
        proc = subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"', cwd=MT, creationflags=subprocess.CREATE_NO_WINDOW); code = proc.wait(timeout=120)
        require(code == 0 and (files/'script-status.bin').read_bytes() == struct.pack('<2i', 0, len(rows)), 'MT5_FAILED')
        for n in ['mql5-results.bin','script-status.bin']:
            with (folder/n).open('xb') as out: out.write((files/n).read_bytes())
        save(folder/'mql5-run.json', dict(**current, cases=len(rows), result_sha256=sha(folder/'mql5-results.bin'), build_receipt_sha256=sha(receipt), **SCOPE)); print(json.dumps({'cases':len(rows), 'exit_code':code})); return
    for n in ['original-run.json','mql5-run.json']:
        record = json.loads((folder/n).read_text()); require(all(record[k] == v for k,v in current.items()), 'RUN_IDENTITY_DIFFERS')
    native, actual = (folder/'original-results.bin').read_bytes(), (folder/'mql5-results.bin').read_bytes(); require(native[:12] == actual[:12] == struct.pack('<3i', MAGIC, 1, len(rows)) and len(native) == len(actual) == 12+RESULT.size*len(rows), 'BAD_RESULTS')
    failed = []
    for c in rows:
        a0 = RESULT.unpack_from(native, 12+c['id']*RESULT.size); b0 = RESULT.unpack_from(actual, 12+c['id']*RESULT.size)
        if a0 != b0: failed.append(dict(id=c['id'], group=c['group'], differences={k:[x,y] for k,x,y in zip(FIELDS,a0,b0) if x != y}))
    report = dict(cases=len(rows), matched=len(rows)-len(failed), failed=len(failed), first_failures=failed[:15], **SCOPE, limits=LIMITS, hashes={'cases':sha(folder/'cases.bin'), 'original':sha(folder/'original-results.bin'), 'mql5':sha(folder/'mql5-results.bin')})
    save(folder/'comparison.json', report); print(json.dumps(report)); raise SystemExit(bool(failed))

if __name__ == '__main__': main()
