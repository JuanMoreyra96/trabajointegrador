#pragma once
#include <string>
#include "pago.h"
class PagoArchivo{
private:
  std::string _nombreArchivo;
public:
  PagoArchivo();
  PagoArchivo(std::string nombreArchivo);

  int buscar(int idPago);
  float sumarPagosPorReserva(int idReserva);
  bool guardar(Pago registro);
  bool guardar(Pago registro, int posicion);
  int getCantidadRegistros();
  Pago leer(int pos);
};
