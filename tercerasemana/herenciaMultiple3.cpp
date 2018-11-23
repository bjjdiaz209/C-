#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;





struct M
{
    void cantar()
    {
        cout<<"lallala\n";
    }
};


struct N
{

    void cantar()
    {
        cout<<"una piedra\n";
    }
};


struct  O : M,N
{
    void cantar()//hidden
    {
        cout<<"loa pollitos\n";
    }
};

struct P:M,N
{
    
};



struct J
{
    int p;
};



struct K1:J
{
    void print()
    {
        cout<<p<<"\n";
    }
};


struct K2:J
{
    void show()
    {
        cout<<p<<"\n";
    }
};


struct L : K1 , K2
{
    
};



int main()
{
    M m ; N n; O o;

    m.cantar();
    n.cantar();
    o.cantar();

     


    P p;
    p.M::cantar();

    p.N::cantar();


    L ins;

     ins.K1::p = 18;
     ins.print();
     ins.show();





}