// programacion generica
//tener tipod de datos y valores parametrizable
//turing complte 
//c++ esta evolucionando por este lado
//pros :reusable:nonpolimorfismo mejor rendimiento//
//mejor rendimiento con tipos abstractos
//cons:mensajes de error terribles:tiempo de compilacion es lento
//no hay separacion .h .cpp 
//los binarios son mas grandes

#include <iostream>
#include <string>

using namespace std;
/*
int sum(int x , int y)
{
    return x +y;
}*/


struct MyInt
{
    int n;

    MyInt operator+(const MyInt& p)const
    {
        return MyInt{n+p.n};
    }
};


template<typename T>
T sum(T a , T b)
{
    return a+b ;
}



int main(int argc, char const *argv[])
{

      //int a= sum(6,8);

      cout<<sum(6,8)<<"\n";
      cout<<sum(3.25,8.59)<<"\n";
      cout<<sum<string>("hello","world")<<"\n";
      cout<<sum(MyInt{8},MyInt{25}).n<<"\n";



    return 0;
}
