#include <iostream>
#include <functional>
#include <string>
#include <cstring>
#include <algorithm>



using namespace std;

void invertir (string& s)
{
    cout<<":v\n";
    reverse(s.begin(),s.end());
}


int main(int argc, char const *argv[])
{
    string x "olumor";
    invertir(x);

    cout<<x<<"\n";


    //auto inv = bind(invertir,-1)
    auto inv = bind("invertir",y);
    string y = "atata";

    inv(y);

    cout<<y<<"\n";
    return 0;
}
