"""Compare the strategy-hour gate with the captured dispatcher instructions.

generate BOT; prepare|mql5 --build BUILD|original|compare BOT RUN.
The time replies and optional mutations during the calls are supplied.
"""
import argparse
import hashlib
import importlib.util
import json
import re
import shutil
import struct
import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
MASK = (1 << 64) - 1
MAGIC = 0x48524731
spec = importlib.util.spec_from_file_location('hour_parent', ROOT / 'cong-cu/kiem-cong-dieu-phoi-bot-1-3.py')
parent = importlib.util.module_from_spec(spec)
spec.loader.exec_module(parent)
require, sha, save, pub = parent.require, parent.sha, parent.save, parent.pub
CFG = {
    1: dict(start=0x11ed7, end=0x11f3f, hour=0x69f78, symbol=0x67918,
            sha='769021e18d144e134564d119355735105b4605f47be1dc167aa391621b334c12'),
    3: dict(start=0x194ef, end=0x19550, hour=0x76fb0, symbol=0x74958,
            sha='dd507ef56be70455ee837b6b2b91881095b7fdddbb79b9505a132d69b5d0263a'),
}
SYMBOLS = ['XAUUSD', 'Vàng.α', '', 'GOLD.a']
SCOPE = dict(full_ea=False, entire_dispatcher_executed=False, native_hour_gate_executed=True,
             time_replies_supplied=True, service_mutations_supplied=True, original_ex5_changed=False)


def cases():
    result = []
    def add(previous, first, second, effect_call=0, effect_field=0, effect_value=0,
            symbol=0, replacement=1):
        result.append((len(result), previous, first, second, effect_call, effect_field,
                       effect_value, symbol, replacement))
    values = [-(1 << 63), -1, 0, 1, 100, (1 << 63) - 1]
    for previous in values:
        for first in values:
            for second in [-(1 << 63), 0, (1 << 63) - 1]:
                for symbol in range(len(SYMBOLS)):
                    add(previous, first, second, symbol=symbol)
    for previous, first in [(0, 0), (0, 1), (100, 100), (100, -1)]:
        for effect_call in [1, 2]:
            for value in values:
                add(previous, first, 77, effect_call, 1, value)
            for replacement in range(len(SYMBOLS)):
                add(previous, first, 77, effect_call, 2, 0, 0, replacement)
    return result


def encoded(rows):
    return struct.pack('<3i', MAGIC, 1, len(rows)) + b''.join(struct.pack('<9q', *row) for row in rows)


SCRIPT = r'''#property strict
datetime MockHour(const string symbol,const ENUM_TIMEFRAMES frame,const int shift);
#define iTime MockHour
#include "../../Include/bot-cua-toi-N/BotNStrategyHour.mqh"
#undef iTime
input string CheckRun="";
string GateSymbol;long Hour,Replies[2],EffectValue,Trace[10];
int Calls,EffectCall,EffectField,Replacement;
string SymbolName(const int id)
{
   if(id==0)return "XAUUSD";
   if(id==1)return "Vàng.α";
   if(id==2)return "";
   return "GOLD.a";
}
ulong TextHash(const string value)
{
   ulong hash=(ulong)0xcbf29ce484222325;
   for(int i=0;i<StringLen(value);i++)
   {
      ushort c=StringGetCharacter(value,i);
      hash^=(ulong)(c&255);hash*=(ulong)0x100000001b3;
      hash^=(ulong)(c>>8);hash*=(ulong)0x100000001b3;
   }
   return hash;
}
datetime MockHour(const string symbol,const ENUM_TIMEFRAMES frame,const int shift)
{
   if(Calls>=2)return 0;
   const int at=5*Calls;const long reply=Replies[Calls];Calls++;
   Trace[at]=(long)frame;Trace[at+1]=(long)shift;Trace[at+2]=(long)TextHash(symbol);
   Trace[at+3]=Hour;Trace[at+4]=reply;
   if(EffectCall==Calls)
   {
      if(EffectField==1)Hour=EffectValue;
      if(EffectField==2)GateSymbol=SymbolName(Replacement);
   }
   return (datetime)reply;
}
int OnStart()
{
   if(CheckRun=="")return 1;
   string folder="botN-strategy-hour\\"+CheckRun+"\\";
   int file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(file==INVALID_HANDLE)return 2;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);
   if(magic!=0x48524731 || version!=1 || count<1)return 3;
   int out=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(out==INVALID_HANDLE)return 4;
   FileWriteInteger(out,magic);FileWriteInteger(out,version);FileWriteInteger(out,count);
   for(int i=0;i<count;i++)
   {
      long id=FileReadLong(file);Hour=FileReadLong(file);Replies[0]=FileReadLong(file);Replies[1]=FileReadLong(file);
      EffectCall=(int)FileReadLong(file);EffectField=(int)FileReadLong(file);EffectValue=FileReadLong(file);
      GateSymbol=SymbolName((int)FileReadLong(file));Replacement=(int)FileReadLong(file);
      Calls=0;ArrayInitialize(Trace,0);
      bool changed=BotNStrategyHourChanged(GateSymbol,Hour);
      FileWriteLong(out,id);FileWriteLong(out,(long)changed);FileWriteLong(out,Hour);
      FileWriteLong(out,Calls);FileWriteLong(out,(long)TextHash(GateSymbol));
      for(int j=0;j<10;j++)FileWriteLong(out,Trace[j]);
   }
   if(FileTell(file)!=FileSize(file))return 5;
   FileClose(file);FileClose(out);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 6;
   FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
'''


def generate(bot):
    path = ROOT / f'bot-cua-toi-{bot}/source/MQL5/Scripts/bot-cua-toi-{bot}/Bot{bot}StrategyHourCheck.mq5'
    require(not path.exists(), 'SOURCE_EXISTS')
    code = SCRIPT.replace('BotN', f'Bot{bot}').replace('botN', f'bot{bot}').replace('bot-cua-toi-N', f'bot-cua-toi-{bot}')
    path.write_text(code, encoding='utf-8', newline='\n')
    print(path)


def text_hash(value):
    result = 0xcbf29ce484222325
    for byte in value.encode('utf-16-le'):
        result = ((result ^ byte) * 0x100000001b3) & MASK
    return result


class Native(parent.Original):
    def __init__(self, bot):
        super().__init__(bot)
        self.bot, self.c = bot, CFG[bot]
        body = bytes(self.m.mem_read(self.base + self.c['start'], self.c['end'] - self.c['start']))
        require(hashlib.sha256(body).hexdigest() == self.c['sha'], 'NATIVE_SECTION_CHANGED')

    def set_symbol(self, value):
        self.m.mem_write(self.base + self.c['symbol'], struct.pack('<IQ', 0, self.string(value)))

    def read_symbol(self, descriptor):
        pointer = struct.unpack('<Q', self.m.mem_read(descriptor + 4, 8))[0]
        require(pointer != 0, 'NULL_SYMBOL')
        length = struct.unpack('<I', self.m.mem_read(pointer - 4, 4))[0]
        require(length < 1024, 'SYMBOL_TOO_LONG')
        return bytes(self.m.mem_read(pointer, 2 * length)).decode('utf-16-le')

    def call(self, m, address, size, user):
        require(address == 0x7ff683f20000 + 0x7d3b50, 'UNEXPECTED_CALL')
        x = self.x
        require(self.calls < 2, 'TOO_MANY_CALLS')
        require(m.reg_read(x.UC_X86_REG_RCX) == self.gate['ctx'], 'BAD_CONTEXT')
        require(m.reg_read(x.UC_X86_REG_RDX) == self.base + self.c['symbol'], 'BAD_SYMBOL_POINTER')
        frame, shift = m.reg_read(x.UC_X86_REG_R8), m.reg_read(x.UC_X86_REG_R9)
        hour = struct.unpack('<Q', m.mem_read(self.base + self.c['hour'], 8))[0]
        reply = self.row[2 + self.calls] & MASK
        self.trace.extend([frame, shift, text_hash(self.read_symbol(self.base + self.c['symbol'])), hour, reply])
        self.calls += 1
        if self.row[4] == self.calls:
            if self.row[5] == 1:
                m.mem_write(self.base + self.c['hour'], struct.pack('<Q', self.row[6] & MASK))
            if self.row[5] == 2:
                self.set_symbol(SYMBOLS[self.row[8]])
        m.reg_write(x.UC_X86_REG_RAX, reply)

    def run(self, row):
        self.row, self.calls, self.trace, self.cursor = row, 0, [], 0x70001000
        m, x = self.m, self.x
        for region, raw in self.regions:
            if region.get('kind') == 'mutable_program_data':
                m.mem_write(region['base'], raw)
        m.mem_write(self.base + self.c['hour'], struct.pack('<Q', row[1] & MASK))
        self.set_symbol(SYMBOLS[row[7]])
        for name in ['RAX', 'RBX', 'RCX', 'RDX', 'RSI', 'RDI', 'RBP', 'R8', 'R9', 'R10', 'R11', 'R12', 'R13', 'R14', 'R15']:
            m.reg_write(getattr(x, 'UC_X86_REG_' + name), 0)
        sp = 0x5001fe00
        m.mem_write(sp, bytes(0x100))
        m.reg_write(x.UC_X86_REG_RSP, sp)
        m.reg_write(x.UC_X86_REG_EFLAGS, 0x202)
        if self.bot == 3:
            m.reg_write(x.UC_X86_REG_RBX, 0x7ff683f20000 + 0x7d3b50)
        m.emu_start(self.base + self.c['start'], self.base + self.c['end'], timeout=1000000, count=10000)
        require(m.reg_read(x.UC_X86_REG_RIP) == self.base + self.c['end'], 'NATIVE_GATE_DID_NOT_FINISH')
        previous = m.reg_read(x.UC_X86_REG_RDI) if self.bot == 1 else struct.unpack('<Q', m.mem_read(sp + 0x50, 8))[0]
        first = m.reg_read(x.UC_X86_REG_RSI)
        hour = struct.unpack('<Q', m.mem_read(self.base + self.c['hour'], 8))[0]
        return [row[0], int(previous != first), hour, self.calls, text_hash(self.read_symbol(self.base + self.c['symbol']))] + self.trace + [0] * (10 - len(self.trace))


def identity(bot):
    source = ROOT / f'bot-cua-toi-{bot}/source/MQL5'
    script = source / f'Scripts/bot-cua-toi-{bot}/Bot{bot}StrategyHourCheck.mq5'
    helpers = [Path(__file__), Path(parent.__file__), ROOT / 'cong-cu/kiem-nfp-toan-nhanh-bot-1-3.py',
               ROOT / 'cong-cu/kiem-gia-vao-bot-1-3.py', ROOT / 'cong-cu/kiem-muc-gia-bot-1-3.py']
    return dict(original_ex5_sha256=parent.base.validation.original_hash(bot), native_section_sha256=CFG[bot]['sha'],
                sources_sha256={p.relative_to(source).as_posix(): sha(p) for p in pub.closure(script, source)},
                helpers_sha256={p.relative_to(ROOT).as_posix(): sha(p) for p in helpers})


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('mode', choices=['generate', 'prepare', 'mql5', 'original', 'compare'])
    parser.add_argument('bot', type=int, choices=[1, 3])
    parser.add_argument('run', nargs='?')
    parser.add_argument('--build')
    args = parser.parse_args()
    if args.mode == 'generate':
        generate(args.bot)
        return
    require(args.run and re.fullmatch('[a-z0-9-]{1,48}', args.run), 'BAD_RUN')
    rows, current = cases(), identity(args.bot)
    home = ROOT / f'bot-cua-toi-{args.bot}'
    folder = home / 'bang-chung/kiem-quan-ly-vi-the' / args.run
    header = struct.pack('<3i', MAGIC, 1, len(rows))
    if args.mode == 'prepare':
        folder.mkdir(parents=True, exist_ok=False)
        (folder / 'cases.bin').write_bytes(encoded(rows))
        save(folder / 'cases.json', rows)
        save(folder / 'baseline.json', dict(**current, cases=len(rows), inputs_sha256=sha(folder / 'cases.bin'), **SCOPE))
        print(json.dumps(dict(cases=len(rows))))
        return
    baseline = json.loads((folder / 'baseline.json').read_text())
    require(all(baseline[k] == v for k, v in current.items()) and (folder / 'cases.bin').read_bytes() == encoded(rows), 'IDENTITY_CHANGED')
    if args.mode == 'mql5':
        require(args.build and re.fullmatch('[a-z0-9-]{1,48}', args.build), 'BUILD_REQUIRED')
        mt = ROOT.parent / f'.local/mt5-bot{args.bot}-thread-20261025'
        receipt = home / 'bang-chung/bien-dich' / args.build / 'bien-nhan.json'
        build = json.loads(receipt.read_text(encoding='utf-8-sig'))
        script = f'Scripts/bot-cua-toi-{args.bot}/Bot{args.bot}StrategyHourCheck.mq5'
        require(build['target'] == script and build['errors'] == build['warnings'] == 0, 'BUILD_NOT_CLEAN')
        for name, digest in current['sources_sha256'].items():
            require(sha(mt / 'MQL5' / name) == build['sources_sha256'][name] == digest, 'BUILD_SOURCE_CHANGED')
        binary = mt / 'MQL5' / Path(script).with_suffix('.ex5')
        require(sha(binary) == build['binary_sha256'] == sha(receipt.parent / binary.name), 'BUILD_BINARY_CHANGED')
        files = mt / f'MQL5/Files/bot{args.bot}-strategy-hour' / args.run
        files.mkdir(parents=True, exist_ok=False)
        shutil.copyfile(folder / 'cases.bin', files / 'cases.bin')
        preset, ini = mt / 'MQL5/Presets' / ('strategy-hour-' + args.run + '.set'), mt / ('strategy-hour-' + args.run + '.ini')
        preset.write_text('CheckRun=' + args.run + '\n', encoding='utf-16')
        ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{args.bot}\\Bot{args.bot}StrategyHourCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n', encoding='utf-16')
        proc = subprocess.Popen(f'"{mt / "terminal64.exe"}" /portable /config:"{ini}"', cwd=mt, creationflags=subprocess.CREATE_NO_WINDOW)
        try:
            code = proc.wait(timeout=120)
        except subprocess.TimeoutExpired:
            proc.terminate()
            proc.wait(timeout=30)
            raise RuntimeError('MT5_TIMEOUT')
        require(code == 0 and (files / 'script-status.bin').read_bytes() == struct.pack('<2i', 0, len(rows)), 'MT5_FAILED')
        for name in ['mql5-results.bin', 'script-status.bin']:
            with (folder / name).open('xb') as out:
                out.write((files / name).read_bytes())
        save(folder / 'mql5-run.json', dict(**current, cases=len(rows), result_sha256=sha(folder / 'mql5-results.bin'), build=args.build, build_receipt_sha256=sha(receipt), **SCOPE))
        print(json.dumps(dict(cases=len(rows))))
        return
    if args.mode == 'original':
        native = Native(args.bot)
        result = bytearray(header)
        calls = 0
        for row in rows:
            values = native.run(row)
            result += struct.pack('<15Q', *(v & MASK for v in values))
            calls += native.calls
        with (folder / 'original-results.bin').open('xb') as out:
            out.write(result)
        save(folder / 'original-run.json', dict(**current, cases=len(rows), calls=calls, result_sha256=sha(folder / 'original-results.bin'), **SCOPE))
        print(json.dumps(dict(cases=len(rows), calls=calls)))
        return
    for name in ['original', 'mql5']:
        report = json.loads((folder / (name + '-run.json')).read_text())
        require(all(report[k] == v for k, v in current.items()) and report['result_sha256'] == sha(folder / (name + '-results.bin')), 'RUN_CHANGED')
    original, actual = [(folder / (name + '-results.bin')).read_bytes() for name in ['original', 'mql5']]
    require(original[:12] == actual[:12] == header and len(original) == len(actual) == 12 + 120 * len(rows), 'RESULT_LAYOUT')
    failed = []
    for i, row in enumerate(rows):
        x, y = struct.unpack_from('<15Q', original, 12 + i * 120), struct.unpack_from('<15Q', actual, 12 + i * 120)
        if x != y:
            failed.append(dict(case=i, input=row, original=x, actual=y))
    report = dict(cases=len(rows), matched=len(rows)-len(failed), failed=len(failed), first_failures=failed[:8], **SCOPE,
                  limits=['Only the hourly decision before strategy processing. Terminal replies and mutations are supplied; no full dispatcher or EA.'])
    save(folder / 'comparison.json', report)
    print(json.dumps(report, ensure_ascii=False))
    raise SystemExit(bool(failed))


if __name__ == '__main__':
    main()
