#include <iostream>
#include <sstream>

using namespace std; 
#include "Reloj.h"
#include "Registro.h"
#include "Tarjeta.h"
#include "TarjetaEmpleado.h"
#include "TarjetaProveedor.h"
#include "TarjetaCliente.h"

int main(){
    string linea = "P 103 169 Office Depot";
    istringstream iss( linea ); 
    char tipo;
    int n1, n2;
    string nom; 
    iss>>tipo;
    iss>>n1>>n2; 
    getline(iss, nom); 

    cout<<tipo<<' '<<n1<<' '<<n2<<' '<<nom<<endl; 
	return 0; 
}
