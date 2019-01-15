#include <iostream>
#include <map>
#include <memory>
using namespace std;

class vehiculo
{
    public:
    virtual ~vehiculo(){
    }
    virtual void mover()=0;    
};
class autom: public vehiculo
{
    void mover() override
    {
        cout<<"GIRAR LAS RUEDAS\n";
    }
};
int main()
{
    map<string,unique_ptr<vehiculo>> vs;
    vs["4285ABC"] = make_unique<autom>();
    vs["5283XYZ"] = make_unique<autom>();
    for (auto& e:vs)
    {
        cout<<e.first<<" ";
        e.second->mover();
        cout<<"\n";
    }
}