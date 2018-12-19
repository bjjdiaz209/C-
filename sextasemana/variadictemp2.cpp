#include <iostream>

using namespace std;
 
string int_join(const string a,const string b ,const string c)
{
    cout<<"X" << b <<"\n";
    string auxiliar;
    auxiliar=b;
    return auxiliar;

}



template<typename...ARGS>
 string int_join(const string a,const string b ,const string c, const ARGS&... args)
 {
    

 }


 template<typename...ARGS>
 string join(const string a,const string b , const ARGS&... args)

{


}


int main(int argc, char const *argv[])
{
    auto p = join(";",2,"hola","amigos");


    auto p join(",",6,8,15,14,18,26);

    auto p join("pa","e","va","lu","ca");



    cout<<p<<"\n";
    return 0;
}







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