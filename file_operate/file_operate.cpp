#include<iostream>
#include<fstream>//1.包含头文件
using namespace std;
// ofstream 写操作
// ifstream 读操作
// fstream  读写操作

// 打开文件
// ios::in 为读文件打开文件
// ios::out 为写文件打开文件
// ios::ate 初始位置：文件尾
// ios::app 追加方式写文件 append
// ios::trunc 如果文件存在 先删除再创建
// ios::binary 二进制方式打开

int main()
{
    //写文件
    std::fstream osf;//2.创建流对象
    //3.指定打开文件打开方式
    osf.open("file_operate_demo",std::ios::out);
    // 4.写内容
    osf<<"file_write_operate"<<std::endl;
    osf<<"file_read_operate"<<std::endl;
    //5.关闭文件
    osf.close();
    //读文件
    fstream isf;
    isf.open("C:/Users/muzhiyuan/Desktop/c++/file_operate/file_operate.cpp",std::ios::in);
    //对于读文件 要先判断文件是否打开成功
    if(!isf.is_open()) 
    {
        cout<<"打开文件失败"<<endl;
        return 0;
    }
    string s;
    while(isf>>s)
    {   
        cout<<s<<endl;
    }
    isf.close();
    return 0;
}