"""Check the two original strategy selectors; this does not rebuild an EA.

Usage: python -I -B -X utf8 phan-tich-chon-chien-luoc-bot-3.py NEW_RUN
Account reading and currency conversion are explicit supplied boundaries. Only
the native selection segments run; no original EX5 file or live process changes.
"""
import argparse
import importlib.util
import itertools
import json
import math
from pathlib import Path
import re
import struct
import time

ROOT = Path(__file__).resolve().parents[1]
spec = importlib.util.spec_from_file_location('price', Path(__file__).with_name('kiem-muc-gia-bot-1-3.py'))
price = importlib.util.module_from_spec(spec)
spec.loader.exec_module(price)
PATHS = {
    'initialization': {'start': 0x3892, 'end': 0x3ce6, 'preloads': [0x3861], 'table': 0x57cc0},
    'controller': {'start': 0x18c50, 'end': 0x19084, 'preloads': [0x189e8, 0x189f2], 'table': 0x57ed0},
}
INPUTS = {'frequency': 0x1d6f90, 'risk': 0x1d7130, 'max_dd': 0x1d7140,
          'variable': 0x1d6f28, 'manual': 0x1d71a8}
OUTPUTS = {'mode': 0x6d21c, 'enabled': 0x6d220, 'divisor': 0x76fa8}
MENU_TO_INTERNAL = [0, 1, 2, 3, 5, 4, 7, 8, 6]
DIVISORS = [(3.0, 2.4), (4.0, 3.4), (5.0, 4.1), (5.6, 4.8), (6.0, 5.1)]


def bits(value):
    return struct.pack('<d', value).hex()


def reference(case):
    enabled = [(case['initial'] >> i) & 1 for i in range(9)]
    mode = case['frequency']
    if mode == 5 and case['risk'] == 1234:
        budget = (case['max_dd'] / 100.0) * case['converted_balance']
        mode = next((m for m, threshold in [(3, 810.0), (2, 560.0), (1, 330.0)]
                     if budget > (threshold if case['threshold_flags'] & (1 << (m - 1)) else 0.0)), 0)
    divisor = case['initial_divisor']
    if 0 <= mode <= 4:
        for i in range(3, 9):
            enabled[i] = int(i in [[3, 5], [3, 4, 5, 7], [3, 4, 5, 7, 8],
                                  [3, 4, 5, 6, 7, 8]][mode - 1]) if mode else 0
        divisor = DIVISORS[mode][int(not case['variable'])]
    elif mode == 6:
        for menu, internal in enumerate(MENU_TO_INTERNAL):
            enabled[internal] = (case['manual'] >> menu) & 1
    return {'mode': mode, 'enabled': enabled, 'divisor_bits': bits(divisor)}


def cases():
    common = {'risk': 0, 'max_dd': 100.0, 'converted_balance': 1000.0,
              'threshold_flags': 7, 'manual': 0, 'initial_divisor': 7.125}
    for mode, variable, initial, risk in itertools.product([-1, 0, 1, 2, 3, 4, 5, 7], [0, 1], [0, 511, 341, 170], [0, 3, 1234, 9999]):
        # The automatic branch has a separate exhaustive threshold matrix below.
        if mode == 5 and risk == 1234:
            continue
        yield {**common, 'group': 'fixed-or-unhandled', 'frequency': mode,
               'variable': variable, 'initial': initial, 'risk': risk}
    for manual, variable, initial in itertools.product(range(512), [0, 1], [0, 511, 341]):
        yield {**common, 'group': 'all-manual-combinations', 'frequency': 6,
               'variable': variable, 'initial': initial, 'manual': manual}
    balances = [-100.0, -0.0, 0.0, 1.0, float('-inf'), float('inf'), float('nan')]
    for threshold in [330.0, 560.0, 810.0]:
        balances += [math.nextafter(threshold, -math.inf), threshold,
                     math.nextafter(threshold, math.inf)]
    for balance, flags, variable, initial in itertools.product(balances, range(8), [0, 1], [0, 511]):
        yield {**common, 'group': 'automatic-thresholds', 'frequency': 5, 'risk': 1234,
               'variable': variable, 'initial': initial, 'converted_balance': balance,
               'threshold_flags': flags}
    for balance, percentage, variable in itertools.product([1000.0, 10000.0, 100000.0], [0.0, 1.0, 12.5, 35.0, -1.0], [0, 1]):
        yield {**common, 'group': 'percentage-order', 'frequency': 5, 'risk': 1234,
               'variable': variable, 'initial': 511, 'converted_balance': balance,
               'max_dd': percentage}


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('run')
    args = ap.parse_args()
    if not re.fullmatch('[a-z0-9-]+', args.run):
        raise ValueError('INVALID_RUN')
    out = ROOT / 'bot-cua-toi-3/phan-tich/chon-chien-luoc' / args.run
    out.mkdir(parents=True, exist_ok=False)
    original = price.Original(3)
    m, x, uc, base = original.m, original.x, original.uc, original.base
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    raw = next(raw for region, raw in original.regions if region['base'] == base)
    metadata_path = ROOT / 'bot-cua-toi-3/phan-tich/luot-20261023-data/metadata/import.json'
    metadata = json.loads(metadata_path.read_text())
    instructions = {}
    for function in metadata['functions']:
        if int(function['begin_rva'], 16) in [0xc30, 0x17f00]:
            lo, hi = int(function['begin_rva'], 16), int(function['end_rva'], 16)
            instructions.update({i.address - base: i for i in md.disasm(raw[lo:hi], base + lo)})
    for cfg in PATHS.values():
        if any(rva not in instructions for rva in [cfg['start'], cfg['end'], *cfg['preloads']]):
            raise ValueError('SEGMENT_IS_NOT_ON_INSTRUCTION_BOUNDARY')
        for rva in cfg['preloads']:
            if instructions[rva].mnemonic != 'movabs':
                raise ValueError('PRELOAD_IS_NOT_AN_ORIGINAL_IMMEDIATE')
    for name, cfg in PATHS.items():
        tables = [struct.unpack('<2d', m.mem_read(base + cfg['table'] + i * 16, 16)) for i in range(4)]
        if tables != DIVISORS[:4]:
            raise ValueError('ORIGINAL_DIVISOR_TABLE_DIFFERS')
        (out / f'{name}-instructions.txt').write_text('\n'.join(
            f'{rva:#x} {i.mnemonic} {i.op_str}' for rva, i in instructions.items()
            if cfg['start'] <= rva < cfg['end'] or rva in cfg['preloads']), encoding='utf-8')
    # The original engine address is also present in both verified original loads.
    account_api = 0x7ff6846b7370
    if hex(account_api) not in instructions[0x189e8].op_str:
        raise ValueError('ACCOUNT_API_LOAD_DIFFERS')
    page = account_api & ~4095
    if not any(lo <= page <= hi for lo, hi, _ in m.mem_regions()):
        m.mem_map(page, 4096)
    state = {}

    def boundary(machine, address, size, _):
        if address == account_api:
            if machine.reg_read(x.UC_X86_REG_RDX) != 0x25:
                raise ValueError('UNEXPECTED_ACCOUNT_PROPERTY')
            machine.mem_write(base + 0x1d6e48, struct.pack('<d', state['case']['converted_balance']))
            state['calls'].append('account-balance-boundary')
        else:
            state['calls'].append('currency-conversion-boundary')
            machine.reg_write(x.UC_X86_REG_XMM0, int.from_bytes(struct.pack('<d', state['case']['converted_balance']), 'little'))
        stack = machine.reg_read(x.UC_X86_REG_RSP)
        machine.reg_write(x.UC_X86_REG_RIP, struct.unpack('<Q', machine.mem_read(stack, 8))[0])
        machine.reg_write(x.UC_X86_REG_RSP, stack + 8)

    for address in [account_api, base + 0x8300]:
        m.hook_add(uc.UC_HOOK_CODE, boundary, begin=address, end=address)

    def visit(machine, address, size, _):
        if address in [account_api, base + 0x8300]:
            return
        if not (base + state['cfg']['start'] <= address < base + state['cfg']['end']):
            raise ValueError('UNDECLARED_NATIVE_CALL_OR_JUMP ' + hex(address))
        state['visited'].add(address - base)

    def write(machine, access, address, size, value, _):
        allowed = [(base + 0x6d21c, base + 0x6d229), (base + 0x76fa8, base + 0x76fb0),
                   (0x50000000, 0x50020000)]
        if not any(lo <= address and address + size <= hi for lo, hi in allowed):
            raise ValueError('UNEXPECTED_NATIVE_WRITE ' + hex(address - base))

    start = time.monotonic()
    summaries = []
    failures = []
    with (out / 'results.jsonl').open('x', encoding='utf-8') as stream:
        for name, cfg in PATHS.items():
            state.update(cfg=cfg, visited=set())
            counts = {}
            for number, case in enumerate(cases()):
                state.update(case=case, calls=[])
                for reg in ['RAX', 'RBX', 'RCX', 'RDX', 'RSI', 'RDI', 'RBP', 'R8', 'R9', 'R10', 'R11', 'R12', 'R13', 'R14', 'R15']:
                    m.reg_write(getattr(x, 'UC_X86_REG_' + reg), 0)
                for i in range(16):
                    m.reg_write(getattr(x, 'UC_X86_REG_XMM' + str(i)), 0)
                m.reg_write(x.UC_X86_REG_RSP, 0x50018000)
                for field, fmt in [('frequency', '<i'), ('risk', '<i'), ('max_dd', '<d'), ('variable', '<B')]:
                    m.mem_write(base + INPUTS[field], struct.pack(fmt, case[field]))
                for i in range(9):
                    m.mem_write(base + INPUTS['manual'] + i * 8, bytes([(case['manual'] >> i) & 1]))
                m.mem_write(base + OUTPUTS['mode'], struct.pack('<i', -97))
                m.mem_write(base + OUTPUTS['enabled'], bytes((case['initial'] >> i) & 1 for i in range(9)))
                m.mem_write(base + OUTPUTS['divisor'], struct.pack('<d', case['initial_divisor']))
                for i in range(3):
                    m.mem_write(base + 0x75351 + i, bytes([(case['threshold_flags'] >> i) & 1]))
                for rva in cfg['preloads']:
                    i = instructions[rva]
                    m.emu_start(i.address, i.address + i.size, count=1)
                code_hook = m.hook_add(uc.UC_HOOK_CODE, visit)
                write_hook = m.hook_add(uc.UC_HOOK_MEM_WRITE, write)
                m.emu_start(base + cfg['start'], base + cfg['end'], timeout=1000000, count=2000)
                m.hook_del(code_hook)
                m.hook_del(write_hook)
                if m.reg_read(x.UC_X86_REG_RIP) != base + cfg['end']:
                    raise ValueError('SELECTOR_NOT_COMPLETED')
                actual = {'mode': struct.unpack('<i', m.mem_read(base + OUTPUTS['mode'], 4))[0],
                          'enabled': list(m.mem_read(base + OUTPUTS['enabled'], 9)),
                          'divisor_bits': bytes(m.mem_read(base + OUTPUTS['divisor'], 8)).hex()}
                expected = reference(case)
                calls = ['account-balance-boundary', 'currency-conversion-boundary'] if case['frequency'] == 5 and case['risk'] == 1234 else []
                matched = actual == expected and state['calls'] == calls
                row = {'path': name, 'case': number, 'inputs': case, 'original': actual,
                       'hypothesis': expected, 'boundary_calls': state['calls'], 'matched': matched}
                stream.write(json.dumps(row, ensure_ascii=False) + '\n')
                counts[case['group']] = counts.get(case['group'], 0) + 1
                if not matched:
                    failures.append(row)
            summaries.append({'path': name, 'cases': number + 1, 'groups': counts,
                              'visited_instruction_rvas': [hex(rva) for rva in sorted(state['visited'])],
                              'native_segment': cfg})
    result = {'bot': 3, 'passed': not failures, 'checks': sum(s['cases'] for s in summaries),
              'failed': len(failures), 'first_failures': failures[:10], 'paths': summaries,
              'menu_to_internal_index': MENU_TO_INTERNAL, 'divisors_variable_on_off': DIVISORS,
              'seconds': round(time.monotonic() - start, 2), 'tool_sha256': price.sha(Path(__file__)),
              'metadata_sha256': price.sha(metadata_path), 'code_sha256': metadata['code_sha256'],
              'data_sha256': metadata['data_sha256'], 'results_sha256': price.sha(out / 'results.jsonl'),
              'scope': 'Native selection segments versus an explicit analysis hypothesis, including all 512 manual combinations. Account reading/currency conversion are supplied boundaries. Not MQL5 implementation, complete initialization, actual strategy execution, menu labels, or a complete EA comparison.'}
    (out / 'summary.json').write_text(json.dumps(result, ensure_ascii=False, indent=2), encoding='utf-8')
    print(json.dumps({k: result[k] for k in ['bot', 'passed', 'checks', 'failed', 'first_failures', 'seconds']}))
    raise SystemExit(bool(failures))


if __name__ == '__main__':
    main()
