// ### 线程Thread的引入
// #include<thread>
// #include<iostream>
// #include<vector>

// void func()
// {
//     std::cout<<std::this_thread::get_id()<<std::endl;//非线程安全
//     //printf("%d\n",std::this_thread::get_id());//线程安全
// }
// int main()
// {
//     // thread my_thread(func);
//     // if(my_thread.joinable()) my_thread.join();
//     std::vector<std::thread>v;
//     //v.resize(10);
//     for(int i=0;i<10;i++)
//     {
//         //v[i]=std::thread(func);
//         std::thread t1([]()->void{
//             std::cout<<std::this_thread::get_id()<<std::endl;
//         });
//         v.emplace_back(std::move(t1));
//     }
//     for(auto &i:v)
//     {
//         i.join();
//     }
//     return 0;
// }


// ----------------------------------------------------------------
// ###线程对象的 detach函数和join函数的使用
// #include <iostream>
// #include <thread>

// void threadproc() {
//     while(true) {
//         std::cout << "I am New Thread!" << std::endl;
//     }
// }

// void func() {
//     std::thread t(threadproc);//报错 因为func()调用完了之后 线程t就被销毁了 但是此时线程函数还在执行
//     //加上detach函数 分离线程t和它自身的函数->这样即使线程对象被销毁，也不影响线程函数的运行。
//     //t.detach();
//     t.join(); // 使用t.join()函数也可以 join函数的作用是阻塞当前进程 以等待进程中的子进程能够顺利完成
// }

// int main() {
//     func();
//     while(true) {} //让主线程不要退出
//     return 0;
// }

// ----------------------------------------------------------------
// ### future关键字的使用
// #include <iostream>
// #include <future>

// int add(int a, int b) {
//  return a + b;
// }
// int main() {
//  // 使用 std::async 启动线程并返回 std::future
//  std::future<int> result = std::async(std::launch::async, add, 5, 3);
//  // 获取线程结果
//  std::cout << "Result: " << result.get() << std::endl;
//  return 0;
// }

//### mutex

#include<iostream>
#include<thread>
#include<mutex>
std::mutex mtx;
void func(char _,int cnt)
{
    //mtx.try_lock();//或者直接使用智能锁进行管理 lock_gurad<>
    std::lock_guard<std::mutex>lock(mtx);
    for(int i=0;i<cnt;i++) 
    std::cout<<_<<" ";
    //mtx.unlock(); //使用智能锁之后就不需要手动管理释放了
    return ;
}
int main()
{
    std::thread t1(func,'a',10);
    std::thread t2(func,'b',10);
    t1.join();
    t2.join();
    return 0;
}