
class Pasajero{
	private:
		int id;
		string nombre; 
		
	public:
		//Constructores
		Pasajero();
		Pasajero(int, string);
		
		//Setters y Getters
		void setId(int);
		int getId();
		
		void setNombre(string);
		string getNombre();
};
	//CONSTRUCTORES
	Pasajero::Pasajero(){
		id = -1;
		nombre = "Nombre Indefinido";
	}
	Pasajero::Pasajero(int id, string nombre){
		this->id = id;
		this->nombre = nombre;
	}
	//FIN DE CONSTRUCTORES
	
	//SETTERS Y GETTERS
	void Pasajero::setId(int id){
		this->id = id; 
	}
	int Pasajero::getId(){
		return id; 
	}

	void Pasajero::setNombre(string nombre){
		this->nombre = nombre; 
	}
	string Pasajero::getNombre(){
		return nombre; 
	}
	//FIN DE SETTERS Y GETTERS
