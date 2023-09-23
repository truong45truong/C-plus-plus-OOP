#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass(int val) : value(val) {}
    void printValue() {
        std::cout << "Value: " << value << std::endl;
    }

private:
    int value;
};

int main() {
    // Tạo shared_ptr
    std::shared_ptr<MyClass> sharedObj = std::make_shared<MyClass>(42);

    // Sử dụng shared_ptr
    sharedObj->printValue();

    // Sử dụng nhiều shared_ptr chia sẻ cùng một đối tượng
    std::shared_ptr<MyClass> anotherSharedObj = sharedObj;

    // Tự động giải phóng bộ nhớ khi không còn references
    sharedObj.reset(); // sharedObj vẫn còn anotherSharedObj sử dụng nó
    anotherSharedObj.reset();  // Looix
    anotherSharedObj->printValue();
    sharedObj = anotherSharedObj;
    sharedObj->printValue();
    return 0; // Khi main() kết thúc, bộ nhớ được giải phóng tự động.
}
