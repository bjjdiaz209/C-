#include <stdexcept>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;


class Ex : public exception
{
      int errorcode;
      char msg[100];
      public:
      Ex(int ec):errorcode{ec}
      {

          char aux[10];
          sprintf(aux,"%d",errorcode);
          strcat(msg,aux);
      }

      const char* what()const noexcept override
      {
          //return "un error ucurrio";

        
          return msg;
      }
};

int main(int argc, char const *argv[])
{
    
    
    try
    {
         throw Ex{58};
    }
    catch(const exception& e)
    {
        cerr << e.what() <<"\n";
    }
    
}


