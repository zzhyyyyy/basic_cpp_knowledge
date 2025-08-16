#include <iostream>
using namespace std;
#define pi 3.14
class circul{
    public:
    circul() = default;//默认构造
    circul(double r,int max):r(r),max(new int(max)){cout<<"调用有参数构造"<<endl;};//有参数构造
    //拷贝构造
    //circul(const circul &p){*this = p;};//不推荐 可能会引发递归
    circul(const circul &p):r(p.r),max(new int(*p.max)){cout<<"调用拷贝构造"<<endl;};
    void set(double r){this->r = r;}
    void getr(){cout<<r<<endl;}
    double get() 
    {
        return 2*pi*r;
    }
    ~circul(){if(max!=nullptr) {delete max;cout<<"delete pointer"<<endl;} cout<<"执行析构"<<endl;};
    private:
    double r ;
    int* max; 
    //浅拷贝对于指针问题可能会造成同一块内存多次释放
    //使用深拷贝来解决->不使用系统自带的默认拷贝函数
};

void fun(const circul& p)
{
    return ;
}
circul fun1(const circul& p)
{
    cout<<"&p:"<<&p<<endl;
    return p;
}
int main()
{
    circul a(10,10);
    circul c(a);
    // circul b(a);
    // fun(a);
    // circul c = fun1(b);
    // cout<<"&c:"<<&c<<endl;
    //会输出几次拷贝构造呢？
    //b(a)

    return 0;
}