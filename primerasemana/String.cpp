#include <iostream>
#include <string>

//C introdujols


using namespace std;



 

 size_t calc_length(const char* s)
 {
     
     /*size_t n = 0;
     while(s[n]!='\0')
     {
     n++;
       
     }
     return n;
     */
    /*const char* ini = s;
    while(*s != '\0')
    
        s++

    return s ini-1;*/

    const char*origin = s;

    while(*s++)

    return s - origin -1;






     
 }




 int main()
 {
     const char* q = "hello world";//warning ninguno alos memoria solo lectura , puntero a una direccion de memoria de solo lectura
     cout<<q<<"\n";

     char s[]="cola mundo";//array de caracteres en el stack

     cout<<s<<"\n";
     
     s[0]='c';
     cout<<s<<"\n";
     

     cout<<calc_length(q)<<"\n";
     cout<<calc_length(s)<<"\n";

     //q[1]='o';
     //q[5]='w';
     //cout<<q<<"\n";
     


     /*const char* s= "perro";

     const char* q = s+2;

     cout<<q<<"\n";
     q--;
     cout<<q<<"\n";

     int x[]={1,2,3,4};
     int y[]=x+2;
     */


     
     
 }
 