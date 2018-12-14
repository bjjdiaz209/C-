#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;


template<typename T>

class Container
{
    T value;
    public:
    Container(const T& x):value{x}
    {

    }
    const T& get()const
    {
        return value;
    }
};

template<>

class Container<FILE*>
{
  FILE* f;
public:
    Container(const char* fn,const char* om)
    :f{fopen(fn,om)}
    {

    }
    void puts(const char* s)
    {
        fputs(s,f);
    }
    ~Container()
    {
        fclose(f);
    }
};


struct Z
{
    ~Z()
    {
        cout<<"bye Z\n";

    }
    void salute()const{
        cout<<"hoy es viernes\n";
    }
};

template<typename T>
class Container<T*>
{
    T* p;

    public:
    Container(T* p):p{p}
    {

    }

    const T& get()const
    {
        return *p;
    }

    ~Container()
    {
        cout<<"byeconatiner\n";
        delete p;
    }

    const T* operator->()const
    {
        return p;
    }

};




int main(int argc, char const *argv[])
{
    Container<Z*>y{new Z()};
    //y.get().salute();
    y->salute();

    return 0;
}
