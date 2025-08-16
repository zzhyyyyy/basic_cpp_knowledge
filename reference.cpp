#include<iostream>
using namespace std;
void func(int &c)
{
    cout<<"左值引用"<<endl;
    return ;
}
void func(int &&c)
{
    cout<<"右值引用"<<endl;
    return ;
}
template<typename T>
void g(T &&c)  //要配合上模板才能称之为万能引用，否则就是普通的右值引用
{
    func(forward<T>(c));
}
// 比如当前g参数是3 类型自动推导使得typename->int 故void函数实质为 void g(int &&c)
int main()
{
    int a = 3;
    g(a);
    g(move(a));
    return 0;
}