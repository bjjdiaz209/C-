#include<iostream>
#include <vector>
#include<string>
#include <cstring>

using namespace std;

class Couple
{
    Person a;
    Person b;
    public:
    Couple(const Person& a ,const Person& b)
    :a{a},b{b}
    {
    }
        void show()const
        {
            cout<<"couple\n";
            a.show();
            b.show();
        }

        Couple(Person&& a,Person&& b)
        :a{move(a)},b{move(b)}
        {
            cout<<"c2\n";
        }
    
};

int main(int argc, char const *argv[])
{
    Person a1{"adan"};

    Person a2 {"eva"};
    Couple a {a1,a2};
    a.show();
    Couple b {Person{"alvaro"},Person{"eva"}};

    b.show();
    
}
