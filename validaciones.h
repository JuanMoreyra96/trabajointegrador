#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED
#include <string>
#include "fechahora.h"
class Validaciones{

    public:
        bool validarCadena(std::string cadena, int minumo, int maximo);
        bool validarIntPositivo(int numero);
        bool validarFloatPositivo(float numero);
        bool validarFechaProxima(int dia, int mes, int anio, int horas, int minutos);
        bool validarFechaPosterior(FechaHora primeraFecha, int dia, int mes, int anio, int horas, int minutos);
};

#endif // VALIDACIONES_H_INCLUDED
