#include<iostream>
using namespace std;
class calculator{
    public:
        int x1,x2;
        void setx(int x1,int x2)
        {
            this->x1 = x1;
            this->x2 = x2;
            return ;
        }
        virtual int fun(int x,int y)=0;//纯虚函数，可以直接写=0
        //当类内存在纯虚函数，这个类也称为抽象类
        //virtual ~calculator(){};//虚析构函数 保证子类析构也能正常调用
        virtual ~calculator()=0;//纯虚析构函数 如果直接写=0 会报错
}; 
calculator::~calculator()//需在类外补上纯虚析构函数说明
{
    cout<<"纯虚析构函数调用"<<endl;
}
class add:public calculator{
    public:
    int fun(int x,int y){
        cout<<"执行add操作"<<endl;
        return x+y;
    }
};
class sub:public calculator{
    public:
    int fun(int x,int y){
        cout<<"执行sub操作"<<endl;
        return x-y;
    }
};
class multipul:public calculator{
    public:
    int fun(int x,int y){
        cout<<"执行multipul操作"<<endl;
        return x*y;
    }
};
class divide:public calculator{
    public:
    int fun(int x,int y){
        if(!y){cout<<"除数为0,非法操作";return INT_MAX;}
        cout<<"执行add操作"<<endl;
        return x+y;
    }
};

int main()
{
    // calculator c;//抽象类不允许实例化对象
    // c.setx(10,10);  
    // c.fun(c.x1,c.x2);
    add a;
    //calculator* pc =&a;
    // calculator* pc = new add;
    a.setx(20,10);
    int r = a.fun(a.x1,a.x2);
    cout<<r<<endl;
    return 0;
}