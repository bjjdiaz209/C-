//POD:plain old data
//POD: un valor de tipo primitivo
//un array de tipo primitivo
//unstruct de pods
//una clase con atributos PODs

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

template <class T>

class Arraylist
{
    T* items;
    size_t n;
public:
    Arraylist()
    :items{static_cast<T*>(malloc(0))},n{0}
    {}
    ~Arraylist()
    {
        free(items);
    }
    
    Arraylist<T>& add(const T& x)
    {
        items = static_cast<T*>(realloc(items,(n+1)*sizeof(T)));
        items[n++]=x;
        return *this;
    }

    void show()const
    {

        for(size_t i = 0; i < n ; i++)
        {
            cout<<items[i]<<"\n";
        }
        
    }
};

struct PromanInt
{
    int* n;

    PromanInt(int p)
    :n{new int {p}}
    {}
    PromanInt()
    :n{nullptr}
    {}

    ~PromanInt()
    {
        delete n;
    }
};



int main(int argc, char const *argv[])
{
 /*
    Arraylist<string> r;
    r.add("hello my freiends").add("hola").add("mundo").add("happy").show();

    
    Arraylist<int> p;
    p.add(5).add(8).add(15).add(25).add(40).show();


    Arraylist<double> q;
    q.add(3.14).add(45.56).add(5.77).add(54.56).add(40.78).show();
    */


    Arraylist<PromanInt> z;

    
    for(int i = 0; i < 1000; i++)
    {
        z.add(i* 17);
    }
    


    return 0;
}
