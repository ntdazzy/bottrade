# Viết chương trình kiểm phần đầu quản lý bot 3

Cùng dự án khôi phục nguồn bot của người dùng. Codex đã phân tích
đoạn gốc và đang giao một Claude khác viết header. Bạn viết chương
trình MQL5 kiểm độc lập và công cụ Python. Không EX5/C/capture, không
lệnh/MT5/Git/kỹ năng lồng nhau; chỉ đọc nguồn và mô tả, ghi trong thư
mục TASK này. Đọc AGENTS.md rồi đúng mô tả mới:
`dich-nguoc/khoi-phuc/bot-cua-toi-3/phan-tich/dong-vi-the/management-prelude-20261025-r2/contract.md`.

Đầu ra: `Bot3ManagementPreludeCheck.mq5`, `check-management-prelude.py`,
`SUMMARY.md`. Codex chép lần lượt vào Scripts/bot-cua-toi-3 và tests/.
Header ứng viên đang được viết ở
`claude-thuc-hien/bot3-management-prelude-20261025-r2/Bot3ManagementPrelude.mqh`.
Nếu nó chưa có, viết theo chữ ký dự kiến trong contract rồi ghi chỗ
cần nối, không dừng chờ. Tận dụng bộ kiểm bot1 tại
`bot-cua-toi-1/tests/check-management-prelude.py` và
`bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/Bot1ManagementPreludeCheck.mq5`;
không sửa chúng. Chỉ phục hồi và kiểm ba chức năng ở contract, không
điều phối/vòng lệnh ngoài. Trước khi viết, đọc contract thật, tránh
chép lỗi shift/cờ của bot1 sang bot3.

## Tệp ca chung

Giữ protocol gần mẫu bot1 nhưng có BA nhóm nến, shift riêng:
magic `0x4d505233`, version1, countint32. Mỗi ca lần lượt:
`<3iQ2q2i5i7d3i2dq6q7i9d` rồi ba chuỗi như mẫu bot1.

- id,buy,scenario (scenario==0); ticketuint64; typelong,magiclong;
  expected_magic,enabledint; digits[5]int; sl,tp,open,volume,unit,stop,take;
  tick_ok,0,0; bid,ask; openedlong; times[6]long;
  candle_on[3]byte được ghi int32, timeframes[3]byte ghi int32, shiftbyte
  ghiint32; closes[6]double; opens[3]double; symbol/position_symbol/comment.
- Chuỗi `<2i` (nullflag,UTF16length) + UTF16LE, có chữ Việt, emoji,
  NULL và trống như mẫu.
- Kết quả percase giống mẫu bot1 `<iiQi5Q3q2Q2i2QiQ`: id,accepted,
  last_ticket,present,sl,tp,ticket_number,open,volume,opened,type,magic,
  commenthash,symbolhash,commentnull,symbolnull,bid,ask,calls,orderedhash.
- Ghi cả sl/tp sau khi bổ sung mức. Nếu vé0 phải xuất 0 cho toàn
  position và flags NULL theo zero initialization (mẫu bot1).
- Hash lời gọi 5×uint64 mỗi sự kiện giống mẫu bot1:1digits,2ticket,
  3PositionDouble,4Integer,5String,6Tick,7Print,8Modify,9TryClose,
  10iTime,11iClose,12iOpen. Cấp boolhelperfalse, tickreply như case.
  Hàm TryClose giả chỉ ghi vé, không đọc thêm tài khoản/gửi lệnh.
  Nguồn thật PHẢI dùng TryClose; macro chỉ trong Script kiểm.

## Native phía Python (Codex đã chốt ranh giới)

Dùng entry.Original(3) từ cong-cu/kiem-gia-vao-bot-1-3.py; tái dùng
string allocation/free cơ sở, extra API như bộ kiểm bot1. Hằng mapping:

- func mua32f60,bán37590; dừng accepted trước33b73/38194;
  dừng rejected tại330a0/330a3/330ca hoặc376d0/376d3/376f7.
- global magic6d564,enabled6d520,stop6d588,take6d590,unit73dd8;
  candleflags6d29e/6d2a0/6d2a2,frames6d29d/6d29f/6d2a1,shift6d29c;
  symbol74958,last_ticket74838,tick74790 (+8Bid,+16Ask);
  double scratch1d6e48,string scratch1d6e3c.
- local tại ranh giới: slXMM8,tpXMM7,ticketXMM9,openXMM6,volumeXMM13;
  commentdescriptor RSP+90 cả hai; symboldescriptor RSP+80 mua,+58 bán;
  openedlong ởcase, type/magic cũng từcase. Xem mẫu để xử lý zero vé.
- API runtime là địa chỉ enginebase+ các RVA như mẫu bot1; `call()`
  phải đặt scratch vào địa chỉ BOT3 trên. Bẫy child32a90=8 và47d20=9,
  ghiđốisốrồi giảlậpreturnkhôngchạyhelper (đãkiểmriêng).
- nativegiữnguyênmã hàm;khôngsửa nó, không dùng thuậttoánMQL làm đápán.
- PositionsTotal trả1 ởphầntiền tố,nhưngkhôngcầnso nóvớihàmđọcmộtvé
  trongScript. Ghi đúng phạmvi so từng phần, chưakiểm vòng ngoài.

## Phép kiểm cần có

Sinh các ca theo mẫu bot1; thêm cả ba cờ/khung/shift0,1,2,255, ba
nhóm đều đủ điều kiện để chứng minh không thoát sau đóng nhóm đầu;
giácloseđọclạikhác; NaN,±inf,±0 ởcôngthức; vé64âm/lớn; digits
kháccủa5lầnđọc; lọcloại/magiclow32/enable; tickfalsevẫnlọctiếp.
Khoảng500–1000ca đủ phân biệt các nhánh mới, khôngnângsốchođẹp.

Python command `prepare|original|mql5|compare NEW_RUN [--build BUILD]`.
Lưu `bot-cua-toi-3/bang-chung/kiem-quan-ly-vi-the/NEW_RUN`, khôngghiđè.
Ràngbuộcsource/helper/tool/analysis/originalSHAđúng;đọckếtquả
đúngshape/id/EOF;status(0,count);mỗi ca so đầyđủ trạngthái vàorderedhash.
MQL5 chạy riêng `.local/mt5-bot3-thread-20261025`, giao dịch/DLL tắt.
Compile từbiênnhận đúngtarget/errorswarningsint0/EX5hash/privatecopy.
ROOT=HOME.parent vớiPythonnằmtrong bot3/tests/ nhưmẫu.
Đừng mởbinarygốc đểviết; Codex sẽrunchươngtrìnhnative sau.

Giữ nhỏ,gần mẫu,dùngHàmconđãcó,khônglớpkiểmthửchung. Không tự ghi
phép chạy đã đạt khi chưa có output. `whole_bot_complete=false`,
`whole_manager_complete=false`, `prefix_only=true`.
