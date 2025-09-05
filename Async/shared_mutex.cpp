#include<iostream>
#include<vector>
#include<thread>
#include<mutex>
#include<shared_mutex>
#include<ctime>
class demo{
    public:
    void read()
    {
        mtx.lock();
        //std::shared_lock<std::shared_mutex> lock(smtx);  // 共享锁 读
        printf_s("I am Read thread:count=");
        printf("%d\n",count);
        mtx.unlock();
    }
    void write()
    {
        mtx.lock();
        //std::unique_lock<std::shared_mutex> lock(smtx);  // 独占锁 用于写进程独写
        printf_s("I am Write thread:count++\n");
        count++;
        mtx.unlock();
    }
    private:
    int count=0;
    std::mutex mtx;//使用普通的锁也能完成任务 只是全部都是串行执行 效率相较于shared_mutex低
    //std::shared_mutex smtx;//读进程共享，写进程独占
};

int main()
{
    demo d;
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<std::thread>R_thread;
    auto read = [&](){return d.read();};
    auto write = [&](){return d.write();};
    for(int i=0;i<4;i++)
    {
        // R_thread.emplace_back(d.read()); 报错 因为在此处d.read()会直接执行，相当于穿的并不是一个函数
        // R_thread.emplace_back(demo::read,&d);这样也可以
        R_thread.emplace_back(read);//推荐直接配合lambda表达式一起使用
    }
    std::thread W_thread(write);
    std::thread W_thread1(write);
    for(int i=0;i<4;i++) R_thread[i].join();//.join()函数只是阻塞main进程 各线程抢占cpu资源与join()函数先后顺序无关
    W_thread.join();
    W_thread1.join();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "耗时: " << duration.count() << " 毫秒" << std::endl;
    return 0;
}