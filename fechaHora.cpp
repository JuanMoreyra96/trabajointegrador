#include <iostream>
#include "fechaHora.h"

using namespace std;

FechaHora::FechaHora(){
    _dia=0;
    _mes=0;
    _anio=0;
    _hora=0;
    _minuto=0;
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

void FechaHora::Cargar(int dia, int mes, int anio, int hora, int minuto){
    setDia(dia);
    setMes(mes);
    setAnio(anio);
    setHora(hora);
    setMinuto(minuto);
}

void FechaHora::Mostrar(){
    std::cout << "La hora es: " << _hora << ":" << _minuto <<  endl;
    std::cout << "La fecha es: " << _dia << "/" << _mes << "/" << _anio << endl;
}
