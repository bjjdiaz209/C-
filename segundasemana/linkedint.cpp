#include <iostream>
#include <string>
#include <cstring>

using namespace std;

struct ILLItem
{
    int value;
    ILLItem* next;

};


struct ILL
{
    ILLItem* first;
    ILLItem* last;
};

void init(ILL* x)
{
    x->first=x->last=nullptr;
}

void add(ILL* x, int n)
{
    auto item = new ILLItem{n ,nullptr};

    
    if (x->first==nullptr) {
        x->first=x->last=item;

        return;
    }

    x->last->next=item;
    x->last=item;
    
}

void  print(const ILL* x)
{
    auto aux=x->first;

    
    while(aux)
    {
        cout<<aux->value<<"\n";
        aux=aux->next;
    }
    

}

void release(ILL* x)

{
    auto aux =x->first;
    
    while(aux){
        /*delete aux;
        aux=aux->next;*/

        auto next = aux->next;
        delete aux;
        aux=next;
    }
    
}




int main()
{
    ILL x;
    init(&x);
    add(&x,85);
    add(&x,18);
    add(&x,14);
    add(&x,6);
    
    print(&x);
    release(&x);


    
}