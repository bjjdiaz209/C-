#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;


struct Person
{
    string fn;
    string ln;
};



int main(int argc, char const *argv[])
{
    Person p []= {
        Person{"juan","lopez",},
        Person{"jorge","lopez"},
        Person{"Omar","vera"},
        Person{"alvaro","perez"}};
        sort(p, p + 4, [](auto &a, auto &b){
        return tie(a.ln, a.fn) < tie(b.ln, b.fn);
    });

    for(auto& i: p)
    {
        cout<<i.ln<<" "<<i.fn<<'\n';
    }
}   


