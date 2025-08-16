#include<iostream>
using namespace std;

class base{
    friend void showBase(base &p);//友元函数不是类的成员
    friend void showBase1(base &p)//友元函数不是类的成员
    {
        cout<<p.age<<" "<<p.name<<endl;
    }
    friend class fri;//友元类
    friend void wrong::visit(base &p);//出错 无法成功编译
    public:
    base() = default;
    base(string name,int age):name(name),age(age){};
    private:
    int age;
    string name;
};
class fri{
    public:
    void visit(base &p)
    {
        cout<<p.age<<" "<<p.name<<endl;
    }
};
class wrong{
    public:
    void visit(base &p);
};

void showBase(base &p) //友元全局函数
{
    cout<<p.age<<" "<<p.name<<endl;
}
//因为wrong类定义在base类后面
//即使在base中将wrong的visit定义为友元
//编译器在解析时也不知道wrong::visit的存在,导致无法通过编译
// void wrong::visit(base &p)
// {
//     cout<<p.age<<" "<<p.name<<endl;
// }

int main()
{
    base a = base("zzh",12);
    showBase(a);
    //无法使用 a.showBase1()的形式调用 因为友元函数不是类的成员
    showBase1(a);
    fri w;//通过友元类调用
    w.visit(a);
    return 0;
}