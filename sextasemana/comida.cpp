#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
void tengohambre()
{
    cout<<"muero de hambre"<<"\n";
}

string quierocomer()
{
    return "quiero comer un tranca pecho";
}
main(int argc, char const *argv[])
{
    cout<<"tengo hambre"<<"\n";
    tengohambre();
    auto comida = quierocomer();
    cout<<comida<<"\n";

    return 0;
}
