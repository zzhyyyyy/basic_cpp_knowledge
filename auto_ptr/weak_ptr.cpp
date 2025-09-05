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
    shared_ptr<person> p(new person(18,"zzh"));  //weak_ptr必须结合shared_ptr进行使用
    cout<<p->age<<" "<<p->name<<endl;
    //unique_ptr<person>p1 =static_cast<unique_ptr<person>>(p); //报错 不存在使用static_cast将shared_ptr转换至unique_ptr
    //unique_ptr<person>p2(p); 同一时间只允许一个unique_ptr指向内存的同一个区域
    shared_ptr<person> p1= p;//允许 相当于将p资源转移给p1
    weak_ptr<person>p2;
    p2 = p1; //对象的销毁由最后一个 shared_ptr 决定
    cout<<static_cast<shared_ptr<person>>(p2)->name<<endl;
    cout<<"使用次数："<<p.use_count()<<endl;
    return 0;
}