#include <iostream>
using namespace std;
class A{
    public:
    void func()
    {
        cout<<"AAA"<<endl;
    }
};
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

    int x = 4;
    int y = std::move(x);
    cout<<x<<" "<<y<<endl;
    return 0;
}