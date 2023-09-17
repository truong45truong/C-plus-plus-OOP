#include <arpa/inet.h>
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    int serverSocket;
    struct sockaddr_in serverAddr;

    // Tạo socket
    serverSocket = socket(PF_INET, SOCK_DGRAM, 0);

    // Thiết lập thông tin địa chỉ máy chủ
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // Kết nối socket đến cổng và địa chỉ máy chủ
    bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

    std::cout << "Máy chủ UDP đang lắng nghe..." << std::endl;

    char buffer[1024];
    struct sockaddr_in clientAddr;
    socklen_t addrLen = sizeof(clientAddr);

    while (true) {
        memset(buffer, '\0', sizeof(buffer));
        
        // Nhận dữ liệu từ máy khách
        ssize_t bytesReceived = recvfrom(serverSocket, buffer, sizeof(buffer), 0, (struct sockaddr*)&clientAddr, &addrLen);
        
        std::cout << "Tin nhắn từ máy khách: " << buffer << std::endl;
        
        // Phản hồi cho máy khách
        sendto(serverSocket, buffer, bytesReceived, 0, (struct sockaddr*)&clientAddr, addrLen);
    }

    // Đóng socket và kết thúc
    close(serverSocket);

    return 0;
}
