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

for (int i = 0; i < cantidadRegistros; i++) {
    registro = pArchivo.leer(i);

    if (registro.getEstado()) {
        FechaHora fechaSalida = registro.getFechaSalida();

        if (val.validarFechaPosterior(fechaActual,
                                       fechaSalida.getDia(),
                                       fechaSalida.getMes(),
                                       fechaSalida.getAnio() ))
           {
            if (!encontrado) {
                paqueteMasCercano = registro;
                encontrado = true;
            } else {
                FechaHora fechaAnterior = paqueteMasCercano.getFechaSalida();
                if (!val.validarFechaPosterior(fechaSalida,
                                               fechaAnterior.getDia(),
                                               fechaAnterior.getMes(),
                                               fechaAnterior.getAnio()))
                {
                    paqueteMasCercano = registro;
                }
            }
        }
    }
}
    registro.Mostrar();
}
