#include<iostream>
#include<memory>
using namespace std;

class person{
    public:
    string name;
    int age;
    person() =default;
    person(int Age,string Name):age(Age),name(Name){};
    person(const person &p){
        *this = p;
    }
};

int main()
{
    unique_ptr<person> p(new person(18,"zzh"));
    cout<<p->age<<" "<<p->name<<endl;
    //unique_ptr<person>p1 = p; 报错 unique_ptr对所管理资源具有独占性，
    //unique_ptr<person>p2(p); 同一时间只允许一个unique_ptr指向内存的同一个区域
    unique_ptr<person> p1= move(p);//允许 相当于将p资源转移给p1
    cout<<p->age<<" "<<p->name<<endl;//p指针变为空指针 可能会发生segmention fault
    return 0;
}