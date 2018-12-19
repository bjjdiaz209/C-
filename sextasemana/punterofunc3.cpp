#include <iostream>
#include <cstdlib>
#include <cstring>
typedef void(*ProgressFptr)(int,int);
using namespace std;

void f(ProgressFptr pp)

//void f(void(*pp)(int pos, int cant))
{
    
    for(int i = 0; i < 2'000'000'000; i++)
    {
        
        if (i/20'000'000'000==0) {
            pp(i,2'000'000'000);
        }
        
    }
    
}

void print_progres(int p, int c)
{
    cout<<p<<"de"<<c<<"elemntos\n";
}

int main(int argc, char const *argv[])
{
    f(print_progres);
    return 0;
}
