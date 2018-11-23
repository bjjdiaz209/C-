#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;


struct BF
{
    int n;
};


struct A: virtual BF
{
    A() : BF {100}{}
};





struct B :virtual BF
{
   B(): BF {888}{}
};


struct C : A,B
{
    C(): BF {456}{}
};



int main(int argc, char const *argv[])
{
    C c;
    cout<<c.n<<"\n";
    return 0;
}





