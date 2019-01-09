#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <tuple>
#include <unordered_set>

using namespace std;





int main(int argc, char const *argv[])
{
    unordered_set<string>ms;
    ms.insert("january");
    ms.insert("febrero");
    ms.insert("marzo");
    ms.insert("abril ");
    ms.insert("mayo");

    ms.erase("abril");

    
    for(auto& e: ms)
    {
        cout<<e<<"\n";
    }

    unordered_set<string>::iterator it = ms.find("abril");

      if(it == ms.end())
    {
    cerr<<"Not found\n";
    }
   else
   {
    cout<<*it<<"\n";
   }
    


    return 0;
}
