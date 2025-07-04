#pragma once
#include <string>
#include "Reserva.h"

class ReservaArchivo{
private:
  std::string _nombreArchivo;
public:
  ReservaArchivo();
  ReservaArchivo(std::string nombreArchivo);

  int buscar(int idReserva);
  bool guardar(Reserva registro);
  bool guardar(Reserva registro, int posicion);
  int getCantidadRegistros();
  Reserva leer(int pos);
};

