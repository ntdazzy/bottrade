"""Inventory every captured function, observed input and referenced string for bots 1/3.

python -I -B -X utf8 lap-ban-do-bot-1-3.py NEW_OUTPUT_DIRECTORY
Read-only toward EX5/captures/C/current source. Reject overwriting output. Function
roles are bounded descriptions of visible code, not proof that all behavior is known.
"""
import argparse
import base64
import hashlib
import json
import os
from pathlib import Path
import re
import struct

ROOT=Path(__file__).resolve().parents[1]
# Native RVA pairs; None means that there is no matching standalone function.
# Labels deliberately leave full business semantics unresolved when not verified.
ROLES=[
(0,0,'Hạ số người dùng và giải phóng chuỗi','Bộ nhớ'),
(0x60,0x60,'Tạo/mở rộng bộ nhớ chuỗi','Bộ nhớ'),
(0x1e0,0x1e0,'Chép chuỗi từ con trỏ văn bản','Bộ nhớ'),
(0x3c0,0x3c0,'Cắt/chép đoạn chuỗi','Bộ nhớ'),
(0x4a0,0x4a0,'Chuẩn bị ghi chuỗi, giữ quyền dùng bộ nhớ','Bộ nhớ'),
(0x5c0,0x5c0,'Gán chuỗi và quản lý số người dùng','Bộ nhớ'),
(0x7e0,0x7e0,'Hủy phần tử và giải phóng mảng','Bộ nhớ'),
(0x8c0,0x8c0,'Chuyển lỗi chạy chương trình, mã 0x224','Lỗi'),
(0x8e0,0x8e0,'Chuyển lỗi chạy chương trình, mã 0x21e','Lỗi'),
(0x900,0x900,'Hàm rỗng do bản gốc tạo','Bộ nhớ'),
(0x910,0x910,'Khởi tạo thông tin kiểu đối tượng','Bộ nhớ'),
(0x950,0x950,'Gửi yêu cầu thường/bất đồng bộ và ghi thông báo','Giao dịch'),
(0xb60,0xb60,'Hủy các chuỗi của đối tượng giao dịch','Bộ nhớ'),
(0xbd0,0xbd0,'Hủy chuỗi của một cấu trúc lưu','Bộ nhớ'),
(0xc30,0xc30,'Luồng khởi tạo: tài khoản, dữ liệu, chỉ báo và trạng thái','Vòng đời'),
(0x5880,0x61a0,'Kiểm quyền tài khoản qua HTTP và xử lý phản hồi','Điều kiện dùng'),
(0x61b0,0x6ad0,'Tra lịch sự kiện USD, tìm Nonfarm Payrolls và mốc phát hành','Tin tức'),
(0x6600,0x6f20,'Tra lịch sự kiện US, tìm Fed Interest Rate Decision','Tin tức'),
(0x6a90,0x73b0,'Tra lịch USD và lọc Consumer Price Index/CPI','Tin tức'),
(0x7310,0x7c30,'Chọn thời điểm chặn tin còn hiệu lực','Tin tức'),
(0x7500,0xe0c0,'Đọc ATR/giá và điều chỉnh tham số chiến lược','Tham số'),
(0x8320,0xef40,'Tạo/cập nhật các đối tượng bảng thông tin','Hiển thị'),
(0xe1b0,0x14fa0,'Quét vị thế, tổng hợp số liệu và nhãn thông tin','Hiển thị'),
(0xffb0,0x16e80,'Quét lịch sử, tổng hợp số liệu và nhãn thông tin','Hiển thị'),
(0x10f60,0x17f00,'Luồng điều phối chiến lược, vốn và bộ lọc','Điều phối'),
(0x173f0,0x1fd00,'Cập nhật vốn cao nhất theo lịch sử rút tiền','Trạng thái vốn'),
(0x17840,0x7e20,'Tính giờ theo mùa bằng hai công thức và so ngày trong năm','Giờ'),
(0x17d20,0x20150,'Đọc giờ UTC qua HTTP và tách kết quả','Giờ'),
(0x18790,0x20bc0,'Đồng bộ các bảng lưu theo vé vị thế','Trạng thái lệnh'),
(0x18aa0,0x20ef0,'Xử lý một chiến lược: lọc, quét, vào và quản lý lệnh','Chiến lược'),
(0x1efa0,0x2a1c0,'Tổng hợp lịch sử theo điều kiện nhận dạng/mã giao dịch','Lịch sử'),
(0x1f5e0,0x2a800,'Thả chỉ báo và xóa đối tượng khi dừng','Vòng đời'),
(0x20950,None,'Đọc ba chỉ tiêu máy thử và tính điểm; sự kiện gọi còn phải chốt','Kết quả'),
(0x20a00,0x2bb80,'Khởi tạo biến/cấu trúc và thông tin tài khoản','Vòng đời'),
(0x22750,0x2dd30,'Giải phóng toàn bộ cấu trúc/chuỗi/mảng dùng chung','Vòng đời'),
(0x22bd0,0x2e300,'Xóa các trường số trong một cấu trúc','Bộ nhớ'),
(0x22c00,0x2e330,'Hủy chuỗi trong một cấu trúc','Bộ nhớ'),
(0x22c40,0x2e370,'Tạo/gửi yêu cầu đóng vị thế theo vé','Giao dịch'),
(0x231c0,0x2e8f0,'Kiểm kiểu khớp lệnh theo thuộc tính mã giao dịch','Giao dịch'),
(0x235c0,0x2ecf0,'Định dạng kết quả giao dịch','Thông báo'),
(0x23fa0,0x2f6d0,'Định dạng chi tiết yêu cầu giao dịch','Thông báo'),
(0x26060,0x31790,'Đổi loại lệnh thành chuỗi','Thông báo'),
(0x26360,0x31a90,'Định dạng giá và giá kích hoạt','Thông báo'),
(0x265a0,0x31cd0,'Tìm mức mua, xác nhận và lọc lệnh chờ gần','Điểm vào'),
(0x26960,0x32090,'Tìm mức bán, xác nhận và lọc lệnh chờ gần','Điểm vào'),
(0x26d20,0x32a90,'Kiểm vé/mã giao dịch và tạo yêu cầu sửa','Giao dịch'),
(0x271f0,0x32f60,'Quản lý vị thế nhánh mua: dừng/chốt, dời và đóng','Quản lý vị thế'),
(0x2abc0,0x37590,'Quản lý vị thế nhánh bán: dừng/chốt, dời và đóng','Quản lý vị thế'),
(0x2e6d0,0x3bb10,'Gửi hàng đợi 100 lệnh chờ theo giá, ghi kết quả và thử lại khi lỗi 132','Giao dịch'),
(0x2f5c0,0x3ca00,'Quét/hủy lệnh chờ mua theo khoảng cách','Quản lý lệnh chờ'),
(0x2f7e0,0x3cc20,'Quét/hủy lệnh chờ bán theo khoảng cách','Quản lý lệnh chờ'),
(0x2fa00,0x3ce40,'Quét/đóng vị thế nhánh mua theo bộ lọc','Quản lý vị thế'),
(0x2fce0,0x3d220,'Quét/đóng vị thế nhánh bán theo bộ lọc','Quản lý vị thế'),
(0x2ffb0,0x3d5f0,'Đọc trường năm của thời gian hiện tại','Giờ'),
(0x2ffe0,0x3d620,'Đọc trường tháng của thời gian hiện tại','Giờ'),
(0x30010,0x3d650,'Quét/hủy lệnh chờ theo bộ lọc nhận dạng','Quản lý lệnh chờ'),
(0x30320,None,'Quét/sửa/hủy lệnh chờ; cần chốt mọi nhánh','Quản lý lệnh chờ'),
(0x31f40,None,'Đếm lệnh chờ nhánh mua theo bộ lọc','Quản lý lệnh chờ'),
(0x32110,0x3da90,'Giới hạn lệnh chờ nhánh mua, chọn giá cần xử lý','Quản lý lệnh chờ'),
(0x323e0,None,'Đếm lệnh chờ nhánh bán theo bộ lọc','Quản lý lệnh chờ'),
(0x325b0,0x3dd60,'Giới hạn lệnh chờ nhánh bán, chọn giá cần xử lý','Quản lý lệnh chờ'),
(0x32890,0x3e040,'Tìm mức đỉnh theo hai chiều rộng nến','Mức giá'),
(0x32ac0,0x3e270,'Tìm mức đáy theo hai chiều rộng nến','Mức giá'),
(0x32ce0,0x3e490,'Dọn bảng kết quả 100 hàng theo vé vị thế; lấy biên từ tổng lệnh chờ','Quản lý lệnh chờ'),
(0x32dd0,0x3e580,'Kiểm thuộc tính và tạo yêu cầu mở lệnh','Giao dịch'),
(0x336d0,0x3ee80,'Đổi mã lỗi thành chuỗi và tăng bộ đếm','Thông báo'),
(0x34150,0x32450,'Kiểm vùng cấm sửa rồi tạo yêu cầu hủy lệnh','Giao dịch'),
(0x34780,0x3f900,'Tính khối lượng và cập nhật trạng thái vốn','Khối lượng'),
(0x36220,0x8300,'Đổi tiền của tài khoản sang USD','Đổi tiền tệ'),
(0x3bfe0,0x46ca0,'Kiểm khối lượng theo min/max/bước cho phép','Khối lượng'),
(None,0x47330,'Kiểm tổng lệnh với hạn mức của tài khoản','Giao dịch'),
(0x3c670,0x47380,'Lọc lệnh chờ mua gần mức giá','Điểm vào'),
(0x3c8d0,0x475e0,'Lọc lệnh chờ bán gần mức giá','Điểm vào'),
(0x3cb30,0x47840,'Chặn theo vốn/khối lượng rồi kiểm ký quỹ','Ký quỹ'),
(0x3d010,0x47d20,'Kiểm hai ngưỡng khoảng cách tới dừng lỗ rồi gọi đóng vị thế','Quản lý vị thế'),
(0x3d200,0x47f10,'Tính và lưu mức dừng theo vé; bảng dừng ảo','Dừng ảo'),
(None,0x482b0,'Lưu/đọc mức chốt lời ảo theo vé trong bảng 500 hàng','Trạng thái lệnh'),
(0x3d5a0,0x484c0,'Kiểm thời gian chờ theo vé trong bảng','Dừng ảo'),
(0x3d640,0x48560,'Ghi thời điểm vào bảng theo vé','Dừng ảo'),
(0x3d6c0,0x485e0,'Các điều kiện tài khoản/chuỗi và chế độ chạy; chưa chốt toàn bộ','Điều kiện dùng'),
(0x457d0,0x53670,'Tính ký quỹ cần có và so tiền khả dụng','Ký quỹ'),
(0x45b70,0x53a10,'Cập nhật nhãn chiến lược/tin trên bảng','Hiển thị'),
(0x47740,0x555e0,'Cập nhật nhãn số liệu trên bảng','Hiển thị'),
(0x47950,0x557f0,'Sắp xếp hai mảng song song','Dữ liệu'),
(0x47d20,0x41780,'Đổi từ USD sang tiền của tài khoản','Đổi tiền tệ'),
(0x4d260,0x55bc0,'Kiểm quyền tài khoản qua HTTP phụ và xử lý phản hồi','Điều kiện dùng'),
]
PROOFS={
 'Mức giá':('kiem-muc-gia/gia-20261023-r1','PriceLevels'),
 'Điểm vào':('kiem-gia-vao/entry-20261023-r3','EntryLevels'),
 'Tham số':('kiem-dieu-chinh/settings-20261023-r2','DistanceSettings'),
 'Khối lượng':('kiem-khoi-luong/volume-20261023-r1','Volume'),
 'Đổi tiền tệ':(None,'Currency'),
 'Trạng thái vốn':('kiem-rut-tien/withdrawal-20261023-r1','Withdrawal'),
 'Ký quỹ':('kiem-ky-quy/margin-20261023-r2','Margin'),
}
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def read_bytes(regions,address,size):
    for base,raw in regions:
        if base<=address and address+size<=base+len(raw):return raw[address-base:address-base+size]
    return None
def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('output')
    ap.add_argument('--extra-calibration',type=Path)
    ap.add_argument('--menu-evidence',type=Path)
    args=ap.parse_args()
    out=Path(args.output).resolve()
    if not out.is_relative_to(ROOT) or out==ROOT:raise ValueError('OUTPUT_MUST_BE_NEW_FOLDER_INSIDE_KHOI_PHUC')
    out.mkdir(parents=True,exist_ok=False)
    probe_root=Path('C:/Users/NTD/Desktop/BotTradeEA/local/market-demos-20261020/dich-nguoc-luot2')
    probe_path=probe_root/'captures/api_probe_v4/probe-analysis.json'
    probe=json.loads(probe_path.read_text())
    probe_source=probe_root/'api-probe-v4/Ex5ApiProbeLibraryV4.mq5'
    probe_source_text=probe_source.read_text(encoding='utf-8-sig')
    assert 'EX5_API_PROBE:' in probe_source_text and 'Sleep' in probe_source_text
    operations={int(k):v[0] for k,v in probe['observed_dispatch_operations'].items() if len(v)==1}
    sleep_calls=[c for f in probe['functions'] if f['markers']==['Sleep'] for c in f['calls'] if c['target_rva']=='0x7b17c0']
    assert sleep_calls,'NO_SLEEP_REFERENCE_PROOF'
    calibration={'probe_analysis':str(probe_path),'probe_analysis_sha256':sha(probe_path),'source':str(probe_source),'source_sha256':sha(probe_source),
        'engine_sha256':probe['engine_sha256'].lower(),'dispatcher_rva':probe['dispatcher_rva'],'observed_operations':operations,
        'sleep_call_sites':sleep_calls,'scope':'Known-source call-site calibration on identical engine; not business-logic verification.'}
    extra_labels={}
    if args.extra_calibration:
        extra_path=args.extra_calibration.resolve()
        if not extra_path.is_relative_to(ROOT):raise ValueError('CALIBRATION_OUTSIDE_KHOI_PHUC')
        extra=json.loads(extra_path.read_text())
        assert extra['engine_sha256']==calibration['engine_sha256'] and extra['runner_verified'] and extra['only_anchor_executed']
        build=json.loads((extra_path.parent/'build.json').read_text())
        for row in build['builds']:
            assert row['errors']==row['warnings']==0
            assert sha(extra_path.parent/(row['name']+'.mq5'))==row['source_sha256']
            assert sha(extra_path.parent/(row['name']+'.ex5'))==row['binary_sha256']
        anchor=[f for f in extra['functions'] if f['markers']==['Anchor']]
        if len(anchor)==1 and len(anchor[0]['calls'])==1:
            call=anchor[0]['calls'][0]
            source_text=(extra_path.parent/'RecoveryApiLibrary.mq5').read_text(encoding='utf-8-sig')
            if call.get('rdx_constant')==2 and call.get('r8_constant')==1 and 'Print("EX5_API_PROBE:Anchor");' in source_text:
                operations[2]='Print'
        for bot in extra['bots']:
            for address in bot['addresses']:
                names={site['source_marker'] for site in address['known_source_sites']}
                if not names:continue
                assert len(names)==1,'AMBIGUOUS_KNOWN_SOURCE_CALL'
                name=next(iter(names))
                extra_labels[int(address['engine_rva'],16)]='runtime_string_to_lower' if name=='StringToLower' else 'MT5_'+name
        calibration['additional']={'path':extra_path.relative_to(ROOT).as_posix(),'sha256':sha(extra_path),
            'engine_rva_labels':{hex(k):v for k,v in extra_labels.items()},
            'scope':'Direct call-site matches to exported known-source wrappers; StringToLower match is an internal helper, not the public string descriptor interface.'}
    (out/'api-calibration.json').write_text(json.dumps(calibration,ensure_ascii=False,indent=2),encoding='utf-8')
    menu_evidence=None
    if args.menu_evidence:
        menu_path=args.menu_evidence.resolve()
        if not menu_path.is_relative_to(ROOT):raise ValueError('MENU_EVIDENCE_OUTSIDE_KHOI_PHUC')
        menu_evidence=json.loads(menu_path.read_text())
        assert menu_evidence['labels_observed']==152 and menu_evidence['enum_choices_mapped']==28
        for b in menu_evidence['bots']:
            assert sha(menu_path.parent/b['defaults_set'])==b['defaults_set_sha256']
            for s in b['settings']:
                assert s['label_screenshots'] and all((menu_path.parent/p).is_file() for p in s['label_screenshots'])
            for m in b['menus']:
                assert sha(menu_path.parent/m['dropdown_observation'])==m['dropdown_observation_sha256']
    all_bots=[]
    for bot,run,filename in [(1,'luot-20261023-data-v2','ma-trung-gian.c'),(3,'luot-20261023-data','ma-trung-gian-day-du.c')]:
        folder=ROOT/f'bot-cua-toi-{bot}/phan-tich'/run;meta=json.loads((folder/'metadata/import.json').read_text())
        assert meta['engine']['engine_sha256'].lower()==calibration['engine_sha256'],'CALIBRATION_ENGINE_MISMATCH'
        source=folder/filename;text=source.read_text();base=int(meta['code_base'],16)
        capdir=Path(meta['capture']);cap=json.loads((capdir/'capture.json').read_text());regions=[]
        for region in cap['regions']:
            p=capdir/region['file'];assert sha(p)==region['sha256'];regions.append((region['base'],p.read_bytes()))
        assert sha(Path(meta['code_file']))==meta['code_sha256']
        roles={pair[bot==3]:pair[2:] for pair in ROLES if pair[bot==3] is not None}
        runtime={int(f['begin_rva'],16):f for f in meta['functions']};assert set(roles)==set(runtime),'ROLE_TABLE_COVERAGE'
        labels={int(a,16):name for a,name in (line.split('\t') for line in (folder/'metadata/native-labels.tsv').read_text().splitlines())}
        labels[int(meta['engine']['engine_base'],16)+0x7b17c0]='MT5_Sleep'
        labels.update({int(meta['engine']['engine_base'],16)+rva:name for rva,name in extra_labels.items()})
        strings={int(a,16):base64.b64decode(t).decode() for a,n,t in (line.split('\t') for line in (folder/'metadata/strings.tsv').read_text().splitlines())}
        refs={int(s,16) for s in (folder/'metadata/refs.tsv').read_text().splitlines()}
        heads=list(re.finditer(r'/\* Address: ([0-9a-f]+) \*/',text));assert {int(h[1],16)-base for h in heads}==set(runtime)
        functions=[]
        for i,h in enumerate(heads):
            start=h.start();end=heads[i+1].start() if i+1<len(heads) else len(text);body=text[start:end];rva=int(h[1],16)-base
            line=text.count('\n',0,start)+1;last=text.count('\n',0,end)+1;role,category=roles[rva]
            apis=sorted(set(re.findall(r'\bMT5_[A-Za-z0-9_]+',body)))
            named_calls=sorted({int(a,16)-base for a in re.findall(r'\bFUN_([0-9a-f]+)\s*\(',body)}-{rva})
            unknown_calls=[hex(n) for n in named_calls if n not in runtime]
            raw_native=sorted(set(int(a,16) for a in re.findall(r'\(\*\(code \*\)0x([0-9a-f]+)\)\s*\(',body)))
            apis=sorted(set(apis)|{labels[a] for a in raw_native if labels.get(a,'').startswith('MT5_')})
            tokens=set(int(a,16) for a in re.findall(r'(?:DAT_|string_ref_|literal_|ram0x|0x)([0-9a-f]{10,16})',body))
            references=[]
            for address in sorted(tokens):
                ptr=struct.unpack('<Q',read_bytes(regions,address+4,8))[0] if address in refs and read_bytes(regions,address+4,8) else None
                target=address if address in strings else ptr
                if target in strings:references.append({'token_address':hex(address),'text_address':hex(target),'text':strings[target]})
            dispatch=[{'line':line+body.count('\n',0,m.start()),'opcode':int(m[1],0),'argc':int(m[2],0),'known_source_api':operations.get(int(m[1],0))} for m in re.finditer(r'MT5_Dispatch\(\(void \*\)0x[0-9a-f]+,\s*(0x[0-9a-f]+|\d+),\s*(0x[0-9a-f]+|\d+)',body)]
            proof=None;reconstructed=None
            verified_rvas={1:{0x7500,0x173f0,0x265a0,0x26960,0x32890,0x32ac0,0x34780,0x36220,0x3c670,0x3c8d0,0x3cb30,0x457d0,0x47d20},
                           3:{0x8300,0xe0c0,0x1fd00,0x31cd0,0x32090,0x3e040,0x3e270,0x3f900,0x41780,0x47380,0x475e0,0x47840,0x53670}}
            if category in PROOFS and rva in verified_rvas[bot]:
                sub,name=PROOFS[category]
                if category=='Đổi tiền tệ':sub='kiem-doi-tien/currency-20261023-r1' if bot==1 else 'kiem-doi-tien/currency-20261023-r2'
                p=ROOT/f'bot-cua-toi-{bot}/bang-chung'/sub/'comparison.json'
                if p.exists():
                    proof={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p),'comparison':json.loads(p.read_text())}
                p=ROOT/f'bot-cua-toi-{bot}/source/MQL5/Include/bot-cua-toi-{bot}/Bot{bot}{name}.mqh'
                if p.exists():reconstructed={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p)}
            if rva==0xc30:
                p=ROOT/f'bot-cua-toi-{bot}/bang-chung/kiem-khoi-tao-von/init-state-check-20261023-r1/comparison.json'
                if p.exists():
                    comparison=json.loads(p.read_text());assert comparison['passed']
                    proof={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p),'comparison':comparison,
                           'partial_only':'Đoạn nạp vốn/tên lưu; chưa toàn bộ hàm khởi tạo.'}
                    p=ROOT/f'bot-cua-toi-{bot}/source/MQL5/Include/bot-cua-toi-{bot}/Bot{bot}AccountInitialization.mqh'
                    reconstructed={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p),'partial_only':True}
            new_parts={
                (0x34150 if bot==1 else 0x32450):('kiem-huy-lenh-cho/cancel-20261024-r2','OrderCancel','Hủy một vé qua kiểm vùng cấm, tạo và gửi/thông báo: 964 ca. Truy vấn/kết quả gửi cấp sẵn; còn hàm chọn vé, nơi giao dịch, lỗi cấp bộ nhớ và toàn EA.'),
                (0x2e6d0 if bot==1 else 0x3bb10):('kiem-hang-doi/queue-20261024-r3','PendingQueue','Hàng đợi và thử lại; kết quả tạo lệnh cấp sẵn, còn so chung với tạo/gửi và toàn EA.'),
                (0x336d0 if bot==1 else 0x3ee80):('kiem-chuoi-loi/errors-20261024-r3','TradeErrors','Nội dung lỗi/tăng đếm; chuỗi cũ kiểm ở gốc, lỗi cấp bộ nhớ và toàn bộ nơi gọi còn mở.'),
                (0x231c0 if bot==1 else 0x2e8f0):('kiem-kieu-khop-lenh/filling-20261024-r1','Filling','Hàm chọn cách khớp; dữ liệu thuộc tính cấp sẵn, chưa ghép giao dịch.'),
                (0x32dd0 if bot==1 else 0x3e580):('kiem-ghep-dat-lenh-cho/open-pending-20261024-r1','TradeSend','Ghép tạo yêu cầu qua gửi/thông báo; kết quả gửi cấp sẵn, chưa có nơi giao dịch/hàng đợi/EA.'),
                (0x3bfe0 if bot==1 else 0x46ca0):('kiem-khoi-luong-hop-le/volume-validation-20261024-r5','VolumeValidation','Hàm kiểm khối lượng; đuôi số trong thông báo và ghép EA còn mở.'),
                (0x17840 if bot==1 else 0x7e20):('kiem-gio-mua-he/dst-20261024-r1','AmericanDST','Hàm giờ theo mùa trong bộ ca đã ghi; các lỗi và giờ sát biên năm xa còn mở.'),
            }
            scan_rvas={1:{0x31f40:'0',0x323e0:'1',0x32ce0:'2'},3:{0x3e490:'2',0x47330:'3'}}
            selection_rvas={1:[0x32110,0x325b0],3:[0x3da90,0x3dd60]}
            close_rvas={1:[0x22c40,0x3d010],3:[0x2e370,0x47d20]}
            position_scan_rvas={1:[0x2fa00,0x2fce0],3:[0x3ce40,0x3d220]}
            for selection_rva in selection_rvas[bot]:
                new_parts[selection_rva]=('kiem-chon-lenh-huy/selection-20261024-r2','PendingSelection','Bộ 2.522 ca mua/bán mỗi bot: chọn vé qua hủy/gửi, dọn bảng và thông báo. Truy vấn/kết quả gửi cấp sẵn; còn tài khoản thực, lỗi cấp bộ nhớ, nơi gọi và toàn EA.')
            for close_rva in close_rvas[bot]:
                new_parts[close_rva]=('kiem-dong-vi-the/close-20261025-r4','PositionClose','Bộ 2.589 ca: kiểm điều kiện/đóng vị thế qua chọn cách khớp, gửi và thông báo. So trạng thái trước truy vấn và sau gửi. Truy vấn/kết quả gửi cấp sẵn; còn nguồn biến giá dùng chung, nơi gọi, tài khoản thực, lỗi cấp bộ nhớ và toàn EA.')
            for scan_rva in position_scan_rvas[bot]:
                new_parts[scan_rva]=('kiem-chon-vi-the-dong/position-selection-20261025-r3','PositionSelection','Bộ 4.600 ca mỗi bot: quét mua/bán qua nguyên phần kiểm đóng, đóng, chọn cách khớp, gửi và thông báo. So trạng thái trước/sau dịch vụ; truy vấn/kết quả gửi/trạng thái chọn cấp sẵn. Còn nơi gọi, thứ tự nạp giá mọi nhánh, tài khoản/mã lỗi thật, lỗi cấp bộ nhớ và toàn EA.')
            for scan_rva in scan_rvas[bot]:
                new_parts[scan_rva]=('kiem-quet-lenh/scan-20261024-r2','OrderScan','Quét/đếm/dọn bảng/giới hạn trong bộ ca; truy vấn và trạng thái chọn được cấp. Còn tài khoản thật, lỗi cấp bộ nhớ và ghép EA.')
            for send_rva in [0x950,*( [0x235c0,0x23fa0,0x26060,0x26360] if bot==1 else [0x2ecf0,0x2f6d0,0x31790,0x31a90])]:
                new_parts[send_rva]=('kiem-gui-lenh/send-20261024-r3','TradeSend' if send_rva==0x950 else 'TradeMessages','Hàm gửi/thông báo trong bộ ca đã ghi; kết quả gửi cấp sẵn, chưa có nơi giao dịch hoặc toàn EA.')
            if rva in new_parts:
                sub,name,limit=new_parts[rva];p=ROOT/f'bot-cua-toi-{bot}/bang-chung'/sub/'comparison.json'
                if p.exists():
                    comparison=json.loads(p.read_text());assert comparison['failed']==0
                    proof={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p),'comparison':comparison,'partial_only':limit}
                    p=ROOT/f'bot-cua-toi-{bot}/source/MQL5/Include/bot-cua-toi-{bot}/Bot{bot}{name}.mqh'
                    reconstructed={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p),'partial_only':True}
                    if rva in scan_rvas[bot]:
                        group=scan_rvas[bot][rva];engine=ROOT/f'doi-chung-mt5/quet-lenh-20261024/engine-scan-b{bot}-r2/comparison.json'
                        proof.update(function_case_group=group,group_comparison=comparison['groups'][group],tester_comparison=engine.relative_to(ROOT).as_posix(),tester_comparison_sha256=sha(engine))
                    if rva==(0x34150 if bot==1 else 0x32450):
                        engine=ROOT/f'doi-chung-mt5/huy-lenh-cho-20261024/engine-cancel-b{bot}-r2/comparison.json'
                        tested=json.loads(engine.read_text());assert tested['cases']==tested['matched']==964 and tested['failed']==0
                        proof.update(tester_comparison=engine.relative_to(ROOT).as_posix(),tester_comparison_sha256=sha(engine))
                    if rva in selection_rvas[bot]:
                        engine=ROOT/f'doi-chung-mt5/chon-lenh-huy-20261024/engine-selection-b{bot}-r2/comparison.json'
                        tested=json.loads(engine.read_text());assert tested['cases']==tested['matched']==2522 and tested['failed']==0
                        proof.update(function_case_kind=selection_rvas[bot].index(rva),tester_comparison=engine.relative_to(ROOT).as_posix(),tester_comparison_sha256=sha(engine))
                    if rva in close_rvas[bot]:
                        engine=ROOT/f'doi-chung-mt5/dong-vi-the-20261024/engine-close-b{bot}-r2/comparison.json'
                        tested=json.loads(engine.read_text());assert tested['cases']==tested['matched']==2589 and tested['failed']==0
                        semantics=ROOT/f'bot-cua-toi-{bot}/phan-tich/dong-vi-the/close-20261024-r1/semantics.json'
                        proof.update(function_case_kind=close_rvas[bot].index(rva),tester_comparison=engine.relative_to(ROOT).as_posix(),tester_comparison_sha256=sha(engine),semantics_source=semantics.relative_to(ROOT).as_posix(),semantics_sha256=sha(semantics))
                    if rva in position_scan_rvas[bot]:
                        engine=ROOT/f'doi-chung-mt5/chon-vi-the-dong-20261025/engine-position-selection-b{bot}-r3/comparison.json'
                        tested=json.loads(engine.read_text());assert tested['cases']==tested['matched']==4600 and tested['failed']==0
                        semantics=ROOT/f'bot-cua-toi-{bot}/phan-tich/dong-vi-the/scan-20261025-r1/semantics.json'
                        proof.update(function_case_kind=position_scan_rvas[bot].index(rva),tester_comparison=engine.relative_to(ROOT).as_posix(),tester_comparison_sha256=sha(engine),semantics_source=semantics.relative_to(ROOT).as_posix(),semantics_sha256=sha(semantics))
            pipeline_rvas={1:{0x950,0x231c0,0x235c0,0x23fa0,0x26060,0x26360,0x2e6d0,0x32dd0,0x336d0},
                           3:{0x950,0x2e8f0,0x2ecf0,0x2f6d0,0x31790,0x31a90,0x3bb10,0x3e580,0x3ee80}}
            if proof and rva in pipeline_rvas[bot]:
                p=ROOT/f'bot-cua-toi-{bot}/bang-chung/kiem-chuoi-dat-lenh/pipeline-20261024-r3/comparison.json'
                if p.exists():
                    comparison=json.loads(p.read_text());assert comparison['cases']==comparison['matched']==818 and comparison['failed']==0
                    engine=ROOT/f'doi-chung-mt5/chuoi-dat-lenh-20261024/engine-b{bot}-r5/comparison.json'
                    tested=json.loads(engine.read_text());assert tested['cases']==tested['matched']==818 and tested['failed']==0
                    proof['combined_pipeline']={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p),'comparison':comparison,
                        'tester_comparison':engine.relative_to(ROOT).as_posix(),'tester_comparison_sha256':sha(engine),
                        'remaining':'Thuộc tính/kết quả gửi/lỗi được cấp; chưa nơi giao dịch, toàn EA, mọi cài đặt, hiển thị và khởi động lại.'}
            functions.append({'rva':hex(rva),'end_rva_exclusive':runtime[rva]['end_rva'],'role':role,'category':category,
                'source':source.relative_to(ROOT).as_posix(),'line':line,'last_line':last,'c_sha256':hashlib.sha256(body.encode()).hexdigest(),
                'native_apis':apis,'native_address_calls':[{'address':hex(a),'label':labels.get(a)} for a in raw_native],
                'callees':[hex(n) for n in named_calls],'unresolved_callees':unknown_calls,'dispatch_calls':dispatch,
                'strings':references,'globals':sorted(set(re.findall(r'\b(?:_?DAT_|PTR_DAT_|string_ref_)([0-9a-f]+)',body))),
                'visible_c_conditions':len(re.findall(r'\bif\s*\(',body)),'visible_c_switches':len(re.findall(r'\bswitch\s*\(',body)),
                'reconstructed':reconstructed,'component_proof':proof,'full_function_verified':False,
                'remaining':'Cần chốt toàn bộ nhánh, lời gọi gián tiếp, lỗi và kết nối; kết quả thành phần không chứng minh toàn bộ hàm.'})
        for f in functions:f['callers']=[g['rva'] for g in functions if f['rva'] in g['callees']]
        observed=json.loads((folder/'tham-so-quan-sat.json').read_text());inputs=[]
        bindings_path=ROOT/f'bot-cua-toi-{bot}/phan-tich/cai-dat-20261023/cai-dat-da-kiem.json'
        bindings=json.loads(bindings_path.read_text()) if bindings_path.exists() else None
        by_name={f['name']:f for f in bindings['bindings']} if bindings else {}
        menu_bot=next((b for b in menu_evidence['bots'] if b['bot']==bot),None) if menu_evidence else None
        menu_settings={f['name']:f for f in menu_bot['settings']} if menu_bot else {}
        menu_choices={m['name']:m for m in menu_bot['menus']} if menu_bot else {}
        for i,s in enumerate(observed['inputs_observed']):
            name,value=s.split('=',1);header=len(value)>5 and ('---' in value or set(value)=={'='})
            inputs.append({'order':i+1,'name':name,'observed_value':value,'is_header':header,
                'default_verified':False,'original_memory_binding_verified':False,'menu_verified':False,
                'remaining':'Kiểm kiểu, nhãn, thứ tự, giá trị mặc định/phạm vi và nối vào thuật toán; đây là giá trị của lượt đã chạy.'})
            if name in by_name:
                binding=by_name[name]
                inputs[-1].update(default_verified=binding['default_verified'],
                    original_memory_binding_verified=binding['original_memory_binding_verified'],
                    verified_default=binding['default_from_fresh_log'],native_input_rva=binding['candidate_rva'],
                    observed_representation=binding['representation'],
                    binding_evidence={'path':bindings_path.relative_to(ROOT).as_posix(),'sha256':sha(bindings_path)},
                    remaining='Còn kiểu khai báo/menu, nhãn hiển thị và tác dụng toàn bộ; đã kiểm vị trí lưu và mặc định.')
            if name in menu_settings:
                s=menu_settings[name]
                assert s['order']==i+1 and s['default']==inputs[-1]['verified_default']
                inputs[-1].update(visible_label=s['visible_label'],visible_label_verified=True,
                    ui_evidence={'path':menu_path.relative_to(ROOT).as_posix(),'sha256':sha(menu_path),
                                 'screenshots':s['label_screenshots']},
                    menu_verified=name in menu_choices,
                    enum_choices=menu_choices[name]['choices'] if name in menu_choices else None,
                    remaining='Còn kiểu khai báo chính xác/phạm vi số, ký tự nhãn bị ẩn và tác dụng toàn bộ; đã đọc nhãn/thứ tự/mặc định và bảy menu trong MT5 riêng.')
        assert len(inputs)==observed['count']
        unknown_native=sorted({a['address'] for f in functions for a in f['native_address_calls'] if a['label'] is None})
        result={'bot':bot,'function_count':len(functions),'code_sha256':meta['code_sha256'],'captured_data_sha256':meta['data_sha256'],
            'c_source':source.relative_to(ROOT).as_posix(),'c_source_sha256':sha(source),'function_table_address':meta['function_table_address'],
            'functions':functions,'inputs':inputs,'input_evidence_sha256':sha(folder/'tham-so-quan-sat.json'),
            'known_strings':len(strings),'unlabelled_native_addresses':unknown_native,
            'analysis_gate':'INCOMPLETE: inventoried captured functions/observed inputs; detailed semantics and full EX5 coverage remain unproven.',
            'limitations':['Không chứng minh mọi hàm của EX5 đã được thực thi/chụp.','Tên vai trò là mô tả phần nhìn thấy; chưa chốt toàn bộ nhánh.','Số điều kiện là số trong mã C trung gian, không phải độ bao phủ mã máy.','Lựa chọn mặc định/menu và tài nguyên gốc chưa được kiểm đủ.','Lời gọi gián tiếp còn cần nối với API thật.']}
        target=out/f'bot-{bot}.json';target.write_text(json.dumps(result,ensure_ascii=False,indent=2),encoding='utf-8');all_bots.append(result)
        lines=[f'# Bản đồ bot {bot}', '',f'{len(functions)} hàm trong bản chụp, {len(inputs)} dòng cài đặt đã quan sát. Đây là danh sách kiểm, chưa phải xác nhận phân tích xong toàn bộ EX5.','',
            '| Vị trí gốc | Phần nhìn thấy | Nguồn hiện có | Trạng thái |','|---|---|---|---|']
        for f in functions:
            rel=os.path.relpath(ROOT/f['source'],out).replace('\\','/')
            original=f'[{f["rva"]}]({rel}#L{f["line"]})';reco=f['reconstructed']['path'].split('/')[-1] if f['reconstructed'] else '—'
            status='Có phép kiểm thành phần; chưa kiểm toàn bộ hàm' if f['component_proof'] else 'Chưa dựng/kiểm đủ'
            lines.append(f'| {original} | {f["role"]} | {reco} | {status} |')
        lines+=['','## Toàn bộ dòng cài đặt đã quan sát','','Mặc định/vị trí lưu đã có phép so riêng. Nhãn và menu được thêm khi có bằng chứng cửa sổ; kiểu khai báo chính xác và tác dụng toàn bộ vẫn cần kiểm. Giá trị cũ của lượt có ghi đè chỉ giữ trong JSON.','',
            '| Thứ tự | Tên gốc | Nhãn đã đọc | Mặc định đã kiểm | Vị trí lưu |','|---|---|---|---|---|']
        for row in inputs:
            value=json.dumps(row.get('verified_default',row['observed_value']),ensure_ascii=False).replace('|','&#124;')
            lines.append(f'| {row["order"]} | `{row["name"]}` | {row.get("visible_label","chưa đọc trực tiếp")} | `{value}` | `{row.get("native_input_rva","chưa nối")}` |')
        lines+=['','## Chỗ chưa rõ','','- Lời gọi tới hàm nội bộ chưa có trong bảng: '+str(sum(len(f['unresolved_callees']) for f in functions))+'.',
            '- Địa chỉ gọi ngoài chưa có nhãn: '+(', '.join(unknown_native) or 'không thấy trong các lời gọi địa chỉ trực tiếp được quét')+'.',
            '- Chưa chốt đầy đủ cách nối các hàm với sự kiện MT5, toàn bộ lựa chọn và tài nguyên.',
            '- Các chi tiết lời gọi, chuỗi, biến dùng chung và phép kiểm nằm trong tệp JSON cùng tên.','']
        (out/f'bot-{bot}.md').write_text('\n'.join(lines),encoding='utf-8')
    summary={'bots':[{'bot':b['bot'],'functions':b['function_count'],'observed_input_rows':len(b['inputs']),'unlabelled_native_addresses':len(b['unlabelled_native_addresses'])} for b in all_bots],
             'tool_sha256':sha(Path(__file__)),'analysis_complete':False,'outputs':{p.name:sha(p) for p in out.iterdir() if p.is_file()}}
    (out/'summary.json').write_text(json.dumps(summary,ensure_ascii=False,indent=2),encoding='utf-8');print(json.dumps(summary,ensure_ascii=False))
if __name__=='__main__':main()
