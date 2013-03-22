#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std; 

#include "Aeropuerto.h"
#include "Pasajero.h"
#include "Fecha.h"
#include "Hora.h"
#include "Vuelo.h"

const string borde = "===============";
bool debug = true; 
const int numMaxAeropuertos = 5; 
const int numMaxPasajeros = 30; 
const int numMaxVuelos = 10; 

//Declaración de los arreglos de objetos para el programa. 
Aeropuerto aeropuertos[numMaxAeropuertos];
Pasajero pasajeros[numMaxPasajeros];
Vuelo vuelos[numMaxVuelos];

void imprimirAeropuertos(){
	for(int i = 0; i<numMaxAeropuertos; i++){
		cout<<i+1<<") ";
		aeropuertos[i].muestra();
	}		
}

void imprimirPasajeros(){
	for(int i = 0; i<numMaxPasajeros; i++){
		cout<<i+1<<") ";
		pasajeros[i].muestra();
	}		
}

void imprimirVuelos(bool imprimirLista){
	//Podría cambiarlo a un while para no recorrer todo el arreglo... pero son solo 10 vuelos
	for(int i = 0; i<numMaxVuelos; i++){
		if(vuelos[i].getNumVuelo() != "Vuelo Indefinido"){
			vuelos[i].muestra(imprimirLista);
			cout<<endl; 
		}
	}		
}

void cargarAeropuertos(string nomArchAeropuertos){
	ifstream archAeropuertos;
	archAeropuertos.open(nomArchAeropuertos.c_str());
	
	string temp, clv_temp, nom_temp;
	int primerEspacio, i = 0; 
	
	//recorre todo el archivo evitando salirse del range del arreglo
	while(!archAeropuertos.eof() && i<numMaxAeropuertos){
		getline(archAeropuertos, temp);//leo linea del archivo
		
		//encuentra espacio separando la clave del nombre del aeropuerto
		primerEspacio = temp.find_first_of(' ');
		
		//extraigo los valores de clave y nombre del string temp
		clv_temp = temp.substr(0, primerEspacio);
		nom_temp = temp.substr(primerEspacio+1);
		
		//guardo los valores en el arreglo
		aeropuertos[i].setClave(clv_temp);
		aeropuertos[i].setCiudad(nom_temp);
		
		i++;//aumento el iterador del arreglo
	}
	
	archAeropuertos.close();
}

void cargarPasajeros(string nomArchPasajeros){
	ifstream archPasajeros;
	archPasajeros.open(nomArchPasajeros.c_str());
	
	string temp, id_temp, nom_temp;
	int id;
	int primerEspacio, i = 0; 
	
	//recorre todo el archivo evitando salirse del range del arreglo
	while(!archPasajeros.eof() && i<numMaxPasajeros){
		getline(archPasajeros, temp);//leo linea del archivo
		
		//encuentra espacio separando la clave del nombre del aeropuerto
		primerEspacio = temp.find_first_of(' ');
		
		//extraigo los valores de clave y nombre del string temp
		id_temp = temp.substr(0, primerEspacio);
		nom_temp = temp.substr(primerEspacio+1);
		
		
		id = atoi(id_temp.c_str());//convierto id_temp a entero
		//guardo los valores en el arreglo
		pasajeros[i].setId(id);
		pasajeros[i].setNombre(nom_temp);
		
		i++;//aumento el iterador del arreglo
	}
	
	archPasajeros.close();
}

void introducirVuelos(){
	//Debo pedir: numVuelo S, cveOrigen S, cveDestino S, fecha F(int, int, int), horaSalida H(int, int), cantPasajeros = 0;
	string numVuelo, cveOrigen, cveDestino;
	int dia, mes, anio, horas, minutos;
	
	//mientras el usuario quiera seguir introduciendo vuelos
	bool seguir = true;
	char resp = '0'; 
	int i = 0;
	while(seguir && i<numMaxVuelos){
		cout<<"Vuelo número "<<i+1<<endl; 
		cout<<endl; 
		cout<<"Introduzca el número de vuelo: "<<endl;
		cin>>numVuelo;
		cout<<"Introduzca la clave del aeropuerto de origen: "<<endl;
		cin>>cveOrigen;
		cout<<"Introduzca la clave del aeropuerto destino: "<<endl;
		cin>>cveDestino;
		
		//Introducción de fecha
		cout<<"Introducción de la fecha de salida"<<endl;
		cout<<"Día: "<<endl; 
		cin>>dia;
		cout<<"Mes: "<<endl; 
		cin>>mes;
		cout<<"Año: "<<endl; 
		cin>>anio;
		
		Fecha f(dia, mes, anio);
		cout<<endl; 
		
		//Introducción de la hora de salida
		cout<<"Introducción de la hora de salida"<<endl; 
		cout<<"Hora: "<<endl;
		cin>>horas;
		cout<<"Minutos: "<<endl;
		cin>>minutos;
		
		Hora hs(horas, minutos);
		cout<<endl;
		
		//Guardar vuelo en el arreglo
		vuelos[i].setNumVuelo(numVuelo);
		vuelos[i].setCveOrigen(cveOrigen);
		vuelos[i].setCveDestino(cveDestino);
		vuelos[i].setFecha(f);
		vuelos[i].setHoraSalida(hs);
		
		//Aumento el índice
		i++;
		
		//Preguntar al usuario si desea seguir...
		cout<<"¿Desea seguir introduciendo vuelos? 1)Si 2)No"<<endl;
		cin>>resp;
		seguir = (resp=='1') ? true:false;
	}//Fin de while con introducción de vuelos
	
}

int main(){
	cout<<borde<<"Bienvenido a mi proyecto parcial 2"<<borde<<endl; 
	cout<<endl;
	cout<<endl;
	//debo cargar los aeropuertos y los pasajeros primero
	string archivoAeropuertos, archivoPasajeros;
	cout<<"Introduzca el nombre del archivo con los datos de aeropuertos: "<<endl; 
	cin>>archivoAeropuertos;
	cout<<"Introduzca el nombre del archivo con los datos de pasajeros: "<<endl; 
	cin>>archivoPasajeros;
	
	cout<<endl; 
	cargarAeropuertos(archivoAeropuertos);
	cargarPasajeros(archivoPasajeros);
	
	introducirVuelos();
	if(debug){
		cout<<"Introducción de vuelos exitosa"<<endl; 
		cout<<endl; 
		imprimirVuelos(false);
	}
	return 0; 
}
