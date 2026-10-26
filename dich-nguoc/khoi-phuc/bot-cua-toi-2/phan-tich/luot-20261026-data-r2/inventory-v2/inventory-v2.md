# Inventory snapshot bot2 — luot-20261026-r1

Nguồn EX5 SHA: `390d8ab14fc213ff4b8cbe5084bec545526e62c6028516fe21219a59398ce795`; engine: `5033d9d45d669cebd735e8a6be20b54d74b75274f885c9a0e48e52d872104efb`; code SHA: `ae4e9020f7f5f08d49774728bed14c17eb2bd26b6271c20da51bd3aaa446014f`; 86 hàm, 85 hoàn tất, 1 lỗi.

| # | RVA | Trạng thái | Dòng C | Khai báo | Gọi nội bộ | SDK tên rõ |
|---:|---:|---|---:|---|---|---|
| 1 | `0x0`..`0x57` | done | 7 | `void FUN_253f2620000(int *param_1)` | `—` | `chưa gắn` |
| 2 | `0x60`..`0x1d8` | done | 31 | `ulonglong FUN_253f2620060(int *param_1,ulonglong param_2)` | `—` | `chưa gắn` |
| 3 | `0x1e0`..`0x3bd` | done | 130 | `void FUN_253f26201e0(int *param_1,longlong param_2,uint param_3)` | `—` | `chưa gắn` |
| 4 | `0x3c0`..`0x49d` | done | 238 | `ulonglong FUN_253f26203c0(short *param_1,short *param_2)` | `—` | `chưa gắn` |
| 5 | `0x4a0`..`0x5bd` | done | 314 | `ulonglong FUN_253f26204a0(longlong param_1,longlong param_2)` | `FUN_253f2620060` | `chưa gắn` |
| 6 | `0x5c0`..`0x7d8` | done | 390 | `void FUN_253f26205c0(int *param_1,int *param_2,char param_3,void *param_4)` | `—` | `chưa gắn` |
| 7 | `0x7e0`..`0x8a5` | done | 514 | `void FUN_253f26207e0(longlong param_1)` | `—` | `chưa gắn` |
| 8 | `0x8c0`..`0x8df` | done | 557 | `void FUN_253f26208c0(undefined8 param_1,undefined4 param_2)` | `—` | `chưa gắn` |
| 9 | `0x8e0`..`0x8ff` | done | 568 | `void FUN_253f26208e0(undefined8 param_1,undefined4 param_2)` | `—` | `chưa gắn` |
| 10 | `0x900`..`0x901` | done | 579 | `void FUN_253f2620900(void)` | `—` | `chưa gắn` |
| 11 | `0x910`..`0x94f` | done | 589 | `void FUN_253f2620910(undefined8 *param_1)` | `—` | `chưa gắn` |
| 12 | `0x950`..`0xb5e` | done | 601 | `undefined4 FUN_253f2620950(longlong param_1,undefined8 param_2,undefined8 param_3)` | `FUN_253f2620000, FUN_253f26205c0, FUN_253f2643930, FUN_253f2644310` | `MT5_Dispatch` |
| 13 | `0xb60`..`0xbcc` | done | 663 | `void FUN_253f2620b60(undefined8 *param_1)` | `FUN_253f2620000` | `chưa gắn` |
| 14 | `0xbd0`..`0xc23` | done | 679 | `void FUN_253f2620bd0(longlong param_1)` | `FUN_253f2620000` | `chưa gắn` |
| 15 | `0xc30`..`0x58ca` | failed | 709 | `—` | `—` | `chưa gắn` |
| 16 | `0x58d0`..`0x61f9` | done | 713 | `ulonglong FUN_253f26258d0(void)` | `FUN_253f2620000, FUN_253f2620060, FUN_253f26205c0, FUN_253f265e8f0, FUN_253f266a940` | `MT5_AccountInfoInteger, MT5_Dispatch` |
| 17 | `0x6200`..`0x6643` | done | 997 | `ulonglong FUN_253f2626200(void)` | `FUN_253f26207e0` | `MT5_TimeTradeServer` |
| 18 | `0x6650`..`0x6ad3` | done | 1209 | `ulonglong FUN_253f2626650(void)` | `FUN_253f26207e0` | `MT5_Dispatch, MT5_TimeTradeServer` |
| 19 | `0x6ae0`..`0x7356` | done | 1426 | `longlong FUN_253f2626ae0(void)` | `FUN_253f2620000, FUN_253f26205c0, FUN_253f26207e0` | `MT5_TimeTradeServer` |
| 20 | `0x7360`..`0x7548` | done | 1800 | `void FUN_253f2627360(void)` | `FUN_253f26205c0` | `MT5_TimeTradeServer` |
| 21 | `0x7550`..`0x83c4` | done | 1890 | `void FUN_253f2627550(undefined4 param_1)` | `FUN_253f26205c0` | `MT5_CopyBuffer, MT5_Dispatch, MT5_SymbolInfoDouble, MT5_SymbolInfoInteger, MT5_SymbolInfoTick, MT5_TimeCurrent, MT5_iOpen` |
| 22 | `0x83d0`..`0xe24e` | done | 2135 | `void FUN_253f26283d0(void)` | `FUN_253f2620000, FUN_253f2620060, FUN_253f26205c0, FUN_253f2627360, FUN_253f2663250` | `MT5_Dispatch, MT5_DoubleToString, MT5_IntegerToString, MT5_ObjectFind, MT5_ObjectSetInteger, MT5_ObjectSetString` |
| 23 | `0xe250`..`0x100a2` | done | 4865 | `void FUN_253f262e250(void)` | `FUN_253f2620000, FUN_253f2620060, FUN_253f26205c0, FUN_253f2627360` | `MT5_DoubleToString, MT5_IntegerToString, MT5_MQLInfoInteger, MT5_ObjectSetString, MT5_PositionGetDouble, MT5_PositionGetInteger, MT5_PositionGetString, MT5_PositionGetTicket, MT5_PositionSelectByTicket, MT5_PositionsTotal` |
| 24 | `0x100b0`..`0x1105f` | done | 5926 | `void FUN_253f26300b0(void)` | `FUN_253f2620000, FUN_253f2620060, FUN_253f26205c0` | `MT5_DoubleToString, MT5_HistoryDealGetDouble, MT5_HistoryDealGetInteger, MT5_HistoryDealGetString, MT5_HistoryDealGetTicket, MT5_HistoryDealsTotal, MT5_HistorySelect, MT5_IntegerToString, MT5_MQLInfoInteger, MT5_ObjectSetString` |
| 25 | `0x11060`..`0x16fe7` | done | 6476 | `void FUN_253f2631060(void)` | `FUN_253f2620000, FUN_253f2620060, FUN_253f26205c0, FUN_253f26258d0, FUN_253f2627550, FUN_253f262e250, FUN_253f26300b0, FUN_253f2636ff0, FUN_253f2637440, FUN_253f2637920, FUN_253f2638390, FUN_253f26386c0, FUN_253f263f2c0, FUN_253f2650ec0, FUN_253f2664e20, FUN_253f2665400` | `MT5_AccountInfoDouble, MT5_AccountInfoInteger, MT5_Dispatch, MT5_DoubleToString, MT5_HistoryDealGetDouble, MT5_HistoryDealGetInteger, MT5_HistoryDealGetTicket, MT5_HistoryDealsTotal, MT5_HistorySelect, MT5_IntegerToString, MT5_MQLInfoInteger, MT5_StringToTime, MT5_TimeCurrent, MT5_TimeGMT, MT5_TimeToStruct, MT5_iTime` |
| 26 | `0x16ff0`..`0x17439` | done | 8637 | `void FUN_253f2636ff0(double param_1)` | `FUN_253f2620000, FUN_253f26205c0` | `MT5_Dispatch, MT5_DoubleToString, MT5_HistoryDealGetDouble, MT5_HistoryDealGetInteger, MT5_HistoryDealGetTicket, MT5_HistoryDealsTotal, MT5_HistorySelect, MT5_MQLInfoInteger, MT5_TimeCurrent` |
| 27 | `0x17440`..`0x17917` | done | 8736 | `undefined8 FUN_253f2637440(void)` | `FUN_253f2620000, FUN_253f26205c0` | `MT5_Dispatch, MT5_StringToTime, MT5_TimeCurrent, MT5_TimeToStruct` |
| 28 | `0x17920`..`0x18389` | done | 8841 | `ulonglong FUN_253f2637920(void)` | `FUN_253f2620000, FUN_253f2620060, FUN_253f26201e0, FUN_253f26205c0` | `MT5_Dispatch, MT5_StringToInteger, MT5_TimeCurrent, MT5_TimeToStruct` |
| 29 | `0x18390`..`0x186c0` | done | 9178 | `void FUN_253f2638390(void)` | `—` | `MT5_PositionGetInteger, MT5_PositionGetTicket, MT5_PositionsTotal` |
| 30 | `0x186c0`..`0x1f2b3` | done | 9305 | `void FUN_253f26386c0(uint param_1)` | `FUN_253f2620000, FUN_253f2620060, FUN_253f26204a0, FUN_253f26205c0, FUN_253f2626200, FUN_253f2626650, FUN_253f2626ae0, FUN_253f2627360, FUN_253f262e250, FUN_253f26300b0, FUN_253f2637440, FUN_253f2646910, FUN_253f2646d10, FUN_253f2647100, FUN_253f26475d0, FUN_253f264b580, FUN_253f264f580, FUN_253f2650470, FUN_253f2650690, FUN_253f26508b0, FUN_253f2650b90, FUN_253f2650e60, FUN_253f2650e90, FUN_253f2650ec0, FUN_253f2652df0, FUN_253f2652fc0, FUN_253f2653290, FUN_253f2653460, FUN_253f2653740, FUN_253f2653970, FUN_253f2653c80, FUN_253f2654580, FUN_253f2655000, FUN_253f2655810, FUN_253f265cfb0, FUN_253f265d640, FUN_253f265d690, FUN_253f265d8f0, FUN_253f265db50` | `MT5_Dispatch, MT5_IntegerToString, MT5_MQLInfoInteger, MT5_OrderGetDouble, MT5_OrderGetInteger, MT5_OrderGetString, MT5_OrderGetTicket, MT5_OrdersTotal, MT5_PositionGetDouble, MT5_PositionGetInteger, MT5_PositionGetString, MT5_PositionGetTicket, MT5_PositionsTotal, MT5_StringToTime, MT5_SymbolInfoInteger, MT5_SymbolInfoTick, MT5_TimeCurrent, MT5_TimeToString, MT5_TimeToStruct, MT5_TimeTradeServer, MT5_iTime` |
| 31 | `0x1f2c0`..`0x1f8ff` | done | 12105 | `double FUN_253f263f2c0(void)` | `FUN_253f2620000, FUN_253f26205c0, FUN_253f2665030` | `MT5_HistoryDealGetDouble, MT5_HistoryDealGetInteger, MT5_HistoryDealGetString, MT5_HistoryDealGetTicket, MT5_HistoryDealsTotal, MT5_HistorySelect, MT5_MQLInfoInteger` |
| 32 | `0x1f900`..`0x20c6e` | done | 12312 | `void FUN_253f263f900(void)` | `FUN_253f2620000, FUN_253f2620060, FUN_253f26205c0` | `MT5_IndicatorRelease, MT5_IntegerToString, MT5_ObjectDelete` |
| 33 | `0x20c70`..`0x20d1e` | done | 13038 | `ulonglong FUN_253f2640c70(void)` | `—` | `chưa gắn` |
| 34 | `0x20d20`..`0x22ab5` | done | 13062 | `void FUN_253f2640d20(void)` | `FUN_253f2620000, FUN_253f26205c0` | `MT5_AccountInfoInteger, MT5_MQLInfoInteger` |
| 35 | `0x22ac0`..`0x22f38` | done | 13556 | `void FUN_253f2642ac0(void)` | `FUN_253f2620000` | `chưa gắn` |
| 36 | `0x22f40`..`0x22f68` | done | 13661 | `void FUN_253f2642f40(longlong param_1)` | `—` | `chưa gắn` |
| 37 | `0x22f70`..`0x22fa2` | done | 13676 | `void FUN_253f2642f70(longlong param_1)` | `FUN_253f2620000` | `chưa gắn` |
| 38 | `0x22fb0`..`0x2352c` | done | 13689 | `void FUN_253f2642fb0(ulonglong param_1)` | `FUN_253f2620000, FUN_253f26205c0, FUN_253f2620950, FUN_253f2643530` | `MT5_Dispatch, MT5_PositionGetDouble, MT5_PositionGetInteger, MT5_PositionGetString, MT5_PositionSelectByTicket, MT5_SymbolInfoDouble` |
| 39 | `0x23530`..`0x23926` | done | 13827 | `ulonglong FUN_253f2643530(undefined *param_1)` | `FUN_253f2620000, FUN_253f26205c0` | `MT5_Dispatch, MT5_SymbolInfoInteger, MT5_SymbolInfoIntegerRef` |
| 40 | `0x23930`..`0x2430f` | done | 13979 | `void FUN_253f2643930(undefined8 param_1,int *param_2,uint *param_3)` | `FUN_253f2620000, FUN_253f2620060, FUN_253f26205c0` | `MT5_Dispatch, MT5_DoubleToString, MT5_SymbolInfoIntegerRef` |
| 41 | `0x24310`..`0x263cb` | done | 14286 | `void FUN_253f2644310(longlong param_1,longlong param_2,int *param_3)` | `FUN_253f2620000, FUN_253f2620060, FUN_253f26204a0, FUN_253f26205c0, FUN_253f26463d0, FUN_253f26466d0` | `MT5_Dispatch, MT5_DoubleToString, MT5_SymbolInfoIntegerRef` |
| 42 | `0x263d0`..`0x266c6` | done | 14866 | `void FUN_253f26463d0(undefined8 param_1,uint param_2)` | `FUN_253f2620000, FUN_253f2620060, FUN_253f26205c0` | `chưa gắn` |
| 43 | `0x266d0`..`0x26908` | done | 15000 | `void FUN_253f26466d0(undefined8 param_1,double param_2,double param_3,int param_4)` | `FUN_253f2620000, FUN_253f26205c0` | `MT5_Dispatch, MT5_DoubleToString` |
| 44 | `0x26910`..`0x26d0b` | done | 15054 | `void FUN_253f2646910(int param_1)` | `FUN_253f265d690` | `MT5_SymbolInfoInteger, MT5_iHigh` |
| 45 | `0x26d10`..`0x270fb` | done | 15171 | `void FUN_253f2646d10(int param_1)` | `FUN_253f265d8f0` | `MT5_SymbolInfoInteger, MT5_iLow` |
| 46 | `0x27100`..`0x275c7` | done | 15288 | `undefined1 FUN_253f2647100(ulonglong param_1,undefined8 param_2,undefined8 param_3)` | `FUN_253f2620000, FUN_253f26205c0, FUN_253f2620950` | `MT5_Dispatch, MT5_PositionGetString, MT5_PositionSelectByTicket` |
| 47 | `0x275d0`..`0x2b57e` | done | 15412 | `ulonglong FUN_253f26475d0(void)` | `FUN_253f2620000, FUN_253f26204a0, FUN_253f26205c0, FUN_253f2647100, FUN_253f2654580, FUN_253f265e030, FUN_253f265e220, FUN_253f265e5c0, FUN_253f265e7d0, FUN_253f265e870` | `MT5_Dispatch, MT5_PositionGetDouble, MT5_PositionGetInteger, MT5_PositionGetString, MT5_PositionGetTicket, MT5_PositionsTotal, MT5_SymbolInfoDouble, MT5_SymbolInfoInteger, MT5_SymbolInfoTick, MT5_TimeCurrent, MT5_iClose, MT5_iOpen, MT5_iTime` |
| 48 | `0x2b580`..`0x2f57f` | done | 16650 | `ulonglong FUN_253f264b580(void)` | `FUN_253f2620000, FUN_253f2620060, FUN_253f26204a0, FUN_253f26205c0, FUN_253f2647100, FUN_253f2654580, FUN_253f265e030, FUN_253f265e220, FUN_253f265e5c0, FUN_253f265e7d0, FUN_253f265e870` | `MT5_Dispatch, MT5_PositionGetDouble, MT5_PositionGetInteger, MT5_PositionGetString, MT5_PositionGetTicket, MT5_PositionsTotal, MT5_SymbolInfoDouble, MT5_SymbolInfoInteger, MT5_SymbolInfoTick, MT5_TimeCurrent, MT5_iClose, MT5_iOpen, MT5_iTime` |
| 49 | `0x2f580`..`0x30468` | done | 17988 | `void FUN_253f264f580(void)` | `FUN_253f2620000, FUN_253f2620060, FUN_253f26205c0, FUN_253f2653c80, FUN_253f2654580` | `MT5_Dispatch` |
| 50 | `0x30470`..`0x3068d` | done | 18346 | `void FUN_253f2650470(int param_1)` | `FUN_253f2620000, FUN_253f26205c0, FUN_253f2655000` | `MT5_OrderGetDouble, MT5_OrderGetInteger, MT5_OrderGetString, MT5_OrderGetTicket, MT5_OrdersTotal` |
| 51 | `0x30690`..`0x308ad` | done | 18417 | `void FUN_253f2650690(int param_1)` | `FUN_253f2620000, FUN_253f26205c0, FUN_253f2655000` | `MT5_OrderGetDouble, MT5_OrderGetInteger, MT5_OrderGetString, MT5_OrderGetTicket, MT5_OrdersTotal` |
| 52 | `0x308b0`..`0x30b89` | done | 18488 | `void FUN_253f26508b0(void)` | `FUN_253f2620000, FUN_253f26205c0, FUN_253f265e030` | `MT5_PositionGetDouble, MT5_PositionGetInteger, MT5_PositionGetString, MT5_PositionGetTicket, MT5_PositionsTotal` |
| 53 | `0x30b90`..`0x30e58` | done | 18580 | `void FUN_253f2650b90(void)` | `FUN_253f2620000, FUN_253f26205c0, FUN_253f265e030` | `MT5_PositionGetDouble, MT5_PositionGetInteger, MT5_PositionGetString, MT5_PositionGetTicket, MT5_PositionsTotal` |
| 54 | `0x30e60`..`0x30e88` | done | 18688 | `undefined4 FUN_253f2650e60(void)` | `—` | `MT5_TimeCurrent` |
| 55 | `0x30e90`..`0x30eb8` | done | 18701 | `undefined4 FUN_253f2650e90(void)` | `—` | `MT5_TimeCurrent` |
| 56 | `0x30ec0`..`0x311c3` | done | 18715 | `void FUN_253f2650ec0(void)` | `FUN_253f2620000, FUN_253f26205c0, FUN_253f26508b0, FUN_253f2650b90, FUN_253f2655000` | `MT5_Dispatch, MT5_OrderGetInteger, MT5_OrderGetString, MT5_OrderGetTicket, MT5_OrdersTotal` |
| 57 | `0x311d0`..`0x32de5` | done | 18814 | `void FUN_253f26511d0(void)` | `FUN_253f2620000, FUN_253f2620060, FUN_253f26205c0, FUN_253f2655000` | `MT5_Dispatch, MT5_OrderGetDouble, MT5_OrderGetInteger, MT5_OrderGetString, MT5_OrderGetTicket, MT5_OrdersTotal` |
| 58 | `0x32df0`..`0x32fba` | done | 19806 | `int FUN_253f2652df0(void)` | `FUN_253f2620000, FUN_253f26205c0` | `MT5_OrderGetInteger, MT5_OrderGetString, MT5_OrderGetTicket, MT5_OrdersTotal` |
| 59 | `0x32fc0`..`0x3328c` | done | 19877 | `void FUN_253f2652fc0(void)` | `FUN_253f2620000, FUN_253f26205c0, FUN_253f2655000` | `MT5_Dispatch, MT5_OrderGetDouble, MT5_OrderGetInteger, MT5_OrderGetString, MT5_OrderGetTicket, MT5_OrdersTotal` |
| 60 | `0x33290`..`0x3345a` | done | 19974 | `int FUN_253f2653290(void)` | `FUN_253f2620000, FUN_253f26205c0` | `MT5_OrderGetInteger, MT5_OrderGetString, MT5_OrderGetTicket, MT5_OrdersTotal` |
| 61 | `0x33460`..`0x3373c` | done | 20045 | `void FUN_253f2653460(void)` | `FUN_253f2620000, FUN_253f26205c0, FUN_253f2655000` | `MT5_Dispatch, MT5_OrderGetDouble, MT5_OrderGetInteger, MT5_OrderGetString, MT5_OrderGetTicket, MT5_OrdersTotal` |
| 62 | `0x33740`..`0x3396d` | done | 20142 | `double FUN_253f2653740(int param_1,int param_2)` | `—` | `MT5_SymbolInfoInteger, MT5_iHigh` |
| 63 | `0x33970`..`0x33b8e` | done | 20200 | `double FUN_253f2653970(int param_1,int param_2)` | `—` | `MT5_SymbolInfoInteger, MT5_iLow` |
| 64 | `0x33b90`..`0x33c7b` | done | 20256 | `void FUN_253f2653b90(void)` | `—` | `MT5_OrdersTotal, MT5_PositionGetTicket` |
| 65 | `0x33c80`..`0x34578` | done | 20303 | `FUN_253f2653c80(undefined *param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,` | `FUN_253f2620000, FUN_253f26205c0, FUN_253f2620950, FUN_253f2643530` | `MT5_Dispatch, MT5_SymbolInfoInteger, MT5_SymbolInfoIntegerRef` |
| 66 | `0x34580`..`0x34ff8` | done | 20541 | `void FUN_253f2654580(int param_1)` | `FUN_253f2620000, FUN_253f26204a0, FUN_253f26205c0` | `chưa gắn` |
| 67 | `0x35000`..`0x35803` | done | 21110 | `void FUN_253f2655000(ulonglong param_1)` | `FUN_253f2620000, FUN_253f2620060, FUN_253f26205c0, FUN_253f2620950` | `MT5_Dispatch, MT5_OrderGetDouble, MT5_OrderGetInteger, MT5_OrderGetString, MT5_OrderSelect, MT5_SymbolInfoDouble, MT5_SymbolInfoInteger, MT5_SymbolInfoTick` |
| 68 | `0x35810`..`0x371f0` | done | 21348 | `void FUN_253f2655810(double param_1,int param_2)` | `FUN_253f2620000, FUN_253f2620060, FUN_253f26205c0, FUN_253f2636ff0, FUN_253f26571f0` | `MT5_AccountInfoDouble, MT5_Dispatch, MT5_SymbolInfoDouble` |
| 69 | `0x371f0`..`0x3cfa5` | done | 21956 | `double FUN_253f26571f0(double param_1)` | `FUN_253f2620000, FUN_253f2620060, FUN_253f26205c0` | `MT5_AccountInfoString, MT5_iClose` |
| 70 | `0x3cfb0`..`0x3d63a` | done | 25177 | `ulonglong FUN_253f265cfb0(double param_1)` | `FUN_253f2620000, FUN_253f2620060, FUN_253f26205c0` | `MT5_Dispatch, MT5_SymbolInfoDouble` |
| 71 | `0x3d640`..`0x3d690` | done | 25398 | `bool FUN_253f265d640(void)` | `—` | `MT5_AccountInfoInteger, MT5_OrdersTotal` |
| 72 | `0x3d690`..`0x3d8e7` | done | 25416 | `undefined8 FUN_253f265d690(double param_1)` | `FUN_253f2620000, FUN_253f26205c0` | `MT5_OrderGetDouble, MT5_OrderGetInteger, MT5_OrderGetString, MT5_OrderGetTicket, MT5_OrdersTotal` |
| 73 | `0x3d8f0`..`0x3db4b` | done | 25495 | `undefined8 FUN_253f265d8f0(double param_1)` | `FUN_253f2620000, FUN_253f26205c0` | `MT5_OrderGetDouble, MT5_OrderGetInteger, MT5_OrderGetString, MT5_OrderGetTicket, MT5_OrdersTotal` |
| 74 | `0x3db50`..`0x3e023` | done | 25574 | `ulonglong FUN_253f265db50(undefined8 param_1,undefined4 param_2,double param_3)` | `FUN_253f2620000, FUN_253f26205c0, FUN_253f2662eb0` | `MT5_AccountInfoDouble, MT5_AccountInfoString, MT5_Dispatch` |
| 75 | `0x3e030`..`0x3e21c` | done | 25745 | `void FUN_253f265e030(ulonglong param_1)` | `FUN_253f2642fb0` | `MT5_PositionGetDouble, MT5_PositionGetInteger, MT5_PositionSelectByTicket` |
| 76 | `0x3e220`..`0x3e5b7` | done | 25791 | `double FUN_253f265e220(int param_1,double param_2,double param_3,longlong param_4)` | `FUN_253f2638390` | `MT5_Dispatch, MT5_PositionsTotal, MT5_SymbolInfoInteger` |
| 77 | `0x3e5c0`..`0x3e7cf` | done | 25876 | `double FUN_253f265e5c0(double param_1,longlong param_2)` | `FUN_253f2638390` | `MT5_Dispatch, MT5_PositionsTotal` |
| 78 | `0x3e7d0`..`0x3e86b` | done | 25936 | `undefined8 FUN_253f265e7d0(longlong param_1)` | `—` | `MT5_TimeCurrent` |
| 79 | `0x3e870`..`0x3e8ee` | done | 25965 | `void FUN_253f265e870(longlong param_1)` | `—` | `MT5_TimeCurrent` |
| 80 | `0x3e8f0`..`0x42ea4` | done | 25990 | `ulonglong FUN_253f265e8f0(longlong param_1)` | `FUN_253f2620000, FUN_253f26203c0, FUN_253f26205c0` | `MT5_AccountInfoInteger, MT5_AccountInfoString, MT5_MQLInfoInteger` |
| 81 | `0x42eb0`..`0x43244` | done | 27764 | `undefined4 FUN_253f2662eb0(void *param_1,undefined4 param_2,uint param_3)` | `FUN_253f2620000, FUN_253f26201e0` | `MT5_AccountInfoDouble, MT5_Dispatch, MT5_SymbolInfoTick` |
| 82 | `0x43250`..`0x44e1b` | done | 27880 | `void FUN_253f2663250(int param_1,int param_2,void *param_3,undefined8 param_4,int param_5,` | `FUN_253f2620000, FUN_253f2620060, FUN_253f26205c0` | `MT5_Dispatch, MT5_IntegerToString, MT5_ObjectSetInteger, MT5_ObjectSetString` |
| 83 | `0x44e20`..`0x4502b` | done | 28825 | `void FUN_253f2664e20(int param_1,void *param_2,undefined8 param_3,undefined8 param_4)` | `FUN_253f2620000, FUN_253f2620060, FUN_253f26205c0` | `MT5_IntegerToString, MT5_ObjectSetString` |
| 84 | `0x45030`..`0x453fc` | done | 28920 | `void FUN_253f2665030(int param_1,int param_2)` | `FUN_253f2665030` | `chưa gắn` |
| 85 | `0x45400`..`0x4a936` | done | 29074 | `double FUN_253f2665400(double param_1)` | `FUN_253f2620000, FUN_253f2620060, FUN_253f26205c0` | `MT5_AccountInfoString, MT5_iClose` |
| 86 | `0x4a940`..`0x4b73b` | done | 31971 | `ulonglong FUN_253f266a940(void)` | `FUN_253f2620000, FUN_253f2620060, FUN_253f26205c0` | `MT5_Dispatch` |


Phạm vi chỉ là 86 dải hàm của một snapshot; không kết luận toàn EA. Hàm lỗi giữ nguyên lý do, không tự điền.
