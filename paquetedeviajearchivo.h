#pragma once
#include <string>
#include "paquetedeviaje.h"

class PaqueteDeViajeArchivo{
private:
  std::string _nombreArchivo;
public:
  PaqueteDeViajeArchivo();
  PaqueteDeViajeArchivo(std::string nombreArchivo);

  int buscar(int idPaquete);
  bool guardar(PaqueteDeViaje registro);
  bool guardar(PaqueteDeViaje registro, int posicion);
  int getCantidadRegistros();
  PaqueteDeViaje leer(int pos);
  void guardarPaquetesPorDestino(PaqueteDeViaje *v,int tam, std::string destino);
  void mostrarPaquetesPorDestinoParcial(std::string texto, bool soloProximos = false);
  void buscarPorRangoPrecios(float precioMenor, float precioMayor);
  void buscarRegistroPorFechaSalida(FechaHora fecha);
  void buscarRegistroPorFechaRegreso(FechaHora fecha);
  void mostrarPaquetesPorTransporte(std::string transporte);
};
