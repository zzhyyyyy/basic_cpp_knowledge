#include <iostream>
using namespace std;
#define pi 3.14
class circul{
    public:
    const static int sc = 100;
    circul() = default;//默认构造
    circul(double r):r(r){};//有参数构造
    //拷贝构造
    //circul(const circul &p){*this = p;};//不推荐 可能会引发递归
    circul(const circul &p):r(p.r){};
    void set(double r){this->r = r;}
    void getr(){cout<<r<<endl;}
    double get() 
    {
        return 2*pi*r;
    }
    ~circul(){cout<<"执行析构"<<endl;};
    private:
    double r ;
};
class person{
    public:
    string name;
    int age;
    circul a;
    person() = default;
    person(string Name,int Age,circul A):name(Name),age(Age),a(A){};
    void setname(string name){this->name = name;};
    void setage(int age){this->age = age;}
    bool cmp(person &a)
    {
        return this->name==a.name && this->age==a.age;;
    }
};
class t{

};//空对象占用内存空间字节为1，为了区分空对象占内存的位置
void fun(int* &p1,int* &p2)
{
    int *t = p1;
    p1 = p2;
    p2 = t;
}

int main()
{

    // circul a = circul();
    // a.getr();
    // a.set(2);
    // a.getr();
    // cout<<a.get()<<endl;
    // circul b = circul(3);
    // circul c = b; //赋值构造
    // cout<<c.get()<<endl;
    cout<<"size of t:"<<sizeof(t)<<endl;
    cout<<"static:"<<circul::sc<<endl;
    circul d(4);
    cout<<d.get()<<endl;
    circul e(d);
    cout<<e.get()<<endl;
    // circul aw;
    // aw.set(2);
    // cout<<aw.get()<<endl;
    circul(3);//匿名对象,创建完系统会立即进行析构

    person aa = person("厦门大学",123,d);
    cout<<aa.name<<" "<<aa.age<<" "<<d.get()<<endl;
    person bb = person("厦门大学",123,d);
    if(aa.cmp(bb)) cout<<"是相同的"<<endl;
    else cout<<"不同"<<endl;
    cout<<"--------------------"<<endl;
    //利用指针交换数据
    int a1 =2 ,a2= 3;
    int* p1=&a1,*p2=&a2;
    fun(p1,p2);
    cout<<a1<<" "<<a2<<endl;
    cout<<*p1<<" "<<*p2<<endl;
    return 0;
}