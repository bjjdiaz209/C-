//es una clse que puede ser accesible , para tener permiso de informacion
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class Singleton
{
    static Singleton* p;//unico bojetod ela clase  

    Singleton()
    {
        cout<<"creating instance";
    }

    public:
       void hi()const {cout<<"hello\n";}
       static Singleton* instance()
       {
           
           if (p==nullptr) {
               p = new Singleton();

           }
           return p;
           
       }
};
Singleton* Singleton::p=nullptr;




int main(int argc, char const *argv[])
{
    Singleton::instance()->hi();//instancia unica para todo el prgrama
    Singleton::instance()->hi();

    return 0;
}
