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
    shared_ptr<person> p(new person(18,"zzh"));
    cout<<p->age<<" "<<p->name<<endl;
    shared_ptr<person>p1 = p; //允许 shared_ptr允许多个指针管理同一块内存区域，
    shared_ptr<person>p2(p); //同一时间只允许多个shared_ptr指向内存的同一个区域
    shared_ptr<person> p3= move(p);//允许 相当于将p资源转移给p且p变为空指针nullptr
    //cout<<p->age<<" "<<p->name<<endl;//p指针变为空指针 可能会发生segmention fault
    int cnt = p1.use_count();//返回3 p1,p2,p3
    cout<<cnt<<endl;
    return 0;
}