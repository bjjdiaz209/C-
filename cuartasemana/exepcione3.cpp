#include <iostream>
using namespace std;


struct Animal
{
    virtual void hablar()const = 0;
    virtual ~Animal(){}
};



struct Perro:Animal
{
    void hablar()const override
    {
        cout<<"gua\n";
    }
};




Animal* getAnimal()
{
    return new Perro();
}


void p()
{
    cout<<"hello\n";
    throw 5;
}

struct wrapper
{
   Animal* a;
   ~wrapper(){delete a;}
};
int main(int argc, char const *argv[])
{
    
    
    try
    {
        wrapper w {getAnimal()};
        w.a->hablar();
        p();
    }
    catch(int n)
    {
        cerr << "error" << n<<"\n";
    }
    
}
