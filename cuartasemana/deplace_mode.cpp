#include <iostream>
#include <string>
using namespace std;





int main(int argc, char const *argv[])
{ //iteracion de cadena
    auto dm = "deplace mode";

    for( string :: iterator i= dm.begin();i!=dm.end();i++)

    {
        cout<<*i<<"\n";
    }
    
    for(string :: reverse_iterator i = dn.rbegin(); i!=dm.rend(); ++i)

    {
          cout<<*i<<"\n";
    }

    
    for(char k:dm)

    {
        cout<<k<<"\n";
    }
    
    
    
}


