#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;


template<class A , class B , class C>

struct X
{
    A a;
    B b;
    C c;

    void print()const
    {
        cout<<a<<"\n";
        cout<<b<<"\n";
        cout<<c<<"\n";

    }
};
template<class P>

struct X<int ,int , P>
{
    int a;
    int b;
     P c;

    void print()const
    {
        cout<<a+b<<"\n";
        cout<<c<<"\n";
    }
};

template<>  

struct X<string,string,string>
{
    string a,b,c;

void show()const
{
    cout<<a<<" "<<b<<" "<<c<<"\n";
}
};


int main(int argc, char const *argv[])
{
    X<int, string ,double>x{10,"hola",3.15};
    x.print();

    X<int,int ,string>y{12,13,"viernes"};
    y.print();
    
    X<int, int ,int>z{10,34,6};
    x.print();
   
    return 0;
}
