#include<iostream>
using namespace std;
class A {
    public:
    A(){};
    A(int a):a(a){};
    A(const A &a) = delete;
    A& operator=(const A&a)
    {
        if(this == &a) return *this;
        cout<<"xxx"<<endl;
        this->a = a.a;
        return *this;
    }
    void geta(){cout<<a<<endl;}
    private:
    int a;
};
int main()
{
    A a(3);
    A b(3);
    b = a;//正确 拷贝构造符定义声明了
    //b = a; //报错 因为拷贝运算符已经delete了{A& operator=(const A&a)=delete;}
    //A c = a; 报错 因为A类的拷贝构造函数已经被delete了
    b.geta();
    a.geta();
    return 0;
}