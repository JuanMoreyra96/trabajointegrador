#include "paquetedeviaje.h"
#include "cstring"
#include <iostream>

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
   _FechaSalida = FechaHora(); 
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
        FechaHora FechaSalida, 
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
    setFechaSalida(FechaSalida);
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
            return _fechaRegreso
         }
         FechaHora PaqueteDeViaje::getFechaSalida(){
            return _FechaSalida;
         }
        bool PaqueteDeViaje::getEstado(){
            return _estado;
        }
        //SETTERS
        void PaqueteDeViaje::setIdPaquete(int idPaquete){
            _idPaquete = idPaquete;
        }
        void PaqueteDeViaje::setIdCoordinador1(int idCoordinador){
            _idCoordinador[0] = idCoordinador
        }
         void PaqueteDeViaje::setIdCoordinador2(int idCoordinador){
            _idCoordinador[1] = idCoordinador
        }
        void PaqueteDeViaje::setDestino (std::string destino){
            strcpy(_destino, destino.c_str());
        }
        void PaqueteDeViaje::setTipoTransporte (std::string tipoTransporte){
            strcpy(_tipoTransporte, tipoTransporte.c_str());
        }
        void PaqueteDeViaje::setHotel (std::string hotel){
            strcpy(_hora, hotel.c_str());
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
            _FechaSalida = fecha;
        }
        void PaqueteDeViaje::setEstado(bool estado){
            _estado = estado;
        }
   
        void PaqueteDeViaje::Mostrar(){
//TODO: el manager ya habrá validado que el paquete esté activo
            cout<<"ID PAQUETE: "<<_idPaquete<<endl;
            cout<<"ID COORDINADOR 1: "<<_idCoordinador[0]<<endl;
            cout<<"ID COORDINADOR 2:"<<_idCoordinador[1]<<endl;
            cout<<"DESTINO: "<<_destino<<endl;
            cout<<"HOTEL: "<<_hotel<<endl;
            cout<<"TIPO DE TRANSPORTE: "<<_tipoTransporte<<endl;
            cout<<"PRECIO POR PERSONA: "<< _precio<<endl;
            cout<<"TOTAL DE CUPOS: "<<_totalCupos<<endl;
            cout<<"CUPOS OCUPADOS: "<<_cuposOcupados<<endl;
            cout<<"TEMPORADA: "<<_temporadaAlta<<endl;
            cout<<"FECHA DE SALIDA: "<<_FechaSalida<<endl;
            cout<<"FECHA DE REGRESO"<<_fechaRegreso<<endl;
            // estado: no se muestra
        }
