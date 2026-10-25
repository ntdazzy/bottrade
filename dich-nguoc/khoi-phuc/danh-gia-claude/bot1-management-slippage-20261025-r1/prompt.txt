# Viết nhánh dời dừng ảo theo kiểm trượt giá bot 1

Đây là phần phục hồi nguồn bot giao dịch. Codex đã đọc mã máy gốc và
chốt hợp đồng ở `dich-nguoc/khoi-phuc/bot-cua-toi-1/phan-tich/dong-vi-the/management-prelude-20261025-r1/virtual-slippage-contract.md`.
Bạn chỉ viết phần MQL5 theo hợp đồng; không cần tự phân tích EX5.
Không đọc EX5/C/bản chụp, không lệnh/MT5/git/kỹ năng lồng nhau, chỉ
Read/Grep/Glob/Edit/Write trong thư mục này. Không ghi ngoài thư mục.

Viết mã thật: `Bot1ManagementSlippage.mqh` và `SUMMARY.md`. Tên hàm:
`void Bot1AdvanceSlippageVirtualStop(...)`, giữ cờ changed và các tham
số rõ. Không sửa/đóng, không hỏi số chữ số và không ghi giờ trong phần
này. Giữ thứ tự đọc sau SymbolInfoDouble(SYMBOL_POINT), so dấu `<`,
NaN làm điều kiện sai. Giữ đúng chuỗi bán có lỗi chính tả.

Hợp đồng: int enabled đúng 1, distance_passed đúng theo bảng, trail_distance
>0; chụp mức/giá rồi hỏi point, đọc tham số sau đó. Mua cần mức+point+
distance*unit<Bid, reference+start*unit<Bid, Bid<TP-freeze,
mức<unit*limit+open. Bán cần Ask<(mức-point)-distance*unit,
Ask<reference-start*unit, freeze+TP<Ask, open-unit*limit<mức.
In trước khi tính mức mới: mua `Slippage control active`, bán
`Slippage controle active`; sau lời gọi in đọc lại Bid/Ask, khoảng,
đơn vị rồi bật changed và ghi mức mới. Nêu giới hạn phần còn thiếu.
