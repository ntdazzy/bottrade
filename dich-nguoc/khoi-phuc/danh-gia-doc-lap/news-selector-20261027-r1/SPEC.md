# Toàn bộ hàm chọn tin cần chặn

| Ô trạng thái | Bot 1 | Bot 3 |
|---|---|---|
| Hàm gốc | `7310..74f8` | `7c30..7e18` |
| Thời điểm chọn | `6a390` | `1d6ca0` |
| Nhãn chọn | `6a398` | `1d6ca8` |

Hàm mới BotNUpdateNewsSelection nhận tham chiếu tới3thời điểm,3cờ bật,
3số phút sau tin và trạng thái trả. Không cấp một ảnh chụp thời gian duy
nhất; dùng TimeTradeServer trực tiếp theo đúng nhánh gốc.

1. Xóa thời điểm chọn về0, nhãn vềchuỗi rỗng như raw gọi helperchuỗi5c0.
2. Với thứ tự NFP → lãi suất → CPI: nếu cờ khác0 và thời điểm>0,
   chụp end=thời điểm+thời lượng; sau đó mới gọi TimeTradeServer. Chỉ
   xét khiend>giờ trả về (so chặt, hết hạn đúng mốc thì bỏ).
3. Thời lượng phải là phép nhân số nguyên32bit với60, rồi mở rộng dấu
   thành64bit. Dùng `(long)(int)((uint)minutes*60)`. Không viết
   `(long)minutes*60`, vì đó là công thức64bit khác hành vi gốc.
4. Khi NFP hợp lệ, đọc lại thời điểmNFP sau lời gọi giờ để ghi vào ô
   chọn và đặt nhãnNFP. Với lãi suất/CPI, sau lời gọi giờ mới đọc lại
   thời điểm và ô đã chọn: chỉ ghi nếu ôchọn0 hoặc thời điểm mới nhỏ hơn.
   Bằng thời điểm thì giữ phần đã chọn trước. Nhãn là `Interest rates`
   hoặc `CPI`, đúng chữ hoa/thường và khoảng trắng.
5. Vẫn gọi giờ ở nhánh lãi suất/CPI đủ cờ/thời điểm trước khi so với
   tin đã chọn. Không rút gọn thành so thời điểm trước rồi bỏ đọc giờ.
   Các ô có thể đổi trong lời gọi dịch vụ; không tự dùng lại ảnh chụp cũ.

Nguồn số học cũ BotNSelectNewsBlock vẫn dùng cho kiểm từng phần; đã sửa
độ rộng phép nhân trong cùng lượt. Phép kiểm cũ1620ca dùng số phút nhỏ,
chưa phát hiện khác biệt tràn32bit. Lượt mới kiểm946ca nguồn số học đã
sửa trên các đầu vào cùng giờ cố định; so với kết quả native thật.

Ca chứng minh lỗi: NFP900, giờ1000, phút2147483647. Gốc nhân32bit ra-60,
end840 nên không chọn. Công thức nguồn cũ64bit cho end128849019720 và
sẽ chọn900; đây là đối chiếu công thức từ nguồn cũ, không gọi là đã
đo bản biên dịch cũ. Nguồn MQL5 mới đã chạy thật và trả0 như raw.

Bộ kiểm mới961ca mỗi bot: tràn32bit/64bit, cờbyte0/1/2/255, thứ tự
chọn và bằng thời điểm, nhãn, các lần giờ khác nhau, thay thời điểm/
cờ/phút/ôchọn trong dịch vụ. Chạy nguyên hàm gốc, không sửa byte hoặc
chặn helperchuỗi; chỉ cấp trả lời giờ và cấp phát thành công. So từng
byte kết quả, nhãn, toàn đầu vào sau tác dụng phụ và trạng thái trước
mỗi lần đọc giờ. Không có lịch trực tuyến hoặc lệnh giao dịch thật.

Còn dữ liệu/lời gọi từ lịch và nhánh hủy/đóng trước selector, lỗi cấp
phát thật, toàn evaluator vàEA. Phép kiểm này không xác nhận toàn bot.
