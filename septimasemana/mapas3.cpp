#include <map>
#include <iostream>
#include <string>
#include <cstring>
#include <unordered_map>

using namespace std;



int main(int argc, char const *argv[])
{
    unordered_map<int,string>ns;
    ns[0]="cero";
    ns[10]="diez";
    ns[20]="veinte";
    ns[30]="treinta";
    ns[40]="cuarebta";
   

   
   for(auto& e : ns)
   {
       cout<<e.first<<" "<<e.second<<"\n";
   }
   
}
