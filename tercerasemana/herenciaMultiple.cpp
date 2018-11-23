//clases pueden basarse en mas de una clase
//ifstram para ller archivos
//ninguna clse es mas importante que otra
//no tiene limmite en el numero de clases
//pedasos de implementaciones
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;


class Animal
{
private:
    /* data */
public:
   void comer()
   {
       cout<<"como\n";
   }
    
};

class vehiculo
{

public:
   void acelerar()
   {
       cout<<"mas rapido\n";
   }
    
};

class volador
{

public:
   void volar()
   {
       cout<<"vuelo\n";
   }
    
};


class Murcielago:public Animal,public volador
{
    public:
    void chuparsangre()
    {
        cout<<"yummi\n";
    }
    
};
class Avion:public volador , public vehiculo
{

};





int main(int argc, char const *argv[])
{
    Avion a;
    a.volar();



    Murcielago m;
    m.volar();
    m.comer();
    m.chuparsangre();

    return 0;
}
