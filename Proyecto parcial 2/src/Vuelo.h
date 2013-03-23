const int maxPasajeros = 10;
class Vuelo{
	private:
		string numVuelo;
		string cveOrigen;
		string cveDestino;
		Fecha fecha;
		Hora horaSalida;
		int cantidadPasajeros;
		int listaPasajeros[maxPasajeros];
	
	public:
		//Constructor
		Vuelo();
		
		//Setters y Getters
		void setNumVuelo(string);
		string getNumVuelo();
		
		void setCveOrigen(string);
		string getCveOrigen();
		
		void setCveDestino(string);
		string getCveDestino();
		
		void setFecha(Fecha);
		Fecha getFecha();
		
		void setHoraSalida(Hora);
		Hora getHoraSalida();
		
		int getListaPasajeros(int);
		
		int getCantidadPasajeros();
		
		//Comportamientos
		bool agregarPasajero(int);
		void muestra();
};

	//CONSTRUCTORES
	Vuelo::Vuelo(){
		numVuelo = "Vuelo Indefinido";
		cveOrigen = "Origen Indefinido"; 
		cveDestino = "Destino Indefinido"; 
		cantidadPasajeros = 0; 
		//No se si ya se hayan creado fecha y horaSalida, pero creo que si.
	}
	//FIN DE CONSTRUCTORES
	
	//SETTERS Y GETTERS
	void Vuelo::setNumVuelo(string numVuelo){
		this->numVuelo = numVuelo;	
	}
	string Vuelo::getNumVuelo(){
		return numVuelo; 	
	}
	
	void Vuelo::setCveOrigen(string cveOrigen){
		this->cveOrigen = cveOrigen;	
	}
	string Vuelo::getCveOrigen(){
		return cveOrigen; 	
	}
	
	void Vuelo::setCveDestino(string cveDestino){
		this->cveDestino = cveDestino;	
	}
	string Vuelo::getCveDestino(){
		return cveDestino; 	
	}
	
	void Vuelo::setFecha(Fecha fecha){
		this->fecha = fecha; 
	}
	Fecha Vuelo::getFecha(){
		return fecha; 	
	}

	void Vuelo::setHoraSalida(Hora horaSalida){
		this->horaSalida = horaSalida; 
	}
	Hora Vuelo::getHoraSalida(){
		return horaSalida; 	
	}
	
	int Vuelo::getListaPasajeros(int indice){
		int id	= listaPasajeros[indice];
		return id; 
	}
	
	int Vuelo::getCantidadPasajeros(){
		return cantidadPasajeros; 	
	}
	//FIN DE SETTERS Y GETTERS
	
	//COMPORTAMIENTOS
	bool Vuelo::agregarPasajero(int idAgregar){
		if(cantidadPasajeros<maxPasajeros){
			listaPasajeros[cantidadPasajeros] = idAgregar;
			cantidadPasajeros++;
			return true; 
		}else{
			return false; 	
		}	
	}
	
	void Vuelo::muestra(){
		cout<<numVuelo<<endl;
		cout<<"Origen: "<<cveOrigen<<endl;
		cout<<"Destino: "<<cveDestino<<endl;
		cout<<"Fecha: ";
		fecha.muestra();
		cout<<"Hora de Salida: ";
		horaSalida.muestra();
		cout<<"Cantidad de Pasajeros: "<<cantidadPasajeros<<endl; 
	}
	
	//FIN DE COMPORTAMIENTOS
