#include <iostream>
#include <map>
#include <memory>
#include <variant> //c++17
using namespace std;

struct automovil
{
    void mover()
    {
        cout<<"girar ruedas\n";
    }

};
struct avion
{
    void mover()
    {
        cout<<"elevar alas\n";
    }
};
struct barco
{
    void mover()
    {
        cout<<"Remar\n";
    }
};
using vehiculo = variant<automovil,avion,barco>;

int main()
{
    map<string, vehiculo> vs;
    vs["1234ABC"]= automovil{};
    vs["6789XYZ"]= avion{};
    vs["1111AAA"]= barco{};

    get<avion>(vs["6789XYZ"]).mover();

    for(auto& e:vs)
    {
        cout<<e.first<<" ";
        visit([](auto& p){
            p.mover();
        },e.second);
    }

}