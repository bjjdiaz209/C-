#include <iostream>
using namespace std;

struct Exception
{
    int err;
    void print()const
    {
        cerr<<"eror code"<<err<<"\n";
    }

    ~Exception()
    {
        cout<<"bye ex\n";
    }
};

void x()
{
    cout<<"hola\n";
    throw Exception{125};
}

int main(int argc, char const *argv[])
{
    
    
    try
    {
        x();
    }
    catch(const Exception& e)
    {
        e.print();
       
    }
    
}
