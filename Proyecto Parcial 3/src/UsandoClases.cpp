#include <iostream>

using namespace std; 
#include "Reloj.h"

int main(){
    Reloj r(10,10); 
	cout<<"Hola mundo."<<endl;
    cout<<r<<endl;
    
    Reloj r2; 
    cout<<"Cambia el reloj:"<<endl;
    cin>>r2; 
    cout<<r2<<endl; 

    r = r-r2;
    cout<<r<<endl;

	return 0; 
}
