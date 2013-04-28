#include <iostream>

using namespace std; 

class Registro{
	private:
		int idTarj;
		Reloj hrEntrada; 
	public:
		Registro();
		Registro(int, Reloj); 
		
		void setIdTarj(int);
		int getIdTarj();
		
		void setHrEntrada(Reloj);
		Reloj getHrEntrada(); 

};
