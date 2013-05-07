class TarjetaProveedor : public Tarjeta{
    private:
        int idPro;
        string Empresa; 
    public: 
        TarjetaProveedor();
        TarjetaProveedor(int id, int idP, string E);

        void setIdPro(int id);
        int getIdPro();

        void setEmpresa(string E);
        string getEmpresa();
        
        int calculaPago(Reloj hEntrada, Reloj hSalida, int tarifaxhora);
        void muestraDatos();
};

TarjetaProveedor::TarjetaProveedor(){
    idPro = -1; 
    Empresa = "Sin nombre"; 
}
TarjetaProveedor::TarjetaProveedor(int id, int idP, string E):Tarjeta(id){
    idPro = idP; 
    Empresa = E; 
}

void TarjetaProveedor::setIdPro(int id){
    idPro = id; 
}
int TarjetaProveedor::getIdPro(){
    return idPro; 
}

void TarjetaProveedor::setEmpresa(string E){
    Empresa = E; 
}
string TarjetaProveedor::getEmpresa(){
    return Empresa; 
}


int TarjetaProveedor::calculaPago(Reloj hEntrada, Reloj hSalida, int tarifaxhora){ 
    int pago, horas;
    horas = calculaHoras(hEntrada,hSalida);
    pago =  (horas>0) ? (horas-1):0;     
    pago *= tarifaxhora;

    return pago; 
}
void TarjetaProveedor::muestraDatos(){
    cout<<idPro<<' '<<Empresa<<endl;
}
