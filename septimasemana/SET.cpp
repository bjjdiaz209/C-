//set arbol binario de busqueda balanceado
//unorden_set tablas hasg

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


struct my_pair_comparetor
{
    bool operator()(const mypair& a, const mypair& b)const
    {
        return tie(a.x,a.y)<tie(b.x,b.y);
    }
};



int main(int argc, char const *argv[])
{
    set<mypair,my_pair_comparetor>mps;
    mps.insert(mypair{6,5});
    mps.insert(mypair{8,2});
    mps.insert(mypair{4,9});
    mps.insert(mypair{6,6});

    
    /*for(auto& e : mps)
    {
        cout<<e<<"\n";
    }*/
    

    set<string>s;
    s.insert("java");
    s.insert("c++");
    s.insert("rust");
    s.insert("swift");
    s.insert("python");
    s.insert("c#");


 
 for(auto i = s.begin();i!=s.end(); ++i)
 {
     cout<<*i<<"\n";
       
       s.erase("swift");
     
     for(auto& x : s)
     {
         cout<<x<<"\n";
     }
     
 }
 auto it=s.find("python");
      if(it != s.end())
      {
          cout<<"FOUnD and killed\n"<<*it<<"\n";
          s.erase(it);

      }
      else
      cerr<<"NOt found\n";
 
    return 0;
}
