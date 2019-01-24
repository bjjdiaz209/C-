#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//pod tipos primitivos
using namespace std;



struct student
{
    int id;
    char name[124];
};


int main(int argc, char const *argv[])
{
    vector<student>sts;
    sts.push_back(student{1,"avril lavigne"});
    sts.push_back(student{2,"natalia lavigne"});
    sts.push_back(student{3,"lady lavigne"});

    ofstream j {"student.dat",ios::binary};
    
    for(auto& s : sts)
    {
        j.write((char*)&s,sizeof(student));

    }
    j.close();

    student arr[3];

    ifstream k {"student.dat",ios::binary};
    k.read((char*)arr,3*sizeof(student));
    k.close();

    
    for(auto& a : arr)
    {
        cout<<a.name<<"\n";
    }
    

    return 0;
}

