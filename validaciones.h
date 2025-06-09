#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED
#include <string>
#include "fechahora.h"
class Validaciones{

    public:
        bool validarCadenaDeLetras(std::string cadena);
        bool validarLongitudCadena(std::string cadena, int minumo, int maximo);
        int pedirNumero();
        float pedirNumeroFloat();
        bool validarIntPositivo(int numero);
        bool validarFloatPositivo(float numero);
        bool validarFechaProxima(int dia, int mes, int anio, int horas, int minutos);
        bool validarFechaPosterior(FechaHora primeraFecha, int dia, int mes, int anio, int horas, int minutos);
        bool validarDia(int dia);
        bool validarMes(int mes);
        bool validarAnio(int anio);
        bool validarHora(int hora);
        bool validarMinutos(int minutos);
        bool validarBooleano(int valor);
};

#endif // VALIDACIONES_H_INCLUDED
