Read AGENTS.md. Đây là kiểm độc lập sai khác khi phục hồi nguồn bot3, chủ dự án sở hữu EX5. Chỉ đọc; chỉ ghi báo cáo trong dich-nguoc/khoi-phuc/claude-thuc-hien/bot3-nan-review-20261025-r1/REVIEW.md.
Không viết/sửa thuật toán giao dịch, bộ kiểm hoặc bằng chứng. Không yêu cầu bỏ qua ca lệch.

Đã chạy phần đầu quản lý bot3: 636 ca,626khớp10lệch. Các ca lệch đều nhóm nan-payload-operand-order, xem:
dich-nguoc/khoi-phuc/bot-cua-toi-3/bang-chung/kiem-quan-ly-vi-the/prelude-20261025-r1/comparison.json
và tested-sources/Bot3ManagementPrelude.mqh, check-management-prelude.py.
Mã máy và RVA tại bot3/phan-tich/dong-vi-the/management-20261025-r1/analysis.json; mô tả tại management-prelude-20261025-r2/contract.md.
Cặp phép tính thực:
mua dừng: xmm0=stop; MULSD xmm0,[unit]; xmm8=open; SUBSD xmm8,xmm0 (335a9/335ad)
mua chốt: xmm7=take; MULSD xmm7,[unit]; ADDSD xmm7,xmm6(open) (3367d/33681)
bán dừng: xmm8=stop; MULSD xmm8,[unit]; ADDSD xmm8,xmm6(open) (37be5/37bea)
bán chốt: xmm0=take; MULSD xmm0,[unit]; xmm7=open; SUBSD xmm7,xmm0 (37cbe/37cc2)

Codex đang đo trực tiếp cùng opcode SSE trên CPU Windows và so với Unicorn. Không được mặc định Unicorn và CPU giữ cùng mẫu bit NaN; không kết luận nguồn sai trước khi có đo. Nguồn hiện tại đã khớp626ca khác, chỉ10ca nhiềuNaNkhác mẫu bit khác nhau. Yêu cầu REVIEW.md:
- kiểm bộ tạo ca/pack đọc, vòng reset, trace có sai cách kiểm nào gây10lệch không;
- nêu bằng chứng nguyên nhân đã chắc, phần cần phép đoCPU;
- nếu sau này có cpu-nan-20261025-r1/probe.json thì đọc; nếu chưa có không chờ;
- không sửa kỳ vọng, không nới so sánh, không đề nghị vá nguồn dựa trên giả thuyết chưa đo.
Giao báo cáo có dẫn chứng địa chỉ/dòng, ngắn rõ. Opus5.5max; mứcUltracode chỉ ghi đã yêu cầu, không tự khẳng định dùng thực tế.

