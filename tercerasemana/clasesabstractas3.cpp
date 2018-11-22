#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;



struct A
{
    int a;
    int b;
};

struct B
{
    static n;
};

int main(int argc, char const *argv[])
{
    A x{6,8};
    cout<<x.a+x.b<<"\n";

    B::n = 16;
    return 0;
}

