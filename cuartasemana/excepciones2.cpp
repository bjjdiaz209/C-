
#include <iostream>
using namespace std;


struct A
{
    A(){}
    ~A(){cout<<"bye\n";}
};


void p()
{
    cout<<"hello\n";
    throw 5;
}




int main(int argc, char const *argv[])
{
   
    
    try
    {
        A a;//variable stack
        //auto a = new A();
        p();
        //delete a;
    }
    catch(int n)
    {
        cerr << "error" <<n<< "\n";
        
       // if (a) {
         //   delete a;
       // }
        
    }
    
}

