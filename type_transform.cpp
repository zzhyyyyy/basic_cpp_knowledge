#include<iostream>
using namespace std;
int main()
{
    int a = 3;
    double f = static_cast<double>(a);
    cout<<typeid(a).name()<<endl;
    cout<<typeid(f).name()<<endl;
    void* vp = &a;
    int* ip=static_cast<int*>(vp);
    cout<<typeid(vp).name()<<endl;
    cout<<"指针Ip所指向的值为:"<<*ip<<endl;
    //cout<<"指针Vp所指向的值为:"<<*vp<<endl; 报错对于void指针不允许解引用
    cout<<"指针Vp所指向的值为:"<<*((short*)vp)<<endl;//正确
    return 0;
}