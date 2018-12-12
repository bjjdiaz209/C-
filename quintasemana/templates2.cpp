#include <iostream>
using namespace std;
//tipos enteros,boeanos
//vlaores conocidos en tirmpo de compilacion
template<int N, char K>

   void print()
   {
       
       for(int i = 0; i < N; i++)
       {
           cout<<K;
       }
       cout<<"\n";
   }


   int main(int argc, char const *argv[])
   {
       print<6,'*'>();
       print<10,'#'>();


       constexpr int n =5;
       print<n,'A'>();
       return 0;
   }
   
