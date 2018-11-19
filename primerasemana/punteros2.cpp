#include <iostream>
#include <string>
//en C paso de parametros siempre por valor
//para modificar parametros de salida
//String en C 

using namespace std;

/*void q()
{
    int m=25;
    int* pm=&m;
    cout<<pm<<"\n";

    cout<<*pm<<"\n";

    *pm=450;

    cout<<m<<"\n";
}
*/

void sum(int a, int b , int* c)
{
    *c=a+b;
}

 



 int main()
 {
    int a=5, b=8;
    int r;

    sum(a,b,&r);

    cout<<r<<"\n";
     //q();

 }