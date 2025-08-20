#include<iostream>
using namespace std;

class base{
    public:
    virtual void fun(){cout<<"base function"<<endl;}
};

class son:public base{
    public:
    //void fun()override{cout<<"son function"<<endl;}//报错 因为原基类函数fun不是虚函数 无法通过override进行重写
    void fun()override final{cout<<"son function"<<endl;}//正确 可通过override重写原基类虚函数
};
class grandson:public base{
    public:
    //void fun()override{cout<<"grandson function"<<endl;}//报错 无法重写父类中通过final修饰的函数
    void fun() override{cout<<"grandson function"<<endl;}
};
int main()
{
    son a;
    grandson b;
    base* p1=&a;
    base* p2=&b;
    base* p3=new base();
    cout<<"p1->fun:";
    p1->fun();
    cout<<"p2->fun:";
    p2->fun();
    cout<<"p3->fun:";
    p3->fun();

    return 0;
}