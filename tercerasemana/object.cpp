#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class Object 
{

    public:
    virtual bool equals(const Object& obj)const = 0;
    virtual void show()const = 0;
    virtual ~Object(){}

};

class IComparable:public virtual Object
{
    public:
    virtual int comopareTo(const Object& obj)const = 0;
};


class Integer: public virtual Object, public virtual IComparable
{
    int n;
    public:
    Integer(int n ): n{n}
    {}

    bool equals(const Object& obj) const override
    {
        //Integer& i = (Integer&)obj;
        const Integer& i = dynamic_cast<const Integer&>(obj);
        return n ==i.n;
    }
        void show()const override
        {
            cout<<n<<"\n";
        }
    
    int comopareTo(const Object& obj)const override
    {
        //Integer& i = (Integer&)obj;
        const Integer& i = dynamic_cast<const Integer&>(obj);
        return n-i.n;
    }

};


int main(int argc, char const *argv[])
{
    
    Object* p1 = new Integer{10};
    IComparable* p2 = new Integer{20};
    cout<<p1->equals(*p2)<<"\n";
    cout<<p2->comopareTo(*p1)<<"\n";

    p1->show();
    p2->show();

    delete p1;
    delete p2;

}
