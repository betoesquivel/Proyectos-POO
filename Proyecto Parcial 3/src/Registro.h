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

Registro::Registro(){
    idTarj = -1; 
}
Registro::Registro(int idT, Reloj r){
    idTarj = idT; 
    hrEntrada.setHh(r.getHh());
    hrEntrada.setMm(r.getMm());
}


void Registro::setIdTarj(int idT){
    idTarj = idT; 
}
int Registro::getIdTarj(){
    return idTarj;
}

void Registro::setHrEntrada(Reloj r){
    hrEntrada.setHh(r.getHh());
    hrEntrada.setMm(r.getMm());
}
Reloj Registro::getHrEntrada(){
    return hrEntrada; 
}
