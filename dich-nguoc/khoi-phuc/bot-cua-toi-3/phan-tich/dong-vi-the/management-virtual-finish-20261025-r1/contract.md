# Bot 3: kết thúc nhánh ảo, mô tả trước khi viết

Chủ dự án khôi phục nguồn bot đã mất. EX5 SHA-256
ee063d3d87490afe24e2f4ce85f6b05659320e297b102efd70207f71ca2feb83,
base 0x17156250000. Codex đọc trực tiếp instructions của hai hàm
0x32f60/0x37590 trong ../management-20261025-r1/analysis.json.
Chỉ phần cuối nhánh ảo; không bỏ khóa, không sửa EX5 hay MT5 chính.

## Giao diện và dữ liệu

Mỗi phiên chỉ viết phần được giao. Không tự ghép vòng quản lý hoặc hàm chốt
ảo đã được giao ở nơi khác. Dùng Bot3RoundPrice, không NormalizeDouble.
Đầu vào position dùng Bot3ManagedPosition trong Bot3ManagementPrelude.mqh;
table dùng Bot3VirtualStopState trong Bot3VirtualStops.mqh.

Các biến chung là tham chiếu: P current_level=double[0x6d670],
T current_take=double[0x724a0], unit=double[0x73dd8],
gap=double[0x73ab0], freeze=double[0x744a8],
tick.bid/ask=0x74798/0x747a0, strategy_index=uint32[0x74934].
levels[] trỏ bảng mua 0x74110 hoặc bán 0x73df0, chỉ số hợp lệ 0..8.
position.open_price là XMM6 lúc vào, tp là XMM7 lúc vào.
zero=XMM11, initial_stop=XMM10, initial_take=XMM9,
cached_ticket_number=XMM12 là double của LONG vé đã đổi ở phần mốc
(0x33bb1/0x381d2), không lấy lại vé chung.
selected_anchor là stack mua+78/bán+88.
copied_step là double chung[0x74428]. Counter int32[0x74430], tăng có cuộn.

struct Bot3VirtualFinishSettings gồm đúng:
int high_low_enabled; uchar high_low_before_open; uchar high_low_shift;
double high_low_buy_shift; double high_low_sell_shift;
double lock_start; double lock_extra; int mode;
uchar step_enabled; double step_reference; int min_steps; double step_distance;
Ánh xạ lần lượt: 6d5d4,6d5c8,6d5dc,58488,584b0,6d5b8,6d5c0,6d514,
6d5f8,6d600,6d608,6d610. Hai shift là hằng đã chụp, không tự thay bằng đơn vị.
Không dùng 6d3c0 trong ba đoạn này: địa chỉ đó thuộc đoạn khác.

## A. Cao/thấp

Hàm void Bot3AdvanceVirtualHighLow(const bool buy,const string &symbol,
const Bot3VirtualFinishSettings &settings,const double &unit,
const double &gap,const double &freeze,const Bot3ManagedPosition &position,
MqlTick &tick,const double &levels[],const uint &strategy_index,
double &current_level,bool &changed).

Mua bắt đầu 0x36667 (các cạnh tương đương 0x36736/36813), thân36749..36911;
bán bắt đầu3a97d, thân3a990..3aafe. Không nhận các đoạn xen giữa thuộc
slippage hoặc real→virtual. Không reset changed tại đầu/cuối.
Đây là các block theo cạnh, không phải mọi lệnh trong một khoảng liên tục:
36667→36674 JG36749 hoặc3667a JMP3691b; không đi qua3667f..36727.
Block3667f là thân tách của slippage đã kiểm riêng, không thuộc hàm A.

1. Chỉ tiếp nếu high_low_enabled>0. Đọc P và levels[index] trước POINT.
   limit=mua P+gap, bán P-gap; POINT là SymbolInfoDouble(symbol,SYMBOL_POINT).
   Mua yêu cầu limit+point<level1; bán level1<limit-point.
2. Đọc LẠI index và level2 sau POINT. Chấp nhận nếu mua level2<open,
   bán open<level2; hoặc (high_low_before_open&1)==0.
3. k=high_low_shift==0 ? 0.0 : (buy ? high_low_buy_shift : high_low_sell_shift).
   offset=k*unit vẫn tính cả 0*unit. Trước POINT thứ hai, chụp quote
   bid mua/ask bán và gap: mua limit=(quote-offset)-gap,
   bán limit=(offset+quote)+gap. Sau POINT yêu cầu mua level2<limit-point,
   bán limit+point<level2. Level2 không đọc lại tại phép so này.
4. Sau POINT thứ hai, đọc tick và freeze mới: bid<position.tp-freeze mua;
   freeze+position.tp<ask bán. Nếu đạt, changed=true rồi đọc lại index/level3
   và gán P=level3. Không sửa position, không Modify, Print, Stamp hay đóng.
Các lần đọc mua3677b/3679b/367b1/3688e/368b1/368fc;
bán3a9c2/3a9e2/3a9f7/3aa93/3aaa7/3aaeb.

## B. Khóa lời và bộ đếm

void Bot3AdvanceVirtualBreakEvenCounter(const bool buy,const string &symbol,
const Bot3VirtualFinishSettings &settings,const double &unit,
const double &gap,const double &freeze,const double selected_anchor,
const double &copied_step,const Bot3ManagedPosition &position,MqlTick &tick,
double &current_level,bool &changed,int &counter).

Mua3691b..36b19 với thân tách36f72..36fd4;
bán3aafe..3ad01 với thân tách3b162..3b1c7.
Hàm không làm bước chạm dừng/đóng, phần bao ngoài làm ngay sau hàm.

1. Nếu 0<lock_start và mode==2: chụp u=unit và quote (bid mua/ask bán).
   activation=lock_start*u; trigger=mua activation+open, bán open-activation.
   Yêu cầu trigger<quote mua, quote<trigger bán.
2. Trước POINT, offset=u*lock_extra; candidate=mua offset+open,
   bán open-offset; chụp old=P. Gọi POINT. Yêu cầu old+point<candidate mua,
   candidate<old-point bán.
3. Sau POINT đọc lại extra, quote và unit: offset=extra*unit;
   candidate=mua open+offset, bán open-offset.
   Yêu cầu mua gap+candidate<quote, bán quote<candidate-gap;
   rồi mua quote<tp-freeze, bán freeze+tp<quote. Đạt thì P=candidate,changed=true.
4. Nếu changed đang true (kể cả do phần trước), không chạy counter.
   Nếu false: chụp quote và old=P TRƯỚC đọc step_enabled.
   Chỉ khi step_enabled==1 mới tăng counter int32 có cuộn, đọc unit và
   step_distance. next=mua step_distance*unit+old, bán old-step_distance*unit.
5. Yêu cầu mua gap+next<quote, quote<tp-freeze;
   bán quote<next-gap, freeze+tp<quote. Nếu không đạt giữ counter đã tăng,
   P không đổi, changed=false.
6. Nếu step_reference bằng số 0 có thứ tự (+0 hoặc -0), bỏ điều kiện mốc.
   Nếu khác 0, kể cả NaN, yêu cầu mua selected_anchor+unit*copied_step<quote;
   bán quote<selected_anchor-unit*copied_step. CẢ HAI dùng selected_anchor;
   khác bot1 phía bán dùng raw reference. Unit ở đây là bản chụp tại bước4.
7. Nếu counter>=min_steps thì counter=0,P=next,changed=true; ngược lại
   giữ counter, P cũ, changed=false. Không Modify; không có lời gọi32a90
   trong đoạn này. Không sửa position.tp dù XMM7 gốc có thể là thanh ghi tạm.

## C. Lưu hai bảng

void Bot3StoreVirtualLevels(const string &symbol,const double initial_stop,
const double initial_take,const double &current_level,const double &current_take,
const double cached_ticket_number,Bot3VirtualStopState &table).

Mua36b19..36f5f, bán3ad01..3b14f, gồm thân ghi36f26/36f50 và3b116/3b140.
1. Hỏi digits1 rồi RoundPrice(initial_stop,digits1).
2. Hỏi digits2 rồi đọc P mới và RoundPrice(P,digits2).
3. Nếu hai giá bằng có thứ tự, bỏ ghi dừng; NaN tính là khác.
   Nếu khác: hỏi digits3 rồi đọc LẠI P và làm tròn. Sau đó mới kiểm
   table.guard==1 (byte73450). Quét500 hàng đầu→cuối, chỉ ghi rows[row][1]
   ở hàng ĐẦU có rows[row][0]==cached_ticket_number có thứ tự. Không thêm
   hàng, không sửa vé/thời gian/guard/P, không hỏi số vé đang mở.
4. Sau phần dừng, đọc T mới. Chỉ nếu0<T: hỏi digits tiếp rồi làm tròn
   initial_take; hỏi digits tiếp rồi đọc T mới làm tròn. Nếu bằng có thứ
   tự, xong. Nếu khác: hỏi digits tiếp rồi đọc LẠI T và làm tròn, kiểm
   table.guard==1 rồi quét500 hàng take_rows ghi cột[1] ở vé khớp đầu tiên.
   Không kiểm lại0<T sau các API digits. Không sửa T, vé, guard hay thêmhàng.
Bảng dừng500×24byte từ6d680; bảng chốt500×16byte từ70560.
Không dùng MathIsValidNumber để bỏ NaN; véNaN không khớp số nào.
Không reset changed và không quay về mode; cuốiảo mua36f5f→330a3,
bán3b14f→376d3. Các ghi36835/3aa2e→kiểmmode thuộc nhánh thật khác.

## Phần bao ngoài và giới hạn

Sau A và B, nếu P>=bid mua hoặc ask>=P bán có thứ tự thì làm mới Tick,
gọi TryClose47d20, bỏ bool Tick, không lưu hai bảng. Ngược lại gọi C.
Cuối vòng aggregate giữ true nếu trước đótrue hoặc changed/closed.
Phần bao ngoài và kiểm chạy sẽ làm sau; chưa coi các đề xuất là đã đạt.
Phải biên dịch, so native/MQL5, kiểm biên/NaN/counteroverflow,
đọc trước/sau API và toàn hàng hai bảng. Chưa phải toàn bot.
