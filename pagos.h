#pragma once
#include "fechaHora.h"

class Pagos{
private:
    int _idPago;
    int _idReserva;
    float _importe;
    FechaHora _fecha;

public:
    Pagos(int idPago, int idReserva, float importe, FechaHora fecha);
    Pagos ();

    int getIdPago();
    int getIdReserva();
    float getImporte();
    FechaHora getFecha();

    void setIdPago(int idPago);
    void setIdReserva(int idReserva);
    void setImporte(float importe);
    void setFecha(FechaHora fecha);

};
