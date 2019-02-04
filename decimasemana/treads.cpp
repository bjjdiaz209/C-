//threads
//unidades de ejecucion oindependiente
//y concurrente,dentro de un proceso
//comparten address space 
//rapido intercambio de datos
//deadlocks/condiciones de carrera
//CONTEXT-SWITCH LIGERO
//diff
//proceso unidad de ejecucion independiente dentro de un sistema operativo
//no comparte addrees space
//intercambio de datos lento
//no hay deadlocks ni condiciones de
//CONTEXT-SWITCH PESADO 
#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <mutex>

using namespace std;

void f(const string& name)
{
    for(int  i = 0; i < 100; i++)
    {
        //this_thread::sleep_for(1ms);
        this_thread::yield();

        //scout<<i<<"\n";

        //cout<<this_thread::get_id()<<":"<<i<<"\n";

        cout<<name<<":"<<i<<"\n";
    }
    
}

void g(int id,mutex& m)
{
    
    //m.lock();
    lock_guard<mutex> gr {m};
    for(int i = 0; i < 100; i++)
    {
        cout<<id<<":"<<i<<"\n";
        this_thread::yield();
        
        
    }
    //m.unlock();
}



int main()
{ 
 
     mutex m;
    vector<thread> r;
    for(int  i = 0; i < 100; i++)
    {
        r.emplace_back(g,i,ref(m));
    }
    
  for(auto& x : r)
  {
      x.join();
  }
  
    /*
    thread p {f,"p"};
    
    string* s =new string ("q");

    thread q {f,*s};

    delete s;
    p.join();

    q.join();
    return 0;
*/
}





