#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
//Arraylist una lista que vive en head se puede camabiar tamano


struct StringArraylist
{
    char** items;
    size_t n;

};
using SAL = StringArraylist;//alias

void init(SAL* s)
{
    s->items= (char**)malloc(0);
    s->n=0;
    //maloc(0) da esoacio de memoria
}
char* clone(const char* s)
{
    auto len = strlen(s);
    auto cs = new char[len+1];
    memcpy(cs,s,len+1);//copia bytes por direcciones de memoria
    return cs;

    

}
void add(SAL* ss, const char* s)
{

/*ss->items[ss->n] = clone(s);

ss->n++;*/

ss->items=(char**)realloc(ss->items,(ss->n+1)*sizeof(char*));//cambiar el tamano de un array ,tamano del tipo de adato
ss->items[ss->n]= clone(s);
ss->n++;

}
void print(const SAL* s)
{
    
    for(size_t i = 0; i<s->n; i++)
    {
        cout<<s->items[i]<<"\n";
    }
    
}

void release(SAL* s)
{
    //free(s->items);//leberar con free sin son creadas con malloc

    
    for(size_t i = 0; i < s->n; i++)
    {
        delete[]s->items[i];
    }
    free(s->items);

}


int main()
{
   SAL ss;
   init(&ss);
   add(&ss,"hello");
   add(&ss,"world");
   add(&ss,"friends");
   add(&ss,"of");
   add(&ss,"c++");
  
   print(&ss);


}