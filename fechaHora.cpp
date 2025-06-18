#include <iostream>
#include "fechaHora.h"
#include <ctime>

using namespace std;

FechaHora::FechaHora(){
   time_t now = time(nullptr);              // Tiempo actual en segundos desde epoch
    struct tm *local = localtime(&now);      // Convertir a estructura de fecha/hora local

    _dia = local->tm_mday;
    _mes = local->tm_mon + 1;                // tm_mon es de 0 (enero) a 11 (diciembre)
    _anio = local->tm_year + 1900;           // tm_year es a�os desde 1900
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
    std::cout << _dia << "/" << _mes << "/" << _anio << " " << _hora << ":" << _minuto << " ";
}

 int convertirADiasTotales(FechaHora fecha);
    int calcularDiferenciaDeDias(FechaHora fecha1, FechaHora fecha2);
    bool esBisiesto(int anio);
    int contarAniosBisiestos(int anio);


bool FechaHora::esBisiesto(int anio) {
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}
int FechaHora::contarAniosBisiestos(int anio) {
    // Restamos 1 porque no contamos el a o actual
    anio--;
    return anio / 4 - anio / 100 + anio / 400;
}

int FechaHora::convertirADiasTotales(FechaHora fecha) {
    int diasTotales = fecha._anio * 365 + fecha._dia;

    int diasPorMes[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    // Sumamos los d as de los meses anteriores al actual
    for (int i = 0; i < fecha._mes - 1; i++) {
        diasTotales += diasPorMes[i];
    }

    // Ajustamos si el a o es bisiesto y la fecha es posterior a febrero
    if (fecha._mes > 2 && esBisiesto(fecha._anio)) {
        diasTotales += 1;
    }

    // Contamos los a os bisiestos anteriores a este a o
    diasTotales += contarAniosBisiestos(fecha._anio);

    return diasTotales;
}

int FechaHora::calcularDiferenciaDeDias(FechaHora fecha1, FechaHora fecha2) {
    int dias1 = convertirADiasTotales(fecha1);
    int dias2 = convertirADiasTotales(fecha2);
    return abs(dias1 - dias2);
}


