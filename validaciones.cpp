#include "validaciones.h"
#include <cstring>
#include <iostream>
#include "fechaHora.h"
using namespace std;

  bool Validaciones::validarCadena(std::string cadena, int minumo, int maximo){
    int longitud = cadena.length();
    if(longitud >= minumo && longitud <= maximo){
        return true;
    }
    return false;
  }
  // para cantidad de viajeros por ejemplo
  bool Validaciones::validarIntPositivo(int numero){
      if(numero < 0) return false;
      return true;
  }
  // para precios de paquetes
  bool Validaciones::validarFloatPositivo(float numero){
      if(numero < 0) return false;
      return true;
  }
  // para fechas de paquetes de viajes: no puedo registrar un paquete con fecha pasada o de hoy. tiene que ser desde mañana en adelante, y como mucho 5 años proximos.
  bool Validaciones::validarFechaProxima(int dia, int mes, int anio, int horas, int minutos){
      FechaHora fechaActual;
      int diaActual, mesActual, anioActual, horaActual, minutoActual;
      diaActual = fechaActual.getDia();
      mesActual = fechaActual.getMes();
      anioActual = fechaActual.getAnio();
      horaActual = fechaActual.getHora();
      minutoActual = fechaActual.getMinuto();

    if (anio < anioActual || anio > anioActual + 5) return false;
    if (mes < 1 || mes > 12) return false;
    if (horas < 0 || horas > 23) return false;
    if (minutos < 1 || minutos > 59) return false;

    // Validar días según el mes (simplificado, sin años bisiestos)
    int diasPorMes[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (mes == 2 && ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0))) {
        diasPorMes[1] = 29; // año bisiesto
    }
    if (dia < 1 || dia > diasPorMes[mes - 1]) return false;

    // Comparar contra la fecha actual: solo se permite una fecha desde mañana en adelante
    if (anio < anioActual) return false;
    if (anio == anioActual && mes < mesActual) return false;
    if (anio == anioActual && mes == mesActual && dia <= diaActual) return false;

    return true;
  }

