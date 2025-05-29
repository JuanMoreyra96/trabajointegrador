# include "pagos.h"
# include<iostream>
# include<cstring>
//# include "archivoPagos.h"
//# include Fecha.h

void Pagos::setIdPago(int idPago){_idPago=idPago;}
void Pagos::setIdReserva(int idReserva){_idReserva=idReserva;}
void Pagos::setImporte(float importe){_importe=importe;}
//void Pagos::setFecha(Fecha fecha){_fecha=fecha};

int Pagos::getIdPago(){return _idPago;}
int Pagos::getIdReserva(){return _idReserva;}
float Pagos::getImporte(){return _importe;}
//Fecha Pagos::getFecha(){return _fecha};

void cargar(int idPago, int idReserva, float importe/*, Fecha fecha*/) {
        setIdPago(idPago);
        setIdReserva(idReserva);
        setImporte(importe);
        //setFecha(fecha);
    }
void Mostrar(){
    std::cout << "ID Pago: " << _idPago << endl;
    std::cout << "ID Reserva: " << _idReserva << endl;
    std::cout << "Importe: " << _importe << endl;
    //std::cout << "Fecha del pago: " << _fecha << endl;
};
