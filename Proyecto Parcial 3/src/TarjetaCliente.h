class TarjetaCliente : public Tarjeta{
    private:
        int idCli;
    public: 
        TarjetaCliente();
        TarjetaCliente(int id);

        void setIdCli(int id);
        int getIdCli();

        int calculaPago(Reloj hEntrada, Reloj hSalida, int tarifaxhora);
        void muestraDatos();
};

TarjetaCliente::TarjetaCliente(){
    idCli = -1; 
}
TarjetaCliente::TarjetaCliente(int id){
    idCli = id; 
}


void TarjetaCliente::setIdCli(int id){
    idCli = id; 
}
int TarjetaCliente::getIdCli(){
    return idCli;
}


int TarjetaCliente::calculaPago(Reloj hEntrada, Reloj hSalida, int tarifaxhora){ 
    int pago; 
    pago = calculaHoras(hEntrada, hSalida) * tarifaxhora;
    return pago; 
}
void TarjetaCliente::muestraDatos(){
    cout<<idCli<<endl;
}
