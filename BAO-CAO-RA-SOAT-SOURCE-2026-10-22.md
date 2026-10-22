# Báo cáo rà soát mã nguồn — 2026-10-22

## Phạm vi

- Đã kiểm kê 17 EX5 gốc; 7 EX5 khác là bản kiểm thử TwisterPro. Không sửa EX5 nhị phân.
- Đã đọc đủ 4 file source MQL5 hiện hành: TwisterProRecovered.mq5, TwisterInputs.mqh, TwisterSettings.mqh, TwisterFilters.mqh.
- Đã khảo sát các script build/test (Python/PowerShell/Java), các mẫu MQL5 trong verification; tệp C trung gian của bot khác chưa được phân tích từng hàm.
- Các file trong verification là bằng chứng lịch sử và có các bản sao thư viện MQL5 của bên thứ ba; không sửa để giữ dấu vết kiểm chứng.

## Phát hiện — cần xử lý trước khi phát hành bot chạy thật

| Mức độ | Thành phần | Kết quả |
|---|---|---|
| BLOCKER | TwisterProRecovered.mq5, OnInit (quanh dòng 427–431) | Từ chối chạy ngoài Strategy Tester và cả Visual Mode; giao diện/live vẫn chưa phục dựng. |
| HIGH | RecoveredPlace (quanh dòng 420–422) | Ghi nhận số lệnh theo kết quả bool CTrade, chưa kiểm ResultRetcode của máy chủ. Có thể đếm lệnh bị từ chối. |
| HIGH | OnTradeTransaction/RecoveredAlignAfterFill | DEAL_POSITION_ID có thể không đồng nhất với ticket dùng để PositionSelectByTicket trong một số vòng đời tài khoản. |
| HIGH | OnInit | Ép ORDER_FILLING_FOK; broker/symbol không hỗ trợ có thể từ chối đặt lệnh. |
| MEDIUM | RecoveredNormalizeVolume/RecoveredLots | NormalizeDouble(...,2) có nguy cơ sai ở broker có bước lot dưới 0.01. |
| MEDIUM | OnTick / Inputs | UseNewsFilter, ShowPanel và nhiều nhánh UI/live chưa được triển khai đúng phạm vi sử dụng. |
| NOTE | tools/run_market.py, build.ps1 | 'Market' là một phần đường dẫn MT5 Experts/Market khi kiểm thử; không nên xóa mù vì sẽ phá các script. |

## Attribution, metadata và giấy phép

- Mã nguồn TwisterPro hiện hành dùng #property copyright của NTDazzy và description NTdazzy — FREE FOR EVERYONE.
- 17 bản EX5 được thêm file .NOTICE.txt đi kèm, nhưng metadata bên trong EX5 **chưa được thay đổi**.
- README và LICENSE công bố quyền miễn phí trong phạm vi NTDazzy thực sự có quyền cấp phép. Không thể xác nhận các thành phần bên thứ ba đều thuộc sở hữu chủ repository.
- Chưa kiểm đầy đủ mọi chuỗi tác giả cũ/Market/Demo/Trial trong từng EX5. Không khẳng định đã xóa sạch.

## Hạng mục còn thiếu

1. Mã MQL5 tương ứng của 14 bot khác chưa có trong thư mục source, vì vậy chưa thể chỉnh trực tiếp #property của chúng.
2. Chưa chạy MetaEditor hoặc MT5 để kiểm chứng biên dịch, vận hành và backtest cho thay đổi metadata.
3. Không thay cơ chế bản quyền, kích hoạt, Trial hoặc dữ liệu nhị phân chỉ để xóa chuỗi văn bản.
4. Trước khi phát hành EX5 được biên dịch lại, cần xác minh mã nguồn, quyền của các thành phần liên quan và kết quả kiểm thử.
