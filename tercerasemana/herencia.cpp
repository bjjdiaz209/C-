///crear clases apartir de otras
//en c++ pueden heredar de 1 o mas clases
//es una base de la reutilizacion
//es una piedra fundamental del polimoorfismo
// em c++ no hay una jerarquia de clases predefinidas
//en  c++ la herencia pude ser public,protected private
//
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class Vehiculo
{
    size_t max_speed;
public:
    Vehiculo(size_t ms)
    :max_speed{ms}
    {}

    void print()const
    {
        cout<<"max speed:"<<max_speed<<"\n";
    }
};
 void show(const Vehiculo& a)
 {
     a.print();
 }

class Airplane: public Vehiculo
{
    size_t max_height;
    public:
        Airplane(size_t ms, size_t mh)
        :Vehiculo{ms},
        max_height{mh}
        {

        }

        void print()const
        {
             cout<<"max height:"<<max_height<<"\n";

        }
};



int main(int argc, char const *argv[])
{
    Vehiculo x {150};
    Airplane y {500, 3000};
    /*x.print();
    cout<<"****\n";
    y.print();*/
    show(x);
    show(y);

    Vehiculo* z1 = new Vehiculo {25};
    z1->print();

    Airplane* z2 = new Airplane {10,100};
    z2->print();

    Vehiculo* z3 = new Airplane{80,20};
    z3->print(); 


    return 0;
}




