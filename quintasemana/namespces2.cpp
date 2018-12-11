#include <iostream>
using std :: cout;



namespace a
{
    namespace b
    {
        namespace c
        {
            void d(){
            cout<<"next\n";
            }
        

        void e()
        {
            cout<<"eee\n";
        }
        }
    }
}

using namespace a::b::c;

int main(int argc, char const *argv[])
{
    a::b::c::d();
    e();
    return 0;
}
