#include <iostream>
#include <string>

using namespace std;

void substring(char* rr, const char* s ,size_t initpos, size_t count  )
{
    auto q = s + initpos;
    
    for(size_t i = 0; i < count; i++)
    {
        *rr = *q;
        rr++;
        q++;
    }
    *rr=0;
    
}
int main()
{
    auto r= "hoy es lunes 12";

    char rr[10];

    substring(rr,r,7,5);

    cout<<rr<<"\n";
}
//mermait