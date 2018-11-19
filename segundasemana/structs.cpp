//struct tipo de dato complejo
//puede ner varios campos cada campo tiene su nombre
//pueden de diferentes tipos 
//clases son  como recetas para crear objetos 
//las clases pueden tener varios atributos adentro
//cada atributo tiene su nombre
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

struct Persona
{
    char nombre[32];
    char apellido[32];

    size_t ci;
};


 void init(Persona* p, const char* n, const char* a, size_t ci)
 {
     /*strcpy((*p).nombre,n);
     strcpy((*p).apellido,a);
     (*p).ci=ci;*/
     
     strcpy(p->nombre,n);
     strcpy(p->apellido,a);
     p->ci=ci;
 }

 void print(const  Persona* p)
 {
     cout<<p->nombre<<"\n";
     cout<<p->apellido<<"\n";
     cout<<p->ci<<"\n";
    
 }



int main()
{
    Persona p ;

    init(&p,"juan","rios",123456);

    print(&p);

    Persona* h = new Persona();
    init( h,"jose" ,"maria", 122324);
    print( h);

    delete h;
}