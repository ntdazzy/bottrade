"""So hai báo cáo máy thử MT5 (.htm): kết quả tổng hợp, bảng lệnh, bảng giao dịch, phần cài đặt.

Dùng:
  python -I -B -X utf8 so-bao-cao-mt5.py <bao-cao-goc.htm> <bao-cao-dung-lai.htm> [--json <ra.json>] [--case ten]
Phần cài đặt được so riêng: dòng tên EA và dòng tiêu đề nhóm tham số ("--- ... ---=") được liệt kê,
không tính vào kết quả trùng. Mã thoát 0 khi kết quả, lệnh và giao dịch trùng từng ô.
"""
import argparse
import hashlib
import html
import json
import re
import sys
from pathlib import Path

GROUP = re.compile(r'^---.*---=$')


def rows(path):
    raw = Path(path).read_bytes()
    text = raw.decode('utf-16') if raw[:2] in (b'\xff\xfe', b'\xfe\xff') else raw.decode('utf-8-sig')
    out = []
    for r in re.findall(r'<tr[^>]*>(.*?)</tr>', text, re.S):
        cells = [html.unescape(re.sub(r'<[^>]+>', '', c)).replace('\xa0', ' ').strip()
                 for c in re.findall(r'<t[dh][^>]*>(.*?)</t[dh]>', r, re.S)]
        if any(cells):
            out.append(cells)
    return out, hashlib.sha256(raw).hexdigest()


def sections(table):
    names = {'Results': 'results', 'Orders': 'orders', 'Deals': 'deals'}
    current, out = 'settings', {'settings': [], 'results': [], 'orders': [], 'deals': []}
    for cells in table:
        if len(cells) == 1 and cells[0] in names:
            current = names[cells[0]]
            continue
        out[current].append(cells)
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('original')
    ap.add_argument('recovered')
    ap.add_argument('--json')
    ap.add_argument('--case')
    a = ap.parse_args()
    (t1, h1), (t2, h2) = rows(a.original), rows(a.recovered)
    s1, s2 = sections(t1), sections(t2)
    result = {'case': a.case or Path(a.original).stem, 'report_sha256': [h1, h2], 'sections': {}}
    for name in ('results', 'orders', 'deals'):
        x, y = s1[name], s2[name]
        first = next((i for i in range(max(len(x), len(y)))
                      if (x[i] if i < len(x) else None) != (y[i] if i < len(y) else None)), None)
        result['sections'][name] = {
            'rows': [len(x), len(y)], 'identical': x == y,
            'first_difference': None if first is None else {
                'index': first, 'original': x[first] if first < len(x) else None,
                'recovered': y[first] if first < len(y) else None}}

    def settings(rows_):
        expert, groups, rest = [], [], []
        for cells in rows_:
            if cells and cells[0] == 'Expert:':
                expert.append(cells)
            elif any(GROUP.match(c) for c in cells):
                groups.append([c for c in cells if c])
            else:
                rest.append(cells)
        return expert, groups, rest
    e1, g1, r1 = settings(s1['settings'])
    e2, g2, r2 = settings(s2['settings'])
    result['settings'] = {'expert': [e1, e2], 'input_groups': [g1, g2],
                          'other_settings_identical': r1 == r2,
                          'other_settings_only_original': [c for c in r1 if c not in r2],
                          'other_settings_only_recovered': [c for c in r2 if c not in r1]}
    ok = all(v['identical'] for v in result['sections'].values())
    result['results_orders_deals_identical'] = ok
    text = json.dumps(result, ensure_ascii=False, indent=1)
    if a.json:
        out = Path(a.json)
        if out.exists():
            raise FileExistsError('REFUSE_OVERWRITE ' + str(out))
        out.write_text(text + '\n', encoding='utf-8')
    print(json.dumps({'case': result['case'], 'rows': {k: v['rows'] for k, v in result['sections'].items()},
                      'results_orders_deals_identical': ok,
                      'other_settings_identical': result['settings']['other_settings_identical'],
                      'input_groups': [len(g1), len(g2)]}, ensure_ascii=False))
    return 0 if ok else 1


if __name__ == '__main__':
    sys.exit(main())
