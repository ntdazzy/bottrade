# Bảng nối nguồn MQL5 bot 3 — r2 (đọc ngày 2026-10-26)

Gốc nguồn: `dich-nguoc/khoi-phuc/bot-cua-toi-3/source/MQL5`. Nền là bảng r1 (`../bot3-integration-map-20261026-r1/`, giữ nguyên). Chi tiết đầy đủ (chữ ký nguyên văn, dòng bắt đầu/kết thúc, 240 vị trí gọi, dữ liệu đọc/ghi) nằm trong `integration-map.json`. Bảng dưới bỏ tiền tố `Bot3` ở tên hàm cho gọn; Lxx là dòng bắt đầu chữ ký.

- `whole_bot_complete: false`. Chưa có chương trình chính: 51 header không có `OnInit/OnTick/OnDeinit`, không có `input`, không có mã hiển thị (tìm kiếm ở r1; header đổi ở r2 cũng không có).
- r2 đọc lại `Bot3PendingSubmission.mqh` (nay 112 dòng, có thêm `SubmissionDifference`) và 2 Script `Bot3PendingSubmissionCheck.mq5`, `Bot3PendingSubmissionApiCompile.mq5`. 50 header còn lại giữ số liệu r1, không đọc lại.

### Trạng thái nối của khối PendingSubmission

| Mức | Trạng thái | Bằng chứng |
|---|---|---|
| Header có trong cây Include chính | có (`main_source_merged`) | tệp `Include/bot-cua-toi-3/Bot3PendingSubmission.mqh`; theo giao việc, bên quản lý đã ghép và kiểm riêng (phiên này không xác minh kết quả kiểm) |
| Gọi hàm của header khác | có, 6 header include L4-9 | CL-021..CL-026 |
| Nối vào chương trình chính | **chưa** | `SubmitPendingAfterPrice` không có nơi gọi trong mã sản phẩm (ML-16); chưa có EA |

## 1. Khối sản phẩm (51 header, 99 hàm, 23 struct)

| # | Tệp (Include/bot-cua-toi-3/) | Hàm (dòng) | Kiểu khai báo | Include trực tiếp | Được gọi bởi mã sản phẩm |
|---|---|---|---|---|---|
| 1 | Bot3PriceLevels.mqh | RoundPrice L7, UpperLevel L18, LowerLevel L54 | – | – | RoundPrice: 29 hàm/19 tệp; Upper/Lower: **không** |
| 2 | Bot3TradeErrors.mqh | TradeErrorText L4 | – | – | PendingQueue, ManagementMessages, RealHighLow, RealLock, PendingSubmission (L105) |
| 3 | Bot3TradeMessages.mqh | TradeUnsignedText L4, TradeSignedText L5, TradeOrderTypeText L6, TradePriceText L17, FormatTradeResult L27, FormatTradeRequest L66 | – | – | TradeSend |
| 4 | Bot3Filling.mqh | ExpirationAllowed L4, CheckFilling L20 | – | – | PendingRequest, PositionClose |
| 5 | Bot3PendingRequest.mqh | PreparePendingRequest L13 | Bot3PendingRequestState | Filling | TradeSend |
| 6 | Bot3TradeSend.mqh | SendTrade L12, OpenPending L23 | Bot3TradeSendOptions | TradeMessages, PendingRequest | SendTrade: OrderCancel, PositionClose, PositionModify; OpenPending: PendingQueue, PendingSubmission (L39) |
| 7 | Bot3PositionModify.mqh | ModifyPosition L5 | – | TradeSend | Prelude, VirtualStart, 7 khối Real |
| 8 | Bot3PositionClose.mqh | ClosePosition L5, TryClosePosition L31 | – | TradeSend | TryClose: PositionSelection, Prelude, Virtual, VirtualTake, VirtualStart, VirtualFinishFlow, RealDistance, RealTake, RealStart, PositionManagement |
| 9 | Bot3PositionSelection.mqh | CloseFilteredPositions L5, CloseFilteredBuyPositions L38, CloseFilteredSellPositions L45 | – | PositionClose | **không** |
| 10 | Bot3OrderCancel.mqh | DeletePending L5 | – | TradeSend | PendingSelection |
| 11 | Bot3PendingSelection.mqh | DeleteExtremePending L5, DeleteHighestBuyPending L39, DeleteLowestSellPending L44 | – | OrderCancel | **không** |
| 12 | Bot3OrderScan.mqh | CleanPendingResults L4, AllowsPendingOrder L18 | – | – | Allows: PendingSubmission (L73); Clean: **không** |
| 13 | Bot3PendingQueue.mqh | QueueSum L24, QueueProduct L30, QueueDifference L36, SendQueuedPending L42, RetryQueuedPending L76, ProcessPendingQueue L89 | Bot3PendingQueue, Bot3PendingQueueContext | TradeSend, TradeErrors | **không** |
| 14 | Bot3Margin.mqh | MarginAvailable L5, MarginGuard L18 | – | – | MarginGuard: PendingSubmission (L53) |
| 15 | Bot3VolumeValidation.mqh | ValidateVolume L5 | – | – | PendingSubmission (L72) |
| 16 | Bot3PendingSubmission.mqh *(đã ghép; chưa nối chương trình chính)* | SubmissionDifference L21, SendPendingEntry L28, SubmitPendingAfterPrice L43 | Bot3PendingSubmissionSettings (L10-19) | PriceLevels, Margin, VolumeValidation, OrderScan, TradeSend, TradeErrors | SubmissionDifference: Submit L64/L69; SendPendingEntry: Submit L86/L103; SubmitPendingAfterPrice: **không** |
| 17 | Bot3EntryProfiles.mqh | LoadEntryProfile L14 | Bot3EntryProfile | – | BaseDistances |
| 18 | Bot3EntryLevels.mqh | NearbyPending L7, EntryPrice L26, EntryLevel L31 | – | PriceLevels | **không** |
| 19 | Bot3DistanceSettings.mqh | PrepareDistances L88 | Bot3DistanceInputs, Bot3DistanceContext, Bot3Distances | EntryProfiles | **không** |
| 20 | Bot3BaseDistances.mqh | LoadBaseDistances L7 | – | DistanceSettings | **không** |
| 21 | Bot3Preparation.mqh | PrepareStrategy L144 | Bot3PreparationInputs, Bot3PreparationState | EntryProfiles | **không** |
| 22 | Bot3StrategySelection.mqh | SelectStrategies L27 | Bot3StrategySelectionInput, Bot3StrategySelectionState | – | **không** |
| 23 | Bot3Currency.mqh | CurrencyPair L5, ConvertCurrency L17 | – | – | AccountVolume |
| 24 | Bot3Volume.mqh | PrepareVolume L49 | Bot3VolumeSettings, Bot3VolumeContext, Bot3VolumeState | PriceLevels | AccountVolume |
| 25 | Bot3AccountVolume.mqh | PrepareAccountVolume L7 | – | Volume, Currency | AccountStateVolume |
| 26 | Bot3Withdrawal.mqh | UpdateWithdrawals L5 | – | – | AccountStateVolume |
| 27 | Bot3AccountStateVolume.mqh | PrepareAccountStateVolume L7 | – | AccountVolume, Withdrawal | **không** |
| 28 | Bot3AccountInitialization.mqh | InitializeAccountState L4 | – | – | **không** |
| 29 | Bot3NewsBlock.mqh | SelectNewsBlock L9 | Bot3NewsBlockState | – | **không** |
| 30 | Bot3AmericanDST.mqh | AmericanDST L4 | – | – | **không** |
| 31 | Bot3HistorySort.mqh | HistorySort L6 | – | – | **không** (chỉ tự đệ quy L29) |
| 32 | Bot3VirtualStops.mqh | DropClosedVirtualStops L16, VirtualStopLevel L60, VirtualTakeLevel L110, VirtualStopDelayPassed L146, VirtualStopStamp L163 | Bot3VirtualStopState; `BOT3_VIRTUAL_STOP_ROWS 500` | PriceLevels | VirtualStart, RealStart |
| 33 | Bot3ManagementAnchor.mqh | PrepareManagementAnchor L17 | Bot3ManagementAnchorState | PriceLevels | PositionManagement |
| 34 | Bot3ManagementPrelude.mqh | ReadManagementPosition L24, FillManagementInitialLevels L49, ManagementCandleTimeframe L74, CloseManagementCandle L81 | Bot3ManagedPosition | PriceLevels, PositionModify, PositionClose | PositionManagement |
| 35 | Bot3ManagementMessages.mqh | PrintManagementError L8 | – | TradeErrors | RealTimed, RealDistance, RealTake, RealSlippage |
| 36 | Bot3ManagementRealStart.mqh | CloseRealStopHit L9, StartRealManagement L24 | – | Prelude, VirtualStops | PositionManagement |
| 37 | Bot3ManagementRealTimed.mqh | AdvanceTimedBuyStop L7, AdvanceTimedSellStop L37 | – | Prelude, Messages | PositionManagement |
| 38 | Bot3ManagementRealDistance.mqh | AdvanceDistanceBuyStop L7, AdvanceDistanceSellStop L55 | – | Prelude, Messages | PositionManagement |
| 39 | Bot3ManagementRealTake.mqh | AdvanceRealTakeBuy L7, AdvanceRealTakeSell L51 | – | Prelude, Messages | PositionManagement |
| 40 | Bot3ManagementRealSlippage.mqh | AdvanceSlippageRealBuyStop L8, AdvanceSlippageRealSellStop L48 | – | Prelude, Messages | PositionManagement |
| 41 | Bot3ManagementRealHighLow.mqh | PrintHighLowError L9, AdvanceHighLowRealBuyStop L18, AdvanceHighLowRealSellStop L62 | – | Prelude, Messages | PositionManagement |
| 42 | Bot3ManagementRealLock.mqh | PrintRealLockError L9, AdvanceRealLockBuyStop L20, AdvanceRealLockSellStop L54 | – | Prelude, Messages | PositionManagement |
| 43 | Bot3ManagementRealCounter.mqh | AdvanceRealCounterBuyStop L6, AdvanceRealCounterSellStop L45 | – | Prelude | PositionManagement |
| 44 | Bot3ManagementRealStore.mqh | StoreRealStop L8 | – | Prelude, VirtualStops | PositionManagement |
| 45 | Bot3ManagementVirtualStart.mqh | StartVirtualManagement L13 | – | Prelude, VirtualStops | PositionManagement |
| 46 | Bot3ManagementVirtual.mqh | AdvanceTimedVirtualStop L7, AdvanceDistanceVirtualStop L28, AdvanceSlippageVirtualStop L68 | – | Prelude | PositionManagement |
| 47 | Bot3ManagementVirtualTake.mqh | AdvanceVirtualTake L8 | – | Prelude | PositionManagement |
| 48 | Bot3ManagementVirtualFinish.mqh | AdvanceVirtualHighLow L23, AdvanceVirtualBreakEvenCounter L51, StoreVirtualLevels L116 | Bot3VirtualFinishSettings | Prelude, VirtualStops | VirtualFinishFlow |
| 49 | Bot3ManagementVirtualFinishFlow.mqh | FinishVirtualManagement L9 | – | VirtualFinish | PositionManagement |
| 50 | Bot3PositionManagement.mqh | ManageOnePosition L78, ManagePositions L272 | Bot3PositionManagementSettings, Bot3PositionManagementState | 15 header quản lý (L5-19) | BarGate |
| 51 | Bot3ManagementBarGate.mqh | ManageOnBarChange L10 | – | PositionManagement | **không** (đỉnh chuỗi quản lý) |

Ghi chú khối #16 (nguồn chính, 112 dòng):
- `SubmissionDifference` (L21-26): trả toán hạng NaN đầu tiên cộng `+0.0`, còn lại `left-right`. Thân giống `QueueDifference` (PendingQueue L36-41) nhưng khác tên, không gọi nhau.
- SL lệnh buy (L64) và TP lệnh sell (L69) đi qua `SubmissionDifference`; SL sell (L65) và TP buy (L68) là phép cộng trực tiếp.
- Cột 0 của `results` nhận kết quả gửi 1.0, không phải ticket (L93, chú thích L87); vòng thử lại lỗi 132 không giới hạn và bỏ kết quả (L100-104, chú thích L99).

Lịch sử: bản đề xuất `claude-thuc-hien/bot3-pending-submission-20261026-r2/Bot3PendingSubmission.mqh` chuyển sang `proposal_history` (status `superseded_history`). Theo lần đọc r1, bản này 105 dòng, không có `SubmissionDifference`. Không dùng bản này thay cho nguồn chính; r2 không đọc lại nó.

## 2. Chuỗi đã có mã trực tiếp (chi tiết từng dòng: `confirmed_links` CL-001..CL-123)

| Chuỗi | Lời gọi (tệp gọi: dòng) |
|---|---|
| Đặt lệnh chờ (đầu chuỗi chưa có nơi gọi: ML-16, ML-17) | SubmitPendingAfterPrice → MarginGuard L53, RoundPrice L62/66/70, SubmissionDifference L64/69, ValidateVolume L72, AllowsPendingOrder L73, SendPendingEntry L86/103 → OpenPending L39 → PreparePendingRequest (TradeSend L28) → CheckFilling L28/79, ExpirationAllowed L85; SendTrade (TradeSend L29) → FormatTradeResult L17, FormatTradeRequest L18 |
| Hàng đợi 100 lệnh | ProcessPendingQueue → SendQueuedPending L100/106 → OpenPending L64; RetryQueuedPending L101/107 → TradeErrorText L86 |
| Hủy lệnh chờ | DeleteHighest/LowestPending L42/47 → DeleteExtremePending → DeletePending L29 → SendTrade L46 |
| Đóng vị thế | CloseFilteredBuy/Sell L43/50 → CloseFilteredPositions → TryClosePosition L35 → ClosePosition L45/56 → CheckFilling L19, SendTrade L29 |
| Sửa SL/TP | ModifyPosition → SendTrade L24 |
| Quản lý vị thế | ManageOnBarChange → ManagePositions L24 (buy), L26 (sell) → ManageOnePosition L286 → Read L85, Fill L88, Candle L92, Anchor L96, đóng khẩn L116; nhánh real (mode≠2) L124-225; nhánh ảo L232-260 |
| Khối lượng | PrepareAccountStateVolume → UpdateWithdrawals L15, PrepareAccountVolume L27 → ConvertCurrency L16/18 (→ CurrencyPair), PrepareVolume L19 |
| Khoảng cách / mức vào | LoadBaseDistances → LoadEntryProfile L9; EntryLevel → EntryPrice, RoundPrice L72/77, NearbyPending L73 |

Thứ tự trong `SubmitPendingAfterPrice`: margin (L49-58, chỉ khi `check_free_margin!=0`) → DIGITS + giá L60-62 → DIGITS + SL L63-66 → DIGITS + TP L67-70 → khối lượng L71-72 → giới hạn lệnh L73 → ask/bid với `minimum_freeze_price` rồi `minimum_stop_price` L74-85 → gửi L86 → ghi `results` L88-98 hoặc thử lại L100-104 → in lỗi L105-110.

Liên kết trạng thái đã có mã (SL-01..SL-12): `Bot3PositionManagementState` là chủ sở hữu duy nhất có trong nguồn cho bảng anchor, bảng SL/TP ảo, open_tickets, current_stop/take, volumes[9], strategy_index, error_count, counter, last_ticket, tick; BarGate truyền cùng `shared` cho lượt buy rồi sell.

## 3. Liên kết còn thiếu (chi tiết: `missing_links`, 62 mục)

| Loại | Mã | Tóm tắt |
|---|---|---|
| Không có nơi gọi | ML-01..ML-16 (20 hàm) | ManageOnBarChange, PrepareStrategy, PrepareDistances/LoadBaseDistances, PrepareAccountStateVolume, InitializeAccountState, SelectStrategies, SelectNewsBlock, AmericanDST, HistorySort, Upper/LowerLevel, EntryLevel, ProcessPendingQueue, CleanPendingResults, DeleteHighest/Lowest, CloseFilteredBuy/Sell, SubmitPendingAfterPrice (L43) |
| Có nơi gọi trong header, chưa nối chương trình | ML-17 *(mới)* | MarginGuard L53, SubmissionDifference L64/69, ValidateVolume L72, AllowsPendingOrder L73, SendPendingEntry L86/103 → OpenPending L39. Không cần thêm liên kết giữa các header này; chuỗi chỉ chạy khi có nơi gọi SubmitPendingAfterPrice |
| Thiếu nguồn giá trị | ML-20..ML-38 | không có `input`; mọi trường Bot3PositionManagementSettings; giá trị đầu của state; levels[]; timeframe/strategy_index/last_times của BarGate; deviation; options; request state; orders/enabled của hàng đợi; context; settings gửi lệnh + base_price + volumes[] (ML-30); struct khối lượng; input chọn chiến lược; tin tức; phần còn lại của DistanceInputs; PreparationInputs; last_check; tham số EntryLevel; số magic |
| Thiếu chủ sở hữu ô | ML-40..ML-47 | results[100][2] (Submission L46/L93); last_ticket; error_count (Submission L46); tick; strategy_index (Submission L45); guard của bảng ảo; số dư/khóa tài khoản; handle ATR |
| Thiếu nơi dùng | ML-50..ML-58 | Bot3PreparationState, Bot3Distances, Bot3VolumeState.volume, Bot3StrategySelectionState, block_time, kết quả DST, giá trị trả về BarGate, mảng đã sắp |
| Thiếu thuật toán/luồng | ML-60..ML-69 | randomization khoảng cách; phần còn lại 0xc30; luồng vào lệnh và base_price (ML-62); hết hạn ảo; hiển thị; thoát/khởi động lại; chính sách lỗi (vòng 132: Queue L80, Submission L100); khi nào vào/xử lý hàng đợi; điều kiện xóa cực trị và đóng lọc; thời điểm chuẩn bị khối lượng |

Vẫn thiếu cho khối đặt lệnh chờ: nơi gọi `SubmitPendingAfterPrice` (ML-16), nguồn `base_price` (ML-62), cài đặt `Bot3PendingSubmissionSettings` và `volumes[]` (ML-30), chủ thể giữ `results`, `error_count`, `strategy_index`, `trade`, `options` ở chương trình chính (ML-40, ML-42, ML-44, ML-27, ML-26).

Lưu ý nguồn: bên ghi bảng results đặt cột 0 = 1.0 (Queue L69, Submission L93), bên dọn/xóa so cột 0 với ticket (ML-40). Đây là hành vi đã ghi trong mã; không tự sửa.

## 4. Struct cùng loại dữ liệu, chưa có bằng chứng cùng ô (chi tiết: `struct_overlaps`)

| Mã | Nhóm | Ghi chú |
|---|---|---|
| SO-01/02 | DistanceInputs↔PreparationInputs; Distances↔PreparationState | trùng tên; khác kiểu bool/uchar; khác chính sách chia 0 và công thức freeze_buffer |
| SO-03/08 | lot_scale (0x6d1c8); start_lots/max_lots/manual_risk/balance_step ↔ native_6d620..6d640 | khớp chú thích/tên địa chỉ; không có mã chép; 0x6d630 int↔uint |
| SO-04 | VolumeState.volume ↔ volumes[9] ↔ volumes[] của Submission (L45) | một giá trị ↔ mảng 9 |
| SO-05/06/07/09/10 | enabled_mask, divisor↔weight_denominator, mode/risk 1234, converted_balance, frequency | trùng tên nhưng cách dùng khác |
| SO-11 | đầu ra InitializeAccountState ↔ VolumeState | cùng loại số dư |
| SO-12..SO-20 | tick/quote, unit, stop/take distance, min stop/freeze ↔ gap/freeze, expiration, virtual_expiration, symbol/comment, magic | nhiều tên, nhiều kiểu |
| SO-21..SO-28 | lock, timed, trailing, aux/levels, entry, mode ảo, delay 0x6d518, management_timeframe | chỉ tên hoặc chú thích |
| SO-29..SO-31 | strategy_index; results/last_ticket/error_count; request state/options | xem ML-40..44 |

Không gộp, không đổi kiểu, không chép sớm các nhóm này khi viết mã ghép.

## 5. Nhóm chương trình chính

| Nhóm | Đã có khối | Còn thiếu | Trạng thái |
|---|---|---|---|
| G1 Khởi động | InitializeAccountState (một phần 0xc30), bảng chiến lược | OnInit, input, giá trị đầu mọi ô, magic | chưa đủ để viết |
| G2 Mỗi tick | PrepareAccountStateVolume, PrepareStrategy, ManageOnBarChange, ProcessPendingQueue, CleanPendingResults | OnTick, thứ tự, vòng 9 chiến lược | chưa đủ để viết |
| G3 Đổi nến | ManageOnBarChange (iTime nến 1 vs last_times) cho quản lý | vào lệnh có theo nến không; nguồn timeframe/last_times | khối có, phần gọi chưa đủ |
| G4 Chuẩn bị chiến lược | PrepareStrategy, PrepareDistances, LoadBaseDistances, SelectStrategies, chuỗi khối lượng | nguồn input, chọn khối, randomization, ánh xạ đầu ra | chưa đủ để viết |
| G5 Điều kiện vào | EntryLevel, Upper/LowerLevel, NewsBlock, AmericanDST; margin/khối lượng/giới hạn lệnh/ask-bid trong Submit (L49-85) | luồng quyết định, quote, base_price, bộ lọc, nơi gọi Submit | chưa đủ để viết |
| G6 Đặt/sửa/hủy/đóng | đủ các chuỗi ở mục 2 (đặt lệnh có SubmissionDifference) | nơi gọi, điều kiện, hết hạn ảo, ô chung (ML-16, ML-17) | chuỗi có giữa header; chưa nối chương trình; điều phối chưa đủ |
| G7 Hiển thị | không có | toàn bộ | chưa có mã, chưa có bằng chứng luồng |
| G8 Lưu/khởi động lại/thoát/lỗi | GlobalVariables HighestBalance/LastBalanceOp, văn bản lỗi, vòng thử lại 132 (Queue L80, Submit L100) | OnDeinit, lưu bảng, chính sách lỗi | một phần, chưa đủ |

## 6. Phần viết mã giao được ngay (giao diện và hành vi đã xác định trong nguồn)

Giữ 3 phần của r1. Không thêm phần cho chương trình chính vì nơi gọi, thứ tự tick, nguồn cài đặt và chủ thể trạng thái chưa có căn cứ. Trong 54 Script hiện có chưa thấy tệp nào tên như dưới.

| Mã | Tệp đề xuất | Việc | Phụ thuộc | Cách kiểm |
|---|---|---|---|---|
| NP-01 | Scripts/.../Bot3AllHeadersApiCompile.mq5 | Script chỉ biên dịch, include đủ 51 header (gồm PendingSubmission 112 dòng) | 51 header | biên dịch ở MT5 kiểm thử, lưu log |
| NP-02 | Scripts/.../Bot3ManagementChainCheck.mq5 | chạy ManageOnBarChange với ManagePositions thật, ghi trạng thái sau lượt buy và sau lượt sell | BarGate, PositionManagement, mẫu FlowCheck + BarGateCheck | bên quản lý so với bản gốc trên cùng dịch vụ giả |
| NP-03 | Scripts/.../Bot3PendingSubmissionPipelineCheck.mq5 | chạy SubmitPendingAfterPrice với OpenPending/PrepareRequest/CheckFilling/SendTrade thật, chỉ giả API terminal; RoundPrice và SubmissionDifference chạy thân thật; ca phải tự kết thúc vòng thử lại 132 | PendingSubmission, PipelineApi | so với bản gốc sau khi chốt kiểm PendingSubmission; bỏ nếu bên quản lý đã có bộ kiểm chuỗi tương đương |

Phần còn lại cần bên quản lý phân tích trước khi giao (AQ-01..AQ-15 trong JSON): thứ tự khởi động 0xc30 và giá trị đầu; thứ tự OnTick; ánh xạ từng trường cài đặt quản lý; nguồn khối lượng và volumes[9]; hàm tính levels[9]; luồng vào lệnh, base_price và nơi gọi SubmitPendingAfterPrice (AQ-06); hàng đợi; ô chung; điều kiện hủy/đóng/hết hạn ảo; chọn PrepareDistances hay PrepareStrategy; randomization; dọn/lưu bảng; nơi dùng tin tức/DST/sắp xếp; chọn chiến lược; hiển thị/thoát/lỗi.

## 7. Script kiểm (54 tệp, không dùng trong bot)

| Loại | Số | Tệp |
|---|---|---|
| runtime_check | 43 | PriceLevels, EntryLevels, DistanceSettings, Volume, Currency, AccountVolume, Withdrawal, AccountStateVolume, Margin, NewsBlock, AccountInitialization, StrategySelection, VolumeValidation, AmericanDST, Filling, PendingRequest, TradeSend, OpenPending, PendingQueue, TradeErrors, PendingPipeline, OrderScan, OrderCancel, PendingSelection, PositionClose, PositionSelection, PositionModify, VirtualStops, ManagementAnchor, HistorySort, ManagementPrelude, ManagementVirtual, ManagementVirtualLevels, ManagementVirtualStore, ManagementVirtualFinishBranches, ManagementVirtualFinish, ManagementRealTimed, ManagementRealTake, ManagementRealBlocks, PositionManagementFlow, ManagementBarGate, Preparation, PendingSubmission (`Bot3` + tên + `Check.mq5`) |
| compile_only | 8 | VirtualStops, ManagementVirtual, ManagementVirtualLevels, ManagementReal, PositionManagement, ManagementBarGate, Preparation, PendingSubmission (`Bot3` + tên + `ApiCompile.mq5`) |
| storage_check | 1 | Bot3WithdrawalStorageCheck.mq5 (ghi/xóa 2 biến toàn cục thật trong terminal kiểm) |
| runtime_calibration | 1 | Bot3DivisionBehaviorCheck.mq5 |
| test_helper_header | 1 | Bot3PipelineApi.mqh (30 hàm: giả API gửi/thuộc tính/in và đọc/ghi tệp ca; cần PipelineSendComplete/PipelinePropertyComplete từ Script dùng nó) |

Hai Script PendingSubmission đọc lại ở r2, nội dung như r1: `Check` thay 9 tên bằng macro L14-22 (có `Bot3OpenPending`, `Bot3MarginGuard`, `Bot3ValidateVolume`, `Bot3AllowsPendingOrder`, `Bot3TradeErrorText`), gọi Submit ở L299, hàm giả gửi dừng ở lần gọi thứ năm (L134); `ApiCompile` chỉ gọi L16 khi `InvokeFunctions=true`.

Hàm sản phẩm mỗi Script gọi và dòng gọi: `test_scripts[].calls` trong JSON.

## 8. Thay đổi so với r1

Danh sách đầy đủ: `changes_from_r1` trong JSON và `SUMMARY.md`. Chính: khối #16 đổi trạng thái và dòng (thêm `SubmissionDifference`, 12 lời gọi); CL-021..CL-026 đổi dòng; ML-16 đổi dòng, thêm ML-17; ML-40/42/44/66 và SO-04 đổi dòng; G5/G6/G8 cập nhật; `pending_proposals` thành `proposal_history`. Tổng: 99 hàm (r1: 98), 240 vị trí gọi (r1: 238); số header, struct, Script, liên kết khác tệp không đổi.
