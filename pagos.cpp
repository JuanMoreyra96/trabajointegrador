# include<iostream>
# include "pagos.h"
# include<cstring>
//# include "archivoPagos.h"
#include "fechaHora.h"

using namespace std;

Pagos::Pagos(){
    _idPago=0;
    _idReserva=0;
    _importe=0;
    FechaHora _fecha(1,1,2000,0,0);
}
Pagos::Pagos(int idPago, int idReserva, float importe, FechaHora fecha){
    setIdPago(idPago);
    setIdReserva(idReserva);
    setImporte(importe);
    setFecha(fecha);
}

int Pagos::getIdPago(){
    return _idPago;
    }
int Pagos::getIdReserva(){
    return _idReserva;
    }
float Pagos::getImporte(){
    return _importe;
    }
FechaHora Pagos::getFecha(){
    return _fecha;
    }

void Pagos::setIdPago(int idPago){
    _idPago=idPago;
    }
void Pagos::setIdReserva(int idReserva){
    _idReserva=idReserva;
    }
void Pagos::setImporte(float importe){
    _importe=importe;
    }
void Pagos::setFecha(FechaHora fecha){
    _fecha=fecha;
    }


