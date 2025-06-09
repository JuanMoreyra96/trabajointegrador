#include "validaciones.h"
#include <string>
#include <cctype>
#include <iostream>
#include "fechaHora.h"

using namespace std;

  bool Validaciones::validarCadenaDeLetras(std::string cadena){
      for (char c : cadena) {
        if (!isalpha(c) && c != ' ') return false;
      }
  }
  bool Validaciones::validarLongitudCadena(std::string cadena, int minimo, int maximo){
    int longitud = cadena.length();
    if (longitud <= minimo || longitud >= maximo) return false;
    return true;
  }
  // para cantidad de viajeros por ejemplo

  bool Validaciones::validarIngresoNumero(int numero){

  }
  bool Validaciones::validarIntPositivo(int numero){
      if(numero <= 0) return false;
      return true;
  }
  // para precios de paquetes
  bool Validaciones::validarFloatPositivo(float numero){
     //validar que se ingresa float
      if(numero <= 0) return false;
      return true;
  }
  // para fechas de paquetes de viajes: no puedo registrar un paquete con fecha pasada o de hoy. tiene que ser desde ma�ana en adelante, y como mucho 5 a�os proximos.
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

    int diasPorMes[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (mes == 2 && ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0))) {
        diasPorMes[1] = 29; // a�o bisiesto
    }
    if (dia < 1 || dia > diasPorMes[mes - 1]) return false;

    // Comparar contra la fecha actual: solo se permite una fecha desde ma�ana en adelante
    if (anio < anioActual) return false;
    if (anio == anioActual && mes < mesActual) return false;
    if (anio == anioActual && mes == mesActual && dia <= diaActual) return false;

    return true;
  }

bool Validaciones::validarFechaPosterior(FechaHora primeraFecha, int dia, int mes, int anio, int horas, int minutos){
    FechaHora fechaNueva(dia, mes, anio, horas, minutos);

    if (fechaNueva.getAnio() < primeraFecha.getAnio()) return false;
    if (fechaNueva.getAnio() == primeraFecha.getAnio() && fechaNueva.getMes() < primeraFecha.getMes()) return false;
    if (fechaNueva.getAnio() == primeraFecha.getAnio() && fechaNueva.getMes() == primeraFecha.getMes() && fechaNueva.getDia() <= primeraFecha.getDia()) return false;

    return true;
  }
    // validar dia, mes, anio, minutos, horas por separado
  // validar que se ingrso 1 o 0 para booleano
  // validar que se ingrese avion, tren o colectivo

