class Hora{
	private:
		int hh;
		int mm; 
		
	public:
		//Constructores
		Hora();
		Hora(int, int);
		
		//Setters y Getters
		void setHh(int);
		int getHh();

		void setMm(int);
		int getMm();
		
		//Comportamientos
		void muestra();
};
	//CONSTRUCTORES
	Hora::Hora(){
		hh = 0;
		mm = 0; 
	}
	Hora::Hora(int hh, int mm){
		this->hh = hh;
		this->mm = mm; 
	}
	//FIN DE CONSTRUCTORES
	
	//SETTERS Y GETTERS
	void Hora::setHh(int hh){
		this->hh = hh; 
	}
	int Hora::getHh(){
		return hh; 	
	}

	void Hora::setMm(int mm){
		this->mm = mm; 
	}
	int Hora::getMm(){
		return mm; 	
	}
	//FIN DE SETTERS Y GETTERS
	
	//COMPORTAMIENTOS
	void Hora::muestra(){
		string h = (hh<10) ? "0":"";
		string m = (mm<10) ? "0":"";
		
		cout<<h<<hh<<':'<<m<<mm<<endl; 	
	}
	//FIN DE COMPORTAMIENTOS
