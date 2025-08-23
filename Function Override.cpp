#include<iostream>
using namespace std;
class Animal{
    public:
    void virtual fun()=0;
};
class cat:public Animal{
    public:
    void fun()override{cout<<"小猫在说话"<<endl;}
};
class dog:public Animal{
    public:
    void fun()override{cout<<"小狗在说话"<<endl;}  //当子类重写基类虚函数时，若函数标签不一致，则会使基类虚函数没有在子类成功重写，导致子类也变为抽象类无法实例化，但override关键字可以提醒我们当前重写的函数签名是否和基类一致，避免低级错误
};
void getfun(Animal& Animal){//基类引用可以引用子类对象,c++内部自动完成了转换
    Animal.fun();
}
int main()
{
    Animal *p = new dog();// 父类指针可以指向子类对象 因为子类包含父类所有信息 只是有些(private域的不能访问)
    // dog *p = new Animal() 报错 子类可能会存在一些自己新建的东西 父类不能够包含 但dog* 中dog域已经声明
    cat c;
    getfun(c);
    (*p).fun();
    cout<<sizeof(Animal)<<endl;
    return 0;
}


//多态的底层原理