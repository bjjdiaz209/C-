//run time type information

#include <iostream>
#include <typeinfo>
using namespace std;



struct FundacionJala
{
    
};






int main(int argc, char const *argv[])
{
    
    auto p = new FundacionJala();
    const type_info& ti= typeid(p);

    cout<<ti.name()<<"\n";
    
}







