#include <iostream>
#include <string>

using namespace std;
 
const string vacio = "";
 
const string X[] = { vacio, "Uno", "Dos ", "Tres ", "Cuatro ", "Cinco ",
                "Seis ", "Siete ", "Ocho ", "Nueve ", "Diez", "Once ",
                "Doce", "Trece ", "Catorce ", "Quince ",
                "Dieciseis", "diecisiete", "Dieciocho ", "Diecinueve " };
 
const string Y[] = { vacio, vacio, "Veinte ", "Treinta ", "Cuarenta ", "Cincuenta ",
                "Sesenta", "Setenta ", "Ochenta ", "Noventa" };
 
string convert2digit(int n, string suffix)
{
    if (n == 0) {
        return vacio;
    }

    if (n > 19) {
        return Y[n / 10] + X[n % 10] + suffix;    
    }
    else {
        return X[n] + suffix;
    }
}
 
string print_as_text(unsigned int n)
{

    
    string res;
 
   
    res = convert2digit((n % 100), "");

   if (n > 100 && n % 100) {
         res= res + "y";
    }

    
    res = convert2digit(((n / 100) % 10), "Cientos ")+ res;

    //cout<<res<<"\n";
 
    res = convert2digit(((n / 1000) % 100), "Mil ") + res;

    cout<<res<<"\n";

 
   return res;
}
 
int main()
{
    print_as_text(2481);
    
}