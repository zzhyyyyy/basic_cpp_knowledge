#include<iostream>
using namespace std;
class base{
    //注释下一行 则继承类son1无法访问base类的private
    friend class son1;
    public:
    int a;
    void geta(){cout<<a<<endl;}
    virtual ~base(){cout<<"调用父类析构函数"<<endl;}
    protected:
    int b;
    private:
    int c;
};
class son1:public base{ //这也证明了即使对于源类的隐私变量，
                        //也会被继承，只是需要特定方法才能访问(友元)
    public:
    void setb()
    {
        this-> b= 10;
    }
    void getb()
    {
        cout<<this->b<<endl;
    }
    void setc()
    {
        this-> c= 10;
    }
    void getc()
    {
        cout<<this->c<<endl;
    }
    ~son1(){cout<<"调用子类析构函数"<<endl;}

};
int main()
{
    base A;
    A.a = 10;
    //A.b = 10;//protected及private类外无法访问
    son1 B;//先隐式创建一个父类 再有B继承
    B.a = 10;
    B.base::a= 15;
    B.geta();
    B.setb();
    B.getb();
    return 0;

}
