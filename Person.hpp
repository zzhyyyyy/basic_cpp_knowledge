#include <iostream>
using namespace std;
template <typename T1,typename T2>
class person{
    public:
    T1 name;
    T2 age;
    person(T1 name ,T2 age);
    void showperson();
};
template <typename T1,typename T2>
person<T1,T2>::person(T1 name,T2 age)
{
    this->name = name;
    this->age = age;
}
template <typename T1,typename T2>
void person<T1,T2>::showperson()
{
    cout<<this->name<<" "<<this->age<<endl;
}
// int main()
// {
//     person a = person("zzh",12);
//     cout<<a.age<<" "<<a.name<<endl;
//     a.showperson();
//     return 0;
// }