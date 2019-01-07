#include<iostream>
#include <vector>
#include<string>
#include <cstring>
#include <ctime>

using namespace std;


class Person
{
    char* name;

    public:
    Person(const char* n)
    {
        size_t len = strlen(n);
        name = new char[len+1];
        mempcpy(name,n,len+1);
    }
    ~Person()
    {
        delete[]name;
    }

    Person(const Person& p)
    {
        cout<<"copu\n";
        auto len = strlen(p.name);
        name= new char [len+1];
        memcpy(name,p.name,len+1);
    }
    

    Person& operator=(const Person& p)
    {
        cout<<"copy\n";

        delete []name;
        auto len = strlen(p.name);
        name = new char [len+1];
        memcpy(name,p.name,len+1);
        return *this;
    }

    Person(Person&& src)
    :name{src.name}
    {
        src.name= nullptr;
        cout<<"move\n";
    }

   void show()
   {
       cout<<name<<"\n";
   }

};

class Couple
{
    Person a;
    Person b;
    public:
    Couple(const Person& a ,const Person& b)
    :a{a},b{b}
    {
        cout<<"couple ctor\n";
    }
     Couple(Person&& a,Person&& b)
    :a{move(a)},b{move(b)}
    {
        cout<<"c2\n";
    }
    template<typename P1,typename P2>
    Couple(P1&& a, P2&& b)
    :a{forward<P1>(a)},b{forward<P2>(b)}
    {}
    
    void show()const
    {
        cout<<"couple:\n";
        a.show();
        b.show();
    }

   
};
/*
class Fatty
{
   char* p;
   public:
   Fatty(char k)
   {
       p= new char [10000000];
       
       for(int i = 0; i < 100000; i++)
       {
           p[i]=k;
       }

       
   }
    ~Fatty(){delete[]p;}

    Fatty(const Fatty& src)
    {
        p= new char [10000000];
        
        for(int i = 0; i < 1000000; i++)
        {
            p[i]=src.p[i];
        }
        
    }

Fatty& operator=(const Fatty& src)
    {
        delete[] p;
        p= new char [10000000];
        
        for(int i = 0; i < 1000000; i++)
        {
            p[i]=src.p[i];
            return *this;
        }
        
    }
    Fatty(Fatty&& src):p{src.p}
    {
        src.p=nullptr;
    }
    Fatty& operator=(Fatty&& src)
    {
        p = src.p;
        src.p= nullptr;
        return *this;
    }
};

template<typename T>
void swp(T& a ,T& b)
{
    T aux= move(a);
    a=move(b);
    b=move(aux);
}
*/
int main(int argc, char const *argv[])
{
    Person p {"Juan peres"};
     Person q = p;
     p.show();
     q.show();

     Person r = move(q);
     r.show();
     q.show();

/////////////////////////

     Person a1{"adan"};

    Person a2 {"eva"};
    Couple a {a1,a2};
    a.show();
    Couple b {Person{"alvaro"},Person{"eva"}};

    b.show();

    Couple c {Person{"carlos"},a2};
    c.show();
    /////////////////////////////////
/*
    Fatty a {'x'};

    Fatty b {'y'};


    auto z0 = clock();

    
    for(int i = 0; i <3000; i++)
    {
        swp(a,b);
    }

    auto z1 = clock();

    cout<<(z1-z0)<<"\n";
    
    

  */  
}
