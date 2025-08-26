#include<iostream>
#include<vector>
#include<thread>
#include<mutex>
#include<semaphore>
#include <syncstream>
#include<chrono>

constexpr int N = 10;
class CarPark{
    public:
    CarPark():sem(N){};
    int Enter()
    {
        std::osyncstream(std::cout)<<std::this_thread::get_id()<<"准备进入停车场"<<std::endl;
        sem.acquire();//取信号量,判断是否能够进入停车场
        std::lock_guard<std::mutex> lock(mtx);
        std::osyncstream(std::cout)<<std::this_thread::get_id()<<"进入停车场"<<std::endl;
        for(int i=0;i<N;i++)
        {
            if(!v[i].size())
            {
                std::stringstream ss;
                ss<<std::this_thread::get_id();
                v[i]=ss.str();
                std::osyncstream(std::cout)<<std::this_thread::get_id()<<"找到了第"<<i<<"个位置"<<std::endl;
                return i;
            }
        }
        throw(std::runtime_error("程序执行异常!"));
    }
    void TimeWaste()
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    void exit(int index)
    {
        std::osyncstream(std::cout)<<std::this_thread::get_id()<<"离开停车场"<<std::endl;
        {
            std::unique_lock<std::mutex> lock(mtx);
            v[index]="";
        }
        sem.release();
    }
    void WorkStream()
    {
        int Carid = Enter();
        TimeWaste();
        exit(Carid);
        return ;
    }
    private:
    std::vector<std::string>v = std::vector<std::string>(N, "");
    std::counting_semaphore<N> sem;
    std::mutex mtx;
};

int main()
{
    std::vector<std::thread>v;
    CarPark a;
    for(int i=0;i<5;i++)
    {
        //v.emplace_back([&](){a.WorkStream();});
        v.emplace_back(CarPark::WorkStream,&a);
    }
    for(auto &i:v) i.join();
    return 0;
}

