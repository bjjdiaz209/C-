//son strcusts con todo privado
//destructor 
//RAII adquision de recursos//crear un objeto adquiere recursos de memoria
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;


class Curso
{
    char nombre[16];
    size_t alumnos;
public:

Curso(const char* n , size_t al)//construuctor
{
    strcpy(nombre,n);//cpoia el valor del objeto creado
    alumnos=al;
}
void mostrar()const//const metodo constate que no va modificar los atributos de la clase
{
    cout<<nombre<<"\n"<<alumnos<<"\n";
}
~Curso()//general es publico
{
  cout<<"Bye"<<"\n";   
}
   
};


int main(int argc, char const *argv[])
{
    Curso c{"dev27",18};
    c.mostrar();//vive en elstack se liberea automaticamrnte

    Curso* d = new Curso("dev27h",18);//head
    d->mostrar();
    delete d;//llam al destrucructor de l obejto y libera la memoria
    
    
}

