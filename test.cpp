#include <iostream>
using namespace std;
class A{
    public:
    A();
    A(const A &p);
    void func()
    {
        cout<<"AAA"<<endl;
    }
};
A::A(){cout<<"struct"<<endl;}
A::A(const A &p){cout<<"copy"<<endl;}
class B:public A{
    public:
    void func()
    {
        cout<<"BBB"<<endl;
    }
};

int main()
{
    B a;//子类对象
    A* p = &a;//父类指针可以指向子类对象
    (*p).func();
    A aa;
    //B* p1 =&aa;//子类指针不能指向父类对象
    int* p2 = new int(1);
    int* p3 =p2;
    p2 = nullptr;//改变的是p2的指向，而不是改变指向的内容
    cout<<"*p2 "<<endl;
    cout<<"*p3 "<<*p3<<endl;

    cout<<"--------------------------------"<<endl;
    A aaaa;
    A &cc=aaaa;//如果不使用引用 则会调用拷贝构造函数
    return 0;
}