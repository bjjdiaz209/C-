#include <iostream>

using namespace std;


struct A {virtual ~A(){}};

struct B:A
{
     void m()
     {
         cout<<"hello\n";
     }
};

void invoke(long long m)
{
    B* b = reinterpret_cast<B*>(m);
    b->m();
}


int main(int argc, char const *argv[])
{ 
    /*int p = (int) 12.45;
    A* a= new B();
    ((B*)a)->m();
    const B* ca = (const B*)a;
    auto nca = (B*)ca;
    nca->m();
*/

    auto p=static_cast<int>(12.45);

    A* a = new B();
    static_cast<B*>(a)->m();




    const B* ca = static_cast<B*>(a);

    const_cast<B*>(ca)->m();

    invoke((long long)ca);
    
}


