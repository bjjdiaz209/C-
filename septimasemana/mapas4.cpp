#include <map>
#include <iostream>
#include <string>
#include <cstring>
#include <unordered_map>

using namespace std;

struct key
{
    int id1;
    int id2;
};


struct key_hash
{
    size_t operator()(const key& e)const
    {
        return e.id1*31+e.id2;
    }
};


struct  key_eq
{
    bool operator()(const key& a,const key& b)const
   {
    return a.id1== b.id2&&a.id2==b.id2;
   }
};





int main(int argc, char const *argv[])
{
    unordered_map<key,string,key_hash,key_eq>s;
    s[key{10,15}]="veinticinco";
    s[key{2,8}]="diez";
    s[key{4,7}]="once";
    s[key{18,2}]="veinte";

    
    for(auto& e : s)
    {
        cout<<e.first.id1<<" "<<e.first.id2<<" "<<e.second<<"\n";
    }

    auto it = s.find(key{2,8});

    if(it!=s.end())
    cout<<it->second<<"\n";

    
    

}
