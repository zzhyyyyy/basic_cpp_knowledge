#include<iostream>
#include<memory>
using namespace std;
class virtual_class{
    public:
    virtual_class()=default;
    virtual_class(const virtual_class &p)=default;
    virtual void fun()=0;//如果类中有纯虚函数，析构函数必须要为虚析构函数，不然当时有基类指针指向子类对象时，很容易发生内存泄漏
    virtual ~virtual_class()=0;//单纯这样会报错，因为析构函数会被调用，这样的话单纯只有函数说明没有函数定义
    // virtual ~virtual_class() = default;
};
virtual_class::~virtual_class(){};//必须加上函数定义
// 1.virtual ~virtual_class()=0;//单纯这样会报错，因为析构函数会被调用，这样的话单纯只有函数说明没有函数定义
// virtual_class::~virtual_class(){};//必须加上函数定义
// 2.直接使用virtual ~virtual_class() = default;
class son_class : public virtual_class{
    public:
    void fun() override{cout<<"Son fun"<<endl;};
    ~son_class(){cout<<"调用son_class的析构函数"<<endl;}
};

int main()
{
    virtual_class *p = new son_class();
    (*p).fun();
    delete p;
    return 0;
}