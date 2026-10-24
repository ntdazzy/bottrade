# Các dòng cài đặt bot 1 đã đối chiếu

72 dòng × 9 lượt = 648/648 lần khớp. Bao gồm 8 tiêu đề.

Tên, thứ tự trong nhật ký, vị trí lưu và mặc định đã kiểm. Kiểu ghi ở
dưới là cách lưu quan sát được; số nguyên chưa phân biệt `int`/`long`/
danh sách lựa chọn. Nhãn hiển thị và tác dụng toàn bộ chưa kiểm xong.

[Bằng chứng chi tiết](cai-dat-da-kiem.json) · [Phép so](../../bang-chung/phan-tich-cai-dat/inputs-20261023-r2/comparison-extended.json)

| Thứ tự | Tên gốc | Dạng lưu | Vị trí từ đầu vùng mã | Mặc định | Nơi dùng trong mã trung gian |
|---|---|---|---|---|---|
| 1 | `lijntje` (tiêu đề) | chuỗi | `0x6a518` | `"============================================================="` | chưa thấy lời đọc trực tiếp |
| 2 | `ShowInfoPanel` | bật/tắt | `0x6a528` | `"true"` | `0xc30`, `0xe1b0`, `0xffb0`, `0x10f60` |
| 3 | `UpdateInfoTesting` | bật/tắt | `0x6a530` | `"false"` | `0xc30`, `0xe1b0`, `0xffb0`, `0x10f60`, `0x1efa0` |
| 4 | `InfoPanelSizeAdjust` | số thực | `0x6a538` | `"1.0"` | `0xc30`, `0x8320` |
| 5 | `SetFontSize` | số nguyên; kiểu khai báo chưa chốt | `0x6a540` | `"0"` | `0x8320` |
| 6 | `BacktestSpeed_string` (tiêu đề) | chuỗi | `0x6a548` | `"------------------------------ Backtest Speed settings ------------------------------"` | chưa thấy lời đọc trực tiếp |
| 7 | `BacktestSpeed` | số nguyên; kiểu khai báo chưa chốt | `0x6a558` | `"1"` | `0xc30` |
| 8 | `spreadfilter` (tiêu đề) | chuỗi | `0x6a560` | `"------------------------------ settings ------------------------------"` | chưa thấy lời đọc trực tiếp |
| 9 | `AllowBuyTrades` | bật/tắt | `0x6a570` | `"true"` | `0x18aa0` |
| 10 | `AllowSellTrades` | bật/tắt | `0x6a578` | `"true"` | `0x18aa0` |
| 11 | `RunStrategyA` | bật/tắt | `0x6a580` | `"true"` | `0x10f60` |
| 12 | `RunStrategyB` | bật/tắt | `0x6a588` | `"true"` | `0x10f60` |
| 13 | `RunStrategyC` | bật/tắt | `0x6a590` | `"true"` | `0x10f60` |
| 14 | `RunStrategyD` | bật/tắt | `0x6a598` | `"true"` | `0x10f60` |
| 15 | `RunStrategyE` | bật/tắt | `0x6a5a0` | `"true"` | `0x10f60` |
| 16 | `RunStrategyF` | bật/tắt | `0x6a5a8` | `"true"` | `0x10f60` |
| 17 | `RunStrategyG` | bật/tắt | `0x6a5b0` | `"true"` | `0x10f60` |
| 18 | `RunStrategyH` | bật/tắt | `0x6a5b8` | `"true"` | `0x10f60` |
| 19 | `MaxSpread` | số thực | `0x6a5c0` | `"500.0"` | `0x7500` |
| 20 | `UseVariableValues` | bật/tắt | `0x6a5c8` | `"true"` | `0x7500` |
| 21 | `UseHL_TrailingSL` | bật/tắt | `0x6a5d0` | `"true"` | `0x10f60`, `0x271f0`, `0x2abc0` |
| 22 | `FridayStopHour` | số nguyên; kiểu khai báo chưa chốt | `0x6a5d8` | `"25"` | `0x7500`, `0x20a00` |
| 23 | `setSL_TP_After_Entry` | bật/tắt | `0x6a5e0` | `"false"` | `0x7500` |
| 24 | `Virtual_expiration` | bật/tắt | `0x6a5e8` | `"true"` | `0x7500`, `0x32dd0` |
| 25 | `Randomization` | số thực | `0x6a5f0` | `"0.0"` | `0x10f60` |
| 26 | `FakeOutFilter` | số nguyên; kiểu khai báo chưa chốt | `0x6a5f8` | `"1"` | `0x10f60` |
| 27 | `EnableVirtualSLTP` | bật/tắt | `0x6a600` | `"false"` | `0x7500`, `0x10f60` |
| 28 | `SetVSL_to_hardSL_sec_delay` | số nguyên; kiểu khai báo chưa chốt | `0x6a608` | `"99"` | `0x7500` |
| 29 | `ST1_MagicNumber` | số nguyên; kiểu khai báo chưa chốt | `0x6a610` | `"9000"` | `0xc30`, `0xe1b0`, `0xffb0`, `0x10f60`, `0x2fa00`, `0x2fce0`, `0x30010` |
| 30 | `ST1_Comment` | chuỗi | `0x6a618` | `"Gold Trade Pro"` | `0xc30`, `0x10f60` |
| 31 | `RemoveCommentSuffix` | bật/tắt | `0x6a628` | `"false"` | `0x10f60` |
| 32 | `NFP_FILTER` (tiêu đề) | chuỗi | `0x6a630` | `"----------------------- NFP Filter -----------------------"` | chưa thấy lời đọc trực tiếp |
| 33 | `EnableNFP_Filter` | bật/tắt | `0x6a640` | `"true"` | `0xc30`, `0x7310`, `0x18aa0` |
| 34 | `UseMQL5Calendar` | bật/tắt | `0x6a648` | `"true"` | `0x18aa0` |
| 35 | `AutoGMT` | bật/tắt | `0x6a650` | `"true"` | `0x10f60` |
| 36 | `Broker_GMT_OFFSET_Winter` | số nguyên; kiểu khai báo chưa chốt | `0x6a658` | `"2"` | `0x10f60` |
| 37 | `Broker_GMT_OFFSET_Summer` | số nguyên; kiểu khai báo chưa chốt | `0x6a660` | `"3"` | `0x10f60` |
| 38 | `NFP_CloseOpenTrades` | bật/tắt | `0x6a668` | `"true"` | `0x18aa0` |
| 39 | `NFP_ClosePendingOrders` | bật/tắt | `0x6a670` | `"true"` | `0x18aa0` |
| 40 | `NFP_MinutesBefore` | số nguyên; kiểu khai báo chưa chốt | `0x6a678` | `"10"` | `0x18aa0` |
| 41 | `NFP_MinutesAfter` | số nguyên; kiểu khai báo chưa chốt | `0x6a680` | `"240"` | `0x7310`, `0x18aa0` |
| 42 | `IR_FILTER` (tiêu đề) | chuỗi | `0x6a688` | `"----------------------- Interest Rate Filter -----------------------"` | chưa thấy lời đọc trực tiếp |
| 43 | `EnableIR_Filter` | bật/tắt | `0x6a698` | `"false"` | `0xc30`, `0x7310`, `0x18aa0` |
| 44 | `IR_CloseOpenTrades` | bật/tắt | `0x6a6a0` | `"true"` | `0x18aa0` |
| 45 | `IR_ClosePendingOrders` | bật/tắt | `0x6a6a8` | `"true"` | `0x18aa0` |
| 46 | `IR_MinutesBefore` | số nguyên; kiểu khai báo chưa chốt | `0x6a6b0` | `"100"` | `0x18aa0` |
| 47 | `IR_MinutesAfter` | số nguyên; kiểu khai báo chưa chốt | `0x6a6b8` | `"60"` | `0x7310`, `0x18aa0` |
| 48 | `CPI_FILTER` (tiêu đề) | chuỗi | `0x6a6c0` | `"----------------------- CPI Filter -----------------------"` | chưa thấy lời đọc trực tiếp |
| 49 | `EnableCPI_Filter` | bật/tắt | `0x6a6d0` | `"false"` | `0xc30`, `0x7310`, `0x18aa0` |
| 50 | `CPI_CloseOpenTrades` | bật/tắt | `0x6a6d8` | `"true"` | `0x18aa0` |
| 51 | `CPI_ClosePendingOrders` | bật/tắt | `0x6a6e0` | `"true"` | `0x18aa0` |
| 52 | `CPI_MinutesBefore` | số nguyên; kiểu khai báo chưa chốt | `0x6a6e8` | `"100"` | `0x18aa0` |
| 53 | `CPI_MinutesAfter` | số nguyên; kiểu khai báo chưa chốt | `0x6a6f0` | `"60"` | `0x7310`, `0x18aa0` |
| 54 | `propfirmsettings` (tiêu đề) | chuỗi | `0x6a6f8` | `"----------------------- Propfirm unique trades settings -----------------------"` | chưa thấy lời đọc trực tiếp |
| 55 | `AdjustEntry` | số thực | `0x6a708` | `"0.0"` | `0x10f60` |
| 56 | `AdjustSL` | số thực | `0x6a710` | `"0.0"` | `0x10f60` |
| 57 | `AdjustTP` | số thực | `0x6a718` | `"0.0"` | `0x10f60` |
| 58 | `AdjustTrailSL` | số thực | `0x6a720` | `"0.0"` | `0x10f60` |
| 59 | `LotSizeSettings` (tiêu đề) | chuỗi | `0x6a728` | `"----------------------- LotSize Settings -----------------------"` | chưa thấy lời đọc trực tiếp |
| 60 | `ManualBalance` | số thực | `0x6a738` | `"0.0"` | `0xc30`, `0x10f60`, `0x34780` |
| 61 | `StartLots` | số thực | `0x6a740` | `"0.01"` | `0x7500` |
| 62 | `Risk` | số nguyên; kiểu khai báo chưa chốt | `0x6a748` | `"0"` | `0x7500`, `0x8320`, `0xe1b0` |
| 63 | `Manual_RiskPerTrade` | số thực | `0x6a750` | `"1.2"` | `0x7500`, `0x8320`, `0xe1b0` |
| 64 | `MaxRiskPerStrategy` | số thực | `0x6a758` | `"3.0"` | `0x8320`, `0xe1b0`, `0x34780` |
| 65 | `PropFirmMaxDailyDD` | số thực | `0x6a760` | `"0.0"` | `0x10f60` |
| 66 | `LotPerBalance_step` | số nguyên; kiểu khai báo chưa chốt | `0x6a768` | `"600"` | `0x7500`, `0x8320`, `0xe1b0` |
| 67 | `OnlyUp` | bật/tắt | `0x6a770` | `"true"` | `0x10f60`, `0x34780` |
| 68 | `ResetHighestBalance` | bật/tắt | `0x6a778` | `"false"` | `0xc30` |
| 69 | `ResetHighestBalanceOnWithdrawal` | bật/tắt | `0x6a780` | `"true"` | `0x173f0` |
| 70 | `CheckMargin` | bật/tắt | `0x6a788` | `"true"` | `0x7500` |
| 71 | `UseEquity` | bật/tắt | `0x6a790` | `"false"` | `0xc30`, `0x10f60`, `0x34780` |
| 72 | `AdjustLotsizeToVariableValues` | bật/tắt | `0x6a798` | `"true"` | `0x7500` |

Chuỗi được ghi trong dấu ngoặc kép để giữ rõ khoảng trắng. Bot 3 có
một dấu cách cuối `ManStratWarn`; bản dựng phải giữ nguyên. Không thấy
lời đọc trực tiếp chưa đủ để kết luận mục đó không được dùng.
