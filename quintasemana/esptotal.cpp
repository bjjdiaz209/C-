//cpprefrence.com
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

};






int main(int argc, char const *argv[])
{
    /*
    Container<int>p{5};
    Container<int>q{18};
    cout<<p.get()+q.get()<<"\n";
    Container<string>s{"hello"};
    cout<<s.get()<<"\n";

  //wb escritura binaria
  //wt escriturta de texto
  //rb lectura de texto
   /* Container<FILE*>f{fopen("a.txt","w")};

    fputs("hello",f.get());
    fclose(f.get());*/
    
  /*
    Container<FILE*>f{"b.txt","w"};
    f.puts("hello friday");
    */


    Container<Z*>y{new Z()};
    y.get().salute();

}
