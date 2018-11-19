#include <iostream>

#include <cstring> 

using namespace std;







struct SLLItem

{

char* value;

SLLItem *next;

};




struct SLL

{

SLLItem *first;

SLLItem *last;

};




void init(SLL *x)

{

x->first = x->last = nullptr;

}




void add_tail(SLL* x, const char* value)

{

size_t size = strlen(value)+1;

char* new_value = new char[size];

memcpy(new_value, value, size);

SLLItem* new_item = new SLLItem{new_value, nullptr};




if (x->first==nullptr) {

x->first=x->last=new_item;

return;

}

x->last->next=new_item;

x->last=new_item;

 

}

void add_head(SLL* x, const char* value)

{

size_t size = strlen(value)+1;

char* new_value = new char[size];

memcpy(new_value, value, size);

SLLItem* new_item = new SLLItem{new_value, nullptr};

 

if (x->first==nullptr) {

x->first=x->last=new_item;

return;

}

new_item->next = x->first;

x->first = new_item;

 

}




void print(const SLL*x)

{

auto aux=x->first;

 

while(aux){

cout<<aux->value<<'\n';

aux=aux->next;

}

 

}

void release(SLL* x)

{

auto aux=x->first;

 

while(aux){

auto next = aux->next;

delete aux;

aux=next;

cout<<"eliminado"<<'\n';

}

}




int main()

{

SLL s;

init (&s);

add_tail(&s,"1");

add_head(&s,"2");

add_tail(&s,"3");

add_head(&s,"4");

add_tail(&s,"5");

add_head(&s,"6");

add_tail(&s,"7");

add_head(&s,"8");

print(&s);

release(&s);




return 0;

}

