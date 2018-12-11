//sirven para evitar name custlers
//agrupacion logica identificadores(simbolos)
#include <iostream>
using std :: cout;



namespace funcs
{

    void f()
    {
        cout<<"hello\n";
    }


void g()
{
    cout<<"2018\n";
}
}
void g()
{
    cout<<"bye\n";
}


using namespace funcs;
int main(int argc, char const *argv[])
{
    funcs::f();
    funcs::g();
        ::g();
    return 0;
}
