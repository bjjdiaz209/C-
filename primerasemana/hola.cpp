#include <iostream>
#include <string>

using namespace std;
 


void do_something(int n)
{
    cout<<"hello\n";

    cout<<"one\n";

    cout<<"two\n";

            if(n==3)
            goto SAY_BYE;
                return;


    cout<<"four\n";
    cout<<"five\n";


    SAY_BYE:

    cout<<"bye\n";

}

/*void p()
{
    int n=8;

    do{
        cout<<n--<<"\n";
    }
    while(n!=0);
}
*/


 int main()
 {
    do_something(5);

    cout<<"***\n";

    do_something(3);


 }