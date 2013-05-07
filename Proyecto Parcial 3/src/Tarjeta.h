class Tarjeta{
    private:
        int idTarjeta; 
    public: 
        Tarjeta();
        Tarjeta(int idT);
        
        void setIdTarjeta(int idT);
        int getIdTarjeta();

        virtual int calculaPago(Reloj hEntrada, Reloj hSalida, int tarifaxhora) = 0; 
        virtual void muestraDatos() = 0;

        int calculaHoras(Reloj hEntrada, Reloj hSalida); 
};
Tarjeta::Tarjeta(){
    idTarjeta = -1; 
}
Tarjeta::Tarjeta(int idT){
    idTarjeta = idT; 
}

void Tarjeta::setIdTarjeta(int idT){
    idTarjeta = idT; 
}
int Tarjeta::getIdTarjeta(){
    return idTarjeta;
}

int Tarjeta::calculaHoras(Reloj hEntrada, Reloj hSalida){
    int m, h;
    m = hSalida - hEntrada; 
    Reloj diferencia;
    diferencia.convertirMinutosAHoraCompleta(m); 
    h = diferencia.getHh();
    h = (diferencia.getMm() >= 15) ? h+=1:h; 
    return h; 
}
