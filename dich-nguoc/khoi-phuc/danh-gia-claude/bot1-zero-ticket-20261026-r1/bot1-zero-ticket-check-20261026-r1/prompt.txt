# Cập nhật bên gọi và bộ kiểm cho cờ vé0 đầu

Viết bản đầy đủ của4tệp vào CHÍNH thư mục đề xuất này, kèm SUMMARY.md:
`Bot1PositionManagementFlowCheck.mq5`, `Bot1ManagementRouterCheck.mq5`,
`Bot1PositionManagementApiCompile.mq5`, `Bot1ManagementRouterApiCompile.mq5` (tệp cuối mới).
Không sửa nguồn chính, Git/MT5, chạy lệnh, đọc EX5/mã máy/phân tích hay tạo tác tử.
Đọc4tệp cần thiết hiện hành trongsource/MQL5/Scripts/bot-cua-toi-1 và
đề xuất2header tại `../bot1-first-zero-ticket-20261026-r1/` để dùng API mới.
Opus5.5max, ultracode được yêu cầu. Codex tự kiểm và đối chiếu gốc.

Codex đã xác minh: cờ mới first_zero_ticket_changed giữ đầu vào ngữ cảnh
của hàm quản lý tại nhánh vé đầu0. Router nhánh từng lần nhận giá truyền
true; nhánh nến mới nhận cờ bool tường minh từ bên gọi. Đây không phải luật
mới, không đoán cờ ngoài ngữ cảnh đã nêu.

## 1. Chương trình kiểm toàn vòng quản lý hiện hành

Giữ mọi dữ liệu/mã ca/công thức/mock/định dạng xuất/phiên bản1/2/3.
Thêm hai inputbool mặc địnhfalse: `FirstZeroTicketChanged`, `ExecuteManagementRouter`.
Ở chỗ include Bot1PositionManagement.mqh trong vùng macro hiện hành, thay
include đó thành `Bot1ManagementRouter.mqh`. Header Router include Manager;
các macroSDK/helper vẫn tác động cả hai, vẫn undef đủ như cũ. Không thêm
mock thay manager hoặc tính kết quả mong đợi.

Trong mỗi ca sauFInitialize/FWriteCasts, giữ lời gọi manager cũ khi
ExecuteManagementRouter=false, chỉ thêm tham số cuối FirstZeroTicketChanged.
Khi ExecuteManagementRouter=true, gọi router THẬT với:

- local ucharlicense_valid=1,tick_management=1,bar_override=0;
- local inttimeframe=15, longtimes[8] khởi0; capturedstrategyindex=(uint)FCase[15]
  NẾU trườngindexkhôngphải15trongScript thì dùng vị trí trườngindex đã định
  nghĩa hiện hành (đọc FInitialize để biết; không đoán). Có thể dùng
  FShared.strategy_index chụp NGAY trước lời gọi vì chưa có dịch vụ xen vào.
- dùng FCfg/FShared/FRequests/FOptions/FDeviation thật;
- buy_levels vàsell_levels phải làhai mảng8ô: ArrayInitialize(buy_levels,95.0),
  ArrayInitialize(sell_levels,105.0). Không chỉ truyền FLevels cho cả hai.
  Bộ ca hiện hành FLevels khởi95choBUY/105choSELL, đây là đúnghai bảng từngchiều.
- tham số cuối bar_first_zero_ticket_changed=FirstZeroTicketChanged (nhánh
  từng lần nhận giá không dùng nó; router tự truyềntrue). Không tự sửa
  kết quảreturned/đếm/SDK/giá/sốca cho chế độ này.

FWriteResult như cũ ghi giá trị sau cả router+manager; caller-chain dùng
cùng định dạng176byte khi bật haihàmcon. times/bar không xuất thêm vì
nhánh từng lần nhận giá cốđịnh vàcóbộkiểm riêng. Đừng đổi phiên bản chỉ vì
thêm input chọn cách gọi.

## 2. Chương trình kiểm router với manager giả

Thêm inputbool `FirstZeroTicketChanged=false`. Thêm tham số cuối bắt buộc
`const bool first_zero_ticket_changed` vàoFakeBot1ManagePositions giốngheader.
Không thay reply/logicmock theo cờ này: manager vẫn được cấp kết quả như cũ.
Chỉ kiểm cờ được truyền đúng: nếu nhánh từng lần nhận giá đã được chọn
(case.tick_management!=0 && case.bar_override==0 && case.profile!=0),
mock mong cờtrue; nhánh nến mới mong FirstZeroTicketChanged. Dùng lời
kiểm này CHỈđể báo lỗi truyền tham số, không tạo đáp ánreturned. Profile7
cóTotallần2trả0 nhưng vẫn lànhánh từng lần nhận giá. Không thêm truy vấn SDK.

Lời gọi Bot1RoutePositionManagement cuốiScript thêmtham số cuối
FirstZeroTicketChanged; giữ nguyên mọi ca/định dạng, hash1.536ca vàdịchvụgiả.

## 3. Biên dịch API thật

Bot1PositionManagementApiCompile.mq5: chỉ cập nhật hai lời gọi thêmcờfalse
tường minh. Đây là mẫu biên dịch, không ngữ cảnh EA thật. Giữguard
InvokeFunctionsfalse vàcommentkhôngchạy.

Tạo Bot1ManagementRouterApiCompile.mq5 theo cùngkiểu: includeRouter;
inputbool InvokeFunctionsfalse, OnStartreturnngay khi tắt. Khi bật chỉ
chuẩn bịstruct/mảng8ô và localucharvalid/tick/override,intframe,ulongdev;
gọiroutermộtlần với index0vàcờbarfalse tườngminh đểkiểmkhaibáo API.
Đừng chạyscript hoặc mặcđịnhbật nó. Khôngđặtđơn lệnh.

Chỉ sửa những chỗ cần thiết, không đổi định dạng/logicngoài yêu cầu.
SUMMARYghiđúngchưabiên dịch/chạy vàCodexcầnsohai ngữcảnhfalse/true,
router1.536ca vàchuỗirouter→thânmanager→hàmconsử a/đóng/bảng.
