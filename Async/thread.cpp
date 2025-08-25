#include<thread>
#include<iostream>
#include<vector>

void func()
{
    std::cout<<std::this_thread::get_id()<<std::endl;//非线程安全
    printf("%d\n",std::this_thread::get_id());//线程安全
}
int main()
{
    // thread my_thread(func);
    // if(my_thread.joinable()) my_thread.join();
    std::vector<std::thread>v;
    v.resize(10);
    for(int i=0;i<10;i++)
    {
        v[i]=std::thread(func);
    }
    for(auto &i:v)
    {
        i.join();
    }
    return 0;
}