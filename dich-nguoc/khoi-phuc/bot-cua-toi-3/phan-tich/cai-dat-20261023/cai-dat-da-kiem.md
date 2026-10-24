# Các dòng cài đặt bot 3 đã đối chiếu

80 dòng × 9 lượt = 720/720 lần khớp. Bao gồm 9 tiêu đề.

Tên, thứ tự trong nhật ký, vị trí lưu và mặc định đã kiểm. Kiểu ghi ở
dưới là cách lưu quan sát được; số nguyên chưa phân biệt `int`/`long`/
danh sách lựa chọn. Nhãn hiển thị và tác dụng toàn bộ chưa kiểm xong.

[Bằng chứng chi tiết](cai-dat-da-kiem.json) · [Phép so](../../bang-chung/phan-tich-cai-dat/inputs-20261023-r3/comparison-extended.json)

| Thứ tự | Tên gốc | Dạng lưu | Vị trí từ đầu vùng mã | Mặc định | Nơi dùng trong mã trung gian |
|---|---|---|---|---|---|
| 1 | `lijntje` (tiêu đề) | chuỗi | `0x1d6f18` | `"============================================================="` | chưa thấy lời đọc trực tiếp |
| 2 | `UseVariableValues` | bật/tắt | `0x1d6f28` | `"true"` | `0xc30`, `0xe0c0`, `0x17f00` |
| 3 | `AdjustLotsizeToVariableValues` | bật/tắt | `0x1d6f30` | `"true"` | `0xe0c0` |
| 4 | `ShowInfoPanel` | bật/tắt | `0x1d6f38` | `"true"` | `0xc30`, `0x14fa0`, `0x16e80`, `0x17f00` |
| 5 | `UpdateInfoTesting` | bật/tắt | `0x1d6f40` | `"false"` | `0x14fa0`, `0x16e80`, `0x17f00`, `0x2a1c0` |
| 6 | `InfoPanelSizeAdjust` | số thực | `0x1d6f48` | `"1.0"` | `0xc30`, `0xef40` |
| 7 | `SetFontSize` | số nguyên; kiểu khai báo chưa chốt | `0x1d6f50` | `"0"` | `0xef40` |
| 8 | `BacktestSpeed_string` (tiêu đề) | chuỗi | `0x1d6f58` | `"------------------------------ Backtest Speed settings ------------------------------"` | chưa thấy lời đọc trực tiếp |
| 9 | `BacktestSpeed` | số nguyên; kiểu khai báo chưa chốt | `0x1d6f68` | `"1"` | `0xc30` |
| 10 | `spreadfilter` (tiêu đề) | chuỗi | `0x1d6f70` | `"------------------------------ settings ------------------------------"` | chưa thấy lời đọc trực tiếp |
| 11 | `AllowBuyTrades` | bật/tắt | `0x1d6f80` | `"true"` | `0x20ef0` |
| 12 | `AllowSellTrades` | bật/tắt | `0x1d6f88` | `"true"` | `0x20ef0` |
| 13 | `TradeFrequency` | số nguyên; kiểu khai báo chưa chốt | `0x1d6f90` | `"5"` | `0xc30`, `0x17f00` |
| 14 | `MaxSpread` | số thực | `0x1d6f98` | `"500.0"` | `0xe0c0` |
| 15 | `UseHL_TrailingSL` | bật/tắt | `0x1d6fa0` | `"true"` | `0x17f00`, `0x32f60`, `0x37590` |
| 16 | `FridayStopHour` | số nguyên; kiểu khai báo chưa chốt | `0x1d6fa8` | `"25"` | `0xe0c0`, `0x2bb80` |
| 17 | `FridayClosePending` | bật/tắt | `0x1d6fb0` | `"true"` | `0x3d650` |
| 18 | `FridayCloseOpen` | bật/tắt | `0x1d6fb8` | `"true"` | `0x3d650` |
| 19 | `setSL_TP_After_Entry` | bật/tắt | `0x1d6fc0` | `"false"` | `0xe0c0` |
| 20 | `Virtual_expiration` | bật/tắt | `0x1d6fc8` | `"true"` | `0xe0c0`, `0x3e580` |
| 21 | `Randomization` | số thực | `0x1d6fd0` | `"0.0"` | `0x17f00` |
| 22 | `FakeOutFilter` | số nguyên; kiểu khai báo chưa chốt | `0x1d6fd8` | `"2"` | `0x17f00` |
| 23 | `EnableVirtualSLTP` | bật/tắt | `0x1d6fe0` | `"false"` | `0xe0c0`, `0x17f00` |
| 24 | `SetVSL_to_hardSL_sec_delay` | số nguyên; kiểu khai báo chưa chốt | `0x1d6fe8` | `"99"` | `0xe0c0` |
| 25 | `ST1_MagicNumber` | số nguyên; kiểu khai báo chưa chốt | `0x1d6ff0` | `"8000"` | `0xc30`, `0x14fa0`, `0x16e80`, `0x17f00`, `0x20ef0`, `0x3ce40`, `0x3d220`, `0x3d650` |
| 26 | `ST1_Comment` | chuỗi | `0x1d6ff8` | `"The Gold Reaper"` | `0xc30`, `0x17f00` |
| 27 | `RemoveCommentSuffix` | bật/tắt | `0x1d7008` | `"false"` | `0x17f00` |
| 28 | `NFP_FILTER` (tiêu đề) | chuỗi | `0x1d7010` | `"----------------------- NFP Filter -----------------------"` | chưa thấy lời đọc trực tiếp |
| 29 | `EnableNFP_Filter` | bật/tắt | `0x1d7020` | `"true"` | `0xc30`, `0x7c30`, `0x20ef0` |
| 30 | `UseMQL5Calendar` | bật/tắt | `0x1d7028` | `"true"` | `0x20ef0` |
| 31 | `AutoGMT` | bật/tắt | `0x1d7030` | `"true"` | `0x17f00` |
| 32 | `Broker_GMT_OFFSET_Winter` | số nguyên; kiểu khai báo chưa chốt | `0x1d7038` | `"2"` | `0xc30`, `0x17f00` |
| 33 | `Broker_GMT_OFFSET_Summer` | số nguyên; kiểu khai báo chưa chốt | `0x1d7040` | `"3"` | `0xc30`, `0x17f00` |
| 34 | `NFP_CloseOpenTrades` | bật/tắt | `0x1d7048` | `"true"` | `0x20ef0` |
| 35 | `NFP_ClosePendingOrders` | bật/tắt | `0x1d7050` | `"true"` | `0x20ef0` |
| 36 | `NFP_MinutesBefore` | số nguyên; kiểu khai báo chưa chốt | `0x1d7058` | `"100"` | `0x20ef0` |
| 37 | `NFP_MinutesAfter` | số nguyên; kiểu khai báo chưa chốt | `0x1d7060` | `"60"` | `0x7c30`, `0x20ef0` |
| 38 | `IR_FILTER` (tiêu đề) | chuỗi | `0x1d7068` | `"----------------------- Interest Rate Filter -----------------------"` | chưa thấy lời đọc trực tiếp |
| 39 | `EnableIR_Filter` | bật/tắt | `0x1d7078` | `"false"` | `0xc30`, `0x7c30`, `0x20ef0` |
| 40 | `IR_CloseOpenTrades` | bật/tắt | `0x1d7080` | `"true"` | `0x20ef0` |
| 41 | `IR_ClosePendingOrders` | bật/tắt | `0x1d7088` | `"true"` | `0x20ef0` |
| 42 | `IR_MinutesBefore` | số nguyên; kiểu khai báo chưa chốt | `0x1d7090` | `"100"` | `0x20ef0` |
| 43 | `IR_MinutesAfter` | số nguyên; kiểu khai báo chưa chốt | `0x1d7098` | `"60"` | `0x7c30`, `0x20ef0` |
| 44 | `CPI_FILTER` (tiêu đề) | chuỗi | `0x1d70a0` | `"----------------------- CPI Filter -----------------------"` | chưa thấy lời đọc trực tiếp |
| 45 | `EnableCPI_Filter` | bật/tắt | `0x1d70b0` | `"false"` | `0xc30`, `0x7c30`, `0x20ef0` |
| 46 | `CPI_CloseOpenTrades` | bật/tắt | `0x1d70b8` | `"true"` | `0x20ef0` |
| 47 | `CPI_ClosePendingOrders` | bật/tắt | `0x1d70c0` | `"true"` | `0x20ef0` |
| 48 | `CPI_MinutesBefore` | số nguyên; kiểu khai báo chưa chốt | `0x1d70c8` | `"100"` | `0x20ef0` |
| 49 | `CPI_MinutesAfter` | số nguyên; kiểu khai báo chưa chốt | `0x1d70d0` | `"60"` | `0x7c30`, `0x20ef0` |
| 50 | `propfirmsettings` (tiêu đề) | chuỗi | `0x1d70d8` | `"----------------------- Propfirm unique trades settings -----------------------"` | chưa thấy lời đọc trực tiếp |
| 51 | `AdjustEntry` | số thực | `0x1d70e8` | `"0.0"` | `0x17f00` |
| 52 | `AdjustSL` | số thực | `0x1d70f0` | `"0.0"` | `0x17f00` |
| 53 | `AdjustTP` | số thực | `0x1d70f8` | `"0.0"` | `0x17f00` |
| 54 | `AdjustTrailSL` | số thực | `0x1d7100` | `"0.0"` | `0x17f00` |
| 55 | `AdjustTrailTP` | số thực | `0x1d7108` | `"0.0"` | `0x17f00` |
| 56 | `AdjustBreakEven` | số thực | `0x1d7110` | `"0.0"` | `0x17f00` |
| 57 | `LotSizeSettings` (tiêu đề) | chuỗi | `0x1d7118` | `"----------------------- LotSize Settings -----------------------"` | chưa thấy lời đọc trực tiếp |
| 58 | `ManualBalance` | số thực | `0x1d7128` | `"0.0"` | `0xc30`, `0x17f00`, `0x3f900` |
| 59 | `Risk` | số nguyên; kiểu khai báo chưa chốt | `0x1d7130` | `"1234"` | `0xc30`, `0xe0c0`, `0x17f00` |
| 60 | `StartLots` | số thực | `0x1d7138` | `"0.01"` | `0xe0c0`, `0xef40`, `0x14fa0` |
| 61 | `MaxAllowedDD` | số thực | `0x1d7140` | `"30.0"` | `0xc30`, `0xef40`, `0x14fa0`, `0x17f00`, `0x3f900` |
| 62 | `UseWeightedLots` | bật/tắt | `0x1d7148` | `"true"` | `0x3f900` |
| 63 | `MaxRiskPerStrategy_` | số thực | `0x1d7150` | `"1.0"` | `0xef40`, `0x14fa0`, `0x3f900` |
| 64 | `PropFirmMaxDailyDD` | số thực | `0x1d7158` | `"0.0"` | `0x17f00` |
| 65 | `OnlyUp` | bật/tắt | `0x1d7160` | `"true"` | `0x17f00`, `0x3f900` |
| 66 | `ResetHighestBalance` | bật/tắt | `0x1d7168` | `"false"` | `0xc30` |
| 67 | `ResetHighestBalanceOnWithdrawal` | bật/tắt | `0x1d7170` | `"true"` | `0x1fd00` |
| 68 | `CheckMargin` | bật/tắt | `0x1d7178` | `"true"` | `0xe0c0` |
| 69 | `UseEquity` | bật/tắt | `0x1d7180` | `"false"` | `0xc30`, `0x17f00`, `0x3f900` |
| 70 | `ManualStratSelect` (tiêu đề) | chuỗi | `0x1d7188` | `"------------------------- Manual Strategy Selection -------------------------"` | chưa thấy lời đọc trực tiếp |
| 71 | `ManStratWarn` | chuỗi | `0x1d7198` | `"!! DO NOT RUN MANUAL STRATEGIES WHILE USING 'MAX ALLOWED TOTAL DD' OPTION !! "` | chưa thấy lời đọc trực tiếp |
| 72 | `RunStrat1` | bật/tắt | `0x1d71a8` | `"true"` | `0xc30`, `0x17f00` |
| 73 | `RunStrat2` | bật/tắt | `0x1d71b0` | `"true"` | `0xc30`, `0x17f00` |
| 74 | `RunStrat3` | bật/tắt | `0x1d71b8` | `"true"` | `0xc30`, `0x17f00` |
| 75 | `RunStrat4` | bật/tắt | `0x1d71c0` | `"true"` | `0xc30`, `0x17f00` |
| 76 | `RunStrat5` | bật/tắt | `0x1d71c8` | `"true"` | `0xc30`, `0x17f00` |
| 77 | `RunStrat6` | bật/tắt | `0x1d71d0` | `"true"` | `0xc30`, `0x17f00` |
| 78 | `RunStrat7` | bật/tắt | `0x1d71d8` | `"true"` | `0xc30`, `0x17f00` |
| 79 | `RunStrat8` | bật/tắt | `0x1d71e0` | `"true"` | `0xc30`, `0x17f00` |
| 80 | `RunStrat9` | bật/tắt | `0x1d71e8` | `"true"` | `0xc30`, `0x17f00` |

Chuỗi được ghi trong dấu ngoặc kép để giữ rõ khoảng trắng. Bot 3 có
một dấu cách cuối `ManStratWarn`; bản dựng phải giữ nguyên. Không thấy
lời đọc trực tiếp chưa đủ để kết luận mục đó không được dùng.
