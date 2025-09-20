#include<iostream>
#include<thread>
#include<mutex>

std::mutex mtx;//lock、unlock、try_lock
void create(const int N,int &target)
{
    //std::lock_guard<std::mutex>lock(mtx);//lock_guard就是在获取锁并自动管理锁的释放
    //等价于 std::lock_guard lock(mtx);
    mtx.lock();
    for(int i=0;i<N;i++) target++;
    mtx.unlock();//虽然guard_lock可以自动管理锁 但也可由用户自己解锁
}
void sub(const int N,int &target)
{
    std::unique_lock<std::mutex>lock(mtx);
    for(int i=0;i<N;i++) target--;
    //mtx.unlock();
}
int main()
{   
    const int N = 1000000;
    auto fun =[](){std::cout<<"Thread Ready"<<std::endl;};
    std::thread m(fun);
    if(m.joinable()) m.join();
    std::thread mm(fun);
    if(mm.joinable())mm.join();
    int target=0;
    std::thread t(create,N,std::ref(target));  //thread源码(callback Function,Args&& ... __args)
    std::thread t1(create,N,std::ref(target));
    t.join();
    t1.join();
    std::cout<<target<<std::endl;
    std::thread t2(sub,N,std::ref(target));
    std::thread t3(sub,N,std::ref(target));
    t2.join();
    t3.join();
    std::cout<<target<<std::endl;
    return 0;
}
