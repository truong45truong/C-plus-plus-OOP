#include <iostream>
#include <memory>
#include <thread>
#include <mutex>
std::mutex lock;
void threadFunction(std::shared_ptr<int> sptr) {
    // Mỗi luồng sẽ thay đổi giá trị của shared_ptr và in ra giá trị đó.
    for(int i =0 ; i < 500000; i++){
        lock.lock();
        ++(*sptr);
        lock.unlock();
    }
}

int main() {
    // Tạo shared_ptr và khởi tạo giá trị là 0.
    std::shared_ptr<int> sharedInt = std::make_shared<int>(0);

    // Tạo một số luồng để thay đổi giá trị của sharedInt.
    std::thread t1(threadFunction, sharedInt);
    std::thread t2(threadFunction, sharedInt);

    // Chờ cho đến khi các luồng kết thúc.
    t1.join();
    t2.join();

    // In giá trị cuối cùng của sharedInt.
    std::cout << "Final Value = " << (*sharedInt) << std::endl;

    return 0;
}
