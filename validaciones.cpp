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
      return true;
  }


    bool Validaciones::validarLongitudCadena(std::string cadena, int minimo, int maximo){
        int longitud = cadena.length();
        if (longitud < minimo || longitud > maximo) return false;
        return true;
    }


    bool Validaciones::validarCadenaDeNumeros(std::string cadena){
        for (char c : cadena) {
            if (!isdigit(c)) return false;
        }
        return true;
    }


    bool Validaciones::validarCadenaEmail(std::string cadena) {
        bool tieneArroba = false;
        bool tienePunto = false;

        for (char c : cadena) {
            if (isalpha(c) || isdigit(c) || c == '@' || c == '.' || c == '-' || c == '_') {
                if (c == '@') tieneArroba = true;
                if (c == '.') tienePunto = true;
            } else {
                return false;
            }
        }
        if (tieneArroba && tienePunto){
            return true;
        }else{
            return false;
        }
	}

  // para cantidad de viajeros por ejemplo

  int Validaciones::pedirNumero(){
    int numero;
    while (!(cin >> numero) || numero <= 0) {
        cout << "Entrada invalida. Ingrese un numero entero positivo: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    return numero;
}
  float Validaciones::pedirNumeroFloat(){
   float numero;
   while (!(cin >> numero) || numero <= 0) {
        cout << "Entrada invalida. Ingrese un numero positivo: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    return numero;
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
    bool Validaciones::validarDia(int dia){
        if(dia >= 1 && dia <=31) return true;
        return false;
        }
    bool Validaciones::validarMes(int mes){
          if(mes >= 1 && mes <=12) return true;
        return false;
    }
    bool Validaciones::validarAnio(int anio){
        if(anio >= 2025 && anio <= 2030) return true;
        return false;
    }
    bool Validaciones::validarHora(int hora){
         if(hora >= 0 && hora <= 23) return true;
        return false;
    }
    bool Validaciones::validarMinutos(int minutos){
        if(minutos >= 0 && minutos <= 59) return true;
        return false;
    }
  // validar que se ingrso 1 o 0 para booleano
    bool Validaciones::validarBooleano(int valor){
    if(valor == 1 || valor == 0) return true;
    return false;
    }
  // validar que se ingrese avion, tren o colectivo

