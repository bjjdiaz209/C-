//elementos estan almacenados como pares ,clave ,valor
//se recuperan apartir de las claves
//no hay clves repetidas
//map arbol binario de busqueda
#include <map>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;


int main(int argc, char const *argv[])
{
    map<string,int>dpm;
    dpm.insert(pair<string,int>{"enero",31});
    dpm.insert(make_pair("febrero",27));

    dpm["marzo"]=31;
    dpm["abril"]=30;
    dpm["mayo"]=31;
    

    
    
    for(auto& e : dpm)
    {
        cout<<e.first<<" ;"<<e.second<<"\n";

        dpm["febrero"]=28;
        auto it = dpm.find("abril");
        if(it==dpm.end())
        cerr<<"Not found\n";
        
        else

        cout<<it->second<<"\n";
    }
    
    return 0;
}




