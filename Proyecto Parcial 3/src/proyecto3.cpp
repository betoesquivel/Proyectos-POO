#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
#include "Reloj.h"
#include "Registro.h"
#include "Tarjeta.h"
#include "TarjetaEmpleado.h"
#include "TarjetaProveedor.h"
#include "TarjetaCliente.h"

//información para arreglos de tarjetas
const int tamMaxTarjetas = 40; 
char tipoTarjetas[tamMaxTarjetas];
int idTarjetas[tamMaxTarjetas];
int idEspecificos[tamMaxTarjetas];
string tienda_empresas[tamMaxTarjetas];
int indice; //Variable con el índice de una tarjeta en el arreglo

Tarjeta* tarjetas[40];

bool debug = true; 
string TAG = "DEBUG::";

string border = "====================";

void imprimirTodasTarjetas(){
    
    //como ya se
    if(debug)
        cout<<TAG<<"COMO YA SE IMPRIMIR"<<endl;
    for(int i = 0; i<40; i++){
        if(idTarjetas[i]!=0)
            cout<<tipoTarjetas[i]<<' '<<idTarjetas[i]<<' '<<idEspecificos[i]<<' '<<tienda_empresas[i]<<endl;
    }

    if(debug)
        cout<<TAG<<"USANDO ARREGLO DE APUNTADORES"<<endl;
    for(int i = 0; i<40; i++){
        if(tarjetas[i]->getIdTarjeta()!=0)
            tarjetas[i]->muestraDatos();
    }

}


void cargarTarjetas(string archivo){

	ifstream a;
	a.open(archivo.c_str());
	//Loop que lea y cargue las tarjetas en los arreglos paralelos
    char tipoTarjeta;
    int idTarjeta, idEspecifico; 
    string temp; 
    string tienda_empresa;

    string linea; 
    int i = 0; 
    while( getline(a,linea) ){
        //partir la línea
        istringstream iss( linea ); 

        //leer datos desde la línea
        iss>>tipoTarjeta>>idTarjeta>>idEspecifico;
        //Si la tarjeta es de empleado o de proveedor, se pide el nombre de la tienda o la empresa
        if(tipoTarjeta == 'E' || tipoTarjeta == 'P'){
            tienda_empresa = "";
            while(iss>>temp){
                if(tienda_empresa != "")
                    tienda_empresa += ' ';
                tienda_empresa += temp; 
            }
        }else{
            tienda_empresa = "N/A";
        }
            
        switch(tipoTarjeta){
            case 'E':
                //haz objeto empleado
                tarjetas[i] = new TarjetaEmpleado(idTarjeta,idEspecifico,tienda_empresa);
                break;
            case 'C':
                //haz objeto cliente
                tarjetas[i] = new TarjetaCliente(idTarjeta,idEspecifico);
                break;
            case 'P':
                //haz objeto proveedor
                tarjetas[i] = new TarjetaProveedor(idTarjeta,idEspecifico, tienda_empresa);
                break;
            default:
                cout<<"Tipo de tarjeta no existente."<<endl;
                break;
        }
        //Cargar la información de la tarjeta en el índice i de los arreglos paralelos. 
        tipoTarjetas[i] = tipoTarjeta;
        idTarjetas[i] = idTarjeta; 
        idEspecificos[i] = idEspecifico; 
        tienda_empresas[i] = tienda_empresa;

        i++;
    }
  
    
	a.close();

}

//validar hora
//validar hora salida
//validar tarjeta existente
//validar tarjeta existente en estacionamiento
char Menu(){
    char op; 
    cout<<endl;
    cout<<endl;
    cout<<border<<"Menu"<<border<<endl;
    cout<<endl;
    cout<<"a. Entrada al estacionamiento"<<endl;
    cout<<"b. Salida del estacionamiento"<<endl;
    cout<<"c. Consulta del estacionamiento"<<endl;
    cout<<"d. Consulta de tarjetas"<<endl;
    cout<<"e. Salir"<<endl;
    cout<<endl;
    cout<<"Elija una opcion: "<<endl;
    cin>>op; 
    return op; 
}

int main(){
	
	Registro estacionados[20];
    
    string nomArchivoDatos; 
    cout<<"Introduzca el nombre del archivo con los datos de las tarjetas: (con .txt)"<<endl;
    cin>>nomArchivoDatos; 
    cargarTarjetas(nomArchivoDatos);
    if(debug){
        cout<<TAG<<"Despues de cargar las tarjetas, mis arreglos paralelos quedan asi"<<endl; 
        imprimirTodasTarjetas();
    }
    char opcion = ' ';
    do{
        opcion = Menu();
        switch(opcion){
            case 'a':
                //hacer algo
                break;
            case 'b':
                //hacer algo
                break;
            case 'c':
                //hacer algo
                break;
            case 'd':
                //hacer algo
                break;
            case 'e':
                cout<<"Gracias por usar la aplicación."<<endl;
                break;
            default:
                cout<<"Esa no es una opcion valida. Intente otra vez."<<endl;
                break;
        }
    }while(opcion!='e');
	return 0; 

}
