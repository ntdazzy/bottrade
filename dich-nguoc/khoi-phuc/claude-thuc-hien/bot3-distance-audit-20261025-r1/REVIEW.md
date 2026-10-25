# Rà độc lập `Bot3AdvanceDistanceVirtualStop` — bot3-distance-audit-20261025-r1

**Kết luận:** so với contract và lệnh máy gốc, tôi không thấy lỗi nào có căn cứ
trong hàm này. Vì vậy không có header sửa. Đây là rà tĩnh cộng đọc lại bằng
chứng chạy đã lưu. Tôi không biên dịch, không chạy MT5 hay bộ giả lập, và không
tự tính lại SHA-256 (không dùng shell).

Bối cảnh: chủ dự án khôi phục nguồn The Gold Reaper MT5 (bot 3) từ EX5 của mình,
SHA-256 gốc `ee063d3d87490afe24e2f4ce85f6b05659320e297b102efd70207f71ca2feb83`.
Chỉ xét đoạn mua `0x35fd3..0x36189` trong 0x32f60 và đoạn bán `0x3a2f7..0x3a4af`
trong 0x37590. Đây không phải cả hàm quản lý hay EA. Không xét phần dời chốt lời
ảo, và không viết bộ kiểm.

## Nguồn đã đọc

- Mã: `bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/Bot3ManagementVirtual.mqh:28-66`.
  Phụ thuộc: `Bot3PriceLevels.mqh:7-16` (`Bot3RoundPrice`),
  `Bot3PositionClose.mqh:31-59` (`Bot3TryClosePosition`),
  `Bot3ManagementPrelude.mqh:10-22`.
- Contract: `phan-tich/dong-vi-the/management-virtual-20261025-r1/contract.md:10-22, 48-86`.
- Lệnh máy: `phan-tich/dong-vi-the/management-20261025-r1/native-guards.txt`:
  dòng 2356-2435 (mua), 3249-3257 (đóng, mua), 5562-5642 (bán), 6652-6660
  (đóng, bán), 1-45 và 3355-3391 (khởi tạo thanh ghi).
- Hằng số và close guard: `management-20261025-r1/initial-findings.json:1812-1832`,
  `management-prelude-20261025-r2/native-boundaries.json:6282-6298`,
  `close-20261024-r1/semantics.json:31-52`.
- Bằng chứng chạy: `bang-chung/kiem-quan-ly-vi-the/virtual-20261025-r1/`
  (comparison, original-run, baseline, mql5-run, tested-sources),
  `cpu-nan-20261025-r1/probe.json`, `prelude-cpu-20261025-r1/comparison.json`,
  `bang-chung/bien-dich/b3-management-virtual-01/bien-nhan.json`.

Tôi đọc so từng dòng: `tested-sources/Bot3ManagementVirtual.mqh` giống hệt bản
nguồn hiện hành. `final-verification.json` ghi cả hai cùng SHA
`e74e2780…6db21d`; số này tôi không tự tính lại.

## Đối chiếu từng bước

Ký hiệu: B = tick.bid `0x74798`, A = tick.ask `0x747a0`, P = current_level
`0x6d670`, U = unit `0x73dd8`, H = anchor (stack mua +0x78 / bán +0x88),
O = xmm6 (giá mở), V = xmm13 (khối lượng vị thế).

| Bước | Gốc, mua | Gốc, bán | Mã | Khớp |
|---|---|---|---|---|
| `0.0<trail_distance`; sai thì ra, chưa gọi API | 0x35fdd-0x35fe7 | 0x3a301-0x3a30b | :38 | ✓ |
| Chụp level=P và quote=B/A **trước** POINT | 0x3600d, 0x36012 → gọi 0x36021 | 0x3a331, 0x3a336 → 0x3a345 | :39-41 | ✓ |
| Sau POINT: đọc lại trail, U đọc một lần, `offset=(step+trail)*U` | 0x36037, 0x36046, 0x3604a-0x3604e | 0x3a35b, 0x3a369, 0x3a36d-0x3a371 | :42-44 | ✓ |
| Điều kiện 1 | `offset+(level+point)<quote` 0x3603c, 0x36052-0x3605c | `quote<((level-point)-offset)` 0x3a360, 0x3a375-0x3a37f | :47 / :54 | ✓ |
| Điều kiện 2 | `trail_start*U+H<B`, B đọc lại 0x3606c | `A<(H-trail_start*U)`, A đọc lại 0x3a398 | :48 / :55 | ✓ |
| Điều kiện 3 | `P<trail_limit*U+O`, P đọc lại 0x360b3 | `(O-trail_limit*U)<P`, P đọc lại 0x3a3cf | :49 / :56 | ✓ |
| Gán P | `B-trail*U` 0x360bd-0x360cf | `trail*U+A` 0x3a3e5-0x3a401 | :50 / :57 | ✓ |
| volume | `volumes[0x73ac0][uint32 0x74934]*xmm11`, làm tròn 0x360d3-0x3614b | 0x3a405-0x3a47d | :59 | ✓ |
| changed=true, cả khi bỏ làm tròn | 0x36150 (đích `je` 0x360fc) | 0x3a482 (đích 0x3a42e) | :60 | ✓ |
| `volume<V` | 0x36153-0x36158 | 0x3a485-0x3a48a | :61 | ✓ |
| Chỉ khi đạt mới gọi VOLUME_MIN (r8d=0x22) | 0x3615a-0x36170 | 0x3a48c-0x3a4a2 | :62 | ✓ |
| `minimum<=volume` | 0x36172 `jb` ra | 0x3a4a4 `jae` tới đóng | :63 | ✓ |
| Gọi 0x47d20 (rcx = vé stack +0x40 / +0x48), hàm ngoài trả 1 | 0x3617a → 0x372ef-0x3731e (`mov bl,1`) | 0x3b853-0x3b87f | :64-65 | ✓ |
| Đường không đạt về đoạn kế | 0x36189 (0x3617f chỉ đặt lại r14) | 0x3a4af | `return false` | ✓ |

Thứ tự toán hạng của mọi phép cộng/trừ/nhân trong mã giống hệt lệnh gốc. Đây
không chỉ là cùng giá trị nhờ tính giao hoán.

## Các điểm được yêu cầu

1. **Nhóm công thức:** ngoặc và thứ tự đúng như bảng trên. Ưu tiên toán tử MQL5
   cho `a*b+c<d` thành `((a*b)+c)<d`, đúng như gốc.
2. **Chụp trước POINT:** gốc chỉ chụp level và quote (xmm14, xmm8, hai thanh ghi
   không bị lời gọi xoá theo quy ước Win64). Mã cũng chỉ chụp hai giá trị này và
   chỉ dùng chúng ở điều kiện 1.
3. **Đọc mới sau POINT:** trail_distance, trail_step, unit, trail_start,
   trail_limit, B/A, P đều được đọc sau API. `point` lấy từ ô trả về của runtime
   ngay sau lời gọi: [r13] ở mua (r13 = 0x17156426e48, lệnh 0x3307c), [r14] ở bán
   (lệnh 0x376a6). Lời gọi chỉ có rcx = ngữ cảnh, rdx = chuỗi symbol `0x74958`,
   r8d = mã thuộc tính, không có con trỏ ra. Vậy nó khớp với dạng hàm trả double.
   H là ô stack của hàm gọi, còn O và V là thanh ghi có từ trước đoạn. API không
   ghi vào chúng, nên truyền theo giá trị hay const& đều cho cùng kết quả.
4. **Nhân khối lượng với 0:** xmm11 = +0.0 (`xorpd` ở 0x33086 mua, 0x376b0 bán).
   Ngoài ra chỉ có lần khôi phục ở cuối hàm (0x3736a, 0x3b8cb). Mã `*0.0` cũng là
   +0.0.
   - Kết quả nhân chỉ có thể là ±0 (đầu vào hữu hạn) hoặc NaN (đầu vào ±Inf/NaN).
   - `Bot3RoundPrice` biến ±0 thành +0.0. Với NaN, `(long)` cho LONG_MIN nên hàm
     trả nguyên NaN, giống `cmp rax,0x8000000000000000; je`.
   - Bảng nửa ±0.5000001 ở 0x58468 và 0x58490 đã có byte đọc trực tiếp, giống mã.
   - Hệ số nhân ở 0x58480/0x584a8: tôi chưa thấy giá trị trong bằng chứng đã đọc.
     Với đầu vào ±0/NaN, kết quả như nhau với mọi hệ số khác 0 và không phải NaN.
     Ca chạy có table_volume hữu hạn đã khớp, nên hệ số không thể là 0/NaN.
   - Hành vi lạ của gốc được giữ: helper chỉ được gọi khi V>0 và VOLUME_MIN ≤ 0
     (kể cả -0).
5. **NaN/Inf/±0:** mọi phép so gốc là `ucomisd` rồi `jbe`/`jb`/`jae`, nghĩa là
   chỉ đi tiếp khi so có thứ tự đúng. Mã viết `!(a<b)`, `!(a<=b)`, nên NaN làm
   điều kiện hỏng y như gốc.
   - Khi tới phép gán P: B/A đã qua phép so có thứ tự nên không phải NaN.
     `trail*U` chỉ có thể là NaN mặc định (0×Inf, khi trail bị đổi trong lúc gọi
     API). Vậy không bao giờ có hai toán hạng NaN, và kết quả không phụ thuộc thứ
     tự toán hạng. Sai khác của Unicorn khi cả hai toán hạng đều NaN
     (`cpu-nan` probe) không chạm tới đoạn này.
   - ±0: phép gán dùng cùng phép trừ/cộng như gốc. volume luôn là +0.0 hoặc NaN.
     `-0<=+0` là đúng, giống `ucomisd` báo bằng.
6. **changed:** cờ được đặt sau khi tính volume và trước phép so `volume<V`, kể cả
   khi volume là NaN. Không đường nào xoá cờ. Thoát sớm thì cờ và P giữ nguyên.
   Khớp.
7. **Đối số close guard:** gốc chỉ truyền vé (rcx = [rsp+0x40] / [rsp+0x48]).
   0x47d20 tự đọc tham chiếu a = 0x74798, b = 0x747a0, ngưỡng a = 0x73ab0,
   b = 0x744a8 (semantics.json:43-50). Mã gọi
   `Bot3TryClosePosition(state,options,deviation,tick.bid,tick.ask,threshold_a,threshold_b,ticket)`.
   Helper nhận `const double &`, nên khi helper đọc lại thì thấy giá trị mới như
   gốc. Mã không gọi `Bot3ClosePosition` (0x2e370). Khớp.

Lệnh gốc cũng trả lời bốn câu hỏi còn mở trong SUMMARY của đề xuất cũ:
- POINT là dạng hàm trả double.
- Khi một điều kiện hỏng thì thoát ngay, không tính volume và không đặt cờ (các
  `jbe` nhảy qua khối volume).
- anchor là H.
- Vé lấy ở stack +0x40 (mua) / +0x48 (bán).

## Bằng chứng chạy có sẵn (lượt trước chạy, tôi chỉ đọc)

- `virtual-20261025-r1/comparison.json`: nhóm 2 (đoạn này) khớp 220/220, tổng
  560/560. SHA kết quả gốc và MQL5 trùng nhau: `9436e215…c5cf49a`.
- `original-run.json` đã chạy qua các lệnh then chốt: 0x360fe, 0x36150, 0x36172,
  0x3617a, 0x372ef, 0x3a430, 0x3a482, 0x3a4a4, 0x3b853.
- Biên dịch `b3-management-virtual-01`: 0 lỗi, 0 cảnh báo.
- Các ca đã chạy:
  - Mỗi biến trail, trail_step, trail_start, trail_limit, anchor, volume,
    table_volume, minimum, point, unit, level lần lượt nhận -Inf, -1, -0, 0,
    .01, 1, 100, Inf, NaN.
  - minimum -0.01/0/0.01 kết hợp với index 0/1/7.
  - Kịch bản 5: đổi P, B, A trong lúc gọi API.

## Giới hạn: phần chỉ có căn cứ tĩnh

- Mọi ca nhóm 2 đều có bid = ask = 100, và kịch bản 5 cộng cùng 1.25 cho cả hai.
  Vì vậy lượt chạy không phân biệt được việc chọn bid hay ask (ở quote, điều
  kiện 2, phép gán), cũng như thứ tự `tick.bid, tick.ask` khi gọi helper.
- Kịch bản 5 dời level và quote cùng một mức. Khoảng cách tới ngưỡng ở điều
  kiện 1 trong ca gốc là 4.68 > 1.25, và điều kiện 3 cũng còn khoảng cách. Vậy
  lượt chạy chưa phân biệt "chụp trước POINT" với "đọc mới" ở điều kiện 1 và 3.
  Không ca nào đổi trail_distance hoặc unit trong lúc gọi API. Phép gán P thì
  có phân biệt (99.7 so với 100.95).
- Các ca tới được helper đều là kịch bản 0, nên "giá mới khi gọi helper" chưa
  được chạy phân biệt. Ở nhóm 2, vé luôn là 7 và changed lúc vào luôn là 0.
- Chưa xét chỉ số mảng ngoài phạm vi. Gốc không kiểm biên ở 0x360df/0x3a411,
  còn MQL5 sẽ báo lỗi mảng. Theo contract, không thêm luật chặn.
- Khớp từng bit còn phụ thuộc cách MQL5 sinh mã (ví dụ không gộp nhân-cộng
  thành một lệnh). Điều này mới được xác nhận cho các giá trị đã chạy.
- Chưa chứng minh cả hàm quản lý, vòng lặp ngoài, helper 0x47d20 khi chạy thật,
  giao dịch thật hay EA. Một bộ ca kiểm đạt không phải bằng chứng cho cả bot.

## Cấu hình phiên

Thông tin hệ thống ghi model `claude-opus-5-5`. Tôi không tự kiểm được mức
`max` và Ultracode từ trong phiên. Theo yêu cầu, tôi không dùng tác tử phụ,
skill, Bash, PowerShell hay MT5. Tôi chỉ đọc bằng Read/Grep/Glob và chỉ ghi
tệp này.
