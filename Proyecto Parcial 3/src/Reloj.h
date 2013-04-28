
class Reloj{
	private:
		int hora;
		int minutos;
	public: 
		Reloj();
		Reloj(int h);
		Reloj(int h, int m);
		int getHora();
		void setHora(int h);
		int getMinutos();
		void setMinutos(int m);
		void muestra();
};

//CONSTRUCTORES
Reloj::Reloj(){
	hora = 0;
	minutos = 0;
}

Reloj::Reloj(int h){
	hora = h;
	minutos = 0;
}

Reloj::Reloj(int h, int m){
	hora = h;
	minutos = m;
}

//SETTERS Y GETTERS
int Reloj::getHora(){
	return hora; 
}

void Reloj::setHora(int h){
	hora = h; 
}


int Reloj::getMinutos(){
	return minutos; 
}

void Reloj::setMinutos(int m){
	minutos = m; 
}

//COMPORTAMIENTOS
void Reloj::muestra(){
	if(hora<10)
		cout<<0;
	cout<<hora<<":";
	
	if(minutos<10)
		cout<<0;
	cout<<minutos<<endl;
}
