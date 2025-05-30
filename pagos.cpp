# include<iostream>
# include "pagos.h"
# include<cstring>
//# include "archivoPagos.h"
//# include "fecha.h"

using namespace std;

Pagos::Pagos(){
    setIdPago(0);
    setIdReserva(0);
    setImporte(0);
    //setFecha(0);
}
Pagos::Pagos(int idPago, int idReserva, float importe/*, FechaHora fecha*/){
    setIdPago(idPago);
    setIdReserva(idReserva);
    setImporte(importe);
    //setFecha(fecha);
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
/*FechaHora Pagos::getFecha(){
    return _fecha;
    }*/

void Pagos::setIdPago(int idPago){
    _idPago=idPago;
    }
void Pagos::setIdReserva(int idReserva){
    _idReserva=idReserva;
    }
void Pagos::setImporte(float importe){
    _importe=importe;
    }
/*void Pagos::setFecha(FechaHora fecha){
    _fecha=fecha
    }*/

}
