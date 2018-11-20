//cuando dosinstacias de la misa clse  base reaccionan de manera diferente ante un mismo mensaje
//se implementa con "sobreescritura"

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

    virtual void print()const
    {
        cout<<"max speed:"<<max_speed<<"\n";
    }
    virtual ~Vehiculo(){}
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

        void print() const override
        {
            Vehiculo::print();
             cout<<"max height:"<<max_height<<"\n";

        }
};


 int main()
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
      
      delete z1;
      delete z2;
      delete z3;



    return 0;
 }