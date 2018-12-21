#include <iostream>
#include <array>//es un arraya stack contamano definido
#include <list>
using namespace std;



template<typename T, typename PRED>

void erase_items(list<T>& e,PRED p)

{
    for(auto i = e.begin();i != e.end();/*nothin*/)

    
    if (p(*i)) 
        i= e.erase(i);
    
    else
    i++;
    
}

template<typename T>
void print(const T& x)
{
    
    for(auto& i:x)
    {
        cout<<i<<"\n";
    }
    
}


int main(int argc, char const *argv[])
{
    list<string >dias = {
        "martees","miercoles","jueves","viernes","sabado"
    };

    dias.push_back("domingo");
    dias.push_front("lunes");

    print(dias);

    cout<<dias.size()<<"\n";


    erase_items(dias,[](auto& x){
        return x[0]=='m';
    });
    print(dias);


    return 0;
}
