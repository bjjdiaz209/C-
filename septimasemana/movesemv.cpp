#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

class Person
{
    char* name;

    public:
    Person(const char* n)
    {
        size_t len = strlen(n);
        name = new char[len+1];
        memcpy(name,n,len+1);
    }
    ~Person()
    {
        delete[] name;
    }
    Person (const Person& p)
    {
        cout<<"COPY CTOR\n";
        auto len = strlen(p.name);
        name = new char [len+1];
        memcpy(name,p.name,len+1);
    }
    Person& operator= (const Person& p)
    {
        cout<<"COPY =\n";
        delete[] name;
        auto len = strlen(p.name);
        name = new char[len+1];
        memcpy(name,p.name,len+1);
        return *this;
    }
    void show() const
    {
        cout<<name<<"\n";
    }

    Person(Person&& src):name{src.name}
    {
        cout<<"MOVE ctor\n";
        src.name = nullptr;
    }
};

class Couple
{
    Person a;
    Person b;

    public:
    Couple(const Person& a, const Person& b)
    :a{a},b{b}
    {
        cout<<"couple ctor\n";
    }
    Couple( Person&& a, Person&& b)
    :a{move(a)},b{move(b)}
    {
        cout<<"1move ctor\n";
    }

    template<typename P1,typename P2>
    Couple(P1&& a, P2&& b)
    :a{forward<P1>(a)},b{forward<P2>(b)}
    {}

    void show() const
    {
        cout<<"couple:\n";
        a.show();
        b.show();
    }
};

int main()
{
    Person p{"Juan Perez"};
    Person q=p;
    p.show();
    q.show();

    Person r = move(q);
    r.show();
    //q.show();//este no funca

    Person a1 {"Adan"};
    Person a2 {"Eva"};
    Couple a{a1,a2};
    a.show();

    Couple b {
        Person{"Alvaro"},
        Person{"Evo"}
    };
    b.show();
    cout<<"-----\n";
    Couple c {
        Person{"Carlos"},//movida
        a2//copia
    };
    c.show();
}