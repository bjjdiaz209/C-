#include <iostream>
#include <memory>
#include <vector>

using namespace std;



struct Animal
{
    virtual ~Animal(){ cout<<"chaii\n";}

};


struct Vaca:Animal
{
    /* data */
};


struct Oveja:Animal
{
    /* data */
};



struct Zoo
{
    /*
    Animal* a1;
    Animal* a2;
    Animal* a3;*/

    unique_ptr<Animal>a1;
    unique_ptr<Animal>a2;
    unique_ptr<Animal>a3;


    Zoo(Animal* a1,Animal* a2,Animal* a3)
    :a1(a1),a2(a2),a3(a3)
    {
         throw 4;
    }

    ~Zoo()
    {
        /*
        delete a1;
        delete a2;
        delete a3;*/

    }

};



int main(int argc, char const *argv[])
{
    /*
    try{
    Zoo z{new Vaca(),new Oveja(), new Oveja()};

    }
    catch(...)
    {
        cout<<"Error\n";
    }
    return 0;
    */





    //vector<Animal*>animals;
    vector<unique_ptr<Animal>>animals;
     
    
    animals.emplace_back(new Oveja());
    animals.push_back(make_unique< Vaca>());
    
    
    for(auto& a : animals)
    {
        cout<<typeid(*a).name()<<"\n";
    }
    

}
