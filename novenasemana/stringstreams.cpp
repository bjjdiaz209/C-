#include <iostream>
#include <sstream>
#include <string>
#include <cstring>

using namespace std;










int main(int argc, char const *argv[])
{
     stringstream ss;

     string hoy = "viernes";
     int dia= 25;
     const char* mes = "enero";

     size_t anio = 2019;

     ss<<"hoy"<<hoy <<" "<<dia<<"de"<<mes<<"de"<<anio<<"\n";

     string r = ss.str();
     cout<<r<<"\n";

    return 0;
}
