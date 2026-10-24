# Kết quả khôi phục mã — lượt 23/10/2026

Cập nhật tiếp 24/10: mỗi bot khớp 3.096 ca chọn cách khớp lệnh và
1.607 ca chuẩn bị yêu cầu lệnh chờ, gồm đủ 35 trường và thứ tự gọi;
thêm 16 ca riêng cho giá dừng/chốt không xác định cũng khớp.
[Phạm vi](PHAN-TICH-TAO-YEU-CAU-CHO-BOT-1-3.md). Chưa chạy bước gửi
lệnh trong phần mới, chưa có EA chính hoàn chỉnh cho bot 1 và 3.

Cập nhật 24/10: phần đổi giờ theo mùa của bot 1 và 3 đã có nguồn MQL5,
khớp 4.737/4.737 ca mỗi bot; kết quả và thứ tự gọi trùng từng byte,
biên dịch 0 lỗi/cảnh báo. [Phạm vi](PHAN-TICH-GIO-MUA-HE-BOT-1-3.md).
Toàn bộ hai bot vẫn chưa có EA chính; không đổi số ca này thành % hoàn thành.

Cập nhật 24/10: kiểm khối lượng hợp lệ đã có nguồn MQL5, khớp
1.834/1.834 ca mỗi bot; gồm 27 ca dừng vì chia 0 thật cho mỗi bot.
Đã sửa các điểm yếu của bộ kiểm chọn chiến lược do Claude Opus 5.5
`max` nêu, rồi chạy lại: bot 1 256/256 và bot 3 7.724/7.724.
[Khối lượng hợp lệ](PHAN-TICH-KHOI-LUONG-HOP-LE-BOT-1-3.md),
[chọn chiến lược và đánh giá độc lập](PHAN-TICH-CHON-CHIEN-LUOC-MQL5-BOT-1-3.md).

Quy trình hiện hành: [AGENTS.md](../../AGENTS.md) và
[bản đồ 33 phần cùng toàn bộ hàm/cài đặt đã thấy](BAN-DO-TOAN-BO-BOT-1-3.md).
Đang rà phân tích toàn bộ trước khi viết thêm phần mới. Đã nối 152 dòng
cài đặt với vị trí lưu/mặc định, khớp 648/648 và 720/720 lần so;
[chi tiết](PHAN-TICH-CAI-DAT-BOT-1-3.md). Hai đoạn chọn chiến lược bot 3
khớp 7.724 ca phân tích với mã gốc; nguồn MQL5 mới cũng khớp lại đủ ca;
[giới hạn mã gốc](PHAN-TICH-CHON-CHIEN-LUOC-BOT-3.md) và
[báo cáo nguồn mới](PHAN-TICH-CHON-CHIEN-LUOC-MQL5-BOT-1-3.md).
Chưa có EA hoàn chỉnh.
Bot 1 đã khớp đủ 256 tổ hợp bật/tắt, tổng cộng 2.048 lần kiểm nhánh;
[phạm vi](PHAN-TICH-BAT-TAT-BOT-1.md).
Lượt tiếp đã đọc trực tiếp 152 nhãn nhìn thấy, nối 28 lựa chọn/7 menu,
và dựng phần nạp vốn khớp 616 ca mỗi bot, biên dịch sạch.
[Bằng chứng và giới hạn](PHAN-TICH-MENU-VA-KHOI-TAO-BOT-1-3.md).

Trạng thái: **đang khôi phục**. Không bot nào được xác nhận giống bản gốc 100%.

Cập nhật 24/10/2026: đã dựng phần chọn chiến lược bằng MQL5. Bot 1 khớp
256/256 ca bật/tắt; bot 3 khớp 7.724/7.724 ca cho hai đoạn chọn, gồm
chế độ cố định, tự chọn và 512 tổ hợp thủ công. Phần này vẫn chưa là EA
hoàn chỉnh và chưa chứng minh thân chiến lược, giao dịch hoặc giao diện.
[Báo cáo](PHAN-TICH-CHON-CHIEN-LUOC-MQL5-BOT-1-3.md).

Cập nhật tiếp theo: đã phân tích bot 1 và bot 3, xuất đủ các hàm trong bảng mã chụp mới, dựng mức giá, kiểm lệnh chờ gần và bảng tham số gốc. Phần mới khớp 1.096 ca mỗi bot và 102 giá trị tham số; xem [PHAN-TICH-VAO-LENH-BOT-1-3.md](PHAN-TICH-VAO-LENH-BOT-1-3.md). Chưa có EA hoàn chỉnh cho hai bot này.

Cập nhật mới nhất: thêm phần điều chỉnh khoảng cách/thời hạn và bảng cơ bản
của chiến lược; 1.050 ca bot 1 và 1.034 ca bot 3 khớp, cùng 577 giá trị
trong bảng. Xem [PHAN-TICH-DIEU-CHINH-BOT-1-3.md](PHAN-TICH-DIEU-CHINH-BOT-1-3.md).

Đã ghép thêm đổi tiền tệ với tính khối lượng: bot 1 khớp 783/783 ca,
bot 3 khớp 966/966 ca; [phạm vi kiểm](PHAN-TICH-KHOI-LUONG-BOT-1-3.md).

Đã dựng thêm cập nhật vốn sau khi rút tiền: mỗi bot khớp 915/915 ca,
ghi/đọc qua hai lần mở MT5 riêng đạt; [bằng chứng](PHAN-TICH-RUT-TIEN-BOT-1-3.md).

Bot 13 đã trùng bản gốc **ở 7 ca máy thử đã chạy**: mọi dòng đặt/khớp/sửa/hủy/đóng lệnh, số dư, bảng lệnh và bảng giao dịch trong báo cáo, cùng danh sách tham số. Như vậy chưa đủ để nói giống 100%. Bản dựng vẫn thiếu bảng hiển thị, nhãn lời/lỗ, lọc tin và các nhánh ngoài máy thử (mục 6).

## Ba loại mã (để không nhầm)

| Loại | Có trong lượt này? | Ở đâu |
|---|---|---|
| **Mã nguồn gốc** (MQL5 của tác giả) | **Không có.** Lịch sử Git không chứa, không khôi phục được | — |
| **Mã trung gian** (C giả lập do Ghidra xuất từ mã máy; tên `FUN_…`, `DAT_…` là tên tự sinh) | 15 tệp, khôi phục nguyên byte | `bot-cua-toi-N/phan-tich/**/ma-trung-gian*.c` |
| **Nguồn dựng lại** (MQL5 viết lại theo bằng chứng) | Bot 13; thêm các phần mức giá, lệnh chờ gần và bảng tham số bot 1/3, chưa phải EA hoàn chỉnh | `bot-cua-toi-13/source/MQL5/`, `bot-cua-toi-1/source/MQL5/`, `bot-cua-toi-3/source/MQL5/` |

## Tóm tắt

| Việc | Kết quả | Bằng chứng |
|---|---|---|
| A. Khôi phục từ commit `d2c4292` | 250 tệp, 21,8 MB; mọi tệp kiểm lại mã object Git trước khi ghi | [NGUON-GOC.json](NGUON-GOC.json) |
| B. Nguồn bot 13 đổi tên | 4 tệp; 0 dòng còn tên cũ trong `source/` | mục 2 |
| C. Biên dịch | 4 lần biên dịch, đều **0 lỗi, 0 cảnh báo** | `bot-cua-toi-13/bang-chung/bien-dich/` |
| C. So bản gốc/bản dựng trong máy thử (tài khoản demo) | 4 ca cũ + 3 ca dài mới: **trùng từng dòng hoạt động và từng ô báo cáo**. Một khác biệt (tiêu đề nhóm tham số) đã sửa và chạy lại | mục 4.1 |
| C. Kiểm lại bằng chứng cũ | Nhật ký cũ cho lại đúng 533/169/183/123 và 31 dòng trùng; 52/52 tệp chụp mã máy đúng mã băm | mục 4.2 |
| D. Nhánh mới: khối lượng ngoài máy thử (RVA `0x169f0`) | Viết sang MQL5; **2152/2152 ca trùng từng bit** với lệnh máy gốc chạy trong bộ mô phỏng CPU | mục 5 |

## 1. Nguồn dữ liệu

- Kho Git (chỉ đọc bằng `--git-dir`): `C:\Users\NTD\AppData\Local\Temp\Bot-Market-Demo-git-backup-20261022`
- Commit `d2c42927f218146f581b8ccf00b355f9840648e2`, cây `ddf12f6e4bfd00427b9628823f20f9a29027d32b`.
- Công cụ: [cong-cu/khoi-phuc-tu-git.py](cong-cu/khoi-phuc-tu-git.py). Với mỗi tệp, công cụ tính lại SHA-1 của object Git, rồi ghi SHA-256, đường dẫn cũ và đường dẫn mới vào `NGUON-GOC.json`. Công cụ không ghi đè tệp khác nội dung.
- EX5 gốc bot 13 (chỉ đọc): `…\Terminal\820755052E4765D7D56E6DAAFBB28091\MQL5\Experts\Market\`, SHA-256 `c705e2bbbb66d18e31e2a375625dfdef69243cb73e684af3a846d6ab33fabe73`; trùng mã ghi trong hồ sơ cũ. Bản dùng trong máy thử riêng cũng có mã này. Tôi không dùng 17 EX5 đã chỉnh trong dự án.

| Loại tệp khôi phục | Số tệp |
|---|---|
| Dữ liệu chụp mã máy | 158 |
| Bằng chứng, ghi chú, nhật ký so cũ | 54 |
| Công cụ, tài liệu cũ (`cong-cu-cu/`, `tai-lieu-cu/`) | 19 |
| Mã trung gian C | 15 |
| Nguồn dựng lại bot 13 (đã đổi tên) | 4 |

Bằng chứng giữ nguyên từng byte nên nội dung có thể còn tên cũ; chỉ đường dẫn được đặt tên mới.
**Không khôi phục**: các bản EX5, `research-copies/`, `docs/history`, bảng chuyển dự án 400 KB, ảnh/báo cáo HTM cũ, ảnh tài nguyên bot 8, các lượt chụp phụ (`twcfg*`, `control02`, `api_probe_v6`…), bản EX5 cũ đã biên dịch, quy tắc cũ của trợ lý. Tất cả vẫn còn trong commit.

| Bot | Đã có | Mã trung gian C |
|---|---|---|
| 1, 2, 4, 5, 6, 7, 8, 11, 12, 14, 15 | 1 bộ chụp mã máy (`phan-tich/ban-ex5-NN/`) | có |
| 9 | 2 bộ chụp (2 EX5) | có cả 2 |
| 10 | 2 bộ chụp (2 EX5) | chỉ bản `ban-ex5-10`; `ban-ex5-17` không có |
| 3 | 1 bộ chụp | **không có** (hồ sơ cũ chưa xuất) |
| 13 | Chụp mã máy + dữ liệu chương trình, C v5, ký hiệu, nhật ký so v1/v2, kết quả kiểm cũ, nguồn MQL5 | có (v5) |

## 2. Bot 13 — nguồn MQL5

### 2.1 Phần lấy từ lịch sử (nguồn dựng lại cũ)

| Tệp mới | Object Git | SHA-256 trước → sau đổi tên |
|---|---|---|
| `Experts/bot-cua-toi-13/bot-cua-toi-13.mq5` | `535eba56…` | `619841d2…` → `c9954ba2…` |
| `Include/bot-cua-toi-13/Bot13Inputs.mqh` | `0a4218af…` | `52d61648…` → `2294955a…` |
| `Include/bot-cua-toi-13/Bot13Settings.mqh` | `36cd3428…` | `fdd7c358…` → `aeef3db5…` |
| `Include/bot-cua-toi-13/Bot13Filters.mqh` | `0d178904…` | `408de78f…` → `f41adc99…` |

- 3 tệp `.mqh` trùng đúng bản đã biên dịch cho lượt so v2 (mã băm bản UTF-16 trong `version2-build.json`). Tệp `.mq5` = bản v2 bỏ 5 dòng `OnTester`. Phần bỏ này nay đã chạy máy thử: báo cáo bản dựng có `OnTester result: 0`, giống bản gốc.
- Đổi tên theo bảng `DOI_TEN` trong công cụ: tên tệp, `#include`, định danh `Twister…` → `Bot13…`, dòng `Print`, và giá trị mặc định `TradeComment` (ghi chú lệnh) `"TwisterPro"` → `"Bot13"`. Các thông số số học, logic và chốt chặn ngoài máy thử giữ nguyên.
- Kiểm tên cũ: `grep -i twister` trên `bot-cua-toi-13/source` cho 0 dòng.

### 2.2 Phần làm mới trong lượt này

- `Include/bot-cua-toi-13/Bot13LiveVolume.mqh`: hàm khối lượng ngoài máy thử (mục 5).
- `Scripts/bot-cua-toi-13/Bot13LiveVolumeCheck.mq5`: script kiểm, không giao dịch.
- `bot-cua-toi-13.mq5`:
  - thêm 1 `#include`, 1 dòng ghi chú;
  - thêm nhánh `if(!r_tester)` trong `RecoveredPlace`; nhánh máy thử giữ nguyên lệnh, chỉ lùi lề;
  - thêm **10 dòng `input group`**, đúng chuỗi và vị trí như danh sách tham số bản gốc (mục 4.1).
- Bản khác biệt so với lúc khôi phục (thêm 28 dòng, bớt 4 dòng): [thay-doi-nguon-sau-khoi-phuc.diff](bot-cua-toi-13/bang-chung/thay-doi-nguon-sau-khoi-phuc.diff). Nguồn hiện hành trùng đúng đầu vào của `b13-build-03` (6/6 tệp).

## 3. Biên dịch

Công cụ: [cong-cu/bien-dich.ps1](cong-cu/bien-dich.ps1). Dùng MetaEditor của máy thử riêng, SHA-256 `cf2750bd…`, giống máy thử cũ. `Trade.mqh` có SHA-256 `96e67816…`, giống lượt v2.

| Lượt | Đích | Kết quả | SHA-256 EX5 |
|---|---|---|---|
| `b13-build-01` | EA vừa khôi phục, đã đổi tên | 0 lỗi, 0 cảnh báo | `3a2b6a051f0d51a6…` |
| `b13-check-lv-01` | Script kiểm | 0 lỗi, 0 cảnh báo | `b47a7364005dd923…` |
| `b13-build-02` | EA có nhánh mới | 0 lỗi, 0 cảnh báo | `f8f219ef2ccc75c7…` |
| `b13-build-03` | EA có thêm `input group` (**bản hiện hành**) | 0 lỗi, 0 cảnh báo | `d6b4fd2dc2d4c794…` |

MetaEditor trả mã thoát 1 dù nhật ký ghi 0 lỗi; công cụ dựa vào dòng `Result:` trong nhật ký.

Các lỗi gặp trước khi biên dịch được đều là lỗi môi trường/công cụ, **không phải lỗi nguồn**:

1. `MISSING_ISOLATED_MT5`: máy thử chép sang thiếu `Include/Trade/Trade.mqh`. Cách sửa: lấy 7 tệp thư viện chuẩn từ commit cũ, đổi về CRLF; cả 7 trùng mã băm đầu vào biên dịch v2. Các tệp này chỉ chép vào máy thử tạm.
2. `COMPILER_DID_NOT_CREATE_LOG`: với cờ `/portable`, MetaEditor thoát mà không biên dịch. Cách sửa: bỏ cờ này trong công cụ.

## 4. Chạy thử và so sánh

### 4.1 So bản gốc với bản dựng trong máy thử (Strategy Tester, tài khoản demo)

**Môi trường**

- Máy thử riêng: `.local/claude-recovery-20261023/mt5`.
  - Chép từ máy thử cũ: `terminal64` `d92c969e…`, `metatester64` `5033d9d4…`, build 6230.
  - Dữ liệu `XAUUSD_NOCOST_V2` 2024–2026.
- Người dùng đã chép `accounts.dat`/`servers.dat` của tài khoản demo vào máy thử riêng.
- Lượt nào cũng xác nhận đúng tài khoản. Nhật ký terminal ghi `'279786616': authorized on Exness-MT5Trial8` và `trading has been enabled, demo account - hedging mode`.
- Bộ chạy [cong-cu/chay-may-thu.py](cong-cu/chay-may-thu.py) đọc hai dòng này sau mỗi lượt và **tự dừng** nếu thấy tài khoản thật hoặc không xác nhận được tài khoản demo.
- Mọi lượt chỉ là mô phỏng trong Strategy Tester; cấu hình có `[Experts] Enabled=0`, `AllowLiveTrading=0`. Không có lệnh nào gửi tới tài khoản.
- Hai bản dùng cùng dữ liệu, kỳ, khung M15, kiểu giá, vốn 10000 USD, đòn bẩy 1:500 và tham số. `TradeComment=Bot13` cho cả hai.

**Kết quả** (tổng hợp máy đọc được: [luot-20261023/tong-hop.json](bot-cua-toi-13/bang-chung/so-hanh-vi/luot-20261023/tong-hop.json); chi tiết từng ca trong `so-sanh/`)

| Ca | Kỳ, kiểu giá, tham số chính | Dòng hoạt động gốc = dựng | Số dư cuối (cả hai) | Báo cáo: số dòng bảng lệnh / giao dịch (kể cả tiêu đề) |
|---|---|---|---|---|
| ticks1 | 29/09–20/10/2026, mọi tick; mặc định | 533 = 533 | 13708.46 | 23 / 19, trùng |
| ticks2 | 01–06/10/2026, mọi tick; chế độ 2 | 169 = 169 | 16966.65 | 10 / 11, trùng |
| delay | 29/09–20/10/2026, OHLC M1; lot cố định, giới hạn lỗ, trì hoãn dời dừng, SL/TP/TSL riêng | 183 = 183 | 9994.34 | 40 / 35, trùng |
| broker1 | 29/09–20/10/2026, OHLC M1; kiểu sàn 1, Mode1Stop=1, magic âm | 123 = 123 | 13506.05 | 21 / 17, trùng |
| dai1 (mới) | 06/01/2025–28/09/2026, OHLC M1; mặc định | 4392 = 4392 | 2180964.77 | 676 / 557, trùng |
| dai2 (mới) | như dai1; chế độ 2, bảo vệ sụt vốn, 2 lần lỗ, hệ số 0.37, giới hạn lỗ ngày 1%, rủi ro 1.5% | 5901 = 5901 | 2993592.00 | 941 / 789, trùng |
| dai3 (mới) | như dai1; kiểu sàn 1, trì hoãn 45 giây, SL/TP/TSL riêng, lot cố định 0.37, magic âm, tắt lọc ngày lễ | 3254 = 3254 | 30493.25 | 575 / 455, trùng |

- "Dòng hoạt động" là mọi dòng có giờ mô phỏng: đặt lệnh, khớp, sửa dừng lỗ/chốt lời, hết hạn, hủy, đóng. Bộ so: [cong-cu/so-nhat-ky-may-thu.py](cong-cu/so-nhat-ky-may-thu.py).
- Báo cáo `.htm` được so từng ô trong phần kết quả, bảng lệnh và bảng giao dịch. Bộ so: [cong-cu/so-bao-cao-mt5.py](cong-cu/so-bao-cao-mt5.py).
- Bản gốc chạy lại cũng trùng hoàn toàn nhật ký gốc cũ (lượt v2, máy chủ Exness-MT5Trial14) ở cả 4 ca. Vậy môi trường mới cho lại đúng kết quả cũ.

**Khác biệt đã tìm thấy và đã sửa**

- Lượt r1 (EA `b13-build-02`): giao dịch trùng hết, nhưng danh sách tham số khác **ngay dòng đầu**:
  - bản gốc in `--- IDENTIFICATION ---=`, bản dựng in `InpMagic=31250001`;
  - bản gốc có 38 dòng, bản dựng 28 dòng;
  - báo cáo cũng thiếu 10 tiêu đề nhóm.
- Cách sửa: thêm 10 dòng `input group` đúng chuỗi trong nhật ký gốc.
- Lượt r2 (EA `b13-build-03`): 38/38 dòng tham số trùng; giao dịch vẫn trùng ở 4 ca; phần cài đặt báo cáo trùng (chỉ khác tên EA, đúng như mong đợi). 3 ca dài chạy bằng bản này.

**Mã băm chính** (đủ trong `ket-qua-chay.jsonl`)

- EA: gốc `c705e2bb…`; dựng r1 `f8f219ef…`; dựng r2 và ca dài `d6b4fd2d…`.
- Tệp `2026.hcc` bị terminal ghi lại ở mỗi lượt nên mã băm đổi (ghi trước/sau từng lượt). So với bản chép từ máy thử cũ: khác 13 byte trong 8 KB đầu tệp và dài thêm 189 byte. Kết quả bản gốc vẫn trùng nhật ký cũ, nên phần đổi này không làm khác kết quả các kỳ đã thử.

**Lần thử trước khi có tài khoản**: 1 lỗi đường dẫn `/config` (đã sửa công cụ) và 5 lần báo `tester not started because the account is not specified`. Nhật ký trong `luot-20261023/lan-thu-loi-tai-khoan/`.

### 4.2 Kiểm lại bằng chứng cũ (không phải lượt chạy mới)

- Trên nhật ký cũ đã khôi phục, bộ so mới cho lại đúng số dòng trùng: ticks1 533, ticks2 169, delay 183, broker1 123, m1_a 31. Số dư cuối cũng trùng: 13708.46 / 16966.65 / 9994.34 / 13506.05 / 9410.10.
- 10 nhật ký trùng mã băm ghi trong `version1/2-comparison.json` cũ.
- 52/52 vùng mã máy đã chụp (15 bot) trùng SHA-256 trong `capture.json`.
- Con số cũ 400/400 (khởi tạo) và 800/800 (ba bộ lọc) mới chỉ **đọc lại** từ `comparison.json`, chưa chạy lại. Công cụ cũ cần bố cục thư mục cũ.

## 5. Phần D — nhánh đã giải nghĩa: khối lượng ngoài máy thử

**Bằng chứng từ mã máy**:

- Trong hai hàm đặt lệnh chờ (RVA `0xca60` mua, `0xd280` bán), khi cờ RVA `0x2258c` bằng 0, bản gốc gọi RVA `0x169f0` thay cho phép kiểm ký quỹ.
- Cờ này được gán `MQLInfoInteger(MQL_TESTER)` lúc khởi tạo (mã 6 theo bảng enum đã đo).
- Bản dựng cũ chỉ có nhánh máy thử.

**Hàm làm gì** (đọc từ lệnh máy; bản C của Ghidra sai ở vài chỗ khi gặp NaN, bản MQL5 làm theo lệnh máy):

1. Lấy giá Ask (mua) hoặc Bid (bán) và ký quỹ trống.
2. Nếu `SYMBOL_VOLUME_LIMIT` > 0: cộng khối lượng các vị thế và lệnh chờ cùng mã, cùng chiều. Trần = min(khối lượng tối đa, giới hạn − đã dùng), không âm.
3. Lấy min(khối lượng xin, trần), làm tròn xuống theo bước. Nếu nhỏ hơn mức tối thiểu thì trả 0.
4. Gọi `OrderCalcMargin`. Nếu ký quỹ không có hoặc vượt 90% ký quỹ trống, giảm 1 bước rồi thử lại, tối đa 100000 lần.
5. Làm tròn 2 số lẻ. Bản gốc dùng hằng ±0.5000001, nên có lúc khác làm tròn thông thường (ví dụ 853.015 → 853.02).

**Kiểm chứng** ([kiem-tra/kiem-khoi-luong-ngoai-may-thu.py](bot-cua-toi-13/kiem-tra/kiem-khoi-luong-ngoai-may-thu.py), lượt `lv-20261023-01`):

- Phía gốc: chạy đúng mã máy đã chụp (SHA-256 `daf9c801…`, dữ liệu `69d51847…`) trong unicorn 2.1.4 (gói trùng mã băm biên nhận cũ). Các hàm MT5 được thay bằng dữ liệu giả lập.
- Phía MQL5: script chạy trên terminal riêng, không máy thử, cùng dữ liệu.
- Kết quả: **2152/2152 ca trùng từng bit**. Chuỗi lời gọi MT5 (thứ tự, mã thuộc tính, khối lượng, giá) cũng trùng. 17 mã enum trùng hằng trong lệnh máy.
- Bộ ca gồm:
  - 1046 ca quét vị thế/lệnh chờ (có vé 0, khác mã, loại lệnh lạ);
  - NaN, vô cực, số rất lớn;
  - 793 ca trên 200 lời gọi; dài nhất 100023 lời gọi, có ca dừng đúng ở mốc 100000 lần;
  - 26 ca mà làm tròn kiểu gốc khác làm tròn đúng; `NormalizeDouble` của MQL5 cho đúng kết quả gốc ở cả 26 ca.
- Thêm: giá trị `m_ticket` của `COrderInfo` toàn cục (RVA `0x22330`) sau hàm gốc khớp quy tắc ở 2152/2152 ca. Trong hàm này giá trị đó chỉ được ghi, không được đọc.
- Tệp: `bang-chung/kiem-khoi-luong-ngoai-may-thu/lv-20261023-01/`.
  - `cases.bin`: `390a1c27…`
  - hai tệp kết quả trùng nhau: `d9b751b9…`

**Giới hạn của phép kiểm này**:

- Dữ liệu là giả lập, không phải sàn thật. `OrderCalcMargin` được thay bằng quy tắc "khối lượng × hệ số".
- Không mô hình chuỗi rỗng.
- Chỉ kiểm một hàm.
- Nhánh này **không chạy trong máy thử** (bản gốc cũng không dùng nó trong máy thử). Nó cũng chưa chạy được trong EA, vì `OnInit` vẫn dừng ngoài máy thử. Chốt dừng này mới được xác nhận bằng đọc mã.

## 6. Chưa đạt, còn thiếu

- **Bot 13** còn thiếu:
  - bảng hiển thị (`ShowPanel`: vẽ bằng tài nguyên/`TextOut`);
  - nhãn lời/lỗ;
  - lọc tin (dùng `WebRequest`, chỉ ngoài máy thử);
  - các dòng `Print` khi không ở máy thử hoặc ở chế độ hiển thị (cờ RVA `0x2258f`);
  - chạy ngoài máy thử (EA tự dừng);
  - chế độ máy thử có hiển thị (`Visual=1`; bản dựng tự dừng), khởi động lại/lưu trạng thái, các nhánh lỗi.
- **Phạm vi so máy thử**: 7 ca trên một mã giá tùy chỉnh, không phí, hai khoảng ngày (09–10/2026 và 01/2025–09/2026). Có những nhánh mà các ca chưa chắc đi qua, ví dụ ngày lễ sau 28/09/2026 (11–12/2026, 2027), tràn khối lượng, lỗi gửi lệnh. Kết quả trùng chỉ chứng minh cho các ca đã chạy.
- **Lệch nhỏ đã thấy, chưa sửa**: ở nhánh ký quỹ trong máy thử, mã dựng `margin<=0.0 || margin>free*0.9` khác lệnh máy gốc khi ký quỹ hoặc ký quỹ trống là NaN. Máy thử thật không tạo ra NaN ở đây nên không kiểm được bằng chạy; chưa sửa.
- **Bot 1 và 3**: đã có mã C mới và các phần MQL5 về mức giá, lệnh chờ gần, bảng tham số gốc; chưa có EA hoàn chỉnh. Kết quả và giới hạn ở [báo cáo riêng](PHAN-TICH-VAO-LENH-BOT-1-3.md).
- **Bot 2, 4–12, 14, 15**: chỉ có mã trung gian và dữ liệu chụp, **chưa có MQL5**. Một EX5 của bot 10 chưa có mã trung gian.
- Công cụ cũ trong `cong-cu-cu/` và `bot-cua-toi-13/kiem-tra/cu/` còn theo đường dẫn cũ, chưa chạy trực tiếp được.
- Script kiểm làm terminal thoát mã 1 (script thử đơn giản thì mã 0). Chưa rõ nguyên nhân; tệp kết quả đủ 2152 ca và đọc kiểm không thừa/thiếu byte.
- Nhật ký do `chay-may-thu.py` ghi có kết thúc dòng `\r\r\n`. Các bộ so đã xử lý; nội dung không mất.

## 7. Tác động ngoài thư mục được phép

- **Thư mục AppData do lượt này tạo**: MetaEditor/terminal tạo `C:\Users\NTD\AppData\Roaming\MetaQuotes\Terminal\CD664B6C839F0F916A29FD5C370FA154` hai lần. Thư mục chỉ chứa đường dẫn bản tạm và nhật ký biên dịch của lượt này. Cả hai lần đều đã chép sang `.local/claude-recovery-20261023/tam/` rồi xóa.
- **Tệp dùng chung** `…\Terminal\Community\mql5.community.dat`: giờ sửa trùng lần khởi động terminal riêng cuối của tôi (08:58:56, rồi 09:29:45). Không có bản trước để so; tôi không sửa tay và không khôi phục tệp này.
- **Trong máy thử riêng**: terminal đăng nhập tạo `bases/Exness-MT5Trial8`. Trước đó tôi đã sửa `config/common.ini` (bỏ `Login`/`Server` cũ), thêm `terminal.lic` và chuyển `bases/Exness-MT5Trial14` ra `tam/`.
- Tôi không đụng terminal chính đang chạy (PID 32308) hay dữ liệu tài khoản của nó, máy thử cũ, các EX5 hay lịch sử Git. Tôi chỉ dừng các tiến trình do chính lượt này mở. Sau khi xong không còn tiến trình MT5 nào của máy thử riêng.
- Thư mục tạm `.local/claude-recovery-20261023/` (~400 MB: máy thử chép kèm dữ liệu tài khoản demo, thư viện Python, gói tải về, `tam/`) cần cho việc chạy lại phép kiểm. Khi không cần nữa, nên xóa, nhất là `mt5/config/accounts.dat`.

## 8. Bước tiếp

Theo yêu cầu mới nhất, ưu tiên phân tích và khôi phục bot 1 và bot 3. Danh sách dưới đây là việc còn lại của bot 13 để giữ lại khi quay lại bot này.

1. Bảng hiển thị và nhãn lời/lỗ.
   - Mã máy có `ResourceCreate`/`TextOut`; cần chạy máy thử có hiển thị.
   - Trước đó phải cho bản dựng chạy với `Visual=1`. Việc này đổi chốt dừng hiện có, cần chủ dự án đồng ý.
2. Các dòng `Print` sau khi gửi lệnh: thao tác `0xd`, chuỗi tại `0x1e660`/`0x1e6b8`, chỉ in khi không ở máy thử hoặc ở chế độ hiển thị.
3. Thêm ca máy thử cho ngày lễ sau 28/09/2026, lỗi gửi lệnh, dữ liệu sàn có phí.

Danh sách và mã băm mọi tệp tạo mới hoặc đã sửa trong lượt: [TEP-MOI.json](TEP-MOI.json).
