#include <map>
#include <iostream>
#include <unordered_map>

using namespace std;


struct ph
{
    size_t operator()(int* e)const
    {
        return *e;
    }
};

struct pe
{
    bool operator()(int*a ,int* b)const
    {
        return *a == *b;
    }
};







int main(int argc, char const *argv[])
{

unordered_map<int*,string,ph,pe>p;

p[new int {10}]= "diez";
p[new int {11}]= "once";
p[new int {14}]= "catorce";
p[new int {0}]= "cero";

int pivot = 14; 
auto i3 = p.find(&pivot);
cout<<i3->second<<"\n";

}