# Kết thúc quản lý mức ảo — bằng chứng từng phần ngày 25/10/2026

Đã thêm nguồn Bot1ManagementVirtualFinish.mqh và
Bot3ManagementVirtualFinish.mqh. Đây chưa phải hai hàm quản lý đầy đủ hoặc EA.

| Phần | Nguồn | Lượt kiểm hiện hành | Kết quả |
|---|---|---|---|
| Bot 1: cao/thấp, khóa lời, bộ đếm, chạm dừng hoặc lưu bảng | Bot1ManagementVirtualFinish.mqh | finish-root-20261025-r4; b1-virtual-finish-root-02 | 1.260/1.260 khớp; biên dịch 0 lỗi/cảnh báo |
| Bot 3: cao/thấp, khóa lời và bộ đếm | Bot3ManagementVirtualFinish.mqh, hai hàm đầu | finish-root-20261025-r1; b3-virtual-finish-check-01 | 1.304/1.304 khớp, gồm 524 cao/thấp và 780 khóa/bộ đếm; biên dịch 0/0 |
| Bot 3: lưu dừng rồi chốt vào hai bảng | Cùng tệp, Bot3StoreVirtualLevels | store-20261025-r2; b3-virtual-store-check-02 | 296/296 khớp trên đúng nguồn đã ghép; biên dịch 0/0 |

Các lượt ở bang-chung/kiem-quan-ly-vi-the/ của mỗi bot.
Mô tả trước viết và xác nhận mã nguồn ở
phan-tich/dong-vi-the/management-virtual-finish-20261025-r1/.

## Những điều đã so

- Giá từng bit, cờ đã đổi, bộ đếm có cuộn số 32 bit, cờ tổng,
  giá mua/bán và thứ tự/đối số lời gọi trong phạm vi từng bộ.
- Bot 1: đủ 1.500 ô bảng, cờ bảng và chỉ số; vé khớp ở hàng 0/250/499,
  vé trùng ở hàng 1/17/499, không khớp và vé NaN. Có ca cờ đổi đã true
  từ trước để kiểm bỏ bộ đếm. Đây là bổ sung sau nhận xét rà độc lập.
- Bot 3: đọc lại chỉ số và mức sau lời gọi lấy đơn vị giá; giữ mức đã
  chụp ở phép so kế tiếp. Bộ lưu so cả 2.500 ô trong hai bảng và cờ.
- Giữ khác biệt gốc: bot 1 phía bán dùng tham chiếu lưu thô cho cổng
  bộ đếm; bot 3 dùng mốc đã chọn ở cả mua và bán. Không sửa thành cùng luật.
- Bot 3 chỉ tính trên CPU các phép có hai NaN theo bộ mẫu đã đo;
  các lệnh còn lại chạy trong Unicorn. Không đổi byte EX5.

Rà độc lập lần đầu thấy bộ bot 1 thiếu cờ true có sẵn và mẫu hàng sau;
Codex bổ sung, chạy lại và được rà xác nhận không còn lỗi có cơ sở trong
phạm vi mới. Lượt 484 ca cũ được giữ; không dùng nó để chứng minh mẫu vừa thêm.
Lượt finish-root-20261025-r2 sai khởi tạo bảng gốc do còn dòng ghi đè bảng;
đã bỏ dòng của bộ kiểm, giữ bằng chứng lỗi và chạy r3. Nguồn thuật toán không đổi.

## Phân công

Hai thân hàm cao/thấp và khóa/bộ đếm bot 3 do hai phiên Claude viết,
giữ nguyên khi ghép. Codex trực tiếp làm phần lưu bảng bot 3 và phần
bot 1 theo ngoại lệ các phạm vi Claude từ chối. Nhận xét Claude được
đối chiếu lại; kết quả kiểm gốc/MQL5 ở trên mới là bằng chứng chạy.

## Giới hạn và bước còn lại

- Chỉ kết thúc nhánh ảo. Chưa so cả vòng nhiều vị thế, toàn quản lý hoặc EA.
- Hàm kiểm đóng ở đường chạm giá được chặn tại ranh giới. Khi đóng,
  cờ tổng true được ghi theo đường đó; chưa thực thi toàn hàm đóng trong lượt này.
- Lời đáp dịch vụ và các thay đổi sau API được cấp; chưa phải giao dịch thật,
  phép chứng minh hết RAM, mọi lỗi tài khoản hoặc khởi động lại.
- Bot3ManagementVirtualFinishFlow.mqh đã được Claude ghép theo mô tả,
  biên dịch với API thật sạch; chưa có phép so toàn hàm bao này.
- Hai nhánh dời dừng thật theo thời gian có bộ riêng 492 ca; hai nhánh
  khoảng giá mới có nguồn và biên dịch. Còn các nhánh thật khác, nơi gọi,
  cài đặt, hiển thị, trạng thái lưu và chạy cặp EA hoàn chỉnh.

Không dùng các số ca trên làm phần trăm hoàn thành bot.
