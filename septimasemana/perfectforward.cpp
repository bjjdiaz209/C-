#include <iostream>
#include <string>
#include <vector>
using namespace std;


while(!s.is_empety())
{
    auto r = s.dequeuve()<<"\n";
    cout<<r<<"\n";
}
int main(int argc, char const *argv[])
{
    pq<string ,4>s;
    s.enqueve(2,"hello");
    s.enqueve(3,"world");
    s.enqueve(1,"friend");
    s.enqueve(0,"today");
    s.enqueve(0,"is");
    s.enqueve(0,"tuesday");
    s.enqueve(1,"of");
    s.enqueve(1,"c++");


    return 0;
}
