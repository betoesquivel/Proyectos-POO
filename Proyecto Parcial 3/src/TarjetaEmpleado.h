class TarjetaEmpleado : public Tarjeta{
    private:
        int idEmp;
        string Tienda; 
    public: 
        TarjetaEmpleado();
        TarjetaEmpleado(int id, string T);

        void setIdEmp(int id);
        int getIdEmp();

        void setTienda(string T);
        string getTienda();
        
        int calculaPago(Reloj hEntrada, Reloj hSalida, int tarifaxhora);
        void muestraDatos();
};

TarjetaEmpleado::TarjetaEmpleado(){
    idEmp = -1; 
    Tienda = "Sin nombre"; 
}
TarjetaEmpleado::TarjetaEmpleado(int id, string T){
    idEmp = id; 
    Tienda = T; 
}


void TarjetaEmpleado::setIdEmp(int id){
    idEmp = id; 
}
int TarjetaEmpleado::getIdEmp(){
    return idEmp; 
}

void TarjetaEmpleado::setTienda(string T){
    Tienda = T; 
}
string TarjetaEmpleado::getTienda(){
    return Tienda; 
}


int TarjetaEmpleado::calculaPago(Reloj hEntrada, Reloj hSalida, int tarifaxhora){ 
    int pago; 
    pago = 0 * tarifaxhora;
    return pago; 
}
void TarjetaEmpleado::muestraDatos(){
    cout<<idEmp<<' '<<Tienda<<endl;
}

