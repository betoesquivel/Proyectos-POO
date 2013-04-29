
class Reloj{
	private:
		int hh;
		int mm;
	public: 
		Reloj();
		Reloj(int h);
		Reloj(int h, int m);
		int getHh();
		void setHh(int h);
		int getMm();
		void setMm(int m);
        friend ostream& operator<< (ostream& os, Reloj r);
        friend istream& operator>> (istream& is, Reloj &r);
        bool operator== (Reloj param); 
        bool operator<= (Reloj param); 
        bool operator>= (Reloj param); 
        int operator- (Reloj param);
        void operator= (int); 

};

//CONSTRUCTORES
Reloj::Reloj(){
	hh = 0;
	mm = 0;
}

Reloj::Reloj(int h){
	hh = h;
	mm = 0;
}

Reloj::Reloj(int h, int m){
	hh = h;
	mm = m;
}

//SETTERS Y GETTERS
int Reloj::getHh(){
	return hh; 
}

void Reloj::setHh(int h){
	hh = h; 
}


int Reloj::getMm(){
	return mm; 
}

void Reloj::setMm(int m){
	mm = m; 
}

//COMPORTAMIENTOS
ostream& operator<< (ostream& os, Reloj r){

	if(r.hh<10)
		os<<0;
	os<<r.hh<<":";
	
	if(r.mm<10)
		os<<0;
	os<<r.mm<<endl;
    return os; 

}

istream& operator>> (istream& is, Reloj &r){
    is>>r.hh>>r.mm;
    return is; 
}

bool Reloj::operator== (Reloj param){

    return (hh==param.hh && mm==param.mm) ? true:false; 

}

bool Reloj::operator<= (Reloj param){

    return (hh*60+mm <= param.hh*60+param.mm) ? true:false; 

}

bool Reloj::operator>= (Reloj param){

    return (hh*60+mm >= param.hh*60+param.mm) ? true:false; 

}

int Reloj::operator- (Reloj param){

    return ((hh*60+mm) - (param.hh*60+param.mm));

}

void Reloj::operator= (int m){

   mm = m%60;
   hh = m/60;
   hh = hh%24; 

}

