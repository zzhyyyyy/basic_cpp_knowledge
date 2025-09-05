#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <atomic>

std::mutex mtx;
std::condition_variable cv;
std::queue<int> data_queue;
const int MAX_SIZE = 10;
constexpr int N = 20;
std::atomic<int> cnt = 0;
// 生产者
void producer() {
    for (int i = 0; i < N; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        
        // 等待队列不满
        cv.wait(lock, []{ return data_queue.size() < MAX_SIZE; });  //while(!(data_queue.size() < MAX_SIZE)) cv.wait(lock)
        data_queue.push(i);
        std::cout << "生产: " << i << std::endl;
        
        lock.unlock();
        cv.notify_all();  // 通知消费者
    }
}

// 消费者
void consumer(int id) {
    while (true) {
        if(cnt.load() == N)return ;
        std::unique_lock<std::mutex> lock(mtx);
        
        // 等待队列不空
        cv.wait(lock, []{ return !data_queue.empty(); });//相当于 while(!(!data_queue.empty())) cv.wait(lock);
        
        int data = data_queue.front();
        data_queue.pop();
        std::cout << "消费者" << id << " 消费: " << data << std::endl;
        cnt.fetch_add(1);
        std::cout<<"cnt:"<<cnt.load()<<std::endl;
        lock.unlock();
        cv.notify_all();  // 通知生产者
    }
}

int main() {
    std::thread prod(producer);
    std::thread cons1(consumer, 1);
    std::thread cons2(consumer, 2);
    
    prod.join();
    cons1.join();
    cons2.join();
    
    return 0;
}