# Sửa dừng lỗ/chốt lời theo vé — bot 1 và bot 3

Bản phân tích trước khi dựng nguồn. Chỉ đọc tĩnh bằng chứng đã lưu;
**chưa chạy, chưa biên dịch, chưa so với EX5**. `runtime_verified=false`.
Chi tiết máy đọc được: [semantics.json](semantics.json).

## 1. Đầu vào đã đối chiếu

| Mục | Bot 1 | Bot 3 |
|---|---|---|
| EX5 gốc (SHA-256 ghi trong `analysis.json`) | `a3b0de42…e922` | `ee063d3d…eb83` |
| Hàm | RVA `0x26d20`..`0x271e7` (1.223 byte) | RVA `0x32a90`..`0x32f57` |
| Mã máy | 196 lệnh, `native_bytes_sha256` `2e80dc3d…d48c` | 196 lệnh, `739d61a8…0250` |
| Mã C | `ma-trung-gian.c` dòng 16977–17100 | `ma-trung-gian-day-du.c` dòng 22819–22942 |
| Gốc mã | `0x23e5aa10000` | `0x17156250000` |
| Biên nhận lượt phân tích | `receipt.json`: analysis `82312a2b…`, functions.c `ec20c3b3…`, native-guards `57247e28…` | `8a468637…`, `058d60fb…`, `6f780d66…` |

Nguồn: `bot-cua-toi-N/phan-tich/dong-vi-the/modify-20261025-r1/`.
RVA = địa chỉ tuyệt đối − gốc mã, ví dụ `0x23e5aa7a414 − 0x23e5aa10000 = 0x6a414`.
Hai bot có cùng dãy lệnh, cùng độ dài từng lệnh; mọi RVA bot 3 bằng
RVA bot 1 cộng `0xbd70`. Chỉ khác địa chỉ tuyệt đối của biến/chuỗi.
Hàm này tách biệt với đóng vị thế `0x22c40`/`0x2e370`.

Dòng C bot 1 = dòng `functions.c` + 16975; bot 3 = dòng `functions.c` + 22817.

## 2. Chữ ký — chứng minh từ lệnh máy của chính hàm

| Phần | Bằng chứng lệnh máy (RVA bot 1; bot 3 = +0xbd70) | Kết luận |
|---|---|---|
| Đối số 1 | `mov rbx, rcx` 0x26dd1; `mov rdx, rbx` 0x26dee trước lời gọi chọn vé; `mov qword ptr [rbp], rbx` 0x27129 vào `request.position` | Số nguyên 64 bit, dùng nguyên, không mở rộng/cắt |
| Đối số 2 | `movaps xmm7, xmm1` 0x26de8; `movsd [request+56], xmm7` 0x271a3 | `double`, chép nguyên 8 byte vào `request.sl` |
| Đối số 3 | `movaps xmm6, xmm2` 0x26deb; `movsd [request+64], xmm6` 0x271aa | `double`, chép nguyên 8 byte vào `request.tp` |
| Không phải đối số | RDX, R8, R9 bị ghi trước khi dùng; XMM0, XMM3 không được đọc; không đọc vùng đối số trên ngăn xếp của bên gọi | Đúng 3 đối số |
| Trả về | `movzx esi, al` 0x271b2 sau hàm gửi; `xor esi, esi` 0x26dc4 và 0x271b7; `mov eax, esi` 0x271d1 | 1 byte: kết quả gửi hoặc 0 |
| Thanh ghi phải giữ | lưu/khôi phục RBX, RBP, RDI, RSI, R12–R15, XMM6–XMM8 | Đúng quy ước Win64 |

Mã C ghi `param_2`, `param_3` là `undefined8` (số nguyên). Đó là sai
kiểu của trình dịch ngược; lệnh máy dùng XMM1/XMM2. Không lấy mã C làm
bằng chứng kiểu.

Trạng thái gửi (yêu cầu/kết quả/kết quả kiểm, mã nhận diện, đối tượng
gửi) là biến toàn cục cố định, không phải đối số. Bản dựng giữ cách đã
dùng ở các phần trước: truyền `BotNPendingRequestState&` và
`BotNTradeSendOptions&`, rồi `ticket`, `sl`, `tp` đúng thứ tự gốc.

## 3. Thứ tự xử lý gốc

| Bước | RVA bot 1 | RVA bot 3 | C bot 1 / bot 3 | Hành vi |
|---|---|---|---|---|
| 0 | 0x26d20–0x26d3e | 0x32a90–0x32aae | — | Lưu 8 thanh ghi, trừ 0x88 ngăn xếp, lưu XMM6–8 |
| 1 | 0x26d43–0x26d4b | 0x32ab3–0x32abb | 16990–91 / 22832–33 | Chuỗi cục bộ 12 byte tại `[rsp+0x40]` = rỗng (dword 0, qword 0) |
| 2 | 0x26d54–0x26d6b | 0x32ac4–0x32adb | 16992 / 22834 | So **dword** cờ dừng với 0. Khác 0 (kể cả âm) → nhánh dừng |
| D1 | 0x26d6d–0x26db8 | 0x32add–0x32b28 | 17091 / 22933 | Gọi điều phối MT5 mã 13, 2 đối số chuỗi: mẫu `%s: MQL5 program is stopped. Trading is disabled`, tên `CTrade::PositionModify` |
| D2 | 0x26dba–0x26dcc | 0x32b2a–0x32b3c | 17093 / 22935 | **Sau** khi in: ghi dword `result.retcode = 10027`; trả 0 |
| 3 | 0x26dd1–0x26df5 | 0x32b41–0x32b65 | 16993–94 / 22835–36 | Giữ vé/sl/tp; gọi chọn vị thế theo vé; `test al, al`; sai → trả 0, không đổi gì |
| 4 | 0x26dfb–0x27112 | 0x32b6b–0x32e82 | 16995–17074 / 22837–22916 | Xóa toàn bộ 628 byte yêu cầu/kết quả/kiểm, gồm vùng đệm riêng; giải phóng 4 chuỗi (mục 5) |
| 5 | 0x27119–0x27129 | 0x32e89–0x32e99 | 17075–76 / 22917–18 | Ghi dword `request.action = 6`, qword `request.position = vé` — **trước** lời đọc mã giá |
| 6 | 0x2712d | 0x32e9d | 17077 / 22919 | Gọi đọc chuỗi vị thế, thuộc tính 0 (EDX=0) |
| 7 | 0x2712f–0x2716d | 0x32e9f–0x32edd | 17078–79 / 22920–21 | Hàm chuỗi `0x5c0`: chuỗi trả tạm → chuỗi cục bộ (cờ 1); chuỗi cục bộ → `request.symbol` (cờ 0) |
| 8 | 0x2716f–0x2718c | 0x32edf–0x32efc | 17080–81 / 22922–23 | Đọc qword mã nhận diện đã lưu, ghi `request.magic` — **sau** lời đọc mã giá |
| 9 | 0x2718f–0x271aa | 0x32eff–0x32f1a | 17082–83 / 22924–25 | Ghi `request.sl`, `request.tp` từ giá trị lúc vào hàm |
| 10 | 0x271b0–0x271b5 | 0x32f20–0x32f25 | 17084 / 22926 | Gọi hàm gửi đầy đủ `0x950(ngữ cảnh, yêu cầu, kết quả)`; trả byte thấp |
| 11 | 0x271b9–0x271e6 | 0x32f29–0x32f56 | 17095–96 / 22937–38 | Mọi nhánh: giải phóng chuỗi cục bộ, khôi phục thanh ghi, trả EAX |

Thứ tự ghi số 0 trong mã C khác lệnh máy (trình dịch ngược sắp lại).
Theo lệnh máy, phần xóa gồm: yêu cầu 0..127 và đệm 128..239; kết quả
240..311 và đệm 312..435; kiểm 436..499 và đệm 500..627. Byte 628
(chế độ gửi), mã nhận diện, độ lệch giá, ưu tiên cách khớp không bị ghi.

Không có kiểm cách khớp `0x231c0`/`0x2e8f0`, không đặt `type`, `volume`,
`price`, `deviation`, `type_filling`, `comment`; các trường này giữ 0
hoặc rỗng sau khi xóa. Không kiểm mã giá đọc được là rỗng hay lỗi.
Không thử lại, không kiểm mã kết quả trước khi trả.

## 4. Lời gọi theo đúng thứ tự

| # | RVA bot 1 / bot 3 | Đích | Đối số | Dùng kết quả |
|---|---|---|---|---|
| A | 0x26db8 / 0x32b28 | MT5 `+0x7b49f0` (điều phối) | RCX ngữ cảnh MT5; EDX 13; R8D 2; R9D `0x590008`; `[rsp+0x20]` mô tả mẫu; `[rsp+0x28]` `0x590008`; `[rsp+0x30]` mô tả tên | Không |
| B | 0x26df1 / 0x32b61 | MT5 `+0x7d7ee0` (chọn vị thế theo vé) | RCX ngữ cảnh; RDX vé 64 bit | `test al, al` |
| C1–C4 | 0x26e34, 0x26e8a, 0x26f42, 0x26ffa / +0xbd70 | `0x0` (giải phóng chuỗi) | `request.symbol` (+20), `request.comment` (+100), `result.comment` (+292), `check.comment` (+488) | Không |
| D | 0x2712d / 0x32e9d | MT5 `+0x7d8010` (đọc chuỗi vị thế) | RCX ngữ cảnh; EDX 0 | Kết quả ở ô chuỗi tạm |
| E1 | 0x27158 / 0x32ec8 | `0x5c0` | cục bộ, ô tạm, R8B=1, R9 mô tả `0x5d958` (bot 3 `0x67cb8`) | Không |
| E2 | 0x2716d / 0x32edd | `0x5c0` | `request.symbol`, cục bộ, R8D=0, R9 `0x5d968` (bot 3 `0x67cc8`) | Không |
| F | 0x271b0 / 0x32f20 | `0x950` (gửi + thông báo) | RCX `0x67490`/`0x744d0`, RDX yêu cầu, R8 kết quả | AL là kết quả trả |
| G | 0x271be / 0x32f2e | `0x0` | chuỗi cục bộ | Không |

Ánh xạ đích MT5 dựa trên đối chứng có nguồn
`doi-chung-mt5/dong-vi-the-20261024/close-api-r1/api-contract.json`:
`CloseSelect`→`0x7d7ee0`, `CloseSymbol`→`0x7d8010` có `xor edx, edx`,
hằng `POSITION_SYMBOL=0`. Mã 13 của `0x7b49f0` là `PrintFormat` hai
chuỗi như ở phần chuẩn bị/hủy/đóng đã so; bản đồ
`ban-do-bot-1-3/luot-20261025-r1` cũng ghi dòng 17091 (bot 1) và 22933
(bot 3) là `opcode 13, argc 2, known_source_api PrintFormat`. `0x950` và hàm thông báo đã
dựng ở `BotNTradeSend.mqh`/`BotNTradeMessages.mqh`.

## 5. Trạng thái đọc/ghi

| Địa chỉ RVA bot 1 / bot 3 | Ý nghĩa đã đo | Hàm này |
|---|---|---|
| `0x6a414` / `0x1d6e14` | cờ dừng chương trình (`IsStopped`) | Đọc dword một lần ở bước 2 |
| `0x67490` / `0x744d0` | đối tượng gửi; +660 chế độ gửi, +681 chế độ ký quỹ, +685 mức ghi | Chỉ chuyển địa chỉ cho `0x950` |
| `0x674b0` / `0x744f0` | yêu cầu (17 trường, 0..127) + đệm tới 239 | Xóa rồi ghi action, position, symbol, magic, sl, tp |
| `0x675a0` / `0x745e0` | kết quả (10 trường) + đệm | Nhánh dừng: chỉ dword retcode; nhánh chọn được: xóa, `0x950` ghi |
| `0x67664` / `0x746a4` | kết quả kiểm (8 trường) + đệm tới 627 | Xóa (nhánh chọn được) |
| `0x67725` / `0x74765` | mã nhận diện đã lưu (qword) | Đọc một lần ở bước 8 |
| `0x6772d` / `0x7476d` | độ lệch giá (dùng khi đóng) | Không đọc, không ghi |
| `0x67735` / `0x74775` | ưu tiên cách khớp | Không đọc, không ghi |
| `0x6a43c` / `0x1d6e3c` | ô chuỗi trả tạm của MT5 | Đọc qua `0x5c0` |

Bố cục 35 trường và khoảng 240/196 byte theo
`doi-chung-mt5/thu-tu-truong-lenh-class-20261024/layout-class-r1/trade-layout.json`.

## 6. Yêu cầu tại lúc gửi (nhánh chọn được vé)

`action=6`, `position=vé`, `symbol=` chuỗi đọc được (có thể NULL/rỗng),
`magic=` mã đã lưu lúc đọc ở bước 8, `sl/tp=` đối số; mọi trường khác
0/NULL. Kết quả và kết quả kiểm đều 0/NULL trước khi gửi. Hằng
`TRADE_ACTION_SLTP=6`: mã máy ghi số 6; phần thông báo đã so dùng nhánh
6 cho chữ `modify position`; giá trị hằng MQL5 sẽ được chương trình kiểm
ghi ra và đối chiếu ở lượt chạy (U3, mục 10).

## 7. Số thực, NaN, độ rộng

- Không có phép so hay tính số thực trong hàm. `sl/tp` chỉ được chép bit
  (`movaps`, `movsd`); `-0.0`, vô hạn, NaN và NaN báo hiệu giữ nguyên bit.
- Cờ dừng so 32 bit; vé và mã nhận diện 64 bit; `action`, `retcode` ghi 32 bit.
- Định dạng số thực khi in thông báo nằm trong `0x950`, đã có bộ kiểm riêng.

## 8. Chuỗi gốc

`strings.tsv` của từng bot: `CTrade::PositionModify` (22 ký tự) tại
`0x52e7c` / `0x5b62c`; mẫu `%s: MQL5 program is stopped. Trading is
disabled` (48 ký tự) tại `0x5415c` / `0x5c90c`. Mô tả chuỗi mà lệnh máy
truyền (`0x52eb0`, `0x541c0` / `0x5b660`, `0x5c970`) nằm ngay sau phần
chữ + ký tự kết thúc, làm tròn 8 byte; quy luật này cũng đúng với
`CTrade::PositionClose` của hàm đóng. Bộ chạy mã gốc đọc chuỗi thật qua
mô tả lúc chạy; chưa đọc trực tiếp byte mô tả trong lượt phân tích này.

## 9. Nơi gọi (mới thấy trong mã C)

| Bot | Hàm gọi (RVA) | Số chỗ gọi | Dòng C |
|---|---|---|---|
| 1 | 0x18aa0 | 1 | 11995 |
| 1 | 0x271f0 | 9 | 17278, 17294, 17459, 17720, 17801, 17894, 17969, 18047, 18102 |
| 1 | 0x2abc0 | 9 | 18387, 18403, 18558, 18914, 18979, 19048, 19111, 19165, 19218 |
| 3 | 0x20ef0 | 1 | 16242 |
| 3 | 0x32f60 | 10 | 23121, 23137, 23346, 23732, 23818, 23899, 23992, 24067, 24145, 24200 |
| 3 | 0x37590 | 10 | 24483, 24499, 24695, 25159, 25220, 25299, 25374, 25434, 25496, 25532 |

Bản đồ `ban-do-bot-1-3/luot-20261025-r1` và `r2` cũng ghi đúng ba hàm
gọi này cho mỗi bot (bot 1 `0x18aa0` ở C 11210–13824). RVA hàm gọi tính
bằng địa chỉ trong mã C trừ gốc mã, ví dụ `0x23e5aa28aa0 − 0x23e5aa10000 = 0x18aa0`. Mã C chỉ hiện hai đối số ở 9 chỗ (bot 1) và 10 chỗ (bot 3); các chỗ
còn lại hiện ba đối số. Một số chỗ
truyền vé dạng `(longlong)dVar6`, với `dVar6=(double)(longlong)vé`
(dòng 17203 bot 1). Bot 1 dùng kết quả ở 10 chỗ, bot 3 ở 12 chỗ. Đây
là quan sát C, chưa kiểm lệnh máy phía gọi. Đã viết công cụ phân tích
`phan-tich-goi-sua-vi-the-bot-1-3.py` để Codex chạy. Phần này thuộc hàm
gọi, không đổi chữ ký đã chứng minh ở mục 2.

## 10. Chưa rõ / giới hạn

| Mục | Tình trạng |
|---|---|
| U1 | Nghĩa cờ R8B=1/0 và mô tả R9 của `0x5c0` chưa đặt tên; bộ kiểm chạy nguyên mã gốc |
| U2 | Hàm `0x0` với chuỗi cục bộ rỗng ở nhánh dừng/chọn lỗi: chỉ kiểm qua cân bằng cấp/giải phóng |
| U3 | Hằng `TRADE_ACTION_SLTP` mới có số 6 ở mã máy; giá trị MQL5 chờ bản ghi chạy thật |
| U4 | Lệnh máy phía gọi: nguồn XMM2 ở chỗ C hiện hai đối số, cách dùng AL/EAX, cách đổi vé `double→số nguyên` |
| U5 | Hành vi MT5 thật: chọn vị thế đổi vị thế đang chọn, lỗi đọc chuỗi, `_LastError`, phản hồi nơi giao dịch — bộ kiểm chỉ cấp dữ liệu |
| U6 | Lỗi cấp bộ nhớ trong `0x5c0`/`0x950` chưa kiểm |
| U7 | Thứ tự từng lệnh ghi 0 xen giữa 4 lần giải phóng chuỗi không quan sát được từ MQL5; chỉ so trạng thái tại ranh giới dịch vụ và cuối hàm |
| U8 | Tên `BotNModifyPosition` là tên dựng lại; tên gốc chỉ biết qua chuỗi `CTrade::PositionModify` |
| U9 | Chưa ghép nơi gọi, toàn EA, cài đặt, giao diện, khởi động lại, tài khoản thật |

## 11. Quyết định dựng

Đối số, kiểu, nhánh, thứ tự gọi/đọc/ghi và giá trị trả đã đủ bằng
chứng ở lệnh máy của hàm. Có thể viết nguồn đề xuất:

```text
if dừng: PrintFormat(mẫu, "CTrade::PositionModify"); result.retcode=10027; return false
if !PositionSelectByTicket(vé): return false
ZeroMemory(request/result/check)
action=TRADE_ACTION_SLTP; position=vé
symbol=PositionGetString(POSITION_SYMBOL)
magic=state.magic; sl=sl; tp=tp
return BotNSendTrade(options, request, result)
```

Bộ kiểm phải so: giá trị trả, 35 trường, 4 chuỗi đầy đủ và cờ NULL, mã
nhận diện/ưu tiên/độ lệch/tùy chọn gửi, trạng thái trước mỗi lời gọi
dịch vụ và sau gửi, thứ tự/đối số có kiểu, nội dung thông báo; nhánh
thoát sớm giữ nguyên vùng lưu (chỉ đổi retcode khi dừng); nhánh chọn
được xóa đủ vùng đệm riêng; mọi lệnh trong hàm đều được chạy ít nhất một lần.
