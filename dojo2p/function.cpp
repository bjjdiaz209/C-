#include <iostream>
#include <functional>
#include <string>
#include <cstring>
#include <algorithm>



using namespace std::placeholders;

int sum(int x, int y)
{
    return x+y;
}

void v1(const string& s)
{
    cout<<s<<"\n";
}

void v2(const string& a, const string& b)
{
    cout<<a<<" "<<b<<"\n";
}
void p(int a,const string& b,int c)
{
  cout<<a<<" "<<b<<" "<<c<<"\n";
}

void invertir (string & s)
{
    reverse(s.begin(),send.end());
}

int main(int argc, char const *argv[])
{
    /*
    function<int (int,int)>q = sum;

    cout<<q(10,15)<<"\n";

    vector<function<void(const string& )>>visitors;

    visitors.push_back(v1);

    visitors.push_back([](auto s2)
    {
        cout<<"***"<<s2<<"\n";

    });


    string h ="hello worls";


     visitors.push_back([](auto s2)
    {
        cout<<s2<<"\n";

    });
*/
vector<function<void(const string& )>>visitor;

auto x = bind(v2,"HHHH",-1);
    visitor.push_back(x);

    visitor.push_back(bind(v2,-1,"MMMMM"));

    
    p(2,"lunes",8);

    auto q = bind(p,-1,-3,-2);

    q(15,25,"martes");


    auto r = bind(p,10,-2,50);

    r("miercoles");
    return 0;
}
