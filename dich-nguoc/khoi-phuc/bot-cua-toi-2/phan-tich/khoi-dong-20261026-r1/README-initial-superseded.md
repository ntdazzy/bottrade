# Khởi động phân tích bot2 — 2026-10-26

## Đầu vào đã xác định

| Mục | Bằng chứng | SHA-256 | Trạng thái |
|---|---|---|---|
| EX5 hiện có | `1-dang-tin-nhat/bot-cua-toi-2/bot-cua-toi-2.ex5` | `0b501b712685844b8cdd17a3bf691767383e7edd727fb62c4630fe323050c557` | Đã kiểm, 226872 byte |
| Bộ cài đặt 1 | `bo-cai-tac-gia/bot-cua-toi-2_HighRisk_Max50DD.set` | `3bdeba636532cc3ba5c739a2823702b2a55d5f1c6383706df60e1c1c088c6d5f` | Đã kiểm |
| Bộ cài đặt 2 | `bot-cua-toi-2_LowRisk_Max15DD.set` | `e6d8d6218f3cd6f8cac8fdb1c2923a221d306d04449777563952d41b93ed9daf` | Đã kiểm |
| Bộ cài đặt 3 | `bot-cua-toi-2_MediumRisk_Max30DD.set` | `cfe384ec07cbbfa02c86c23e913f4cb4b5c70837bebaeda42e039d7667af93d9` | Đã kiểm |
| Bộ cài đặt 4 | `bot-cua-toi-2_PropFirm_10_5.set` | `f3c0a348e081d07d9277be95af0eaeb9efb8e4b11b714ba3e4b2b1f7f54097f9` | Đã kiểm |
| Bộ cài đặt 5 | `bot-cua-toi-2_PropFirm_5_2.5.set` | `e2ea32de00a41f38d94ee3429230a8a09a040f0a759e9c8fcfb4dd9890222fc8` | Đã kiểm |

## Phát hiện quan trọng

`dich-nguoc/khoi-phuc/bot-cua-toi-2/phan-tich/ban-ex5-06` không phải bằng
chứng của EX5 hiện tại. Tệp cũ ghi nguồn là `Goldbot One MT5.ex5`, SHA-256
`390d8ab14fc213ff4b8cbe5084bec545526e62c6028516fe21219a59398ce795`,
trong khi EX5 bot2 hiện tại có SHA khác hoàn toàn. Bản chụp cũ cũng có vùng
chính 311296 byte, còn EX5 hiện tại dài 226872 byte. Vì vậy không được dùng
83 hàm, địa chỉ nền `0x24fc8630000`, hay mã trung gian cũ để kết luận cho
bot2 hiện tại.

## Danh sách chức năng nhìn thấy hiện nay

Chưa có bản chụp mã máy, danh sách hàm, chuỗi, đầu vào được gắn với SHA của
EX5 hiện tại. Năm `.set` chỉ chứng minh các cấu hình tên rủi ro; chúng không
chứng minh thuật toán, nhánh lệnh, giao diện, trạng thái hay lỗi. Do đó chưa
đánh dấu bất kỳ chức năng nào là đã phân tích, đã phục hồi hoặc đủ để giao
Claude viết mã.

## Blocker và bước tiếp theo

Blocker cụ thể: thiếu bản chụp vùng nhớ/mã máy và metadata được tạo từ đúng
`bot-cua-toi-2.ex5` SHA-256 nêu trên. Cần chạy lại công cụ chụp trong MT5 thử
riêng, hoặc cung cấp thư mục phân tích đúng bản này; sau đó mới lập bản đồ
địa chỉ hàm, đầu vào, tài nguyên, khởi động/thoát, giao dịch và lỗi. Không
được chạy bản chụp cũ rồi gán sang EX5 mới.

Tài liệu này chỉ là báo cáo khởi động; chưa có phần nào đạt hoàn chỉnh và
chưa tạo mã MQL5.

## Bổ sung đối chiếu bản đã cài

Đã tìm thấy `C:/Users/NTD/Desktop/BotTradeEA/local/market-demos-20261020/dich-nguoc-luot2/terminal/MQL5/Experts/Market/Goldbot One MT5.ex5`.
Tệp này dài 226872 byte, SHA-256 `390d8ab14fc213ff4b8cbe5084bec545526e62c6028516fe21219a59398ce795`.
Nó cùng kích thước với EX5 workspace và chỉ khác 52 byte; các byte khác nằm
trong hai vùng chuỗi UTF-16 `0xa8..0xea` và `0x1a8..0x1d0`, các byte ngoài
đó trùng. Đây là dấu hiệu mạnh của bản đổi tên, nhưng vẫn giữ riêng hai SHA.

Bản chụp `ban-ex5-06` đúng với bản đã cài: base `0x24fc8630000`, vùng chính
311296 byte, 83 hàm. Có thể dùng để lập danh sách ban đầu với nhãn “bản đã
cài”; chưa gọi là đã phục hồi workspace cho đến khi đối chiếu đầy đủ chuỗi,
địa chỉ và metadata. Chi tiết nằm trong `inputs-r2.json`.
