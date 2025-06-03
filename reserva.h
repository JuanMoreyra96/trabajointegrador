#pragma once
#include "fechaHora.h"

class Reserva{
private:
    int _idReserva;
    int _idCliente;
    int _idPaquete;
    int _cantidadViajeros;
    FechaHora _fecha;
    float _precioTotal;
    bool _deudaCancelada;

public:
    Reserva();
    Reserva(int idReserva, int idCliente, int idPaquete, int cantidadViajeros, FechaHora fecha, float precioTotal, bool deudaCancelada);

    int getIdReserva();
    int getIdCliente();
    int getIidPaquete();
    int getCantidadViajeros();
    FechaHora getFecha();
    float getPrecioTotal();
    bool getDeudaCancelada();

    void setIdReserva(int idReserva);
    void setIdCliente(int idCliente);
    void setIidPaquete(int idPaquete);
    void setCantidadViajeros(int cantidadViajeros);
    void setFecha(FechaHora fecha);
    void setPrecioTotal(float precioTotal);
    void setDeudaCancelada(bool deudaCancelada);

    void Mostrar();


};
