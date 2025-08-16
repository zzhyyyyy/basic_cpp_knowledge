#include <iostream>
using namespace std;
class Base{
    public:
    void fun(){
        cout<<"调用Base类函数"<<endl;
    }
};
class son:public Base{
    public:
    void fun(){
        cout<<"调用son类函数"<<endl;
    }
};

int main()
{
    son a =son();
    a.fun();
    a.Base::fun();
    return 0;
}