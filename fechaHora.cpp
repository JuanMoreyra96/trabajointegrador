#include <iostream>
#include "fechaHora.h"
#include <ctime>

using namespace std;

FechaHora::FechaHora(){
   time_t now = time(nullptr);              // Tiempo actual en segundos desde epoch
    struct tm *local = localtime(&now);      // Convertir a estructura de fecha/hora local

    _dia = local->tm_mday;
    _mes = local->tm_mon + 1;                // tm_mon es de 0 (enero) a 11 (diciembre)
    _anio = local->tm_year + 1900;           // tm_year es años desde 1900
    _hora = local->tm_hour;
    _minuto = local->tm_min;
}

FechaHora::FechaHora(int dia, int mes, int anio, int hora, int minuto){
    setDia(dia);
    setMes (mes);
    setAnio (anio);
    setHora (hora);
    setMinuto (minuto);
}

int FechaHora::getDia(){
    return _dia;
}
int FechaHora::getMes(){
    return _mes;
}
int FechaHora::getAnio(){
    return _anio;
}
int FechaHora::getHora(){
    return _hora;
}
int FechaHora::getMinuto(){
    return _minuto;
}

void FechaHora::setDia(int dia){
    _dia=dia;
}
void FechaHora::setMes (int mes){
    _mes=mes;
}
void FechaHora::setAnio (int anio){
    _anio=anio;
}
void FechaHora::setHora (int hora){
    _hora=hora;
}
void FechaHora::setMinuto (int minuto){
    _minuto=minuto;
}

void FechaHora::Mostrar(){
    std::cout << _dia << "/" << _mes << "/" << _anio << " " << _hora << ":" << _minuto <<  endl;
}

//prueba
