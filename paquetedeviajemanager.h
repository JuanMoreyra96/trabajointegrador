#ifndef PAQUETEDEVIAJEMANAGER_H_INCLUDED
#define PAQUETEDEVIAJEMANAGER_H_INCLUDED
#include "fechaHora.h"

class PaqueteDeViajeManager{
private:

public:
  void cargarPaqueteDeViaje();
  void mostrarCantidadRegistros();
  void listarTodos(); // activos e inactivos
  void listarPaquetesActivos(); //solo activos: que todavia no se hicieron
  void darDeBaja();
  void darDeAlta();
  void buscarPaquetePorDestino();
  void buscarPorRangoDePrecio();
  void buscarPaquetePorFechaSalida();
  void buscarPaquetePorFechaRegreso();
  void buscarPorTransporte();
  void buscarPorTemporada();
  void buscarConCuposDisponibles();
};
#endif
