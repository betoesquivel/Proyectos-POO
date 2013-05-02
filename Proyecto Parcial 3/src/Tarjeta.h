class Tarjeta{
    private:
        int idTarjeta; 
    public: 
        virtual int calculaPago(Reloj hEntrada, Reloj hSalida, int tarifaxhora) = 0; 
        virtual void muestraDatos() = 0;
        int calculaHoras(Reloj hEntrada, Reloj hSalida); 
};


int Tarjeta::calculaHoras(Reloj hEntrada, Reloj hSalida){
    int m, h;
    m = hSalida - hEntrada; 
    Reloj diferencia;
    diferencia.convertirMinutosAHoraCompleta(m); 
    h = diferencia.getHh();
    h = (diferencia.getMm() >= 15) ? h+=1:h; 
    return h; 
}
