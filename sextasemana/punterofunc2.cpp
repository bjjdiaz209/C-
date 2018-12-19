//polimorfismo "ad hoc"
//callbacks
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;


int cmp(const void* a , const void* b)
{
    auto aa = static_cast<const int*>(a);
    auto bb = static_cast<const int*>(b);
    return *aa-*bb;
}

int cmps(const void* a,const void* b)
{
    auto aa =(const char**)a; 
    auto bb = (const char**)b;

    return strcmp(*aa,*bb);


}



int main(int argc, char const *argv[])
{
    int m[]= {6,8,2,1,0,9};

    qsort(m,6,sizeof(int),cmp);

    
    for( int n: m)
    {
        cout<<n<<"\n";
    }




    const char* ss[] = {"marzo","abril","enero"};
    qsort(ss,3,sizeof(const char*),cmps);
    for( auto i: ss)
    {
        cout<<i<<"\n";
    }



    
    return 0;
}
