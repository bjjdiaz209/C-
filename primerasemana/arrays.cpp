//arrays es un comnjunto de elementos del mismo tipos
//en C los arrays tienen tamano fijo
//los elementos se aceden pon un indice
//array esta en el stack
//no hay informacion de tamo
//


#include <iostream>
#include <string>

using namespace std;





int main()

{
    int q[5];//valores de tamano fijo limitado
    q[0]=10;
    q[1]=5;
    q[2]=8;
    q[3]=4;
    q[4]=9;

     
     for(int n: q)
     {
         cout<<n<<"\n";
     }

     int* r = q;

     
     for(int i = 0; i < 5; i++)
     {
         cout<<r[i]<<"\n";
     
     
     }

     q[5]=29;
         cout<<q[5]<<"\n";


         
         for(int i = 0; i < 1000000; i++)
         {
                  cout<<q[i]<<"\n";
             
         }
         
}

