#include <iostream>
#include <cstring>
#include <string_view>
#include <string>

using namespace std;


using namespace std::string_literals;



/*a.push_back('!');
a.push_back('!');
a.push_back('!');

cout<<a<<"\n";


a.insert(3,"");
a.insert(0,"!");
cout<<a<<"\n";


auto b = a.substring(0,3);
cout<<b<<"\n";
auto v = a.substring(0,3);
cout<<v<<"\n";

string d = "dinosario";

auto index = d.find("sav");

if(index==string::npos)
cout<<"no hay\n";
else
cout<<index<<"\n";*/




class Person
{
    string p;
private:
    /* data */
public:
    Person(const string_view sv)
    :p{sv}
    {

    }

    void print()const
    {
        cout<<p<<"\n";
    }
    
};






int main(int argc, char const *argv[])
{
    Person p{"juan"};

    Person q{ "jose"};



    p.print();
    q.print();
    return 0;
}
