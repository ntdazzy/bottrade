# Bot 3: ba phần dời dừng ảo — mô tả đã đối chiếu, 20261025-r1

Bối cảnh: khôi phục nguồn độc lập của The Gold Reaper MT5 từ EX5 của chủ dự án.
SHA-256 gốc: ee063d3d87490afe24e2f4ce85f6b05659320e297b102efd70207f71ca2feb83.
Đầu mã 0x17156250000. Nguồn bằng chứng: ../management-20261025-r1/analysis.json,
functions.c, native-guards.txt. Codex đã đọc trực tiếp các lệnh bên dưới.
Đây là các đoạn trong hai hàm 0x32f60/0x37590, chưa phải cả hàm hay EA.
Không phân tích/viết lại nhánh chưa nằm trong mô tả này. Giữ nguyên tệp gốc.

## Dữ liệu chung và quy ước

Giá hiện tại P: double 0x6d670; đơn vị U: double 0x73dd8.
Giá mua lại B=tick.bid: 0x74798; giá bán lại A=tick.ask: 0x747a0.
Giá mở O=xmm6, chốt lời T=xmm7, khối lượng V=xmm13.
Mốc đã chọn H: stack mua+0x78/bán+0x88. Mốc tham chiếu R=xmm15.
Cờ changed=r12b; đầu vào/đầu ra, giữ nguyên khi không có tác động.
Tên vị trí dùng const string&, các thiết lập double/int dùng const &.
P và MqlTick truyền tham chiếu để dịch vụ kiểm có thể thay đổi chúng.
Dùng Bot3ManagedPosition từ Bot3ManagementPrelude.mqh. API MT5 chuẩn.
Mọi phép so là có thứ tự: nếu NaN thì điều kiện <,>,<= phải không tự đảo thành phủ định sai.
Không tự kiểm hợp lệ hoặc nắn giá, không thêm làm tròn ngoài nơi chỉ rõ.
Số thực tính theo thứ tự từng biểu thức bên dưới; không gộp đổi thứ tự cộng/trừ.

## A. Bot3AdvanceTimedVirtualStop

Mua: 0x35f8f..0x35fd3, thân 0x3667f..0x36727.
Bán: 0x3a21a..0x3a2f7.
activation=double 0x6d5e8, distance=double 0x6d5f0,
delay_seconds=int32 0x7449c, freeze_distance=double 0x744a8.
Hàm void, tham số theo thứ tự:
bool buy, const string &symbol, const double &unit,
const double &activation, const double &distance,
const int &delay_seconds, const double &freeze_distance,
const Bot3ManagedPosition &position, MqlTick &tick,
double &current_level, bool &changed.

- Chỉ tiếp tục khi 0.0<activation. Gọi TimeCurrent đúng một lần.
- So now >= position.opened+(long)delay_seconds; đọc delay sau TimeCurrent.
- Chụp level=current_level và quote=(buy?tick.bid:tick.ask) TRƯỚC
  SymbolInfoDouble(symbol,SYMBOL_POINT). API chỉ gọi khi hai điều kiện trước đạt.
- Sau API, đọc offset=distance*unit.
- Mua: ((level+point)+offset)<quote, sau đó tick.bid<(position.tp-freeze_distance).
  Nếu đủ: changed=true, current_level=tick.bid-offset.
- Bán: quote<((level-point)-offset), sau đó (freeze_distance+position.tp)<tick.ask.
  Nếu đủ: changed=true, current_level=offset+tick.ask.
- Dùng offset đã tính, không đọc lại sau phép kiểm cuối. Không làm tròn, gửi hoặc in.

## B. Bot3AdvanceDistanceVirtualStop

Mua: 0x35fd3..0x36189, bán: 0x3a2f7..0x3a4af.
trail_distance=double 0x6d598, trail_step=0x6d5b0,
trail_start=0x6d5a0, trail_limit=0x6d5a8.
volumes=double[] 0x73ac0, strategy_index=uint32 0x74934.
threshold_a=double 0x73ab0, threshold_b=double 0x744a8.
Close helper 0x47d20 là Bot3TryClosePosition, không phải Bot3ClosePosition 0x2e370.
ticket là ulong đã chuyển từ ticket_number qua long ở phần mốc trước đó
(mua stack+0x40, bán stack+0x48); truyền riêng const ulong ticket.

Hàm bool, tham số theo thứ tự:
bool buy, const string &symbol, const double &unit,
const double &trail_distance, const double &trail_step,
const double &trail_start, const double &trail_limit,
const double anchor, const Bot3ManagedPosition &position,
MqlTick &tick, const double &volumes[], const uint &strategy_index,
double &current_level, bool &changed,
Bot3PendingRequestState &state, Bot3TradeSendOptions &options,
const ulong &deviation, const double &threshold_a, const double &threshold_b,
const ulong ticket.

- Nếu !(0.0<trail_distance), trả false, không gọi API.
- Chụp level=current_level, quote=buy?tick.bid:tick.ask trước API POINT.
- Sau API: đọc trail=trail_distance; U=unit một lần; offset=(trail_step+trail)*U.
- Mua kiểm theo thứ tự: offset+(level+point)<quote;
  trail_start*U+anchor<tick.bid; current_level<trail_limit*U+position.open_price.
  Nếu đủ, current_level=tick.bid-trail*U.
- Bán kiểm: quote<((level-point)-offset);
  tick.ask<(anchor-trail_start*U); (position.open_price-trail_limit*U)<current_level.
  Nếu đủ, current_level=trail*U+tick.ask.
- Tính volume=Bot3RoundPrice(volumes[strategy_index]*0.0,2); đặt changed=true.
- Chỉ khi volume<position.volume mới gọi SymbolInfoDouble(symbol,SYMBOL_VOLUME_MIN).
  Nếu minimum<=volume, gọi Bot3TryClosePosition(state,options,deviation,
  tick.bid,tick.ask,threshold_a,threshold_b,ticket); trả true.
  Nếu không gọi helper thì false.
- Không có điều kiện chốt lời ở phần này. Chỉ xét chỉ số mảng hợp lệ trong kiểm đoạn;
  không thêm luật chặn/chỉnh index. Chưa chứng minh lỗi mảng hay toàn hàm.
- Thứ tự làm tròn/cờ/đọc minimum phải giữ nguyên kể cả volume bằng 0/NaN.

## C. Bot3AdvanceSlippageVirtualStop

Mua: 0x364e2..0x36667 (đích ra 0x3672c/0x36736/0x36813).
Bán: 0x3a803..0x3a97d.
enabled=int32 0x6d4e8, distance_passed byte ở local 0x5c mua/0x54 bán,
trail_distance=double 0x6d4f8, start_distance=0x6d4f0,
limit_distance=0x6d500; freeze_distance=double 0x744a8.
Mốc reference R là double đã chụp trước phần này, không lấy lại từ bảng.
Hàm void, tham số theo thứ tự:
bool buy, const string &symbol, const double &unit,
const int &enabled, const bool distance_passed,
const double reference, const double &trail_distance,
const double &start_distance, const double &limit_distance,
const double &freeze_distance, const Bot3ManagedPosition &position,
MqlTick &tick, double &current_level, bool &changed.

- Chỉ khi enabled==1, distance_passed và 0.0<trail_distance mới tiếp.
- Chụp level=current_level, quote=buy?tick.bid:tick.ask trước API POINT.
- Sau API, đọc U=unit một lần, offset=trail_distance*U.
- Mua lần lượt: offset+(level+point)<quote;
  reference+start_distance*U<tick.bid;
  tick.bid<(position.tp-freeze_distance);
  current_level<(U*limit_distance+position.open_price).
- Bán: quote<((level-point)-offset);
  tick.ask<(reference-start_distance*U);
  (freeze_distance+position.tp)<tick.ask;
  (position.open_price-U*limit_distance)<current_level.
- Nếu đủ gọi Print đúng một lần: mua "Slippage control active",
  bán "Slippage controle active" (lỗi chữ của gốc phải giữ).
  Đã đọc trực tiếp chuỗi descriptor 0x5e1f0/0x5e3c0 từ bản chụp gốc.
- Sau Print: changed=true; ĐỌC LẠI trail_distance, unit và tick.
  Mua current_level=tick.bid-trail_distance*unit;
  bán current_level=trail_distance*unit+tick.ask.
- Không Modify, không Close, không làm tròn hoặc xóa changed khi không đạt.

## Kiểm còn phải làm

Ba bản đề xuất cần biên dịch, so lệnh gốc theo ranh giới với dữ liệu cố định,
ca sát ngưỡng, NaN/vô cực, dữ liệu đổi sau TimeCurrent/POINT/Print và gọi helper.
Các đoạn chưa có phép chạy đối chứng. Không gọi là đã kiểm hoặc đã hoàn thành EA.

