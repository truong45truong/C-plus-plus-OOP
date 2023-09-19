#include <iostream>
#include <cstring>
#include <hiredis/hiredis.h> // Include hiredis library

int main() {
    // Khởi tạo một kết nối đến Redis
    redisContext* redis = redisConnect("localhost", 6379); // Thay đổi host và cổng Redis nếu cần

    if (redis == nullptr || redis->err) {
        if (redis) {
            std::cerr << "Lỗi kết nối đến Redis: " << redis->errstr << std::endl;
            redisFree(redis); // Đóng kết nối Redis nếu có lỗi
        } else {
            std::cerr << "Không thể khởi tạo kết nối đến Redis." << std::endl;
        }
        return 1;
    }

    std::string clientInfo = "Thông tin của client"; // Thay đổi thông tin client tại đây

    // Lưu thông tin client vào Redis
    redisReply* reply = (redisReply*)redisCommand(redis, "SET client_info \"%s\"", clientInfo.c_str());
    if (reply == nullptr || redis->err) {
        std::cerr << "Lỗi khi lưu thông tin client vào Redis: " << redis->errstr << std::endl;
    } else {
        std::cout << "Thông tin client đã được lưu vào Redis." << std::endl;
        freeReplyObject(reply);
    }

    // Đóng kết nối Redis
    redisFree(redis);

    return 0;
}
