#include <iostream>
#include <string>
#include <vector>
using namespace std;

int sum(int a,int b)
{
    return a+b;
}

int inc(int& n)
{
    n++;
    return n;
}

template<typename PROC,typename...ARGS>
auto invoke(PROC p, ARGS&&...args)
{
    return p(forward<ARGS>(args)...);
}



int main(int argc, char const *argv[])
{
    auto r = invoke(sum,4,3);
    cout<<r<<"\n";


    int n=8;
    invoke(inc,n);
    cout<<n<<"\n";
    return 0;
}
