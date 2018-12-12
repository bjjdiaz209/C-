#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

struct PromanInt
{
    int* n;

    PromanInt(int p)
    :n{new int {p}}
    {}
    PromanInt()
    :n{nullptr}
    {}
    void operator=(const PromanInt& s)
    {
        delete n;
        n= new int {*(s.n)};
    }

    ~PromanInt()
    {
        delete n;
    }
};

template <typename T>

class Arraylist
{
    T* items;
    size_t n;
    size_t cap;

    public:
    Arraylist()
    :items{new T[4]},n{0},cap{4}
    {
    
    }

    ~Arraylist()
    {
        delete [] items;
    }

    Arraylist<T>& add(const T& x)
    {
        resize();
        items[n++]=x;
        return *this;
    }
  
  private:
  void resize()
  {
      if(n<cap)
      return;
  

  auto ncap = cap*2;

  auto nitems = new T[ncap];

  
  for(auto i = 0U; i < n; i++)
  {
      nitems[i] = items[i];
  }

  delete [] items;

  items = nitems;

  cap = ncap;
}

};


int main(int argc, char const *argv[])
{
    Arraylist<PromanInt> z;

    
    for(int i = 0; i < 1000; i++)
    {
        z.add(i* 17);
    }
    return 0;
}





  