//

#include <iostream>
#include <string>
#include <cstring>

using namespace std;









int main(int argc, char const *argv[])
{
    int p[5];//stack
     int r=5;
    int* q = new int [5];

    q[0]=4;
    q[1]=9;
    q[2]=2;
    q[3]=3;
    q[4]=4;
     
    
    for(int i = 0; i < r; i++)
    {
        cout<<q[i]<<"\n";
    }

    delete[]q;
    
}


