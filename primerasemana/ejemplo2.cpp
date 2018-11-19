#include <iostream>
using namespace std;


bool is_even(int n)

{
	if(n/2==0)//if(n/2)
	{

		return true;
	}

	return false;
}

void print_day(int d)
{
	switch(d)
	{
	


		case 0: cout<<"domingo\n";
		   break;

		case 1: cout<<"lunes\n";
		    break;

		case 2: cout<<"martes\n";
		    break;

		    default:
		       cout<<"invalid day\n";
		          break;
	}


}

void count_down(int n)
{
	/*cout<<n<<"\n";

	if(n==0)
	{
		return;
	}

	count_down(n-1);*/


	/*while(n>=0)
	{
		cout<<n<<"\n";
		n--;
	}
	*/

	while(n>=0)
	{
		cout<<n--<<"\n";
	}

}

void count(int a, int b)
{
	for (int i = a; i <=b; i++)
	{
		cout<<i<<"\n";
	}
}

void count(int a, int b,int ex)
{
	/*int i=a;
	while(i<=b)
	{
		if(i==ex){
			i++
			continue;
		}

		cout<<i<<"\n";

		i++;
	}*/

	for (int i = a; i <=b; i++)
	{
		if (i==ex)
		{
			i++;
		}
		cout<<i<<"\n";
	}
}



int main(int argc, char const *argv[])
{
	
	/*cout<<is_even(64)<<"\n";
	cout<<is_even(63)<<"\n";

	print_day(0);


	count_down(5);*/

	count(5,8);

	count(1,15,11);//sobrecarga



	///tarea 
	//void print_as_text(unsigned int n)

	// print_as_text(2481)

	//dos mil cuatricientos ochenta y uno
}