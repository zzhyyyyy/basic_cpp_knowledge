#include <iostream>
using namespace std;
class person{
    public:
    int age;
    string name;
    person(int age,string name):age(age),name(name){};
};
//模板参数推导默认不推导引用，除非显式指定
template<typename T>
void swapnum(T &a,T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}
int add(int a,int b) 
{
    cout<<"调用普通函数"<<endl;
    return a+b;
}
template<typename T>//模板函数默认采用自动类型推导，不可以发生隐式类型推导
T add(T &a,T &b)//但可以显式指定
{
    cout<<"调用函数模板"<<endl;
    return a+b;
}
// template<typename T>
// bool cmp(T &a,T &b)
// {
//     return a==b;
// }

template<typename T>
bool cmp(T a,T b)
{
    cout<<"调用的是普通模板"<<endl;
    if(a.age==b.age&&a.name==b.name) return true;
    return false;
}
template<>bool cmp(person p1,person p2) //模板特化 若存在模板特化,先比较模板特化,再查看函数普通模板
{
    cout<<"调用的是模板特化"<<endl;
    if(p1.age==p2.age&&p1.name==p2.name) return true;
    return false;
}
// int add(int a,int c)//普通函数调用可以发生隐式类型推导
// {
//     return a+c;
// }
int main()
{
    int a = 1,b=2;
    double c = 1.3,d = 2.4;
    swapnum(a,b); //必须推导出一致的数据类型T才可以使用
    //显性指定 swapnum<int>(a,b);
    swapnum(c,d);
    double e = add(c,d);
    cout<<a<<" "<<b<<endl;
    cout<<c<<" "<<d<<endl;
    add(a,b);//优先调用普通函数
    add<>(a,b);//使用空模板参数列表,强制调用函数模板
    cout<<a<<" "<<b<<endl;
    person p1(10,"tom");
    person p2(10,"tom");
    if(cmp(p1,p2)) cout<<"p1==p2"<<endl;
    else cout<<"p1!=p2"<<endl;
    cout<<e<<" "<<endl;
    return 0;
}