# Bảng nối nguồn MQL5 bot 1 – r2

Ngày 26/10/2026. Nguồn: `dich-nguoc/khoi-phuc/bot-cua-toi-1/source/MQL5`
(44 header trong `Include/bot-cua-toi-1`, 48 tệp trong `Scripts/bot-cua-toi-1`).
Nền: bảng r1 (`bot1-integration-map-20261026-r1`, giữ nguyên). Chi tiết chữ ký, dòng, đối số: `integration-map.json`.
Chưa biên dịch, chưa chạy, chưa so với bản gốc. `whole_bot_complete: false`.

## 1. Kết luận

- 44 header sản phẩm, 97 hàm, 20 struct, 0 enum. Mỗi header có đúng một mục trong `modules`.
- **Đã có header ≠ đã nối chương trình chính.** Cả 44 header nằm trong nguồn chính, nhưng chưa header nào được chương trình chính gọi: không có `Experts/`, Include không có `OnInit/OnTick/OnDeinit`, không có `input`.
- Khối mới `Bot1PendingSubmission.mqh` đã có trong nguồn chính. Khối này đã gọi `Bot1MarginGuard` (dòng 65), `Bot1ValidateVolume` (84) và `Bot1OpenPending` (51, qua `Bot1SendPendingEntry`). Chính `Bot1SubmitPendingAfterPrice` chưa có nơi gọi.
- 21 hàm đầu chuỗi chưa có nơi gọi (r1 ghi 21 nhưng danh sách r1 thật có 22; r2 bỏ MarginGuard, ValidateVolume và thêm SubmitPendingAfterPrice).
- Chỉ P1 (Script biên dịch chung 44 header) đủ điều kiện giao ngay. B1–B15 cần bên quản lý phân tích trước.

## 2. Thay đổi r1 → r2

| Mục | r1 | r2 |
|---|---|---|
| Header / hàm / struct | 43 / 94 / ghi 20 (thật 19) | 44 / 97 / 20 |
| Tệp Script | 46 | 48 (thêm PendingSubmissionCheck, PendingSubmissionApiCompile) |
| Liên kết đã có mã | L001–L144 | L001–L151 |
| Chuỗi | 8 (có chuỗi "Ký quỹ") | 8: thêm "Đặt lệnh chờ sau giá cơ sở", gộp chuỗi "Ký quỹ" vào đó |
| Hàm đầu chuỗi chưa có nơi gọi | ghi 21 (thật 22) | 21 |
| Liên kết thiếu | M01–M33 | M01–M37; sửa M05, M06, M12, M13, M15, M16, M17, M23–M26 |
| Dữ liệu trùng | D01–D27 | D01–D28 (mở rộng 13 mục), thêm F01–F02 (hàm trùng mẫu) |
| Ràng buộc | C1–C5 | C1–C7 |
| Phần giao tiếp | P1 (43 header), B1–B14 | P1 (44 header), B1–B15 (sửa B4, B5, B6) |

Nơi gọi mới trong Include:

| Hàm | Nơi gọi mới | Liên kết |
|---|---|---|
| Bot1MarginGuard | SubmitPendingAfterPrice:65, chỉ khi `check_free_margin!=0` | L146 |
| Bot1ValidateVolume | SubmitPendingAfterPrice:84 | L149 |
| Bot1OpenPending | SendPendingEntry:51 (thêm vào PendingQueue:64 đã có) | L145 |
| Bot1RoundPrice | SubmitPendingAfterPrice:74, 78, 82 | L147 |
| Bot1TradeErrorText | SubmitPendingAfterPrice:119 | L151 |

Đề xuất cũ của khối (`bot1-pending-submission-20261026-r1`, `bot1-pending-check-20261026-r1`) chỉ ghi là lịch sử; r2 không đọc và không dùng chúng. Nguồn dùng là tệp trong `source/`.

## 3. Khối Bot1PendingSubmission (nguồn chính, chưa nối chương trình chính)

Include: PriceLevels:4, Margin:5, VolumeValidation:6, TradeSend:7, TradeErrors:8. `#endif` ở dòng 126.

`Bot1PendingSubmissionSettings` (9-18), 14 trường, không có chú thích địa chỉ gốc:
`symbol, comment` (string); `check_free_margin, omit_real_sl_tp, virtual_expiration` (uchar); `strategy_magic` (int); `expiration` (datetime); `unit, stop_distance, take_distance, minimum_stop_price, minimum_freeze_price, ask, bid` (double).

| Hàm | Dòng | Đầu vào chụp | Đọc lại qua tham chiếu | Ghi |
|---|---|---|---|---|
| SubmissionDifference | 20-25 | left, right | – | trả left−right; giữ NaN của toán hạng |
| SendPendingEntry | 28-54 | first_attempt, buy, price, sl, tp | settings, volumes, strategy_index | trade, options qua OpenPending |
| SubmitPendingAfterPrice | 55-125 | buy, base_price | settings, volumes, strategy_index | results, error_count, trade, options |

Thứ tự trong `Bot1SubmitPendingAfterPrice`:

| Bước | Dòng | Việc |
|---|---|---|
| 1 | 61-70 | `check_free_margin!=0`: MarginGuard(symbol, BUY/SELL, volumes[strategy_index]); sai thì Print "Free margin not sufficient for setting order..." và thoát |
| 2 | 72-74 | DIGITS; giá = RoundPrice(unit*(buy ? 0.0 : -0.0)+base_price) |
| 3 | 75-78 | DIGITS; SL mua = SubmissionDifference(base_price,(stop_distance+0.0)*unit), bán = (stop_distance+0.0)*unit+base_price; làm tròn |
| 4 | 79-82 | DIGITS; TP mua = take_distance*unit+base_price, bán = SubmissionDifference(base_price,take_distance*unit); làm tròn |
| 5 | 83-84 | ValidateVolume(symbol, volumes[strategy_index]); sai thì thoát |
| 6 | 86-87 | `limit=ACCOUNT_LIMIT_ORDERS`; `limit!=0 && OrdersTotal()>=limit` thì thoát (OrdersTotal chỉ gọi khi limit≠0) |
| 7 | 88-99 | Mua: cần `ask<price-minimum_freeze_price` rồi `ask<price-minimum_stop_price`. Bán: cần `minimum_freeze_price+price<bid` rồi `minimum_stop_price+price<bid`. Viết `!(a<b)` nên NaN làm thoát |
| 8 | 100 | SendPendingEntry(true,…) → OpenPending BUY_STOP/SELL_STOP |
| 9 | 102-111 | Được chấp nhận: ô đầu tiên có `results[row][0]==0.0` nhận `[0]=1.0`, `[1]=base_price` chưa làm tròn; hết ô thì thoát |
| 10 | 114-118 | Bị từ chối: `while(GetLastError()==132)` Sleep(2500) rồi SendPendingEntry(false,…), bỏ kết quả, không giới hạn số lần |
| 11 | 119-124 | TradeErrorText(GetLastError(), error_count); Print "error: '…' when setting entry order" (in cả khi một lần thử lại thành công) |

`SendPendingEntry`: lần đầu đọc `omit_real_sl_tp` rồi `expiration`; lần thử lại đọc ngược lại. `omit_real_sl_tp!=0` thì gửi SL/TP bằng 0.0. Comment, volume, symbol, magic, virtual_expiration đọc mới mỗi lần gửi; giá/SL/TP không tính lại.

Còn thiếu: nơi gọi (M34), bên điền settings (M35), nguồn `base_price` (M36), chủ thể `volumes/strategy_index/results/error_count/trade/options` (M37).

## 4. Header sản phẩm (44)

Tên hàm bỏ tiền tố `Bot1`. "Chưa có nơi gọi" = không hàm nào trong Include gọi tới. Dấu * = cập nhật trong r2.

| Tệp | Hàm | Struct | Include trực tiếp | Chưa có nơi gọi | Đầu tệp tự ghi |
|---|---|---|---|---|---|
| Bot1PriceLevels* | RoundPrice:7, UpperLevel:18, LowerLevel:54 | – | – | UpperLevel, LowerLevel | – |
| Bot1EntryLevels | NearbyPending:7, EntryPrice:26, EntryLevel:31 | – | PriceLevels:5 | EntryLevel | – |
| Bot1EntryProfiles | LoadEntryProfile:14 | EntryProfile:5 | – | – | – |
| Bot1DistanceSettings* | PrepareDistances:82 | DistanceInputs:8, DistanceContext:35, Distances:46 | EntryProfiles:7 | PrepareDistances | – |
| Bot1BaseDistances | LoadBaseDistances:7 | – | DistanceSettings:6 | LoadBaseDistances | – |
| Bot1Volume | PrepareVolume:44 | VolumeSettings:7, VolumeContext:18, VolumeState:32 | PriceLevels:6 | – | – |
| Bot1Currency | CurrencyPair:5, ConvertCurrency:17 | – | – | – | – |
| Bot1AccountVolume | PrepareAccountVolume:7 | – | Volume:5, Currency:6 | – | – |
| Bot1Withdrawal | UpdateWithdrawals:5 | – | – | – | – |
| Bot1AccountStateVolume | PrepareAccountStateVolume:7 | – | AccountVolume:5, Withdrawal:6 | PrepareAccountStateVolume | – |
| Bot1Margin* | MarginAvailable:5, MarginGuard:18 | – | – | – (MarginGuard ← PendingSubmission:65) | – |
| Bot1NewsBlock | SelectNewsBlock:9 | NewsBlockState:4 | – | SelectNewsBlock | – |
| Bot1AccountInitialization | InitializeAccountState:4 | – | – | InitializeAccountState | – |
| Bot1StrategySelection | SelectStrategies:24 | StrategySelectionInput:7, StrategySelectionState:19 | – | SelectStrategies | – |
| Bot1VolumeValidation* | ValidateVolume:5 | – | – | – (ValidateVolume ← PendingSubmission:84) | – |
| Bot1AmericanDST | AmericanDST:4 | – | – | AmericanDST | – |
| Bot1Filling | ExpirationAllowed:4, CheckFilling:20 | – | – | – | – |
| Bot1PendingRequest | PreparePendingRequest:13 | PendingRequestState:5 | Filling:4 | – | – |
| Bot1TradeSend* | SendTrade:12, OpenPending:23 | TradeSendOptions:6 | TradeMessages:4, PendingRequest:5 | – (OpenPending ← PendingQueue:64, PendingSubmission:51) | – |
| Bot1TradeMessages | TradeUnsignedText:4, TradeSignedText:5, TradeOrderTypeText:6, TradePriceText:17, FormatTradeResult:27, FormatTradeRequest:66 | – | – | – | – |
| Bot1TradeErrors* | TradeErrorText:4 | – | – | – | – |
| Bot1PendingQueue* | QueueSum:24, QueueProduct:30, QueueDifference:36, SendQueuedPending:42, RetryQueuedPending:76, ProcessPendingQueue:89 | PendingQueue:6, PendingQueueContext:13 | TradeSend:4, TradeErrors:5 | ProcessPendingQueue | – |
| Bot1OrderScan* | CountPendingKind:4, CountBuyPending:21, CountSellPending:25, CleanPendingResults:29 | – | – | CountBuy, CountSell, CleanPendingResults | – |
| Bot1OrderCancel | DeletePending:5 | – | TradeSend:4 | – | – |
| Bot1PendingSelection* | DeleteExtremePending:5, DeleteHighestBuyPending:39, DeleteLowestSellPending:44 | – | OrderCancel:4 | Highest, Lowest | – |
| Bot1PositionClose | ClosePosition:5, TryClosePosition:31 | – | TradeSend:4 | – | – |
| Bot1PositionSelection | CloseFilteredPositions:5, CloseFilteredBuyPositions:38, CloseFilteredSellPositions:45 | – | PositionClose:4 | FilteredBuy, FilteredSell | – |
| Bot1PositionModify | ModifyPosition:5 | – | TradeSend:4 | – | – |
| Bot1VirtualStops | DropClosedVirtualStops:14, VirtualStopLevel:44, VirtualStopDelayPassed:93, VirtualStopStamp:110 | VirtualStopState:7, `#define BOT1_VIRTUAL_STOP_ROWS 500`:5 | PriceLevels:4 | – | Verification is pending |
| Bot1HistorySort | HistorySort:4 | – | – | HistorySort (chỉ đệ quy) | – |
| Bot1ManagementPrelude | ReadManagementPosition:24, FillManagementInitialLevels:49, ManagementCandleTimeframe:72, CloseManagementCandle:77, ManagementCachedReference:99, StartVirtualManagement:131, AdvanceTimedVirtualStop:167, AdvanceDistanceVirtualStop:194, AdvanceSlippageVirtualStop:238 | ManagedPosition:10 | PriceLevels:5, PositionModify:6, PositionClose:7, VirtualStops:8 | – | phạm vi kiểm ở bằng chứng riêng |
| Bot1ManagementVirtualFinish | AdvanceVirtualHighLow:22, AdvanceVirtualBreakEvenCounter:50, StoreVirtualStop:105, FinishVirtualManagement:125 | VirtualFinishSettings:6 | Prelude:4 | – | – |
| Bot1ManagementRealTimed | AdvanceTimedBuyStop:7, AdvanceTimedSellStop:37 | – | Prelude:4, Messages:5 | – | – |
| Bot1ManagementMessages | PrintManagementError:8 | – | TradeErrors:5 | – | Candidate only |
| Bot1ManagementRealDistance | AdvanceDistanceBuyStop:8, AdvanceDistanceSellStop:57 | – | Prelude:5, Messages:6 | – | – |
| Bot1ManagementRealStore | StoreRealStop:7 | – | Prelude:4, VirtualStops:5 | – | – |
| Bot1ManagementRealSlippage | AdvanceSlippageRealBuyStop:9, AdvanceSlippageRealSellStop:45 | – | Prelude:6, Messages:7 | – | so sánh chạy theo dõi riêng |
| Bot1ManagementRealHighLow | PrintHighLowError:10, AdvanceHighLowRealBuyStop:17, AdvanceHighLowRealSellStop:59 | – | Prelude:6, Messages:7 | – | Candidate only |
| Bot1ManagementRealCounter | AdvanceRealCounterBuyStop:7, AdvanceRealCounterSellStop:48 | – | Prelude:5 | – | – |
| Bot1ManagementRealLock | PrintRealLockError:10, AdvanceRealLockBuyStop:17, AdvanceRealLockSellStop:50 | – | Prelude:6, Messages:7 | – | Candidate only |
| Bot1ManagementRealStart | CloseRealStopHit:10, StartRealManagement:24 | – | Prelude:6, VirtualStops:7 | – | phạm vi kiểm ở bằng chứng riêng |
| Bot1ManagementRouter | CountManagementPositions:9, RoutePositionManagement:55 | – | PositionManagement:5 | RoutePositionManagement | – |
| Bot1PositionManagement | ManageOnePosition:71, ManagePositions:262 | PositionManagementSettings:18, PositionManagementState:53 | Prelude, VirtualFinish, RealStart, RealTimed, RealDistance, RealSlippage, RealHighLow, RealLock, RealCounter, RealStore (5-14) | – | phạm vi kiểm ở bằng chứng riêng |
| **Bot1PendingSubmission** (mới) | SubmissionDifference:20, SendPendingEntry:28, SubmitPendingAfterPrice:55 | PendingSubmissionSettings:9 | PriceLevels:4, Margin:5, VolumeValidation:6, TradeSend:7, TradeErrors:8 | SubmitPendingAfterPrice | – (ghi là thành phần, không phải EA) |

## 5. Script kiểm (48) – không phải mã dùng trong bot

46 Script của r1 giữ nguyên (xem bảng r1). Hai Script mới:

| Tệp | Loại | Hàm sản phẩm được gọi | Ghi chú |
|---|---|---|---|
| Bot1PendingSubmissionCheck.mq5 | Kiểm API giả | SubmitPendingAfterPrice (315) | 5 header include thật trước macro (7-11); macro 14-23 thay DIGITS, MarginGuard, ValidateVolume, AccountInfoInteger, OrdersTotal, OpenPending, Sleep, GetLastError, TradeErrorText, Print chỉ trong thân khối. RoundPrice, SubmissionDifference, SendPendingEntry chạy thật. Đổi ô tham chiếu ở 10 điểm biên API (87-99). Lần gửi thứ 5 dừng bằng lỗi 21 để chặn vòng thử lại. Thư mục `Files/bot1-pending-submission/<CheckRun>` |
| Bot1PendingSubmissionApiCompile.mq5 | Chỉ biên dịch | SubmitPendingAfterPrice (16, chỉ khi `InvokeFunctions=true`) | API thật; không chạy. Kéo 9 header |

Dữ liệu khởi tạo trong Script (`T.magic`, `O.*`, `V[i]`, bảng có NaN/±inf/−0.0) là dữ liệu kiểm, không phải bằng chứng khởi tạo của bot.

## 6. Liên kết đã có mã

151 cặp gọi trực tiếp ở `confirmed_links`. Có mã gọi không có nghĩa là đã nối chương trình chính.

| Chuỗi | Lời gọi (tệp:dòng) | Đầu chuỗi có nơi gọi? |
|---|---|---|
| Khối lượng theo tài khoản | AccountStateVolume:15 → UpdateWithdrawals; :27 → PrepareAccountVolume; AccountVolume:16 → ConvertCurrency (khi mode 999); :17 → PrepareVolume | Không |
| Hồ sơ khoảng cách | BaseDistances:9 → LoadEntryProfile; PrepareDistances không có lời gọi nối | Không |
| Mức vào | EntryLevels:44-77 → EntryPrice, RoundPrice, NearbyPending | Không |
| Lệnh chờ từ hàng đợi | PendingQueue:100/106 → SendQueuedPending; :64 → OpenPending; TradeSend:28 → PreparePendingRequest (→ CheckFilling 28/79, ExpirationAllowed 85); TradeSend:29 → SendTrade; lỗi: PendingQueue:101/107 → Retry → TradeErrorText 86 | Không |
| **Lệnh chờ sau giá cơ sở** (mới) | PendingSubmission:65 → MarginGuard (→ MarginAvailable, Margin:30); :74/78/82 → RoundPrice; :76/81 → SubmissionDifference; :84 → ValidateVolume; :100/117 → SendPendingEntry; :51 → OpenPending (→ PreparePendingRequest, SendTrade); :119 → TradeErrorText | Không |
| Hủy lệnh chờ cực trị | PendingSelection:42/47 → DeleteExtremePending; :29 → DeletePending; OrderCancel:46 → SendTrade | Không |
| Đóng theo lọc | PositionSelection:43/50 → CloseFilteredPositions; :35 → TryClosePosition; PositionClose:45/56 → ClosePosition (→ CheckFilling 19, SendTrade 29) | Không |
| Quản lý vị thế | Router:85/87/99/105 → ManagePositions; PositionManagement:276 → ManageOnePosition; 78-251 → 26 bước | Không |

Thứ tự trong `Bot1ManageOnePosition` và bảng trường settings quản lý → tham số: không đổi so với r1 (xem r1 mục 4 hoặc L118–L143 trong JSON).

## 7. Liên kết còn thiếu (chi tiết M01–M37 trong JSON)

| Nhóm | Thiếu |
|---|---|
| Chương trình chính | EA, OnInit/OnTick/OnDeinit, thứ tự gọi các khối đầu chuỗi (M01) |
| Input | tên, kiểu, mặc định, thứ tự (M02); Bot1PendingSubmissionSettings không có chú thích địa chỉ gốc |
| Không có nơi gọi | LoadBaseDistances, PrepareDistances, Upper/LowerLevel, EntryLevel, SelectStrategies, InitializeAccountState, PrepareAccountStateVolume, SelectNewsBlock, AmericanDST, ProcessPendingQueue, CountBuy/SellPending, CleanPendingResults, DeleteHighest/LowestPending, CloseFilteredBuy/Sell, HistorySort, RoutePositionManagement, **SubmitPendingAfterPrice** (M03–M20, M34) |
| Có nơi gọi nhưng đầu chuỗi chưa nối | MarginGuard, ValidateVolume (M12, M13) |
| Giá trị đầu vào | Bot1PositionManagementSettings, Bot1PositionManagementState, Bot1TradeSendOptions, deviation, Bot1DistanceContext, Bot1VolumeContext, Bot1PendingQueueContext (M21–M24); **Bot1PendingSubmissionSettings** (M35); **base_price** (M36) |
| Chủ thể trạng thái | Bot1VolumeState, Bot1PendingQueue, Bot1PositionManagementState, last_times[8], peak_key/time_key/last_check/last_deal_time, Bot1PendingRequestState (M23, M25); **volumes, strategy_index, results, error_count, trade, options của khối mới** (M37) |
| Đường luồng | đặt lệnh mới: đoạn sau giá cơ sở đã có, đoạn trước giá cơ sở còn thiếu (M26); hiển thị (M27); thoát/khởi động lại/lưu (M28) |
| Đầu ra không ai đọc | confirmation_frame, toàn bộ Bot1Distances, converted_dd_balance, enabled_mask của VolumeContext (M29–M32) |
| Trạng thái chấp nhận | 3 header tự ghi Candidate only, 1 header ghi Verification is pending (M33) |

## 8. Cùng loại dữ liệu, chưa có bằng chứng dùng chung ô

| Mã | Dữ liệu | Nơi xuất hiện | Bằng chứng |
|---|---|---|---|
| D01 | lot_scale | Distances ↔ VolumeSettings | cùng chú thích 0x682f0; không có mã nối |
| D02–D05 | 0x624c8, 0x624d0, 0x624e4, 0x62520 | Distances ↔ VirtualFinishSettings | cùng địa chỉ, khác tên; D04 khác cả vai trò |
| D06–D07* | dừng lỗ, chốt lời | Distances, PositionManagementSettings, VolumeContext (chỉ D06), QueueContext, **PendingSubmissionSettings** | chỉ giống tên |
| D08 | dời dừng | Distances ↔ PositionManagementSettings | chỉ giống tên |
| D09* | unit | Distances, PositionManagementSettings, QueueContext, EntryLevel, **PendingSubmissionSettings** | chỉ giống tên |
| D10–D11 | số dư; enabled_mask | xem JSON | chỉ giống tên |
| D12* | results[100][2] | PendingQueue.results, **results của SubmitPendingAfterPrice**, CleanPendingResults, DeleteExtremePending | cột 0: cờ chấp nhận 1.0 (Queue, Submission) ↔ ticket (OrderScan, PendingSelection) |
| D13–D15* | bộ đếm lỗi, magic, chỉ số chiến lược | thêm error_count, strategy_magic, strategy_index của khối mới | không; riêng D14 có mã chép magic vào state.magic (PendingRequest:18, PositionClose:36) |
| D17* | khối lượng | thêm volumes[strategy_index] của khối mới | không |
| D19* | freeze | thêm minimum_freeze_price ↔ Distances.freeze_min_price | chỉ giống tên |
| D20–D21* | hạn lệnh, virtual_expiration | thêm expiration, virtual_expiration của khối mới | không; kiểu khác nhau |
| D25* | giá hiện tại | thêm settings.ask/bid của khối mới | không |
| D27* | đối tượng yêu cầu | thêm trade của khối mới | không |
| D28 (mới) | khoảng dừng tối thiểu | Distances.stop_min_price ↔ minimum_stop_price | chỉ giống tên |
| F01 (mới) | hàm hiệu giữ NaN | QueueDifference (PendingQueue:36-41) ↔ SubmissionDifference (PendingSubmission:20-25) | Grep: thân giống từng dòng |
| F02 (mới) | vòng thử lại lỗi 132 | RetryQueuedPending (PendingQueue:76-88) ↔ PendingSubmission:114-124 | cùng mẫu, khác hàm gửi và bộ đếm |

## 9. Nhóm chương trình chính

| Nhóm | Đã có | Đủ để viết? | Còn thiếu |
|---|---|---|---|
| Khởi động | InitializeAccountState, LoadBaseDistances, PrepareDistances, SelectStrategies | Chưa | OnInit, thứ tự, input, DistanceContext, khởi tạo trạng thái (gồm results/error_count/volumes của khối mới), dừng khi lỗi |
| Mỗi lần nhận giá | router nhánh per-tick, PrepareAccountStateVolume, ProcessPendingQueue, NewsBlock, DST | Chưa | OnTick, thứ tự và điều kiện từng khối, thời điểm gọi SubmitPendingAfterPrice |
| Đổi nến | router nhánh đổi nến (Router:74-90) | Chưa | chủ thể last_times, nguồn timeframe |
| Chuẩn bị chiến lược | 5 khối như r1 | Chưa | ngẫu nhiên hóa/chỉnh thêm, 7 input còn lại, ánh xạ Distances sang settings quản lý và settings khối mới |
| Điều kiện vào | EntryLevel, Upper/Lower, NearbyPending, News, DST, Count; cổng trong SubmitPendingAfterPrice (ký quỹ, khối lượng, giới hạn lệnh, cổng giá) | Chưa – thiếu thuật toán | quyết định vào lệnh, chọn chiều, nguồn base_price, thứ tự các cổng ngoài khối, ngưỡng theo chiều |
| Đặt/sửa/hủy/đóng | chuỗi gửi đã có mã, gồm đặt sau giá cơ sở | Chưa | đoạn trước giá cơ sở, nơi gọi khối mới, chủ thể requests/trade/options/deviation, điều kiện hủy/đóng |
| Hiển thị | không có | Chưa – không có bằng chứng | toàn bộ |
| Lưu/khởi động lại/thoát/lỗi | GV HighestBalance/LastBalanceOp, văn bản lỗi, in lỗi đặt lệnh (PendingSubmission:119-124) | Chưa | OnDeinit, lưu bảng dừng ảo/hàng đợi/cache/results, luồng lỗi |

## 10. Phần viết mã tiếp theo

**P1 – sẵn sàng giao.** Script `Bot1AllHeadersCompile.mq5`: `#property strict`, 44 dòng
`#include "../../Include/bot-cua-toi-1/<tệp>"` theo thứ tự `modules`, `OnStart` chỉ `Print("Bot1AllHeadersCompile: compile only")`.
Không thêm hàm, không gọi hàm sản phẩm, không thay API, không sửa header.
Lý do: chưa Script nào include đủ 44 header trong một đơn vị dịch (FlowCheck kéo 22, PendingSubmissionApiCompile kéo 9).
Kiểm: biên dịch bằng MetaEditor của MT5 kiểm thử riêng, đạt khi 0 lỗi, ghi lại cảnh báo. Không phải EA, không gọi là đã nối.

**Cần bên quản lý phân tích trước khi giao** (giao diện đã biết, còn thiếu dữ kiện hoặc thuật toán):

| Mã | Phần | Cần chốt |
|---|---|---|
| B1 | Điền Bot1PositionManagementSettings | nguồn từng trường; giải D02–D05 |
| B2 | Nối khởi tạo tài khoản với khối lượng | D10, last_check đầu, thời điểm gọi, nguồn VolumeContext/Settings/mode |
| B3 | Vòng chuẩn bị 8 chiến lược | ánh xạ bit↔index, thứ tự gốc, DistanceContext, ngẫu nhiên hóa |
| B4* | Điều kiện vào và nơi gọi SubmitPendingAfterPrice | thuật toán vào lệnh, chọn chiều, nguồn base_price, thứ tự cổng ngoài khối, chủ thể trạng thái, thời điểm gọi |
| B5* | Chủ thể hàng đợi lệnh chờ | ai ghi orders, ai bật enabled, nguồn context, results dùng chung không (D12) |
| B6* | Đếm/hủy lệnh chờ cực trị | ngưỡng, điều kiện, mảng results, quan hệ với ACCOUNT_LIMIT_ORDERS (PendingSubmission:86-87) |
| B7 | Đóng theo lọc | magic_base, nghĩa reference/threshold |
| B8 | Nơi gọi router | vòng chiến lược, cờ tick/bar, timeframe, last_times, levels, volumes, guard, cờ zero-ticket; cờ bản quyền chỉ đọc |
| B9 | Cổng tin tức/DST/spread | nguồn sự kiện, nơi dùng |
| B10 | HistorySort | mảng nào, khi nào |
| B11 | Hiển thị | toàn bộ bằng chứng |
| B12 | Thoát/khởi động lại/lưu/lỗi | OnDeinit, lưu trạng thái (gồm results), luồng lỗi |
| B13 | Khai báo input | tên, kiểu, mặc định, thứ tự |
| B14 | Trạng thái 4 header tự ghi ứng viên/đang chờ | bằng chứng chấp nhận |
| B15 (mới) | Điền Bot1PendingSubmissionSettings | nguồn 14 trường, thời điểm chụp ask/bid, quan hệ D06–D28 |

## 11. Ràng buộc khi ghép (C1–C7)

- C1: tham số `const &` và struct settings/shared được đọc lại trong thân hàm; truyền chính ô trạng thái, chỉ giữ các điểm nguồn tự chụp. Khối mới tự chụp `buy, base_price`, giá/SL/TP (73-82), `margin_volume`, `volume`, `limit`, `ask`, `bid`. Script kiểm đọc lại bằng cách đổi ô ở biên API (RealTimedCheck:32-37, RealBlocksCheck:56-65, FlowCheck:324-328, PendingSubmissionCheck:84-99).
- C2: giữ nguyên kiểu như nguồn (magic int/ulong, virtual_expiration bool/uchar, khung int/ENUM_TIMEFRAMES, ticket double/long/ulong).
- C3: `license_valid` chỉ đọc (Router:66); không sửa khóa bản quyền.
- C4: `Bot1PrepareDistances` trả false thì dừng thiết lập; `Bot1PrepareVolume` trả false thì không dùng trạng thái.
- C5: hàm gửi lệnh dùng API thật; chỉ kiểm trong MT5 riêng hoặc qua Script thay API. Script ApiCompile chỉ để biên dịch.
- C6 (mới): `SendPendingEntry` đọc lại settings và `volumes[strategy_index]` mỗi lần gửi, kể cả thử lại; giá/SL/TP không tính lại; thứ tự đọc omit/expiration khác giữa lần đầu và thử lại.
- C7 (mới): giữ hành vi thử lại như nguồn: không giới hạn khi lỗi 132, Sleep 2500, bỏ kết quả thử lại, không ghi results khi chỉ lần thử lại thành công, vẫn in lỗi sau vòng thử lại.
