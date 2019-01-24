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
    


    size_t size;

    ifstream m{"student.dat",ios::binary};
    m.seekg(0,ios::end);

    size = m.tellg();

    cout<<size<<"\n";

    cout<<size/sizeof(student)<<"\n";
    
    student n;
    m.seekg(1*sizeof(student),ios::beg);

    m.read((char*)&n,sizeof(student));
    
    cout<<n.name<<"\n";
}