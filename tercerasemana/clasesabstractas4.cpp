#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;



void p()
{
    static int n = 5;
    cout<<n++<<"\n";
}





int main(int argc, char const *argv[])
{
    p();
    p();
    p();
    p();
    p();

    return 0;
}
