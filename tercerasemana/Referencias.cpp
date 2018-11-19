//son como punteros con restricciones
//tienes sintaxis simplificado
//sirve para hacer paso de parametros por referencia
//restricciones 1.se inicializan al crearse 2. son inmitables las referencias siempre se va referir al mismo elemento
//no aritmetica de referencias,no hay referencias nullas
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

void factorial(int n, int* r)
{
   int s=1;
   
   for(int i = 2; i <= n; i++)
   {
    s*=i;
   }
   *r=s;
   

}

void factorial2(int n , int& r)
{
     r=1;
     
     for(int i = 2; i <= n; i++)
     {
        r*=1;
     }
     
     
}



int main()
{
    int f;
     factorial(6,&f);

     cout<<f<<"\n";

     int g;
     factorial2(5,g);


}