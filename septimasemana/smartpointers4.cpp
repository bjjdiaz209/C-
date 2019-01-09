//objeto que apunta a un shared_ptr
//si el weak_ptr apunta aun objeto cuyo refcount es 0 no evita que se destruya
#include <iostream>
#include <memory>

using namespace std;

struct Hijo;


struct Padre
{
    shared_ptr<Hijo>hijo;
    ~Padre()
    {
        cout<<"adioishijo\n";
    }
};

struct Hijo
{
    weak_ptr<Padre>padre;
    ~Hijo()
    {
        cout<<"adios padre\n";
    }

    void cocinar()
    {
        cout<<"yo no cocino\n";
    }
};


int main(int argc, char const *argv[])
{
    auto p = make_shared<Padre>();
    auto h = make_shared<Hijo>();


     p->hijo=h;
     h->padre=p;

     //h->padre.lock()->cocinar();


    shared_ptr<string>s;
    weak_ptr<string>ws = s;

    
        s= make_shared<string>("hello");
        ws=s;

        cout<<ws.lock()->c_str()<<"\n";

        s.reset();

        cout<<ws.expired()<<"\n";//objeto a sido borrado ono
    
}




