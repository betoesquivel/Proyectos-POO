#include <iostream>
#include <fstream>
#include <cstdlib>
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
const int anioActual = 13;

//Declaración de los arreglos de objetos para el programa. 
Aeropuerto aeropuertos[numMaxAeropuertos];
Pasajero pasajeros[numMaxPasajeros];
Vuelo vuelos[numMaxVuelos];

//Declaración de variables globales que contendrán los índices de los objetos encontrados al realizar una búsqueda
int indiceAeropuertos = 0;
int indicePasajeros = 0;
int indiceVuelos = 0;

bool validarNumVuelo(string numVuelo){
	bool existe = false;
	
	int i = 0;
	string numVueloTemp;
	while(!existe && i<numMaxVuelos){
		numVueloTemp = vuelos[i].getNumVuelo();
		if(numVueloTemp == numVuelo){
			existe = true; 
			indiceVuelos = i;
		}
		i++;
	}
	return existe; 
}

bool validarClaveAeropuerto(string clave){
	bool existe = false;
	
	int i = 0;
	string claveTemp;
	while(!existe && i<numMaxAeropuertos){
		claveTemp = aeropuertos[i].getClave();
		if(claveTemp == clave){
			existe = true; 
			indiceAeropuertos = i;
		}
		i++;
	}
	return existe; 
}
bool validarIdPasajero(int id){
	bool existe = false;
	int i = 0;
	int idTemp;
	while(!existe && i<numMaxPasajeros){
		idTemp = pasajeros[i].getId();
		if(idTemp == id){
			existe = true;
			indicePasajeros = i;
		}	 
		i++;
	}
	return existe; 
}
bool validarFecha(int dd, int mm, int aa){
	bool valida = false; 
	valida = (mm<=12 && mm>0 && aa>=anioActual && dd>0) ? true:false; 
	if(valida){
		if(mm == 2){
			valida = (dd<=28) ? true:false;
		}else{
			//1 3 5 7 8 10 12 tienen 31 días
			if(mm==1 && mm==3 && mm==5 && mm==7 && mm==8 && mm==10 && mm==12){
				valida = (dd<=31) ? true:false; 	
			}else{
				valida = (dd<=30) ? true:false; 
			}	
		}
	}
	return valida; 
}
bool validarHora(int hh, int mm){
	bool valida = false; 
	valida = (hh<24 && mm<60 && hh>0 && mm>0) ? true:false; 
	return valida; 
}

void imprimirAeropuertos(){
	for(int i = 0; i<numMaxAeropuertos; i++){
		if(aeropuertos[i].getClave() != "Clave Indefinida"){
			cout<<i+1<<") ";
			aeropuertos[i].muestra();
		}		
	}
}

void imprimirPasajeros(){
	for(int i = 0; i<numMaxPasajeros; i++){
		if(pasajeros[i].getId() != -1){
			cout<<i+1<<") ";
			pasajeros[i].muestra();
		}
	}		
}

void imprimirVuelos(bool imprimirLista){
	int cantidadPasajeros;
	int idAImprimir;
	//Podría cambiarlo a un while para no recorrer todo el arreglo... pero son solo 10 vuelos
	for(int i = 0; i<numMaxVuelos; i++){
		if(vuelos[i].getNumVuelo() != "Vuelo Indefinido"){
			vuelos[i].muestra();
			if(imprimirLista){
				//Extraigo el id del pasajero a imprimir, lo busco y lo imprimo
				cantidadPasajeros = vuelos[i].getCantidadPasajeros();
				for(int j = 0; j<cantidadPasajeros; j++){
					//Obtengo el id del pasajero en el índice j de la lista de pasajeros
					idAImprimir = vuelos[i].getListaPasajeros(j);
					
					validarIdPasajero(idAImprimir);
					//después de ejecutar ese metodo, ya tengo el índice del pasajero encontrado
					
					//Imprimo el nombre del pasajero encontrado...
					cout<<j+1<<") "<<pasajeros[indicePasajeros].getNombre()<<endl;
				}
			}
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
	//Debo pedir: numVuelo S, cveOrigen S, cveDestino S, fecha F(int, int, int), horaSalida H(int, int),
	string numVuelo, cveOrigen, cveDestino;
	int dia, mes, anio, horas, minutos;
	
	//mientras el usuario quiera seguir introduciendo vuelos
	bool seguir = true;
	char resp = '0'; 
	int i = 0;
	while(seguir && i<numMaxVuelos){
		cout<<"Vuelos introducidos hasta ahora: "<<i<<endl; 
		cout<<endl; 
		
		cout<<"Introduzca el número de vuelo: "<<endl;
		cin>>numVuelo;
		
		cout<<"Introduzca la clave del aeropuerto de origen: "<<endl;
		cin>>cveOrigen;
		while( !validarClaveAeropuerto(cveOrigen) ){
			cout<<"Ese aeropuerto no existe, intente de nuevo: "<<endl;
			cin>>cveOrigen;	
		}
		
		cout<<"Introduzca la clave del aeropuerto destino: "<<endl;
		cin>>cveDestino;
		while( !validarClaveAeropuerto(cveDestino) ){
			cout<<"Ese aeropuerto no existe, intente de nuevo: "<<endl;
			cin>>cveDestino;	
		}
		
		//Introducción de fecha
		cout<<"Introducción de la fecha de salida"<<endl;
		cout<<"Día: "<<endl; 
		cin>>dia;
		cout<<"Mes: "<<endl; 
		cin>>mes;
		cout<<"Año: "<<endl; 
		cin>>anio;
		while( !validarFecha(dia, mes, anio) ){
			cout<<"Fecha no válida, intente de nuevo:"<<endl;
			cout<<"Día: "<<endl; 
			cin>>dia;
			cout<<"Mes: "<<endl; 
			cin>>mes;
			cout<<"Año: "<<endl; 
			cin>>anio;
		}
		Fecha f(dia, mes, anio);
		
		cout<<endl; 
		
		//Introducción de la hora de salida
		cout<<"Introducción de la hora de salida"<<endl; 
		cout<<"Hora: "<<endl;
		cin>>horas;
		cout<<"Minutos: "<<endl;
		cin>>minutos;
		while( !validarHora(horas, minutos) ){
			cout<<"Hora inválida, intente de nuevo:"<<endl; 
			cout<<"Hora: "<<endl;
			cin>>horas;
			cout<<"Minutos: "<<endl;
			cin>>minutos;
		}
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

void consultaDeVueloPorFecha(Fecha fechaConsultada){
	Fecha fechaTemp;
	for(int i = 0; i<numMaxVuelos; i++){
		fechaTemp = vuelos[i].getFecha();
		if(fechaTemp == fechaConsultada){
			cout<<endl;
			vuelos[i].muestra();	
		}
	}
}

void consultaDeVuelosDeUnAeropuerto(string claveConsultada){
	string claveTemp;
	
	//Imprimo los vuelos que salen del aeropuerto
	cout<<"Del aeropuerto "<<claveConsultada<<" salen los siguientes vuelos:"<<endl;
	for(int i = 0; i<numMaxVuelos; i++){
		claveTemp = vuelos[i].getCveOrigen();	
		if(claveTemp == claveConsultada){
			cout<<endl;
			vuelos[i].muestra();	
		}
	}
	
	cout<<endl;
	
	//Imprimo los vuelos que llegan al aeropuerto
	cout<<"Al aeropuerto "<<claveConsultada<<" llegan los siguientes vuelos:"<<endl;
	for(int i = 0; i<numMaxVuelos; i++){
		claveTemp = vuelos[i].getCveDestino();	
		if(claveTemp == claveConsultada){
			cout<<endl;
			vuelos[i].muestra();	
		}
	}
}

//Este metodo despliega el menu y permite al usuario acceder a sus opciones
//Si el usuario decide salir del programa, el menu regresa false, si no, 
//regresa true. 
bool Menu(){
	bool seguir = true; 

	bool opcionValida = false;
	while(!opcionValida){ //imprime el menú mientras la opcion sea inválida
		cout<<endl;
		cout<<endl;
		
		cout<<borde<<"Menú"<<borde<<endl;
		cout<<"1) Dar de alta un pasajero en un vuelo"<<endl;
		cout<<"2) Consulta de vuelo por fecha"<<endl;
		cout<<"3) Consulta de vuelo por número de vuelo"<<endl;
		cout<<"4) Consulta de vuelos en un aeropuerto"<<endl;
		cout<<"0) Salir"<<endl;		
		
		cout<<endl;
		
		cout<<"Introduzca el caracter correspondiente a la instrucción a realizar:"<<endl;
		char op;
		cin>>op;
		switch(op){
			
			case '1': {
				opcionValida = true; 
				int idTemp; 
				string numVueloTemp;
				
				cout<<"Introduzca el id del pasajero a agregar: "<<endl; 
				cin>>idTemp; 
				while(!validarIdPasajero(idTemp)){
					cout<<"Ese id no existe, intente de nuevo:"<<endl; 
					cin>>idTemp; 
				}
				
				cout<<"Introduzca el número de vuelo donde se va a agregar: "<<endl; 
				cin>>numVueloTemp; 
				while(!validarNumVuelo(numVueloTemp)){
					cout<<"Ese número de vuelo no existe, intente de nuevo: "<<endl; 
					cin>>numVueloTemp; 	
				}

				//Con el objeto de la clase Vuelo con la clave introducida por el usuario
				//mando a llamar al método agregar pasajero con el id introducido por el usuario
				if(!( vuelos[indiceVuelos].agregarPasajero(idTemp) ) ){//recuerda que indice vuelos se actualizó en validarNumVuelo
				
					//si el método agregarPasajero regresó false, imprimo el mensaje de error...
					cout<<"El vuelo ya está lleno. No se agregó al pasajero."<<endl; 
				
				}
			}
			break;
			
			case '2': { 
				int dia, mes, anio; 
				opcionValida = true; 
				cout<<"Introducción de la Fecha a Buscar"<<endl;
				cout<<"Día: "<<endl; 
				cin>>dia;
				cout<<"Mes: "<<endl; 
				cin>>mes;
				cout<<"Año: "<<endl; 
				cin>>anio;
				while(!validarFecha(dia, mes, anio)){
					cout<<"Fecha no válida, intente de nuevo:"<<endl;
					cout<<"Día: "<<endl; 
					cin>>dia;
					cout<<"Mes: "<<endl; 
					cin>>mes;
					cout<<"Año: "<<endl; 
					cin>>anio;
				}
				Fecha f(dia, mes, anio);
				
				//Imprimo todos los vuelos(datos generales) con la fecha f...
				consultaDeVueloPorFecha(f);
			}
			break;
			
			case '3': { 
				opcionValida = true; 
				string numVueloTemp;
				int cantidadPasajeros;
				int idAImprimir;
				
				cout<<"Introduzca el número de vuelo: "<<endl;
				cin>>numVueloTemp;
				while( !validarNumVuelo(numVueloTemp) ){
					cout<<"Ese vuelo no existe, intente de nuevo: "<<endl;
					cin>>numVueloTemp;
				}
				
				cout<<endl;
				
				cout<<"Lista de pasajeros: "<<endl;
				//ya tengo el índice del arreglo vuelos donde está el vuelo...
				vuelos[indiceVuelos].muestra();
				
				//Imprimo la lista de pasajeros...
				
				//Extraigo la cantidad de pasajeros, para poder recorrer la lista con ids
				cantidadPasajeros = vuelos[indiceVuelos].getCantidadPasajeros();
				for(int j = 0; j<cantidadPasajeros; j++){
					//Obtengo el id del pasajero en el índice j de la lista de pasajeros
					idAImprimir = vuelos[indiceVuelos].getListaPasajeros(j);
					
					validarIdPasajero(idAImprimir);
					//después de ejecutar ese metodo, ya tengo el índice del pasajero encontrado
					
					//Imprimo el nombre del pasajero encontrado...
					cout<<j+1<<") "<<pasajeros[indicePasajeros].getNombre()<<endl;
				}
				cout<<endl;
			}
			break;
			
			case '4': { 
				opcionValida = true; 
				string cveTemp;
				cout<<"Introduzca la clave del aeropuerto cuyos vuelos desea consultar: "<<endl;
				cin>>cveTemp;
				while( !validarClaveAeropuerto(cveTemp) ){
					cout<<"Ese aeropuerto no existe, intente de nuevo: "<<endl;
					cin>>cveTemp;	
				}
				
				//Busco e imprimo los vuelos que salen y llegan al aeropuerto con esta clave válida.
				consultaDeVuelosDeUnAeropuerto(cveTemp);
				
			}
			break;

			case '0': {
				opcionValida = true; 
				seguir = false; 
			}
			break;
					
			default: {opcionValida = false; cout<<"Esa no es una opción válida. Intente de nuevo."<<endl;}
			break;
		}
	}
	
	return seguir; 
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
	cin.ignore();
	cargarAeropuertos(archivoAeropuertos);
	cargarPasajeros(archivoPasajeros);
	cin.ignore();
	introducirVuelos();
	if(debug){
		cout<<"Introducción de vuelos exitosa"<<endl; 
		cout<<endl; 
		imprimirVuelos(false);
	}
	bool mostrarMenu = true; 
	while(mostrarMenu){
		mostrarMenu = Menu();
	}
	return 0; 
}
