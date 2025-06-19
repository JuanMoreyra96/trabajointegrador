#pragma once
#include <string>
#include "fechahora.h"
 class PaqueteDeViaje{
    private:
    int _idPaquete;
    int _idCoordinador[2];
    char _destino[50];
    char _tipoTransporte[20];
    char _hotel[30];
    float _precio;
    int _totalCupos;
    int _cuposOcupados;
    bool _temporadaAlta;
    FechaHora _fechaRegreso;
    FechaHora _fechaSalida;
    bool _estado;

     public:
        PaqueteDeViaje();
        PaqueteDeViaje(
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
        );
        //GETTERS
        int getIdPaquete();
        int getIdCoordinador1();
        int getIdCoordinador2();
        std::string getDestino();
        std::string  getTipoTransporte();
        std::string getHotel();
        float getPrecio();
        int getTotalCupos();
        int getCuposOcupados();
        bool getTemporadaAlta();
         FechaHora getFechaRegreso();
         FechaHora getFechaSalida();
        bool getEstado();
        //SETTERS
        void setIdPaquete(int idPaquete);
        void setIdCoordinador1(int idCoordinador);
        void setIdCoordinador2(int idCoordinador);

        void setDestino (std::string destino);
        void setTipoTransporte (std::string tipoTransporte);
        void setHotel (std::string hotel);
        void setPrecio(float precio);
        void setTotalCupos(int totalCupos);
        void setCuposOcupados(int cuposOcupados);
        void setTemporadaAlta(bool temporadaAlta);
        void setFechaRegreso(FechaHora fecha);
        void setFechaSalida(FechaHora fecha);
        void setEstado(bool estado);

        void Mostrar();

    };
