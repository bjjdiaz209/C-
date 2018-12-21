#include <iostream>
#include <array>//es un arraya stack contamano definido
#include <list>
#include <vector>
using namespace std;



struct X
{
    ~X()
    {
        cout<<"bye\n";
    }
};




int main(int argc, char const *argv[])
{
    vector<int> n = {6,7,8,2,1,7,14};
    n.push_back(17);
    n.push_back(2);


    cout<<n[5]<<"\n";
    cout<<n.at(2)<<"\n";

    vector<X> x1 = {X{},X{},X{}};

    vector<X*>x2={new X(),new X(),new X()};

    
    for(auto i : x2)
    {
        delete i;
    }
    
    return 0;
}
