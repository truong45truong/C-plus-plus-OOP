# Hai đoạn mã cho TCP và UDP có nhiều điểm khác biệt quan trọng vì chúng sử dụng hai giao thức mạng khác nhau, làm việc theo cách khác nhau và có tính chất khác nhau. Dưới đây là một số điểm khác biệt quan trọng giữa chúng:

## 1. Giao thức:

### Mã TCP sử dụng giao thức TCP (Transmission Control Protocol).
### Mã UDP sử dụng giao thức UDP (User Datagram Protocol).
## 2. Tính đáng tin cậy:

### TCP đảm bảo tính đáng tin cậy cho việc truyền tải dữ liệu bằng cách kiểm soát lỗi, đảm bảo thứ tự và tái gửi dữ liệu nếu cần.
### UDP không đảm bảo tính đáng tin cậy; nó truyền dữ liệu mà không kiểm tra lỗi, không đảm bảo thứ tự và không tái gửi dữ liệu.
## 3. Thiết lập kết nối:

### TCP yêu cầu thiết lập một kết nối hai chiều (connection-oriented) giữa máy chủ và máy khách trước khi truyền dữ liệu.
### UDP không yêu cầu thiết lập kết nối trước khi truyền dữ liệu và là kết nối không đồng bộ (connectionless).
## 4. Sử dụng hàm:

### Trong mã TCP, sử dụng accept, bind, listen, và connect để thiết lập và quản lý kết nối.
### Trong mã UDP, không cần thiết lập kết nối trước, và bạn sử dụng recvfrom và sendto để gửi và nhận dữ liệu.
## 5. Địa chỉ và cổng:

### TCP sử dụng địa chỉ và cổng để xác định máy chủ và máy khách trong quá trình thiết lập kết nối.
### UDP cũng sử dụng địa chỉ và cổng nhưng không yêu cầu thiết lập kết nối trước.
## 6. Tính chất thời gian thực:

### TCP thích hợp cho các ứng dụng yêu cầu đáng tin cậy và kiểm soát như truyền tệp, email.
### UDP thích hợp cho các ứng dụng yêu cầu thời gian thực và hiệu suất như trò chơi trực tuyến, streaming video.
## 7. Cơ chế kiểm tra lỗi:

### TCP có cơ chế kiểm tra lỗi và tái gửi dữ liệu khi cần.
### UDP không có cơ chế kiểm tra lỗi hoặc tái gửi, dữ liệu có thể bị mất hoặc bị sai lệch.
### Nhớ rằng việc lựa chọn giữa TCP và UDP phụ thuộc vào yêu cầu cụ thể của ứng dụng của bạn. TCP thường được sử dụng trong các tình huống đòi hỏi đáng tin cậy và kiểm soát, trong khi UDP thích hợp cho các ứng dụng yêu cầu thời gian thực và hiệu suất cao.