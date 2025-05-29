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

    void setIdPago(int idPago);
    void setIdReserva(int idReserva);
    void setImporte(float importe);
    //void setFecha(Fecha fecha);

    int getIdPago();
    int getIdReserva();
    float getImporte();
    //Fecha getFecha();

    bool cargar();
    void costrar();

};
