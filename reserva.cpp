# include<iostream>
# include "reserva.h"
# include<cstring>
# include "fechaHora.h"
#include <iomanip>
using namespace std;

Reserva::Reserva(){
    _idReserva=0;
    _idCliente=0;
    _idPaquete=0;
    _cantidadViajeros=0;
    _fecha=FechaHora();
    _precioTotal=0;
    _deudaCancelada=false;
}

Reserva::Reserva(int idReserva, int idCliente, int idPaquete, int cantidadViajeros, FechaHora fecha, float precioTotal, bool deudaCancelada){
    setIdReserva(idReserva);
    setIdCliente(idCliente);
    setIidPaquete(idPaquete);
    setCantidadViajeros(cantidadViajeros);
    setFecha(fecha);
    setPrecioTotal(precioTotal);
    setDeudaCancelada(deudaCancelada);
}

//  ---- GETTERS ----

int Reserva::getIdReserva(){
    return _idReserva;
}
int Reserva::getIdCliente(){
    return _idCliente;
}
int Reserva::getIidPaquete(){
    return _idPaquete;
}
int Reserva::getCantidadViajeros(){
    return _cantidadViajeros;
}
FechaHora Reserva::getFecha(){
    return _fecha;
}
float Reserva::getPrecioTotal(){
    return _precioTotal;
}
bool Reserva::getDeudaCancelada(){
    return _deudaCancelada;
}

//  ---- SETTERS ----

void Reserva::setIdReserva(int idReserva){
    _idReserva=idReserva;
}

void Reserva::setIdCliente(int idCliente){
    _idCliente=idCliente;
}
void Reserva::setIidPaquete(int idPaquete){
    _idPaquete=idPaquete;
}
void Reserva::setCantidadViajeros(int cantidadViajeros){
    _cantidadViajeros=cantidadViajeros;
}
void Reserva::setFecha(FechaHora fecha){
    _fecha=fecha;
}
void Reserva::setPrecioTotal(float precioTotal){
    _precioTotal=precioTotal;
}
void Reserva::setDeudaCancelada(bool deudaCancelada){
    _deudaCancelada=deudaCancelada;
}

//  ---- MOSTRAR ----

void Reserva::Mostrar(){
 cout << left
         << setw(10) << _idReserva
         << setw(12) << _idCliente
         << setw(12) << _idPaquete
         << setw(20) << _cantidadViajeros;

    _fecha.Mostrar();

    cout << setw(15) << fixed << setprecision(2) << _precioTotal
         << setw(18) << (_deudaCancelada ? "CANCELADA" : "NO CANCELADA")
         << endl;
}



