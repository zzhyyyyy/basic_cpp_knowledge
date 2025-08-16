#include <iostream>
 
struct S
{
    int n;
    S(int in) {n = in;std::cout<<"copy"<<std::endl;}
    S(S&& other) { n = other.n + 1; }
};

int main()
{
    S v{1};
    std::cout << "v.n = " << v.n << '\n';
    S u = std::move(v);
 
    // Class `S` doesn't satisfy a MoveConstructible requirement
    // The value of `u` is NOT equivalent to the value of `v` before the `u` initialization
    std::cout << "u.n = " << u.n << '\n';
}