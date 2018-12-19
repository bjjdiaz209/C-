#include <iostream>
#include <tuple>
using namespace std;


void show(const tuple<string,string, int>&s)
{
    cout<<get<0>(s)<<" "<<get<1>(s)<<" " <<get<2>(s)<<"\n";
}






int main(int argc, char const *argv[])
{
    tuple<string,string,int>p{"ozzy","osborn",1946};

    auto p2 = make_tuple("jim"s,"morrison"s,1942);

    show(p);
    show(p2);
    return 0;
}



