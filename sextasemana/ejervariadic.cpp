#include <iostream>

using namespace std;


auto get_string(int p)
{
    return to_string(p);
}

auto get_string(const string& s)
{
    return s;
}

template<class P>
string join(const string& ,const P& p)
{
    return get_string(p);
}

auto get_string (const char*s )
{
    return string{s};
}



template<typename P , typename...A>
string join(const string& sep,const P& p ,const A&...args)
{
return get_string(p)+ sep+ join(sep,args...)
}




int main(int argc, char const *argv[])
{
    auto p = join(";",2,"hola","amigos");


    //auto p join(",",6,8,15,14,18,26);

    //auto p join("pa","e","va","lu","ca");



    cout<<p<<"\n";
    return 0;
}