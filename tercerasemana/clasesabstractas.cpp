//es una clse que tiene uno omas metodos abastractyos
//obliga a implementar los metodos abstractos en clases hijas
//una clse que no se puede instanciar para instaciarse los metdos abstractos deben implementarse
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;



class Animal
{
public:
 virtual  void comunicarse()const =0;//metodso virtual puro,un metodo implementado que de implementarse en una clase
 virtual ~Animal(){}   
};
 class vaca : public Animal
 {
 public:
     void comunicarse() const override
     {
         cout<<"MUUU\n";
     }
 };

class perro : public Animal
 {
 public:
     void comunicarse() const override
     {
         cout<<"Guau\n";
     }
 };

 



int main(int argc, char const *argv[])
{
    Animal* e = new vaca();
    e->comunicarse();
    delete e;

    e = new perro();
    e->comunicarse();

    delete e;
    return 0;
}


