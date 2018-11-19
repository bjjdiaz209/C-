#include <iostream>
#include <cstring>
using namespace std;

struct SSLItem
{
    char* value;
    SSLItem* next;
};

struct SSL
{
    SSLItem* first;
    SSLItem* last;

};

 void init(SSL* x)
{
    x->first=x->last=nullptr;

}

void add_tail(SSL* x , const char* text)

{
    size_t size_text = strlen(text)+1;
    char* save_text = new char[size_text];
    memcpy(save_text, text, size_text);
    SSLItem* new_item = new SSLItem{save_text,nullptr};

    
    if (x->first==nullptr) 
    {

          x->first=x->last=new_item;

          return;

    }

        new_item->next = x->first;

        x->first= new_item;
}

 
void add_head(SSL* x , const char* text)
{

        size_t size_text= strlen(text)+1;

        char* save_text = new char[size_text];

        memcpy(save_text, text, size_text);

        SSLItem* new_item = new SSLItem{save_text,nullptr};

        if (x->first==nullptr) {

           x->first=x->last=new_item;

          return;

}

      new_item->next = x->first;

      x->first= new_item;

 
}

void print(SSL*x)
{
     auto aux=x->first;

    
    while(aux)
    {
        cout<<aux->value<<"\n";
        aux=aux->next;
    }
}

void release(SSL* x)
{
    auto aux =x->first;
    
    while(aux){
    
        auto next = aux->next;
        delete aux;
        aux=next;
    }

}

int main()
{
    SSL s;
    init(&s);
    add_tail(&s,"hello");
    add_head(&s,"world");
    add_tail(&s, "today");
    add_head(&s ,"is");
    add_head(&s,"thursday");

    print(&s);
    //release(&s);

}