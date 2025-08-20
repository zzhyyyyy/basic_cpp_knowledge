// #include <iostream>
// using namespace std;
// class Singleton {
// private:
//     // 1. 私有化构造函数
//     Singleton() {
//         std::cout << "Singleton instance created!\n";
//     }
//     // 2. 删除拷贝构造和赋值操作符，防止复制
//     // Singleton(const Singleton&) = delete;
//     // Singleton& operator=(const Singleton&) = delete;

// public:
//     // 3. 提供全局访问点
//     static Singleton& getInstance() {
//         // 4. 使用静态局部变量
//         // C++11保证静态局部变量的初始化是线程安全的
//         static Singleton instance;
//         return instance;
//     }
//     Singleton(const Singleton& p)
//     {
//         *this = p;
//     }
//     // 一个示例成员函数
//     void doSomething() {
//         std::cout << "Doing something...\n";
//     }
//     // 析构函数（如果需要特殊清理，可以在此实现）
//     ~Singleton() {
//         std::cout << "Singleton instance destroyed!\n";
//     }
// };

// // 使用示例
// int main() {
//     std::cout << "Main starts\n";
//     cout<<"类Singleton的大小"<<sizeof(Singleton)<<endl;
//     // 获取单例实例并使用它
//     Singleton a = Singleton::getInstance();
//     Singleton b = a;//如果不删除拷贝构造和移动构造 则单例模式无意义
//     // 再次获取，仍然是同一个实例
//     a.doSomething();
//     b.doSomething();
//     cout<<"对象a的地址是:"<<&a<<endl;
//     cout<<"对象b的地址是:"<<&b<<endl;
//     std::cout << "Main ends\n";
//     // 程序结束时，静态局部变量 `instance` 会自动析构
//     return 0;
// }

//  ###单例模式
#include<iostream>
using namespace std;
class base{
    public:
    static base& getExam()//使用静态局部变量是实现单例模式的首选方法 在C++11及之后的版本中 static都能够保证线程安全
    {
        static base a;// 我认为也可以简单理解为static变量只会在第一次使用的时候进行初始化，其他时候初始化时就直接使用第一次初始化好的实例
        return a;
    }
    private:
    base(){};
    base(const base &p)=delete;//删除拷贝构造函数
    base& operator=(const base &p)=delete;//删除拷贝构造运算符
    base(const base &&p)=delete;//删除移动构造函数
    base& operator=(base &&p)=delete;//删除移动赋值运算符
    static base example;//如何说明当前example还是"空"的呢?
};
int main()
{
    
    //base a = base::getExam();会报错 因为这句代码会调用已经删除的拷贝构造函数
    base &a = base::getExam();//但使用引用不会
    cout<<&a<<endl;
    cout<<&base::getExam()<<endl;
    return 0;
}





























