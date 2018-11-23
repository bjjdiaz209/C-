#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;



struct A
{
    int a;
};


struct B
{
int b;
};


struct c : A,B
{
    int c;
};

struct f : A,B
{

};

int main(int argc, char const *argv[])
{
    A a;

    return 0;
}



