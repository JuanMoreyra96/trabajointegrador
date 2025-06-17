#include "informes.h"
#include <iostream>
#include "fechaHora.h"
#include "paquetedeviaje.h"
#include "paquetedeviajearchivo.h"
#include "paquetedeviajemanager.h"
#include "validaciones.h"
#include <iomanip>
using namespace std;

void Informes::mostrarPaquetesParaPublicidad(){
    FechaHora fechaActual;
    PaqueteDeViajeArchivo pArchivo;
    PaqueteDeViaje registro, paqueteMasCercano;
    int cantidadRegistros = pArchivo.getCantidadRegistros();
    bool encontrado = false;
    Validaciones val;

}

void Informes::mostrarClientesQueAdeudan(){

}
