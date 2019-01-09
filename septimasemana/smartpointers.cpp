#include <iostream>
#include <memory>

using namespace std;



struct N
{
    int n;
    ~N()
    {
        cout<<"bye\n";
    }
    N(int n):n{n}
    {

    }
};


int main(int argc, char const *argv[])
{
    /*N* p = new N{16};
    cout<<p->n<<"\n";

    throw 10;

    delete p;*/


    unique_ptr<N>p {new N{16}};

    cout<<p->n<<"\n";
    cout<<(*p).n<<"\n";

    N* pp = p.get();

    cout<<pp->n<<"\n";





    auto q = make_unique<N>(25);

    auto r = move(q);

    cout<<r->n<<"\n";

    cout<<q.get()<<"\n";
    return 0;
}

