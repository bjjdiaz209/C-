#include <iostream>
#include <string>

using namespace std;



void es_par(const char** x,int a)
{
    if(a/2==0)
    {
         *x ="par";

    }
    else{
        *x= "impar";
    }
}



int main()
{
    const char* s = nullptr;
    //int* r = nullptr;//propio de c++, puntros sin inicializar
    es_par(&s,63);
    cout<<s<<"\n";//impar

}