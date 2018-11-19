#include <iostream>
#include <string>

using namespace std;

size_t calc_lenght(const char* s)
 {
     auto origin = s;
     while(*s++);
     return s-origin-1;

    
 }

/*void copiar_cadena(char* t,const char* u )
{
    while(*u!='\0')
    {
    *t++ = *u++;
    }
    *u++;

}*/

void copiar_cadena(char* dest,const char* src)
{
    
    while(*src)
    {
        *dest= *src;
        dest++;
        src++;
    }
    *dest=0;
    
}

void concatenar_cadena(char* dest,const char* src)
{
    copiar_cadena(dest+calc_lenght(dest),src);
    

}

int main(int argc, char const *argv[])
{

    const char* c = "Fundacion";
    const char* d = "jala";

    char cd[30];
    copiar_cadena(cd,c);

    cout<<cd<<"\n";

    concatenar_cadena(cd,d);

    cout<<cd<<"\n";
}
