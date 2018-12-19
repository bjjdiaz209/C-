//soportan cantidad de parametros
#include <iostream>

using namespace std;


template<typename T, typename U>
auto sum(const T& a, const U& b) //T
{
    return a+b;
}


template<typename T , typename... PARAMS>//paramater packs
auto sum(const T& n, const PARAMS&... args )
{
    return n+sum(args...);//pack expansion
}


int main(int argc, char const *argv[])
{
    
    cout<<sum(2,8)<<"\n";
    
    cout<<sum(6,9,14)<<"\n";

    cout<<sum(3,8,15,4,2,1)<<"\n";//n ,args
          

    return 0;
}
