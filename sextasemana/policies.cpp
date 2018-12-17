//comoortamiento que se inyecta a una clase template
//se especifican al momento de instanciar una clase template
//se pasa atravez de un tipo parametrizado

#include <iostream>

using namespace std;



template<typename H>

struct Animal
{
    H h;

    void habla()const
    {
        h.habla();
    }
};



struct PerroPolicy
{
    void habla()const
    {
        cout<<"ggua\n";
    }
};




struct VacaPolicy
{
    void habla()const
    {
        cout<<"muuuu\n";
    }
};

using Perro = Animal<PerroPolicy>;

using Vaca = Animal<VacaPolicy>;

template<typename P>
void hablar(const Animal<P>& p)
{
     p.habla();
}


int main(int argc, char const *argv[])
{
    Perro p;
    Vaca w;

    hablar(p);
    hablar(w);
    return 0;
}


