#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <tuple>
using namespace std;

struct mypair
{
    int x;
    int y;

};

ostream& operator<<(ostream& os,const mypair& e)
{
    os<<"("<<e.x<<","<<e.y<<")";
    return os;
}


struct my_pair_comparetor
{
    bool operator()(const mypair& a, const mypair& b)const
    {
        return tie(a.x,a.y)<tie(b.x,b.y);
    }
};

bool c2(const mypair& a,const mypair& b)
{
    return tie(a.y,a.x)<tie(b.y,b.x);
}



int main(int argc, char const *argv[])
{
    using ctype = bool(*)(const mypair& a, const mypair& b);
    set<mypair,ctype>mps{c2};
    
    //set<mypair,decltype(c2)>mps;

    //set<mypair,my_pair_comparetor>mps;
    mps.insert(mypair{6,5});
    mps.insert(mypair{8,2});
    mps.insert(mypair{4,9});
    mps.insert(mypair{6,6});

    for(auto& e : mps)
    {
        cout<<e<<"\n";
    }
}