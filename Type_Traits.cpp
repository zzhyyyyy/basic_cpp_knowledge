#include <iostream>
#include <type_traits>
using namespace std;

template <typename T>
void testIntegral(T a)
{
    if(is_integral<T>::value)
        cout<<boolalpha<<a<<" IS an integral type"<<endl;
    else cout<<a<<" IS an integral type"<<endl;
}
int main()
{
    testIntegral(3);
    testIntegral(false);
    testIntegral('A');
    testIntegral(3.5);
    testIntegral("zzh");
    testIntegral(30l);
    return 0;
}