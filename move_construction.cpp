#include <iostream>
 
struct S
{
    int n;
    S(int in) {n = in;std::cout<<"copy"<<std::endl;}
    S(S&& other) { n = other.n + 1; std::cout<<"move"<<std::endl;}
};

int main()
{
    S v(1);
    std::cout << "v.n = " << v.n << '\n';
    S u = std::move(v);
    std::cout << "u.n = " << u.n << '\n';
}