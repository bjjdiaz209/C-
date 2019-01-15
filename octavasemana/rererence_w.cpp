#include <iostream>
#include <vector>
#include <string>
#include <functional>
using namespace std;
struct nombre_completo
{
    string nombre;
    string apellido;
};
template<typename T, typename PRED>
auto get_if(const T& c, PRED p)
{
    vector<reference_wrapper<const typename T::value_type>> r;//vector de referencias
    for(auto& e:c)
    {
        if(p(e))
            //r.push_back(ref(e));
            r.push_back(e);
    }
    return r;
}
int main ()
{
    vector<nombre_completo> ns;
    ns.push_back({"Juan","Perez"});
    ns.push_back({"Jorge","Lopez"});
    ns.push_back({"Alvaro","Perez"});
    auto f= get_if(ns,[](auto& n){return n.apellido == "Perez";});
    
    for(auto& e:f)
        cout<<e.get().nombre<<" "<<e.get().apellido<< "\n";
}