# include<iostream>
# include "reserva.h"
# include<cstring>
//# include "fecha.h"

using namespace std;

Reserva::Reserva(){
    setIdReserva(0);
    setIdCliente(0);
    setIidPaquete(0);
    setCantidadViajeros(0);
    //setFecha(0);
    setPrecioTotal(0);
    setDeudaCancelada(0);
}

Reserva::Reserva(int idReserva, int idCliente, int idPaquete, int cantidadViajeros, /*FechaHora fecha*/ float precioTotal, bool deudaCancelada){
    setIdReserva(idReserva);
    setIdCliente(idCliente);
    setIidPaquete(idPaquete);
    setCantidadViajeros(cantidadViajeros);
    //setFecha(fecha);
    setPrecioTotal(precioTotal);
    setDeudaCancelada(deudaCancelada);
}

int Reserva::getIdReserva(){
    return _idReserva;
}
int getIdCliente();
int getIidPaquete();
int getCantidadViajeros();
//FechaHora getFecha();
float getPrecioTotal();
bool getDeudaCancelada();
