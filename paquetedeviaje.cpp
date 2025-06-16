#include "paquetedeviaje.h"
#include "cstring"
#include <iostream>
#include <iomanip>
using namespace std;

PaqueteDeViaje::PaqueteDeViaje(){
    _idPaquete = 0;
    _idCoordinador[0] = 0;
      _idCoordinador[1] = 0;
       strcpy( _destino, "");
       strcpy( _tipoTransporte, "");
       strcpy(  _hotel, "");
    _precio = 0;
    _totalCupos = 0;
    _cuposOcupados = 0;
    _temporadaAlta = false;
   _fechaRegreso = FechaHora();
   _fechaSalida = FechaHora();
    _estado = false;
   }


PaqueteDeViaje::PaqueteDeViaje(
      int idPaquete,
        int idCoordinador1,
        int idCoordinador2,
        std::string destino,
        std::string tipoTransporte,
        std::string hotel,
        float precio,
        int totalCupos,
        int cuposOcupados,
        bool temporadaAlta,
        FechaHora fechaRegreso,
        FechaHora fechaSalida,
        bool estado
){
    setIdPaquete(idPaquete);
    setIdCoordinador1(idCoordinador1);
    setIdCoordinador2(idCoordinador2);
    setDestino(destino);
    setTipoTransporte(tipoTransporte);
    setHotel(hotel);
    setPrecio(precio);
    setTotalCupos(totalCupos);
    setCuposOcupados(cuposOcupados);
    setTemporadaAlta(temporadaAlta);
    setFechaRegreso(fechaRegreso);
    setFechaSalida(fechaSalida);
    setEstado(estado);
}

        int PaqueteDeViaje::getIdPaquete(){
            return _idPaquete;
        }
        int PaqueteDeViaje::getIdCoordinador1(){
            return _idCoordinador[0];
        }
        int PaqueteDeViaje::getIdCoordinador2(){
            return _idCoordinador[1];
        }
        std::string PaqueteDeViaje::getDestino(){
            return _destino;
        }
        std::string  PaqueteDeViaje::getTipoTransporte(){
            return _tipoTransporte;
        }
        std::string PaqueteDeViaje::getHotel(){
            return _hotel;
        }
        float PaqueteDeViaje::getPrecio(){
            return _precio;
        }
        int PaqueteDeViaje::getTotalCupos(){
            return _totalCupos;
        }
        int PaqueteDeViaje::getCuposOcupados(){
            return _cuposOcupados;
        }
        bool PaqueteDeViaje::getTemporadaAlta(){
            return _temporadaAlta;
        }
         FechaHora PaqueteDeViaje::getFechaRegreso(){
            return _fechaRegreso;
         }
         FechaHora PaqueteDeViaje::getFechaSalida(){
            return _fechaSalida;
         }
        bool PaqueteDeViaje::getEstado(){
            return _estado;
        }
        //SETTERS
        void PaqueteDeViaje::setIdPaquete(int idPaquete){
            _idPaquete = idPaquete;
        }
        void PaqueteDeViaje::setIdCoordinador1(int idCoordinador){
            _idCoordinador[0] = idCoordinador;
        }
         void PaqueteDeViaje::setIdCoordinador2(int idCoordinador){
            _idCoordinador[1] = idCoordinador;
        }
        void PaqueteDeViaje::setDestino (std::string destino){
            strcpy(_destino, destino.c_str());
        }
        void PaqueteDeViaje::setTipoTransporte (std::string tipoTransporte){
            strcpy(_tipoTransporte, tipoTransporte.c_str());
        }
        void PaqueteDeViaje::setHotel (std::string hotel){
            strcpy(_hotel, hotel.c_str());
        }
        void PaqueteDeViaje::setPrecio(float precio){
            _precio = precio;
        }
        void PaqueteDeViaje::setTotalCupos(int totalCupos){
            _totalCupos = totalCupos;
        }
        void PaqueteDeViaje::setCuposOcupados(int cuposOcupados){
            _cuposOcupados = cuposOcupados;
        }
        void PaqueteDeViaje::setTemporadaAlta(bool temporadaAlta){
            _temporadaAlta = temporadaAlta;
        }
        void PaqueteDeViaje::setFechaRegreso(FechaHora fecha){
            _fechaRegreso = fecha;
        }
        void PaqueteDeViaje::setFechaSalida(FechaHora fecha){
            _fechaSalida = fecha;
        }
        void PaqueteDeViaje::setEstado(bool estado){
            _estado = estado;
        }

void PaqueteDeViaje::Mostrar(){
 cout << setw(5)  << _idPaquete
         << setw(8)  << _idCoordinador[0]
         << setw(8)  << _idCoordinador[1]
         << setw(20) << _destino
         << setw(20) << _hotel
         << setw(13) << _tipoTransporte
         << setw(10) << fixed << setprecision(2) << _precio
         << setw(8)  << _totalCupos
         << setw(8)  << _cuposOcupados
         << setw(10) << (_temporadaAlta ? "Alta" : "Baja")
         << " ";

    _fechaSalida.Mostrar();
    cout << " - ";
    _fechaRegreso.Mostrar();
    cout << endl;

}
