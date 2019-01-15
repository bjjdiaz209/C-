#include <functional>
#include <optional> //c++17
#include <map>
#include <iostream>
#include <any>
using namespace std;

template<typename C, typename T>
optional<reference_wrapper<const typename C::mapped_type>> my_find(const C& c, const T& val)
{
    auto it = c.find(val);
    if(it == c.end())
    {
        return {};
    }
    else
    {
        return {it->second};
    }
}
int main ()
{
    map<int,string> m;
    m[10]="diez";
    m[20]="veinte";
    m[30]="treinta";

    auto r = my_find(m,20);
    if(r)
        cout<<r.value().get()<<"\n";
    else
        cerr<<"NOT FOUND\n";

    any p=1;

    cout<<any_cast<int>(p)<<"\n";

    p = "hola"s;

    cout<<any_cast<string>(p)<<"\n";

    vector<any> x;
    x.push_back(1);
    x.push_back("hola"s);
    x.push_back(true);

    for(auto e:x)
    {
        if(e.type()==typeid(int))
        {
            cout<<any_cast<int>(e)<<"\n";
        }
    }
}


