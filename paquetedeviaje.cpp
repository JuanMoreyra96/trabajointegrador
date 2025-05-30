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
  // _fechaRegreso = FechaHora(); 
   //_FechaSalida = FechaHora(); 
    _estado;
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
        // FechaHora fechaRegreso, 
        // FechaHora FechaSalida, 
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
    // setFechaRegreso(fechaRegreso);
    // setFechaSalida(FechaSalida);
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

        }
        void PaqueteDeViaje::setTipoTransporte (std::string tipoTransporte);
        void PaqueteDeViaje::setHotel (std::string hotel);
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
        void PaqueteDeViaje::setFechaRegreso(Fecha fecha){
            _fechaRegreso = fecha;
        }
        void PaqueteDeViaje::setFechaSalida(Fecha fecha){
            _FechaSalida = fecha;
        }
        void PaqueteDeViaje::setEstado(bool estado){
            _estado = estado;
        }
        bool PaqueteDeViaje::Cargar()
        {
            //TODO: agregar validaciones
        cout<<"Id del paquete: ";
        cin>>_idPaquete;

        cout<<"Id del 1° coordinador: ";
        cin>>_idCoordinador[0];

        cout<<"Id del 2° coordinador: ";
        cin>>_idCoordinador[1]; 
        cout<<"Destino: ";
        cin>>_destino; 
        cout<<"Tipo de transporte: ";
        cin>>_tipoTransporte; 
        cout<<"Hotel: ";
        cin>>_hotel; 
        cout<<"Precio por persona en pesos:";
        cin>>_precio;
        cout<<"Total de cupos:";
        cin>>_cupos;
        cout<<"¿El paquete es de temporada alta o baja? 1-Alta 0-Baja";
        cin>>_temporadaAlta;
        _cuposOcupados = 0;
         cout<<"Fecha Y hora de salida (DD/MM/AAAA HH:mm): ";
        cin>>_FechaSalida
    
         cout<<"Fecha Y hora de regreso (DD/MM/AAAA HH:mm): ";
        cin>>_fechaRegreso
 
        _estado = true;
            return true;
        }
        void PaqueteDeViaje::Mostrar(){
//TODO:validar que este activo
            cout<<_idPaquete<<endl;
            cout<<_idCoordinador[0]<<endl;
            cout<<_idCoordinador[1]<<endl;
            cout<<_destino<<endl;
            cout<<_hotel<<endl;
            cout<<_tipoTransporte<<endl;
            cout<<_precio<<endl;
            cout<<_totalCupos<<endl;
            cout<<_cuposOcupados<<endl;
            cout<<_temporadaAlta<<endl;
            cout<<_FechaSalida<<endl;
            cout<<_fechaRegreso<<endl;

        }
