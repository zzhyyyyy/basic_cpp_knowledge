#include<iostream>
#include<functional>

void func()
{
    std::cout<<"This is a simple Function"<<std::endl;
    return ;
}
int add(int a,int b)
{
    return a+b;
}
class base {
    public:
    static void fun1()
    {
        std::cout<<"This is a static class function"<<std::endl;
        return ;
    }
    void fun2()
    {
        std::cout<<"This is a class function"<<std::endl;
        return ;
    }
};

int main()
{
    //封装普通函数
    std::function<int(int,int)>func1 = add;
    std::function<void()>func2 = func;
    func2();
    //封装lambda表达式
    auto fun =[](int a,int b){
        return a+b;
    };
    std::function<int(int,int)>func3 = fun;
    std::cout<<func3(1,2)<<std::endl;
    //绑定静态成员函数
    std::function<void()>func4 = &base::fun1;
    func4();
    //绑定非静态成员函数
    base b;
    std::function<void()>func5=std::bind(&base::fun2,&b);//绑定非静态成员函数需要一个对象实例
    func5();
    std::function<void(base*)>func6 = &base::fun2;
    func6(&b);//也可以这种写法
    return 0;
}