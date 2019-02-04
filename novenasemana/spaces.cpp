#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include<iomanip>

using namespace std;

template <size_t N>


ostream& stars(ostream& os)
{
    
    for(int i = 0; i < N; i++)
    {
        return os;
    }
    
}

int main(int argc, char const *argv[])
{
    cout<<stars<5><<"hola"<<"\n";

    cout<<dashes(5)<<"mundo"<<"\n";

    return 0;
}
