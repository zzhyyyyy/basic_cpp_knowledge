#include<iostream>
using namespace std;
class virtual_class{
    public:
    virtual_class()=default;
    virtual_class(const virtual_class &p)=default;
    virtual void fun()=0;
};
class son_class : public virtual_class{
    public:
    void fun() override{cout<<"Son fun"<<endl;};
};

int main()
{
    son_class a;
    virtual_class *p = &a;
    (*p).fun();
    return 0;
}