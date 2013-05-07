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
const int tarifaxhora = 15;
char tipoTarjetas[tamMaxTarjetas];
int idTarjetas[tamMaxTarjetas];
int idEspecificos[tamMaxTarjetas];
string tienda_empresas[tamMaxTarjetas];

int indice; //Variable con el índice de una tarjeta en el arreglo
int indiceEstacionados; //Variable con el indice de la tarjeta de un auto estacionado
int numTarjetas = 0;
int numEstacionados = 0;

Tarjeta* tarjetas[40];
Registro estacionados[20];

bool debug = true; 
string TAG = "DEBUG::";

string border = "====================";

void imprimirTodasTarjetas(){
    
    if(debug)
        cout<<TAG<<"USANDO ARREGLO DE APUNTADORES"<<endl;
    for(int i = 0; i<numTarjetas; i++){
        if(tarjetas[i]->getIdTarjeta()!=0){
            tarjetas[i]->muestraDatos();
            cout<<endl;
        }
    }

}


void cargarTarjetas(string archivo){

	ifstream a;
	a.open(archivo.c_str());
    char tipoTarjeta;
    int idTarjeta, idEspecifico; 
    string temp; 
    string tienda_empresa;

    string linea; 
    int i = 0; 
	//Loop que lea y cargue las tarjetas en los arreglos paralelos
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
        numTarjetas++;
        i++;
    }
  
    
	a.close();

}

//validar hora
bool validarHora(int h, int m){
    return (h<22 && h>=8 && m<60 && m>=0) ? true:false; 
}
//validar hora salida
//se supone que cuando mando a llamar a este método ya validé primero la tarjeta
//asi que ya tengo el indice donde esta la hora guardado en la variable indice. 
bool validarHoraSalida(Reloj rSalida){
    bool valido = false; 
    Reloj rEntrada;
    rEntrada = estacionados[indice].getHrEntrada();
    if(rSalida>=rEntrada)
        valido = true; 
    else
        valido = false; 
    return valido; 
}

//validar tarjeta existente
bool validarTarjetaExistente(int id){
    int i = 0; 
    bool encontrado = false; 
    while(i<numTarjetas && !encontrado){
        if(tarjetas[i]->getIdTarjeta() == id){
            encontrado = true; 
            indice = i; 
        }
        i++;
    }
    return encontrado; 
}
//validar tarjeta existente en estacionamiento
bool validarTarjetaExistenteEstacionamiento(int id){
    int i = 0; 
    bool encontrado = false; 
    while(i<numTarjetas && !encontrado){
        if(estacionados[i].getIdTarj() == id){
            encontrado = true; 
            indiceEstacionados = i;
        }
        i++;
    }
    return encontrado; 
}

void sacarAuto(){
    //utilizando la variable indiceEstacionados, voya borrar ese auto y mover todos los demas hacia arriba.
    for(int i = indiceEstacionados; i<numEstacionados-1; i++){
        //el i+1 lo pongo en el i
        estacionados[i] = estacionados[i+1];
    }
    numEstacionados--;
}

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
	
    
    string nomArchivoDatos; 
    cout<<"Introduzca el nombre del archivo con los datos de las tarjetas: (con .txt)"<<endl;
    cin>>nomArchivoDatos; 
    cargarTarjetas(nomArchivoDatos);
    if(debug){
        cout<<TAG<<"Despues de cargar las tarjetas, mis arreglos paralelos quedan asi"<<endl; 
        imprimirTodasTarjetas();
    }
    char opcion = ' ';
    int id, h, m; 
    bool valido = false; 
    Reloj temp; 
    int totalAPagar = 0;
    do{
        opcion = Menu();
        switch(opcion){
            case 'a':
                //valido el id
                do{
                    cout<<"Introduzca el id de la tarjeta del auto que entra: "<<endl;
                    cin>>id; 
                    valido = validarTarjetaExistente(id);
                    if(valido){
                        do{
                            cout<<"Introduzca la hora de entrada del auto: "<<endl;
                            cin>>temp;
                            valido = validarHora(temp.getHh(),temp.getMm());
                            if(!valido) 
                                cout<<"Esa hora no es valida. Intente de nuevo."<<endl;
                            else{
                                estacionados[numEstacionados].setIdTarj(id);
                                estacionados[numEstacionados].setHrEntrada(temp);
                                numEstacionados++;
                            }
                                
                        }while(!valido);
                    }else{
                        cout<<"Esa tarjeta no existe. Intente de nuevo."<<endl;
                    }
                }while(!valido);
                break;
            case 'b':
                do{
                    cout<<"Introduzca el id de la tarjeta del auto que sale: "<<endl;
                    cin>>id; 
                    valido = validarTarjetaExistente(id);
                    if(valido)
                        valido = validarTarjetaExistenteEstacionamiento(id);
                    
                    if(valido){
                        do{
                            cout<<"Introduzca la hora de salida del auto: "<<endl;
                            cin>>temp;
                            valido = validarHora(temp.getHh(),temp.getMm());

                            if(!valido) 
                                cout<<"Esa hora no es valida. Intente de nuevo."<<endl;
                            else{
                                valido = validarHoraSalida(temp);
                                if(valido){
                                    //despliego la informacion del auto y su importe a pagar
                                    //ya tengo el indice de la tarjeta en la variable indice
                                    //ya tengo el indice en estacionados en la variable indiceEstacionados
                                    
                                    Reloj entrada; 
                                    entrada.setHh(estacionados[indiceEstacionados].getHrEntrada().getHh());
                                    entrada.setMm(estacionados[indiceEstacionados].getHrEntrada().getMm());
                                    cout<<"HORA DE ENTRADA:"<<endl;
                                    cout<<entrada;
                                    cout<<"HORA DE SALIDA:"<<endl;
                                    cout<<temp;

                                    totalAPagar = tarjetas[indice]->calculaPago(entrada, temp, tarifaxhora);
                                    cout<<"Horas a cobrar:"<<endl;
                                    cout<< totalAPagar/tarifaxhora <<endl;

                                    cout<<"Monto total: "<<endl;
                                    cout<< totalAPagar <<endl;

                                    //AQUI TENDRÍA QUE HACER TODOS LOS SHIFTS EN EL ARREGLO DE ESTACIONADOS PORQUE YA SE SALIÓ UN AUTO...
                                    sacarAuto();
                                    
                                    

                                }else{
                                    cout<<"Esa hora no es valida. Intente de nuevo."<<endl;
                                }
                            }
                                
                        }while(!valido);
                    }else{
                        cout<<"Esa tarjeta no existe o no se encuentra en el estacionamiento. Intente de nuevo."<<endl;
                    }
                }while(!valido);
                break;
            case 'c':
                int idBuscada;
                for(int i = 0; i<numEstacionados; i++){
                    idBuscada = estacionados[i].getIdTarj();
                    validarTarjetaExistente(idBuscada);
                    //ya tengo en la variable indice el indice donde encontro la variable
                    tarjetas[indice]->muestraDatos();
                    cout<<endl;
                }
                break;
            case 'd':
                cout<<"Estas son todas las tarjetas disponibles: "<<endl; 
                imprimirTodasTarjetas();
                break;
            case 'e':
                cout<<"Gracias por usar la aplicacion."<<endl;
                break;
            default:
                cout<<"Esa no es una opcion valida. Intente otra vez."<<endl;
                break;
        }
    }while(opcion!='e');
	return 0; 

}
