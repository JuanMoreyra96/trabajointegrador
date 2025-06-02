#ifndef PAQUETEDEVIAJEARCHIVO_H_INCLUDED
#define PAQUETEDEVIAJEARCHIVO_H_INCLUDED
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
};
#endif
