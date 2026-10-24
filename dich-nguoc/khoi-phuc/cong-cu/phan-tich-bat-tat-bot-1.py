"""Check all 256 combinations at the original eight bot-1 strategy gates.

Usage: python -I -B -X utf8 phan-tich-bat-tat-bot-1.py NEW_RUN
Only input loads, comparisons and their conditional branches run. No strategy
body, terminal API, live process or original EX5 file is modified or executed.
"""
import argparse
import importlib.util
import json
from pathlib import Path
import re

ROOT = Path(__file__).resolve().parents[1]
spec = importlib.util.spec_from_file_location('price', Path(__file__).with_name('kiem-muc-gia-bot-1-3.py'))
price = importlib.util.module_from_spec(spec)
spec.loader.exec_module(price)


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('run')
    args = ap.parse_args()
    if not re.fullmatch('[a-z0-9-]+', args.run):
        raise ValueError('INVALID_RUN')
    out = ROOT / 'bot-cua-toi-1/phan-tich/bat-tat-chien-luoc' / args.run
    out.mkdir(parents=True, exist_ok=False)
    original = price.Original(1)
    m, x, base = original.m, original.x, original.base
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    md.detail = True
    folder = ROOT / 'bot-cua-toi-1/phan-tich/luot-20261023-data-v2'
    metadata_path = folder / 'metadata/import.json'
    metadata = json.loads(metadata_path.read_text())
    function = next(f for f in metadata['functions'] if int(f['begin_rva'], 16) == 0x10f60)
    raw = next(raw for region, raw in original.regions if region['base'] == base)
    instructions = list(md.disasm(raw[0x10f60:int(function['end_rva'], 16)], base + 0x10f60))
    address_index = {i.address: n for n, i in enumerate(instructions)}
    profile_path = folder / 'kiem-tham-so-goc.json'
    profiles = json.loads(profile_path.read_text())['profiles']
    binding_path = ROOT / 'bot-cua-toi-1/phan-tich/cai-dat-20261023/cai-dat-da-kiem.json'
    bindings = json.loads(binding_path.read_text())['bindings']
    by_address = {base + int(f['candidate_rva'], 16): f for f in bindings}
    gates = []
    for profile in profiles:
        enabled = base + int(profile['start_rva'], 16)
        branch_index = address_index[enabled] - 1
        branch = instructions[branch_index]
        if branch.mnemonic != 'je' or branch.operands[0].type != capstone.CS_OP_IMM:
            raise ValueError('EXPECTED_ZERO_CONDITIONAL_GATE')
        compare_index = branch_index - 1
        while instructions[compare_index].mnemonic in ['mov', 'movabs']:
            compare_index -= 1
        compare = instructions[compare_index]
        if compare.mnemonic != 'cmp' or compare.op_str != 'byte ptr [rax], 0':
            raise ValueError('EXPECTED_BOOLEAN_COMPARE')
        load_index = compare_index - 1
        while not any(md.reg_name(reg) == 'rax' for reg in instructions[load_index].regs_access()[1]):
            if load_index < compare_index - 12:
                raise ValueError('INPUT_LOAD_NOT_LOCAL')
            load_index -= 1
        load = instructions[load_index]
        if load.mnemonic != 'movabs' or load.operands[1].type != capstone.CS_OP_IMM:
            raise ValueError('INPUT_LOAD_NOT_AN_ORIGINAL_IMMEDIATE')
        binding = by_address[load.operands[1].imm]
        if binding['representation'] != 'bool' or not binding['original_memory_binding_verified']:
            raise ValueError('INPUT_BINDING_UNVERIFIED')
        prefix = instructions[load_index:branch_index]
        if any(i.mnemonic not in ['mov', 'movabs', 'cmp'] for i in prefix):
            raise ValueError('GATE_PREFIX_HAS_OTHER_BEHAVIOR')
        gates.append({'profile_index': profile['index'], 'input': binding['name'],
                      'input_rva': binding['candidate_rva'], 'start_rva': hex(load.address - base),
                      'branch_rva': hex(branch.address - base), 'enabled_rva': hex(enabled - base),
                      'disabled_rva': hex(branch.operands[0].imm - base),
                      'instructions': [f'{i.address-base:#x} {i.mnemonic} {i.op_str}' for i in [*prefix, branch]]})
    if len(gates) != 8 or len({g['input'] for g in gates}) != 8:
        raise ValueError('EXPECTED_EIGHT_DISTINCT_GATES')
    with (out / 'gates.json').open('x', encoding='utf-8') as stream:
        json.dump(gates, stream, ensure_ascii=False, indent=2)
    boundary = {}

    def stop_at_destination(machine, address, size, _):
        if address in boundary['destinations']:
            machine.emu_stop()
        elif address not in boundary['instructions']:
            raise ValueError('EXECUTION_LEFT_THE_GATE_PREFIX ' + hex(address - base))

    # Stop explicitly before either branch destination. A previous translated
    # block may include the next gate; changing emu_start's end address alone
    # did not reliably stop inside that block in the retained failed run.
    m.hook_add(original.uc.UC_HOOK_CODE, stop_at_destination)
    rows = []
    for mask in range(256):
        actual = []
        expected = []
        for n, gate in enumerate(gates):
            value = (mask >> n) & 1
            for reg in ['RAX', 'RBX', 'RCX', 'RDX', 'RSI', 'RDI', 'RBP', 'R8', 'R9', 'R10', 'R11', 'R12', 'R13', 'R14', 'R15']:
                m.reg_write(getattr(x, 'UC_X86_REG_' + reg), 0)
            m.reg_write(x.UC_X86_REG_RSP, 0x50018000)
            for i, other in enumerate(gates):
                m.mem_write(base + int(other['input_rva'], 16), bytes([(mask >> i) & 1]))
            start = base + int(gate['start_rva'], 16)
            boundary['destinations'] = {base + int(gate[k], 16) for k in ['enabled_rva', 'disabled_rva']}
            boundary['instructions'] = {base + int(line.split(' ', 1)[0], 16) for line in gate['instructions']}
            try:
                m.emu_start(start, 0x60000000, count=100)
            except original.uc.UcError:
                with (out / 'failure.json').open('x', encoding='utf-8') as stream:
                    json.dump({'mask': mask, 'gate': gate, 'rip': hex(m.reg_read(x.UC_X86_REG_RIP)),
                               'rax': hex(m.reg_read(x.UC_X86_REG_RAX))}, stream, indent=2)
                raise
            after = m.reg_read(x.UC_X86_REG_RIP) - base
            if after == int(gate['enabled_rva'], 16):
                actual.append(gate['profile_index'])
            elif after != int(gate['disabled_rva'], 16):
                raise ValueError('UNEXPECTED_GATE_DESTINATION')
            if value:
                expected.append(gate['profile_index'])
        rows.append({'mask': mask, 'original_selected_profiles': actual,
                     'expected_selected_profiles': expected, 'matched': actual == expected})
    with (out / 'results.json').open('x', encoding='utf-8') as stream:
        json.dump(rows, stream, ensure_ascii=False, indent=2)
    failures = [row for row in rows if not row['matched']]
    result = {'bot': 1, 'passed': not failures, 'combinations': len(rows), 'gates_per_combination': len(gates),
              'branch_checks': len(rows) * len(gates), 'failed_combinations': failures, 'gates': gates,
              'tool_sha256': price.sha(Path(__file__)), 'metadata_sha256': price.sha(metadata_path),
              'profile_evidence_sha256': price.sha(profile_path), 'binding_evidence_sha256': price.sha(binding_path),
              'code_sha256': metadata['code_sha256'], 'data_sha256': metadata['data_sha256'],
              'results_sha256': price.sha(out / 'results.json'),
              'scope': 'Only eight original enable gates for all 256 input combinations. Does not execute or validate strategy bodies, order management, or reconstructed MQL5.'}
    with (out / 'summary.json').open('x', encoding='utf-8') as stream:
        json.dump(result, stream, ensure_ascii=False, indent=2)
    print(json.dumps({k: result[k] for k in ['bot', 'passed', 'combinations', 'branch_checks', 'failed_combinations']}))
    raise SystemExit(bool(failures))


if __name__ == '__main__':
    main()
