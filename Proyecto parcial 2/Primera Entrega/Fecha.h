class Fecha{
	private:
		int dd; 
		int mm; 
		int aa; 
		
	public:
		//Constructores
		Fecha();
		Fecha(int, int, int);
		
		//Setters y Getters
		void setDd(int);
		int getDd();
	
		void setMm(int);
		int getMm();
	
		void setAa(int);
		int getAa();
		
		//Comportamientos
		void muestra();
};
	//CONSTRUCTORES
	Fecha::Fecha(){
		dd = 0;
		mm = 0;
		aa = 0; 
	}
	Fecha::Fecha(int dd, int mm, int aa){
		this->dd = dd;
		this->mm = mm;
		this->aa = aa; 
	}
	//FIN DE CONSTRUCTORES
	
	//SETTERS Y GETTERS
	void Fecha::setDd(int dd){
		this->dd = dd; 
	}
	int Fecha::getDd(){
		return dd; 
	}
	
	void Fecha::setMm(int mm){
		this->mm = mm; 
	}
	int Fecha::getMm(){
		return mm; 
	}
	
	void Fecha::setAa(int aa){
		this->aa = aa; 
	}
	int Fecha::getAa(){
		return aa; 
	}
	//FIN DE SETTERS Y GETTERS

	//COMPORTAMIENTOS
	void Fecha::muestra(){
		string d, m, a; 
		d = (dd<10) ? "0":"";
		m = (mm<10) ? "0":"";
		a = (aa<10) ? "0":"";
		
		cout<<d<<dd<<'/'<<m<<mm<<'/'<<a<<aa<<endl; 	
	}
	//FIN DE COMPORTAMIENTOS
