#include <iostream>
#include <typeinfo>

using namespace std;





struct X
{
    virtual ~X(){}
};


struct Y:X
{
    int* n;
    Y(int p):n{new int {p}}
    {}

    ~Y()
    {
        cout<<"bye"<<*n<<"\n";
        delete n;
    }

    void show()const
    {
        cout<<*n<<"\n";
    }
};

void print(const X& x)
{
    try
    {
    auto y = dynamic_cast<const Y& >(x);
    y.show();
    }
    catch(const bad_cast& e)
    {
        std::cout<<"if is not\n";
    }



}

int main(int argc, char const *argv[])
{
    /*X* x = new X(48);;

    static_cast<Y*>(x)->show();
    delete x;*/

    X* x = new X();
    auto y = dynamic_cast<Y*>(x);
    
    if(y)
    {
        y->show();
        //print(*x);
    }
    else{
        cout<<"no es instancia\n";
    }
    print(*x);

    delete x;
}


