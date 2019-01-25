#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//pod tipos primitivos
using namespace std;




class Point3D
{
    int x,y,z;

    public:
    Point3D(int x ,int y,int z)
    :x{x},y{y},z{z}
    {

    }

    friend ostream& operator<<(ostream& os,const Point3D& p);
    friend class Point3DModifier;


};

ostream& operator<<(ostream& os,const Point3D& p)
{
    os<<p.x<<";"<<p.y<<";"<<p.z;

}

class Point3DModifier
{
    public:
    void modify(Point3D& p,int x,int y,int z)
    {
         p.x=x;
         p.y=y;
         p.z=z;
    }
};





int main(int argc, char const *argv[])
{
    Point3D p{6,7,8};
    cout<<p<<"\n";



    Point3DModifier m;
    m.modify(p,10,20,30);
    cout<<p<<"\n";
    return 0;
}
