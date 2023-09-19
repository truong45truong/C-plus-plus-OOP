#include <iostream>

// Lớp cơ sở (Base class) với phương thức ảo
class Animal {
public:
    virtual void speak() {
        std::cout << "Animal is speaking." << std::endl;
    }
};

// Lớp con (Subclass) kế thừa từ lớp cơ sở và ghi đè phương thức ảo
class Dog : public Animal {
public:
    void speak() override {
        std::cout << "Dog is barking." << std::endl;
    }
};

int main() {
    Dog dogV = Dog();
    Animal* myAnimal = &dogV; // Con trỏ của lớp cơ sở trỏ đến đối tượng của lớp con
    myAnimal->speak(); // Gọi phương thức ảo, kết quả phụ thuộc vào loại đối tượng thực sự

    // delete myAnimal;

    return 0;
}
