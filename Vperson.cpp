#include "Person.hpp"
#include<iostream>

using namespace std;

int main()
{
    person a = person("zzh",12);
    cout<<a.age<<" "<<a.name<<endl;
    a.showperson();
    return 0;
}