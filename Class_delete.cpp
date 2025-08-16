#include<iostream>
using namespace std;
class A {
    public:
    A() = delete;
    A(int a):a(a){};
    A(const A &a) = delete;
    void geta(){cout<<a<<endl;}
    private:
    int a;
};
int main()
{
    A a(2);
    A b(3);
    b = a;
    //A c = a; 报错 因为A类的拷贝构造函数已经被delete了
    b.geta();
    a.geta();
    return 0;
}