#include <iostream>
#include <fstream>
using namespace std;
#include "Reloj.h"
#include "Registro.h"
#include "Tarjeta.h"
#include "TarjetaEmpleado.h"
#include "TarjetaProveedor.h"
#include "TarjetaCliente.h"

//información para arreglos de tarjetas
const int tamMaxTarjetas = 40; 
char tipoTarjeta[tamMaxTarjetas];
int idTarjeta[tamMaxTarjetas], idEspecifico[tamMaxTarjetas];
string tienda-empresa[tamMaxTarjetas];
//Variable con el índice de una tarjeta en el arreglo
int indice; 

void cargarTarjetas(string archivo){

	File a;
	a.open(archivo.c_str());
	//Loop que lea y cargue las tarjetas en los arreglos paralelos
	a.close();

}

int main(){
	
	Registro estacionados[20];
	Tarjeta* tarjetas[40];
	return 0; 

}
