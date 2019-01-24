#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


struct person
{
    int id;
    string name;
};


ostream& operator<<(ostream& os,const person& p)
{
    os<<p.id<<";"<<p.name;
    return os;
}

istream& operator>>(istream& is, person& p)
{
    string line;
    getline(is,line);
    
    if (is.fail()) 
        return is;
    
    

    auto pos = line.find(";");

    
    if (pos==string::npos) 
        throw 143;
    

    auto sid = line.substr(0,pos);
    auto name = line.substr(pos+1);

    p.id =stoi(sid);

    p.name = name;
    return is;
    
    
}

int main(int argc, char const *argv[])
{
    /*
    vector<person>ps;
    ps.push_back({1,"juan lopez"});
    ps.push_back({8,"peter lopez"});
    ps.push_back({16,"jhonlopez"});


    ofstream g("people.txt");

    
    for(auto& p : ps)
    {
        g<<p<<"\n";
    }

    
  */
  ifstream h{"people.txt"};

  
  if (h.fail()) 
      return -1;
  

  vector<person>ps2;

  while(true)
  {
      person aux;
      h >> aux;

      if(h.fail())break;

      ps2.push_back(aux);
  }

  
  for(auto& p : ps2)
  {
      cout<<p<<"\n";
  }
  
  


    return 0;
}
