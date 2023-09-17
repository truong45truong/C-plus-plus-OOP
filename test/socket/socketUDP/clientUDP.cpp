#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int clientSocket;
    struct sockaddr_in serverAddr;

    // Tạo socket
    clientSocket = socket(PF_INET, SOCK_DGRAM, 0);

    // Thiết lập thông tin địa chỉ máy chủ
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    while (true)
    {
        std::string message;
        std::cout << "Nhập tin nhắn: ";
        std::getline(std::cin, message);

        if (message == "exit") {
            break;
        }
        sendto(clientSocket, message.c_str(), message.length(),  0, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    }
        
    // Gửi dữ liệu đến máy chủ

    char buffer[1024];
    memset(buffer, '\0', sizeof(buffer));

    // Nhận phản hồi từ máy chủ
    recvfrom(clientSocket, buffer, sizeof(buffer), 0, nullptr, nullptr);

    std::cout << "Phản hồi từ máy chủ: " << buffer << std::endl;

    // Đóng socket và kết thúc
    close(clientSocket);

    return 0;
}
