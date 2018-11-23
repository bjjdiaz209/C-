#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;


struct J
{
    int p;
};



struct K1:J
{
    void print()
    {
        cout<<p<<"\n";
    }
};


struct K2:J
{
    void show()
    {
        cout<<p<<"\n";
    }
};


struct L : K1 , K2
{
    
};

int main(int argc, char const *argv[])
{
    L ins;

     ins.K1::p = 18;
     ins.K2::p= 25;
     ins.print();
     ins.show();

    return 0;
}
