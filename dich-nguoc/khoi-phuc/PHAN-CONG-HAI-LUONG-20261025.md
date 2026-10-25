# Hai luồng khôi phục bot 1 và bot 3

Người dùng yêu cầu ngày 25/10/2026: làm hai bot cùng lúc, tách hai chat.
Mỗi chat có Codex phân tích và kiểm chứng, phối hợp Claude Opus 5.5 mức
max để viết từng chức năng theo mô tả đã chốt. Đây là phân chia công
việc được người dùng yêu cầu. Không có phần trăm toàn bot đáng tin cậy;
hiện 0/2 EA hoàn chỉnh. Không đổi mục tiêu thành bot gần giống.

## Cách giao mã cho Claude

Codex đọc quy tắc và bằng chứng gốc, chốt công thức, điều kiện, kiểu
số, thứ tự và tác dụng phụ trước. Claude nhận ngữ cảnh/mục tiêu chính
xác cùng mô tả từng chức năng để viết MQL5 và bộ kiểm, không bị giao
lại việc tự phân tích EX5. Không bịa ngữ cảnh hoặc yêu cầu vượt chặn.
Phần đã bị Claude từ chối thì Codex làm theo ngoại lệ người dùng đã
duyệt; không hỏi lại người dùng về phân công này.

Dùng `cong-cu/giao-claude-phan-viec.ps1`; đặt đề xuất riêng dưới
`claude-thuc-hien/` với tên có bot và lượt. Từng chat dùng phiên Claude
riêng, không dùng phiên `06889925-53b9-46d0-abd8-2e1f08e68869` vì chat
điều phối đang dùng để làm bộ kiểm bảng dừng ảo. Kiểm thực tế
api-request trong nhật ký Claude trước khi nói đã dùng Opus 5.5/max.
Ultracode đã được yêu cầu trong cấu hình; nếu chưa có bằng chứng chạy
thì ghi chưa xác nhận, không suy ra từ cờ yêu cầu.

## Phân chia tệp và máy thử

| Luồng | Phạm vi ghi riêng | Việc trước mắt |
|---|---|---|
| Bot 1 | `bot-cua-toi-1/`, công cụ mới tên riêng cho quản lý bot 1, đề xuất Claude bot 1 | Chốt và dựng hai hàm quản lý vị thế `0x271f0`, `0x2abc0`, sau đó luồng chiến lược/điều phối; ghép các hàm nền đã kiểm |
| Bot 3 | `bot-cua-toi-3/`, công cụ mới tên riêng cho bot 3, đề xuất Claude bot 3 | Phân tích đủ năm hàm bảng dừng/chốt ảo rồi giao Claude viết theo mô tả; tiếp tục hai hàm quản lý `0x32f60`, `0x37590` và điều phối |
| Điều phối | Tài liệu/bảng chung, quy tắc, bộ kiểm chung, Git | Chốt bằng chứng bảng dừng ảo bot 1 r4, rà sản phẩm hai luồng và ghép tài liệu/commit |

Không sửa công cụ chung, catalog, bản đồ, tài liệu chung hoặc tệp của
bot kia đồng thời. Cần sửa thì viết đề xuất có tên riêng vào thư mục
của bot và nêu trong tiến độ. Không tự commit/push từ hai luồng; chat
điều phối sẽ kiểm đúng tập tệp và commit/push. Mỗi luồng cập nhật
`bot-cua-toi-N/TIEN-DO-LUONG-20261025.md` với việc đã viết, bằng chứng,
việc đang làm, phần thiếu. Không gửi tin sang chat khác tự động; chat
điều phối đọc trạng thái và tệp này.

Mỗi luồng dùng MT5 riêng bên trong `.local/mt5-botN-thread-20261025`,
sao chép từ máy thử sẵn có nếu cần. Không dùng chung máy thử đang ở
`.local/claude-recovery-20261023/mt5`, không sửa MT5 chính, bản EX5
gốc, khóa hay giới hạn. `cong-cu/bien-dich.ps1` đã nhận `-Terminal`;
dùng lại, không cần viết lại trình biên dịch. Công cụ chạy kiểm mới
phải nhận/chỉ đúng máy riêng của luồng, không âm thầm chạy máy chung.
Không gửi lệnh lên tài khoản thật. Giữ cấu hình đăng nhập riêng ở
`.local`; không đưa tài khoản/mật khẩu hoặc tệp chạy nhị phân vào Git.

Khi có EA đầy đủ: bản gốc và bản mới chạy song song trong hai môi
trường MT5 thử riêng với cùng dữ liệu/cài đặt, so toàn bộ giao dịch,
trạng thái, lỗi và giao diện. Kiểm từng hàm trước đó không thay phép
kiểm cặp cả bot. Không dùng tổng lợi nhuận làm điều kiện đạt duy nhất.

## Bằng chứng để tiếp tục

Gốc Git đã đẩy: `d894e487c23a16259804f08e148f6b8b70abb61e`.
396 tệp bị xóa ngoài phạm vi và `README.md` gốc thay đổi đã có từ
trước; không khôi phục/xóa/stage chúng. Hàng nghìn tệp chưa theo dõi
không đều do lượt này tạo. Xem `GIT-SCOPE.md` ở gốc dự án.

Đọc `README.md` của từng bot, `BAN-DO-TOAN-BO-BOT-1-3.md`,
`ban-do-bot-1-3/luot-20261025-r4/`, `PHAN-TICH-SUA-VI-THE-BOT-1-3.md`,
`PHAN-TICH-BANG-DUNG-AO-BOT-1-3.md` và đúng bản C/bản chụp đã chốt.
Bản đồ có 84/82 hàm trong bản chụp, không chứng minh đã có toàn EX5.

Bot 1 SHA-256 gốc:
`a3b0de423a06e10ebedc279307b93d7cb9188ba2bb5de77131a913c865b0e922`.
Địa chỉ đầu mã chụp `0x23e5aa10000`. Phải trừ địa chỉ đầu, không lấy
đuôi tên hàm làm vị trí. C hiện hành
`bot-cua-toi-1/phan-tich/luot-20261023-data-v2/ma-trung-gian.c`.
Quản lý đầy đủ đã xuất ở
`bot-cua-toi-1/phan-tich/dong-vi-the/management-20261025-r1/`
(5.621 lệnh, 2 hàm); chưa có nguồn MQL5 cho hai hàm này.

Bot 3 SHA-256 gốc:
`ee063d3d87490afe24e2f4ce85f6b05659320e297b102efd70207f71ca2feb83`.
Địa chỉ đầu `0x17156250000`. C hiện hành
`bot-cua-toi-3/phan-tich/luot-20261023-data/ma-trung-gian-day-du.c`.
Năm hàm vừa xuất và xác nhận tám lời gọi API tại
`bot-cua-toi-3/phan-tich/dong-vi-the/virtual-stops-20261025-r1/`
(530 lệnh). Mới có phân tích thô, chưa có nguồn hoặc phép so chạy.
Không chép logic bot 1 sang bot 3: bot 3 có thêm bảng chốt ảo 500×2
và hàm `0x482b0`; phải đọc lại nhánh NaN theo lệnh máy.

Bot 1 có bốn hàm bảng dừng ảo nguồn hiện hành và bản biên dịch sạch
`b1-virtual-matrix-03`. Lượt
`virtual-matrix-20261025-r4` khớp 220/220 ca thường và hai ca lỗi mảng
ở `fatal-checks/virtual-faults-20261025-r3`. Lượt cùng máy đo quá khứ
`engine-virtual-b1-r2` thất bại ở xác nhận demo: nhật ký ghi mất kết
nối và chưa đồng bộ máy chủ; không sửa/xóa lượt này hoặc gọi nó đạt.
Lượt chạy mới `engine-virtual-b1-r3` đã xác nhận demo và khớp đủ
220/220 ca cùng dữ liệu r4, không nới điều kiện kiểm. Lượt trước
`engine-virtual-b1-r1` đã khớp 211/211 ca r3. Claude đang viết bộ kiểm
bằng chứng mới ở `claude-thuc-hien/virtual-stop-verifier-20261025-r1/`.

Đã kiểm riêng ở cả hai bot: sửa dừng/chốt 1.596 ca; chọn/đóng vị thế
4.600 ca; đóng vị thế 2.589 ca; chọn/hủy 2.522 ca; hủy 964 ca; luồng
đặt lệnh 818 ca. Các hàm và những phần nền khác đã có nguồn sạch và
bằng chứng trong README; dùng lại, không viết lại hoặc kiểm lại toàn
bộ khi chưa đổi nguồn. Chưa có EA chính hoàn chỉnh.

## Lưu ý từ việc rà sai trước đây

Các báo cáo tác nhân cũ về quản lý có lỗi; không dùng làm đáp án.
Vị trí dữ liệu giá: bot 1 tick `0x67750`, giá bán +8, giá mua +16;
bot 3 tick `0x74790`, tương ứng +8/+16. PositionGetDouble(3) là khối
lượng; (4) giá mở; (6)/(7) dừng/chốt. SymbolInfoTick lỗi thì hai nhánh
vẫn tiếp tục xử lý sau khi in lỗi. PositionModify false là thất bại.
Điều kiện nến mua phải kiểm lại theo mã máy, không dựa kết luận sai
`Close<Open<Close`. Nhánh mode ở đầu và cuối vòng lặp chưa chốt;
không suy ra một chế độ không chạy chỉ vì nhìn một cạnh quay lại.

Mỗi lượt phải tạo phần mã/bằng chứng cụ thể, không dừng ở kế hoạch.
Giữ phần chưa rõ trong bảng; không thêm luật để làm mã trông đủ.

Bản đồ lời gọi quản lý mới:
`bot-cua-toi-1/phan-tich/dong-vi-the/management-20261025-r1/branch-map.md`
và `bot-cua-toi-3/phan-tich/dong-vi-the/management-20261025-r1/branch-map.md`.
Hai tệp chỉ là bản đồ tĩnh để chia nhánh; chúng không được dùng thay
phép chạy hoặc xác nhận hai hàm quản lý hoàn chỉnh.

## Hai chat và công việc đã giao

- Chat bot 1: `01a171c2-add5-7a92-be00-6a7afc2406a4`.
- Chat bot 3: `01a171c2-b374-7120-86bd-ae8b11eafd30`.
- Bản đồ mới `ban-do-bot-1-3/luot-20261025-r5/` đã nối bốn hàm
  bảng dừng ảo bot 1 với nguồn, phép so 220 ca, máy đo quá khứ và
  hai ca lỗi. Giữ toàn bộ cờ xác nhận đầy đủ hàm/toàn bot là false.
- Bot 3 đã giao năm phiên Claude độc lập viết dọn bảng, lấy/lưu
  dừng, lấy/lưu chốt, thời gian, mã kiểm; xem `claude-dispatch.json`
  trong lượt phân tích bot 3. Chat điều phối đọc lại nhật ký cả năm
  và xác nhận các yêu cầu thực tế đều Opus 5.5/max. Các đề xuất đã
  có mã, chat bot 3 phụ trách kiểm và ghép, chưa có phép so đạt.
- Chat điều phối còn một phiên Claude viết bộ kiểm bằng chứng
  bảng dừng ảo bot 1. Không gọi là đã bàn giao công cụ khi chưa có
  mã hoàn chỉnh và chưa chạy kiểm độc lập.

Lượt tiếp theo đã giao thêm ba phiên Claude song song cho phần hàm phụ
sắp xếp lịch sử: bot 1 `b751396e-1166-4172-8b45-1cf9ce178a64`, bot 3
`34a7fb95-fff7-482d-8268-c0b0f12d458f`, và bộ kiểm
`ed96b19a-5a71-4fbe-95d7-ba696ddb815c`. Nhật ký API xác nhận lần lượt
10, 12 và 30 yêu cầu thực tế, đều `claude-opus-5-5`, effort `max`;
Ultracode được yêu cầu nhưng chưa có bằng chứng chạy thực tế. Mã đã
được kiểm độc lập: mỗi bot 512/512 ca thường khớp từng byte, biên dịch
0 lỗi/0 cảnh báo. Ca lỗi ngoài mảng và nơi gọi còn thiếu.

## Đợt quản lý bot 3 làm song song

Đã giao tám việc cho tám phiên Claude: phần đầu, ba nhánh dời dừng,
hai bộ kiểm, rà sai khác NaN và sửa bộ so theo CPU. Nhật ký xác nhận
189 yêu cầu Opus 5.5/max; Ultracode chỉ xác nhận đã yêu cầu.
Bảy phiên giao kết quả. Phiên bộ kiểm ba nhánh bị chặn với nhãn cyber;
Codex trực tiếp viết và chạy bộ đó theo ngoại lệ đã duyệt, không gửi lại.
Kết quả đã kiểm: 636/636 phần đầu, 560/560 ba nhánh, 0 lỗi/cảnh báo.
Các đoạn chưa phải hai hàm quản lý đầy đủ hoặc EA. Phân công, mã,
biên nhận và giới hạn: PHAN-TICH-QUAN-LY-BOT-3-20261025.md và
danh-gia-claude/management-parallel-20261025-r3/dispatch.json.
