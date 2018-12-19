 //son objetos 
 //cuya sintaxis permite sumarlos
 //como si fueran funciones

#include <iostream>
using namespace std;


struct Sumador
{
    int descuento;
    int operator()(int a, int b)const
    {
         return a+b - descuento;
    }
};




int main(int argc, char const *argv[])
{
    Sumador s {5};
    cout<<s(10,15)<<"\n";
    return 0;
}
