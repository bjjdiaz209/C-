#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;










int main(int argc, char const *argv[])
{
    int p =25;
    int q = 40;

    int &rp =p;

    rp=q;

    rp++;

    cout<<p<<"\n";

    cout<<q<<"\n";
    return 0;

    auto rq= q;
    auto rs = rp;
    auto& rr = rq;
    auto& ss = rp;
}
