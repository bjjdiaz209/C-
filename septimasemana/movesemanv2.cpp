#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Fatty
{
    char* p;
    public:
    Fatty(char k)
    {
        p = new char[1000000];
       
        for(int i = 0; i < 1'000'000; i++)
        {
            p[i]=k;
        }
       
    }
    ~Fatty()
    {
        delete[] p;
    }

    Fatty(const Fatty& src)
    {
        p= new char[1'000'000];
       
        for(int i = 0; i < 1'000'000; i++)
        {
            p[i]= src.p[i];
        }
       
    }
    Fatty& operator= (const Fatty& src)
    {
        delete[] p;
        p = new char[1'000'000];
        for(int i = 0; i < 1'000'000; i++)
        {
            p[i]= src.p[i];
        }
        return *this;
    }

    Fatty(Fatty&& src)
    :p{src.p}
    {
        src.p = nullptr;
    }

    //operador igual de movida
    Fatty& operator= (Fatty&& src)
    {
        delete[] p;
        p = src.p;
        src.p = nullptr;
        return *this;
    }
};

template <typename T>
void swp(T& a, T& b)
{
    //aqui debe ser move(movida)
    T aux = move(a);
    a=move(b);
    b=move(aux);
}
int main()
{
    Fatty a{'x'};
    Fatty b{'y'};
    auto z0 = clock();

    for (int i = 0; i<10'001;i++)
    {
        swp(a,b);
    }
    auto z1 = clock();

    cout<<(z1-z0)<<"\n";
    //84'186'814
    //84'851'713
    //con semantica de movidas en el template (move)
    //215
}