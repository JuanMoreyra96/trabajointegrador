#pragma once
#include <string>
#include "fechahora.h"
class Validaciones{

    public:
        bool validarCadenaDeLetras(std::string cadena);
        bool validarCadenaDeNumeros(std::string cadena);
        bool validarCadenaEmail(std::string cadena);
        bool validarLongitudCadena(std::string cadena, int minumo, int maximo);
        int pedirNumero();
        float pedirNumeroFloat();
        bool validarIntPositivo(int numero);
        bool validarFloatPositivo(float numero);
        bool validarFechaProxima(int dia, int mes, int anio, int horas, int minutos);
        bool validarFechaPosterior(FechaHora primeraFecha, int dia, int mes, int anio, int horas, int minutos);
        bool validarFechaCorrecta(int dia, int mes, int anio, int horas, int minutos);
        bool validarBooleano(int valor);
        bool validarTransporte(std::string cadena);
        bool validarBajaOcupacion(int totalCupos, int cuposOcupados);
};
