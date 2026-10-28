"""Cố ý làm sai phép nối khởi động để kiểm bộ kiểm có bắt được lỗi.

generate tạo Script kiểm sai; run RUN --build BUILD --source-run RUN --fault
FAULT chạy bản sai trong MT5 riêng và so với kết quả gốc của lượt nối đúng.
"""
import argparse, hashlib, importlib.util, json, re, shutil, struct, subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
GOOD = ROOT / "cong-cu" / "kiem-noi-khoi-dong-bot-1.py"
NAME_RE = re.compile(r"[a-z0-9-]{1,48}\Z")

def load_good():
    spec = importlib.util.spec_from_file_location("good_join", GOOD)
    mod = importlib.util.module_from_spec(spec); spec.loader.exec_module(mod); return mod

def sha(path): return hashlib.sha256(path.read_bytes()).hexdigest()

def validate_name(value, label):
    if not value or not NAME_RE.fullmatch(value): raise ValueError("BAD_"+label.upper())

def validate_closure(good, script, receipt, terminal):
    src_root=ROOT/"bot-cua-toi-1"/"source"/"MQL5"
    closure=good.pub.closure(script,src_root)
    build=json.loads(receipt.read_text(encoding="utf-8-sig"))
    for path in closure:
        rel=path.relative_to(src_root).as_posix(); digest=sha(path)
        if build["sources_sha256"].get(rel)!=digest or sha(terminal/"MQL5"/rel)!=digest: raise ValueError("SOURCE_CLOSURE_CHANGED "+rel)
    binary=terminal/"MQL5"/script.relative_to(src_root).with_suffix(".ex5")
    archived=receipt.parent/script.with_suffix(".ex5").name
    if sha(binary)!=build["binary_sha256"] or sha(archived)!=build["binary_sha256"]: raise ValueError("BINARY_CHANGED")
    return closure,build,binary,archived

def tape_records(raw):
    if len(raw)<12: raise ValueError("TAPE_HEADER")
    magic,version,count=struct.unpack_from("<3i",raw,0); pos=12; records=[]
    for expected in range(count):
        if pos+8>len(raw): raise ValueError("TAPE_TRAILING")
        ident,size=struct.unpack_from("<2i",raw,pos); pos+=8
        if ident!=expected or size<0 or pos+size>len(raw): raise ValueError("TAPE_RECORD")
        records.append((ident,raw[pos:pos+size])); pos+=size
    if pos!=len(raw): raise ValueError("TAPE_TRAILING")
    return (magic,version,count),records

def render():
    good = load_good()
    source = good.render()
    source = source.replace('input string CheckRun="";', 'input string CheckRun="";\ninput int JoinFault=0;', 1)
    source = source.replace('bot1-startup-joined\\\\', 'bot1-startup-joined-negative\\\\')
    marker = '      Result='+good.CALL+';'
    replacement = '''      double old_lots[8];for(int i=0;i<8;i++)old_lots[i]=Panel.lots[i];
      uint old_index=P.strategy_index;double old_start=P.native_62530;ulong old_ticket=LastTicket;
      Bot1InitializeTradingState(Inputs,P,Magic,Entry,Nfp,Interest,Cpi,Manager,Queue,Levels,MinimumSpread,FridayClosed,Panel.lots,LastTicket,State);
      if(JoinFault==1)for(int i=0;i<8;i++)Panel.lots[i]=old_lots[i];
      if(JoinFault==2)P.strategy_index=old_index;
      if(JoinFault==4)LastTicket=old_ticket;
      if(JoinFault==3)
         Result=Bot1InitializeStartupTail(OrderComment,Inputs.symbol,P.strategy_index,old_start,P.calendar,TailBars,Show,Tester,HistoryWindow,Magic,Seed,Balance,Panel,Events,Windows,Selection,LastTicket,LastHour,Wins,Losses,TailState);
      else if(JoinFault==5)
         Result=Bot1InitializeStartupTail(P.comment,Inputs.symbol,P.strategy_index,P.native_62530,P.calendar,TailBars,Show,Tester,HistoryWindow,Magic,Seed,Balance,Panel,Events,Windows,Selection,LastTicket,LastHour,Wins,Losses,TailState);
      else
         Result=Bot1InitializeStartupTail(OrderComment,Inputs.symbol,P.strategy_index,P.native_62530,P.calendar,TailBars,Show,Tester,HistoryWindow,Magic,Seed,Balance,Panel,Events,Windows,Selection,LastTicket,LastHour,Wins,Losses,TailState);'''
    if marker not in source: raise RuntimeError("JOIN_CALL_MARKER_NOT_FOUND")
    source = source.replace(marker, replacement, 1)
    return source

def generate():
    path = ROOT / "bot-cua-toi-1" / "source" / "MQL5" / "Scripts" / "bot-cua-toi-1" / "Bot1StartupPostPreparationNegativeCheck.mq5"
    if path.exists(): raise RuntimeError("SOURCE_EXISTS")
    path.write_text(render(), encoding="utf-8", newline="\n")
    print(path)

def run_case(run, build, source_run, fault):
    good=load_good(); require = good.require
    validate_name(run,"RUN"); validate_name(build,"BUILD"); validate_name(source_run,"SOURCE_RUN")
    if fault not in {"control","reset-lots","reset-index","old-start-lots","reset-ticket","wrong-comment"}: raise ValueError("BAD_FAULT")
    fault_num={"control":0,"reset-lots":1,"reset-index":2,"old-start-lots":3,"reset-ticket":4,"wrong-comment":5}[fault]
    base=ROOT/"bot-cua-toi-1"/"bang-chung"/"kiem-quan-ly-vi-the"
    src=base/source_run; out=base/run
    if out.exists(): raise RuntimeError("RUN_EXISTS")
    good_identity=good.identity(); baseline=json.loads((src/"baseline.json").read_text())
    source_receipts=[json.loads((src/(name+"-run.json")).read_text()) for name in ["original","mql5"]]
    for record in [baseline]+source_receipts:
        for key,value in good_identity.items():
            require(record.get(key)==value,"SOURCE_IDENTITY_CHANGED "+key)
    rows=good.cases(); require((src/"cases.bin").read_bytes()==good.encode(rows) and sha(src/"cases.bin")==baseline["inputs_sha256"],"SOURCE_CASES_CHANGED")
    for name,record in zip(["original","mql5"],source_receipts):
        require(sha(src/(name+"-results.bin"))==record["result_sha256"] and sha(src/"sdk-tape.bin")==record["sdk_tape_sha256"],"SOURCE_RUN_HASH_CHANGED")
    require(source_receipts[0]["result_sha256"]==source_receipts[1]["result_sha256"],"SOURCE_RESULTS_DIFFER")
    out.mkdir(parents=False)
    shutil.copyfile(src/"cases.bin",out/"cases.bin")
    script=ROOT/"bot-cua-toi-1"/"source"/"MQL5"/"Scripts"/"bot-cua-toi-1"/"Bot1StartupPostPreparationNegativeCheck.mq5"
    terminal=ROOT.parent/".local"/"mt5-bot1-thread-20261025"
    receipt=ROOT/"bot-cua-toi-1"/"bang-chung"/"bien-dich"/build/"bien-nhan.json"
    closure,b,binary,archived=validate_closure(good,script,receipt,terminal)
    require(b["target"]=="Scripts/bot-cua-toi-1/Bot1StartupPostPreparationNegativeCheck.mq5" and b["errors"]==b["warnings"]==0,"BUILD_NOT_CLEAN")
    files=terminal/"MQL5"/"Files"/"bot1-startup-joined-negative"/run; files.mkdir(parents=True,exist_ok=False); shutil.copyfile(src/"cases.bin",files/"cases.bin")
    preset=terminal/"MQL5"/"Presets"/("startup-negative-"+run+".set"); ini=terminal/("startup-negative-"+run+".ini")
    preset.write_text(f"CheckRun={run}\nJoinFault={fault_num}\n",encoding="utf-16")
    ini.write_text(f"[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-1\\Bot1StartupPostPreparationNegativeCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n",encoding="utf-16")
    p=subprocess.Popen(f'"{terminal/"terminal64.exe"}" /portable /config:"{ini}"',cwd=terminal,creationflags=subprocess.CREATE_NO_WINDOW)
    try: code=p.wait(timeout=150)
    except subprocess.TimeoutExpired:
        p.terminate()
        try: p.wait(timeout=20)
        except subprocess.TimeoutExpired: p.kill(); p.wait(timeout=20)
        raise RuntimeError("MT5_TIMEOUT")
    require(code==0 and (files/"script-status.bin").read_bytes()==struct.pack("<2i",0,len(good.cases())),"SCRIPT_FAILED")
    for name in ["mql5-results.bin","sdk-tape.bin","script-status.bin"]: shutil.copyfile(files/name,out/name)
    original=src/"original-results.bin"; ours=out/"mql5-results.bin"
    head_a,recs_a=tape_records(original.read_bytes()); head_b,recs_b=tape_records(ours.read_bytes())
    require(head_a==head_b==(good.MAGIC,1,len(rows)),"RESULT_HEADER")
    result_ids={i for i,(a,b) in enumerate(zip(recs_a,recs_b)) if a!=b}
    head_a,recs_a=tape_records((src/"sdk-tape.bin").read_bytes()); head_b,recs_b=tape_records((out/"sdk-tape.bin").read_bytes())
    require(head_a==head_b==(good.MAGIC,1,len(rows)),"TAPE_HEADER")
    tape_ids={i for i,(a,b) in enumerate(zip(recs_a,recs_b)) if a!=b}
    detected=sorted(result_ids|tape_ids); detected_total=len(detected)
    if fault=="control": require(detected_total==0,"CONTROL_DIFF")
    else: require(detected_total>0,"FAULT_NOT_DETECTED")
    report={"source_run":source_run,"fault":fault,"cases":len(rows),"detected":detected_total,"result_records_different":len(result_ids),"tape_records_different":len(tape_ids),"first_ids":detected[:5],"source_sha256":sha(script),"tool_sha256":sha(Path(__file__)),"good_identity":good_identity,"cases_sha256":sha(out/"cases.bin"),"build_receipt_sha256":sha(receipt),"binary_sha256":sha(binary),"archived_binary_sha256":sha(archived),"source_result_sha256":sha(original),"negative_result_sha256":sha(ours),"source_tape_sha256":sha(src/"sdk-tape.bin"),"negative_tape_sha256":sha(out/"sdk-tape.bin"),"closure_sha256":{p.relative_to(ROOT).as_posix():sha(p) for p in closure},"whole_bot_complete":False,"full_ea":False}
    (out/"negative-controls.json").write_text(json.dumps(report,ensure_ascii=False,indent=2)+"\n",encoding="utf-8")
    print(json.dumps({key:report[key] for key in ["source_run","fault","cases","detected","result_records_different","tape_records_different","first_ids"]},ensure_ascii=False))

def main():
    p=argparse.ArgumentParser(); p.add_argument("mode",choices=["generate","run"]); p.add_argument("run",nargs="?"); p.add_argument("--build"); p.add_argument("--source-run"); p.add_argument("--fault",choices=["control","reset-lots","reset-index","old-start-lots","reset-ticket","wrong-comment"]); a=p.parse_args()
    if a.mode=="generate": generate(); return
    if not a.run or not a.build or not a.source_run or not a.fault: raise SystemExit("run cần RUN, --build, --source-run và --fault")
    run_case(a.run,a.build,a.source_run,a.fault)
if __name__=="__main__": main()
