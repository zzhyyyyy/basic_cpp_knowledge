// 条款02
// #include<iostream>
// using namespace std;
// class base{
//     public:
//     void set(int x){a=x;}
//     void adda(){a++;}
//     void geta(){cout<<"a:"<<a<<endl;}
//     private:
//     int a=0;
// };

// int main()
// {
//     base a;
//     a.geta();
//     a.set(3);
//     a.geta();
//     a.adda();
//     a.geta();
//     return 0;
// }


// #条款03
// #include<iostream>
// #include<vector>
// using namespace std;
// int main()
// {
//     vector<int>v{1,2,3,4};
//     vector<int>::iterator const iter=v.begin();//int * const
//     //++iter;报错 使用const修饰 当前iter为常量 不可自增改变
//     *iter=10;//可以 改变iter指向的值
//     vector<int>::const_iterator it = v.begin();//const int * 相当于可以改变it的指向，不允许改变it指向地址所对应的值
//     ++it;//正确
//     //*it=10;报错
//     //-------------------------------------
//     const int a = 3;
//     //int* p =&a;//报错 const int*类型的值不能初始化int *
// }


// #条款04
#include <iostream>
#include <chrono> // 包含计时库

using namespace std;
using namespace std::chrono; // 使用chrono命名空间

class A{
    public:
    string a, b, c;
    A(string a, string b, string c) : a(a), b(b), c(c) {};
};

class B{
    public:
    string a, b, c;
    B(string a, string b, string c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

int main()
{
    // 测试 A 的耗时
    auto start_A = high_resolution_clock::now(); // 开始计时点A
    for (int i = 0; i < 1000000; i++) { // 增加循环次数以便测量
        A obj("leetcode", "acwing", "codeforce");
        // 防止循环被优化掉
        asm volatile("" : : "r,m"(obj) : "memory");
    }
    auto end_A = high_resolution_clock::now(); // 结束计时点A

    // 测试 B 的耗时
    auto start_B = high_resolution_clock::now(); // 开始计时点B
    for (int i = 0; i < 1000000; i++) {
        B obj("leetcode", "acwing", "codeforce");
        // 防止循环被优化掉
        asm volatile("" : : "r,m"(obj) : "memory");
    }
    auto end_B = high_resolution_clock::now(); // 结束计时点B

    // 计算耗时（转换为微秒 microseconds）
    auto duration_A = duration_cast<microseconds>(end_A - start_A).count();
    auto duration_B = duration_cast<microseconds>(end_B - start_B).count();

    // 输出结果
    cout << "Time taken by A (initialization list): " << duration_A << " microseconds" << endl;
    cout << "Time taken by B (assignment in body):  " << duration_B << " microseconds" << endl;

    double ratio = static_cast<double>(duration_B) / duration_A;
    cout << "B took " << ratio << " times longer than A." << endl;

    return 0;
}
