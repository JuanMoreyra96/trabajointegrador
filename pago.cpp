# include<iostream>
# include "pago.h"
# include<cstring>
#include "fechaHora.h"

using namespace std;

Pago::Pago(){
    _idPago=0;
    _idReserva=0;
    _importe=0;
    FechaHora _fecha(1,1,2000,0,0);
}
Pago::Pago(int idPago, int idReserva, float importe, FechaHora fecha){
    setIdPago(idPago);
    setIdReserva(idReserva);
    setImporte(importe);
    setFecha(fecha);
}

int Pago::getIdPago(){
    return _idPago;
    }
int Pago::getIdReserva(){
    return _idReserva;
    }
float Pago::getImporte(){
    return _importe;
    }
FechaHora Pago::getFecha(){
    return _fecha;
    }

void Pago::setIdPago(int idPago){
    _idPago=idPago;
    }
void Pago::setIdReserva(int idReserva){
    _idReserva=idReserva;
    }
void Pago::setImporte(float importe){
    _importe=importe;
    }
void Pago::setFecha(FechaHora fecha){
    _fecha=fecha;
    }
void Pago::Mostrar(){
    cout<<"ID PAGO: "<<_idPago<<endl;
    cout<<"ID RESERVA:"<<_idReserva<<endl;
    cout<<"IMPORTE"<<_importe<<endl;
    cout<<"FECHA DE PAGO: ";
    _fecha.Mostrar();
}
