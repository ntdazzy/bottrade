"""Prepare Ghidra metadata from captured code/data and the observed tester identity.

Usage: python -I -B -X utf8 tao-ho-so-ma-chup.py BOT CAPTURE_DIR ENGINE_JSON OUTPUT_DIR
Finds and validates the x64 RUNTIME_FUNCTION table; records its exact entries.
Reuses only native API labels/signatures measured with the identical tester binary.
Does not claim the recovered C is MQL5 or a complete reconstruction.
"""
import argparse
import base64
import hashlib
import json
from pathlib import Path
import re
import struct

ap = argparse.ArgumentParser(description=__doc__)
ap.add_argument('bot', type=int, choices=(1, 3))
ap.add_argument('capture', type=Path)
ap.add_argument('engine', type=Path)
ap.add_argument('out', type=Path)
a = ap.parse_args()
root = Path(__file__).resolve().parents[1]
capture = json.loads((a.capture / 'capture.json').read_text(encoding='utf-8'))
engine = json.loads(a.engine.read_text(encoding='utf-8-sig'))
if engine.get('engine_sha256', engine.get('tester_sha256')) != '5033d9d45d669cebd735e8a6be20b54d74b75274f885c9a0e48e52d872104efb':
    raise ValueError('NATIVE_LABELS_REQUIRE_THE_VERIFIED_TESTER_BUILD')
if engine.get('pid', engine.get('tester_pid')) != capture['pid']:
    raise ValueError('ENGINE_PID_DOES_NOT_MATCH_CAPTURE')
regions = []
for r in capture['regions']:
    raw = (a.capture / r['file']).read_bytes()
    if hashlib.sha256(raw).hexdigest() != r['sha256']:
        raise ValueError('CAPTURE_HASH_MISMATCH ' + r['file'])
    regions.append((r, raw))
code, code_bytes = max((v for v in regions if v[0].get('kind') == 'executable'), key=lambda v: v[0]['bytes'])
data_regions = [v for v in regions if v[0].get('kind') == 'mutable_program_data']
if len(data_regions) != 1:
    raise ValueError('EXPECTED_ONE_PROGRAM_DATA_REGION')
data, raw = data_regions[0]
base = code['base']
data_rva = data['base'] - base
tables = []
for offset in range(0, len(raw) - 12, 4):
    if struct.unpack_from('<I', raw, offset)[0] != 0:
        continue
    rows, last = [], 0
    for pos in range(offset, len(raw) - 11, 12):
        begin, end, unwind = struct.unpack_from('<III', raw, pos)
        if not (last <= begin < end <= code['bytes'] and data_rva <= unwind < data_rva + len(raw)):
            break
        ui = unwind - data_rva
        if ui + 4 > len(raw) or raw[ui] & 7 != 1:
            break
        if ui + 4 + 2 * raw[ui + 2] > len(raw) or raw[ui + 1] > end - begin:
            break
        rows.append((begin, end, unwind))
        last = end
    if len(rows) >= 20:
        tables.append((offset, rows))
if len(tables) != 1:
    raise ValueError('AMBIGUOUS_OR_MISSING_FUNCTION_TABLE ' + str([(o, len(r)) for o, r in tables]))
offset, functions = tables[0]
a.out.mkdir(parents=True, exist_ok=False)
def write(name, lines):
    (a.out / name).write_text('\n'.join(lines) + ('\n' if lines else ''), encoding='utf-8')
write(code['file'] + '.base.txt', [f'{base:x}'])
write('seeds.txt', [f'{base+b:x}' for b, _, _ in functions])
write('functions.tsv', [f'{base+b:x}\t{base+e:x}' for b, e, _ in functions])
write('data.tsv', [f"{data['base']:x}\t{(a.capture / data['file']).resolve()}"])
strings = {}
for match in re.finditer(rb'(?:[\x20-\x7e]\x00){1,4096}\x00\x00', raw):
    if match.start() % 2:
        continue
    text = match.group()[:-2].decode('utf-16-le')
    # Captured static literals have a 12-byte header: 0, 2, UTF-16 length.
    # Avoid treating isolated ASCII-looking numeric bytes as string data.
    if match.start() < 12 or struct.unpack_from('<III', raw, match.start()-12) != (0, 2, len(text)):
        continue
    strings[data['base'] + match.start()] = text
write('strings.tsv', [f'{addr:x}\t{len(text)}\t{base64.b64encode(text.encode()).decode()}' for addr, text in strings.items()])
refs = [data['base'] + pos for pos in range(len(raw) - 11) if struct.unpack_from('<Q', raw, pos + 4)[0] in strings]
write('refs.tsv', [f'{addr:x}' for addr in refs])
native = root / 'bot-cua-toi-13/phan-tich/ky-hieu-v4'
labels = json.loads((native / 'native-labels.json').read_text(encoding='utf-8'))
engine_base = int(engine['engine_base'], 16)
write('native-labels.tsv', [f"{engine_base+int(r['rva'],16):x}\t{r['label']}" for r in labels])
signatures = []
for line in (native / 'native-signatures.tsv').read_text().splitlines():
    fields = line.split('\t')
    fields[0] = f'{engine_base + int(fields[0],16) - 0x7ff652fe0000:x}'
    signatures.append('\t'.join(fields))
write('native-signatures.tsv', signatures)
for name in ['inputs.tsv', 'predefined.tsv']:
    write(name, [])
record = {'bot': a.bot, 'capture': str(a.capture.resolve()), 'engine': engine,
          'code_file': str((a.capture / code['file']).resolve()), 'code_base': hex(base),
          'code_sha256': code['sha256'], 'data_sha256': data['sha256'],
          'function_table_address': hex(data['base'] + offset),
          'functions': [{'begin_rva': hex(b), 'end_rva': hex(e), 'unwind_rva': hex(u)} for b,e,u in functions],
          'strings': len(strings), 'string_refs': len(refs), 'native_labels': len(labels),
          'native_signatures': len(signatures),
          'format_reference': 'https://learn.microsoft.com/en-us/cpp/build/exception-handling-x64',
          'limitations': ['Snapshot is not atomic and does not establish completion of OnInit.',
                          'Only literal strings with observed header (0, 2, UTF-16 length) are annotated.',
                          'ASCII UTF-16 strings only; other text and heap buffers are not reconstructed.',
                          'Function table entries are ranges; names and complete trading behavior remain unverified.',
                          'No call-site dispatch overrides from bot 13 are reused.']}
(a.out / 'import.json').write_text(json.dumps(record, ensure_ascii=False, indent=2), encoding='utf-8')
print(json.dumps({k: record[k] for k in ['bot','function_table_address','strings','string_refs','native_labels','native_signatures']} | {'functions': len(functions)}))
