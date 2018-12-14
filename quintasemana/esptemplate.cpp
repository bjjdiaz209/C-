#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;



template<typename T>

void sucesor(const T& n)
{
    cout<<(n+1)<<"\n";
}

template<>
void sucesor<string>(const string& s)
{
    cout<<s<<"no tiene sucesor\n";
}




int main(int argc, char const *argv[])
{
    sucesor(12);
    sucesor("hola"s);
    return 0;
}
