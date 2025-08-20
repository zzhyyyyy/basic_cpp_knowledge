#include <iostream>
using namespace std;

void process(int &prama)
{
	cout<<"Now prama is lvalue:"<<prama<<endl;
}
void process(int &&prama)
{
	cout<<"Now prama is rvalue:"<<prama<<endl;
}
template<typename T>
void logAndprocess(T &&prama)
{
    // process(std::forward<T>(prama));
    // process(prama);//不管loaAndprocess函数的参数传入的是左值还是右值，用于接收参数的prama始终都是左值，所以只会调用第一种process
    process(move(prama));//使用move操作后 会将prama转化为将亡值(也可直接说是右值) 只会调用第二种process
    return ;
}
int main()
{
    int x=3;
    logAndprocess(x);
    logAndprocess(3);
    return 0;
}