#include<iostream>
using namespace std;


template<typename Tname,typename Tage>
class person{
    public:
    Tname name;
    Tage age;
    person(Tname name,Tage age):name(name),age(age){};
    void output()
    {
        cout<<this->name<<" "<<this->age<<endl;
    }
}; 
int main()
{
    person a = person("zzh",20);
    person b("zzz",22);
    a.output();
    b.output();
    string c ="";
    cout<<typeid(c).name()<<endl;
    return 0;
}