//shared varios pueden tener la propiedad del objeto
//contedor de referencias
//es un objeto
#include <iostream>
#include <memory>
using namespace std;

class Int 
{
    int n;

    public:
    Int(int n)
    :n(n)
    {}

    ~Int()
    {
        cout<<"bye"<<n<<"\n";
    }
};



int main(int argc, char const *argv[])
{
    shared_ptr<Int> a{ new Int{19}};
    auto b = make_shared<Int>(60);
    auto c = make_shared<Int>(88);

    auto d =a ;
    b= make_shared<Int>(429);
    auto e =a ;

    a = make_shared<Int>(8000);

    cout<<"*******\n";



}
