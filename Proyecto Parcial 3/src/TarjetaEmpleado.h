class TarjetaEmpleado : public Tarjeta{
    private:
        int idEmp;
        string Tienda; 
    public: 
        TarjetaEmpleado();
        TarjetaEmpleado(int id, int idE, string T);

        void setIdEmp(int id);
        int getIdEmp();

        void setTienda(string T);
        string getTienda();
        
        int calculaPago(Reloj hEntrada, Reloj hSalida, int tarifaxhora);
        void muestraDatos();
};

TarjetaEmpleado::TarjetaEmpleado():Tarjeta(){
    idEmp = -1; 
    Tienda = "Sin nombre"; 
}
TarjetaEmpleado::TarjetaEmpleado(int id, int idE, string T):Tarjeta(id){
    idEmp = idE; 
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
    cout<<"EMPLEADO "<<idEmp<<endl;
    cout<<"Tarjeta "<<idTarjeta<<endl;
    cout<<"Tienda "<<Tienda<<endl;
}

