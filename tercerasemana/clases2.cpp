#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;


class Carro
{
    char* desc;
    char id[10];
private:
    /* data */
public:
    Carro(const char* des, const char* id)
    {
        auto len = strlen(des);
        desc = new char[len+1];
        memcpy(desc,des,len+1);

        strcpy(this->id,id);

    }
    Carro (const Carro& c)
    {
        strcpy(id,c.id);
        auto len = strlen(c.desc);
        desc= new char[len+1];
        memcpy(desc,c.desc,len+1);

    }
    const char* get_description()const
    {
        return desc;
    }
    const char* get_id()const
    {
        return id;
    }
    ~Carro()
    {
        cout<<"bye carro"<<"\n";
        delete[]desc;
    }
   
};



int main(int argc, char const *argv[])
{
    auto c1 = Carro{"ferrari2018","012033yy"};
    {
    Carro c2{"mustang","122y7"};

    cout<<c1.get_description()<<"\n";
    cout<<c2.get_id()<<"\n";

    }
    cout<<"hoy es lunes"<<"\n";
     
     auto c3 = Carro {"Una lambo regao de papa","12123uhuh"};

     auto c4 =c3;
      
    //cout<<c3.get_description()<<"\n";

}
