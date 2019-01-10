#include <map>
#include <iostream>
#include <string>
#include <cstring>
#include <unordered_map>

using namespace std;


struct id
{
    int n;
    string c;
};

bool operator<(const id& a,const id& b)
{
    return tie(a.n,a.c)<tie(b.n,b.c);
}


int main(int argc, char const *argv[])
{
    map<id,string> pp;

    pp.insert(make_pair(id{6854217,"CB"},"mauricio slazar"));
    pp[id{421894,"PT"}]="omar vera";
    pp[id{421894,"CH"}]="pamela alvarez";

    
    for(auto& e : pp)
    {
        cout<<e.first.n<<" "<<e.first.c<<" "<<e.second<<"\n";
    }
    
    auto i2 = pp.find(id{6854217,"CB"});

    if(i2==pp.end())

    cerr<<"NOt found\n";
    else
    cout<<i2->second<<"\n";

}
