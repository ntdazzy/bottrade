# Bot 1 — đoạn đặt lệnh chờ sau khi có giá cơ sở

Đây là lát thân gọi sau khi điều kiện vào lệnh và giá cơ sở đã được cấp.
Không phải toàn bộ chương trình chính.

- Hàm dựng lại: `Bot1SubmitPendingAfterPrice` và hàm gửi một lần.
- Bằng chứng gốc: vùng native `0x32dd0..0x336c8`, cùng các hàm con được cấp
  trả lời trong bộ kiểm; `native-bindings.json` ghi địa chỉ và thứ tự đối số.
- Giữ đúng thứ tự: kiểm tiền (nếu bật) → đọc chữ số/làm tròn ba lần → kiểm
  khối lượng → giới hạn lệnh → so giá đóng băng/dừng → gửi → ghi bảng hoặc
  thử lại mã 132 rồi báo lỗi.
- Ca kiểm: **416/416 khớp**, `failed=0`; mã kiểm kết quả gốc/MQL5
  `06b446adceb3845651714e39231094912cf65237bf7af8af03c4ff4dfe0a84f3`.
- Biên dịch Script kiểm và Script API: **0 lỗi, 0 cảnh báo**.

Giới hạn: giá cơ sở, dữ liệu dịch vụ, mảng 8 khối lượng và bảng 100 hàng
được bộ kiểm cấp; chưa nối các điều kiện trước đó, nơi gọi EA, tài khoản
thật, vòng đời, hiển thị hoặc toàn bộ chương trình.
