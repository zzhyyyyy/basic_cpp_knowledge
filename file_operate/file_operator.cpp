#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    fstream f;
    f.open("test_demo",ios::out);
    struct w
    {
        string name,age,male;
    };
    w a[10];
    a[0].name = "zzh";
    a[0].age = "17";
    a[0].male = "男";
    for(int i=0;i<1;i++)
    {
        f<<a[i].name<<" "<<a[i].age<<" "<<a[i].male<<endl;
    }
    f.close();
    f.open("test_demo",ios::in);
    if(!f.is_open()) 
    {
        cout<<"文件打开错误"<<endl;
        return -1;
    }
    string temp;
    while(f>>temp)
    {
        cout<<temp<<" ";
    }
    return 0;
}
