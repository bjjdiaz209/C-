#include <iostream>
using namespace std;




bool is_impar(int n)
{
    return n%2;
}
template <typename PRED>
void show(const int* a,size_t n, PRED pred) //bool(*pred)(int),
{
    
    for(auto i = 0U; i < n; i++)
    {
        auto& e = a[i];

        
        if (pred(e)) {
            cout<<e<<"\n";
        }
        cout<<"***\n";
    }
    
}
struct Range
{
    int min ,max;

    bool operator()(int n)const
    {
        return n>=min && n<=max;
    }
};



int main(int argc, char const *argv[])
{
    int nn[] = {10,8,2,5,40,27,4,6,19,21};
    show(nn,10,is_impar);

    Range r {10,30};

    show(nn,10,Range{2,8});
 //lambada expression
    show(nn,10,[](int n)->bool{
        return n%2==0;});
    
    
}
