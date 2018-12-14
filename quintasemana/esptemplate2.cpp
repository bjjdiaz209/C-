#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

template<int N>

struct fact
{
    static const int value = N*fact<N-1>::value;
};

template<>

struct fact<1>
{
    static const int value =1;
};


/*
template<int N>
int factorial()
{
    return N*factorial<N-1>();
}
template<>
int factorial<1>()
{
    return 1;
}
*/




int main(int argc, char const *argv[])
{
    //cout<<factorial<5>()<<"\n";
    cout<<fact<6>::value<<"\n";
    return 0;
}
