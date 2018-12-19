#include <iostream>
using namespace std;




struct A
{
    int x;
    int y;
};


class P
{
    string p;

public:
    P(const string& s)
    :p{s}
    {
        cout<<"HIII\n";
    }
  
    void show()const
    {
        cout<<p<<"\n";

    }
};
template<typename PROC, typename...ARGS>
auto invoke(PROC p, const ARGS&...args)
{
    cout<<"Invoking..\n";
    return p(args...);
}


template<typename T , typename...A>
T create_instance(const A&... args)
{
    cout<<"create instance\n";
    return T {args...};
}

int sum(int a, int b)
{
    return a+b;
}




int main(int argc, char const *argv[])
{
    auto x = create_instance<A>(10,8);
    auto y = create_instance<P>("hello");

    cout<<x.x+x.y<<"\n";

    y.show();

    cout<<invoke(sum,6,8)<<"\n";

    return 0;
}

