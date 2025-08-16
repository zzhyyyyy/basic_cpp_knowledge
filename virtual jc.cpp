#include<iostream>
using namespace std;
class Animal{//虚基类
    public:
    int age;
};
class ox:virtual public Animal{};//虚继承
class horse:virtual public Animal{};
class db : public ox,public horse{};
int main()
{
    db b;
    //b.age = 100;  //继承多个基类且基类都存在相同变量 造成二义性
    b.ox::age = 100; //通过使用基类作用域表明访问哪个类的变量
    b.horse::age = 200;
    cout<<b.ox::age<<endl;
    cout<<b.horse::age<<endl;
    //但这样很容易造成内存浪费 
    //即只需要一个变量却继承了两个
    //采用虚继承的方式解决

    //采用虚继承之后 可以不采用基类作用域了 因为变量已经明确
    cout<<b.age<<endl;
    return 0;
}