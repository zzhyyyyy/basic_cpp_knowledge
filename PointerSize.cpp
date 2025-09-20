#include <iostream>

class MyClass {
public:
    void nonStaticFunc() {}    // 非静态成员函数
    static void staticFunc() {} // 静态成员函数
    virtual void virtualFunc() {} // 虚成员函数
};

void globalFunc() {} // 全局函数

int main() {
    std::cout << "Size of global function pointer: " << sizeof(&globalFunc) << std::endl;
    std::cout << "Size of static member function pointer: " << sizeof(&MyClass::staticFunc) << std::endl;

    std::cout << "Size of non-static member function pointer: " << sizeof(&MyClass::nonStaticFunc) << std::endl;
    std::cout << "Size of virtual member function pointer: " << sizeof(&MyClass::virtualFunc) << std::endl;

    return 0;
}