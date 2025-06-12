#pragma once
#include "fechaHora.h"

class Pago{
private:
    int _idPago;
    int _idReserva;
    float _importe;
    FechaHora _fecha;

public:
    Pago(int idPago, int idReserva, float importe, FechaHora fecha);
    Pago();

    int getIdPago();
    int getIdReserva();
    float getImporte();
    FechaHora getFecha();

    void setIdPago(int idPago);
    void setIdReserva(int idReserva);
    void setImporte(float importe);
    void setFecha(FechaHora fecha);

    void Mostrar();


};
