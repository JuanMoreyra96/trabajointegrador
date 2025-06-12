#ifndef PAGOARCHIVO_H_INCLUDED
#define PAGOARCHIVO_H_INCLUDED
#include <string>
#include "pago.h"
class PagoArchivo{
private:
  std::string _nombreArchivo;
public:
  PagoArchivo();
  PagoArchivo(std::string nombreArchivo);

  int buscar(int idPago);
  bool guardar(Pago registro);
  bool guardar(Pago registro, int posicion);
  int getCantidadRegistros();
  Pago leer(int pos);
};


#endif // PAGOARCHIVO_H_INCLUDED
