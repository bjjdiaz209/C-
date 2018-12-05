#include <stdexcept>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
void z();


void y()noexcept(false)
{
    cout<<"hello\n";
    z();
}

void z()
{
    throw 665;
}



int main(int argc, char const *argv[])
{
       
       
       try
       {
           y();
       }
       catch(int n)
       {
           cerr << n<< "\n";
       }
       
}
