//camabian la salida
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include<iomanip>

using namespace std;



int main(int argc, char const *argv[])
{
    bool x = true;
    cout<<boolalpha<<x<<"\n";

    
    for(int i = 1; i < 100000; i*=10)
    {
        cout<<setw(10)<<i<<"\n";
    }

    double p = 214'868'542'214.25;

    cout<<p<<"\n";

    cout<<fixed<<p<<"\n";
    cout<<scientific<<p<<defaultfloat;

    cout<< setprecision(15)<<p<<"\n";

    cout<<0xCAFEBABABE<<"\n";
    cout<<hex<<0xCAFEBABE<<"\n";

    int d = 0xCAFEBABE;

    cout<<uppercase<<d<<"\n";
    cout<<dec<<d<<"\n";

    cout<<oct<<d<<dec<<"\n";

    cout<<false<<"\n";
    
    cout<<noboolalpha<<false<<"\n";
    
    
    return 0;
}
