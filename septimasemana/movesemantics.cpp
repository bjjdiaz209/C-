
#include<iostream>
#include <vector>
#include<string>

using namespace std;

class A
{
    string p;

    public:
    A(const string& s):p{s}
    {

    }
    const string& get()const
    {
        return p;
    }

    //A(A&& src)//rvalue reference puede cambiar el valor
    A(A&& src):p{move(src.p)}
    {

    
    }

    A(string&& s):p{move(s)}
    {
        cout<<"MOVE\n";
    }
};






int main(int argc, char const *argv[])
{
    A m {"hello"};
    string n = "2019";
      
      A q{n};

      cout<<m.get()<<"\n";

      cout<<q.get()<<"\n";



      vector<int> r;

      //r = get_list();
      /*
      vector<int> get_list()
      {
          vector<int>z;
          
          for(int i = 0; i <1000000; i++)
          {
              z.push_back(i*10);

              return z;
          }
          
      }*/

}
