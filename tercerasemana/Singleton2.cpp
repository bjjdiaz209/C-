#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;




struct Singleton2
{
    private:
    Singleton2()
    {
        cout<<"hola amigos\n";
    }
    public:
    void hi()const
    {
        cout<<"hoy jueves de fideos uchu\n";
    }

    static Singleton2& instance()
    {
        static Singleton2 s;
        return s;
    }
};

int main(int argc, char const *argv[])
{
    Singleton2::instance().hi();
    Singleton2::instance().hi();
    return 0;
}

