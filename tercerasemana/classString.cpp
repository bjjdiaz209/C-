#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;


class String
{
    size_t len;

    char* str;

public:
    String(const char*s)
    :len{strlen(s)}//inicialix=zacion list
    {
        str = new char[len+1];
        memcpy(str,s,len+1);
        
     }
    String():String{""}
    {

    }
    String(const String& s)
    :len{s.len}, str{(char*)malloc(s.len+1)}//str{new char [len+1]}//constructor copia:
    {
          memcpy(str,s.str,len+1);
    }
    String& operator = (const String& s)
    {
        if(this==&s)return *this;
        this->~String();
        len = s.len;
        str = (char*)malloc(len+1);
        memcpy(str,s.str,len+1);
        return *this;
    }
    ~String()
    {
        free(str);
    }
    const char* c_str()const
    {
        return str;
    }
    const String operator+(const String& s)const
    {
       String aux;
       auto nlen = len + s.len;
       aux.str = (char*)realloc(aux.str,nlen+1);
       memcpy(aux.str,str,len);
       memcpy(aux.str+len,s.str,s.len+1);
       aux.len=nlen;


       return aux;
    }
    String operator+=(const String& s)
    {
        auto nlen= len +s.len;
        str= (char*)realloc(str,nlen+1);
        memcpy(str+len,s.str,s.len+1);
        len= nlen;
        return *this;

    }
/*bool operator==(const String&s)const;

bool operator!=(const String& s)const;
void trim();
int index_of(const String& s) const;

String substring(size_t init,size_t len)const;
String substring(size_t init )const;

cout << String("zanaoria").substring(1,3).c_str()<<"\n";

cout << String("coloflor").substring(4).c_str()<<"\n";

String p = "batman";

int x = p.index_of("man");

x = p.index_of("men");*/

};


class Person
{
 String first_name;
 String last_name;
 int id;
public:
    Person(const String& fn,const String& ln, int i)
    :first_name{fn},last_name{ln},id{i}
    {
        /*first_name=fn;
        last_name = ln;
        id = i;*/
    }
void print()const
    {
        cout<<first_name.c_str()<<" "<<last_name.c_str()<<" " <<id<<"\n";
    }
};


int main(int argc, char const *argv[])
{
    String s;

    String s2 = {"hola"};
    String s3 = "mundo";

    String s4 = s2;
    s = s3;

    cout<<s4.c_str()<<"\n";//devuelve cadena como const cahr *
    cout<<s.c_str()<<"\n";

    auto hm = s4+ " "+s;
    cout<<hm.c_str()<<"\n";
    hm +="nativo";
    cout<<hm.c_str()<<"\n";


    Person p1 {"elon ","musk",12122434};
    Person p2 {"el ","mu",12122434};
    Person p3 = p1;

    p1 = Person {"rick","grimees",34343435};

    p1.print();
    p2.print();
    p3.print();
    
    return 0;
}
