# Ngữ cảnh khởi động bot 3 trước lần chuẩn bị đầu

`Bot3StartupContext.mqh` phục hồi đoạn `0x3ce6..0x4580`, sau chọn
tần suất ban đầu và trước lần gọi chuẩn bị `0xe0c0`. Địa chỉ tính
bằng phép trừ đầy đủ base `0x17156250000`, không lấy đuôi địa chỉ C.

| Dữ liệu | RVA |
|---|---|
| Bình luận gốc → bình luận giao dịch | `0x1d6ff8 → 0x6d568` |
| Mã nhận diện gốc → mã đang dùng | `0x1d6ff0 → 0x6d564` |
| Mã biểu đồ → mã đang xử lý | `0x1d6e28 → 0x74958` |
| Đuôi mã giá | `0x6d230` |
| Đỉnh vốn ngày, cờ chặn, mốc bảng | `0x75348`, `0x75320`, `0x75338` |
| Tổng/số mục lịch sử và cờ dọn | `0x77358`, `0x77354`, `0x752d4` |
| Cờ cỡ ô, kích thước đầu vào | `0x752e8`, `0x75328`, `0x75330` |
| Tỷ lệ, kích thước ô đầu ra | `0x1d6f48`, `0x752d8`, `0x752e0` |

Giữ thứ tự ghi, bốn phép nhân, việc chỉ tự tìm đuôi khi chuỗi đuôi
rỗng và thông báo khi tìm được. NULL khác chuỗi rỗng. Các trường
không thuộc đoạn này giữ nguyên.

## Kết quả

- `b3-startup-context-20261029-r1`: **298/298 ca khớp**, 17 trường,
  5 chuỗi, trạng thái tại 30 lần in và khi kết thúc.
- 1.192 phép nhân được đối chiếu bằng CPU thật. Bốn vị trí gốc
  `0x3db9`, `0x3dcb`, `0x3e0e`, `0x3e1c` và hằng `175/24.5`
  được kiểm trực tiếp trước chạy.
- Có mã giá ngắn/dài/NULL/UTF-16, đuôi có sẵn/rỗng, mã nhận diện
  sát giới hạn, các cờ byte, số không hợp lệ và giữ mã lỗi.
- Nguồn kiểm `b3-startup-context-check-20261029-r1` và bộ ghép
  `b3-all-headers-api-20261029-r1` biên dịch 0 lỗi, 0 cảnh báo.
- Codex kiểm độc lập không thấy lỗi trọng yếu trong đoạn này.

## Giới hạn

Chưa chạy phần đổi giờ/đổi tiền/chọn tần suất phía trước, lần chuẩn
bị đầu hoặc toàn OnInit. Vùng trả chuỗi từ phần trước được nạp trước;
cấp phát thành công được cấp. Không thực thi quyền dùng; bộ chạy
dừng nếu chạm `0xc30`, `0x61a0`, `0x485e0` hoặc `0x55bc0`.

Các bản nháp trước dùng sai địa chỉ/hàm không phải bằng chứng của
đoạn này. Chưa có EA hoàn chỉnh hay phép chạy cặp toàn bot.

## Chạy lại

`cong-cu/kiem-ngu-canh-khoi-dong-bot-3.py`: `generate`, `prepare RUN`,
`mql5 RUN --build BUILD`, `original RUN`, `compare RUN`. Dùng máy
MT5 bot 3 riêng và tên lượt mới; giữ bằng chứng cũ.

[Kết quả tổng hợp](verification.json), [danh sách tệp chung](../dispatch-and-bot3-context-20261029-r1-manifest.txt).
