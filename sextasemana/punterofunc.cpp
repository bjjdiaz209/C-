//variables que alamcenan una direccion de memoria
//enlugar de apuntar un dato apunta una funcion
//la sintaxis de los punteros a funciones especifican la    de una funcion apuntada


#include <iostream>

using namespace std;

int sum(int a,int b)
{
    return a+b;
}

int sub(int a,int b)
{
    return a-b;
}


int main(int argc, char const *argv[])
{
    int (*q)(int, int);
    q =sum;

    cout<<q(18,17)<<"\n";
    q = sub;

    cout<<q(25,4)<<"\n";

    return 0;
}
