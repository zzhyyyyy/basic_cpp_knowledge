#include<iostream>
#include<vector>
#include<algorithm>
int main()
{

    int b = 1;
    int c = 1;
    auto fun1 = [=]{  //格式中 只有捕获列表[],函数体{}必须存在
        std::cout<<"lambda function1"<<std::endl;
        return b;
    };
    auto fun2 = [&]()->int{
        c++;
        std::cout<<"lambda function2"<<std::endl;
        return c;
    };
    int a = fun1();
    int d = fun2();
    std::cout<<a<<std::endl;
    std::cout<<d<<std::endl;

    std::vector<double>v;
    v.resize(10);
    srand(time(NULL));
    std::generate(v.begin(),v.end(),[]()->double{
     return static_cast<double>(rand())/static_cast<double>(RAND_MAX);  
    });
    for(auto &i:v)  std::cout<<i<<" ";
    std::for_each(v.begin(),v.end(),[](double v){
        std::cout<<v<<" ";
    });
    //std::cout<<std::endl<<RAND_MAX<<std::endl;
    return 0;
}