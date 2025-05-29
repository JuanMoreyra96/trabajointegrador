#pragma once

class Pagos{
private:
    int _idPago;
    int _idReserva;
    float _importe;
    //Fecha _fecha;

public:
    Pagos(int idPago, int idReserva, float importe/*, Fecha fecha*/);
    Pagos ();

    int getIdPago();
    int getIdReserva();
    float getImporte();
    //Fecha getFecha();

    void setIdPago(int idPago);
    void setIdReserva(int idReserva);
    void setImporte(float importe);
    //void setFecha(Fecha fecha);

    void Mostrar();
    void Cargar(int idPago, int idReserva, float importe/*, Fecha fecha*/);

};
