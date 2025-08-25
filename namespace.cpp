#include<iostream>

namespace N//命名空间
{
	int a = 10;
	int b = 20;
	int Add(int &left, int &right)
	{
		return left + right;
	}
	int Sub(int &left, int &right)
	{
		return left - right;
	}
}
int main()
{
	printf("%d\n", N::a); // 该语句编译出错，无法识别a
    std::cout<<N::Add(N::a,N::b);
    std::cout<<N::Sub(N::a,N::b);
	return 0;
}
