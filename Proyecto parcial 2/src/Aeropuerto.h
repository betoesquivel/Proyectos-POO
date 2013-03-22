
class Aeropuerto{
	private:
		string clave;
		string ciudad;
	
	public:
		//Constructores
		Aeropuerto();
		Aeropuerto(string, string);
		
		//Setters y Getters
		void setClave(string);
		string getClave();
		
		void setCiudad(string);
		string getCiudad();
};
	//CONSTRUCTORES
	Aeropuerto::Aeropuerto(){
		clave = "Clave Indefinida";
		ciudad = "Ciudad Indefinida";
	}
	Aeropuerto::Aeropuerto(string clave, string ciudad){
		this->clave = clave;
		this->ciudad = ciudad; 
	}
	//FIN DE CONSTRUCTORES
	
	//SETTERS Y GETTERS
	void Aeropuerto::setClave(string clave){
		this->clave = clave; 
	}
	string Aeropuerto::getClave(){
		return clave; 
	}

	void Aeropuerto::setCiudad(string ciudad){
		this->ciudad = ciudad; 
	}
	string Aeropuerto::getCiudad(){
		return ciudad; 
	}
	//FIN DE SETTERS Y GETTERS
	
