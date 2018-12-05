
#include <iostream>

using namespace std;

void b();

void c()
{
    throw 1UL;
}

void a()
try{
    c();
    cout<<"jejej\n";

    /*int n* = nullptr;
    *c=40;*/

   int d =14 ,b=0;
   int e=d/b;
}
catch(...)
{
       cerr<<"cerrar\n";
}

void b()
{
    cout<<"b\n";
    throw true;
}


int main(int argc, char const *argv[])
{
   /* try
    {
        a();
    }
    catch(...)
    {
        cerr<<"exeption\n";
    }*/

    
    try
    {
        a();
    }
    catch(const char* s)
    {
        cerr << s << '\n';
    }
    catch(int p)
    {
        cerr<<"error"<<p<<"\n";
    }
    catch(...)
    {
        cerr<<"exeption oknown\n";

    }
    
}
