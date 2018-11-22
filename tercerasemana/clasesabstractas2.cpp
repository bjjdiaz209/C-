#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;


enum class language 
{
    SPANISH=1,
    ENGLISH=2

};

struct Greeter
{
    virtual const char* hi()const = 0;
    virtual const char* bye()const = 0;
    virtual ~Greeter(){}

};

struct SpanishGreeter : Greeter
{
    const char* hi()const override
    {
        return "buenos dias";

    }
    const char* bye()const override
    {
        return "buenos luego";

    }

};
struct EnglishGreeter : Greeter
{
    const char* hi()const override
    {
        return "good morning";

    }
    const char* bye()const override
    {
        return "talk yo you later";

    }

};

struct GreeterFactory
{
     static Greeter* create(language x)
     {
         
         switch (x)
         {
             case language::SPANISH:
             return new SpanishGreeter();
                 break;
                 case language::ENGLISH:
             return new EnglishGreeter();
                 break;
             
         
             
         }
         return nullptr;
     }
};






int main(int argc, char const *argv[])
{
    cout<<"Ingrese 1 espanol, 2 ingles";
    int n;
    cin>>n;
    language lng = (language)n;
    Greeter* g = GreeterFactory::create(lng);
    cout<<g->hi()<<"\n";
    cout<<g->bye()<<"\n";

    delete g;
}
