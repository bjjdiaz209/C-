#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;



int main(int argc, char const *argv[])
{
    cout<<"hola\n";

    ofstream f{"archivo.txt"};

    if(!f.good())
    {
        cerr<<"error\n";
        return -4;
    }

    vector<string> ss= {"omar","boris","pato"};

    
    for(auto& s : ss)
    {
        f<<s<<"\n";
    }
    
    return 0;
}
