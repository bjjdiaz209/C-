//en los containers ,arraylist,linked list,quees

#include <iostream>
#include <array>//es un arraya stack contamano definido
#include <list>
using namespace std;


template<typename T>
void print(const T& x)
{
    
    for(auto& i:x)
    {
        cout<<i<<"\n";
    }
    
}
int main(int argc, char const *argv[])
{

    array<int,6>x;
    x[0]=8;
    x[1]=2;
    x[2]=3;
    x[3]=4;
    x[4]=5;
    x[5]=6;


print(x);
    return 0;
}
